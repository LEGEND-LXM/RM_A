#include "gimbal_task.h"
#include "bsp_headfile.h"
//#include "mpu_dmp_useapi.h"
//#include "mpu6050.h"
#include "Remote_Control.h"
#include "robomaster_vision.h"
#include "stdio.h"
float yaw,pit;


gimbal_checktask GIMBALCHECK;
extern RC_Type remote_control;
extern int cnt1;
extern uint8_t IO_value_1,IO_value_2;
uint8_t move_flag=0;


#define GYRO_XISHU		(2000.0/65535.0)
#define chassis_speed 4000
#define chassis_speed_plus 6000
#define chassis_speed_mini 3000
volatile float speed_PIT = 0;
volatile float speed_YAW = 0;	
volatile float angle_PIT = 3500;		
volatile float angle_YAW = 5000;		


volatile float speed_PIT2 = 0;
volatile float speed_YAW2 = 0;	
volatile float angle_PIT2 = 3500;		
volatile float angle_YAW2 = 5000;		

int remote_pit=4827;  //ң��������ĽǶ�
int remote_yaw=6665;  //ң��������ĽǶ�
int remote_bodan=0;//ң��������Ĳ�����
int remote_mocha=0;//ң���������Ħ����
int remote_speed=0;  //ң��������Ľ��ٶ�
int HP=600,HP_error=0,count2=0,count3=0,flagflag=0;
int speed_flag_up=0,speed_flag_down=0;

int16_t mpuspeed_pit,mpuspeed_yaw,mpu_pit,mpu_yaw;	
int16_t motor[4]={0};
//�����ý��ٶ�mpuspeed_pit mpuspeed_yaw
//��õĽǶ�pit
void run_speed(int speed)
{
	if(IO_value_1==0&&IO_value_2==1)
	{
		remote_speed=-speed;
		move_flag=0;
	}
	else if(IO_value_1==1&&IO_value_2==0)
	{
		remote_speed=speed;
		move_flag=1;
	}
	else if(IO_value_1==1&&IO_value_2==1)
	{
		if(move_flag==0)   remote_speed=-speed;
		if(move_flag==1)   remote_speed=speed;	
	}
	else
	{
		remote_speed=0;
	}
	pid_calc(&pid_moto1_move,motor_info[moto1].rotor_speed,-remote_speed); 
  pid_calc(&pid_moto2_move,motor_info[moto2].rotor_speed,remote_speed);
	motor[0]=pid_moto1_move.pos_out;
	motor[1]=pid_moto2_move.pos_out;
	Super_Cap_control(motor);
	set_chassismotor_voltage(motor[0],motor[1]);
}

void yuntai_control()//��̨����
{///////////////////////////YAW�����/////////////////////////////////
	speed_YAW=75;
	pid_calc(&pid_yuntai_yaw_speed,imu.gz,speed_YAW);
	if(pid_yuntai_yaw_speed.pos_out>0)
	{
		pid_yuntai_yaw_speed.pos_out=pid_yuntai_yaw_speed.pos_out+100;
	}
	if(pid_yuntai_yaw_speed.pos_out<0)
	{
		pid_yuntai_yaw_speed.pos_out=pid_yuntai_yaw_speed.pos_out-100;
	}
//	set_yuntaimotor_voltage(-pid_yuntai_yaw_speed.pos_out,0,0);
		set_yuntaimotor_voltage(0,0,0);

}

void bodan_control(void)
{
	
//		     fric1_on(1400);       //���
//	       fric2_on(1400);
	
	remote_bodan=remote_control.ch2*5;
//	 remote_bodan=remote_control.ch3*5;
	 pid_calc(&check_bodan,motor_info[BODAN].rotor_speed,remote_bodan);
	 //set_yuntaimotor_voltage(0,0,check_bodan.pos_out);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//���߿���
void offline_control(void)
{
  fric_off();//ͣĦ����
	set_yuntaimotor_voltage(0,0,0);
	set_chassismotor_voltage(0,0);
	set_bodanmotor2_voltage(0);
	set_yuntaimotor2_voltage(0  , 0);
}

void shoot_control(void)
{
	
	
	if(motor_info[PITCH].rotor_angle>4875)
	{
		pid_yuntai_yaw_speed.pos_out = -pid_yuntai_yaw_speed.pos_out;
	}
		if(motor_info[PITCH2].rotor_angle>4875)
	{
		pid_yuntai2_yaw_speed.pos_out = -pid_yuntai2_yaw_speed.pos_out;
	}
	
	if(robot_status.vision_status==VISION_SUCCESS)
	{
	armour_attack();
	if(abs(VISION_PIT_TARGET-Armour_attack.pan_tilt_angel_err.Pitch_Err)<60 
		&& abs(VISION_PIT_TARGET-Armour_attack.pan_tilt_angel_err.Pitch_Err)<60)
	{
		pid_calc(&check_bodan,motor_info[BODAN].rotor_speed,1500);
		pid_calc(&check_bodan2,motor_info[BODAN].rotor_speed,1500);
	  set_yuntaimotor_voltage(-pid_yuntai_yaw_speed.pos_out,pid_yuntai_pitch_speed.pos_out,check_bodan.pos_out);
		set_bodanmotor2_voltage(check_bodan2.pos_out);
	}
	else
	{
		set_yuntaimotor_voltage(-pid_yuntai_yaw_speed.pos_out,pid_yuntai_pitch_speed.pos_out,0);
		set_yuntaimotor2_voltage(-pid_yuntai2_yaw_speed.pos_out,pid_yuntai2_pitch_speed.pos_out);
	}
	}
	
else
{
			/********************************yaw��*****************************************************/


	speed_YAW=150;
	speed_YAW2=150;
	pid_calc(&pid_yuntai_yaw_speed,imu.gz,speed_YAW);
	pid_calc(&pid_yuntai2_yaw_speed,imu.gz,speed_YAW2);
	if(pid_yuntai_yaw_speed.pos_out>0&&pid_yuntai2_yaw_speed.pos_out>0)
	{
		pid_yuntai_yaw_speed.pos_out=pid_yuntai_yaw_speed.pos_out+100;
		pid_yuntai2_yaw_speed.pos_out=pid_yuntai2_yaw_speed.pos_out+100;
	}
	if(pid_yuntai_yaw_speed.pos_out<0&&pid_yuntai2_yaw_speed.pos_out<0)
	{
		pid_yuntai_yaw_speed.pos_out=pid_yuntai_yaw_speed.pos_out-100;
		pid_yuntai2_yaw_speed.pos_out=pid_yuntai2_yaw_speed.pos_out-100;
	}
	
	
			/********************************pitch��*****************************************************/
	          pid_calc(&pid_yuntai_pitch,motor_info[PITCH].rotor_angle,6500);
				    pid_calc(&pid_yuntai_pitch_speed,imu.gx,pid_yuntai_pitch.pos_out);
	          pid_calc(&pid_yuntai2_pitch,motor_info[PITCH2].rotor_angle,6500);
				    pid_calc(&pid_yuntai2_pitch_speed,imu.gx,pid_yuntai_pitch.pos_out);

	
	
	
	set_yuntaimotor_voltage(-pid_yuntai_yaw_speed.pos_out,pid_yuntai_pitch_speed.pos_out,0);
	set_yuntaimotor2_voltage(-pid_yuntai2_yaw_speed.pos_out,pid_yuntai2_pitch_speed.pos_out);
//		set_yuntaimotor_voltage(0,0,0);
}



}


void manual_control(void)
{
	
	
				/******************************���̵��****************************************************/
	remote_speed=remote_control.ch1*4000/660;
	
	
	pid_calc(&pid_moto1_move,motor_info[moto1].rotor_speed,-remote_speed); 
  pid_calc(&pid_moto2_move,motor_info[moto2].rotor_speed,remote_speed);
	motor[0]=pid_moto1_move.pos_out;
	motor[1]=pid_moto2_move.pos_out;
//	Super_Cap_control(motor);
	set_chassismotor_voltage(motor[0],motor[1]);
	

	
	
			 //ԭ״ֹ̬ͣ���е��
//	  set_yuntaimotor_voltage(0,0,0);
		
//		if(remote_control.switch_left == 3)
		
			/******************************yaw��pitch��****************************************************/
			/*****************************�ǶȻ�**************************************************/
//						pid_calc(&pid_yuntai_yaw  ,motor_info[YAW].rotor_angle,500);
	          pid_calc(&pid_yuntai_pitch,motor_info[PITCH].rotor_angle,6500);
			/*****************************�ǶȻ�**************************************************/
			
//            if(remote_control.ch3 <-5||remote_control.ch3 >5)
//			{
				    		remote_yaw=(-remote_control.ch3*500/660)+0;     //yaw_control;//ƫ���ǽǶ�������ֱ����Դ��ң���������
//                pid_calc(&pid_yuntai_yaw  ,motor_info[YAW].rotor_angle,remote_yaw);
////			}      
			      if(remote_control.ch4 <-5||remote_control.ch4 >5) 
			{
				        remote_pit=(remote_control.ch4*650/660)+6500;     //yaw_control;//ƫ���ǽǶ�������ֱ����Դ��ң���������
                pid_calc(&pid_yuntai_pitch,motor_info[PITCH].rotor_angle,remote_pit);
			}
			
			/******************************���ٶȻ�***********************************************/
//						pid_calc(&pid_yuntai_yaw_speed  ,imu.gz,remote_yaw);pid_yuntai_yaw.pos_out  pid_yuntai_pitch.pos_out
				    pid_calc(&pid_yuntai_yaw_speed  ,imu.gz,remote_yaw);
//	          pid_calc(&pid_yuntai_pitch_speed,imu.gx,remote_pit);
				    pid_calc(&pid_yuntai_pitch_speed,imu.gx,pid_yuntai_pitch.pos_out);
			/******************************���ٶȻ�***********************************************/
		/********************************yaw��pitch��*****************************************************/
			
			
			
	    /******************************�����ֵ��*********************************************/
			
			if(remote_control.switch_right == 3) 
			{
				bodan_control();
			
			}
			
			
//		if(remote_control.switch_right == 3)         
//		{
//			
//	       fric1_on(1400);       //���
//	       fric2_on(1400);
//			
//			
//			   remote_bodan = 0;
//				if(remote_control.ch1 > 5)
//				{
//					remote_bodan = remote_control.ch1 *(-5);
//				}
//		}
		/********************************�����ֵ��*********************************************/
		
	          //�������	
			      set_yuntaimotor_voltage(-pid_yuntai_yaw_speed.pos_out,pid_yuntai_pitch_speed.pos_out,remote_bodan);
//					  set_yuntaimotor_voltage(0,0,0);
//			      set_yuntaimotor_voltage(-pid_yuntai_yaw_speed.pos_out,0,remote_bodan);


		
	 
		
	 /*********************************j_scope***********************************************/
//			        yaw_in      =  mpuspeed_yaw;
//	            yaw_out     =  pid_yuntai_yaw.pos_out;
//	            yaw_angle   =  motor_info[0].rotor_angle;
//	            pitch_angle =  motor_info[1].rotor_angle;
//	armour_attack();
//	if(abs(VISION_PIT_TARGET-Armour_attack.pan_tilt_angel_err.Pitch_Err)<60 
//		&& abs(VISION_PIT_TARGET-Armour_attack.pan_tilt_angel_err.Pitch_Err)<60)
//	{
//		pid_calc(&check_bodan,motor_info[BODAN].rotor_speed,1500);
//	  set_yuntaimotor_voltage(-pid_yuntai_yaw_speed.pos_out,pid_yuntai_pitch_speed.pos_out,check_bodan.pos_out);
//	}
//	else
//	{
//		set_yuntaimotor_voltage(-pid_yuntai_yaw_speed.pos_out,pid_yuntai_pitch_speed.pos_out,0);
//	}
}

void Get_Anglespeed(void)
{
//	mpu_get_data();                         //���ⲿ�ж�
//	mpuspeed_pit = gyro_mpu[1]*GYRO_XISHU; //���ٶȻ��
//	mpuspeed_yaw = gyro_mpu[2]*GYRO_XISHU; //���ٶȻ��
//	mpu_pit=(int)pit*10,                   //�ǶȻ��
//	mpu_yaw=(int)yaw*10;                   //�ǶȻ��
	
}


/*
speed_flag_up
1������ȫ����
2��ֹͣ
3��������
	
speed_flag_down
1:pit yaw bodan�����
2:��̨��׼������ת��
3:pit����㣬yawת�������������
*/
void decision(void)
{
	HP_error=HP-refSysData.game_robot_state_t.remain_HP;
	
	if(refSysData.game_robot_state_t.remain_HP<=200) //Ѫ������200ʱ�������ӵ���ȫ����
	{
		speed_flag_down=1;
		speed_flag_up=1;
	}
	else if(HP_error>50)    //��ⱻ��������ȫ���ܣ���ʶ��
	{
		speed_flag_down=1;
		flagflag=1;
	}
  else if(robot_status.vision_status==VISION_SUCCESS && flagflag==0)
	{
		speed_flag_up=2;
		speed_flag_down=2;
	}
	else
	{
		speed_flag_up=3;
		speed_flag_down=3;
	}
	
	if(flagflag==1 && IO_value_1==1 && IO_value_2==1)//����Ϳ����
	{
		speed_flag_up=1;
		speed_flag_down=1;
	}
	if(IO_value_1==0 || IO_value_2==0)
	{
		flagflag=0;
	}                                              //�ܵ�һ��Ϊֹ
	switch(speed_flag_up)
	{
		
		case 1:run_speed(0);break;
		case 2:run_speed(0);break;
		case 3:run_speed(0);break;
//		case 1:run_speed(1000);break;
//		case 2:run_speed(0);break;
//		case 3:run_speed(1000);break;
		
//		case 1:run_speed(chassis_speed_plus);break;
//		case 2:run_speed(0);break;
//		case 3:run_speed(chassis_speed_mini);break;
	}
//	if(speed_flag_up==1)   run_speed(chassis_speed_plus);
//	if(speed_flag_up==2)   run_speed(0);
//	if(speed_flag_up==3)   run_speed(chassis_speed_mini);
	if(speed_flag_down==1)  set_yuntaimotor_voltage(0,0,0);
//	if(speed_flag_down==2)  manual_control();
	if(speed_flag_down==2)  
		shoot_control();
	if(speed_flag_down==3)  
		yuntai_control();
	
	HP=refSysData.game_robot_state_t.remain_HP;
}
