#ifndef _LED_H
#define _LED_H

#include "stm32f4xx_hal.h"
#include "main.h"

void greenled_ctrl_on(uint16_t GPIO_Pin);
void greenled_ctrl_off(uint16_t GPIO_Pin);

void single_green_off(void);
void single_green_on(void);
void single_red_off(void);
void single_red_on(void);

#endif
