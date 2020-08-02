

#ifndef __TASK_INIT
#define __TASK_INIT

#include "task_tatal.h"
#include "cmsis_os.h"

extern osThreadId Task_Task_ScheduleHandle;        //定义与任务调用有关的线程ID
extern osThreadId Task_Task_ImuHandle;             //定义与IMU有关的线程ID
extern osThreadId Task_Task_WaveformHandle;        //定义与波形助手有关的线程ID
extern osThreadId Task_Task_ChassisHandle;         //定义与底盘控制有关的线程ID
extern osThreadId Task_Task_HolderHandle;          //定义与云台控制有关的线程ID
extern osThreadId Task_Task_ShootHandle;           //定义与发射机构有关的线程ID
extern osThreadId Task_Task_VisualHandle;          //定义与视觉通信有关的线程ID


void User_Init(void);   //用户程序初始化

void Task_Init(void);                    //初始化任务调度函数



#endif






