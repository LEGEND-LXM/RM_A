#ifndef __PID_h
#define __PID_h

#include "stm32f4xx_hal.h"

enum{
    LLAST	= 0,
    LAST 	= 1,
    NOW 	= 2,
    
    POSITION_PID,
    DELTA_PID,
};

typedef struct __pid_t
{
    float p;
    float i;
    float d;
    
    float set[3];				//目标值,包含NOW， LAST， LLAST上上次
    float get[3];				//测量值
    float err[3];				//误差
	
    
    float pout;							//p输出
    float iout;							//i输出
    float dout;							//d输出
    
    float pos_out;						//本次位置式输出
    float last_pos_out;				//上次输出
    float delta_u;						//本次增量值
    float delta_out;					//本次增量式输出 = last_delta_out + delta_u
    float last_delta_out;
    
	  float max_err;
	  float deadband;				//err < deadband return
    uint32_t pid_mode;
    uint32_t MaxOutput;				//输出限幅
    uint32_t IntegralLimit;		//积分限幅
    
    void (*f_param_init)(struct __pid_t *pid,  //PID参数初始化
													uint32_t pid_mode,
													uint32_t maxOutput,
													uint32_t integralLimit,
													float p,
													float i,
													float d);
													
    void (*f_pid_reset)(struct __pid_t *pid, float p, float i, float d);		//pid三个参数修改

}pid_t;

void PID_struct_init(
											pid_t* pid,
											uint32_t mode,
											uint32_t maxout,
											uint32_t intergral_limit,
											
											float 	kp, 
											float 	ki, 
											float 	kd);
    
float pid_calc(pid_t* pid, float fdb, float ref);
		

		
extern pid_t pid_yuntai_pitch;
extern pid_t pid_yuntai_yaw;
extern pid_t pid_moto_bodan;
extern pid_t pid_yuntai_pitch_speed;
extern pid_t pid_yuntai_yaw_speed;
											
											
extern pid_t pid_yuntai2_pitch;
extern pid_t pid_yuntai2_yaw;
extern pid_t pid_moto2_bodan;
extern pid_t pid_yuntai2_pitch_speed;
extern pid_t pid_yuntai2_yaw_speed;
											
											
											
extern pid_t check_pitch;
extern pid_t check_yaw;
extern pid_t check_bodan;

extern pid_t check_pitch2;
extern pid_t check_yaw2;
extern pid_t check_bodan2;

extern pid_t pid_moto1_move;
extern pid_t pid_moto2_move;											
extern pid_t pid_vision_yaw;//视觉yaw的外环
extern pid_t pid_vision_pitch;//视觉pit的外环	

extern pid_t pid_vision2_yaw;//视觉yaw的外环
extern pid_t pid_vision2_pitch;//视觉pit的外环				
extern void PID_struct_init(
														pid_t* pid,
														uint32_t mode,
														uint32_t maxout,
														uint32_t intergral_limit,
														
														float 	kp, 
														float 	ki, 
														float 	kd);

#endif
/*********************lalal*************/
														