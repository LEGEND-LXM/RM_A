#ifndef BUZZER_H
#define BUZZER_H
#include "main.h"
#include "stm32f4xx_hal.h"

extern void buzzer_on(uint16_t psc, uint16_t pwm);
extern void buzzer_off(void);

#endif
