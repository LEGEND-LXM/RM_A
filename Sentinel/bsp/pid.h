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
    
    float set[3];				//Ŀ��ֵ,����NOW�� LAST�� LLAST���ϴ�
    float get[3];				//����ֵ
    float err[3];				//���
	
    
    float pout;							//p���
    float iout;							//i���
    float dout;							//d���
    
    float pos_out;						//����λ��ʽ���
    float last_pos_out;				//�ϴ����
    float delta_u;						//��������ֵ
    float delta_out;					//��������ʽ��� = last_delta_out + delta_u
    float last_delta_out;
    
	  float max_err;
	  float deadband;				//err < deadband return
    uint32_t pid_mode;
    uint32_t MaxOutput;				//����޷�
    uint32_t IntegralLimit;		//�����޷�
    
    void (*f_param_init)(struct __pid_t *pid,  //PID������ʼ��
													uint32_t pid_mode,
													uint32_t maxOutput,
													uint32_t integralLimit,
													float p,
													float i,
													float d);
													
    void (*f_pid_reset)(struct __pid_t *pid, float p, float i, float d);		//pid���������޸�

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
extern pid_t pid_vision_yaw;//�Ӿ�yaw���⻷
extern pid_t pid_vision_pitch;//�Ӿ�pit���⻷	

extern pid_t pid_vision2_yaw;//�Ӿ�yaw���⻷
extern pid_t pid_vision2_pitch;//�Ӿ�pit���⻷				
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
														