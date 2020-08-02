/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"

/* USER CODE BEGIN 0 */
#include "hcsr04.h"
#include "usart.h"
#include "robomaster_common.h"
/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern CAN_HandleTypeDef hcan1;
extern DMA_HandleTypeDef hdma_tim1_ch1_ch2_ch3;
extern TIM_HandleTypeDef htim2;
extern DMA_HandleTypeDef hdma_usart1_rx;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart6;
extern u8  USART_RX_BUF[USART_REC_LEN]; //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符 
extern u16 USART_RX_STA;         		//接收状态标记	

extern u8 TIM3_CAPTURE_STA;
extern u32 TIM3_CAPTURE_VAL;
extern u8 TIM3_CAPTURE_TERM;
extern u8 footstep_target_flag;//抬升高度
extern TIM_HandleTypeDef htim6;

/******************************************************************************/
/*            Cortex-M4 Processor Interruption and Exception Handlers         */ 
/******************************************************************************/

/**
* @brief This function handles Non maskable interrupt.
*/
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
* @brief This function handles Hard fault interrupt.
*/
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
  /* USER CODE BEGIN HardFault_IRQn 1 */

  /* USER CODE END HardFault_IRQn 1 */
}

/**
* @brief This function handles Memory management fault.
*/
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
  /* USER CODE BEGIN MemoryManagement_IRQn 1 */

  /* USER CODE END MemoryManagement_IRQn 1 */
}

/**
* @brief This function handles Pre-fetch fault, memory access fault.
*/
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
  /* USER CODE BEGIN BusFault_IRQn 1 */

  /* USER CODE END BusFault_IRQn 1 */
}

/**
* @brief This function handles Undefined instruction or illegal state.
*/
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
  /* USER CODE BEGIN UsageFault_IRQn 1 */

  /* USER CODE END UsageFault_IRQn 1 */
}

/**
* @brief This function handles System service call via SWI instruction.
*/
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
* @brief This function handles Debug monitor.
*/
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
* @brief This function handles Pendable request for system service.
*/
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
* @brief This function handles System tick timer.
*/
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_SYSTICK_IRQHandler();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
* @brief This function handles CAN1 TX interrupts.
*/
void CAN1_TX_IRQHandler(void)
{
  /* USER CODE BEGIN CAN1_TX_IRQn 0 */

  /* USER CODE END CAN1_TX_IRQn 0 */
  HAL_CAN_IRQHandler(&hcan1);
  /* USER CODE BEGIN CAN1_TX_IRQn 1 */

  /* USER CODE END CAN1_TX_IRQn 1 */
}

/**
* @brief This function handles CAN1 RX0 interrupts.
*/
void CAN1_RX0_IRQHandler(void)
{
  /* USER CODE BEGIN CAN1_RX0_IRQn 0 */

  /* USER CODE END CAN1_RX0_IRQn 0 */
  HAL_CAN_IRQHandler(&hcan1);
  /* USER CODE BEGIN CAN1_RX0_IRQn 1 */

	/*#### add enable can it again to solve can receive only one ID problem!!!####**/
  /* USER CODE END CAN1_RX0_IRQn 1 */
}

/**
* @brief This function handles TIM2 global interrupt.
*/
void TIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM2_IRQn 0 */
	task();
  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim2);
  /* USER CODE BEGIN TIM2_IRQn 1 */

  /* USER CODE END TIM2_IRQn 1 */
}

/**
* @brief This function handles USART1 global interrupt.
*/
void TIM3_IRQHandler(void)
{
	//计数器更新和上升沿和下降沿 触发中断，进入此函数
  HAL_TIM_IRQHandler(&htim3);
}
/**
* @brief This function handles TIM3 Update interrupt.
*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance==TIM3){
		
	if(TIM3_CAPTURE_STA!=CAP_CMPL)//还未成功捕获
	{
			if(TIM3_CAPTURE_STA==CAP_UP)//已经捕获到高电平了
			{
				if(TIM3_CAPTURE_TERM>2)//高电平太长了
				{
					TIM3_CAPTURE_STA=CAP_CMPL;		//标记成功捕获了一次
					TIM3_CAPTURE_VAL=65535;
				}else TIM3_CAPTURE_TERM++;
			}	 
	}
}	
	if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
}
/**
* @brief This function handles TIM3 Input capture interrupt.
*/
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance==TIM3){
//		tim3flag=11;
		if(TIM3_CAPTURE_STA!=CAP_CMPL)//还未成功捕获
	{
		if(TIM3_CAPTURE_STA==CAP_UP)		//捕获到一个下降沿 		
			{	  			
				TIM3_CAPTURE_STA=CAP_CMPL;		//标记成功捕获到一次高电平脉宽
                TIM3_CAPTURE_VAL=HAL_TIM_ReadCapturedValue(htim,TIM_CHANNEL_3);//获取当前的捕获值.
                TIM_RESET_CAPTUREPOLARITY(htim,TIM_CHANNEL_3);   //一定要先清除原来的设置！！
                TIM_SET_CAPTUREPOLARITY(htim,TIM_CHANNEL_3,TIM_ICPOLARITY_RISING);//配置上升沿捕获
			}else  								//还未开始,第一次捕获上升沿
			{
				TIM3_CAPTURE_STA=CAP_NO;			//清空
				TIM3_CAPTURE_VAL=RESET;
				TIM3_CAPTURE_TERM=RESET;
				TIM3_CAPTURE_STA=CAP_UP;		//标记捕获到了上升沿
				__HAL_TIM_DISABLE(htim);        //关闭
				__HAL_TIM_SET_COUNTER(htim,0);
				TIM_RESET_CAPTUREPOLARITY(htim,TIM_CHANNEL_3);   //一定要先清除原来的设置！！
				TIM_SET_CAPTUREPOLARITY(htim,TIM_CHANNEL_3,TIM_ICPOLARITY_FALLING);//通道1设置为下降沿捕获
				__HAL_TIM_ENABLE(htim);
			}		    
		}
}
}
/**
* @brief This function handles TIM3 Input capture interrupt.
*/
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */
  
  /*< 注意！ 由于使用了串口空闲中断，HAL库中默认的回调函数无法处理，所以需要加入下面自定义回调处理函数并且需要将默认回调屏蔽 >*/
  
	HAL_UART_IDLE_IRQHandler(&huart1);
    
  /* USER CODE END USART1_IRQn 0 */
  //HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */
	
  /* USER CODE END USART1_IRQn 1 */
}

/**
* @brief This function handles TIM6 global interrupt, DAC1 and DAC2 underrun error interrupts.
*/


void TIM6_DAC_IRQHandler(void)
{
  /* USER CODE BEGIN TIM6_DAC_IRQn 0 */

  /* USER CODE END TIM6_DAC_IRQn 0 */
  HAL_TIM_IRQHandler(&htim6);
  /* USER CODE BEGIN TIM6_DAC_IRQn 1 */

  /* USER CODE END TIM6_DAC_IRQn 1 */
}

/**
* @brief This function handles DMA2 stream2 global interrupt.
*/
void DMA2_Stream2_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Stream2_IRQn 0 */

  /* USER CODE END DMA2_Stream2_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart1_rx);
  /* USER CODE BEGIN DMA2_Stream2_IRQn 1 */

  /* USER CODE END DMA2_Stream2_IRQn 1 */
}

/**
* @brief This function handles DMA2 stream6 global interrupt.
*/
void DMA2_Stream6_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Stream6_IRQn 0 */

  /* USER CODE END DMA2_Stream6_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_tim1_ch1_ch2_ch3);
  /* USER CODE BEGIN DMA2_Stream6_IRQn 1 */

  /* USER CODE END DMA2_Stream6_IRQn 1 */
}

/**
* @brief This function handles USART6 global interrupt.
*/
void USART6_IRQHandler(void)
{
  /* USER CODE BEGIN USART6_IRQn 0 */

  /* USER CODE END USART6_IRQn 0 */
  HAL_UART_IRQHandler(&huart6);
  /* USER CODE BEGIN USART6_IRQn 1 */

  /* USER CODE END USART6_IRQn 1 */
}
//限位开关外部中断
//void EXTI4_IRQHandler(void){
//	delay_ms(100);
//	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
//}
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
//	if(GPIO_Pin==GPIO_PIN_4){
//		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,0);
//		footstep_flag=SET;}
//	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
//}
//光电开关
void EXTI2_IRQHandler(void){
	footstep_target_flag=SET;
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
}
/**
* @brief This function handles USART3 global interrupt.
*/
#if EN_USART2_RX   //如果使能了接收
void USART2_IRQHandler(void)                	
{ 
	u8 Res;

	if((__HAL_UART_GET_FLAG(&huart2,UART_FLAG_RXNE)!=RESET))  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
	{
        HAL_UART_Receive(&huart2,&Res,1,1000); 
		if((USART_RX_STA&0x8000)==0)//接收未完成
		{
			if(USART_RX_STA&0x4000)//接收到了0x0d
			{
				if(Res!=0x0a)USART_RX_STA=0;//接收错误,重新开始
				else USART_RX_STA|=0x8000;	//接收完成了 
			}
			else //还没收到0X0D
			{	
				if(Res==0x0d)USART_RX_STA|=0x4000;
				else
				{
					USART_RX_BUF[USART_RX_STA&0X3FFF]=Res ;
					USART_RX_STA++;
					if(USART_RX_STA>(USART_REC_LEN-1))USART_RX_STA=0;//接收数据错误,重新开始接收	  
				}		 
			}
		}   		 
	}
	HAL_UART_IRQHandler(&huart2);	
} 
#endif	
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
