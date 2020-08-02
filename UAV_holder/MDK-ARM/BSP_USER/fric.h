#ifndef _FRIC_H
#define _FRIC_H
#include "stm32f1xx_hal.h"


void fric_PWM_configuration(void);
void PWM_SetDuty(TIM_HandleTypeDef *tim,uint32_t tim_channel,float duty);
void fric_off(void);
void fric1_on(uint32_t cmd1);
void fric2_on(uint32_t cmd2);

#endif

