#pragma once  
#ifndef SERIALPORT_H_    
#define SERIALPORT_H_    

#include <Windows.h>    
/** 串口通信类
*
*  本类实现了对串口的基本操作
*  例如监听发到指定串口的数据、发送指定数据到串口
*/

typedef unsigned char           uint8_t;//unsigned char typeddef一个别名
class CSerialPort
{
public:
	CSerialPort(void);//构造函数
	~CSerialPort(void);//析构函数
	/*缓存数据*/
	bool Readexit;
public:
	int GetList();
	bool InitPort(UINT  portNo = 1, UINT  baud = CBR_115200, char  parity = 'N', UINT  databits = 8, UINT  stopsbits = 1, DWORD dwCommEvents = EV_RXCHAR);
	bool InitPort(UINT  portNo, const LPDCB& plDCB);
	bool WriteData(unsigned char* pData, unsigned int length);//向pData写入长度为length的数据
	UINT GetBytesInCOM();
	bool ReadChar(char& cRecved);
	void ReadData(unsigned char* buff);

private:
	//判断是否打开了编号为portNo的串口，如果打开，则return true，否则，return false
	bool openPort(UINT  portNo);
	//关闭串口
	void ClosePort();

private:
	/** 串口句柄 */
	HANDLE  m_hComm;
	/** 同步互斥,临界区保护 */
	CRITICAL_SECTION   m_csCommunicationSync;       //!< 互斥操作串口    
	/** 线程句柄 */
	volatile HANDLE    m_hListenThread;

};

#endif //SERIALPORT_H_   
