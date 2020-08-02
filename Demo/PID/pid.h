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
 
#ifndef _PID_H
#define _PID_H

#include "stm32f4xx_hal.h"

//#include "main.h"

enum{

    
    POSITION_PID,
    DELTA_PID,
};


typedef struct _pid_struct_t
{
  float kp;
  float ki;
  float kd;
  float i_max;
  float out_max;
	float max_err;
	float deadband;
	uint32_t pid_mode;
  
  float ref;      // target value
  float fdb;      // feedback value
  float err[3];   // error and last error

  float p_out;
  float i_out;
  float d_out;
  float output;
	
													
    void (*f_pid_reset)(struct _pid_struct_t *pid, float kp, float ki, float kd);		//pid三个参数修改
	
	
}pid_struct_t;

void pid_init(pid_struct_t *pid,
	            uint32_t mode,
              float kp,
              float ki,
              float kd,
              float i_max,
              float out_max,
							float deadband);
              
float  pid_calc(pid_struct_t *pid, float ref, float fdb);

#endif
