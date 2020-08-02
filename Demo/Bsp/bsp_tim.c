#include "bsp_tim.h"

PWM_INPUT_Type PWM_INPUT_Ture[2];



//PWM检测

/**
  * 函数功能: TIM_IC配置
  * 输入参数: value
  * 返 回 值: 无
  * 说    明: 无
  */
void user_ic_config(TIM_HandleTypeDef *htim ,uint32_t Channel ,uint16_t value) //捕获状态切换
{
    TIM_IC_InitTypeDef sConfigIC;
    if(value != 0)  //1
    {
        sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_RISING;//上升沿
    }
    else//0
    {
        sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_FALLING; //下降沿
    }
    sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
    sConfigIC.ICPrescaler = TIM_ICPSC_DIV1;
    sConfigIC.ICFilter = 0;
    HAL_TIM_IC_ConfigChannel(htim, &sConfigIC, Channel);
}
 
/**
  * 函数功能: TIM_IC回调函数
  * 输入参数: htim
  * 返 回 值: 无
  * 说    明: 得到转速
  */

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{  
	if(htim->Instance == TIM2)
	{
    switch((uint32_t)htim->Channel)
		{
			case HAL_TIM_ACTIVE_CHANNEL_1:
			{
				switch(PWM_INPUT_Ture[Left].uhCaptureIndex)
				{
					case 0:
							PWM_INPUT_Ture[Left].uhCaptureIndex = 1;
							PWM_INPUT_Ture[Left].uwIC2Value_High[0] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);         
							user_ic_config(&htim2 ,TIM_CHANNEL_1 ,FALLIN );           //下降
							if(HAL_TIM_IC_Start_IT(htim, TIM_CHANNEL_1) != HAL_OK){}  //中断
						break;
					case 1:
							PWM_INPUT_Ture[Left].uhCaptureIndex = 2;
							PWM_INPUT_Ture[Left].uwIC2Value_Low = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);            
							user_ic_config(&htim2 ,TIM_CHANNEL_1 ,RISING );           //上升
							if(HAL_TIM_IC_Start_IT(htim, TIM_CHANNEL_1) != HAL_OK){}
						break;
					case 2:
							PWM_INPUT_Ture[Left].uhCaptureIndex = 0; 
							PWM_INPUT_Ture[Left].uwIC2Value_High[1] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);													
							if(HAL_TIM_IC_Start_IT(htim, TIM_CHANNEL_1) != HAL_OK){}   //中断	
               	Computation_period_frequency(&PWM_INPUT_Ture[Left] ,PWM_INPUT_Ture[Left].uwIC2Value_High 
																																	 ,PWM_INPUT_Ture[Left].uwIC2Value_Low );							
						break;
				 default :
						break;
				}
			}
				break;
			
			case HAL_TIM_ACTIVE_CHANNEL_2:
			{
				switch(PWM_INPUT_Ture[Right].uhCaptureIndex)
				{
					case 0:
							PWM_INPUT_Ture[Right].uhCaptureIndex = 1;
							PWM_INPUT_Ture[Right].uwIC2Value_High[0] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);         
							user_ic_config(&htim2 ,TIM_CHANNEL_2 ,FALLIN );           //下降
							if(HAL_TIM_IC_Start_IT(htim, TIM_CHANNEL_2) != HAL_OK){}  //中断
						break;
					case 1:
							PWM_INPUT_Ture[Right].uhCaptureIndex = 2;
							PWM_INPUT_Ture[Right].uwIC2Value_Low = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);            
							user_ic_config(&htim2 ,TIM_CHANNEL_2 ,RISING );           //上升
							if(HAL_TIM_IC_Start_IT(htim, TIM_CHANNEL_2) != HAL_OK){}
						break;
					case 2:
							PWM_INPUT_Ture[Right].uhCaptureIndex = 0; 
							PWM_INPUT_Ture[Right].uwIC2Value_High[1] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);						
							user_ic_config(&htim2 ,TIM_CHANNEL_2 ,RISING );           //下降
							if(HAL_TIM_IC_Start_IT(htim, TIM_CHANNEL_2) != HAL_OK){}   //中断	
               	Computation_period_frequency(&PWM_INPUT_Ture[Right] ,PWM_INPUT_Ture[Right].uwIC2Value_High 
																																	  ,PWM_INPUT_Ture[Right].uwIC2Value_Low );							
			
								break;
					default :
						break;
				}
			}
				break;
			default :
				break;
		}
	}    
 }

void Computation_period_frequency(PWM_INPUT_Type* PWM_INPUT ,uint32_t* Value_High ,uint32_t Value_Low )
{
	if(Value_Low >= Value_High[0])                                //一个周期内高电平时间
		PWM_INPUT -> High_Time = Value_Low - Value_High[0] ;    
	else
		if(Value_Low < Value_High[0])
			PWM_INPUT -> High_Time = ( 65536 - Value_High[0] ) + Value_Low  ;

	if(Value_High[1] >= Value_Low)                                //一个周期内低电平时间
		PWM_INPUT -> Low_Time = Value_High[1] - Value_Low ;    
	else
		if(Value_High[1] < Value_Low)
			PWM_INPUT -> Low_Time = ( 65536 - Value_Low ) + Value_High[1]  ;
		
	
	PWM_INPUT -> period = (PWM_INPUT -> High_Time + PWM_INPUT -> Low_Time)*0.001f ;  //周期 ms
	
	PWM_INPUT -> frequency = 1/(PWM_INPUT -> period *0.001f) ;   //频率 
	
	PWM_INPUT -> fe_speed = PWM_INPUT -> frequency * PWM_INPUT->Coefficient ;  //转速
}




