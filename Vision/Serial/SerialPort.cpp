#include "SerialPort.h"    
#include <process.h>    
#include <iostream> 
#include <WinBase.h>
#include <atlbase.h>

#define NAME_LEN 100
using namespace std;


CSerialPort::CSerialPort(void)
{
	InitializeCriticalSection(&m_csCommunicationSync);//��ʼ���ؼ���

}

CSerialPort::~CSerialPort(void)
{

	ClosePort();//�رմ���
	DeleteCriticalSection(&m_csCommunicationSync);//ɾ���ؼ���
}

bool CSerialPort::InitPort(UINT portNo /*= 1*/, UINT baud /*= CBR_9600*/, char parity /*= 'N'*/,
	UINT databits /*= 8*/, UINT stopsbits /*= 1*/, DWORD dwCommEvents /*= EV_RXCHAR*/)
{

	/** ��ʱ����,���ƶ�����ת��Ϊ�ַ�����ʽ,�Թ���DCB�ṹ */
	char szDCBparam[50];
	sprintf_s(szDCBparam, "baud=%d parity=%c data=%d stop=%d", baud, parity, databits, stopsbits);

	/** ��ָ������,�ú����ڲ��Ѿ����ٽ�������,�����벻Ҫ�ӱ��� */
	if (!openPort(portNo))
	{
		return false;
	}

	/** �����ٽ�� */
	EnterCriticalSection(&m_csCommunicationSync);

	/** �Ƿ��д����� */
	BOOL bIsSuccess = TRUE;

	///** �ڴ˿���������������Ļ�������С,���������,��ϵͳ������Ĭ��ֵ.
	//*  �Լ����û�������Сʱ,Ҫע�������Դ�һЩ,���⻺�������
	//*/
	///*if (bIsSuccess )
	//{
	//bIsSuccess = SetupComm(m_hComm,10,10);
	//}*/

	/** ���ô��ڵĳ�ʱʱ��,����Ϊ0,��ʾ��ʹ�ó�ʱ���� */
	COMMTIMEOUTS  CommTimeouts;
	CommTimeouts.ReadIntervalTimeout = 0;
	CommTimeouts.ReadTotalTimeoutMultiplier = 0;
	CommTimeouts.ReadTotalTimeoutConstant = 0;
	CommTimeouts.WriteTotalTimeoutMultiplier = 0;
	CommTimeouts.WriteTotalTimeoutConstant = 0;

	DCB  dcb;
	if (bIsSuccess)
	{
		// ��ANSI�ַ���ת��ΪUNICODE�ַ���    
		DWORD dwNum = MultiByteToWideChar(CP_ACP, 0, szDCBparam, -1, NULL, 0);
		wchar_t* pwText = new wchar_t[dwNum];
		if (!MultiByteToWideChar(CP_ACP, 0, szDCBparam, -1, pwText, dwNum))
		{
			bIsSuccess = TRUE;
		}

		/** ��ȡ��ǰ�������ò���,���ҹ��촮��DCB���� */
		bIsSuccess = GetCommState(m_hComm, &dcb) && BuildCommDCB(pwText, &dcb);
		/** ����RTS flow���� */
		dcb.fRtsControl = RTS_CONTROL_ENABLE;

		/** �ͷ��ڴ�ռ� */
		delete[] pwText;
	}

	if (bIsSuccess)
	{
		/** ʹ��DCB�������ô���״̬ */
		bIsSuccess = SetCommState(m_hComm, &dcb);
	}

	/**  ��մ��ڻ����� */
	PurgeComm(m_hComm, PURGE_RXCLEAR | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_TXABORT);

	/** �뿪�ٽ�� */
	LeaveCriticalSection(&m_csCommunicationSync);

	return bIsSuccess == TRUE;
}

bool CSerialPort::InitPort(UINT portNo, const LPDCB& plDCB)
{
	/** ��ָ������,�ú����ڲ��Ѿ����ٽ�������,�����벻Ҫ�ӱ��� */
	if (!openPort(portNo))
	{
		return false;
	}

	/** �����ٽ�� */
	EnterCriticalSection(&m_csCommunicationSync);

	/** ���ô��ڲ��� */
	if (!SetCommState(m_hComm, plDCB))
	{
		return false;
	}

	/**  ��մ��ڻ����� */
	PurgeComm(m_hComm, PURGE_RXCLEAR | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_TXABORT);

	/** �뿪�ٽ�� */
	LeaveCriticalSection(&m_csCommunicationSync);

	return true;
}

void CSerialPort::ClosePort()
{
	/** ����д��ڱ��򿪣��ر��� */
	if (m_hComm != INVALID_HANDLE_VALUE)
	{
		CloseHandle(m_hComm);
		m_hComm = INVALID_HANDLE_VALUE;
	}
}

bool CSerialPort::openPort(UINT portNo)
{
	/** �����ٽ�� */
	EnterCriticalSection(&m_csCommunicationSync);

	/** �Ѵ��ڵı��ת��Ϊ�豸�� */
	char szPort[50];
	sprintf_s(szPort, "COM%d", portNo);

	/** ��ָ���Ĵ��� */
	m_hComm = CreateFileA(szPort,  /** �豸��,COM1,COM2�� */
		GENERIC_READ | GENERIC_WRITE, /** ����ģʽ,��ͬʱ��д */
		0,                            /** ����ģʽ,0��ʾ������ */
		NULL,                         /** ��ȫ������,һ��ʹ��NULL */
		OPEN_EXISTING,                /** �ò�����ʾ�豸�������,���򴴽�ʧ�� */
		0,
		0);

	/** �����ʧ�ܣ��ͷ���Դ������ */
	if (m_hComm == INVALID_HANDLE_VALUE)
	{
		LeaveCriticalSection(&m_csCommunicationSync);
		return false;
	}

	/** �˳��ٽ��� */
	LeaveCriticalSection(&m_csCommunicationSync);

	return true;
}




UINT CSerialPort::GetBytesInCOM()
{
	DWORD dwError = 0;  /** ������ */
	COMSTAT  comstat;   /** COMSTAT�ṹ��,��¼ͨ���豸��״̬��Ϣ */
	/*memset�������ͣ���s�е�ǰλ�ú����n���ֽ� ��typedef unsigned int size_t ���� ch �滻������ s ��*/
	memset(&comstat, 0, sizeof(COMSTAT));

	UINT BytesInQue = 0;
	/** �ڵ���ReadFile��WriteFile֮ǰ,ͨ�������������ǰ�����Ĵ����־ */

	/*ClearCommError�����ĵ�һ������hFile����CreateFile��������ָ���Ѵ򿪴��пڵľ����
	**�ڶ�������ָ�����˴������͵�32λ������
	**����������ָ��һ�������豸״̬�Ŀ��ƿ�COMSTAT��
	**����������óɹ����򷵻�ֵΪ��0������������ʧ�ܣ��򷵻�ֵΪ0*/
	if (ClearCommError(m_hComm, &dwError, &comstat))
	{
		BytesInQue = comstat.cbInQue; /** ��ȡ�����뻺�����е��ֽ��� */
	}

	return BytesInQue;
}


bool CSerialPort::ReadChar(char& cRecved)
{
	BOOL  bResult = TRUE;
	DWORD BytesRead = 0;
	if (m_hComm == INVALID_HANDLE_VALUE)
	{
		return false;
	}

	/** �ٽ������� */
	EnterCriticalSection(&m_csCommunicationSync);

	/** �ӻ�������ȡһ���ֽڵ����� */
	bResult = ReadFile(m_hComm, &cRecved, 1, &BytesRead, NULL);
	if ((!bResult))
	{
		/** ��ȡ������,���Ը��ݸô�����������ԭ�� */
		DWORD dwError = GetLastError();

		/** ��մ��ڻ����� */
		PurgeComm(m_hComm, PURGE_RXCLEAR | PURGE_RXABORT);
		LeaveCriticalSection(&m_csCommunicationSync);

		return false;
	}

	/** �뿪�ٽ��� */
	LeaveCriticalSection(&m_csCommunicationSync);

	return (BytesRead == 1);

}

void CSerialPort::ReadData(unsigned char* buff)
{
	// �߳�ѭ��,��ѯ��ʽ��ȡ��������  

	UINT BytesInQue = this->GetBytesInCOM();
	memset(buff, 0x00, sizeof(buff));
	/** ��ȡ���뻺�����е����ݲ������ʾ */
	char cRecved = 0x00;
	int count = 0;
	do
	{

		cRecved = 0x00;
		if (this->ReadChar(cRecved) == true)
		{
			if (Readexit)
			{
				break;
			}
			cout << (unsigned)cRecved << " ";
			continue;
		}
	} while (--BytesInQue);

}

bool CSerialPort::WriteData(unsigned char* pData, unsigned int length)
{
	BOOL   bResult = TRUE;
	DWORD  BytesToSend = 0;
	if (m_hComm == INVALID_HANDLE_VALUE)
	{
		return false;
	}

	/** �ٽ������� */
	EnterCriticalSection(&m_csCommunicationSync);

	/** �򻺳���д��ָ���������� */
	bResult = WriteFile(m_hComm, pData, length, &BytesToSend, NULL);
	if (!bResult)
	{
		DWORD dwError = GetLastError();
		/** ��մ��ڻ����� */
		PurgeComm(m_hComm, PURGE_RXCLEAR | PURGE_RXABORT);
		LeaveCriticalSection(&m_csCommunicationSync);

		return false;
	}

	/** �뿪�ٽ��� */
	LeaveCriticalSection(&m_csCommunicationSync);

	return true;
}



int CSerialPort::GetList()
{

	long lRet;

	HKEY hKey;

	char szValueName[NAME_LEN];
	BYTE szPortName[NAME_LEN];
	LONG status;
	DWORD dwSizeofPortName = NAME_LEN;
	DWORD dwIndex = 0;
	DWORD dwSizeValueName = NAME_LEN;
	DWORD Type;

	LPCWSTR cpp_data = _T("HARDWARE\\DEVICEMAP\\SERIALCOMM\\");
	lRet = RegOpenKeyEx(
		HKEY_LOCAL_MACHINE,         // handle to open key
		cpp_data,  // subkey name
		0,   // reserved
		KEY_QUERY_VALUE, // security access mask
		&hKey    // handle to open key
	);

	if (lRet == ERROR_SUCCESS)
	{
		cout << "��ע���ɹ�" << endl;
		do
		{
			status = RegEnumValueA(hKey, dwIndex++, szValueName, &dwSizeValueName, NULL, &Type,
				szPortName, &dwSizeofPortName);//Use Unicode Character Set
			if ((status == ERROR_SUCCESS))
			{
				//m_lstPort.AddString((char*)szPortName);
				cout << "the first com:" << szPortName << endl;
				return szPortName[3];

			}
			//ÿ��ȡһ��dwSizeValueName��dwSizeofPortName���ᱻ�޸�
			//ע��һ��Ҫ����,�������ֺ�����Ĵ���,���˾��Թ���û������,���ֶ�����COM����10���ϵĴ���
			dwSizeValueName = NAME_LEN;
			dwSizeofPortName = NAME_LEN;
		} while ((status != ERROR_NO_MORE_ITEMS));




	}
	else
	{
		cout << "��ע���ʧ��" << endl;
		return false;
	}

}