#include "fric.h"
#include "stm32_hal_legacy.h"
#include "tim.h"
void fric_PWM_configuration(void) 
{
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3); 
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);

	  __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3, 900);
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_4, 900);
}
void PWM_SetDuty(TIM_HandleTypeDef *tim,uint32_t tim_channel,float duty)
{
	switch(tim_channel){	
		case TIM_CHANNEL_3: tim->Instance->CCR3 =duty;break;
		case TIM_CHANNEL_4: tim->Instance->CCR4 =duty;break;
	}
}
void fric_off(void)
{
    PWM_SetDuty(&htim1,TIM_CHANNEL_3,900);    //off 900   on 1900
    PWM_SetDuty(&htim1,TIM_CHANNEL_4,900);
}
void fric1_on(uint32_t cmd1)
{
    PWM_SetDuty(&htim1,TIM_CHANNEL_3,cmd1);
}
void fric2_on(uint32_t cmd2)
{
    PWM_SetDuty(&htim1,TIM_CHANNEL_4,cmd2);
}
