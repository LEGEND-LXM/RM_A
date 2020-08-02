#ifndef __Revolver_Task_H
#define __Revolver_Task_H
#ifdef __cplusplus
 extern "C" {
#endif
#define shooting 1
	 
	 
/********freertos需要调用的库文件********/
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
/********外设驱动库文件********/
#include "bsp_can.h"
#include "pid.h"
#include "user_lib.h"
#include "dji_remote.h"
	 
#if shooting
/***********************************************START***********************************************/
/*功能代码名称：摩擦轮的所有参数*/
	 
#define SHOOYTINGMOTOR_UP_SPEED_PID_KP 2.0f
#define SHOOYTINGMOTOR_UP_SPEED_PID_KI 0.1f
#define SHOOYTINGMOTOR_UP_SPEED_PID_KD 0.0f
#define SHOOYTINGMOTOR_UP_SPEED_PID_MAX_OUT 16000.0f
#define SHOOYTINGMOTOR_UP_SPEED_PID_MAX_IOUT 5000.0f
	 
#define SHOOYTINGMOTOR_DOWN_SPEED_PID_KP 2.0f
#define SHOOYTINGMOTOR_DOWN_SPEED_PID_KI 0.1f
#define SHOOYTINGMOTOR_DOWN_SPEED_PID_KD 0.0f
#define SHOOYTINGMOTOR_DOWN_SPEED_PID_MAX_OUT 16000.0f
#define SHOOYTINGMOTOR_DOWN_SPEED_PID_MAX_IOUT 5000.0f
	 
#define SHOOT_ACCEL_UP_NUM 0.0111f
#define SHOOT_ACCEL_DOWN_NUM 0.0111f

//摩擦轮电机反装
#define UP_TURN 0
#define DOWN_TURN 1

//摩擦轮速度	
#define SPEED_NUM_UP_0 		0
#define SPEED_NUM_DOWN_0 	0

#define SPEED_NUM_UP_1 		2000.0f
#define SPEED_NUM_DOWN_1 	2000.0f

#define SPEED_NUM_UP_2 		1000.0f
#define SPEED_NUM_DOWN_2 	1000.0f

typedef struct
{
  const moto_info_t *shooting_motor_measure;
  fp32 accel;
  fp32 speed;
  fp32 speed_set;
  int16_t given_current;				//PID计算后给电机的值
} Shooting_Motor_t;

typedef struct
{
  const RC_Type *shooting_RC;               
	Shooting_Motor_t shooting_up_motor;   
	Shooting_Motor_t shooting_down_motor; 
	
  pid_struct_t shooting_speed_up_pid;             			//上摩擦轮pid
  pid_struct_t shooting_speed_down_pid;               	//下摩擦轮pid

  first_order_filter_type_t shooting_cmd_slow_set_up;		//上摩擦轮启动
  first_order_filter_type_t shooting_cmd_slow_set_down;	//下摩擦轮启动
	
	fp32 shooting_speed_up_set;														
	fp32 shooting_speed_down_set;
	
	fp32 shooting_up_speed;
	fp32 shooting_down_speed;
	
}Shooting_Control_t;	 
/***********************************************END***************************************************/

#endif
	

extern osThreadId vTest_TaskHandle;
void Test_Task(void const * argument);
	 
#ifdef __cplusplus
}
#endif
#endif /*__Gimbal_Task_H */
