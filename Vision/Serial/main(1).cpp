//#include"./include/ArmorDetector.h"
//#include"./include/skt_driver.h"
//#include<opencv2/imgproc/imgproc.hpp>
//#include<opencv2/highgui/highgui.hpp>
//#include<chrono>
//#include<signal.h>
//#include<iostream>
//#include<stdio.h>
//#include <windows.h>
//#include "conio.h"
//#include "SerialPort.h"  
//#include<thread>
//
//using namespace cv;
//using namespace std;
//using namespace rm;
//ArmorDetector arm;
//
//	#define skt_camera
//	//#define local_vedio
//
//int com_flag_enter = 0;
//int com_flag_send = 0;
//
//unsigned char buf[] = "";
// /*element = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(10, 10))*/;
///*
//*	To prevent camera from dying!
//*/
//bool quit_flag ;
//void signal_handler(int)
//{
//	quit_flag = true;
//}
//
//void init_signals(void)
//{
//	quit_flag = false;
//	signal(SIGINT, signal_handler);
//}
//bool communicate();
//bool mainprocess();
//int main()
//{
//	thread com_thread(communicate);
//	thread main_thread(mainprocess);
//
//	com_thread.join();
//	main_thread.join();
//}
//bool mainprocess()
//{
//	
//	init_signals();
//
//#ifdef local_vedio
//	cv::VideoCapture cap("out.avi");
//	if (!cap.isOpened())
//	{
//		cout << "Could not open the input video: " << std::endl;
//		return -1;
//	}
//#endif // local_vedio
//#ifdef skt_camera
//	camera cm;
//	cm.mpCam = NULL;
//	cm.mpImgBuf = NULL;
//	cm.mImgWidth = 640;
//	cm.mImgHeight = 512;
//	DWORD sn = 861469925;
//
//	if (!CysLibInit(sn))
//	{
//		return TRUE; //初始化失败，查看弹框提示或log日志信息
//		cout << "初始化失败" << endl;
//	}
//	else
//		cout << "CysLibInit(sn) succeed" << endl;
//	//枚举设备
//	auto count = CysEnumVideoDevices();
//	if (count < 1) return TRUE;
//	//获取序号index的设备
//	auto index = 0;
//	cm.mpCam = CysGetDeviceFromIndex(index);//camera index 0
//	cout << "设备指针" << cm.mpCam << endl;
//
//	cm.OpenCam(cm.mpCam);
//	HWND hwnd = 0;
//	com_flag_enter = 1;
//	CysCallPreviewMediaTypePage(cm.mpCam, hwnd, TRUE);
//	com_flag_enter = 0;
//
//	cm.StartPreivew(cm.mpCam);
//	Sleep(100);
//	
//#endif // skt_camera
//	while (1)
//	{
//		if (quit_flag)
//		{
//			cout << "i am in" << endl;
//			//return 0;
//		}
//		auto t3 = std::chrono::high_resolution_clock::now();
//		com_flag_send = 1;
//		// cap >> frame;
//
//		 //CysCaculateFrameRate(cm.mpCam, TRUE, 240);
//		  //cout << CysCaculateFrameRate(cm.mpCam, TRUE, 240) << endl;
//		imshow("frame", frame);
//		auto t1 = std::chrono::high_resolution_clock::now();
//
//		arm.loadImg(frame);
//		armorFlag = arm.detect();
//		auto t2 = std::chrono::high_resolution_clock::now();
//		//cout << "Total period: " << (static_cast<chrono::duration<double, milli>>(t2 - t3)).count() << " ms" << endl;
//
//
//		if (cv::waitKey(1) == 'c')
//		{
//			raise(SIGINT);//
//			break;
//		}
//		waitKey(1);
//	}
//
//	cv::destroyAllWindows();
//	cv::waitKey(0);
//	return 0;
//
//
//}
//bool communicate()
//{
//	CSerialPort mySerialPort;
//	unsigned char send_buff[10];
//	int port = 5;
//	if (!mySerialPort.InitPort(port, 9600, 'N', 8, 1, EV_RXCHAR))
//	{
//		std::cout << "initPort fail !" << std::endl;
//	}
//	else
//	{
//		std::cout << "initPort success !" << std::endl;
//	}
//	for (int j = 0;j < 10;j++)
//	{
//		send_buff[j] = j;
//	}
//	while (1)
//	{
//		
//		if (com_flag_enter == 1)
//		{
//			cout << "communicate" << endl;
//			keybd_event(VK_RETURN, 0, 0, 0);
//			Sleep(10);
//			keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
//		}
//	     if(com_flag_send==1)
//		 { 
//			mySerialPort.WriteData(send_buff, sizeof(send_buff));
//			mySerialPort.ReadData(buf);
//			com_flag_send = 0;
//		 }
//	}
//
//
//}