
#include "visual_task.h"

VISUAL_Type VISUAL_Ture ;
uint8_t ab[4] = {1,2,3,4};
/**
*视觉处理任务
*作用 ：接收电脑传回的数据并解析
*flag ;               //标志位
*RInit_data[8] ;      //接收的初始数据
*Coordinates[2] ;    //方位偏移:Coordinates[0] --- Pitch and Coordinates[1] --- Raw
*RDecode_data[5] ;   //处理后数据
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
				VISUAL_Ture.RDecode_data[2] = VISUAL_Ture.RInit_data[5] | VISUAL_Ture.RInit_data[6] << 8 ; // 视野内是否有目标（有0x1100;无0x0011）
				if( VISUAL_Ture.RDecode_data[2] == 0x1100) 
					{  // 有目标是获取偏移角度（单位 ：度--°）
						VISUAL_Ture.RDecode_data[0] = VISUAL_Ture.RInit_data[1] | VISUAL_Ture.RInit_data[2] << 8 ; // Pitch
						VISUAL_Ture.RDecode_data[1] = VISUAL_Ture.RInit_data[3] | VISUAL_Ture.RInit_data[4] << 8 ; // Yaw
					}
				else if ( VISUAL_Ture.RDecode_data[2] == 0x0011 ) 
					{  // 无目标时清 0
						VISUAL_Ture.RDecode_data[0] = 0 ; 
						VISUAL_Ture.RDecode_data[1] = 0 ; 
						
					}	
				VISUAL_Ture.Pitch_deviation = VISUAL_Ture.RDecode_data[0] ;  // Pitch轴偏差
				VISUAL_Ture.Raw_deviation = VISUAL_Ture.RDecode_data[1] ;  // Yaw轴偏差
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



