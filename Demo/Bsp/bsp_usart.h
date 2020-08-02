
#ifndef __BSP_USART
#define __BSP_USART
	
#include "main.h"
#include "task_tatal.h"

typedef struct {
	int16_t ch1;	//each ch value from -364 -- +364
	int16_t ch2;
	int16_t ch3;
	int16_t ch4;
	
	uint8_t switch_left;	//3 value
	uint8_t switch_right;
	
	struct {
		int16_t x;
		int16_t y;
		int16_t z;
	
		uint8_t press_left;
		uint8_t press_right;
	}mouse;
	
	struct {
		uint16_t key_code;
/**********************************************************************************
   * ����ͨ��:15      14     13    12     11    10    9     8     7    6      5         4   3   2   1
   *          V       C      X	   Z      G     F     R     E     Q    CTRL   SHIFT     D   A   S   W   
		         16384  8192   4096   2048   1024   512   256   128   64   32     16        8   4   2   1       
************************************************************************************/

	}keyBoard;
	

}RC_Type;

extern uint8_t UART_Buffer[100];
extern RC_Type remote_control;

void Callback_RC_Handle(RC_Type* rc, uint8_t* buff);
HAL_StatusTypeDef UART_Receive_DMA_NoIT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Receive_IT_IDLE(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
void HAL_UART_IDLE_IRQHandler(UART_HandleTypeDef *huart);

#endif



