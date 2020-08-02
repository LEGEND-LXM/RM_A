#ifndef __Gimbal_Task1_H
#define __Gimbal_Task1_H
#ifdef __cplusplus
 extern "C" {
#endif
	 
/********freertos��Ҫ���õĿ��ļ�********/
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
/********�����������ļ�********/
#include "dji_remote.h"
//#include "oled.h"
//#include "oledfont.h"	
#include "pid.h"
	
//�����ʼ�� ����һ��ʱ��
#define GIMBAL_TASK_INIT_TIME 201 
	 
//��̨��������
#define GIMBAL_CONTROL_TIME 1
	 
//�������Ƕȵ�ϵ��
#define init_k_ 0.027f

//����	 
#define GRAVITY 9.78f	
/***********************************************START***********************************************/
/*���ܴ������ƣ�����ת��ϵ��*/
	 
//��̨ң�ؿ���ϵ��ת�� 												2*pi/660������
#define RC_TRAVEL_RAD_FACTOR 0.0047599f

//��̨ң�ؿ���ϵ��ת�� 												2*180/660�Ƕ���
#define RC_TRAVEL_ANGLE_FACTOR 0.54545454f
	 
//��̨���������ϵ��ת��      								2*PI/8192������ 	 
#define Motor_Ecd_to_Rad 0.00076699f 

//��̨���������ת��Ϊ�Ƕ�										2*180/8192�Ƕ���
#define Motor_Ecd_to_Angle 0.043945312f

//��̨����Ƕ�ת��ϵ�� ������ת��Ϊ�Ƕ�				1/pi * 180
#define Motor_Rad_to_Angle 57.2957795f
/***********************************************END***************************************************/

/***********************************************START***********************************************/
/*���ܴ������ƣ�Ӳ��*/

//��̨�����װ���� 1Ϊ��װ 0Ϊ��װ
#define PITCH_TURN 1
#define YAW_TURN 0

//�������ֵ����Լ���ֵ
#define Half_ecd_range 4096
#define ecd_range 8191

//ң����������������Ϊң�������ڲ��죬ҡ�����м䣬��ֵ��һ��Ϊ��
#define RC_Dead_Band 10
/***********************************************END***************************************************/

/***********************************************START***********************************************/
/*���ܴ������ƣ���̨����������е�Ƕ�����*/
	 
#define YAW_ENCODE_OFFEST 			1861.0f			//YAW���е��ֵ 
#define PITCH_ENCODE_OFFEST 		3475.0f			//pitch���е��ֵ
#define YAW_MAX_ENCODE_ANGLE 		3086.0f			
#define YAW_MIN_ENCODE_ANGLE 		1083.0f
#define PITCH_MAX_ENCODE_ANGLE 	4256.0f
#define PITCH_MIN_ENCODE_ANGLE 	2500.0f
/***********************************************END***************************************************/
	 
/***********************************************START***********************************************/
/*���ܴ������ƣ����PID�궨��*/
	 
//pitch �ٶȻ� PID�����Լ� PID���������������
#define PITCH_SPEED_PID_KP 2000.0f//2000.0f
#define PITCH_SPEED_PID_KI 20.0f//20.0f
#define PITCH_SPEED_PID_KD 0.0f
#define PITCH_SPEED_PID_MAX_OUT 30000.f//30000.0f
#define PITCH_SPEED_PID_MAX_IOUT 5000.0f

//yaw �ٶȻ� PID�����Լ� PID���������������
#define YAW_SPEED_PID_KP 2500.0f
#define YAW_SPEED_PID_KI 20.0f//20.0f
#define YAW_SPEED_PID_KD 0.0f
#define YAW_SPEED_PID_MAX_OUT 30000.0f
#define YAW_SPEED_PID_MAX_IOUT 5000.0f

			//pitch �ǶȻ� �Ƕ��������ǽ��� PID�����Լ� PID���������������
			#define PITCH_GYRO_ABSOLUTE_PID_KP 15.0f
			#define PITCH_GYRO_ABSOLUTE_PID_KI 0.0f
			#define PITCH_GYRO_ABSOLUTE_PID_KD 0.0f

			#define PITCH_GYRO_ABSOLUTE_PID_MAX_OUT 10.0f
			#define PITCH_GYRO_ABSOLUTE_PID_MAX_IOUT 0.0f

			//yaw �ǶȻ� �Ƕ��������ǽ��� PID�����Լ� PID���������������
			#define YAW_GYRO_ABSOLUTE_PID_KP 10.0f
			#define YAW_GYRO_ABSOLUTE_PID_KI 0.0f
			#define YAW_GYRO_ABSOLUTE_PID_KD 0.3f
			#define YAW_GYRO_ABSOLUTE_PID_MAX_OUT 10.0f
			#define YAW_GYRO_ABSOLUTE_PID_MAX_IOUT 0.0f

//pitch �ǶȻ� �Ƕ��ɱ����� PID�����Լ� PID���������������
#define PITCH_ENCODE_RELATIVE_PID_KP 0.36f
#define PITCH_ENCODE_RELATIVE_PID_KI 0.1f
#define PITCH_ENCODE_RELATIVE_PID_KD 0.0f

#define PITCH_ENCODE_RELATIVE_PID_MAX_OUT 4.0f
#define PITCH_ENCODE_RELATIVE_PID_MAX_IOUT 0.0f

//yaw �ǶȻ� �Ƕ��ɱ����� PID�����Լ� PID���������������
#define YAW_ENCODE_RELATIVE_PID_KP 0.36f
#define YAW_ENCODE_RELATIVE_PID_KI 0.1f
#define YAW_ENCODE_RELATIVE_PID_KD 0.0f
#define YAW_ENCODE_RELATIVE_PID_MAX_OUT 4.0f
#define YAW_ENCODE_RELATIVE_PID_MAX_IOUT 0.0f
/***********************************************END***************************************************/

typedef enum
{
  GIMBAL_ZERO_FORCE = 0, //��̨����
  //GIMBAL_ABSOLUTE_ANGLE, //��̨�����Ǿ��ԽǶȿ���     ������
  //GIMBAL_RELATIVE_ANGLE, //��̨�������ֵ��ԽǶȿ���
	GIMBAL_MIXED_AB_RE_ANGLE,
	GIMBAL_STRAIGHT_LOCK,
  GIMBAL_MOTIONLESS,     //��̨��ң����������һ��ʱ��󱣳ֲ���������������Ư��
} gimbal_behaviour_e;

typedef struct
{
    const moto_info_t *gimbal_motor_measure;
		pid_struct_t gimbal_motor_absolute_angle_pid;
    pid_struct_t gimbal_motor_relative_angle_pid;
		pid_struct_t gimbal_motor_gyro_pid;
    uint16_t offset_ecd;//��Խ���ֵ
    fp32 max_relative_angle; //rad//������ֱֵ�Ӳ�������������ʱ��ҲҪ��ע�ⶼ�� �Ƕ�ֵ
    fp32 min_relative_angle; //rad
	  fp32 relative_angle;     //rad
    fp32 relative_angle_set; //rad
    fp32 absolute_angle;     //rad
    fp32 absolute_angle_set; //rad
    fp32 motor_gyro;         //rad/s���ٶ�
    fp32 motor_gyro_set;			//rad/s
		fp32 rc_effective_stroke; //ң������Ч�г� ������������
		int16_t given_current;				//PID�����������ֵ
} Gimbal_Motor_t;

typedef struct
{
	int16_t pitch_channel;
	int16_t yaw_channel;
	
}Gimbal_Value_Limit_t;

typedef struct
{
    const RC_Type *gimbal_rc_ctrl;
    const fp32 *gimbal_INT_angle_point;
    const fp32 *gimbal_INT_gyro_point;
    Gimbal_Motor_t gimbal_yaw_motor;
    Gimbal_Motor_t gimbal_pitch_motor;
		gimbal_behaviour_e Gimbal_Motor_mode;
		Gimbal_Value_Limit_t gimbal_value_limit;//������Ҫ����ʱ��ŵĽṹ��
		
} Gimbal_Control_t;
	 
extern Gimbal_Control_t gimbal_control;
extern uint16_t gimbal_mode;//����������̨״̬
extern osThreadId vGimbal_TaskHandle;
void Gimbal_Task(void const * argument);
extern const Gimbal_Motor_t *get_yaw_motor_point(void);
extern const Gimbal_Motor_t *get_pitch_motor_point(void);
#ifdef __cplusplus
}
#endif
#endif /*__Gimbal_Task1_H */
