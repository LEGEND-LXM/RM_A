#include"../Armor/armor.h"
#include"../Camera/camera.h"
#include"../Serial/SerialPort.h"
#include"../Angle/angle.h"
#include<signal.h>
#include<thread>
#include<mutex>

Armor_detect arm;
cv::Point P1, P2;
Angle a1;

double x_angle;
double y_angle;
double flag;

int com_flag_enter = 0;
int com_flag_send = 0;

int x = 320, y = 256;

char flag1 = 0;
int armorFlag;
int armorType;
unsigned char buf[] = "";

std::mutex muLock;

unsigned char data[] = { 0x1A,0x00,0x00,0x00,0x00,0x00,0x00,0x7A };
int value1, value2, value3;

bool quit_flag;
void signal_handler(int)
{
	quit_flag = true;
}

void init_signals(void)
{
	quit_flag = false;
	signal(SIGINT, signal_handler);
}

bool communicate();
bool mainprocess();

int main()
{
	//std::thread com_thread(communicate);
	std::thread main_thread(mainprocess);

	//com_thread.join();
	main_thread.join();

}


bool mainprocess()
{
	init_signals();

	CmfcDlg cm;
	cm.mpCam = NULL;
	cm.mpImgBuf = NULL;
	cm.mImgWidth = 640;
	cm.mImgHeight = 512;

	DWORD sn = 861469925;

	if (!CysLibInit(sn))//ж�ؿ�(uvclib��)���ͷ���Դ
	{
		std::cout << "��ʼ��ʧ��" << !CysLibInit(sn) << std::endl;
		return TRUE; //��ʼ��ʧ�ܣ��鿴������ʾ��log��־��Ϣ
	}
	else
		std::cout << "CysLibInit(sn) succeed" << !CysLibInit(sn) << std::endl;
	//ö���豸
	auto count = CysEnumVideoDevices();
	if (count < 1) return TRUE;
	//cout << count << endl;
	//��ȡ���index���豸
	auto index = 0;
	//double center;
	cm.mpCam = CysGetDeviceFromIndex(index);
	std::cout << "�豸ָ��" << cm.mpCam << std::endl;
	//���豸
	cm.OpenCam(cm.mpCam);

	HWND hwnd = 0;
	com_flag_enter = 1;
	CysCallPreviewMediaTypePage(cm.mpCam, hwnd, TRUE);
	com_flag_enter = 0;

	//Ԥ��
	cm.StartPreivew(cm.mpCam);
	Sleep(100);

	while (1)
	{
		
		if (quit_flag)
		{
			std::cout << "i am in" << std::endl;
		}
		com_flag_send = 1;
		mLock.lock();
		std::cout << CysCaculateFrameRate(cm.mpCam, TRUE, 240) << std::endl;
		cv::flip(src1, dst, 1);
		flag = arm.detect(dst, P2);
		a1.angle_col(P2, x_angle, y_angle);
		mLock.unlock();


		if (cv::waitKey(1) == 'c')
		{
			raise(SIGINT);//
			break;
		}
		cv::waitKey(1);
	}
	cv::destroyAllWindows();
	cv::waitKey(0);
	return 0;
}

bool communicate()
{
	CSerialPort mySerialPort;

	//unsigned char send_buff[10];
	int port = mySerialPort.GetList() - 0x30;
	while(!flag1)
	{ 
		if (!mySerialPort.InitPort(port, 9600, 'N', 8, 1, EV_RXCHAR))
		{
			//std::cout << "initPort fail !" << std::endl;
		}
		else
		{
			//std::cout << "initPort success !" << std::endl;
			flag1 = 1;
		}
	}
	while (1)
	{

		if (com_flag_enter == 1)
		{
			std::cout << "communicate" << std::endl;
			keybd_event(VK_RETURN, 0, 0, 0);
			Sleep(10);
			keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
		}
		if (com_flag_send == 1)
		{
			value1 = P2.x;
			value2 = P2.y;
			value3 = flag;
			*(short*)(data + 1) = (short)value1;//data0+data1���Yaw��Ƕ�
			*(short*)(data + 3) = (short)value2;//data2+data3���Pitch��Ƕ�
			*(short*)(data + 5) = (short)value3;//16bit����
			mySerialPort.WriteData(data, sizeof(data));
			//std::cout << "have finish send" <<std:: endl <<std:: endl;
			//mySerialPort.WriteData(send_buff, sizeof(send_buff));
			mySerialPort.ReadData(buf);
			//std::cout << "have finish get" << std::endl << std::endl;
			com_flag_send = 0;
		}
	}


}