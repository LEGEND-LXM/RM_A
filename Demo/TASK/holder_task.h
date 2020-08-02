



#ifndef __TASK_HOLDER
#define __TASK_HOLDER

#include "task_tatal.h"
#define Pitch   0
#define Yaw     1
#define Pitch_Init_value    3080   //3080~~135°
#define Yaw_Init_value      5440   //5440~~239°

typedef struct {
	
	uint16_t fe_angle ;     //反馈（实际）角度
	float re_angle ;        //目标角度
	float A_speed ;         //角速度
  int16_t speed ;         //速度 	 
	int16_t voltage ;       //电压输出值
	float standard_angle;   //标准参考角度

}Parameter_Type;

typedef struct {
	
	uint8_t HALDER_i ;
  Parameter_Type halder_motor[2] ;
	uint8_t Mode;
}HALDER_Type;

extern HALDER_Type HALDER_Ture;

void StartTask_Holder(void const * argument);
void Holder_Information_Transfer(void);
 int16_t Dead_zone_immune_angle(int16_t CHx ,uint16_t Dead_line);

//extern HALDER_Type HALDER_Ture ;
//extern pid_struct_t Holder_motor_PID[2];
//extern moto_info_t  Holder_motor_info[2] ;
#endif













