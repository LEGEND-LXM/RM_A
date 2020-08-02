

#ifndef __TASK_IMU
#define __TASK_IMU

#include "task_tatal.h"

typedef struct {
	uint8_t IMU_i;
	//IMU_DATA_Angle[1]:pitch
  //IMU_DATA_Angle[2]:rol
  //IMU_DATA_Angle[3]:yaw
	float IMU_DATA_Angle[3][20] ; 
	//IMU_DATA_Angle_Acceleration[1]:pitch_Acceleration
  //IMU_DATA_Angle_Acceleration[2]:rol_Acceleration
  //IMU_DATA_Angle_Acceleration[3]:yaw_Acceleration
  float IMU_DATA_Angle_Acceleration[3][20] ;  

}IMU_Type;

extern IMU_Type IMU_Ture;

void StartTask_Imu(void const * argument);

#endif



