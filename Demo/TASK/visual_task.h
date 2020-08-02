#ifndef __TASK_VISUAL
#define __TASK_VISUAL

#include "task_tatal.h"
//#define X_Middle   320     //视觉中心点坐标---X
//#define Y_Middle   256     //视觉中心点坐标---Y

//#define X_Max  640     //视觉最大坐标---X
//#define Y_Max   512     //视觉中最大坐标---Y

typedef struct {
	
	uint8_t i ;                  //
	uint8_t flag ;               //标志位
  int8_t RInit_data[8] ;       //接收的初始数据
	int16_t RDecode_data[3] ;    //处理后数据
	int16_t Pitch_deviation ;    // 方位偏移
	int16_t Raw_deviation ;      // 方位偏移
}VISUAL_Type;
extern VISUAL_Type VISUAL_Ture ;

void StartTask_Visual(void const * argument) ;

#endif


