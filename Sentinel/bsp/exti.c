#include "exti.h"
#include "timdelay.h"
//#include "mpu_dmp_useapi.h"
#include "gimbal_task.h"

//外部中断初始化
void EXTI_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;
    
    __HAL_RCC_GPIOC_CLK_ENABLE();               //开启GPIOA时钟

    
    GPIO_Initure.Pin=GPIO_PIN_0;                //PA0
    GPIO_Initure.Mode=GPIO_MODE_IT_RISING;      //上升沿触发
    GPIO_Initure.Pull=GPIO_PULLDOWN;
    HAL_GPIO_Init(GPIOC,&GPIO_Initure);
    

    //中断线0-PA0
    HAL_NVIC_SetPriority(EXTI0_IRQn,2,0);       //抢占优先级为2，子优先级为0
    HAL_NVIC_EnableIRQ(EXTI0_IRQn);             //使能中断线0
    
}


//中断服务函数
void EXTI0_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);//调用中断处理公用函数
}



//中断服务程序中需要做的事情
//在HAL库中所有的外部中断服务函数都会调用此函数
//GPIO_Pin:中断引脚号
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    switch(GPIO_Pin)
    {
        case GPIO_PIN_0:
            //gyro_data_ready_cb();
	          Get_Anglespeed();  //这里就是MPU6050的更新程序
					  //MPU6050_control();
            break;
        
    }
}
