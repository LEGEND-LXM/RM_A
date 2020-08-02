#include "hcsr04.h"

double distance; 
u32 TIM3_CAPTURE_VAL=RESET;
u8 TIM3_CAPTURE_STA=RESET;
u8 TIM3_CAPTURE_TERM=RESET;
GPIO_InitTypeDef gpio_c_init;
void GetDistance(void){
if(TIM3_CAPTURE_STA==CAP_CMPL){
		distance=(double)TIM3_CAPTURE_VAL*0.17;
		//printf("%lf \r\n",distance);
		TIM3_CAPTURE_STA=CAP_NO;
	}
}





