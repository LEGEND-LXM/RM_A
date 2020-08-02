#include "armor.h"
#include<iostream>
#include<math.h>
std::vector<cv::Mat> channels;
ArmorDescriptor arm;
//cv::Point2f Ver;
cv::RotatedRect& adjustRec(cv::RotatedRect& rec, const int mode)
{
	using std::swap;  //使用标准名称空间的交换函数

	float& width = rec.size.width;
	float& height = rec.size.height;
	float& angle = rec.angle;

	if (mode == WIDTH_GREATER_THAN_HEIGHT)//
	{
		if (width < height)
		{
			swap(width, height);
			angle += 90.0;
		}
	}

	while (angle >= 90.0) angle -= 180.0;
	while (angle < -90.0) angle += 180.0;

	if (mode == ANGLE_TO_UP)
	{
		if (angle >= 45.0)
		{
			swap(width, height);
			angle -= 90.0;
		}
		else if (angle < -45.0)
		{
			swap(width, height);
			angle += 90.0;
		}
	}

	return rec;
};

double Armor_detect::detect(const cv::Mat &frame,cv::Point& p)
{
	LightGroup.resize(0);
	split(frame, channels);//分离bgr通道灰度
	if (Enemy == E_BLUE)
		FrameBinary = channels.at(0) - channels.at(2);
	else
		FrameBinary = channels.at(2) - channels.at(0);

	//画中心十字
	//line(frame, cv::Point2f(320 - 10, 256), cv::Point2f(320 + 10, 256), cv::Scalar(0, 0, 255));
	//line(frame, cv::Point2f(320, 256 - 10), cv::Point2f(320, 256 + 10), cv::Scalar(0, 0, 255));


	cv::Mat binBrightImg;
	//阈值化
	threshold(FrameBinary, binBrightImg, THRE, 255, cv::THRESH_BINARY);
	cv::Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3, 3));
	//cv::imshow("bin1", binBrightImg);

	//膨胀
	dilate(binBrightImg, binBrightImg, element);
	//cv::imshow("bin", binBrightImg);
	std::vector<std::vector<cv::Point>> lightContours;
	cv::Mat dst = cv::Mat::zeros(FrameBinary.rows, FrameBinary.cols, CV_8UC3); // 测试
	std::vector<cv::Vec4i> hierarchy;
	//找轮廓
	findContours(binBrightImg.clone(), lightContours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	cv::Scalar color(10, 0, 100);
	drawContours(dst, lightContours, -1, color);
	cv::imshow("dst", dst);


	for (const auto& contour : lightContours)
	{
		//得到面积
		float lightContourArea = contourArea(contour);
		//面积太小的不要
		if (contour.size() < 5 ||
			lightContourArea < _param.light_min_area) continue;
		//椭圆拟合区域得到外接矩形
		cv::RotatedRect lightRec = fitEllipse(contour);
		//矫正灯条
		adjustRec(lightRec, ANGLE_TO_UP);
		//宽高比、凸度筛选灯条
		if (lightRec.size.width / lightRec.size.height >
			_param.light_max_ratio ||
			lightContourArea / lightRec.size.area() <
			_param.light_contour_min_solidity
			)continue;
		//对灯条范围适当扩大
		lightRec.size.width *= _param.light_color_detect_extend_ratio;
		lightRec.size.height *= _param.light_color_detect_extend_ratio;
		cv::Rect lightRect = lightRec.boundingRect();
		const cv::Rect srcBound(cv::Point(0, 0), FrameBinary.size());
		lightRect &= srcBound;
		//因为颜色通道相减后己方灯条直接过滤，不需要判断颜色了,可以直接将灯条保存
		LightGroup.push_back(LightBar(lightRec));
	}
	//没找到灯条就返回没找到
	if (LightGroup.empty())
	{
		std::cout << "No lightbar!\n";
		//return;
	}

	//按灯条中心x从小到大排序
	std::sort(LightGroup.begin(), LightGroup.end(), [](const LightBar& ld1, const LightBar& ld2)
	{//Lambda函数,作为sort的cmp函数
		return ld1.center.x < ld2.center.x;
	});
	for (size_t i = 0; i < LightGroup.size(); i++)
	{//遍历所有灯条进行匹配
		for (size_t j = i + 1; j < LightGroup.size(); j++)
		{
			const LightBar& leftLight = LightGroup[i];
			const LightBar& rightLight = LightGroup[j];
			//角差
			float angleDiff_ = abs(leftLight.led_angle - rightLight.led_angle);
			//长度差比率
			float LenDiff_ratio = abs(leftLight.height - rightLight.height) / std::max(leftLight.height, rightLight.height);
			//筛选
			if (angleDiff_ > _param.light_max_angle_diff_ ||
				LenDiff_ratio > _param.light_max_height_diff_ratio_)
			{
				continue;
			}

			//左右灯条相距距离
			//dis = (std::pow((leftLight.center.x - rightLight.center.x), 2) + std::pow((leftLight.center.y - rightLight.center.y), 2));
			float dis = std::sqrt(((leftLight.center.x - rightLight.center.x)*(leftLight.center.x - rightLight.center.x)) + ((leftLight.center.y - rightLight.center.y)*(leftLight.center.y - rightLight.center.y)));
			//左右灯条长度的平均值
			float meanLen = (leftLight.height + rightLight.height) / 2;
			//左右灯条中心点y的差值
			float yDiff = abs(leftLight.center.y - rightLight.center.y);
			//y差比率
			float yDiff_ratio = yDiff / meanLen;
			//左右灯条中心点x的差值
			float xDiff = abs(leftLight.center.x - rightLight.center.x);
			//x差比率
			float xDiff_ratio = xDiff / meanLen;
			//相距距离与灯条长度比值
			float ratio = dis / meanLen;
			//筛选
			if (yDiff_ratio > _param.light_max_y_diff_ratio_ ||
				xDiff_ratio < _param.light_min_x_diff_ratio_ ||
				ratio > _param.armor_max_aspect_ratio_ ||
				ratio < _param.armor_min_aspect_ratio_)
			{
				continue;
			}

			// calculate pairs' info 
				  //按比值来确定大小装甲
			int armorType = ratio > 3.2 ? BIG_ARMOR : SMALL_ARMOR;
			// calculate the rotation score
			float ratiOff = (armorType == BIG_ARMOR) ? std::max((float)5.0, float(0)) : std::max((float)1.0 - ratio, float(0));
			float yOff = yDiff / meanLen;
			float rotationScore = -(ratiOff * ratiOff + yOff * yOff);
			//得到匹配的装甲板
			ArmorDescriptor armor(leftLight, rightLight, armorType, channels.at(1), rotationScore, _param);

			_armors.emplace_back(armor);
			//++i;
			break;
		}
	}
	//没匹配到装甲板则返回没找到
	if (_armors.empty())
	{
		std::cout << "armor is empty!\n";
		return 0x0011;
		//return _flag = ARMOR_NO;
	}
	//delete the fake armors
	_armors.erase(remove_if(_armors.begin(), _armors.end(), [this](ArmorDescriptor& i)
	{//lamdba函数判断是不是装甲板，将装甲板中心的图片提取后让识别函数去识别，识别可以用svm或者模板匹配等
		return 0 == (i.isArmorPattern());
	}), _armors.end());
	//全都判断不是装甲板
	//if (_armors.empty())
	//{
	//	//_targetArmor.clear();

	//	//if (_flag == ARMOR_LOCAL)
	//	//{
	//	//	//cout << "Tracking lost" << endl;
	//	//	return _flag = ARMOR_LOST;
	//	//}
	//	//else
	//	//{
	//	//	//cout << "No armor pattern detected." << endl;
	//	//	return _flag = ARMOR_NO;
	//	//}
	//}
	if (!_armors.empty())
	{
		for (size_t i = 0; i < _armors.size(); i++) {
			cv::Scalar color = cv::Scalar(0, 0, 255);
			line(frame, _armors[i].vertex[0], _armors[i].vertex[1], color);
			line(frame, _armors[i].vertex[1], _armors[i].vertex[2], color);
			line(frame, _armors[i].vertex[2], _armors[i].vertex[3], color);
			line(frame, _armors[i].vertex[3], _armors[i].vertex[0], color);

			double cenx = (_armors[i].vertex[0].x + _armors[i].vertex[1].x + _armors[i].vertex[2].x + _armors[i].vertex[3].x) / 4,
				ceny = (_armors[i].vertex[0].y + _armors[i].vertex[1].y + _armors[i].vertex[2].y + _armors[i].vertex[3].y) / 4;
			p = cv::Point(cenx, ceny);
			
			std::cout << std::abs((_armors[i].vertex[1].x) - (_armors[i].vertex[0].x))<<std::endl;
			line(frame, cv::Point2f(cenx - 10, ceny), cv::Point2f(cenx + 10, ceny), color);
			line(frame, cv::Point2f(cenx, ceny - 10), cv::Point2f(cenx, ceny + 10), color);

		}

	}
	else
	{
		_armors.clear();
		return 0x0011;
	}
	_armors.clear();
	cv::imshow("frame", frame);
	return 0x1100;
	}

Armor_detect::Armor_detect()
{

}

Armor_detect::~Armor_detect() {

}

