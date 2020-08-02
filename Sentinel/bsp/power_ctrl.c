#include "power_ctrl.h"

void power_ctrl_onall(void)
{
	//24v…œµÁ
  for (uint8_t i = POWER1_CTRL_SWITCH; i < POWER4_CTRL_SWITCH + 1; i++)
    {
        power_ctrl_on(i);
    }
}

void power_ctrl_offall(void)
{
	//24v∂œµÁ
  for (uint8_t i = POWER1_CTRL_SWITCH; i < POWER4_CTRL_SWITCH + 1; i++)
    {
        power_ctrl_off(i);
    }
}

void power_ctrl_on(uint8_t num)
{
    if (num > POWER4_CTRL_SWITCH)
    {
        return;
    }
    HAL_GPIO_WritePin(GPIOH,GPIO_PIN_2 << num,GPIO_PIN_SET);
}

void power_ctrl_off(uint8_t num)
{
    if (num > POWER4_CTRL_SWITCH)
    {
        return;
    }
    HAL_GPIO_WritePin(GPIOH,GPIO_PIN_2 << num,GPIO_PIN_RESET);
}

