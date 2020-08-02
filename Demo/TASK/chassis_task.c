/*步兵地盘示意图                               */
/* -    motor_1 **          ** motor_2         */
/*                **********                   */
/*                  ******                     */
/*                  ******                     */
/*                  ******                     */
/*                **********                   */
/* -    motor_3 **          ** motor_4         */

#include "chassis_task.h"

CHASSIS_Type CHASSIS_Ture ;
pid_struct_t Chassis_motor_PID[4] ;
uint16_t relative_angle(uint16_t angle);
uint16_t difference = 8192 - Yaw_Init_value;

void StartTask_Chassis(void const * argument) 
{
	osDelay(1);
	int32_t CH_Whole = 0 ;
	int16_t CH_X = 0;  // X平移方向速度（车的前后退）前进为正
	int16_t CH_X1 = 0;  // 暂存数据计算
	float CH_X_Proportion = 0;  // X平移方向速度占比
	int16_t CH_Y = 0;	 // y平移方向速度（车的左右方向） 左移为正
	int16_t CH_Y1 = 0;  // 暂存数据计算
	float CH_Y_Proportion = 0;  // y平移方向速度占比
	int16_t CH_R = 0;  // 车的旋转方向速度
	float CH_R_Proportion = 0;  // 车的旋转方向速度占比
	CHASSIS_Ture.Mode = 1;  // 初始化运动模式（1为普通模式；2为小陀螺模式）
/**********************************初始化底盘电机PID结构体***************************************************/
/*        1号电机\\				//2号电机	
//
//
//
//				4号电机//				\\3号电机
*/	
		
	     pid_init(&Chassis_motor_PID[0] ,POSITION_PID      //1号电机
																			,24            		 //Kp
																			,0            		 //Ki
																			,0            		 //Kd
																			,1000 ,20000 ,10); //初始化底盘电机PID结构体
	     CHASSIS_Ture.Chassis_motor_voltage[0] = 0;
	
	     pid_init(&Chassis_motor_PID[1] ,POSITION_PID      //2号电机      
																			,22                 //Kp
																			,0                 //Ki
																			,0                 //Kd
																			,1000 , 20000,10);  //初始化底盘电机PID结构体
	     CHASSIS_Ture.Chassis_motor_voltage[1] = 0;
	
	     pid_init(&Chassis_motor_PID[2] ,POSITION_PID      //4号电机
																			,23                 //Kp
																			,0                 //Ki
																			,0                 //Kd
																			,1000 , 20000,10);//初始化底盘电机PID结构体
			 CHASSIS_Ture.Chassis_motor_voltage[2] = 0;	
			 
	     pid_init(&Chassis_motor_PID[3] ,POSITION_PID      //3号电机 
																			,26                 //Kp
																			,0                 //Ki
																			,0                 //Kd
																			,1000 ,20000 ,10);  //初始化底盘电机PID结构体
	     CHASSIS_Ture.Chassis_motor_voltage[3] = 0;	
	



/*************************************************************************************************************/			

	for(;;)
  {
	if((remote_control.switch_left != 3 || remote_control.switch_right != 3)
    &&(remote_control.switch_left != 1 || remote_control.switch_right != 1)		)
	{
		osDelay(4);
//remote_control.ch2：前进、后退
//remote_control.ch3：左右转向
//remote_control.ch1：左右平移
		CH_X = Dead_zone_immune(remote_control.ch2 ,10);
		CH_Y = Dead_zone_immune(remote_control.ch1 ,10);
		if(CHASSIS_Ture.Mode == 1)  // 普通模式，底盘的旋转由操作手控制
			{
				CH_X *= 0.707f;
				CH_Y *= 0.707f;
				CH_R = Dead_zone_immune(remote_control.ch3 ,10);
				if(Dead_zone_immune_angle(motor_info[6].rotor_angle - Yaw_Init_value, 0) 
					<= -114 && motor_info[6].rotor_angle > 1344)					 
				{  // 当底盘和云台间夹角大于5°时，底盘跟随云台
					CH_R += 1.2;  // 此处为给定一个额外的固定旋转方向的速度
				} 
				else	
					if(Dead_zone_immune_angle(motor_info[6].rotor_angle - Yaw_Init_value, 0) >= 114 || 
						 (Dead_zone_immune_angle(motor_info[6].rotor_angle - Yaw_Init_value, 0) 
							<= -114 && motor_info[6].rotor_angle < 1344))
				{
					CH_R -= 1.2;  // 此处为给定一个额外的固定旋转方向的速度
				}			
			}
		else if(CHASSIS_Ture.Mode == 2) // 小陀螺模式：底盘以一个固定速度旋转（并不影响其它方向的运动）
			{
				CH_R = Dead_zone_immune(396 ,10);
				HALDER_Ture.halder_motor[1].standard_angle = relative_angle(motor_info[6].rotor_angle);
				CH_X1 = CH_X;
				CH_Y1 = CH_Y;
				CH_X = CH_X1*My_Cos(HALDER_Ture.halder_motor[1].standard_angle) 
							+ CH_Y1*My_Sin(HALDER_Ture.halder_motor[1].standard_angle);
				CH_Y = - CH_X1*My_Sin(HALDER_Ture.halder_motor[1].standard_angle) 
							+ CH_Y1*My_Cos(HALDER_Ture.halder_motor[1].standard_angle);
				
				
			}
		
		// 计算出每个方向速度占总体的比例，
		//保证运动合成时不会改变个方向上的速度
		CH_Whole = CH_X + CH_Y + CH_R ;  
		CH_X_Proportion = CH_X/CH_Whole;
		CH_Y_Proportion = CH_Y/CH_Whole;
		CH_R_Proportion = CH_R/CH_Whole;
		
		CH_X *= CH_X_Proportion*1638;
		CH_Y *= CH_Y_Proportion*1638;
		CH_R *= CH_R_Proportion*1638;
		
		
/**********************************底盘电机运动拟合（遥控）***************************************************/
		
/**********************************底盘电机运动拟合（遥控）***************************************************/
  CHASSIS_Ture.Chassis_motor_voltage[0] = (CH_X - CH_Y - CH_R );  //1号电机
	CHASSIS_Ture.Chassis_motor_voltage[0] = fp32_constrain( CHASSIS_Ture.Chassis_motor_voltage[0] ,-8192 ,8192 );
		
  CHASSIS_Ture.Chassis_motor_voltage[1] = (CH_X + CH_Y + CH_R );  //2号电机
	CHASSIS_Ture.Chassis_motor_voltage[1] = fp32_constrain( CHASSIS_Ture.Chassis_motor_voltage[1] ,-8192 ,8192 );	
	
  CHASSIS_Ture.Chassis_motor_voltage[2] = (CH_X + CH_Y - CH_R) ;  //4号电机
	CHASSIS_Ture.Chassis_motor_voltage[2] = fp32_constrain( CHASSIS_Ture.Chassis_motor_voltage[2] ,-8192 , 8192);
		
  CHASSIS_Ture.Chassis_motor_voltage[3] = (CH_X - CH_Y + CH_R) ;  //3号电机
	CHASSIS_Ture.Chassis_motor_voltage[3] = fp32_constrain( CHASSIS_Ture.Chassis_motor_voltage[3] ,- 8192, 8192);
		
/*************************************************************************************************************/	
/**********************************底盘电机PID计算***************************************************/		

	    motor_info[0].set_voltage = pid_calc(&Chassis_motor_PID[0] 
																					,CHASSIS_Ture.Chassis_motor_voltage[0] 
																					,motor_info[0].rotor_speed );		 
	    motor_info[1].set_voltage = pid_calc(&Chassis_motor_PID[1] 
																					,CHASSIS_Ture.Chassis_motor_voltage[1] 
																					,motor_info[1].rotor_speed );			 
	    motor_info[2].set_voltage = pid_calc(&Chassis_motor_PID[2] 
																					,CHASSIS_Ture.Chassis_motor_voltage[2] 
																					,motor_info[2].rotor_speed );
	    motor_info[3].set_voltage = pid_calc(&Chassis_motor_PID[3] 
																					,CHASSIS_Ture.Chassis_motor_voltage[3] 
																					,motor_info[3].rotor_speed );	
		
/*************************************************************************************************************/	
		
		set_motor_voltage(1 ,motor_info[0].set_voltage 
												,motor_info[1].set_voltage 
												,motor_info[2].set_voltage 
												,motor_info[3].set_voltage
										 );
	HAL_GPIO_WritePin( GPIOG , LED5_Pin, GPIO_PIN_SET);
 
   
 }
	else
	{
		set_motor_voltage(1 ,0 
												,0 
												,0 
												,0
										 );
		HAL_GPIO_WritePin( GPIOG , LED5_Pin, GPIO_PIN_RESET);
	}
  }
	
}
//死区限定函数（int16_t型）
// (CHx/100)*4250 ：输出为该方向速度为 (CHx/132) m/s 时的该位置电机的输出值 
int16_t Dead_zone_immune(int16_t CHx ,uint16_t Dead_line)     
{
	if( (CHx <=0) && (CHx+Dead_line >=0) )		
			return 0;
	else
		if( (CHx >0) && (CHx-Dead_line <=0) )
			return 0;
	else
		 return ((int)CHx/132);
}

uint16_t relative_angle(uint16_t angle)
{
	uint16_t value = 0;
	if( angle > 5440 )
	{
		return (angle - Yaw_Init_value)*0.0439;
	}
	else
		if( angle <  5440 )
		{
			return (angle + difference)*0.0439;
		}
	else
		if( angle == 5440 )
		{
			return 0;
		}
	
}
