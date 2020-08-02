/**
  ******************************************************************************
  * @file    Remote_Control.h
  * @author  Ginger
  * @version V1.0.0
  * @date    2015/11/14
  * @brief   
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */
	
#ifndef __RC__
#define __RC__
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

#define RC_Frame_Lentgh		18
#define angle_to_radian  (PI/180)  //角度转弧度
#define radian_to_angle  (180/PI)  //弧度转角度
#define CHASSIS_RC_DEADLINE 10 //遥控器死区
#define int_abs(x) ((x) > 0 ? (x) : (-x))
/* ----------------------- RC Switch Definition----------------------------- */
#define RC_SW_UP ((uint16_t)1)
#define RC_SW_MID ((uint16_t)3)
#define RC_SW_DOWN ((uint16_t)2)
#define switch_is_down(s) (s == RC_SW_DOWN)
#define switch_is_mid(s) (s == RC_SW_MID)
#define switch_is_up(s) (s == RC_SW_UP)
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



enum{
	Switch_Up = 1,
	Switch_Middle = 3,
	Switch_Down = 2,
};

enum{
	Key_W,
	Key_S,
	//...
};

extern uint32_t dbus_time;
extern int yaw_control;
extern RC_Type remote_control;
extern uint32_t  Latest_Remote_Control_Pack_Time ;
void Callback_RC_Handle(RC_Type* rc, uint8_t* buff);
void DBUS_Deal(void);

#endif


