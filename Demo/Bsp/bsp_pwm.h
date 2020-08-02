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
 
#ifndef __BSP_PWM
#define __BSP_PWM

#define Left_Channel     TIM_CHANNEL_1
#define Right_Channel    TIM_CHANNEL_2

#include "task_tatal.h"
#include "tim.h"
#define __HAL_TIM_DIRECTION_STATUS      __HAL_TIM_IS_TIM_COUNTING_DOWN
#define __HAL_TIM_PRESCALER             __HAL_TIM_SET_PRESCALER
#define __HAL_TIM_SetCounter            __HAL_TIM_SET_COUNTER
#define __HAL_TIM_GetCounter            __HAL_TIM_GET_COUNTER
#define __HAL_TIM_SetAutoreload         __HAL_TIM_SET_AUTORELOAD
#define __HAL_TIM_GetAutoreload         __HAL_TIM_GET_AUTORELOAD
#define __HAL_TIM_SetClockDivision      __HAL_TIM_SET_CLOCKDIVISION
#define __HAL_TIM_GetClockDivision      __HAL_TIM_GET_CLOCKDIVISION
#define __HAL_TIM_SetICPrescaler        __HAL_TIM_SET_ICPRESCALER
#define __HAL_TIM_GetICPrescaler        __HAL_TIM_GET_ICPRESCALER
#define  __HAL_TIM_SetCompare    __HAL_TIM_SET_COMPARE
#define  __HAL_TIM_GetCompare    __HAL_TIM_GET_COMPARE

/******摩擦轮****/

#define Fric_ON 1150
#define Fric_OFF  1000

 void fric_PWM_configuration(void);
void PWM_SetDuty(TIM_HandleTypeDef *tim,uint32_t tim_channel,float duty);
 void fric_off(void);
 void fric1_on(uint32_t cmd1);
 void fric2_on(uint32_t cmd2);
/****************/

void pwm_init(void);   //PWM通道初始化
void user_pwm_setvalue(TIM_HandleTypeDef *htim, uint32_t Channel ,uint16_t value); //调节PWM占空比
void Frictiongear_Init(void);   //摩擦轮电机初始化
#endif
