/*Holder_motor[0]:Pitch轴*/
/*Holder_motor[1]:Yaw轴*/
/*YAW:(前) 1340 -- 5440(电池)：（+-）1320 */
/*PITCH:(下)3900 - 3170 - 2700(上) */
/**/
#include "holder_task.h"

int16_t Dead_zone_immune(int16_t CHx ,uint16_t Dead_line);
HALDER_Type HALDER_Ture = {0} ;
pid_struct_t Holder_motor_PID[4] = {0} ;

void StartTask_Holder(void const * argument) 
{
	osDelay(5);
	HALDER_Ture.Mode = 1;  // 初始化机器人模式（1为普通模式；2为小陀螺模式）
	if(Dead_zone_immune_angle(motor_info[6].rotor_angle - Yaw_Init_value, 0) == 0) 
	{
		HALDER_Ture.halder_motor[1].standard_angle = 0;
	}
/**********************************初始化云台电机PID结构体***************************************************/	

	
	     pid_init(&Holder_motor_PID[0] ,POSITION_PID      // PITCH
																								,18 		// 位置环PID参数初始化
																								,0 
																								,0
																								,0 
																								,200 
																								,0 );   
	     pid_init(&Holder_motor_PID[1] ,POSITION_PID      // 速度环PID参数初始化
																								,80 
																								,0
																								,0 
																								,0 
																								,30000 
																								,0);
	
	     pid_init(&Holder_motor_PID[2] ,POSITION_PID      //YAW
																								,10     // 位置环PID参数初始化
																								,0 
																								,0 
																								,0 
																								,300 
																								,0 );   
	     pid_init(&Holder_motor_PID[3] ,POSITION_PID 			// 速度环PID参数初始化
																							  ,80 
																							  ,0 
																							  ,0
																							  ,3000 
																							  ,30000 
																							  ,0 );

/*************************************************************************************************************/		
  int16_t _Pitch_ = 0 ;
	int16_t _Yaw_ = 0 ;
  	
	for(;;)
  {
		
	 if(remote_control.switch_left == 1 ) 
	 {	
     osDelay(1);		 
		 _Pitch_ = Dead_zone_immune_angle(remote_control.ch4 ,5);  // 设定死区并储存遥控器通道4通道值
		  _Yaw_  = Dead_zone_immune_angle(remote_control.ch3 ,5);  // 设定死区并储存遥控器通道3通道值
		 HALDER_Ture.halder_motor[0].re_angle = Pitch_Init_value - (( _Pitch_ > 0 ) ? ( remote_control.ch4*0.71f ) : ( remote_control.ch4*1.1f )) ;
		 HALDER_Ture.halder_motor[1].re_angle = Yaw_Init_value - _Yaw_*2/*(( _Yaw_ > 0 ) ? ( -_Yaw_*2.0f ) : ( -_Yaw_*2.0f ))*/ ; 
/**********************************云台电机初步PID计算***************************************************/		


/**********************PITCH********************************************/
		 if( _Pitch_ == 0 )//遥感回中的时候，进行角度和角速度环控制  
		 {
			 if(Holder_motor_PID[0].ref==0)//
			 {
				 Holder_motor_PID[0].ref = imu.pit;
			 }
			 motor_info[4].set_voltage = pid_calc(&Holder_motor_PID[0] //位置环
																			
			 ,Holder_motor_PID[0].ref
																					 ,imu.pit ); 
			 Holder_motor_PID[1].ref = -motor_info[4].set_voltage;
		 }
	   else //遥感拨动的时候 只进行速度环控制
		 {
				 Holder_motor_PID[0].ref = 0;
				if(VISUAL_Ture.flag == 1)
					{
						Holder_motor_PID[1].ref = -VISUAL_Ture.Pitch_deviation*22.78f - _Pitch_*0.3f ;  // 加入视觉补偿
					}
				 else
				    Holder_motor_PID[1].ref = -_Pitch_*0.3f;
		 }

		 
	    motor_info[4].set_voltage = pid_calc(&Holder_motor_PID[1]  //速度环
																					 ,Holder_motor_PID[1].ref
																				   ,imu.gy /*motor_info[4].set_voltage*/
																					);
		

         
/********************** YAW ********************************************/

		if( _Yaw_ == 0 )//遥感回中的时候，进行角度和角速度环控制
		{
			if( Holder_motor_PID[2].ref == 0 )
			{
				Holder_motor_PID[2].ref =  imu.yaw/*motor_info[6].rotor_angle*0.04f*/ ;
			}
		  motor_info[6].set_voltage = pid_calc(&Holder_motor_PID[2] //位置环
																					 ,Holder_motor_PID[2].ref//HALDER_Ture.halder_motor[1].re_angle*360/8192 
																					 ,imu.yaw ); 
			Holder_motor_PID[3].ref = motor_info[6].set_voltage;
		}
		else//遥感拨动的时候，只进行角速度环控制，
		{
			Holder_motor_PID[2].ref=0;
			if(VISUAL_Ture.flag == 1)
			{
				Holder_motor_PID[3].ref = -VISUAL_Ture.Raw_deviation*22.78f - _Yaw_*0.3f;
			}
			else
				Holder_motor_PID[3].ref = - _Yaw_*0.3f;
		}
	    motor_info[6].set_voltage = pid_calc(&Holder_motor_PID[3]  //速度环
																					 ,Holder_motor_PID[3].ref//motor_info[6].set_voltage
																				   ,(imu.gz)/*motor_info[6].set_voltage*/);
		
/*************************************************************************************************************/	
//由shoot_task.c部分发送		
		set_motor_voltage(2 ,0
												,0
												,motor_info[6].set_voltage
												,0
										 );
										 
		set_motor_voltage(0 ,motor_info[4].set_voltage
												,motor_info[5].set_voltage
												,0
												,0
										 );
							 
		HAL_GPIO_WritePin( GPIOG , LED6_Pin, GPIO_PIN_SET);
	}
	 else
	 {
		 motor_info[4].set_voltage = 0 ;
		 motor_info[6].set_voltage = 0 ;
		 
		 HAL_GPIO_WritePin( GPIOG , LED6_Pin, GPIO_PIN_RESET);
		 set_motor_voltage(2 ,0
												 ,0
												 ,motor_info[6].set_voltage
												 ,0
										 );
										 
		set_motor_voltage(0 ,motor_info[4].set_voltage
												,0
												,0
												,0
										 );
	 }

		osDelay(2);
  }
	
	
}

 /**
	*死区限定函数（int16_t型）
	*
**/                                                                                                                                                                                                                             
int16_t Dead_zone_immune_angle(int16_t CHx ,uint16_t Dead_line)
{
	if( (CHx <=0) && (CHx+Dead_line >=0) )		
			return 0;
	else
		if( (CHx >0) && (CHx-Dead_line <=0) )
			return 0;
	else
		 return CHx;
}





