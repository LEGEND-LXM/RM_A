#ifndef __ROBOMASTER_CONTROL
#define __ROBOMASTER_CONTROL

#include "robomaster_common.h"
//typedef struct {
//	float init;    //�����ϵ�궨yawֵ
//	float mid;     //������ҡ�˻���ʱ�궨���̵�yawֵ
//	
//	
//}IMU_Type;

#define N                  4         //����ƽ���˲�����
extern float Data[N];
extern int32_t set_spd;
void PWM_SetDuty(TIM_HandleTypeDef *tim,uint32_t tim_channel,float duty);
void Ammunition_feed1(void);  //�������
void Ammunition_feed2(void);  //����С����
void chassis_control(void);//���̿���  ����ģʽ
void Acquire1(void);
float GildeAverageValueFilter(float NewValue,float *Data);
void set_chassis_moto_target_zero(void);
void Electromagnet_save(void);
void Card_save();
void Acquire1(void);      //��ȡ����
void Acquire2(void);      //��ȡС����
void  pinch_control1(int pinch_target);  //���ɵ������
void  pinch_control2(int pinch_target);   //��ȡ�������

#endif

