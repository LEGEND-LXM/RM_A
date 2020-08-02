#include "led.h"

void greenled_ctrl_on(uint16_t GPIO_Pin)
{HAL_GPIO_WritePin(GPIOG, GPIO_Pin, GPIO_PIN_RESET);}

void greenled_ctrl_off(uint16_t GPIO_Pin)
{HAL_GPIO_WritePin(GPIOG, GPIO_Pin, GPIO_PIN_SET);}

void single_green_off(void)
{HAL_GPIO_WritePin(GPIOF, SINGLEGREEN_Pin, GPIO_PIN_SET);}

void single_green_on(void)
{HAL_GPIO_WritePin(GPIOF, SINGLEGREEN_Pin, GPIO_PIN_RESET);}

void single_red_off(void)
{HAL_GPIO_WritePin(GPIOE, SINGLE_RED_Pin, GPIO_PIN_SET);}

void single_red_on(void)
{HAL_GPIO_WritePin(GPIOE, SINGLE_RED_Pin, GPIO_PIN_RESET);}
