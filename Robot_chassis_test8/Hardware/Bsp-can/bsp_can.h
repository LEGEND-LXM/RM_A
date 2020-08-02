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

#ifndef __BSP_CAN
#define __BSP_CAN

#include "can.h"

#define FEEDBACK_ID_BASE      0x201
#define CAN_CONTROL_ID_BASE   0x1ff
#define CAN_CONTROL_ID_EXTEND 0x2ff
#define MOTOR_MAX_NUM         	9

#define MOTOR_4_YAW							4  //在测试的底盘上，电机编号如此
#define MOTOR_5_PITCH						5
#define MOTOR_6_PAN_TRIGGER		  6

#define MOTOR_7_TRIGGER			    6
#define SHOOTING_UP_MOTOR				2
#define SHOOTING_DOWN_MOTOR			1

//rm电机统一数据结构体

typedef struct
{
    uint16_t can_id;
		uint16_t last_rotor_angle;//last_ecd
    uint16_t rotor_angle;//ecd 机械角度
    int16_t  rotor_speed;//speed_rpm 转速
    int16_t  torque_current;// given_current 转矩
    uint8_t  temp;
		int16_t  set_voltage;//given_cyrrent
	  int16_t  current_set;
		float motor_gyro_set;
}moto_info_t;

void can_user_init(CAN_HandleTypeDef* hcan);
void set_motor_voltage_CAN1(uint8_t id_range, int16_t v1, int16_t v2, int16_t v3, int16_t v4);
void set_motor_voltage_CAN2(uint8_t id_range, int16_t v1, int16_t v2, int16_t v3, int16_t v4);

extern moto_info_t motor_info[MOTOR_MAX_NUM];

//返回底盘电机变量地址，通过指针方式获取原始数据,i的范围是0-3，对应0x201-0x204,
extern const moto_info_t *get_Chassis_Motor_Measure_Point(uint8_t i);
//返回yaw电机变量地址，通过指针方式获取原始数据
extern const moto_info_t *get_Yaw_Gimbal_Motor_Measure_Point(void);
//返回pitch电机变量地址，通过指针方式获取原始数据
extern const moto_info_t *get_Pitch_Gimbal_Motor_Measure_Point(void);
//返回trigger电机变量地址，通过指针方式获取原始数据
extern const moto_info_t *get_Trigger_Motor_Measure_Point(void);
//返回上下摩擦轮电机地址，通过指针方式获取原始数据
extern const moto_info_t *get_Shooting_Up_Motor_Measure_Point(void);
extern const moto_info_t *get_Shooting_Down_Motor_Measure_Point(void);

extern const moto_info_t *get_PAN_Trigger_Motor_Measure_Point(void);
extern const moto_info_t *get_Trigger_Motor_Measure_Point(void);

#endif
