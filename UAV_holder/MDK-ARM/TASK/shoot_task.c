#include "shoot_task.h"
#include "Init.h"

extern moto_info_t motor_info[MOTOR_MAX_NUM];
//extern pid_struct_t motor_pid[3];
int32_t fric_remote;
extern pid_struct_t FRIC_speed_pid;
void shoot_Task(void const * argument)
{
	for(;;)
	{
			if(remote_control.switch_right == 3)
			     { 
					 ramp_calc(&fric_pwm,900);//б������fric����pwm
	         fric1_on(fric_pwm.out);       //���
	         fric2_on(fric_pwm.out);
//				 if(remote_control.ch1 > 5){
//		      fric_remote = (int)(900+remote_control.ch1*0.5);
//					 if(fric_remote>1900){fric_remote =1900;}
//		       if(fric_remote<900){fric_remote  =900;}
//			    fric1_on(fric_remote);       //Ħ������� 
//	        fric2_on(fric_remote);
//				    }
			      }
					 else
					 fric_off(); 
	} 
}
