#ifndef __TASK_VISUAL
#define __TASK_VISUAL

#include "task_tatal.h"
//#define X_Middle   320     //�Ӿ����ĵ�����---X
//#define Y_Middle   256     //�Ӿ����ĵ�����---Y

//#define X_Max  640     //�Ӿ��������---X
//#define Y_Max   512     //�Ӿ����������---Y

typedef struct {
	
	uint8_t i ;                  //
	uint8_t flag ;               //��־λ
  int8_t RInit_data[8] ;       //���յĳ�ʼ����
	int16_t RDecode_data[3] ;    //���������
	int16_t Pitch_deviation ;    // ��λƫ��
	int16_t Raw_deviation ;      // ��λƫ��
}VISUAL_Type;
extern VISUAL_Type VISUAL_Ture ;

void StartTask_Visual(void const * argument) ;

#endif


