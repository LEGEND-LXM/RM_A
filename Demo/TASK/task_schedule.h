

#ifndef __TASK_SCHEDULE
#define __TASK_SCHEDULE

#include "task_tatal.h"

#define OFF_GPS            5
#define OFF_ATTI_1         7
#define OFF_ATTI_2         6
#define CL_GPS             13
#define CL_ATTI_1          15
#define CL_ATTI_2          14
#define HL_GPS             9
#define HL_ATTI_1          11
#define HL_ATTI_2          10

typedef struct {
	uint8_t IMU_flag ;
  uint8_t WAVE_flag ;
	uint8_t CHASSIS_flag ;
	uint8_t HOLDER_flag ;
	uint8_t SHOOT_flag ;
	uint8_t SCHEDULE_flag ;
}SCHEDULE_flag_Type;


typedef struct {
	uint8_t SCHEDULE_i ;
  SCHEDULE_flag_Type flag_Type ;
}SCHEDULE_Type;

extern SCHEDULE_Type SCHEDULE_Ture ;

void StartTask_Schedule(void const * argument);  






#endif







