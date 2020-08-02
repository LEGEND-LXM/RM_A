/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/********外设驱动库文件********/
#include "dji_remote.h"
#include "robomaster_vcan.h"
/********任务调用库文件********/
//#include "Initial_Task.h"
//#include "User_task.h"
/********系统需要调用的库文件********/
#include "bsp_can.h"
#include "stdio.h"
#include "tim.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

//软件取反系数转换
#define NEGATION_COEFFICIENT -1

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
typedef unsigned char bool_t;
typedef float fp32;
typedef double fp64;
/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define OLED_SCLK_Pin GPIO_PIN_3
#define OLED_SCLK_GPIO_Port GPIOB
#define OLED_DC_Pin GPIO_PIN_9
#define OLED_DC_GPIO_Port GPIOB
#define POWER1_CTRL_Pin GPIO_PIN_2
#define POWER1_CTRL_GPIO_Port GPIOH
#define LED8_Pin GPIO_PIN_8
#define LED8_GPIO_Port GPIOG
#define LED7_Pin GPIO_PIN_7
#define LED7_GPIO_Port GPIOG
#define LED6_Pin GPIO_PIN_6
#define LED6_GPIO_Port GPIOG
#define LED5_Pin GPIO_PIN_5
#define LED5_GPIO_Port GPIOG
#define LED4_Pin GPIO_PIN_4
#define LED4_GPIO_Port GPIOG
#define LED3_Pin GPIO_PIN_3
#define LED3_GPIO_Port GPIOG
#define LIMIT_SWITCH_Pin GPIO_PIN_15
#define LIMIT_SWITCH_GPIO_Port GPIOD
#define LED2_Pin GPIO_PIN_2
#define LED2_GPIO_Port GPIOG
#define LED1_Pin GPIO_PIN_1
#define LED1_GPIO_Port GPIOG
#define LIMIT_UP_Pin GPIO_PIN_14
#define LIMIT_UP_GPIO_Port GPIOD
#define LIMIT_DOWN_Pin GPIO_PIN_13
#define LIMIT_DOWN_GPIO_Port GPIOD
#define LASER_LIGHT_Pin GPIO_PIN_12
#define LASER_LIGHT_GPIO_Port GPIOD
#define LED_RED_Pin GPIO_PIN_11
#define LED_RED_GPIO_Port GPIOE
#define OLED_MOSI_Pin GPIO_PIN_7
#define OLED_MOSI_GPIO_Port GPIOA
#define LED_GREEN_Pin GPIO_PIN_14
#define LED_GREEN_GPIO_Port GPIOF
#define OLED_RST_Pin GPIO_PIN_10
#define OLED_RST_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
#define LIMIT_MIN_MAX(x,min,max) (x) = (((x)<=(min))?(min):(((x)>=(max))?(max):(x))) //pid中需要的求最大值的宏定义

/*
LED1	初始化任务指示
LED2	底盘任务指示
LED3	云台任务指示
LED4	拨盘任务指示
LED5	10ms任务指示
LED6 	失控任务指示
LED7  视觉解码信息指示
LED8  陀螺仪温度控制指示
LIMIT_SWITCH	限位开关
LASER_LIGHT 控制激光的通断
POWER1_CTRL 控制拨叉电源通断
*/

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
