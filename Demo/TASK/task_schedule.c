/***********************
osThreadSuspend               ����ͣһ���߳�
osThreadResume                ������ִ����ͣ���߳�
osThreadSuspendAll            ����ͣ�����߳�
osThreadResumeAll             ������ִ����ͣ�������߳�
vTaskDelete                   ��ɾ������
osThreadGetId                 ����ȡID
osThreadTerminate             ����ֹ�������е��߳�
osDelayUntil                  �������ӳ�
osAbortDelay                  ����ֹ�ض��̵߳��ӳ�
osThreadList                  ���г������е�ǰ�̼߳��䵱ǰ״̬

***********************/
/*
osThreadId Task_Task_ScheduleHandle;        //��������������йص��߳�ID
osThreadId Task_Task_ImuHandle;             //������IMU�йص��߳�ID
osThreadId Task_Task_WaveformHandle;        //�����벨�������йص��߳�ID
osThreadId Task_Task_ChassisHandle;         //��������̿����йص��߳�ID
osThreadId Task_Task_HolderHandle;          //��������̨�����йص��߳�ID
osThreadId Task_Task_ShootHandle;           //�����뷢������йص��߳�ID
osThreadId Task_Task_VisualHandle;          //�������Ӿ�ͨ���йص��߳�ID
*/
/*
#define OFF_GPS            5
#define OFF_ATTI_1         7
#define OFF_ATTI_2         6
#define CL_GPS             13
#define CL_ATTI_1          15
#define CL_ATTI_2          14
#define HL_GPS             9
#define HL_ATTI_1          11
#define HL_ATTI_2          10

*/
#include "task_schedule.h"

SCHEDULE_Type SCHEDULE_Ture;


void StartTask_Schedule(void const * argument) 
{
	osDelay(1);
//	    	osThreadSuspend(Task_Task_ImuHandle);
//				osThreadSuspend(Task_Task_WaveformHandle);
//				osThreadSuspend(Task_Task_ChassisHandle);
//				osThreadSuspend(Task_Task_HolderHandle);
//		    osThreadSuspend(Task_Task_ShootHandle);
//		    osThreadSuspend(Task_Task_VisualHandle);
//		    user_pwm_setvalue(&htim4 ,TIM_CHANNEL_1 ,0 );
//	      user_pwm_setvalue(&htim4 ,TIM_CHANNEL_2 ,0 );
	for(;;)
  {
		/********************/
	  vTaskDelete(Task_Task_ScheduleHandle);
		
    HAL_GPIO_WritePin( GPIOG , LED3_Pin, GPIO_PIN_SET);
    osDelay(1);
		
  }
	
	
}






