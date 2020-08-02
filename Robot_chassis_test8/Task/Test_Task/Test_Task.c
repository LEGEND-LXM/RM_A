#include "Test_Task.h"
#include "bsp_imu.h"

#define SYSTEM_INFORMATION_CALLBACK 0 //任务运行时间信息统计显示，通过0.1来使用
#define MOTOR_TEST 1									//电机测试代码
#define MPU6500_TEST 0								//陀螺仪测试代码
#define DJI_REMOTE_TEST 0									//遥控器测试代码
#define PI 3.1415926f
//#define Pitch_RC_SENABE -0.000006f    //遥控器系数
//#define Motor_Ecd_to_Rad 0.000766990394f //      2*  PI  /8192

//任务运行返回参数所需的变量
uint8_t pcWriteBuffer[200];
uint8_t ulHighFrequencyTimerTicks;

#if shooting
/***********************************************START***********************************************/
/*功能代码名称：*/
Shooting_Control_t shooting_control1;

void Shooting_Task(void);
static void Shooting_Initial(Shooting_Control_t *shooting_init);
static void Shooting_feedback_update(Shooting_Control_t *shooting_update);
static void Shooting_set_contorl(Shooting_Control_t *shooting_run_control);
static void Shooting_control_loop(Shooting_Control_t *shooting_run_control_loop);
static void Shooting_Motor_set(Shooting_Control_t *shooting_motor_set);
/***********************************************END***************************************************/
#endif
void Test_Task(void const * argument)
{
	//	printf("In Test_Task!\n");

	osDelay(300);
	
	MPU6500_INITIAL();
	
	Shooting_Initial(&shooting_control1);
	
  for(;;)
  {
		#if SYSTEM_INFORMATION_CALLBACK
		printf("=================================================\r\n");
		printf("\r\ntask_name    \tstate\t   prior\t  stack\t   Id\r\n");
		vTaskList((char *)&pcWriteBuffer);
		printf("%s\r\n", pcWriteBuffer);

//		printf("\r\ntask_name     time_count(10us) usage_pec\r\n");
		vTaskGetRunTimeStats((char *)&pcWriteBuffer);
		printf("%s\r\n", pcWriteBuffer);
    osDelay(100);
		#endif
		
		//电机检验代码
		#if MOTOR_TEST
		
		Shooting_Task();

    osDelay(10);
		#endif
		
		#if MPU6500_TEST
		MPU6500_GET_DATA();
		
//		wave_form_data[0] = rad_format(imu.pit)*100;
//    wave_form_data[1] = rad_format(imu.yaw)*100;		//左右
//		wave_form_data[2] = imu.rol;		//前后
//		wave_form_data[3] = imu.temp;
//		
//		wave_form_data[4] = imu.wx;
//    wave_form_data[5] = imu.wy;
//		wave_form_data[6] = imu.wz;
//		
//		shanwai_send_wave_form();
    osDelay(10);
		
		#endif
		#if DJI_REMOTE_TEST 
//		wave_form_data[0] = remote_control.ch1;
//    wave_form_data[1] = remote_control.ch2;		//左右
//		wave_form_data[2] = remote_control.ch3;		//前后
//		wave_form_data[3] = remote_control.ch4;	
//		wave_form_data[4] = remote_control.switch_left;
//    wave_form_data[5] = remote_control.switch_right;
////		wave_form_data[6] = imu.pit;
//		
//		shanwai_send_wave_form();
		#endif
		
		
  }

}
void configureTimerForRunTimeStats(void)
{
	ulHighFrequencyTimerTicks = 0ul;
}

unsigned long getRunTimeCounterValue(void)
{
	return ulHighFrequencyTimerTicks;
}
#if shooting
/***********************************************START***********************************************/
/*功能代码名称：*/

void Shooting_Task(void)
{
	

	Shooting_feedback_update(&shooting_control1);
	Shooting_set_contorl(&shooting_control1);
	Shooting_control_loop(&shooting_control1);
	Shooting_Motor_set(&shooting_control1);
	
//	wave_form_data[0] = shooting_control1.shooting_up_speed;
//	wave_form_data[1] = shooting_control1.shooting_up_motor.shooting_motor_measure->rotor_angle;
//	wave_form_data[2] = shooting_control1.shooting_up_motor.shooting_motor_measure->rotor_speed;
//	
////	wave_form_data[3] = shooting_control1.shooting_down_speed;
//	wave_form_data[4] = shooting_control1.shooting_down_motor.shooting_motor_measure->rotor_angle;
//	wave_form_data[5] = shooting_control1.shooting_down_motor.shooting_motor_measure->rotor_speed;
//	
//	shanwai_send_wave_form();
}
/**********************************************************************************************************
*函 数 名:Shooting_Initial(Shooting_Control_t *shooting_init)
*功能说明:枪管初始化
*形    参:shooting_init
*返 回 值:NULL
*作者:		杨文钊
**********************************************************************************************************/
static void Shooting_Initial(Shooting_Control_t *shooting_init)
{
	if(shooting_init == NULL)	
	{
		return;
	}
	//获取遥控器指针
  shooting_init->shooting_RC = get_remote_control_point();
	
	shooting_init->shooting_up_motor.shooting_motor_measure = get_Shooting_Up_Motor_Measure_Point();
	shooting_init->shooting_down_motor.shooting_motor_measure = get_Shooting_Down_Motor_Measure_Point();
	
	const static fp32 shooting_up_order_filter[1] = {SHOOT_ACCEL_UP_NUM};
  const static fp32 shooting_down_order_filter[1] = {SHOOT_ACCEL_DOWN_NUM};
	
	pid_init(&shooting_init->shooting_speed_up_pid,
              SHOOYTINGMOTOR_UP_SPEED_PID_KP,
              SHOOYTINGMOTOR_UP_SPEED_PID_KI,
							SHOOYTINGMOTOR_UP_SPEED_PID_KD,
              SHOOYTINGMOTOR_UP_SPEED_PID_MAX_IOUT,
              SHOOYTINGMOTOR_UP_SPEED_PID_MAX_OUT);
	
	pid_init(&shooting_init->shooting_speed_down_pid,
              SHOOYTINGMOTOR_DOWN_SPEED_PID_KP,
              SHOOYTINGMOTOR_DOWN_SPEED_PID_KI,
              SHOOYTINGMOTOR_DOWN_SPEED_PID_KD,
              SHOOYTINGMOTOR_DOWN_SPEED_PID_MAX_IOUT,
              SHOOYTINGMOTOR_DOWN_SPEED_PID_MAX_OUT);
	
	 //用一阶滤波代替斜波函数生成
  first_order_filter_init(&shooting_init->shooting_cmd_slow_set_up, 0.002, shooting_up_order_filter);
  first_order_filter_init(&shooting_init->shooting_cmd_slow_set_down, 0.002, shooting_down_order_filter);
	
	shooting_init->shooting_speed_up_set = SPEED_NUM_UP_0;
	shooting_init->shooting_speed_down_set = SPEED_NUM_DOWN_0;
	//更新一下数据
  Shooting_feedback_update(shooting_init);
	
}
/**********************************************************************************************************
*函 数 名:Shooting_feedback_update(Shooting_Control_t *shooting_update)
*功能说明:更新枪口数据
*形    参:shooting_update
*返 回 值:NULL
*作者:		杨文钊
**********************************************************************************************************/
static void Shooting_feedback_update(Shooting_Control_t *shooting_update)
{
	if(shooting_update == NULL)	
	{
		return;
	}
	shooting_update->shooting_up_speed = shooting_update->shooting_up_motor.shooting_motor_measure->rotor_speed;
	shooting_update->shooting_down_speed = shooting_update->shooting_down_motor.shooting_motor_measure->rotor_speed;
	
}
/**********************************************************************************************************
*函 数 名:Shooting_set_contorl(Shooting_Control_t *shooting_run_control)
*功能说明:NULL
*形    参:shooting_run_control
*返 回 值:NULL
*作者:		杨文钊
**********************************************************************************************************/
static void Shooting_set_contorl(Shooting_Control_t *shooting_run_control)
{
	if(shooting_run_control == NULL)	
	{
		return;
	}
	if(remote_control.switch_left == 2)
	{
		shooting_run_control->shooting_speed_up_set = SPEED_NUM_UP_0;
		shooting_run_control->shooting_speed_down_set = SPEED_NUM_DOWN_0;
	}
	else if(remote_control.switch_left == 3)
	{
		shooting_run_control->shooting_speed_up_set = SPEED_NUM_UP_1;
		shooting_run_control->shooting_speed_down_set = SPEED_NUM_DOWN_1;	
	}
	else if(remote_control.switch_left == 1)
	{
		shooting_run_control->shooting_speed_up_set = SPEED_NUM_UP_2;
		shooting_run_control->shooting_speed_down_set = SPEED_NUM_DOWN_2;
	}
	
}


/**********************************************************************************************************
*函 数 名:Shooting_control_loop(Shooting_Control_t *shooting_run_control_loop);
*功能说明:NULL
*形    参:shooting_run_control_loop
*返 回 值:NULL
*作者:		杨文钊
**********************************************************************************************************/
static void Shooting_control_loop(Shooting_Control_t *shooting_run_control_loop)
{
	if(shooting_run_control_loop == NULL)	
	{
		return;
	}
	shooting_run_control_loop->shooting_up_motor.given_current = 
					(int16_t)pid_calc(&shooting_run_control_loop->shooting_speed_up_pid, 
														shooting_run_control_loop->shooting_speed_up_set, 
														shooting_run_control_loop->shooting_up_speed);
	
	shooting_run_control_loop->shooting_down_motor.given_current = 
					(int16_t)pid_calc(&shooting_run_control_loop->shooting_speed_down_pid, 
														shooting_run_control_loop->shooting_speed_down_set, 
														-shooting_run_control_loop->shooting_down_speed);
}

/**********************************************************************************************************
*函 数 名:NULL
*功能说明:NULL
*形    参:NULL
*返 回 值:NULL
*作者:		杨文钊
**********************************************************************************************************/
static void Shooting_Motor_set(Shooting_Control_t *shooting_motor_set)
{
	if(shooting_motor_set == NULL)	
	{
		return;
	}
	static int16_t UP_Set_Current = 0, DOWN_Set_Current = 0;
	
	#if UP_TURN
	UP_Set_Current 	=  -shooting_motor_set->shooting_up_motor.given_current;
	#else
	UP_Set_Current 	=  shooting_motor_set->shooting_up_motor.given_current;
	#endif
	
	#if DOWN_TURN
	DOWN_Set_Current 	= -shooting_motor_set->shooting_down_motor.given_current;
	#else
	DOWN_Set_Current 	= shooting_motor_set->shooting_down_motor.given_current;
	#endif
	
//	if(shooting_motor_set->shooting_RC->switch_right == 2)
	if(remote_control.switch_left == 2)
	{
		set_motor_voltage_CAN2(2, 													//设置电机速度
							0, 
							0, 
							0, 
							0);
		set_motor_voltage_CAN1(2, 													//设置电机速度
							0, 
							0, 
							0, 
							0);
	}
//	else if(shooting_motor_set->shooting_RC->switch_right == 3)
	else if(remote_control.switch_left == 3)
	{
		set_motor_voltage_CAN2(2, 													//设置电机速度
							0, 
							0, 
							0, 
							0);
		set_motor_voltage_CAN1(0, 													//设置电机速度
							UP_Set_Current, 
							UP_Set_Current, 
							UP_Set_Current, 
							UP_Set_Current);
	}
	
}

/***********************************************END***************************************************/
#endif

