#include "waveform_task.h"
extern CHASSIS_Type CHASSIS_Ture ;
extern SHOOT_Type SHOOT_Ture ;
/*
*������������
*���� �������ڵ���ʱ���ô��ڷ�����Ҫ��ʾ�Ĳ����Ĳ���
*
*/
void StartTask_Waveform(void const * argument) 
{
	osDelay(2);
	
	for(;;)
  {
	 osDelay(1);
   HAL_GPIO_WritePin( GPIOG , LED4_Pin, GPIO_PIN_SET);
	 wave_form_data[0] = PWM_INPUT_Ture[1].period ;
	 wave_form_data[1] = PWM_INPUT_Ture[0].period ;
//	 wave_form_data[2] = (short)VISUAL_Ture.Coordinates[0] ;
//	 wave_form_data[3] = (short)VISUAL_Ture.Coordinates[1] ;
	 wave_form_data[4] = PWM_INPUT_Ture[0].frequency ;
   wave_form_data[5] = PWM_INPUT_Ture[1].frequency;	
//	 wave_form_data[2] = VISUAL_Ture.RDecode_data[0] ;
//	 wave_form_data[3] = VISUAL_Ture.RDecode_data[1] ;
	 wave_form_data[6] = SHOOT_Ture.PWM_Value[up] ;
	 wave_form_data[7] = SHOOT_Ture.PWM_Value[down] ;
		
//	 wave_form_data[6] = 1100;
//   wave_form_data[7] = 1300;
		shanwai_send_wave_form();
		HAL_GPIO_WritePin( GPIOG , LED4_Pin, GPIO_PIN_SET);
		osDelay(2);
  }
	
	
}


