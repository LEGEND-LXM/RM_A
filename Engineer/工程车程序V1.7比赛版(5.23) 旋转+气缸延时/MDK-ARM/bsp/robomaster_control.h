#ifndef __ROBOMASTER_CONTROL
#define __ROBOMASTER_CONTROL

#include "robomaster_common.h"
//typedef struct {
//	float init;    //底盘上电标定yaw值
//	float mid;     //当左右摇杆回中时标定底盘的yaw值
//	
//	
//}IMU_Type;

#define N                  4         //滑动平均滤波参数
extern float Data[N];
extern int32_t set_spd;
void PWM_SetDuty(TIM_HandleTypeDef *tim,uint32_t tim_channel,float duty);
void Ammunition_feed1(void);  //给予大弹丸
void Ammunition_feed2(void);  //给予小弹丸
void chassis_control(void);//底盘控制  两种模式
void Acquire1(void);
float GildeAverageValueFilter(float NewValue,float *Data);
void set_chassis_moto_target_zero(void);
void Electromagnet_save(void);
void Card_save();
void Acquire1(void);      //获取大弹丸
void Acquire2(void);      //获取小弹丸
void  pinch_control1(int pinch_target);  //弹飞电机工作
void  pinch_control2(int pinch_target);   //夹取电机工作

#endif

