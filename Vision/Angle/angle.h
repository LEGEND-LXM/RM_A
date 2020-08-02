#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;


class Angle
{
public:
	double x_angle;
	double y_angle;
	Angle()
	{
		x_angle = 0;
		y_angle = 0;
	}
	void angle_col(cv::Point &p, double &x_angle, double &y_angle);
};


