#include "Gimbal_Task1.h"

#include "bsp_imu.h"

#include "arm_math.h"
#include "user_lib.h"
#include "oled.h"

#include "usbd_cdc_if.h" //视觉信息

#define gimbal_total_pid_clear(gimbal_clear)                                                   \
    {                                                                                          \
        pid_clear(&(gimbal_clear)->gimbal_yaw_motor.gimbal_motor_absolute_angle_pid);   \
        pid_clear(&(gimbal_clear)->gimbal_yaw_motor.gimbal_motor_relative_angle_pid);   \
        pid_clear(&(gimbal_clear)->gimbal_yaw_motor.gimbal_motor_gyro_pid);                    \
                                                                                               \
        pid_clear(&(gimbal_clear)->gimbal_pitch_motor.gimbal_motor_absolute_angle_pid); \
        pid_clear(&(gimbal_clear)->gimbal_pitch_motor.gimbal_motor_relative_angle_pid); \
        pid_clear(&(gimbal_clear)->gimbal_pitch_motor.gimbal_motor_gyro_pid);                  \
    }
uint16_t gimbal_mode;
//云台的所有数据
static Gimbal_Control_t gimbal_control;
//发送的电机变量
static int16_t Yaw_Set_Current = 0, Pitch_Set_Current = 0;

//云台初始化
static void GIMBAL_Init(Gimbal_Control_t *gimbal_init);

//云台相对位置设置
static void GIMBAL_Cali_Set(Gimbal_Control_t *gimbal_cali_set);

//云台数据更新
static void GIMBAL_Feedback_Update(Gimbal_Control_t *gimbal_feedback_update);
		
//遥控数据更新
static void GIMBAL_RC_Set_Control(Gimbal_Control_t *gimbal_rc_set_control);

//电机控制	
static void GIMBAL_Set_Motor(Gimbal_Control_t *gimbal_set_motor);	

//控制YAW和PITCH电机
static void GIMBAL_YAW_MOTOR_CONTROL(Gimbal_Control_t *gimbal_yaw_motor_control);
static void GIMBAL_PITCH_MOTOR_CONTROL(Gimbal_Control_t *gimbal_pitch_motor_control);

static void GIMBAL_PAN_MOTOR_CONTROL(Gimbal_Control_t *gimbal_pan_motor_control);

//云台限位
static void gimbal_motor_limited(Gimbal_Control_t *gimbal_motor_limited);

//吊射
float BulletModel(float x, float v, float angle);
float GetPitch(float x, float y, float v);

void gimbal_motor_limited(Gimbal_Control_t *gimbal_motor_limited)
{
	if (gimbal_motor_limited == NULL)	
		{
        return;
    }
	//yaw最大限位	
	if(gimbal_motor_limited->gimbal_yaw_motor.absolute_angle_set > gimbal_motor_limited->gimbal_yaw_motor.max_relative_angle)
		{
			gimbal_motor_limited->gimbal_yaw_motor.absolute_angle_set = gimbal_motor_limited->gimbal_yaw_motor.max_relative_angle;
		}
	//yaw最小限位
	if(gimbal_motor_limited->gimbal_yaw_motor.absolute_angle_set < gimbal_motor_limited->gimbal_yaw_motor.min_relative_angle)
		{
			gimbal_motor_limited->gimbal_yaw_motor.absolute_angle_set = gimbal_motor_limited->gimbal_yaw_motor.min_relative_angle;
		}
	//pitch最大限位
	if(gimbal_motor_limited->gimbal_pitch_motor.absolute_angle_set < gimbal_motor_limited->gimbal_pitch_motor.min_relative_angle)
		{
			gimbal_motor_limited->gimbal_pitch_motor.absolute_angle_set = gimbal_motor_limited->gimbal_pitch_motor.min_relative_angle;
		}
	//pitch最小限位
	if(gimbal_motor_limited->gimbal_pitch_motor.absolute_angle_set < gimbal_motor_limited->gimbal_pitch_motor.min_relative_angle)
		{
			gimbal_motor_limited->gimbal_pitch_motor.absolute_angle_set = gimbal_motor_limited->gimbal_pitch_motor.min_relative_angle;
		}
}	
/**********************************************************************************************************
*函 数 名: BulletModel
*功能说明: 在进行弹道补偿时，根据此时云台相对于地面的角度,子弹速度，
					 和云台距目标的水平距离，计算出子弹的下降高度
*形    参: x:水平距离，v:子弹速度，angle：云台相对于地面的弧度
*返 回 值: y:子弹下降高度
**********************************************************************************************************/
//air friction is considered
float BulletModel(float x, float v, float angle)
{ //x:m,v:m/s,angle:rad
  float t,y;
  t=(float)((exp(init_k_*x)-1)/(init_k_*v*cos(angle)));
  y=(v*sin(angle)*t-GRAVITY*t*t/2);
	//y=x*sin(angle)*t-t*t*G/2.0f;
  return y;
}
/**********************************************************************************************************
*函 数 名: GetPitch
*功能说明: 根据此时云台的仰射角度计算的下降高度
*形    参: x:水平距离，y:目标位置相对于枪管的高度，v:子弹速度
*返 回 值: a:云台上仰角度
**********************************************************************************************************/
//x:distance , y: height
float GetPitch(float x, float y, float v) 
{
	float y_temp,y_actual,dy;
	float a;
	y_temp = y;
  // by iteration
  for (int i=0;i<20;i++) 
	{
    a = (float)atan2(y_temp,x);
    y_actual = BulletModel(x,v,a);
    dy = y-y_actual;
    y_temp=y_temp+dy;
    if(fabsf(dy)<0.001f) 
		{
			break;
    }
  }
  return a* Motor_Rad_to_Angle;
}

void Gimbal_Task(void const * argument)
{
	osDelay(GIMBAL_TASK_INIT_TIME);
	GIMBAL_Init(&gimbal_control);
	for(;;)
	{
		GIMBAL_Feedback_Update(&gimbal_control);
		GIMBAL_RC_Set_Control(&gimbal_control);
		GIMBAL_PAN_MOTOR_CONTROL(&gimbal_control);
		GIMBAL_Set_Motor(&gimbal_control);
		HAL_GPIO_TogglePin(GPIOG, LED3_Pin);
		osDelay(GIMBAL_CONTROL_TIME);
		
//		wave_form_data[0] = TRIGGER_Set_Current;
//		wave_form_data[1] = TRIGGER_Set_Current;
//		wave_form_data[2] = TRIGGER_Set_Current;
//		shanwai_send_wave_form();	
	}
}

/**********************************************************************************************************
*函 数 名:get_yaw_motor_point get_pitch_motor_point
*功能说明:把云台的位置信息告诉底盘的指针函数
*形    参:get_yaw_motor_point get_pitch_motor_point
*返 回 值:NULL
*作者:		RM
**********************************************************************************************************/
const Gimbal_Motor_t *get_yaw_motor_point(void)
{
    return &gimbal_control.gimbal_yaw_motor;
}
const Gimbal_Motor_t *get_pitch_motor_point(void)
{
    return &gimbal_control.gimbal_pitch_motor;
}

/**********************************************************************************************************
*函 数 名:fp32 motor_ecd_to_angle_change(uint16_t rotor_angle, uint16_t offset_ecd
*功能说明:计算相对角度
*形    参:rotor_angle offset_ecd
*返 回 值:NULL
*作者:		RM
**********************************************************************************************************/
static fp32 motor_ecd_to_angle_change(uint16_t rotor_angle, uint16_t offset_ecd)
{
    int32_t relative_ecd = rotor_angle - offset_ecd;
    if (relative_ecd > Half_ecd_range)
    {
        relative_ecd -= ecd_range;
    }
    else if (relative_ecd < -Half_ecd_range)
    {
        relative_ecd += ecd_range;
    }

    return relative_ecd * Motor_Ecd_to_Rad;
}

/**********************************************************************************************************
*函 数 名:GIMBAL_RC_Control(Gimbal_Control_t *gimbal_rc_control)
*功能说明:遥控器行程量和模式设置以及限幅
*形    参:gimbal_rc_control
*返 回 值:NULL
*作者:		杨文钊
**********************************************************************************************************/
//遥控数据更新
static void GIMBAL_RC_Set_Control(Gimbal_Control_t *gimbal_rc_set_control)
{
		if (gimbal_rc_set_control == NULL)
    {
        return;
    }
	  //遥控器的数据处理死区
//		static int16_t yaw_channel,pitch_channel;
    rc_deadline_limit(gimbal_rc_set_control->gimbal_rc_ctrl->ch3 , gimbal_rc_set_control->gimbal_value_limit.yaw_channel, RC_Dead_Band);
    rc_deadline_limit(gimbal_rc_set_control->gimbal_rc_ctrl->ch4, gimbal_rc_set_control->gimbal_value_limit.pitch_channel, RC_Dead_Band);
		//遥控器模式设置
		if(switch_is_down(gimbal_rc_set_control->gimbal_rc_ctrl->switch_left))
		{
			gimbal_rc_set_control->Gimbal_Motor_mode = GIMBAL_ZERO_FORCE;
			gimbal_mode = GIMBAL_ZERO_FORCE;
		}
		else if(switch_is_mid(gimbal_rc_set_control->gimbal_rc_ctrl->switch_left))
		{
			gimbal_rc_set_control->Gimbal_Motor_mode = GIMBAL_MIXED_AB_RE_ANGLE;
			gimbal_mode = GIMBAL_MIXED_AB_RE_ANGLE;
		}
		
		
		//防止再次开机时遥控的数据使机器人发疯
		if(gimbal_rc_set_control->Gimbal_Motor_mode == GIMBAL_ZERO_FORCE)
		{
			gimbal_rc_set_control->gimbal_pitch_motor.rc_effective_stroke = 0;
			gimbal_rc_set_control->gimbal_yaw_motor.rc_effective_stroke = 0;
		}
		else if(gimbal_rc_set_control->Gimbal_Motor_mode == GIMBAL_MIXED_AB_RE_ANGLE)
		{
			gimbal_rc_set_control->gimbal_pitch_motor.rc_effective_stroke = gimbal_rc_set_control->gimbal_value_limit.pitch_channel*RC_TRAVEL_RAD_FACTOR;
			gimbal_rc_set_control->gimbal_yaw_motor.rc_effective_stroke = gimbal_rc_set_control->gimbal_value_limit.yaw_channel*RC_TRAVEL_RAD_FACTOR*NEGATION_COEFFICIENT;
		}

}

/**********************************************************************************************************
*函 数 名:GIMBAL_Feedback_Update(Gimbal_Control_t *gimbal_feedback_update)
*功能说明:更新云台参数
*形    参:gimbal_feedback_update
*返 回 值:NULL
*作者:		杨文钊
**********************************************************************************************************/
static void GIMBAL_Feedback_Update(Gimbal_Control_t *gimbal_feedback_update)
{
		if (gimbal_feedback_update == NULL)
		{
				return;
		}
		//更新陀螺仪的数据
		MPU6500_GET_DATA();														 
		gimbal_feedback_update->gimbal_pitch_motor.absolute_angle = *(gimbal_feedback_update->gimbal_INT_angle_point + INS_PITCH_ADDRESS_OFFSET);
    gimbal_feedback_update->gimbal_pitch_motor.relative_angle = motor_ecd_to_angle_change(gimbal_feedback_update->gimbal_pitch_motor.gimbal_motor_measure->rotor_angle,
                                                                                          gimbal_feedback_update->gimbal_pitch_motor.offset_ecd);
//    gimbal_feedback_update->gimbal_pitch_motor.motor_gyro = *(gimbal_feedback_update->gimbal_INT_gyro_point + 2);//原为Y
		
    gimbal_feedback_update->gimbal_yaw_motor.absolute_angle = *(gimbal_feedback_update->gimbal_INT_angle_point + INS_YAW_ADDRESS_OFFSET);
    gimbal_feedback_update->gimbal_yaw_motor.relative_angle = motor_ecd_to_angle_change(gimbal_feedback_update->gimbal_yaw_motor.gimbal_motor_measure->rotor_angle,
                                                                                        gimbal_feedback_update->gimbal_yaw_motor.offset_ecd);
//    gimbal_feedback_update->gimbal_yaw_motor.motor_gyro = arm_cos_f32(gimbal_feedback_update->gimbal_pitch_motor.relative_angle) * 
//														(*(gimbal_feedback_update->gimbal_INT_gyro_point + 1))
//                                                        - arm_sin_f32(gimbal_feedback_update->gimbal_pitch_motor.relative_angle) * 
//														(*(gimbal_feedback_update->gimbal_INT_gyro_point + 0));//原为X
		
	/***********************************************START***********************************************/
	/*功能代码名称：视觉信息更新*/
	if(( Visual_Ture.RInit_data[0] == 0x1a) && (Visual_Ture.RInit_data[7] == 0x7a ))
	{
		Visual_Ture.RDecode_data[0] = Visual_Ture.RInit_data[1] | Visual_Ture.RInit_data[2] << 8 ; //x
		Visual_Ture.RDecode_data[1] = Visual_Ture.RInit_data[3] | Visual_Ture.RInit_data[4] << 8 ; //y
		Visual_Ture.RDecode_data[2] = Visual_Ture.RInit_data[5] | Visual_Ture.RInit_data[6] << 8 ;
		Visual_Ture.Coordinates[0] = Visual_Ture.RDecode_data[0] ;
		Visual_Ture.Coordinates[1] = Visual_Ture.RDecode_data[1] ;
	}
	CDC_Transmit_FS((uint8_t*)Visual_Ture.RDecode_data ,3 );
	/***********************************************END***************************************************/
}
/**********************************************************************************************************
*函 数 名:GIMBAL_Cali_set(Gimbal_Control_t *gimbal_cali_set)
*功能说明:云台相对位置设置及更新值 除offset_ecd为机械角度值 其它单位为弧度
*形    参:gimbal_cali_set
*返 回 值:NULL
*作者:		杨文钊
**********************************************************************************************************/
static void GIMBAL_Cali_Set(Gimbal_Control_t *gimbal_cali_set)
{
		if (gimbal_cali_set == NULL)
		{
				return;
		}
		//云台机械中值
		gimbal_cali_set->gimbal_yaw_motor.offset_ecd 						= YAW_ENCODE_OFFEST;
		gimbal_cali_set->gimbal_pitch_motor.offset_ecd 					= PITCH_ENCODE_OFFEST;
		//云台限位值 单位为弧度
		gimbal_cali_set->gimbal_yaw_motor.max_relative_angle 		= rad_format(YAW_MAX_ENCODE_ANGLE);
		gimbal_cali_set->gimbal_yaw_motor.min_relative_angle 		= rad_format(YAW_MIN_ENCODE_ANGLE);
		gimbal_cali_set->gimbal_pitch_motor.max_relative_angle 	= rad_format(PITCH_MAX_ENCODE_ANGLE);
		gimbal_cali_set->gimbal_pitch_motor.min_relative_angle 	= rad_format(PITCH_MIN_ENCODE_ANGLE); 
}

/**********************************************************************************************************
*函 数 名:GIMBAL_Init(Gimbal_Control_t *gimbal_init)
*功能说明:云台参数初始化
*形    参:gimbal_init
*返 回 值:NULL	
*作者:		杨文钊
**********************************************************************************************************/
static void GIMBAL_Init(Gimbal_Control_t *gimbal_init)
{
		if (gimbal_init == NULL)
		{
				return;
		}
		//电机数据指针获取
    gimbal_init->gimbal_yaw_motor.gimbal_motor_measure = get_Yaw_Gimbal_Motor_Measure_Point();
    gimbal_init->gimbal_pitch_motor.gimbal_motor_measure = get_Pitch_Gimbal_Motor_Measure_Point();

		//陀螺仪数据指针获取
    gimbal_init->gimbal_INT_angle_point = get_INS_angle_point();
    gimbal_init->gimbal_INT_gyro_point = get_MPU6500_Gyro_Data_Point();
	
		//遥控器数据指针获取
    gimbal_init->gimbal_rc_ctrl = get_remote_control_point();
    
		//初始化pitch电机pid
		pid_init(&gimbal_init->gimbal_yaw_motor.gimbal_motor_absolute_angle_pid,
										YAW_GYRO_ABSOLUTE_PID_KP, 
										YAW_GYRO_ABSOLUTE_PID_KI, 
										YAW_GYRO_ABSOLUTE_PID_KD,
										YAW_GYRO_ABSOLUTE_PID_MAX_IOUT, 
										YAW_GYRO_ABSOLUTE_PID_MAX_OUT);
    pid_init(&gimbal_init->gimbal_yaw_motor.gimbal_motor_relative_angle_pid,
										YAW_ENCODE_RELATIVE_PID_KP, 
										YAW_ENCODE_RELATIVE_PID_KI, 
										YAW_ENCODE_RELATIVE_PID_KD,
										YAW_ENCODE_RELATIVE_PID_MAX_IOUT, 
										YAW_ENCODE_RELATIVE_PID_MAX_OUT);
		pid_init(&gimbal_init->gimbal_yaw_motor.gimbal_motor_gyro_pid, 
										YAW_SPEED_PID_KP,
										YAW_SPEED_PID_KI,
										YAW_SPEED_PID_KD,
										YAW_SPEED_PID_MAX_OUT,
										YAW_SPEED_PID_MAX_IOUT);
				
    //初始化pitch电机pid
    pid_init(&gimbal_init->gimbal_pitch_motor.gimbal_motor_absolute_angle_pid,
										PITCH_GYRO_ABSOLUTE_PID_KP, 
										PITCH_GYRO_ABSOLUTE_PID_KI, 
										PITCH_GYRO_ABSOLUTE_PID_KD,
										PITCH_GYRO_ABSOLUTE_PID_MAX_IOUT, 
										PITCH_GYRO_ABSOLUTE_PID_MAX_OUT);
    pid_init(&gimbal_init->gimbal_pitch_motor.gimbal_motor_relative_angle_pid, 
										PITCH_ENCODE_RELATIVE_PID_KP, 
										PITCH_ENCODE_RELATIVE_PID_KI, 
										PITCH_ENCODE_RELATIVE_PID_KD,
										PITCH_ENCODE_RELATIVE_PID_MAX_IOUT, 
										PITCH_ENCODE_RELATIVE_PID_MAX_OUT);
    pid_init(&gimbal_init->gimbal_pitch_motor.gimbal_motor_gyro_pid, 
										PITCH_SPEED_PID_KP,
										PITCH_SPEED_PID_KI,
										PITCH_SPEED_PID_KD,
										PITCH_SPEED_PID_MAX_IOUT,
										PITCH_SPEED_PID_MAX_OUT);
		gimbal_total_pid_clear(gimbal_init);
		
		
		Visual_Ture.Coordinates[0] = 0 ;
		Visual_Ture.Coordinates[1] = 0 ;
	
    //设置云台电机的初始值
		GIMBAL_Cali_Set(gimbal_init);
		
    GIMBAL_Feedback_Update(gimbal_init);

}

/**********************************************************************************************************
*函 数 名:GIMBAL_PAN_MOTOR_CONTROL(Gimbal_Control_t *gimbal_pan_motor_control)
*功能说明:云台YAW和pitch轴电机控制，用Gimbal_Motor_mode标志位上保险
*形    参:NULL
*返 回 值:NULL
*作者:		杨文钊
**********************************************************************************************************/
static void GIMBAL_PAN_MOTOR_CONTROL(Gimbal_Control_t *gimbal_pan_motor_control)
{
		if (gimbal_pan_motor_control == NULL)
		{
				return;
		}
		if(gimbal_pan_motor_control->Gimbal_Motor_mode == GIMBAL_ZERO_FORCE)
		{
			GIMBAL_PITCH_MOTOR_CONTROL(NULL);
			GIMBAL_YAW_MOTOR_CONTROL(NULL);
		}
		else if(gimbal_pan_motor_control->Gimbal_Motor_mode == GIMBAL_MIXED_AB_RE_ANGLE)
		{
			GIMBAL_YAW_MOTOR_CONTROL(gimbal_pan_motor_control);
			GIMBAL_PITCH_MOTOR_CONTROL(gimbal_pan_motor_control);
		}
		

}
/**********************************************************************************************************
*函 数 名:GIMBAL_YAW_MOTOR_CONTROL(Gimbal_Control_t *gimbal_yaw_motor_control);
*功能说明:控制YAW轴电机
*形    参:gimbal_yaw_motor_control
*返 回 值:NULL
*作者:		杨文钊
**********************************************************************************************************/
static void GIMBAL_YAW_MOTOR_CONTROL(Gimbal_Control_t *gimbal_yaw_motor_control)
{
		if (gimbal_yaw_motor_control == NULL)
		{
				return;
		}
		static int yaw_flag_status = 0;//yaw云台静止标志维
		if(gimbal_yaw_motor_control->gimbal_rc_ctrl->ch3 == 0)
		{
			if(yaw_flag_status == 0)
			{
				gimbal_yaw_motor_control->gimbal_yaw_motor.relative_angle_set = rad_format(*(gimbal_yaw_motor_control->gimbal_INT_angle_point + INS_YAW_ADDRESS_OFFSET)*NEGATION_COEFFICIENT);
				//gimbal_yaw_motor_control->gimbal_yaw_motor.relative_angle;
				gimbal_motor_limited(gimbal_yaw_motor_control);//yaw限位
				yaw_flag_status = 1;
			}
			gimbal_yaw_motor_control->gimbal_yaw_motor.given_current = 
				pid_calc(&gimbal_yaw_motor_control->gimbal_yaw_motor.gimbal_motor_relative_angle_pid,
									gimbal_yaw_motor_control->gimbal_yaw_motor.relative_angle_set,
									gimbal_yaw_motor_control->gimbal_yaw_motor.relative_angle);
									//rad_format(*(gimbal_yaw_motor_control->gimbal_INT_angle_point + INS_YAW_ADDRESS_OFFSET)*NEGATION_COEFFICIENT));
			gimbal_yaw_motor_control->gimbal_yaw_motor.motor_gyro_set = gimbal_yaw_motor_control->gimbal_yaw_motor.given_current;
		}
		else
		{
			yaw_flag_status = 0;
			gimbal_yaw_motor_control->gimbal_yaw_motor.relative_angle_set = 0;
			gimbal_yaw_motor_control->gimbal_yaw_motor.motor_gyro_set = gimbal_yaw_motor_control->gimbal_yaw_motor.rc_effective_stroke;
		}
		
		gimbal_yaw_motor_control->gimbal_yaw_motor.given_current = 
			pid_calc(&gimbal_yaw_motor_control->gimbal_yaw_motor.gimbal_motor_gyro_pid,
								gimbal_yaw_motor_control->gimbal_yaw_motor.motor_gyro_set,
								*(gimbal_yaw_motor_control->gimbal_INT_gyro_point+INS_GYRO_Z_ADDRESS_OFFSET));//imu.wz
		
}
/**********************************************************************************************************
*函 数 名:GIMBAL_PITCH_MOTOR_CONTROL(Gimbal_Control_t *gimbal_pitch_motor_control);
*功能说明:控制PITCH轴电机
*形    参:gimbal_pitch_motor_control
*返 回 值:NULL
*作者:		杨文钊
**********************************************************************************************************/
static void GIMBAL_PITCH_MOTOR_CONTROL(Gimbal_Control_t *gimbal_pitch_motor_control)
{
		if (gimbal_pitch_motor_control == NULL)
		{
				return;
		}
		static int pit_flag_status = 0;//pit云台静止标志维
		if(gimbal_pitch_motor_control->gimbal_rc_ctrl->ch4 == 0)//如果遥控器没有输入
		{		
			if(pit_flag_status == 0)//遥控没有输入的时候要实时读取电机机械角度值
			{
				gimbal_pitch_motor_control->gimbal_pitch_motor.relative_angle_set = gimbal_pitch_motor_control->gimbal_pitch_motor.relative_angle;
				//rad_format(*(gimbal_pitch_motor_control->gimbal_INT_angle_point+INS_PITCH_ADDRESS_OFFSET));
				gimbal_motor_limited(gimbal_pitch_motor_control);//pitch限位
				pit_flag_status = 1;
			}
			gimbal_pitch_motor_control->gimbal_pitch_motor.given_current = 
				pid_calc(&gimbal_pitch_motor_control->gimbal_pitch_motor.gimbal_motor_relative_angle_pid,
									gimbal_pitch_motor_control->gimbal_pitch_motor.relative_angle_set,
									rad_format(*(gimbal_pitch_motor_control->gimbal_INT_angle_point+INS_PITCH_ADDRESS_OFFSET)));
			gimbal_pitch_motor_control->gimbal_pitch_motor.motor_gyro_set = gimbal_pitch_motor_control->gimbal_pitch_motor.given_current;
		}
		else
		{
			pit_flag_status = 0;
			gimbal_pitch_motor_control->gimbal_pitch_motor.motor_gyro_set = gimbal_pitch_motor_control->gimbal_pitch_motor.rc_effective_stroke;
		}	
		gimbal_pitch_motor_control->gimbal_pitch_motor.given_current = 
			pid_calc(&gimbal_pitch_motor_control->gimbal_pitch_motor.gimbal_motor_gyro_pid,
								gimbal_pitch_motor_control->gimbal_pitch_motor.motor_gyro_set,
								*(gimbal_pitch_motor_control->gimbal_INT_gyro_point+INS_GYRO_Y_ADDRESS_OFFSET));//imu.wx
		
}
/**********************************************************************************************************
*函 数 名:GIMBAL_Set_Motor(Gimbal_Control_t *gimbal_set_motor)
*功能说明:最终电机控制函数
*形    参:gimbal_set_motor
*返 回 值:NULL
*作者:		杨文钊
**********************************************************************************************************/

static void GIMBAL_Set_Motor(Gimbal_Control_t *gimbal_set_motor)
{
	#if PITCH_TURN
	Pitch_Set_Current 	=  -(int16_t)gimbal_set_motor->gimbal_pitch_motor.given_current;
	#else
	Pitch_Set_Current 	=  (int16_t)gimbal_set_motor->gimbal_pitch_motor.given_current;
	#endif
	
	#if YAW_TURN
	Yaw_Set_Current 	= -(int16_t)gimbal_set_motor->gimbal_yaw_motor.given_current;
	#else
	Yaw_Set_Current 	= (int16_t)gimbal_set_motor->gimbal_yaw_motor.given_current;
	#endif
	
	if(gimbal_set_motor->Gimbal_Motor_mode == GIMBAL_ZERO_FORCE)
//	if(remote_control.switch_left == 2)
	{
		set_motor_voltage_CAN1(0, 													//设置电机速度
							0, 
							0, 
							0, 
							0);
	}
	else if(gimbal_set_motor->Gimbal_Motor_mode == GIMBAL_MIXED_AB_RE_ANGLE)
//	else if(remote_control.switch_left == 3)
	{
		set_motor_voltage_CAN1(0, 													//设置电机速度
							Yaw_Set_Current, /*Yaw_Set_Current*/
							Pitch_Set_Current, /*Pitch_Set_Current*/
							0, 
							0);
	}
}
