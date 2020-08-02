
#include "visual_task.h"

VISUAL_Type VISUAL_Ture ;
uint8_t ab[4] = {1,2,3,4};
/**
*�Ӿ���������
*���� �����յ��Դ��ص����ݲ�����
*flag ;               //��־λ
*RInit_data[8] ;      //���յĳ�ʼ����
*Coordinates[2] ;    //��λƫ��:Coordinates[0] --- Pitch and Coordinates[1] --- Raw
*RDecode_data[5] ;   //���������
*/
void StartTask_Visual(void const * argument) 
{
	osDelay(1);
			VISUAL_Ture.Pitch_deviation = 0 ;
			VISUAL_Ture.Raw_deviation = 0 ;
	VISUAL_Ture.flag = 0 ;
	for(;;)
	{
		if(remote_control.switch_left == 3 && remote_control.switch_right == 1)
			VISUAL_Ture.flag = 1 ;
		else
			VISUAL_Ture.flag = 0 ;
		
		if(( VISUAL_Ture.RInit_data[0] == 0x1a) && (VISUAL_Ture.RInit_data[7] == 0x7a ))
			{
				VISUAL_Ture.RDecode_data[2] = VISUAL_Ture.RInit_data[5] | VISUAL_Ture.RInit_data[6] << 8 ; // ��Ұ���Ƿ���Ŀ�꣨��0x1100;��0x0011��
				if( VISUAL_Ture.RDecode_data[2] == 0x1100) 
					{  // ��Ŀ���ǻ�ȡƫ�ƽǶȣ���λ ����--�㣩
						VISUAL_Ture.RDecode_data[0] = VISUAL_Ture.RInit_data[1] | VISUAL_Ture.RInit_data[2] << 8 ; // Pitch
						VISUAL_Ture.RDecode_data[1] = VISUAL_Ture.RInit_data[3] | VISUAL_Ture.RInit_data[4] << 8 ; // Yaw
					}
				else if ( VISUAL_Ture.RDecode_data[2] == 0x0011 ) 
					{  // ��Ŀ��ʱ�� 0
						VISUAL_Ture.RDecode_data[0] = 0 ; 
						VISUAL_Ture.RDecode_data[1] = 0 ; 
						
					}	
				VISUAL_Ture.Pitch_deviation = VISUAL_Ture.RDecode_data[0] ;  // Pitch��ƫ��
				VISUAL_Ture.Raw_deviation = VISUAL_Ture.RDecode_data[1] ;  // Yaw��ƫ��
					HAL_GPIO_WritePin( GPIOG , LED8_Pin, GPIO_PIN_SET);
			}
	  else
			{
				
				for( VISUAL_Ture.i=0 ;VISUAL_Ture.i <8 ;VISUAL_Ture.i++)
				 {
					 VISUAL_Ture.RInit_data[VISUAL_Ture.i] = 0;
				 }  
				 VISUAL_Ture.Pitch_deviation = 0;
				 VISUAL_Ture.Raw_deviation = 0;
				HAL_GPIO_WritePin( GPIOG , LED8_Pin, GPIO_PIN_RESET);
			}		
    CDC_Transmit_FS(ab ,4); 
		osDelay(1);
		
	}
}



