/****************************************************************************
 *  Copyright (C) 2018 RoboMaster.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of 
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/
 
#include "bsp_can.h"
#include "bsp_led.h"

moto_info_t motor_info[MOTOR_MAX_NUM]={4096};
moto_info_t motor_info_2[MOTOR_MAX_NUM]={4096};
uint16_t can_cnt_1;
uint16_t can_cnt_2;

/**
  * @brief  init can filter, start can, enable can rx interrupt
  * @param  hcan pointer to a CAN_HandleTypeDef structure that contains
  *         the configuration information for the specified CAN.
  * @retval None
  */
void can_user_init(CAN_HandleTypeDef* hcan )
{
  CAN_FilterTypeDef  can_filter;

	if(hcan->Instance == CAN1)
		can_filter.FilterBank = 0;                       // filter 0
	if(hcan->Instance == CAN2)
		can_filter.FilterBank = 14;  
	
  can_filter.FilterMode =  CAN_FILTERMODE_IDMASK;  // mask mode
  can_filter.FilterScale = CAN_FILTERSCALE_32BIT;
  can_filter.FilterIdHigh = 0;
  can_filter.FilterIdLow  = 0;
  can_filter.FilterMaskIdHigh = 0;
  can_filter.FilterMaskIdLow  = 0;                // set mask 0 to receive all can id
  can_filter.FilterFIFOAssignment = CAN_RX_FIFO0; // assign to fifo0
  can_filter.FilterActivation = ENABLE;           // enable can filter
  can_filter.SlaveStartFilterBank  = 14;          // only meaningful in dual can mode
   
  HAL_CAN_ConfigFilter(hcan, &can_filter);        // init can filter
  HAL_CAN_Start(hcan);                          // start can1
  HAL_CAN_ActivateNotification(hcan, CAN_IT_RX_FIFO0_MSG_PENDING); // enable can1 rx interrupt
}

/**
  * @brief  can rx callback, get motor feedback info
  * @param  hcan pointer to a CAN_HandleTypeDef structure that contains
  *         the configuration information for the specified CAN.
  * @retval None
  */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
  CAN_RxHeaderTypeDef rx_header_1;
  uint8_t             rx_data_1[8];
	
	CAN_RxHeaderTypeDef rx_header_2;
  uint8_t             rx_data_2[8];
  
	if(hcan->Instance == CAN1)
  {
    HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &rx_header_1, rx_data_1); //receive can data
  }
	  if(hcan->Instance == CAN2)
  {
    HAL_CAN_GetRxMessage(&hcan2, CAN_RX_FIFO0, &rx_header_2, rx_data_2); //receive can data
  }
	
	//CAN1
  if ((rx_header_1.StdId >= FEEDBACK_ID_BASE)
   && (rx_header_1.StdId <  FEEDBACK_ID_BASE + MOTOR_MAX_NUM))                  // judge the can id
  {
    can_cnt_1 ++;
    uint8_t index = rx_header_1.StdId - FEEDBACK_ID_BASE;		// get motor index by can_id
    motor_info[index].last_rotor_angle    =  motor_info[index].rotor_angle;
		motor_info[index].rotor_angle    = ((rx_data_1[0] << 8) | rx_data_1[1]);//机械角度
    motor_info[index].rotor_speed    = ((rx_data_1[2] << 8) | rx_data_1[3]);//转速
    motor_info[index].torque_current = ((rx_data_1[4] << 8) | rx_data_1[5]);//转矩
    motor_info[index].temp           =   rx_data_1[6];
  }
  if (can_cnt_1 == 500)
  {
    can_cnt_1 = 0;
    //LED_GREEN_TOGGLE(); // green led blink indicate can comunication successful 
  }
	//CAN2
	if ((rx_header_2.StdId >= FEEDBACK_ID_BASE)
   && (rx_header_2.StdId <  FEEDBACK_ID_BASE + MOTOR_MAX_NUM))                  // judge the can id
  {
    can_cnt_2 ++;
    uint8_t index = rx_header_2.StdId - FEEDBACK_ID_BASE;		// get motor index by can_id
    motor_info_2[index].last_rotor_angle    =  motor_info_2[index].rotor_angle;
		motor_info_2[index].rotor_angle    = ((rx_data_2[0] << 8) | rx_data_2[1]);//机械角度
    motor_info_2[index].rotor_speed    = ((rx_data_2[2] << 8) | rx_data_2[3]);//转速
    motor_info_2[index].torque_current = ((rx_data_2[4] << 8) | rx_data_2[5]);//转矩
    motor_info_2[index].temp           =   rx_data_2[6];
  }
  if (can_cnt_2 == 500)
  {
    can_cnt_2 = 0;
    //LED_GREEN_TOGGLE(); // green led blink indicate can comunication successful 
  }
}

/**
  * @brief  send motor control message through can bus
  * @param  id_range to select can control id 0x1ff or 0x2ff
  * @param  motor voltage 1,2,3,4 or 5,6,7
  * @retval None
  */
void set_motor_voltage_CAN1(uint8_t id_range, int16_t v1, int16_t v2, int16_t v3, int16_t v4)
{
  CAN_TxHeaderTypeDef tx_header_1;
  uint8_t             tx_data_1[8];
    
	if(id_range == 2)tx_header_1.StdId = 0x200;
	else tx_header_1.StdId = (id_range == 0)?(0x1ff):(0x2ff);
  tx_header_1.IDE   = CAN_ID_STD;
  tx_header_1.RTR   = CAN_RTR_DATA;
  tx_header_1.DLC   = 8;

  tx_data_1[0] = (v1>>8)&0xff;
  tx_data_1[1] =    (v1)&0xff;
  tx_data_1[2] = (v2>>8)&0xff;
  tx_data_1[3] =    (v2)&0xff;
  tx_data_1[4] = (v3>>8)&0xff;
  tx_data_1[5] =    (v3)&0xff;
  tx_data_1[6] = (v4>>8)&0xff;
  tx_data_1[7] =    (v4)&0xff;
  HAL_CAN_AddTxMessage(&hcan1, &tx_header_1, tx_data_1,(uint32_t*)CAN_TX_MAILBOX0); 
}


void set_motor_voltage_CAN2(uint8_t id_range, int16_t v1, int16_t v2, int16_t v3, int16_t v4)
{
  CAN_TxHeaderTypeDef tx_header_2;
  uint8_t             tx_data_2[8];
    
	if(id_range == 2)tx_header_2.StdId = 0x200;
	else tx_header_2.StdId = (id_range == 0)?(0x1ff):(0x2ff);
	
  tx_header_2.IDE   = CAN_ID_STD;
  tx_header_2.RTR   = CAN_RTR_DATA;
  tx_header_2.DLC   = 8;

  tx_data_2[0] = (v1>>8)&0xff;
  tx_data_2[1] =    (v1)&0xff;
  tx_data_2[2] = (v2>>8)&0xff;
  tx_data_2[3] =    (v2)&0xff;
  tx_data_2[4] = (v3>>8)&0xff;
  tx_data_2[5] =    (v3)&0xff;
  tx_data_2[6] = (v4>>8)&0xff;
  tx_data_2[7] =    (v4)&0xff;
  HAL_CAN_AddTxMessage(&hcan2, &tx_header_2, tx_data_2,(uint32_t*)CAN_TX_MAILBOX0); 
}

//返回底盘电机变量地址，通过指针方式获取原始数据

//can1电机
const moto_info_t *get_Chassis_Motor_Measure_Point(uint8_t i)
{
    return &motor_info[(i & 0x03)];//&0x03是屏蔽高六位，保证电机的前4位是底盘电机的
}
	
//返回yaw电机变量地址，通过指针方式获取原始数据
const moto_info_t *get_Yaw_Gimbal_Motor_Measure_Point(void)
{
    return &motor_info[MOTOR_4_YAW];
}
//返回pitch电机变量地址，通过指针方式获取原始数据
const moto_info_t *get_Pitch_Gimbal_Motor_Measure_Point(void)
{
    return &motor_info[MOTOR_5_PITCH];
}
//返回弹仓电机变量地址，通过指针方式获取原始数据
const moto_info_t *get_PAN_Trigger_Motor_Measure_Point(void)
{
    return &motor_info[MOTOR_6_PAN_TRIGGER];
}


//can2电机
//返回拨叉电机变量地址，通过指针方式获取原始数据
const moto_info_t *get_Trigger_Motor_Measure_Point(void)
{
    return &motor_info_2[MOTOR_7_TRIGGER];
}

//返回上下电机变量地址，通过指针方式获取原始数据
const moto_info_t *get_Shooting_Up_Motor_Measure_Point(void)
{
    return &motor_info_2[SHOOTING_UP_MOTOR];
}

const moto_info_t *get_Shooting_Down_Motor_Measure_Point(void)
{
    return &motor_info_2[SHOOTING_DOWN_MOTOR];//中的MOTOR_MAX_NUM的数字7代表上摩擦轮带电机
}

