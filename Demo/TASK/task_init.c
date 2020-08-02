#include "task_init.h"

uint8_t KeyStatus;
pid_struct_t motor_pid[7];

osThreadId Task_Task_ScheduleHandle;        //��������������йص��߳�ID
osThreadId Task_Task_ImuHandle;             //������IMU�йص��߳�ID
osThreadId Task_Task_WaveformHandle;        //�����벨�������йص��߳�ID
osThreadId Task_Task_ChassisHandle;         //��������̿����йص��߳�ID
osThreadId Task_Task_HolderHandle;          //��������̨�����йص��߳�ID
osThreadId Task_Task_ShootHandle;           //�����뷢������йص��߳�ID
osThreadId Task_Task_VisualHandle;          //�������Ӿ�ͨ���йص��߳�ID
osThreadId Task_Task_Examination;           //������������Լ��йص��߳�ID


void User_Init(void)   //�û������ʼ��
 {
	

	 
  HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_2);
	 
	__HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_1, 0); //Ħ���ֳ�ʼ��
	__HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_2, 0);
		  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
	 
	pwm_init(); 
	ramp_init(& fric_pwm1 , 0.001 ,Fric_ON ,Fric_OFF );//c
	ramp_init(& fric_pwm2 , 0.001 ,Fric_ON ,Fric_OFF );//c	
	oled_init();	                     //OLED��ʾ��ʼ��
 
	led_off();                         //ָʾ�Ƴ�ʼ��
	mpu_device_init();                 //MPU6500��ʼ��
	init_quaternion();	               //��ʼ����Ԫ��

	HAL_UART_Receive_IT_IDLE(&huart1,UART_Buffer,100);   //�������ڽ���,DBUS���տ���

	can_user_init(&hcan1);             // CAN�û���ʼ��
	 /**/
//  HAL_Delay(2000);
	 /**/

	HAL_GPIO_WritePin( GPIOG , LED1_Pin, GPIO_PIN_SET);
	 
 }

 
void Task_Init(void)                   
{
	
	osThreadDef(Task_Schedule, StartTask_Schedule, osPriorityRealtime, 0, 128);             //����������Ⱥ�������
  Task_Task_ScheduleHandle = osThreadCreate(osThread(Task_Schedule), NULL);
	
	osThreadDef(Task_Imu, StartTask_Imu, osPriorityHigh, 0, 128);                    			  //����IMU����
  Task_Task_ImuHandle = osThreadCreate(osThread(Task_Imu), NULL);
	
	osThreadDef(Task_Waveform, StartTask_Waveform, osPriorityLow, 0, 128);          				//����������ʾ����
  Task_Task_WaveformHandle = osThreadCreate(osThread(Task_Waveform), NULL);
	
	osThreadDef(Task_Chassis, StartTask_Chassis, osPriorityRealtime, 0, 128);           		//������������
  Task_Task_ChassisHandle = osThreadCreate(osThread(Task_Chassis), NULL);

	osThreadDef(Task_Holder, StartTask_Holder, osPriorityRealtime, 0, 128);            			//������̨����
  Task_Task_HolderHandle = osThreadCreate(osThread(Task_Holder), NULL);	
	
  osThreadDef(Task_Shoot, StartTask_Shoot, osPriorityNormal, 0, 128);              				//���������������
  Task_Task_ShootHandle = osThreadCreate(osThread(Task_Shoot), NULL);	
	
	osThreadDef(Task_Visual, StartTask_Visual, osPriorityHigh, 0, 128);                     //�����Ӿ�ͨ������
  Task_Task_VisualHandle = osThreadCreate(osThread(Task_Visual), NULL);	
	
	osThreadDef(Task_Examination, StartTask_Examination, osPriorityHigh, 0, 128);           //�����Լ�ͨ������
  Task_Task_Examination = osThreadCreate(osThread(Task_Examination), NULL);	
	
	HAL_GPIO_WritePin( GPIOG , LED2_Pin, GPIO_PIN_SET);
}






