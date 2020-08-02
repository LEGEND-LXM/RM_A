#pragma once
#include <opencv2/opencv.hpp>

#define E_RED	0	
#define E_BLUE	1
//����Ϊ���ò���...
#define		ENEMY		E_RED	//�з���ɫ
#define		THRE		100		//��ֵ����ֵ

enum
{
	WIDTH_GREATER_THAN_HEIGHT,  //width��height��
	ANGLE_TO_UP  //���ӽǶ�
};
enum ObjectType
{
	UNKNOWN_ARMOR = 0,  //δ֪װ�װ�
	SMALL_ARMOR = 1,  //Сװ��
	BIG_ARMOR = 2,  //��װ��
	MINI_RUNE = 3,
	GREAT_RUNE = 4
};

template<typename T>
float distance(const cv::Point_<T>& pt1, const cv::Point_<T>& pt2)  //�������
{
	return std::sqrt(std::pow((pt1.x - pt2.x), 2) + std::pow((pt1.y - pt2.y), 2));
}

template<typename ValType>
const cv::Point2f crossPointOf(const std::array<cv::Point_<ValType>, 2>& line1, const std::array<cv::Point_<ValType>, 2>& line2)
{
	ValType a1 = line1[0].y - line1[1].y;
	ValType b1 = line1[1].x - line1[0].x;
	ValType c1 = line1[0].x*line1[1].y - line1[1].x*line1[0].y;

	ValType a2 = line2[0].y - line2[1].y;
	ValType b2 = line2[1].x - line2[0].x;
	ValType c2 = line2[0].x*line2[1].y - line2[1].x*line2[0].y;

	ValType d = a1 * b2 - a2 * b1;

	if (d == 0.0)
	{
		return cv::Point2f(FLT_MAX, FLT_MAX);
	}
	else
	{
		return cv::Point2f(float(b1*c2 - b2 * c1) / d, float(c1*a2 - c2 * a1) / d);
	}
}

inline const cv::Point2f crossPointOf(const cv::Vec4f& line1, const cv::Vec4f& line2)
{
	const std::array<cv::Point2f, 2> line1_{ cv::Point2f(line1[2],line1[3]),cv::Point2f(line1[2] + line1[0],line1[3] + line1[1]) };
	const std::array<cv::Point2f, 2> line2_{ cv::Point2f(line2[2],line2[3]),cv::Point2f(line2[2] + line2[0],line2[3] + line2[1]) };
	return crossPointOf(line1_, line2_);
}


struct ArmorParam
{
	//Ԥ����
	int brightness_threshold;
	int color_threshold;
	float light_color_detect_extend_ratio;

	//�˹��
	float light_min_area;  //������С����
	float light_max_angle;  //�������ƫ���
	float light_min_size;  //������С�ߴ�
	float light_contour_min_solidity;  //��������
	float light_max_ratio;  //����������

	//����ɸѡ
	float light_max_angle_diff_;  //�����Ҷת���Ƕ�
	float light_max_height_diff_ratio_; // ����Ҷת���߶�������
	float light_max_y_diff_ratio_;  // ����Ҷת��y����������
	float light_min_x_diff_ratio_;  // ����Ҷת��x������С����

	//װ�װ�ɸѡ
	float armor_big_armor_ratio; //��װ�װ����
	float armor_small_armor_ratio;  //Сװ�װ����
	float armor_min_aspect_ratio_;  
	float armor_max_aspect_ratio_;

	//��������
	float sight_offset_normalized_base;
	float area_normalized_base;
	int enemy_color;
	int max_track_num = 3000;
	float armor_max_height_;
	float armor_max_angle_;

	/*Ϊ���������Ĭ��ֵ*/
	ArmorParam()
	{
		//Ԥ����
		brightness_threshold = 100;
		color_threshold = 40;
		light_color_detect_extend_ratio = 1.1;

		// ɸѡ����
		light_min_area = 5;
		light_max_angle = 45.0;
		light_min_size = 5.0;
		light_contour_min_solidity = 0.5;
		light_max_ratio = 1.0;

		//�˲�����
		light_max_angle_diff_ = 7.0; //20
		light_max_height_diff_ratio_ = 0.3; //0.5
		light_max_y_diff_ratio_ = 2.0; //100
		light_min_x_diff_ratio_ = 0.5; //100

		//װ�װ�ɸѡ
		armor_big_armor_ratio = 3.2;
		armor_small_armor_ratio = 2;
		armor_max_height_ = 100.0;
		armor_max_angle_ = 30.0;
		armor_min_aspect_ratio_ = 1.0;
		armor_max_aspect_ratio_ = 5.0;

		//other params
		sight_offset_normalized_base = 200;
		area_normalized_base = 1000;
		enemy_color = E_RED;
	}
};


class LightBar //����
{
public:
	float width//���
		, proportion//��������:��
		, height//�߶�
		, led_angle//ƫת�Ƕ�
		, area;//���
	cv::Point2f vertex[4]//�ĸ�����
		, center//�������ĵ�
		, rect[4];//�洢���ζ���
	LightBar() {}
	LightBar(const float& w, const float& h, const float& lAng, const cv::Point2f rec[]) :width(w), height(h), led_angle(lAng), area(w*h), proportion(h / w)
	{
		for (int i = 0; i < 4; i++)
			vertex[i] = rec[i];
		center = (vertex[0] + vertex[2]) / 2;
	}
	LightBar(const cv::RotatedRect& light)
	{
		width = light.size.width;
		height = light.size.height;
		center = light.center;
		led_angle = light.angle;
		area = light.size.area();
	}

	~LightBar() {}

	cv::RotatedRect rec() const
	{
		return cv::RotatedRect(center, cv::Size2f(width, height), led_angle);
	}

};

class ArmorDescriptor  //װ�װ���
{
public:

	std::array<cv::RotatedRect, 2> lightPairs; //0 �����, 1 �ҵ���
	LightBar Llightbar, Rlightbar; //LlightbarΪ�������RLightbarΪ�ҵ���
	float sizeScore;		//S1 = e^(size)
	float distScore;		//S2 = e^(-offset)
	float rotationScore;		//S3 = -(ratio^2 + yDiff^2) 
	float finalScore;
	int type;
	std::vector<cv::Point2f> vertex; //����������ĸ����㣬����������⣡!
	cv::Mat frontImg; //����Ԥ�ױ任���ǰimg��1ͨ���Ҷ�img

	/*ʹ������0��ʼ��*/
	ArmorDescriptor()
	{
		rotationScore = 0;
		sizeScore = 0;
		vertex.resize(4);
		for (int i = 0; i < 4; i++)
		{
			vertex[i] = cv::Point2f(0, 0);
		}
		type = UNKNOWN_ARMOR;
	}

	/*
	����ArmRodDescriptor��ʣ����Ϣ�����������յ÷ֳ��⣩
	���ڣ�l&r�ơ�ArmorDetector�е�һ���ֳ�Ա��armortype��Ϊ�˽�ʡʱ�䣩
	*/
	ArmorDescriptor(const LightBar lLight, const LightBar rLight, const int armorType, const cv::Mat grayImg, float rotaScore, ArmorParam _param)
	//���캯��
	{
		//������������
		Llightbar = lLight;
		Rlightbar = rLight;
		lightPairs[0] = lLight.rec();
		lightPairs[1] = rLight.rec();

		cv::Size exLSize(int(lightPairs[0].size.width), int(lightPairs[0].size.height * 2));
		cv::Size exRSize(int(lightPairs[1].size.width), int(lightPairs[1].size.height * 2));
		cv::RotatedRect exLLight(lightPairs[0].center, exLSize, lightPairs[0].angle);
		cv::RotatedRect exRLight(lightPairs[1].center, exRSize, lightPairs[1].angle);

		cv::Point2f pts_l[4];
		exLLight.points(pts_l);
		cv::Point2f upper_l = pts_l[2];
		cv::Point2f lower_l = pts_l[3];

		cv::Point2f pts_r[4];
		exRLight.points(pts_r);
		cv::Point2f upper_r = pts_r[1];
		cv::Point2f lower_r = pts_r[0];

		vertex.resize(4);
		vertex[0] = upper_l;
		vertex[1] = upper_r;
		vertex[2] = lower_r;
		vertex[3] = lower_l;

		//����װ�װ�����
		type = armorType;
	}

	bool isArmorPattern(/*_small_Armor_template, _big_Armor_template, lastEnemy*/)const
	{
		return true;
	}

	void clear()
	{
		rotationScore = 0;
		sizeScore = 0;
		distScore = 0;
		finalScore = 0;
		for (int i = 0; i < 4; i++)
		{
			vertex[i] = cv::Point2f(0, 0);
		}
		type = UNKNOWN_ARMOR;
	}

};


class Armor_detect
{
	public:
		double detect(const cv::Mat &frame,cv::Point& p);
	private:
		cv::Mat FrameBinary;
		std::vector<LightBar>LightGroup;
		bool Enemy = ENEMY;	//0-�з���ɫ��1-�з���ɫ
		ArmorParam _param;
		std::vector<ArmorDescriptor> _armors;
		ArmorDescriptor _targetArmor;

	public:
		std::vector<ArmorDescriptor> getArmors() { return _armors; }
		Armor_detect();
		~Armor_detect();
};