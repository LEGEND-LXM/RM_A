#ifndef __BSP_TIM
#define __BSP_TIM

#include "task_tatal.h"
//PWM���벶��

#define Left  0
#define Right  1

#define FALLIN  0
#define RISING  1

typedef struct {
	
	uint8_t uhCaptureIndex ;      //���ת����־λ
	uint32_t uwIC2Value_High[2] ; //�������θߵ�ƽ�Ĵ�������ֵ
	uint32_t uwIC2Value_Low ;     //�������θߵ�ƽ��͵�ƽ�Ĵ�������ֵ
	uint32_t High_Time ;          //һ�������ڸߵ�ƽʱ��
	uint32_t Low_Time ;           //һ�������ڵ͵�ƽʱ��
	uint32_t re_speed ;           //Ŀ��ת��
	float fe_speed ;           //����ת��
	float period ;                //����
  float frequency ;             //Ƶ��
	float Coefficient ;           //ת�ٱ���ϵ��
	
}PWM_INPUT_Type;

extern PWM_INPUT_Type PWM_INPUT_Ture[2];


void user_ic_config(TIM_HandleTypeDef *htim ,uint32_t Channel ,uint16_t value) ;//����״̬�л�
void Computation_period_frequency(PWM_INPUT_Type* PWM_INPUT ,uint32_t* Value_High ,uint32_t Value_Low ); //����Ħ�������ڡ�Ƶ�ʡ�ת��
#endif





