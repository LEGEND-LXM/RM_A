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
extern u8  USART_RX_BUF[USART_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 USART_RX_STA;         		//����״̬���	

extern u8 TIM3_CAPTURE_STA;
extern u32 TIM3_CAPTURE_VAL;
extern u8 TIM3_CAPTURE_TERM;
extern u8 footstep_target_flag;//̧���߶�
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
	//���������º������غ��½��� �����жϣ�����˺���
  HAL_TIM_IRQHandler(&htim3);
}
/**
* @brief This function handles TIM3 Update interrupt.
*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance==TIM3){
		
	if(TIM3_CAPTURE_STA!=CAP_CMPL)//��δ�ɹ�����
	{
			if(TIM3_CAPTURE_STA==CAP_UP)//�Ѿ����񵽸ߵ�ƽ��
			{
				if(TIM3_CAPTURE_TERM>2)//�ߵ�ƽ̫����
				{
					TIM3_CAPTURE_STA=CAP_CMPL;		//��ǳɹ�������һ��
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
		if(TIM3_CAPTURE_STA!=CAP_CMPL)//��δ�ɹ�����
	{
		if(TIM3_CAPTURE_STA==CAP_UP)		//����һ���½��� 		
			{	  			
				TIM3_CAPTURE_STA=CAP_CMPL;		//��ǳɹ�����һ�θߵ�ƽ����
                TIM3_CAPTURE_VAL=HAL_TIM_ReadCapturedValue(htim,TIM_CHANNEL_3);//��ȡ��ǰ�Ĳ���ֵ.
                TIM_RESET_CAPTUREPOLARITY(htim,TIM_CHANNEL_3);   //һ��Ҫ�����ԭ�������ã���
                TIM_SET_CAPTUREPOLARITY(htim,TIM_CHANNEL_3,TIM_ICPOLARITY_RISING);//���������ز���
			}else  								//��δ��ʼ,��һ�β���������
			{
				TIM3_CAPTURE_STA=CAP_NO;			//���
				TIM3_CAPTURE_VAL=RESET;
				TIM3_CAPTURE_TERM=RESET;
				TIM3_CAPTURE_STA=CAP_UP;		//��ǲ�����������
				__HAL_TIM_DISABLE(htim);        //�ر�
				__HAL_TIM_SET_COUNTER(htim,0);
				TIM_RESET_CAPTUREPOLARITY(htim,TIM_CHANNEL_3);   //һ��Ҫ�����ԭ�������ã���
				TIM_SET_CAPTUREPOLARITY(htim,TIM_CHANNEL_3,TIM_ICPOLARITY_FALLING);//ͨ��1����Ϊ�½��ز���
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
  
  /*< ע�⣡ ����ʹ���˴��ڿ����жϣ�HAL����Ĭ�ϵĻص������޷�����������Ҫ���������Զ���ص�������������Ҫ��Ĭ�ϻص����� >*/
  
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
//��λ�����ⲿ�ж�
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
//��翪��
void EXTI2_IRQHandler(void){
	footstep_target_flag=SET;
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
}
/**
* @brief This function handles USART3 global interrupt.
*/
#if EN_USART2_RX   //���ʹ���˽���
void USART2_IRQHandler(void)                	
{ 
	u8 Res;

	if((__HAL_UART_GET_FLAG(&huart2,UART_FLAG_RXNE)!=RESET))  //�����ж�(���յ������ݱ�����0x0d 0x0a��β)
	{
        HAL_UART_Receive(&huart2,&Res,1,1000); 
		if((USART_RX_STA&0x8000)==0)//����δ���
		{
			if(USART_RX_STA&0x4000)//���յ���0x0d
			{
				if(Res!=0x0a)USART_RX_STA=0;//���մ���,���¿�ʼ
				else USART_RX_STA|=0x8000;	//��������� 
			}
			else //��û�յ�0X0D
			{	
				if(Res==0x0d)USART_RX_STA|=0x4000;
				else
				{
					USART_RX_BUF[USART_RX_STA&0X3FFF]=Res ;
					USART_RX_STA++;
					if(USART_RX_STA>(USART_REC_LEN-1))USART_RX_STA=0;//�������ݴ���,���¿�ʼ����	  
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
