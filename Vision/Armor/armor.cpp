#include "armor.h"
#include<iostream>
#include<math.h>
std::vector<cv::Mat> channels;
ArmorDescriptor arm;
//cv::Point2f Ver;
cv::RotatedRect& adjustRec(cv::RotatedRect& rec, const int mode)
{
	using std::swap;  //ʹ�ñ�׼���ƿռ�Ľ�������

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
	split(frame, channels);//����bgrͨ���Ҷ�
	if (Enemy == E_BLUE)
		FrameBinary = channels.at(0) - channels.at(2);
	else
		FrameBinary = channels.at(2) - channels.at(0);

	//������ʮ��
	//line(frame, cv::Point2f(320 - 10, 256), cv::Point2f(320 + 10, 256), cv::Scalar(0, 0, 255));
	//line(frame, cv::Point2f(320, 256 - 10), cv::Point2f(320, 256 + 10), cv::Scalar(0, 0, 255));


	cv::Mat binBrightImg;
	//��ֵ��
	threshold(FrameBinary, binBrightImg, THRE, 255, cv::THRESH_BINARY);
	cv::Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3, 3));
	//cv::imshow("bin1", binBrightImg);

	//����
	dilate(binBrightImg, binBrightImg, element);
	//cv::imshow("bin", binBrightImg);
	std::vector<std::vector<cv::Point>> lightContours;
	cv::Mat dst = cv::Mat::zeros(FrameBinary.rows, FrameBinary.cols, CV_8UC3); // ����
	std::vector<cv::Vec4i> hierarchy;
	//������
	findContours(binBrightImg.clone(), lightContours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	cv::Scalar color(10, 0, 100);
	drawContours(dst, lightContours, -1, color);
	cv::imshow("dst", dst);


	for (const auto& contour : lightContours)
	{
		//�õ����
		float lightContourArea = contourArea(contour);
		//���̫С�Ĳ�Ҫ
		if (contour.size() < 5 ||
			lightContourArea < _param.light_min_area) continue;
		//��Բ�������õ���Ӿ���
		cv::RotatedRect lightRec = fitEllipse(contour);
		//��������
		adjustRec(lightRec, ANGLE_TO_UP);
		//��߱ȡ�͹��ɸѡ����
		if (lightRec.size.width / lightRec.size.height >
			_param.light_max_ratio ||
			lightContourArea / lightRec.size.area() <
			_param.light_contour_min_solidity
			)continue;
		//�Ե�����Χ�ʵ�����
		lightRec.size.width *= _param.light_color_detect_extend_ratio;
		lightRec.size.height *= _param.light_color_detect_extend_ratio;
		cv::Rect lightRect = lightRec.boundingRect();
		const cv::Rect srcBound(cv::Point(0, 0), FrameBinary.size());
		lightRect &= srcBound;
		//��Ϊ��ɫͨ������󼺷�����ֱ�ӹ��ˣ�����Ҫ�ж���ɫ��,����ֱ�ӽ���������
		LightGroup.push_back(LightBar(lightRec));
	}
	//û�ҵ������ͷ���û�ҵ�
	if (LightGroup.empty())
	{
		std::cout << "No lightbar!\n";
		//return;
	}

	//����������x��С��������
	std::sort(LightGroup.begin(), LightGroup.end(), [](const LightBar& ld1, const LightBar& ld2)
	{//Lambda����,��Ϊsort��cmp����
		return ld1.center.x < ld2.center.x;
	});
	for (size_t i = 0; i < LightGroup.size(); i++)
	{//�������е�������ƥ��
		for (size_t j = i + 1; j < LightGroup.size(); j++)
		{
			const LightBar& leftLight = LightGroup[i];
			const LightBar& rightLight = LightGroup[j];
			//�ǲ�
			float angleDiff_ = abs(leftLight.led_angle - rightLight.led_angle);
			//���Ȳ����
			float LenDiff_ratio = abs(leftLight.height - rightLight.height) / std::max(leftLight.height, rightLight.height);
			//ɸѡ
			if (angleDiff_ > _param.light_max_angle_diff_ ||
				LenDiff_ratio > _param.light_max_height_diff_ratio_)
			{
				continue;
			}

			//���ҵ���������
			//dis = (std::pow((leftLight.center.x - rightLight.center.x), 2) + std::pow((leftLight.center.y - rightLight.center.y), 2));
			float dis = std::sqrt(((leftLight.center.x - rightLight.center.x)*(leftLight.center.x - rightLight.center.x)) + ((leftLight.center.y - rightLight.center.y)*(leftLight.center.y - rightLight.center.y)));
			//���ҵ������ȵ�ƽ��ֵ
			float meanLen = (leftLight.height + rightLight.height) / 2;
			//���ҵ������ĵ�y�Ĳ�ֵ
			float yDiff = abs(leftLight.center.y - rightLight.center.y);
			//y�����
			float yDiff_ratio = yDiff / meanLen;
			//���ҵ������ĵ�x�Ĳ�ֵ
			float xDiff = abs(leftLight.center.x - rightLight.center.x);
			//x�����
			float xDiff_ratio = xDiff / meanLen;
			//��������������ȱ�ֵ
			float ratio = dis / meanLen;
			//ɸѡ
			if (yDiff_ratio > _param.light_max_y_diff_ratio_ ||
				xDiff_ratio < _param.light_min_x_diff_ratio_ ||
				ratio > _param.armor_max_aspect_ratio_ ||
				ratio < _param.armor_min_aspect_ratio_)
			{
				continue;
			}

			// calculate pairs' info 
				  //����ֵ��ȷ����Сװ��
			int armorType = ratio > 3.2 ? BIG_ARMOR : SMALL_ARMOR;
			// calculate the rotation score
			float ratiOff = (armorType == BIG_ARMOR) ? std::max((float)5.0, float(0)) : std::max((float)1.0 - ratio, float(0));
			float yOff = yDiff / meanLen;
			float rotationScore = -(ratiOff * ratiOff + yOff * yOff);
			//�õ�ƥ���װ�װ�
			ArmorDescriptor armor(leftLight, rightLight, armorType, channels.at(1), rotationScore, _param);

			_armors.emplace_back(armor);
			//++i;
			break;
		}
	}
	//ûƥ�䵽װ�װ��򷵻�û�ҵ�
	if (_armors.empty())
	{
		std::cout << "armor is empty!\n";
		return 0x0011;
		//return _flag = ARMOR_NO;
	}
	//delete the fake armors
	_armors.erase(remove_if(_armors.begin(), _armors.end(), [this](ArmorDescriptor& i)
	{//lamdba�����ж��ǲ���װ�װ壬��װ�װ����ĵ�ͼƬ��ȡ����ʶ����ȥʶ��ʶ�������svm����ģ��ƥ���
		return 0 == (i.isArmorPattern());
	}), _armors.end());
	//ȫ���жϲ���װ�װ�
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

