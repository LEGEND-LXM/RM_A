#ifndef _TIMDELAY_H
#define _TIMDELAY_H

#include "stm32f4xx_hal.h"

void TIM7_Delay_Init(void);
void TIM7_Delay_Us(uint16_t us);
void TIM_Delay_ms(uint16_t nms);

#endif
