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
#include "User_lib.h"
#include "arm_math.h"

#define rad_format(Ang) loop_fp32_constrain((Ang), -PI, PI)
/**
  * @brief  init pid parameter
  * @param  pid struct
    @param  parameter
  * @retval None
  */
void pid_init(pid_struct_t *pid,
              float kp,
              float ki,
              float kd,
              float i_max,
              float out_max)
{
	if (pid == NULL)	return ;
		
  pid->kp      = kp;
  pid->ki      = ki;
  pid->kd      = kd;
  pid->i_max   = i_max;
  pid->out_max = out_max;
}

/**
  * @brief  pid calculation
  * @param  pid struct
    @param  reference value
    @param  feedback value
  * @retval calculation result
  */
float pid_calc(pid_struct_t *pid, float ref, float fdb)
{
	if (pid == NULL)
	{
		return 0.0f;
	}
  pid->ref = ref;
  pid->fdb = fdb;
  pid->err[1] = pid->err[0];
  pid->err[0] = pid->ref - pid->fdb;
  
  pid->p_out  = pid->kp * pid->err[0];
  pid->i_out += pid->ki * pid->err[0];
  pid->d_out  = pid->kd * (pid->err[0] - pid->err[1]);
  LIMIT_MIN_MAX(pid->i_out, -pid->i_max, pid->i_max);
  
  pid->output = pid->p_out + pid->i_out + pid->d_out;
  LIMIT_MIN_MAX(pid->output, -pid->out_max, pid->out_max);
	
  return pid->output;
}

void pid_clear(pid_struct_t *pid)
{
	if (pid == NULL)
	{
		return;
	}
	pid->fdb = pid->fdb = 0.0f;
	pid->p_out = pid->i_out = pid->d_out = pid->output = 0.0f;
	pid->err[0] = pid->err[1] = 0.0f;	
}

float PID_Calc(pid_struct_t *pid, float ref, float fdb, float error_delta)
{
    fp32 err;
    if (pid == NULL)
    {
        return 0.0f;
    }
    pid->fdb = fdb;
    pid->ref = ref;

    err = ref - fdb;
    pid->err[0] = rad_format(err);
    pid->p_out = pid->kp * pid->err[0];
    pid->i_out += pid->ki * pid->err[0];
    pid->d_out = pid->kd * error_delta;
    abs_limit(&pid->i_out, pid->i_max);
    pid->output = pid->p_out + pid->i_out + pid->d_out;
    abs_limit(&pid->output, pid->out_max);
    return pid->output;
}
