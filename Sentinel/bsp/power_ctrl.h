#ifndef POWER_CTRL_H
#define POWER_CTRL_H
#include "main.h"
#include "stm32f4xx_hal.h"

#define POWER1_CTRL_SWITCH 0
#define POWER2_CTRL_SWITCH 1
#define POWER3_CTRL_SWITCH 2
#define POWER4_CTRL_SWITCH 3

extern void power_ctrl_onall(void);
extern void power_ctrl_offall(void);
extern void power_ctrl_on(uint8_t num);
extern void power_ctrl_off(uint8_t num);

#endif
