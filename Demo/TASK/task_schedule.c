/***********************
osThreadSuspend               ：暂停一个线程
osThreadResume                ：继续执行暂停的线程
osThreadSuspendAll            ：暂停所有线程
osThreadResumeAll             ：继续执行暂停的所有线程
vTaskDelete                   ：删除任务
osThreadGetId                 ：获取ID
osThreadTerminate             ：终止正在运行的线程
osDelayUntil                  ：绝对延迟
osAbortDelay                  ：中止特定线程的延迟
osThreadList                  ：列出了所有当前线程及其当前状态

***********************/
/*
osThreadId Task_Task_ScheduleHandle;        //定义与任务调用有关的线程ID
osThreadId Task_Task_ImuHandle;             //定义与IMU有关的线程ID
osThreadId Task_Task_WaveformHandle;        //定义与波形助手有关的线程ID
osThreadId Task_Task_ChassisHandle;         //定义与底盘控制有关的线程ID
osThreadId Task_Task_HolderHandle;          //定义与云台控制有关的线程ID
osThreadId Task_Task_ShootHandle;           //定义与发射机构有关的线程ID
osThreadId Task_Task_VisualHandle;          //定义与视觉通信有关的线程ID
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






