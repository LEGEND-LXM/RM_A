





#ifndef __TASK_CHASSIS
#define __TASK_CHASSIS

#include "task_tatal.h"

#define motor_1   1
#define motor_2   2
#define motor_3   3
#define motor_4   4

typedef struct {
	int32_t Chassis_motor_voltage[4];
	uint8_t Mode;
	uint8_t Chassis_i;
	

}CHASSIS_Type;


void StartTask_Chassis(void const * argument); 
int16_t Dead_zone_immune(int16_t CHx ,uint16_t Dead_line);    //死区限定函数（int16_t型）


#endif















