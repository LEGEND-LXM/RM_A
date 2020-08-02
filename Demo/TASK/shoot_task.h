#ifndef __TASK_SHOOT
#define __TASK_SHOOT

#include "task_tatal.h"

#define up    0
#define down  1
typedef struct {
	uint8_t mode;
	uint16_t Mode_Value[5] ;
//	uint16_t PWM1_value;
//	uint16_t PWM2_value;
	
}SHOOT_State_Type;


typedef struct {
	uint8_t SHOOT_i;
	uint8_t target_time ;
	float target_angle ;
	uint16_t target_speed ;	
	uint32_t PreviousWakeTime ;
	float benchmark_time ;
	uint16_t benchmark_angle ;
	uint16_t benchmark_speed ;
	uint16_t PWM_Target_Value[2] ;
	uint16_t PWM_Value[2] ;
	int16_t Ammunition_Booster_voltage ;
  SHOOT_State_Type SHOOT_State ;
	uint8_t Mode;
}SHOOT_Type;



void StartTask_Shoot(void const * argument); 



//extern SHOOT_Type SHOOT_Ture ;
//extern pid_struct_t Frictiongear_motor_PID[2] ;     //摩擦轮PID结构体
//extern pid_struct_t Ammunition_Booster_PID ;        //拨弹电机PID结构体
//extern moto_info_t  Ammunition_Booster_info ;       //拨弹电机CAN结构体


#endif

















