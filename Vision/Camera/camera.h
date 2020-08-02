#pragma once
#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
#include<windows.h>
#include<cysuvclib.h>
#include <Vfw.h>
#pragma comment(lib, "Vfw32.lib")  //drawdibdraw支持
#include <thread>
bool ByteToMat(BYTE* pImg, int nH, int nW, int nFlag, cv::Mat& outImg);
std::mutex mLock;
cv::Mat src, dst, src1;
class CmfcDlg
{
public:
	CmfcDlg();	// 标准构造函数
	BYTE* mpImgBuf;  //表示图像
	PCYSDEV mpCam;
	GUID format;
	GUID format_new;
	long mImgWidth;
	long mImgHeight;
	void InitCam(PCYSDEV pCam);//加载相机
	void OpenCam(PCYSDEV pCam);//打开相机
	void StartPreivew(PCYSDEV pCam);//启动预览

};
CmfcDlg* gpMainDlg = NULL;

void CALLBACK StreamingDataCallback(PCYSDEV pCam, BYTE* pBuffer, long lBufferSize)
{
	//gpMainDlg->Invalidate();绘图刷新
	if (!pBuffer || lBufferSize == 0) return;
	mLock.lock();//多线程操作：互斥锁
	memcpy(gpMainDlg->mpImgBuf, pBuffer, lBufferSize); //这里返回的lbuffersize即为w*h*3大小

	ByteToMat(gpMainDlg->mpImgBuf, 512, 640, 3, src);//将mpImgBuf转换为高为512，宽为640，通道为3的cv::Mat类型的图像

	src.copyTo(src1);//src1=src;或src1=src.clone();但不能这样用，会出现错误
	mLock.unlock();

}
CmfcDlg::CmfcDlg()
{
	gpMainDlg = this;
}
//init里修改camer默认参数
void CmfcDlg::InitCam(PCYSDEV pCam)
{
	if (!pCam) return;

	//注册视频流回调函数
	if (!CysRegisterStreamingCallback(pCam, StreamingDataCallback))
		return; //注册失败，查看弹框提示或log日志
	else
		std::cout << "注册视频流回调函数ok" << std::endl;



	//获取当前视频分辨率
	if (!CysGetCurrentMediaType(pCam, PIN_CATEGORY_PREVIEW, &format, &mImgWidth, &mImgHeight))
		return;
	std::cout << "format" << "mImgWidth " << mImgWidth << "mImgHeight:" << mImgHeight << std::endl;

	CysSetMediaType(pCam, PIN_CATEGORY_PREVIEW, MEDIASUBTYPE_MJPG, 640, 512, TRUE);
	CysSetProperty(pCam, PropType_CamCtl, PropIndex_Exposure, -2, 2);

	//分配视频buffer内存
	if (!mpImgBuf)
	{
		mpImgBuf = new BYTE[mImgWidth * mImgHeight * 3];
	}

	//配置，使能参数设定；如果没有改变参数，会使用默认参数
	if (!CysConfigDevice(pCam))
	{
		std::cout << "format" << "mImgWidth " << mImgWidth << "mImgHeight:" << mImgHeight << std::endl;
		return;
	}
	CysGetCurrentMediaType(pCam, PIN_CATEGORY_CAPTURE, &format_new, &mImgWidth, &mImgHeight);
	std::cout << "format" << "mImgWidth " << mImgWidth << "mImgHeight:" << mImgHeight << std::endl;

}
void CmfcDlg::OpenCam(PCYSDEV pCam)
{
	if (!pCam) return;

	auto status = CysGetOpenStatus(pCam);
	std::cout << status << std::endl;
	if (status == OpenStatus_Opened)
	{
		std::cout << "open camera succeed" << std::endl;
		return;//已经打开，直接返回
	}

	if (!CysOpenDevice(pCam))
	{

		std::cout << "open camera failed" << std::endl;
		exit(1);
		//return; //打开设备失败，查看错误弹框或log日志

	}
	else
		std::cout << "open camera succeed" << std::endl;
	InitCam(pCam);

}
void CmfcDlg::StartPreivew(PCYSDEV pCam)
{
	int status = CysGetVideoStatus(pCam);
	if (status == VideoStatus_Streaming || status == VideoStatus_StreamingCapture)
	{

		std::cout << "return1" << std::endl;
		return;
	}
	else
		std::cout << "return2" << std::endl;


	if (!CysStartStreaming(pCam))
		return;
}

/*将BYTE* 类型的图像转为cv::Mat类型*/
bool ByteToMat(BYTE* pImg, int nH, int nW, int nFlag, cv::Mat& outImg)//nH,nW为BYTE*类型图像的高和宽,nFlag为通道数
{
	if (pImg == nullptr)
	{
		return false;
	}
	int nByte = nH * nW * nFlag;//字节计算
	//int nType = nFlag == 8 ? CV_8UC1 : CV_8UC3;
	int nType = CV_8UC3;
	outImg = cv::Mat::zeros(nH, nW, nType);
	memcpy(outImg.data, pImg, nByte);
	return true;
}
