#ifndef __Revolver_Task_H
#define __Revolver_Task_H
#ifdef __cplusplus
 extern "C" {
#endif
	 
/********freertos��Ҫ���õĿ��ļ�********/
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
/********�����������ļ�********/
#include "bsp_can.h"
#include "pid.h"
#include "user_lib.h"
#include "dji_remote.h"
/***********************************************START***********************************************/
/*���ܴ������ƣ�Ħ���ֵ����в���*/
	 
//����ʼ����һ��ʱ��
#define REVOLVER_TASK_INIT_TIME 50
//����������Ƽ�� 2ms
#define REVOLVER_CONTROL_TIME_MS 2
//����������Ƽ�� 0.002s
#define REVOLVER_CONTROL_TIME 0.002

#define SHOOYTINGMOTOR_UP_SPEED_PID_KP 3.0f
#define SHOOYTINGMOTOR_UP_SPEED_PID_KI 0.1f
#define SHOOYTINGMOTOR_UP_SPEED_PID_KD 0.0f
#define SHOOYTINGMOTOR_UP_SPEED_PID_MAX_OUT 16000.0f
#define SHOOYTINGMOTOR_UP_SPEED_PID_MAX_IOUT 5000.0f
	 
#define SHOOYTINGMOTOR_DOWN_SPEED_PID_KP 3.0f
#define SHOOYTINGMOTOR_DOWN_SPEED_PID_KI 0.1f
#define SHOOYTINGMOTOR_DOWN_SPEED_PID_KD 0.0f
#define SHOOYTINGMOTOR_DOWN_SPEED_PID_MAX_OUT 16000.0f
#define SHOOYTINGMOTOR_DOWN_SPEED_PID_MAX_IOUT 5000.0f
	
//���ֵ��pid	
#define PAN_TRIGGER_PID_KP 9.0f
#define PAN_TRIGGER_PID_KI 0.1f
#define PAN_TRIGGER_PID_KD 0.0f
#define PAN_TRIGGER_PID_MAX_OUT 16000.0f
#define PAN_TRIGGER_PID_MAX_IOUT 2000.0f

//������pid
#define TRIGGER_ANGLE_PID_KP 6.0f
#define TRIGGER_ANGLE_PID_KI 0.04f
#define TRIGGER_ANGLE_PID_KD 0.0f
#define TRIGGER_ANGLE_PID_MAX_OUT 2000.0f
#define TRIGGER_ANGLE_PID_MAX_IOUT 200.0f


#define SHOOT_ACCEL_UP_NUM 0.0111f
#define SHOOT_ACCEL_DOWN_NUM 0.0111f

//Ħ���ֵ����װ
#define UP_TURN 0
#define DOWN_TURN 1

//���ֵ����װ
#define PAN_TRIGGER_TURN 0
//�����ֵ����װ
#define TRIGGER_TURN 0

//Ħ�����ٶ�	
#define SPEED_NUM_UP_0 		0
#define SPEED_NUM_DOWN_0 	0

#define SPEED_NUM_UP_1 		6000.0f
#define SPEED_NUM_DOWN_1 	6500.0f

#define SPEED_NUM_UP_2 		6000.0f
#define SPEED_NUM_DOWN_2 	6500.0f

//���ֵ���ٶ�����
#define PAN_TRIGGER_SPEED 1300.0f		//��λΪ��������ֵ
#define TRIGGER_SPEED			1300.0f					//��λΪ����

//����׼��̬���������
#define BALL_MAX 3

//��翪���ж� ��ʼ״̬�Ǹߵ�ƽ 1������ʱ�����͵�ƽ��Ч 0
#define LIMIT_UP_JUDGE HAL_GPIO_ReadPin(LIMIT_UP_GPIO_Port,LIMIT_UP_Pin)
#define LIMIT_DOWN_JUDGE HAL_GPIO_ReadPin(LIMIT_DOWN_GPIO_Port,LIMIT_DOWN_Pin)
//��λ�����ж� �ж��Ƿ�������
#define LIMIT_SWITCH_JUDGE HAL_GPIO_ReadPin(LIMIT_SWITCH_GPIO_Port,LIMIT_SWITCH_Pin)
typedef enum
{
	SHOOTING_FORBID  = 0,//��ֹ����
	SHOOTING_READY   = 1,
	SHOOTING_ALLOWED = 2,//������
	SHOOTING_DONE    = 3,
	SHOOTING_LOOP    = 4,
}Shooting_Motor_mode;

typedef struct
{
  const moto_info_t *shooting_motor_measure;
  fp32 accel;
  fp32 speed;
  fp32 speed_set;
  int16_t given_current;				//PID�����������ֵ
} Shooting_Motor_t;

typedef struct
{
  const RC_Type *shooting_RC;               
	Shooting_Motor_t shooting_up_motor;   
	Shooting_Motor_t shooting_down_motor; 
	
	Shooting_Motor_t pan_trigger_motor;     //Ŀ�ⲻ��Ҫ�ջ�
	Shooting_Motor_t trigger_motor;
	
  pid_struct_t shooting_speed_up_pid;             			//��Ħ����pid
  pid_struct_t shooting_speed_down_pid;	//��Ħ����pid

	pid_struct_t pan_trigger_pid;
	pid_struct_t trigger_pid;
	
  first_order_filter_type_t shooting_cmd_slow_set_up;		//��Ħ��������
  first_order_filter_type_t shooting_cmd_slow_set_down;	//��Ħ��������
	
	uint8_t shooting_mode;
	
	fp32 shooting_speed_up_set;														
	fp32 shooting_speed_down_set;
	
	fp32 shooting_up_speed;
	fp32 shooting_down_speed;
	
	
	fp32 pan_trigger_angle;		//���ֵ���Ƕ�
	fp32 pan_trigger_angle_set;
	
	fp32 trigger_angle;				//�������Ƕ�
	fp32 trigger_angle_set;
	
	fp32 pan_trigger_speed;		//���ֵ�����ٶ�
	fp32 pan_trigger_speed_set;
	
	fp32 trigger_speed;				//���������ٶ�
	fp32 trigger_speed_set;
	
	uint16_t ball_num_limit;		//���������֮�������޶�����
	int16_t ball_num;
	uint16_t ball_num_last;
	
	int16_t last_butter_count;
	int8_t ecd_count;
	
	uint16_t key_up;
	uint16_t key_up_count;
	uint16_t key_down;
	
	int16_t BulletShootCnt;		//�ӵ��������
	uint16_t move_flag;
	
	bool_t shoot_done;
	uint16_t shoot_done_time;
	
	uint16_t cmd_time;
	uint16_t run_time;
	uint16_t key_time;
	
}Shooting_Control_t;	 
/***********************************************END***************************************************/
	 
extern osThreadId vRevolver_TaskHandle;
	 
void Revolver_Task(void const * argument);
	 
#ifdef __cplusplus
}
#endif
#endif /*__Gimbal_Task_H */
