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

#define FEEDBACK_ID_BASE      0x204
#define MOTORID   0x200  //底盘电机ID
#define HEADID    0x1FF   //云台电机ID  


#define YAW   1
#define PITCH 2
#define BODAN 3

#define moto1 4
#define moto2 5


#define YAW2   6
#define PITCH2 7
#define BODAN2 8
typedef struct
{
    uint16_t can_id;
    int16_t  set_voltage;
    uint16_t rotor_angle;
    int16_t  rotor_speed;
    int16_t  torque_current;
    uint8_t  temp;
}moto_info_t;

extern moto_info_t motor_info[6];

void can_user_init(CAN_HandleTypeDef* hcan);
void set_motor_voltage(uint8_t id_range, int16_t v1, int16_t v2, int16_t v3, int16_t v4);

void set_yuntaimotor_voltage(int16_t v1, int16_t v2,int16_t v3);
void set_bodanmotor_voltage(int16_t v1);
void set_bodanmotor2_voltage(int16_t v4);
void set_yuntaimotor2_voltage(int16_t v3, int16_t v4);
void set_chassismotor_voltage(int16_t v1, int16_t v2);
#endif
