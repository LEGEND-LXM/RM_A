#include "Init.h"

pid_struct_t pitch_Angle_pid;
pid_struct_t yaw_Angle_pid;
pid_struct_t pitch_speed_pid;
pid_struct_t yaw_speed_pid;
pid_struct_t BODAN_speed_pid;
pid_struct_t FRIC_speed_pid;
int i;
 void  User_Init(void)
 {
	  can_user_init(&hcan1);  
	 
    pid_init(&pitch_Angle_pid,0.4,  0, 0.2,   0,   100); 
	  pid_init(&pitch_speed_pid, 60,  0,   2, 300, 30000); 
	  pid_init(&yaw_Angle_pid  ,0.8,  0,   0,   0,   100); 
	  pid_init(&yaw_speed_pid  , 40,  0,   0, 300, 30000);
	  pid_init(&BODAN_speed_pid,  2,  0,   0, 300, 30000);
	  pid_init(&FRIC_speed_pid,   2,  0,   0, 300, 30000);

	 
	 	Butterworth_Parameter_Init();
	  MPU9250_INIT();
	  HAL_UART_Receive_IT_IDLE(&huart3,UART_Buffer,100);   //启动串口接收,DBUS接收开启
	 
	  fric_PWM_configuration();
	  ramp_init(&fric_pwm, 0.001, 1200, 900);
 }
 
 
 
 osThreadId holder_TaskHandle;
 osThreadId shoot_TaskHandle; 
 osThreadId test_TaskHandle;
 void Task_Init(void)
 {
	 	 osThreadDef(holder_Task, holder_Task, osPriorityAboveNormal, 0,200);
   holder_TaskHandle = osThreadCreate(osThread(holder_Task), NULL); 
	   osThreadDef(shoot_Task, shoot_Task , osPriorityAboveNormal, 0, 128);
   shoot_TaskHandle  = osThreadCreate(osThread(shoot_Task), NULL);	 
	 	 osThreadDef(test_Task, test_Task , osPriorityNormal, 0, 128);
   test_TaskHandle   = osThreadCreate(osThread(test_Task), NULL);
 } 
