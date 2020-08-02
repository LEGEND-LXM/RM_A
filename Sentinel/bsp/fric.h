#ifndef FRIC_H
#define FRIC_H
#include "main.h"
#include "stm32f4xx_hal.h"

#define Fric_ON 1150
#define Fric_OFF  1000

extern void fric_PWM_configuration(void);
void PWM_SetDuty(TIM_HandleTypeDef *tim,uint32_t tim_channel,float duty);
extern void fric_off(void);
extern void fric1_on(uint32_t cmd1);
extern void fric2_on(uint32_t cmd2);
#endif
