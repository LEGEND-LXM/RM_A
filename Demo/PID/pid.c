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
 
#include "pid.h"
#define ABS(x)		((x>0)? (x): (-x)) 

#define LIMIT_MIN_MAX(x,min,max) (x) = (((x)<=(min))?(min):(((x)>=(max))?(max):(x)))

/**
  * @brief  init pid parameter
  * @param  pid struct
    @param  parameter
  * @retval None
  */
	
/*参数初始化--------------------------------------------------------------*/
void pid_init(pid_struct_t *pid,
	            uint32_t mode,
              float kp,
              float ki,
              float kd,
              float i_max,
              float out_max,
							float deadband)
{
	pid->pid_mode = mode;
  pid->kp      = kp;
  pid->ki      = ki;
  pid->kd      = kd;
  pid->i_max   = i_max;
  pid->out_max = out_max;
	pid->deadband = deadband;
}

//pid计算
/**
  * @brief  pid calculation
  * @param  pid struct
    @param  reference value //目标值
    @param  feedback value  //实际值
  * @retval calculation result
  */
float pid_calc(pid_struct_t *pid, float ref, float fdb)
{
  pid->ref = ref;
  pid->fdb = fdb;
	pid->err[2] = pid->err[1];
  pid->err[1] = pid->err[0];
  pid->err[0] = pid->ref - pid->fdb;
	
	  if (pid->deadband != 0 && ABS(pid->err[0]) < pid->deadband)               //当err小于死区时不进行pid计算
		return 0;
		
		
		if(pid->pid_mode == POSITION_PID) //位置式
		{ 
  pid->p_out  = pid->kp * pid->err[0];
  pid->i_out += pid->ki * pid->err[0];
  pid->d_out  = pid->kd * (pid->err[0] - pid->err[1]);
  LIMIT_MIN_MAX(pid->i_out, -pid->i_max, pid->i_max);
  
  pid->output = pid->p_out + pid->i_out + pid->d_out;
  LIMIT_MIN_MAX(pid->output, -pid->out_max, pid->out_max);
//  return pid->output;
		}
		else if(pid->pid_mode == DELTA_PID)//增量式
		{
	pid->p_out  = pid->kp * pid->err[0]-pid->kp * pid->err[1];
  pid->i_out  = pid->ki * pid->err[0];
  pid->d_out  = pid->kd * (pid->err[0] - 2*pid->err[1]+pid->err[2]);
  LIMIT_MIN_MAX(pid->i_out, -pid->i_max, pid->i_max);
  
  pid->output += (pid->p_out + pid->i_out + pid->d_out);
  LIMIT_MIN_MAX(pid->output, -pid->out_max, pid->out_max);
		}
		return pid->output;
}





