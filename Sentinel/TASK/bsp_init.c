#include "bsp_init.h"
#include "gimbal_task.h"
#include "bsp_headfile.h"
//#include "mpu6050.h"

uint16_t TIM_COUNT[2];
int HARDCHECK=0;
int GIMBAL_COUNT=0;
extern RC_Type remote_control;
void SELFCHECK_param_init(void)
{
		/*�Լ�;��Կ��ƽǶ�PID*/
	 PID_struct_init(
   &check_pitch,
   POSITION_PID,
    29000,
    0,
    200, 
    0, 
    0);
	
	 PID_struct_init(
   &check_yaw,
   POSITION_PID,
    29000,
    0,
    10, 
    0, 
    0);
	
	 PID_struct_init(
   &check_bodan,
   POSITION_PID,
    29000,
    0,
    15, 
    0, 
    0);
		
		
		
		
	 PID_struct_init(
   &check_pitch2,
   POSITION_PID,
    29000,
    0,
    200, 
    0, 
    0);
	
	 PID_struct_init(
   &check_yaw2,
   POSITION_PID,
    29000,
    0,
    10, 
    0, 
    0);
	
	 PID_struct_init(
   &check_bodan2,
   POSITION_PID,
    29000,
    0,
    15, 
    0, 
    0);
}

void param_init(void)
{
	/*�Ƕ�ֵPID����*/
	 PID_struct_init(
   &pid_yuntai_pitch,
   POSITION_PID,
    200,
    0,
    0.8, 
    0, 
    0);
	
	 PID_struct_init(
   &pid_yuntai_yaw,
   POSITION_PID,
    1000,
    0,
    0.1, 
    0,
    0);
	
		 PID_struct_init(
   &pid_yuntai2_pitch,
   POSITION_PID,
    200,
    0,
    0.8, 
    0, 
    0);
	
	 PID_struct_init(
   &pid_yuntai2_yaw,
   POSITION_PID,
    1000,
    0,
    0.1, 
    0,
    0);
	
	/*���ٶ�PID����*/
	 PID_struct_init(
   &pid_yuntai_pitch_speed,
   POSITION_PID,
    18000,
    6000,
    160.0f, //5.6
    0.0f, //0.1
    0.0f);//38
	 PID_struct_init(
   &pid_yuntai_yaw_speed,
   POSITION_PID,
    8000,
    4000,
    9, 
    0, 
    0);
		
	 PID_struct_init(
   &pid_yuntai2_pitch_speed,
   POSITION_PID,
    18000,
    6000,
    160.0f, //5.6
    0.0f, //0.1
    0.0f);//38
	 PID_struct_init(
   &pid_yuntai2_yaw_speed,
   POSITION_PID,
    8000,
    4000,
    9, 
    0, 
    0);
		
	/*������PID����*/
	 PID_struct_init(
   &pid_moto_bodan,
   DELTA_PID,
    8000,
    0,
    10, 
    0, 
    0);
		
	PID_struct_init(
   &pid_moto2_bodan,
   DELTA_PID,
    8000,
    0,
    10, 
    0, 
    0);

		PID_struct_init(
   &pid_moto1_move,
   POSITION_PID,
    4000,
    6000,
    5, 
    0, 
    0);
		PID_struct_init(
   &pid_moto2_move,
   POSITION_PID,
    4000,
    6000,
    5, 
    0, 
    0);
		
		PID_struct_init(
   &pid_vision_yaw,
   POSITION_PID,
    100,
    0,
    1.25f, 
    0, 
    0.01f);
		PID_struct_init(
   &pid_vision_pitch,
   POSITION_PID,
    40,
    0,
    0.85f, 
    0, 
    0.01);
		
		PID_struct_init(
   &pid_vision2_yaw,
   POSITION_PID,
    100,
    0,
    1.25f, 
    0, 
    0.01f);
		PID_struct_init(
   &pid_vision2_pitch,
   POSITION_PID,
    40,
    0,
    0.85f, 
    0, 
    0.01);
}

void system_init(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_DMA_Init();                  
  MX_CAN1_Init();//���CAN1��            
  MX_TIM1_Init();//Ħ����PWM               
	MX_TIM2_Init();//��ʱ���ж�        
  MX_TIM7_Init();//����׼��ʱ��
	MX_UART8_Init();
	ref_sys_init();//����ϵͳ��ʼ��
  MX_USART1_UART_Init();                         

  MX_USART6_UART_Init();                      



	TIM7_Delay_Init();                              
	//can1���ϵĵ�������˲�
	can_user_init(&hcan1);                               
	//ң�����������
	dbus_uart_init();                             
	HAL_UART_Receive_IT_IDLE(&huart6,UART6_Date,12);              
	
	MX_SPI5_Init();//����imu����                     
	mpu_device_init();   //�ڳ�ʼ��imu��ʱ��Ҫ�ȳ�ʼ��SPI5��GPIOF6 ��Ȼ�޷���ʼ��imu             
	init_quaternion();	//��ʼ����Ԫ����������̬����          
	 
	param_init();//��̨����pid �� �����ֲ�����ʼ��            1
	
	SELFCHECK_param_init();/*�Լ�Ƕ�PID*/
	ramp_init(& fric_pwm, 0.01,Fric_ON,Fric_OFF);
	fric_PWM_configuration();//Ħ����PWM��ʼ��
	
	laser_on();//���⿪��

	HAL_GPIO_WritePin(GPIOG, GREENLED5_Pin|GREENLED4_Pin|GREENLED3_Pin|GREENLED2_Pin 
	                     |GREENLED1_Pin, GPIO_PIN_RESET);
}
