#ifndef __dji_remote_H
#define __dji_remote_H
#ifdef __cplusplus
 extern "C" {
#endif
	 
#include "main.h" 
#include "usart.h"	 
#define int_abs(x) ((x) > 0 ? (x) : (-x))	 
/* ----------------------- RC Switch Definition----------------------------- */
#define RC_SW_UP ((uint16_t)1)
#define RC_SW_MID ((uint16_t)3)
#define RC_SW_DOWN ((uint16_t)2)
#define switch_is_down(s) (s == RC_SW_DOWN)
#define switch_is_mid(s) (s == RC_SW_MID)
#define switch_is_up(s) (s == RC_SW_UP)
	 
/* ----------------------- PC Key Definition-------------------------------- */
#define KEY_PRESSED_OFFSET_W ((uint16_t)1 << 0)
#define KEY_PRESSED_OFFSET_S ((uint16_t)1 << 1)
#define KEY_PRESSED_OFFSET_A ((uint16_t)1 << 2)
#define KEY_PRESSED_OFFSET_D ((uint16_t)1 << 3)
#define KEY_PRESSED_OFFSET_SHIFT ((uint16_t)1 << 4)
#define KEY_PRESSED_OFFSET_CTRL ((uint16_t)1 << 5)
#define KEY_PRESSED_OFFSET_Q ((uint16_t)1 << 6)
#define KEY_PRESSED_OFFSET_E ((uint16_t)1 << 7)
#define KEY_PRESSED_OFFSET_R ((uint16_t)1 << 8)
#define KEY_PRESSED_OFFSET_F ((uint16_t)1 << 9)
#define KEY_PRESSED_OFFSET_G ((uint16_t)1 << 10)
#define KEY_PRESSED_OFFSET_Z ((uint16_t)1 << 11)
#define KEY_PRESSED_OFFSET_X ((uint16_t)1 << 12)
#define KEY_PRESSED_OFFSET_C ((uint16_t)1 << 13)
#define KEY_PRESSED_OFFSET_V ((uint16_t)1 << 14)
#define KEY_PRESSED_OFFSET_B ((uint16_t)1 << 15)
	 

/***********************************************START***********************************************/
/*功能代码名称：遥控器死区限制，底盘云台都要用到*/
		
#define rc_deadline_limit(input, output, dealine)        \
    {                                                    \
        if ((input) > (dealine) || (input) < -(dealine)) \
        {                                                \
            (output) = (input);                          \
        }                                                \
        else                                             \
        {                                                \
            (output) = 0;                                \
        }                                                \
    }
/***********************************************END***************************************************/		
/**********************接收机需要的结构体***********************/
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
   * 键盘通道:15      14     13    12     11    10    9     8     7    6      5         4   3   2   1
   *          V       C      X	   Z      G     F     R     E     Q    CTRL   SHIFT     D   A   S   W   
		         16384  8192   4096   2048   1024   512   256   128   64   32     16        8   4   2   1       
************************************************************************************/
	}keyBoard;
}RC_Type;

extern uint8_t UART_Buffer[100];
extern RC_Type remote_control;
extern uint32_t Latest_Remote_Control_Pack_Time;//用于检测遥控器是否离线
/***********************END****************************/

/**********************接收机需要的回调函数***********************/
void Callback_RC_Handle(RC_Type* rc, uint8_t* buff);
HAL_StatusTypeDef UART_Receive_DMA_NoIT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Receive_IT_IDLE(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
void HAL_UART_IDLE_IRQHandler(UART_HandleTypeDef *huart);
extern const RC_Type *get_remote_control_point(void);
#ifdef __cplusplus
}
#endif
#endif /*__ usart_H */

