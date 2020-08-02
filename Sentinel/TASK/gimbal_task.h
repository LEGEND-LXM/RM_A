#ifndef _GIMBAL_TASK_H
#define _GIMBAL_TASK_H

#include "stm32f4xx_hal.h"

typedef struct
{
    int input_angle;  //��ʼ�Ƕ�
   	int exp_angle;    //Ŀ��Ƕ�
    int out;          //�Ƕ����
    int min_angle;    //�Ƕ���Сֵ
    int max_angle;    //�Ƕ����ֵ
    int add;          //ÿ������
} gimbal_checktask;



extern volatile float speed_YAW;
extern volatile float speed_PIT;
extern gimbal_checktask GIMBALCHECK;
extern int16_t mpuspeed_pit,mpuspeed_yaw,mpu_pit,mpu_yaw;	

extern void Get_Anglespeed(void);
extern void control_fricon (void);

extern void gimablcheck_init(gimbal_checktask *gimbal_check_type, int add, int max, int min);
extern void gimablcheck_calc(gimbal_checktask *gimbal_check_type, int input_angle, int exp_angle);

extern void offline_control(void);
extern void manual_control(void);
extern void shoot_control(void);
extern void MPU6050_control(void);
extern void moto_control(void);
extern void chassis_control(void);
extern void bodan_control(void);
extern void decision(void);
extern void run_speed(int speed);
#endif
