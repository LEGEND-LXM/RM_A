#ifndef __Chassis_Task_H
#define __Chassis_Task_H
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
#include "user_lib.h"
#include "Gimbal_Task1.h"
	 
	 
//����ʼ����һ��ʱ��
#define CHASSIS_TASK_INIT_TIME 357
//����������Ƽ�� 2ms
#define CHASSIS_CONTROL_TIME_MS 3
//����������Ƽ�� 0.002s
#define CHASSIS_CONTROL_TIME 0.002
//�����������Ƶ�ʣ���δʹ�������
#define CHASSIS_CONTROL_FREQUENCE 500.0f
	 
//ѡ�����״̬ ����ͨ����
#define MODE_CHANNEL 0
	 
//m3508ת���ɵ����ٶ�(m/s)�ı������������� ����Ϊ���ܻ������Ҫ��������
#define M3508_MOTOR_RPM_TO_VECTOR 0.000415809748903494517209f
#define CHASSIS_MOTOR_RPM_TO_VECTOR_SEN M3508_MOTOR_RPM_TO_VECTOR

	 
//�����˶��������ǰ���ٶ�x��
#define NORMAL_MAX_CHASSIS_SPEED_X 3.0f
//�����˶��������ƽ���ٶ�y��
#define NORMAL_MAX_CHASSIS_SPEED_Y 2.9f

//���̵������ٶ�
#define MAX_WHEEL_SPEED 4.0f
//����������ת�ٶȣ�����ǰ�������ֲ�ͬ�趨�ٶȵı�����Ȩ 0Ϊ�ڼ������ģ�����Ҫ����
#define CHASSIS_WZ_SET_SCALE 0.1f

#define SWING_MOVE_ANGLE 0.31415926575

//����3508���can���͵���ֵ
#define MAX_MOTOR_CAN_CURRENT 7500.0f //16000.0f
	 
//x��y������ٵ�ϵ��
#define CHASSIS_ACCEL_X_NUM 0.1666666667f
#define CHASSIS_ACCEL_Y_NUM 0.3333333333f 

#define MOTOR_SPEED_TO_CHASSIS_SPEED_VX 0.25f
#define MOTOR_SPEED_TO_CHASSIS_SPEED_VY 0.25f
#define MOTOR_SPEED_TO_CHASSIS_SPEED_WZ 0.25f
	 
#define MOTOR_DISTANCE_TO_CENTER 0.2f

//ҡ��ԭ�ز���ҡ�����Ƕ�(rad)
#define SWING_NO_MOVE_ANGLE 0.4f

//���̵���ٶȻ�PID
#define M3508_MOTOR_SPEED_PID_KP 13000.0f//1500
#define M3508_MOTOR_SPEED_PID_KI 10.0f
#define M3508_MOTOR_SPEED_PID_KD 0.0f
#define M3508_MOTOR_SPEED_PID_MAX_OUT MAX_MOTOR_CAN_CURRENT
#define M3508_MOTOR_SPEED_PID_MAX_IOUT 2000.0f

//������ת����PID
#define CHASSIS_FOLLOW_GIMBAL_PID_KP 40.0f
#define CHASSIS_FOLLOW_GIMBAL_PID_KI 5.0f
#define CHASSIS_FOLLOW_GIMBAL_PID_KD 0.0f
#define CHASSIS_FOLLOW_GIMBAL_PID_MAX_OUT 6.0f
#define CHASSIS_FOLLOW_GIMBAL_PID_MAX_IOUT 0.2f

//����ҡ�ڰ���
#define SWING_KEY KEY_PRESSED_OFFSET_CTRL


//����ǰ�����ҿ��ư���
#define CHASSIS_FRONT_KEY KEY_PRESSED_OFFSET_W
#define CHASSIS_BACK_KEY KEY_PRESSED_OFFSET_S
#define CHASSIS_LEFT_KEY KEY_PRESSED_OFFSET_A
#define CHASSIS_RIGHT_KEY KEY_PRESSED_OFFSET_D

#define CHASSIS_RC_DEADLINE 10

//ң����ǰ��ҡ�ˣ�max 660��ת���ɳ���ǰ���ٶȣ�m/s���ı���
#define CHASSIS_VX_RC_SEN 0.006f
//ң��������ҡ�ˣ�max 660��ת���ɳ��������ٶȣ�m/s���ı���
#define CHASSIS_VY_RC_SEN 0.005f

#define CHASSIS_ANGLE_Z_RC_SEN 0.006f//0.000002f
//��������̨��ʱ�� ң������yawң�ˣ�max 660��ת���ɳ�����ת�ٶȵı���
#define CHASSIS_WZ_RC_SEN 0.01f

extern moto_info_t motor_info[MOTOR_MAX_NUM];
extern pid_struct_t motor_pid[7];
/*****�����˶�״̬������ģʽ��ǩ*****/
typedef enum
{
  CHASSIS_VECTOR_FOLLOW_GIMBAL_YAW,	//���̸�����̨
  CHASSIS_VECTOR_FOLLOW_CHASSIS_YAW,//������
  CHASSIS_VECTOR_NO_FOLLOW_YAW,			//���̲�������̨
	CHASSIS_VECTOR_SMALL_TOP_YAW,			//С���ݱ�ǩ ������
  CHASSIS_VECTOR_RAW,								//������
} chassis_mode_e;

typedef struct
{
  const moto_info_t *chassis_motor_measure;
  fp32 accel;
  fp32 speed;
  fp32 speed_set;
  int16_t give_current;
} Chassis_Motor_t;


/*****�����˶�����������*****/
typedef struct
{
  const RC_Type *chassis_RC;               //����ʹ�õ�ң����ָ��
  const Gimbal_Motor_t *chassis_yaw_motor;   //����ʹ�õ�yaw��̨�������ԽǶ���������̵�ŷ����
  const Gimbal_Motor_t *chassis_pitch_motor; //����ʹ�õ�pitch��̨�������ԽǶ���������̵�ŷ����
  const fp32 *chassis_INS_angle;             //��ȡ�����ǽ������ŷ����ָ��
  chassis_mode_e chassis_mode;               //���̿���״̬��
  chassis_mode_e last_chassis_mode;          //�����ϴο���״̬��
  
	//������bsp_can.h�е�rm���ͳһ���ݽṹ�岻��Ӧ������bugʱ��Ҫ�Ų�����
	Chassis_Motor_t motor_chassis[4];          //���̵������
	
	
  pid_struct_t motor_speed_pid[4];             //���̵���ٶ�pid
  pid_struct_t chassis_angle_pid;              //���̸���Ƕ�pid

  first_order_filter_type_t chassis_cmd_slow_set_vx;
  first_order_filter_type_t chassis_cmd_slow_set_vy;

  fp32 vx;                         //�����ٶ� ǰ������ ǰΪ������λ m/s
  fp32 vy;                         //�����ٶ� ���ҷ��� ��Ϊ��  ��λ m/s
  fp32 wz;                         //������ת���ٶȣ���ʱ��Ϊ�� ��λ rad/s
  fp32 vx_set;                     //�����趨�ٶ� ǰ������ ǰΪ������λ m/s
  fp32 vy_set;                     //�����趨�ٶ� ���ҷ��� ��Ϊ������λ m/s
  fp32 wz_set;                     //�����趨��ת���ٶȣ���ʱ��Ϊ�� ��λ rad/s
  fp32 chassis_relative_angle;     //��������̨����ԽǶȣ���λ rad/s
  fp32 chassis_relative_angle_set; //���������̨���ƽǶ�
  fp32 chassis_yaw_set;

  fp32 vx_max_speed;  //ǰ����������ٶ� ��λm/s
  fp32 vx_min_speed;  //ǰ��������С�ٶ� ��λm/s
  fp32 vy_max_speed;  //���ҷ�������ٶ� ��λm/s
  fp32 vy_min_speed;  //���ҷ�����С�ٶ� ��λm/s
  fp32 chassis_yaw;   //�����Ǻ���̨������ӵ�yaw�Ƕ�
  fp32 chassis_pitch; //�����Ǻ���̨������ӵ�pitch�Ƕ�
  fp32 chassis_roll;  //�����Ǻ���̨������ӵ�roll�Ƕ�

} chassis_move_t;
	 
void Chassis_Task(void const * argument);	 
void chassis_rc_to_control_vector(fp32 *vx_set, fp32 *vy_set, chassis_move_t *chassis_move_rc_to_vector);
extern chassis_move_t chassis_move; 
#ifdef __cplusplus
}
#endif
#endif /*__ usart_H */
