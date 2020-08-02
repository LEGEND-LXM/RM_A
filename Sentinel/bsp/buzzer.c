#include "buzzer.h"
#include "tim.h"


void buzzer_on(uint16_t psc, uint16_t pwm) // buzzer_on(0, 20000)Éùµ÷×î¸ß
{
	 TIM12->PSC = psc;
   __HAL_TIM_SetCompare(&htim12, TIM_CHANNEL_1, pwm);
}

void buzzer_off(void)
{
     __HAL_TIM_SetCompare(&htim12, TIM_CHANNEL_1, 0);
}
