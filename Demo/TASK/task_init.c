#include "task_init.h"

uint8_t KeyStatus;
pid_struct_t motor_pid[7];

osThreadId Task_Task_ScheduleHandle;        //定义与任务调用有关的线程ID
osThreadId Task_Task_ImuHandle;             //定义与IMU有关的线程ID
osThreadId Task_Task_WaveformHandle;        //定义与波形助手有关的线程ID
osThreadId Task_Task_ChassisHandle;         //定义与底盘控制有关的线程ID
osThreadId Task_Task_HolderHandle;          //定义与云台控制有关的线程ID
osThreadId Task_Task_ShootHandle;           //定义与发射机构有关的线程ID
osThreadId Task_Task_VisualHandle;          //定义与视觉通信有关的线程ID
osThreadId Task_Task_Examination;           //定义与机器人自检有关的线程ID


void User_Init(void)   //用户程序初始化
 {
	

	 
  HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_2);
	 
	__HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_1, 0); //摩擦轮初始化
	__HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_2, 0);
		  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
	 
	pwm_init(); 
	ramp_init(& fric_pwm1 , 0.001 ,Fric_ON ,Fric_OFF );//c
	ramp_init(& fric_pwm2 , 0.001 ,Fric_ON ,Fric_OFF );//c	
	oled_init();	                     //OLED显示初始化
 
	led_off();                         //指示灯初始化
	mpu_device_init();                 //MPU6500初始化
	init_quaternion();	               //初始化四元数

	HAL_UART_Receive_IT_IDLE(&huart1,UART_Buffer,100);   //启动串口接收,DBUS接收开启

	can_user_init(&hcan1);             // CAN用户初始化
	 /**/
//  HAL_Delay(2000);
	 /**/

	HAL_GPIO_WritePin( GPIOG , LED1_Pin, GPIO_PIN_SET);
	 
 }

 
void Task_Init(void)                   
{
	
	osThreadDef(Task_Schedule, StartTask_Schedule, osPriorityRealtime, 0, 128);             //创建任务调度函数任务
  Task_Task_ScheduleHandle = osThreadCreate(osThread(Task_Schedule), NULL);
	
	osThreadDef(Task_Imu, StartTask_Imu, osPriorityHigh, 0, 128);                    			  //创建IMU任务
  Task_Task_ImuHandle = osThreadCreate(osThread(Task_Imu), NULL);
	
	osThreadDef(Task_Waveform, StartTask_Waveform, osPriorityLow, 0, 128);          				//创建波形显示任务
  Task_Task_WaveformHandle = osThreadCreate(osThread(Task_Waveform), NULL);
	
	osThreadDef(Task_Chassis, StartTask_Chassis, osPriorityRealtime, 0, 128);           		//创建底盘任务
  Task_Task_ChassisHandle = osThreadCreate(osThread(Task_Chassis), NULL);

	osThreadDef(Task_Holder, StartTask_Holder, osPriorityRealtime, 0, 128);            			//创建云台任务
  Task_Task_HolderHandle = osThreadCreate(osThread(Task_Holder), NULL);	
	
  osThreadDef(Task_Shoot, StartTask_Shoot, osPriorityNormal, 0, 128);              				//创建发射机构任务
  Task_Task_ShootHandle = osThreadCreate(osThread(Task_Shoot), NULL);	
	
	osThreadDef(Task_Visual, StartTask_Visual, osPriorityHigh, 0, 128);                     //创建视觉通信任务
  Task_Task_VisualHandle = osThreadCreate(osThread(Task_Visual), NULL);	
	
	osThreadDef(Task_Examination, StartTask_Examination, osPriorityHigh, 0, 128);           //创建自检通信任务
  Task_Task_Examination = osThreadCreate(osThread(Task_Examination), NULL);	
	
	HAL_GPIO_WritePin( GPIOG , LED2_Pin, GPIO_PIN_SET);
}






