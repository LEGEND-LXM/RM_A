/**
  ******************************************************************************
  * File Name          : robomaster_vision.c
	* author						 : �ܺ�
	* Date							 :2019.1.23
  * Description        :�Ӿ������ļ�
	
  ******************************************************************************
  ******************************************************************************
  */
#include "gimbal_task.h"
#include "robomaster_vision.h"
#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "usart.h"

uint8_t UART6_Date[12]={0};//����6�����Ӿ�����

Vision_Attack Armour_attack;

/**
  * @brief  �Ӿ���ʼ��
  * @param  void
  * @retval void
  */

/**********************************************************************************************************
*�� �� ��: get_armour_err
*����˵��: ��ȡװ�װ��������̨�����
*��    ��:��Ҫ�Ӿ��ṩ��̨�����װ�װ��yaw��pitch��err
*�� �� ֵ: 
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
			robot_status.vision_status=VISION_SUCCESS;//���Ӿ���Ϣ������
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);//����
		}
	}


//����6�����жϷ������

//void USART6_IRQHandler(void)                	
//{
//	//HAL_UART_IDLE_IRQHandler(&huart6);	
//}    
	/**********************************************************************************************************
*�� �� ��: armour_attack
*����˵��: �Ӿ�ʶ��װ�װ岢������   ����˼·��ֻ�е����ƫ������ң������ƫ����С��һ��ֵ��ʱ��(����λ����)�����ܼ����Ӿ�ʶ��
*��    ��: ��Ҫ�Ӿ��ṩ��̨�����װ�װ��yaw��pitch��err
*�� �� ֵ: �������
**********************************************************************************************************/
void armour_attack()
{
	/***********YAW��ƫ�����***************/
	pid_calc(&pid_vision_yaw,Armour_attack.pan_tilt_angel_err.Yaw_Err,VISION_YAW_TARGET);
	speed_YAW=pid_vision_yaw.pos_out;
	pid_calc(&pid_yuntai_yaw_speed,imu.gz,speed_YAW);
	/***********PITCH��ƫ�����***************/
	pid_calc(&pid_vision_pitch,Armour_attack.pan_tilt_angel_err.Pitch_Err,VISION_PIT_TARGET);
	speed_PIT=pid_vision_pitch.pos_out;
	pid_calc(&pid_yuntai_pitch_speed,imu.gx,speed_PIT);
//	
	
}