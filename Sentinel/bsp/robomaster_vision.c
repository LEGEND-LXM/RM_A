/**
  ******************************************************************************
  * File Name          : robomaster_vision.c
	* author						 : 周恒
	* Date							 :2019.1.23
  * Description        :视觉处理文件
	
  ******************************************************************************
  ******************************************************************************
  */
#include "gimbal_task.h"
#include "robomaster_vision.h"
#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "usart.h"

uint8_t UART6_Date[12]={0};//串口6接收视觉数据

Vision_Attack Armour_attack;

/**
  * @brief  视觉初始化
  * @param  void
  * @retval void
  */

/**********************************************************************************************************
*函 数 名: get_armour_err
*功能说明: 获取装甲板相对于云台的误差
*形    参:需要视觉提供云台相对于装甲板的yaw和pitch的err
*返 回 值: 
**********************************************************************************************************/
void get_armour_err()
{
	
		if(UART6_Date[0]==0x5a&&UART6_Date[1]==0xa5)
		{
			Armour_attack.current_time=HAL_GetTick();
			Armour_attack.delta_time=Armour_attack.current_time-Armour_attack.last_time;
			Armour_attack.vision_frame=1000/Armour_attack.delta_time;
			
			Armour_attack.pan_tilt_angel_err.Yaw_Err=(UART6_Date[2] | UART6_Date[3]<<8);//Armour_attack.pan_tilt_angel_err.origin_yaw;
			Armour_attack.pan_tilt_angel_err.Pitch_Err=(UART6_Date[4] | UART6_Date[5]<<8);//Armour_attack.pan_tilt_angel_err.origin_pitch;
			Armour_attack.pan_tilt_angel_err.VX=((UART6_Date[6] | UART6_Date[7]<<8))-3000;
			Armour_attack.pan_tilt_angel_err.VY=((UART6_Date[8] | UART6_Date[9]<<8))-3000;
			Armour_attack.pan_tilt_angel_err.HEIGHT=(UART6_Date[10] | UART6_Date[11]<<8);

			Armour_attack.last_time=HAL_GetTick();
			robot_status.vision_status=VISION_SUCCESS;//有视觉信息，正常
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);//测试
		}
	}


//串口6接收中断服务程序

//void USART6_IRQHandler(void)                	
//{
//	//HAL_UART_IDLE_IRQHandler(&huart6);	
//}    
	/**********************************************************************************************************
*函 数 名: armour_attack
*功能说明: 视觉识别装甲板并攻击，   控制思路，只有当鼠标偏移量或遥控器的偏移量小于一定值的时候(即中位死区)，才能激活视觉识别
*形    参: 需要视觉提供云台相对于装甲板的yaw和pitch的err
*返 回 值: 电流输出
**********************************************************************************************************/
void armour_attack()
{
	/***********YAW轴偏差矫正***************/
	pid_calc(&pid_vision_yaw,Armour_attack.pan_tilt_angel_err.Yaw_Err,VISION_YAW_TARGET);
	speed_YAW=pid_vision_yaw.pos_out;
	pid_calc(&pid_yuntai_yaw_speed,imu.gz,speed_YAW);
	/***********PITCH轴偏差矫正***************/
	pid_calc(&pid_vision_pitch,Armour_attack.pan_tilt_angel_err.Pitch_Err,VISION_PIT_TARGET);
	speed_PIT=pid_vision_pitch.pos_out;
	pid_calc(&pid_yuntai_pitch_speed,imu.gx,speed_PIT);
//	
	
}