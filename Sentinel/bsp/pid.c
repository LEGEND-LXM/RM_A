#include "pid.h"
#include "user_lib.h"
#include "math.h"

#define ABS(x)		((x>0)? (x): (-x)) 

pid_t check_pitch;
pid_t check_yaw;
pid_t check_bodan;

pid_t check_pitch2;
pid_t check_yaw2;
pid_t check_bodan2;

pid_t pid_yuntai_pitch;
pid_t pid_yuntai_yaw;
pid_t pid_yuntai_pitch_speed;
pid_t pid_yuntai_yaw_speed;
pid_t pid_moto_bodan;

pid_t pid_yuntai2_pitch;
pid_t pid_yuntai2_yaw;
pid_t pid_yuntai2_pitch_speed;
pid_t pid_yuntai2_yaw_speed;
pid_t pid_moto2_bodan;

pid_t pid_moto1_move;
pid_t pid_moto2_move;
pid_t pid_vision_yaw;//视觉yaw的外环
pid_t pid_vision_pitch;//视觉pit的外环

pid_t pid_vision2_yaw;//视觉yaw的外环
pid_t pid_vision2_pitch;//视觉pit的外环
/*参数初始化--------------------------------------------------------------*/
static void pid_param_init( pid_t *pid, 
														uint32_t mode,
														uint32_t maxout,
														uint32_t intergral_limit,
														float 	kp, 
														float 	ki, 
														float 	kd )
 {
    
    pid->IntegralLimit = intergral_limit;
    pid->MaxOutput = maxout;
    pid->pid_mode = mode;
    
    pid->p = kp;
    pid->i = ki;
    pid->d = kd;
    
 }


float pid_calc(pid_t* pid, float get, float set)
{
	pid->get[NOW] = get;
	                        
	pid->set[NOW] = set;
	
	pid->err[NOW] = set - get;	//set - measure
		 
    if (pid->max_err != 0 && ABS(pid->err[NOW]) >  pid->max_err)
		return 0;
	  if (pid->deadband != 0 && ABS(pid->err[NOW]) < pid->deadband)
		return 0;
    
    if(pid->pid_mode == POSITION_PID) //位置式p
    {   pid->pout = pid->p * pid->err[NOW];
        pid->iout += pid->i * pid->err[NOW];
        pid->dout = pid->d * (pid->err[NOW] - pid->err[LAST] );
        abs_limit(&(pid->iout), pid->IntegralLimit);
        pid->pos_out = pid->pout + pid->iout + pid->dout;
        abs_limit(&(pid->pos_out), pid->MaxOutput);
        pid->last_pos_out = pid->pos_out;	//update last time 
    }
    else if(pid->pid_mode == DELTA_PID)//增量式P
    {   pid->pout = pid->p * (pid->err[NOW] - pid->err[LAST]);
        pid->iout = pid->i * pid->err[NOW];
        pid->dout = pid->d * (pid->err[NOW] - 2*pid->err[LAST] + pid->err[LLAST]);
        
        abs_limit(&(pid->iout), pid->IntegralLimit);
        pid->delta_u = pid->pout + pid->iout + pid->dout;
        pid->delta_out = pid->last_delta_out + pid->delta_u;
        abs_limit(&(pid->delta_out), pid->MaxOutput);
        pid->last_delta_out = pid->delta_out;	//update last time
    }
    
    pid->err[LLAST] = pid->err[LAST];
    pid->err[LAST] = pid->err[NOW];
    pid->get[LLAST] = pid->get[LAST];
    pid->get[LAST] = pid->get[NOW];
    pid->set[LLAST] = pid->set[LAST];
    pid->set[LAST] = pid->set[NOW];
	
    return pid->pid_mode==POSITION_PID ? pid->pos_out : pid->delta_out;
		
}

/**
    *@bref. special calculate position PID @attention @use @gyro data!!
    *@param[in] set： target
    *@param[in] real	measure
    */
float pid_sp_calc(pid_t* pid, float get, float set, float gyro){
    pid->get[NOW] = get;
    pid->set[NOW] = set;
    pid->err[NOW] = set - get;	//set - measure
    
    
    if(pid->pid_mode == POSITION_PID) //位置式p
    {
        pid->pout = pid->p * pid->err[NOW];
				if(fabs(pid->i) >= 0.001f)
					pid->iout += pid->i * pid->err[NOW];
				else
					pid->iout = 0;
        pid->dout = -pid->d * gyro/100.0f;	
        abs_limit(&(pid->iout), pid->IntegralLimit);
        pid->pos_out = pid->pout + pid->iout + pid->dout;
        abs_limit(&(pid->pos_out), pid->MaxOutput);
        pid->last_pos_out = pid->pos_out;	//update last time 
    }
    else if(pid->pid_mode == DELTA_PID)//增量式P
    {
        pid->pout = pid->p * (pid->err[NOW] - pid->err[LAST]);
        pid->iout = pid->i * pid->err[NOW];
        pid->dout = pid->d * (pid->err[NOW] - 2*pid->err[LAST] + pid->err[LLAST]);
        
        abs_limit(&(pid->iout), pid->IntegralLimit);
        pid->delta_u = pid->pout + pid->iout + pid->dout;
        pid->delta_out = pid->last_delta_out + pid->delta_u;
        abs_limit(&(pid->delta_out), pid->MaxOutput);
        pid->last_delta_out = pid->delta_out;	//update last time
    }
    
    pid->err[LLAST] = pid->err[LAST];
    pid->err[LAST] = pid->err[NOW];
    pid->get[LLAST] = pid->get[LAST];
    pid->get[LAST] = pid->get[NOW];
    pid->set[LLAST] = pid->set[LAST];
    pid->set[LAST] = pid->set[NOW];
		

		
    return pid->pid_mode==POSITION_PID ? pid->pos_out : pid->delta_out;
//	
}

/*pid总体初始化-----------------------------------------------------------------*/
void PID_struct_init(pid_t* pid,
											uint32_t mode,
											uint32_t maxout,
											uint32_t intergral_limit,
															
											float 	kp, 
											float 	ki, 
											float 	kd)
{
    /*init function pointer*/
    pid->f_param_init = pid_param_init;
    pid->f_param_init(pid, mode, maxout, intergral_limit, kp, ki, kd);
}

