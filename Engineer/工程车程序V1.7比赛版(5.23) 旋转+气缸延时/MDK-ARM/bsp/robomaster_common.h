#ifndef __ROBOMASTER_COMMON
#define __ROBOMASTER_COMMON

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"
#include "main.h"
#include "stm32f4xx_hal.h"
#include "can.h"
#include "dma.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "mytype.h"
#include <math.h>
/* USER CODE BEGIN Includes */
#include "bsp_can.h"
#include "pid.h"
#include "myiic.h"
#include "Remote_Control.h"
#include "bsp_imu.h"
#include "ist8310_reg.h"
#include "mpu6500_reg.h"
#include "robomaster_vcan.h"
#include "robomaster_control.h"
#include "robomaster_task.h"
#include "robomaster_filter.h"
#include "vector3.h"
#include "robomaster_calibrate.h"
#include "robot_status.h"
#include "pan_tilt_control.h"
#include "bling.h"
#include "delay.h"
#include "hcsr04.h"
#include "Keyboard_Control.h"
/* USER CODE END Includes */

	#define CHASSIS_YAW_MID_VALUE 3278//云台位于底盘中间时，yaw轴电机机械角度为4104	
	#define CHASSIS_PIT_MID_VALUE 4320//pit轴云台相对于底盘平行时的机械角度
	#define IS_PIT_NEGATION -1	//工程一pit角速度反馈需要取反
	#define PIT_MAX_ANGEL 213.0f
	#define PIT_MIN_ANGEL	166.0f
#endif

