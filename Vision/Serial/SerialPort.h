#pragma once  
#ifndef SERIALPORT_H_    
#define SERIALPORT_H_    

#include <Windows.h>    
/** ����ͨ����
*
*  ����ʵ���˶Դ��ڵĻ�������
*  �����������ָ�����ڵ����ݡ�����ָ�����ݵ�����
*/

typedef unsigned char           uint8_t;//unsigned char typeddefһ������
class CSerialPort
{
public:
	CSerialPort(void);//���캯��
	~CSerialPort(void);//��������
	/*��������*/
	bool Readexit;
public:
	int GetList();
	bool InitPort(UINT  portNo = 1, UINT  baud = CBR_115200, char  parity = 'N', UINT  databits = 8, UINT  stopsbits = 1, DWORD dwCommEvents = EV_RXCHAR);
	bool InitPort(UINT  portNo, const LPDCB& plDCB);
	bool WriteData(unsigned char* pData, unsigned int length);//��pDataд�볤��Ϊlength������
	UINT GetBytesInCOM();
	bool ReadChar(char& cRecved);
	void ReadData(unsigned char* buff);

private:
	//�ж��Ƿ���˱��ΪportNo�Ĵ��ڣ�����򿪣���return true������return false
	bool openPort(UINT  portNo);
	//�رմ���
	void ClosePort();

private:
	/** ���ھ�� */
	HANDLE  m_hComm;
	/** ͬ������,�ٽ������� */
	CRITICAL_SECTION   m_csCommunicationSync;       //!< �����������    
	/** �߳̾�� */
	volatile HANDLE    m_hListenThread;

};

#endif //SERIALPORT_H_   
