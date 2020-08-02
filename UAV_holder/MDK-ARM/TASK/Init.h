#ifndef __INIT__H
#define __INIT__H


	
#include "stm32f1xx.h"
#include "cmsis_os.h"
#include "adc.h"
#include "can.h"
#include "dma.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"
#include "bsp_can.h"
#include "pid.h"
#include "stdio.h"
#include "stdint.h"
#include "holder_task.h"
#include "shoot_task.h"
#include "test_task.h"
#include "Remote_Control.h"
#include "filter.h"
#include <time.h>
#include "robomaster_vcan.h"
#include "tim.h"
#include "stm32_hal_legacy.h"
#include "user_lib.h"
#include "math.h"
#include "laser.h"
#include "TIM_delay.h"
#include "bsp_mpu9250.h"
#include "mpu9250.h"
#include "fric.h"
void  User_Init(void);
void Task_Init(void);
extern  osThreadId holder_TaskHandle;
extern  osThreadId shoot_TaskHandle;
#define ABS(x)		((x>0)? (x): (-x)) 
#endif
