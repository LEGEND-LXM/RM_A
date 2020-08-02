#include"Angle.h"

void Angle::angle_col(cv::Point &p,double &x_angle, double &y_angle)
{
	cv::Mat cam = cv::Mat::eye(3, 3, CV_64F);
	cam.at<double>(0, 0) = 5.342326e+02;
	cam.at<double>(0, 1) = 0;
	cam.at<double>(0, 2) = 3.150241e+02;
	cam.at<double>(1, 1) = 5.342136e+02;
	cam.at<double>(1, 2) = 2.47014e+02;

	cv::Mat dis = Mat::zeros(5, 1, CV_64F);
	dis.at<double>(0, 0) = -0.3976;
	dis.at<double>(1, 0) = 0.2156;
	dis.at<double>(2, 0) = 0;
	dis.at<double>(3, 0) = 0;
	dis.at<double>(4, 0) = 0;

	Angle angle;
	double fx = cam.at<double>(0, 0);
	double fy = cam.at<double>(1, 1);
	double cx = cam.at<double>(0, 2);
	double cy = cam.at<double>(1, 2);

	Point2f pnt;
	std::vector<cv::Point2f> in;
	std::vector<cv::Point2f> out;

	in.push_back(p);
	//去畸变
	auto t1 = std::chrono::high_resolution_clock::now();
	undistortPoints(in, out, cam, dis, noArray(), cam);
	auto t2 = std::chrono::high_resolution_clock::now();
	std::cout << "Total period: " 
			  << (static_cast<std::chrono::duration<double, std::milli>>(t2 - t1)).count() 
			  << " ms" << std::endl << std::endl <<std:: endl << std::endl << std::endl;
	
	pnt = out.front();

	//没有去畸变比值
	double rx = (p.x - cx) / fx;
	double ry = (p.y - cy) / fy;
	//去畸变后比值
	double RX = (pnt.x - cx) / fx;
	double RY = (pnt.y - cy) / fy;

	//计算所得角度
	//没有去畸变计算角度
	double x_angle_before = atan(rx) / CV_PI * 180;
	double y_angle_before = atan(ry) / CV_PI * 180;
	//去畸变后的计算角度
	x_angle = atan(RX) / CV_PI * 180;
	y_angle = atan(RY) / CV_PI * 180;


	
	//去畸变前后坐标对比
	std::cout << "before adjust :" << "(" << p.x << "," << p.y << ")" << std::endl;
	std::cout << "after adjust :" << "(" << pnt.x << "," << pnt.y << ")" << std::endl;
	//去畸变前后角度对比
	std::cout << "before adjust : " << std::endl<< "x _angle_before: " << x_angle_before << "  y_angle_before:" << y_angle_before << std::endl;
	std::cout << "AFTER adjust : " << std::endl << "x _angle: " << x_angle << "  y_angle:" << y_angle << std::endl;
}
