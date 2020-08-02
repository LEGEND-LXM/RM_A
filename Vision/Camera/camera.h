#pragma once
#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
#include<windows.h>
#include<cysuvclib.h>
#include <Vfw.h>
#pragma comment(lib, "Vfw32.lib")  //drawdibdraw֧��
#include <thread>
bool ByteToMat(BYTE* pImg, int nH, int nW, int nFlag, cv::Mat& outImg);
std::mutex mLock;
cv::Mat src, dst, src1;
class CmfcDlg
{
public:
	CmfcDlg();	// ��׼���캯��
	BYTE* mpImgBuf;  //��ʾͼ��
	PCYSDEV mpCam;
	GUID format;
	GUID format_new;
	long mImgWidth;
	long mImgHeight;
	void InitCam(PCYSDEV pCam);//�������
	void OpenCam(PCYSDEV pCam);//�����
	void StartPreivew(PCYSDEV pCam);//����Ԥ��

};
CmfcDlg* gpMainDlg = NULL;

void CALLBACK StreamingDataCallback(PCYSDEV pCam, BYTE* pBuffer, long lBufferSize)
{
	//gpMainDlg->Invalidate();��ͼˢ��
	if (!pBuffer || lBufferSize == 0) return;
	mLock.lock();//���̲߳�����������
	memcpy(gpMainDlg->mpImgBuf, pBuffer, lBufferSize); //���ﷵ�ص�lbuffersize��Ϊw*h*3��С

	ByteToMat(gpMainDlg->mpImgBuf, 512, 640, 3, src);//��mpImgBufת��Ϊ��Ϊ512����Ϊ640��ͨ��Ϊ3��cv::Mat���͵�ͼ��

	src.copyTo(src1);//src1=src;��src1=src.clone();�����������ã�����ִ���
	mLock.unlock();

}
CmfcDlg::CmfcDlg()
{
	gpMainDlg = this;
}
//init���޸�camerĬ�ϲ���
void CmfcDlg::InitCam(PCYSDEV pCam)
{
	if (!pCam) return;

	//ע����Ƶ���ص�����
	if (!CysRegisterStreamingCallback(pCam, StreamingDataCallback))
		return; //ע��ʧ�ܣ��鿴������ʾ��log��־
	else
		std::cout << "ע����Ƶ���ص�����ok" << std::endl;



	//��ȡ��ǰ��Ƶ�ֱ���
	if (!CysGetCurrentMediaType(pCam, PIN_CATEGORY_PREVIEW, &format, &mImgWidth, &mImgHeight))
		return;
	std::cout << "format" << "mImgWidth " << mImgWidth << "mImgHeight:" << mImgHeight << std::endl;

	CysSetMediaType(pCam, PIN_CATEGORY_PREVIEW, MEDIASUBTYPE_MJPG, 640, 512, TRUE);
	CysSetProperty(pCam, PropType_CamCtl, PropIndex_Exposure, -2, 2);

	//������Ƶbuffer�ڴ�
	if (!mpImgBuf)
	{
		mpImgBuf = new BYTE[mImgWidth * mImgHeight * 3];
	}

	//���ã�ʹ�ܲ����趨�����û�иı��������ʹ��Ĭ�ϲ���
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
		return;//�Ѿ��򿪣�ֱ�ӷ���
	}

	if (!CysOpenDevice(pCam))
	{

		std::cout << "open camera failed" << std::endl;
		exit(1);
		//return; //���豸ʧ�ܣ��鿴���󵯿��log��־

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

/*��BYTE* ���͵�ͼ��תΪcv::Mat����*/
bool ByteToMat(BYTE* pImg, int nH, int nW, int nFlag, cv::Mat& outImg)//nH,nWΪBYTE*����ͼ��ĸߺͿ�,nFlagΪͨ����
{
	if (pImg == nullptr)
	{
		return false;
	}
	int nByte = nH * nW * nFlag;//�ֽڼ���
	//int nType = nFlag == 8 ? CV_8UC1 : CV_8UC3;
	int nType = CV_8UC3;
	outImg = cv::Mat::zeros(nH, nW, nType);
	memcpy(outImg.data, pImg, nByte);
	return true;
}
