
#include "shoot_task.h"

extern moto_info_t  Holder_motor_info[2] ;

SHOOT_Type SHOOT_Ture ;
pid_struct_t Frictiongear_motor_PID[2] ;     //摩擦轮PID结构体
pid_struct_t Ammunition_Booster_PID ;        //拨弹电机PID结构体


void StartTask_Shoot(void const * argument) 
{
	osDelay(1) ;	
	
	PWM_INPUT_Ture[up].Coefficient = 1.8 ;    //上---摩擦轮速度转化系数	
  PWM_INPUT_Ture[down].Coefficient = 1.8 ;  //下---摩擦轮速度转化系数

	SHOOT_Ture.SHOOT_State.Mode_Value[0] = 0 ;       //mode_1---0
	SHOOT_Ture.SHOOT_State.Mode_Value[1] = 1700 ;    //mode_2---2050
	SHOOT_Ture.SHOOT_State.Mode_Value[2] = 2100 ;    //mode_3---2200
	SHOOT_Ture.SHOOT_State.Mode_Value[3] = 2450 ;    //mode_4---2450
	
	/*************************************************************************************/
	 pid_init(&Frictiongear_motor_PID[up] ,POSITION_PID ,20 ,0 ,0 ,300 ,1700 ,2);  //初始化上面摩擦轮电机PID结构体
	 pid_init(&Frictiongear_motor_PID[down] ,POSITION_PID ,20 ,0 ,0 ,300 ,1700 ,2);  //初始化下面摩擦轮电机PID结构体
	
	 SHOOT_Ture.PWM_Target_Value[down] = 0 ;   //初始化目标值
	 SHOOT_Ture.PWM_Target_Value[up] = 0 ;     
	
	 pid_init(&Ammunition_Booster_PID ,POSITION_PID , 65, 0, 0, 300, 30000 ,0 ); 	//初始化拨弹电机PID结构体
	
	 SHOOT_Ture.Ammunition_Booster_voltage = 0;
	
	 PWM_INPUT_Ture[up].re_speed = SHOOT_Ture.PWM_Target_Value[up] ;        //上边摩擦轮目标转速
	 PWM_INPUT_Ture[down].re_speed = SHOOT_Ture.PWM_Target_Value[down] ;    //下边摩擦轮目标转速
		
	 // SHOOT_Ture.benchmark_angle = SHOOT_Ture.benchmark_speed * SHOOT_Ture.benchmark_time	;	
   //	SHOOT_Ture.target_angle =  Ammunition_Booster_info.rotor_speed * SHOOT_Ture.run_time ;
	 SHOOT_Ture.benchmark_speed = 70 ;           //拨弹电机转动基准转速，需测量（已测量）---- 基准状态下的拨弹轮转速	 °/s																		
	 SHOOT_Ture.benchmark_angle = 10/*角度*/ ;     //拨弹电机转动基准角度，需测量（已测量）---- 减速前转动一圈对应减速后对应转动角度 °
   SHOOT_Ture.benchmark_time  = 0.14f	;          //拨弹电机转动基准时间，需测量（已测量）---- 减速前转动一圈所需要的时间 s
	 SHOOT_Ture.target_angle = 0 ;                 //单发或多连发需要减速后的转动角度（不同发射模式设置）0：关闭；51.4 ：单发；514.3 ：速射
	 SHOOT_Ture.target_speed = 0 ;                 // 控制射速（0：关闭；1：单发；2：速射；3：连发）
	 SHOOT_Ture.Mode = 0;														//（不同发射模式设置,0:关闭；1:3米内目标；2:3~5米目标；3:5米外目标）
/**************************************************************************************/	
	
	for(;;)
  {
    if(/*remote_control.switch_left == 1 &&*/ remote_control.switch_right == 1)
   {
	  osDelay(1);
		 
		 switch(SHOOT_Ture.target_speed)
		 {
			 case 0 :
				 SHOOT_Ture.target_angle = 0;
				break;
			 case 1 :
				 SHOOT_Ture.target_angle = 51.4;
				break;
			 case 2 :
				 SHOOT_Ture.target_angle = 514.3;
				break;
			 case 3 :
				 SHOOT_Ture.target_angle = 3;
				break;
			 
		 }
		 
		 
		 SHOOT_Ture.target_time = (SHOOT_Ture.target_angle/SHOOT_Ture.benchmark_angle) * SHOOT_Ture.benchmark_time ; 
		 
		 switch(SHOOT_Ture.Mode)   // 设置射击距离
		 {
			 case 0 :  // 关闭
				 SHOOT_Ture.PWM_Target_Value[down] = SHOOT_Ture.SHOOT_State.Mode_Value[0] + 50 ;   
				 SHOOT_Ture.PWM_Target_Value[up] = SHOOT_Ture.SHOOT_State.Mode_Value[0] + 50  ;  // 上摩擦轮稍快，
			 break;
			 case 1 :  // 3m内
				 SHOOT_Ture.PWM_Target_Value[down] = SHOOT_Ture.SHOOT_State.Mode_Value[1]  ;
				 SHOOT_Ture.PWM_Target_Value[up] = SHOOT_Ture.SHOOT_State.Mode_Value[1] + 50 ;  // 上摩擦轮稍快，
			 break;
			 case 2 :  // 3-5m
				 SHOOT_Ture.PWM_Target_Value[down] = SHOOT_Ture.SHOOT_State.Mode_Value[2]  ;
				 SHOOT_Ture.PWM_Target_Value[up] = SHOOT_Ture.SHOOT_State.Mode_Value[2] + 50 ;  // 上摩擦轮稍快，
			 break;
			 case 3 :  // 5m外
				 SHOOT_Ture.PWM_Target_Value[down] = SHOOT_Ture.SHOOT_State.Mode_Value[3] ;
				 SHOOT_Ture.PWM_Target_Value[up] = SHOOT_Ture.SHOOT_State.Mode_Value[3] + 50 ;  // 上摩擦轮稍快，
			 break;
		 }
    
		 
		 motor_info[5].set_voltage = pid_calc(&Ammunition_Booster_PID ,
		                                       1750    // 拨弹轮的标准速度
																					 ,motor_info[5].rotor_speed
																					 );
		 set_motor_voltage(0 ,motor_info[4].set_voltage 
												 ,motor_info[5].set_voltage
												 ,0
												 ,0
												);
	 
		SHOOT_Ture.PWM_Value[up] = pid_calc(&Frictiongear_motor_PID[0]       //上边摩擦轮计算
																						,SHOOT_Ture.PWM_Target_Value[up]
																						,PWM_INPUT_Ture[0].frequency*1.7 );   // 传感器测得的实际转速
	
    SHOOT_Ture.PWM_Value[down] = pid_calc(&Frictiongear_motor_PID[down]     //下边摩擦轮计算
																						,SHOOT_Ture.PWM_Target_Value[down]
																						,PWM_INPUT_Ture[1].frequency*1.7 );   // 传感器测得的实际转速
																						
		set_motor_voltage(0 ,motor_info[4].set_voltage 
											  ,motor_info[5].set_voltage
												,0
												,0
										  );
		if(SHOOT_Ture.target_angle != 3)
		{
			SHOOT_Ture.PreviousWakeTime = osKernelSysTick() ;
			osDelayUntil(&SHOOT_Ture.PreviousWakeTime ,SHOOT_Ture.target_time * 1000);  // 使拨弹轮转动目标角度的一个延时，s -> ms
			SHOOT_Ture.target_time = 0 ;    //单次发射完后停止发射
		}
		
		
		
    HAL_GPIO_WritePin( GPIOG , LED7_Pin, GPIO_PIN_SET);
  }
	 else
	 {
		 motor_info[5].set_voltage = 0 ;
		 set_motor_voltage(0 ,motor_info[4].set_voltage 
												 ,motor_info[5].set_voltage
												 ,0
												 ,0
												);
		 HAL_GPIO_WritePin( GPIOG , LED7_Pin, GPIO_PIN_RESET);
	 }

	osDelay(5);
  }
	 
 
		
  }
	
	




























