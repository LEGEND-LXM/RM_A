

#ifndef __TASK_INIT
#define __TASK_INIT

#include "task_tatal.h"
#include "cmsis_os.h"

extern osThreadId Task_Task_ScheduleHandle;        //��������������йص��߳�ID
extern osThreadId Task_Task_ImuHandle;             //������IMU�йص��߳�ID
extern osThreadId Task_Task_WaveformHandle;        //�����벨�������йص��߳�ID
extern osThreadId Task_Task_ChassisHandle;         //��������̿����йص��߳�ID
extern osThreadId Task_Task_HolderHandle;          //��������̨�����йص��߳�ID
extern osThreadId Task_Task_ShootHandle;           //�����뷢������йص��߳�ID
extern osThreadId Task_Task_VisualHandle;          //�������Ӿ�ͨ���йص��߳�ID


void User_Init(void);   //�û������ʼ��

void Task_Init(void);                    //��ʼ��������Ⱥ���



#endif






