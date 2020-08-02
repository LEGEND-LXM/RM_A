#ifndef _BSP_INIT_H
#define _BSP_INIT_H

#include "stm32f4xx_hal.h"
#include "main.h"
#include "can.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "usb_device.h"
#include "gpio.h"
#include "myiic.h"

void param_init(void);
void system_init(void);
void hardware_init(void);
extern void SELFCHECK_param_init(void);


#endif
