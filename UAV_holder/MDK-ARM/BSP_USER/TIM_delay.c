#include "TIM_delay.h"

void delayXus(uint32_t us)
{
	uint16_t differ=0xffff-us-5;					//设定定时器计数器起始值，0xFFFF == 65535
	__HAL_TIM_SET_COUNTER(&htim6,differ);
	HAL_TIM_Base_Start(&htim6);					//启动定时器
  while(differ<0xffff-6)							//补偿，判断
  {
    differ=__HAL_TIM_GET_COUNTER(&htim6);			//查询计数器的计数值
  }
  HAL_TIM_Base_Stop(&htim6);
}
void delayXms(uint32_t ms)
{
	uint32_t i;
	for(i=0;i<ms;i++)
	delayXus(1000);
}
