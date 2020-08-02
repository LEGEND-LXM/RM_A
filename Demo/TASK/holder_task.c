/*Holder_motor[0]:Pitch��*/
/*Holder_motor[1]:Yaw��*/
/*YAW:(ǰ) 1340 -- 5440(���)����+-��1320 */
/*PITCH:(��)3900 - 3170 - 2700(��) */
/**/
#include "holder_task.h"

int16_t Dead_zone_immune(int16_t CHx ,uint16_t Dead_line);
HALDER_Type HALDER_Ture = {0} ;
pid_struct_t Holder_motor_PID[4] = {0} ;

void StartTask_Holder(void const * argument) 
{
	osDelay(5);
	HALDER_Ture.Mode = 1;  // ��ʼ��������ģʽ��1Ϊ��ͨģʽ��2ΪС����ģʽ��
	if(Dead_zone_immune_angle(motor_info[6].rotor_angle - Yaw_Init_value, 0) == 0) 
	{
		HALDER_Ture.halder_motor[1].standard_angle = 0;
	}
/**********************************��ʼ����̨���PID�ṹ��***************************************************/	

	
	     pid_init(&Holder_motor_PID[0] ,POSITION_PID      // PITCH
																								,18 		// λ�û�PID������ʼ��
																								,0 
																								,0
																								,0 
																								,200 
																								,0 );   
	     pid_init(&Holder_motor_PID[1] ,POSITION_PID      // �ٶȻ�PID������ʼ��
																								,80 
																								,0
																								,0 
																								,0 
																								,30000 
																								,0);
	
	     pid_init(&Holder_motor_PID[2] ,POSITION_PID      //YAW
																								,10     // λ�û�PID������ʼ��
																								,0 
																								,0 
																								,0 
																								,300 
																								,0 );   
	     pid_init(&Holder_motor_PID[3] ,POSITION_PID 			// �ٶȻ�PID������ʼ��
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
		 _Pitch_ = Dead_zone_immune_angle(remote_control.ch4 ,5);  // �趨����������ң����ͨ��4ͨ��ֵ
		  _Yaw_  = Dead_zone_immune_angle(remote_control.ch3 ,5);  // �趨����������ң����ͨ��3ͨ��ֵ
		 HALDER_Ture.halder_motor[0].re_angle = Pitch_Init_value - (( _Pitch_ > 0 ) ? ( remote_control.ch4*0.71f ) : ( remote_control.ch4*1.1f )) ;
		 HALDER_Ture.halder_motor[1].re_angle = Yaw_Init_value - _Yaw_*2/*(( _Yaw_ > 0 ) ? ( -_Yaw_*2.0f ) : ( -_Yaw_*2.0f ))*/ ; 
/**********************************��̨�������PID����***************************************************/		


/**********************PITCH********************************************/
		 if( _Pitch_ == 0 )//ң�л��е�ʱ�򣬽��нǶȺͽ��ٶȻ�����  
		 {
			 if(Holder_motor_PID[0].ref==0)//
			 {
				 Holder_motor_PID[0].ref = imu.pit;
			 }
			 motor_info[4].set_voltage = pid_calc(&Holder_motor_PID[0] //λ�û�
																			
			 ,Holder_motor_PID[0].ref
																					 ,imu.pit ); 
			 Holder_motor_PID[1].ref = -motor_info[4].set_voltage;
		 }
	   else //ң�в�����ʱ�� ֻ�����ٶȻ�����
		 {
				 Holder_motor_PID[0].ref = 0;
				if(VISUAL_Ture.flag == 1)
					{
						Holder_motor_PID[1].ref = -VISUAL_Ture.Pitch_deviation*22.78f - _Pitch_*0.3f ;  // �����Ӿ�����
					}
				 else
				    Holder_motor_PID[1].ref = -_Pitch_*0.3f;
		 }

		 
	    motor_info[4].set_voltage = pid_calc(&Holder_motor_PID[1]  //�ٶȻ�
																					 ,Holder_motor_PID[1].ref
																				   ,imu.gy /*motor_info[4].set_voltage*/
																					);
		

         
/********************** YAW ********************************************/

		if( _Yaw_ == 0 )//ң�л��е�ʱ�򣬽��нǶȺͽ��ٶȻ�����
		{
			if( Holder_motor_PID[2].ref == 0 )
			{
				Holder_motor_PID[2].ref =  imu.yaw/*motor_info[6].rotor_angle*0.04f*/ ;
			}
		  motor_info[6].set_voltage = pid_calc(&Holder_motor_PID[2] //λ�û�
																					 ,Holder_motor_PID[2].ref//HALDER_Ture.halder_motor[1].re_angle*360/8192 
																					 ,imu.yaw ); 
			Holder_motor_PID[3].ref = motor_info[6].set_voltage;
		}
		else//ң�в�����ʱ��ֻ���н��ٶȻ����ƣ�
		{
			Holder_motor_PID[2].ref=0;
			if(VISUAL_Ture.flag == 1)
			{
				Holder_motor_PID[3].ref = -VISUAL_Ture.Raw_deviation*22.78f - _Yaw_*0.3f;
			}
			else
				Holder_motor_PID[3].ref = - _Yaw_*0.3f;
		}
	    motor_info[6].set_voltage = pid_calc(&Holder_motor_PID[3]  //�ٶȻ�
																					 ,Holder_motor_PID[3].ref//motor_info[6].set_voltage
																				   ,(imu.gz)/*motor_info[6].set_voltage*/);
		
/*************************************************************************************************************/	
//��shoot_task.c���ַ���		
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
	*�����޶�������int16_t�ͣ�
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





