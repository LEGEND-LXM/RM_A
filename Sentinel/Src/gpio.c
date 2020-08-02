/**
  ******************************************************************************
  * File Name          : gpio.c
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
#include "main.h"
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
	__HAL_RCC_GPIOI_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
		/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(IMU_TEMP_Port, IMU_TEMP_Pin, GPIO_PIN_RESET);//初始化imu电阻模块，设置输出为0
	
  HAL_GPIO_WritePin(GPIOG, GREENLED8_Pin|GREENLED7_Pin|GREENLED6_Pin 
                          |GREENLED5_Pin|GREENLED4_Pin|GREENLED3_Pin|GREENLED2_Pin 
                          |GREENLED1_Pin, GPIO_PIN_SET);
  
	HAL_GPIO_WritePin(GPIOG, LASER_Pin, GPIO_PIN_SET);
	
  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOH, POWER_CONTROL1_Pin|POWER_CONTROL2_Pin|POWER_COMTROL3_Pin|POWER_CONTROL4_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, IIC_SCL_Pin|IIC_SDA_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SINGLE_RED_GPIO_Port, SINGLE_RED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SINGLEGREEN_GPIO_Port, SINGLEGREEN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PGPin PGPin PGPin PGPin 
                           PGPin PGPin PGPin PGPin 
                           PGPin */
  GPIO_InitStruct.Pin = LASER_Pin|GREENLED8_Pin|GREENLED7_Pin|GREENLED6_Pin 
                          |GREENLED5_Pin|GREENLED4_Pin|GREENLED3_Pin|GREENLED2_Pin 
                          |GREENLED1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : PHPin PHPin PHPin PHPin */
  GPIO_InitStruct.Pin = POWER_CONTROL1_Pin|POWER_CONTROL2_Pin|POWER_COMTROL3_Pin|POWER_CONTROL4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);
	
/*Configure GPIO pin : PtPin */  //编号为S的灯
  GPIO_InitStruct.Pin =  GPIO_PIN_6; 
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
	
  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = MPU6050_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(MPU6050_INT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin */
  GPIO_InitStruct.Pin = IIC_SCL_Pin|IIC_SDA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = SINGLE_RED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(SINGLE_RED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = SINGLEGREEN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(SINGLEGREEN_GPIO_Port, &GPIO_InitStruct);
	
	GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

	/*Configure GPIO pin : PtPin */                 //初始化imu_电阻加热模块
	GPIO_InitStruct.Pin = IMU_TEMP_Pin|OLED_DC_Pin|OLED_RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(IMU_TEMP_Port, &GPIO_InitStruct);
}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
