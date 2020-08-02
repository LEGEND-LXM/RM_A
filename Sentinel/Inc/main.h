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

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
typedef float fp32;
typedef double fp64;
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LASER_Pin GPIO_PIN_13
#define LASER_GPIO_Port GPIOG
#define POWER_CONTROL1_Pin GPIO_PIN_2
#define POWER_CONTROL1_GPIO_Port GPIOH
#define POWER_CONTROL2_Pin GPIO_PIN_3
#define POWER_CONTROL2_GPIO_Port GPIOH
#define POWER_COMTROL3_Pin GPIO_PIN_4
#define POWER_COMTROL3_GPIO_Port GPIOH
#define GREENLED8_Pin GPIO_PIN_8
#define GREENLED8_GPIO_Port GPIOG
#define POWER_CONTROL4_Pin GPIO_PIN_5
#define POWER_CONTROL4_GPIO_Port GPIOH
#define GREENLED7_Pin GPIO_PIN_7
#define GREENLED7_GPIO_Port GPIOG
#define GREENLED6_Pin GPIO_PIN_6
#define GREENLED6_GPIO_Port GPIOG
#define GREENLED5_Pin GPIO_PIN_5
#define GREENLED5_GPIO_Port GPIOG
#define GREENLED4_Pin GPIO_PIN_4
#define GREENLED4_GPIO_Port GPIOG
#define GREENLED3_Pin GPIO_PIN_3
#define GREENLED3_GPIO_Port GPIOG
#define GREENLED2_Pin GPIO_PIN_2
#define GREENLED2_GPIO_Port GPIOG
#define MPU6050_INT_Pin GPIO_PIN_1
#define MPU6050_INT_GPIO_Port GPIOC
#define GREENLED1_Pin GPIO_PIN_1
#define GREENLED1_GPIO_Port GPIOG
#define IIC_SCL_Pin GPIO_PIN_4
#define IIC_SCL_GPIO_Port GPIOA
#define IIC_SDA_Pin GPIO_PIN_5
#define IIC_SDA_GPIO_Port GPIOA
#define SINGLE_RED_Pin GPIO_PIN_11
#define SINGLE_RED_GPIO_Port GPIOE
#define SINGLEGREEN_Pin GPIO_PIN_14
#define SINGLEGREEN_GPIO_Port GPIOF
/* USER CODE BEGIN Private defines */
#define ONLINE 1
#define LOSSLINE 2
#define SAFTY_CONTROL 3
#define MANUAL_CONTROL 4
#define MPU_CONTROL 5
#define MOTO_CONTROL 6
#define MOCALUN_CONTROL 7



//#define LASER_Pin 							GPIO_PIN_13
//#define LASER_GPIO_Port 				GPIOG
//#define KEY_Pin 								GPIO_PIN_10
//#define KEY_GPIO_Port 					GPIOD
//#define LED_S_Pin 								GPIO_PIN_14	
//#define LED_S_GPIO_Port 					GPIOF//绿灯 编号为S
//#define LED_T_Pin 								GPIO_PIN_11  
//#define LED_T_GPIO_Port 					GPIOE//红灯 编号为T
//#define LED_H_Pin									GPIO_PIN_1
//#define LED_G_Pin									GPIO_PIN_2
//#define LED_F_Pin									GPIO_PIN_3
//#define LED_E_Pin									GPIO_PIN_4
//#define LED_D_Pin									GPIO_PIN_5
//#define LED_C_Pin									GPIO_PIN_6
//#define LED_B_Pin									GPIO_PIN_7
//#define LED_A_Pin									GPIO_PIN_8
//#define LED_USER_GPIO_PORT				GPIOG        //用户灯
#define OLED_DC_Pin GPIO_PIN_9//OLED引脚定义
#define OLED_DC_GPIO_Port GPIOB
#define OLED_RST_Pin GPIO_PIN_10
#define OLED_RST_GPIO_Port GPIOB

#define IMU_TEMP_Pin       			GPIO_PIN_5 //imu电阻加热为PB5
#define IMU_TEMP_Port						GPIOB



void SystemClock_Config(void);
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
