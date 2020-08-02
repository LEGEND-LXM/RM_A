/****************************************************************************
 *  Copyright (C) 2018 RoboMaster.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of 
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#include "bsp_pwm.h"
#include "stm32f4xx_hal_tim.h"
/**
  * @brief  start pwm output
  * @param  None
  * @retval None
  */
void pwm_init(void)
{
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);     //摩擦轮上边通道开启
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);     //摩擦轮下边通道开启
//    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
//    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4);

}

void user_pwm_setvalue(TIM_HandleTypeDef *htim, uint32_t Channel ,uint16_t value)
{
    TIM_OC_InitTypeDef sConfigOC;

    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = value;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(htim, &sConfigOC, Channel);
    HAL_TIM_PWM_Start(htim, Channel);  
}

void fric_PWM_configuration(void) 
{
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1); 
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);

////		ramp_calc(&fric_pwm,900);
//	  __HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_1, fric_pwm.out);
//    __HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_2, fric_pwm.out);
//	
		__HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_1, 1800);
		__HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_2, 1800);
		HAL_Delay(3000);
		__HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_1, 1000);
		__HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_2, 1000);
		HAL_Delay(3000);
}


void PWM_SetDuty(TIM_HandleTypeDef *tim,uint32_t tim_channel,float duty)
{
	switch(tim_channel){	
		case TIM_CHANNEL_1: tim->Instance->CCR1 =duty;break;
		case TIM_CHANNEL_2: tim->Instance->CCR2 =duty;break;
	}
}
	
void fric_off(void)
{
    PWM_SetDuty(&htim4,TIM_CHANNEL_1,Fric_OFF);
    PWM_SetDuty(&htim4,TIM_CHANNEL_2,Fric_OFF);
}
void fric1_on(uint32_t cmd1)
{
    PWM_SetDuty(&htim4,TIM_CHANNEL_1,cmd1);
}
void fric2_on(uint32_t cmd2)
{
    PWM_SetDuty(&htim4,TIM_CHANNEL_2,cmd2);
}
