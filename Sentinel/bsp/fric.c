#include "fric.h"
#include "stm32f4xx_hal.h"
#include "tim.h"
#include "user_lib.h"

void fric_PWM_configuration(void) 
{
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1); 
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);

		ramp_calc(&fric_pwm,1000);
	  __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, fric_pwm.out);
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_4, fric_pwm.out);
		 
		HAL_Delay(4000);
		__HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, 1000);
			__HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_4, 1000);
		HAL_Delay(4000);
}


void PWM_SetDuty(TIM_HandleTypeDef *tim,uint32_t tim_channel,float duty)
{
	switch(tim_channel){	
		case TIM_CHANNEL_1: tim->Instance->CCR1 =duty;break;
		case TIM_CHANNEL_4: tim->Instance->CCR4 =duty;break;
	}
}
	
void fric_off(void)
{
    PWM_SetDuty(&htim1,TIM_CHANNEL_1,Fric_OFF);
    PWM_SetDuty(&htim1,TIM_CHANNEL_4,Fric_OFF);
}
void fric1_on(uint32_t cmd1)
{
    PWM_SetDuty(&htim1,TIM_CHANNEL_1,cmd1);
}
void fric2_on(uint32_t cmd2)
{
    PWM_SetDuty(&htim1,TIM_CHANNEL_4,cmd2);
}


