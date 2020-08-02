#include "timdelay.h"
#include "tim.h"

TIM_HandleTypeDef delay;

/********************************************************************************
* Routine: TIM7_Delay_Init
* Description: TIM7延时初始化，填充结构体
* Param: NULL
* Return: NULL
* Notes:
**********************************************************************************/
void TIM7_Delay_Init(void)
{
	delay.Instance = TIM7;
	delay.Init.Prescaler = 42-1;
	delay.Init.CounterMode = TIM_COUNTERMODE_UP;
	delay.Init.Period = 0;
}

/********************************************************************************
* Routine: TIM7_Delay_Us
* Description: TIM7微秒级延时，最大延时时长65535微秒
* Param: uint16_t us
* Return: void
* Notes:
**********************************************************************************/
void TIM7_Delay_Us(uint16_t us)
{
	delay.Init.Period = us;
	HAL_TIM_Base_Init(&delay);
	HAL_TIM_Base_Start(&delay);
	while(delay.Instance->CNT != us);
	HAL_TIM_Base_Stop(&delay);
}

//延时nms
//nms:要延时的ms数
void TIM_Delay_ms(uint16_t nms)
{
	uint32_t i;
	for(i=0;i<nms;i++) TIM7_Delay_Us(1000);
}
