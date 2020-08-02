#ifndef _GIMBAL_TASK_H
#define _GIMBAL_TASK_H

#include "stm32f4xx_hal.h"

typedef struct
{
    int input_angle;  //起始角度
   	int exp_angle;    //目标角度
    int out;          //角度输出
    int min_angle;    //角度最小值
    int max_angle;    //角度最大值
    int add;          //每次增量
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
