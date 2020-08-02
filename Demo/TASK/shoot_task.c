
#include "shoot_task.h"

extern moto_info_t  Holder_motor_info[2] ;

SHOOT_Type SHOOT_Ture ;
pid_struct_t Frictiongear_motor_PID[2] ;     //Ħ����PID�ṹ��
pid_struct_t Ammunition_Booster_PID ;        //�������PID�ṹ��


void StartTask_Shoot(void const * argument) 
{
	osDelay(1) ;	
	
	PWM_INPUT_Ture[up].Coefficient = 1.8 ;    //��---Ħ�����ٶ�ת��ϵ��	
  PWM_INPUT_Ture[down].Coefficient = 1.8 ;  //��---Ħ�����ٶ�ת��ϵ��

	SHOOT_Ture.SHOOT_State.Mode_Value[0] = 0 ;       //mode_1---0
	SHOOT_Ture.SHOOT_State.Mode_Value[1] = 1700 ;    //mode_2---2050
	SHOOT_Ture.SHOOT_State.Mode_Value[2] = 2100 ;    //mode_3---2200
	SHOOT_Ture.SHOOT_State.Mode_Value[3] = 2450 ;    //mode_4---2450
	
	/*************************************************************************************/
	 pid_init(&Frictiongear_motor_PID[up] ,POSITION_PID ,20 ,0 ,0 ,300 ,1700 ,2);  //��ʼ������Ħ���ֵ��PID�ṹ��
	 pid_init(&Frictiongear_motor_PID[down] ,POSITION_PID ,20 ,0 ,0 ,300 ,1700 ,2);  //��ʼ������Ħ���ֵ��PID�ṹ��
	
	 SHOOT_Ture.PWM_Target_Value[down] = 0 ;   //��ʼ��Ŀ��ֵ
	 SHOOT_Ture.PWM_Target_Value[up] = 0 ;     
	
	 pid_init(&Ammunition_Booster_PID ,POSITION_PID , 65, 0, 0, 300, 30000 ,0 ); 	//��ʼ���������PID�ṹ��
	
	 SHOOT_Ture.Ammunition_Booster_voltage = 0;
	
	 PWM_INPUT_Ture[up].re_speed = SHOOT_Ture.PWM_Target_Value[up] ;        //�ϱ�Ħ����Ŀ��ת��
	 PWM_INPUT_Ture[down].re_speed = SHOOT_Ture.PWM_Target_Value[down] ;    //�±�Ħ����Ŀ��ת��
		
	 // SHOOT_Ture.benchmark_angle = SHOOT_Ture.benchmark_speed * SHOOT_Ture.benchmark_time	;	
   //	SHOOT_Ture.target_angle =  Ammunition_Booster_info.rotor_speed * SHOOT_Ture.run_time ;
	 SHOOT_Ture.benchmark_speed = 70 ;           //�������ת����׼ת�٣���������Ѳ�����---- ��׼״̬�µĲ�����ת��	 ��/s																		
	 SHOOT_Ture.benchmark_angle = 10/*�Ƕ�*/ ;     //�������ת����׼�Ƕȣ���������Ѳ�����---- ����ǰת��һȦ��Ӧ���ٺ��Ӧת���Ƕ� ��
   SHOOT_Ture.benchmark_time  = 0.14f	;          //�������ת����׼ʱ�䣬��������Ѳ�����---- ����ǰת��һȦ����Ҫ��ʱ�� s
	 SHOOT_Ture.target_angle = 0 ;                 //�������������Ҫ���ٺ��ת���Ƕȣ���ͬ����ģʽ���ã�0���رգ�51.4 ��������514.3 ������
	 SHOOT_Ture.target_speed = 0 ;                 // �������٣�0���رգ�1��������2�����䣻3��������
	 SHOOT_Ture.Mode = 0;														//����ͬ����ģʽ����,0:�رգ�1:3����Ŀ�ꣻ2:3~5��Ŀ�ꣻ3:5����Ŀ�꣩
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
		 
		 switch(SHOOT_Ture.Mode)   // �����������
		 {
			 case 0 :  // �ر�
				 SHOOT_Ture.PWM_Target_Value[down] = SHOOT_Ture.SHOOT_State.Mode_Value[0] + 50 ;   
				 SHOOT_Ture.PWM_Target_Value[up] = SHOOT_Ture.SHOOT_State.Mode_Value[0] + 50  ;  // ��Ħ�����Կ죬
			 break;
			 case 1 :  // 3m��
				 SHOOT_Ture.PWM_Target_Value[down] = SHOOT_Ture.SHOOT_State.Mode_Value[1]  ;
				 SHOOT_Ture.PWM_Target_Value[up] = SHOOT_Ture.SHOOT_State.Mode_Value[1] + 50 ;  // ��Ħ�����Կ죬
			 break;
			 case 2 :  // 3-5m
				 SHOOT_Ture.PWM_Target_Value[down] = SHOOT_Ture.SHOOT_State.Mode_Value[2]  ;
				 SHOOT_Ture.PWM_Target_Value[up] = SHOOT_Ture.SHOOT_State.Mode_Value[2] + 50 ;  // ��Ħ�����Կ죬
			 break;
			 case 3 :  // 5m��
				 SHOOT_Ture.PWM_Target_Value[down] = SHOOT_Ture.SHOOT_State.Mode_Value[3] ;
				 SHOOT_Ture.PWM_Target_Value[up] = SHOOT_Ture.SHOOT_State.Mode_Value[3] + 50 ;  // ��Ħ�����Կ죬
			 break;
		 }
    
		 
		 motor_info[5].set_voltage = pid_calc(&Ammunition_Booster_PID ,
		                                       1750    // �����ֵı�׼�ٶ�
																					 ,motor_info[5].rotor_speed
																					 );
		 set_motor_voltage(0 ,motor_info[4].set_voltage 
												 ,motor_info[5].set_voltage
												 ,0
												 ,0
												);
	 
		SHOOT_Ture.PWM_Value[up] = pid_calc(&Frictiongear_motor_PID[0]       //�ϱ�Ħ���ּ���
																						,SHOOT_Ture.PWM_Target_Value[up]
																						,PWM_INPUT_Ture[0].frequency*1.7 );   // ��������õ�ʵ��ת��
	
    SHOOT_Ture.PWM_Value[down] = pid_calc(&Frictiongear_motor_PID[down]     //�±�Ħ���ּ���
																						,SHOOT_Ture.PWM_Target_Value[down]
																						,PWM_INPUT_Ture[1].frequency*1.7 );   // ��������õ�ʵ��ת��
																						
		set_motor_voltage(0 ,motor_info[4].set_voltage 
											  ,motor_info[5].set_voltage
												,0
												,0
										  );
		if(SHOOT_Ture.target_angle != 3)
		{
			SHOOT_Ture.PreviousWakeTime = osKernelSysTick() ;
			osDelayUntil(&SHOOT_Ture.PreviousWakeTime ,SHOOT_Ture.target_time * 1000);  // ʹ������ת��Ŀ��Ƕȵ�һ����ʱ��s -> ms
			SHOOT_Ture.target_time = 0 ;    //���η������ֹͣ����
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
	
	




























