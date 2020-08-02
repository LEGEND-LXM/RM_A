#include "Gimbal_Task1.h"

#include "bsp_imu.h"

#include "arm_math.h"
#include "user_lib.h"
#include "oled.h"

#include "usbd_cdc_if.h" //�Ӿ���Ϣ

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
//��̨����������
static Gimbal_Control_t gimbal_control;
//���͵ĵ������
static int16_t Yaw_Set_Current = 0, Pitch_Set_Current = 0;

//��̨��ʼ��
static void GIMBAL_Init(Gimbal_Control_t *gimbal_init);

//��̨���λ������
static void GIMBAL_Cali_Set(Gimbal_Control_t *gimbal_cali_set);

//��̨���ݸ���
static void GIMBAL_Feedback_Update(Gimbal_Control_t *gimbal_feedback_update);
		
//ң�����ݸ���
static void GIMBAL_RC_Set_Control(Gimbal_Control_t *gimbal_rc_set_control);

//�������	
static void GIMBAL_Set_Motor(Gimbal_Control_t *gimbal_set_motor);	

//����YAW��PITCH���
static void GIMBAL_YAW_MOTOR_CONTROL(Gimbal_Control_t *gimbal_yaw_motor_control);
static void GIMBAL_PITCH_MOTOR_CONTROL(Gimbal_Control_t *gimbal_pitch_motor_control);

static void GIMBAL_PAN_MOTOR_CONTROL(Gimbal_Control_t *gimbal_pan_motor_control);

//��̨��λ
static void gimbal_motor_limited(Gimbal_Control_t *gimbal_motor_limited);

//����
float BulletModel(float x, float v, float angle);
float GetPitch(float x, float y, float v);

void gimbal_motor_limited(Gimbal_Control_t *gimbal_motor_limited)
{
	if (gimbal_motor_limited == NULL)	
		{
        return;
    }
	//yaw�����λ	
	if(gimbal_motor_limited->gimbal_yaw_motor.absolute_angle_set > gimbal_motor_limited->gimbal_yaw_motor.max_relative_angle)
		{
			gimbal_motor_limited->gimbal_yaw_motor.absolute_angle_set = gimbal_motor_limited->gimbal_yaw_motor.max_relative_angle;
		}
	//yaw��С��λ
	if(gimbal_motor_limited->gimbal_yaw_motor.absolute_angle_set < gimbal_motor_limited->gimbal_yaw_motor.min_relative_angle)
		{
			gimbal_motor_limited->gimbal_yaw_motor.absolute_angle_set = gimbal_motor_limited->gimbal_yaw_motor.min_relative_angle;
		}
	//pitch�����λ
	if(gimbal_motor_limited->gimbal_pitch_motor.absolute_angle_set < gimbal_motor_limited->gimbal_pitch_motor.min_relative_angle)
		{
			gimbal_motor_limited->gimbal_pitch_motor.absolute_angle_set = gimbal_motor_limited->gimbal_pitch_motor.min_relative_angle;
		}
	//pitch��С��λ
	if(gimbal_motor_limited->gimbal_pitch_motor.absolute_angle_set < gimbal_motor_limited->gimbal_pitch_motor.min_relative_angle)
		{
			gimbal_motor_limited->gimbal_pitch_motor.absolute_angle_set = gimbal_motor_limited->gimbal_pitch_motor.min_relative_angle;
		}
}	
/**********************************************************************************************************
*�� �� ��: BulletModel
*����˵��: �ڽ��е�������ʱ�����ݴ�ʱ��̨����ڵ���ĽǶ�,�ӵ��ٶȣ�
					 ����̨��Ŀ���ˮƽ���룬������ӵ����½��߶�
*��    ��: x:ˮƽ���룬v:�ӵ��ٶȣ�angle����̨����ڵ���Ļ���
*�� �� ֵ: y:�ӵ��½��߶�
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
*�� �� ��: GetPitch
*����˵��: ���ݴ�ʱ��̨������Ƕȼ�����½��߶�
*��    ��: x:ˮƽ���룬y:Ŀ��λ�������ǹ�ܵĸ߶ȣ�v:�ӵ��ٶ�
*�� �� ֵ: a:��̨�����Ƕ�
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
*�� �� ��:get_yaw_motor_point get_pitch_motor_point
*����˵��:����̨��λ����Ϣ���ߵ��̵�ָ�뺯��
*��    ��:get_yaw_motor_point get_pitch_motor_point
*�� �� ֵ:NULL
*����:		RM
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
*�� �� ��:fp32 motor_ecd_to_angle_change(uint16_t rotor_angle, uint16_t offset_ecd
*����˵��:������ԽǶ�
*��    ��:rotor_angle offset_ecd
*�� �� ֵ:NULL
*����:		RM
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
*�� �� ��:GIMBAL_RC_Control(Gimbal_Control_t *gimbal_rc_control)
*����˵��:ң�����г�����ģʽ�����Լ��޷�
*��    ��:gimbal_rc_control
*�� �� ֵ:NULL
*����:		������
**********************************************************************************************************/
//ң�����ݸ���
static void GIMBAL_RC_Set_Control(Gimbal_Control_t *gimbal_rc_set_control)
{
		if (gimbal_rc_set_control == NULL)
    {
        return;
    }
	  //ң���������ݴ�������
//		static int16_t yaw_channel,pitch_channel;
    rc_deadline_limit(gimbal_rc_set_control->gimbal_rc_ctrl->ch3 , gimbal_rc_set_control->gimbal_value_limit.yaw_channel, RC_Dead_Band);
    rc_deadline_limit(gimbal_rc_set_control->gimbal_rc_ctrl->ch4, gimbal_rc_set_control->gimbal_value_limit.pitch_channel, RC_Dead_Band);
		//ң����ģʽ����
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
		
		
		//��ֹ�ٴο���ʱң�ص�����ʹ�����˷���
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
*�� �� ��:GIMBAL_Feedback_Update(Gimbal_Control_t *gimbal_feedback_update)
*����˵��:������̨����
*��    ��:gimbal_feedback_update
*�� �� ֵ:NULL
*����:		������
**********************************************************************************************************/
static void GIMBAL_Feedback_Update(Gimbal_Control_t *gimbal_feedback_update)
{
		if (gimbal_feedback_update == NULL)
		{
				return;
		}
		//���������ǵ�����
		MPU6500_GET_DATA();														 
		gimbal_feedback_update->gimbal_pitch_motor.absolute_angle = *(gimbal_feedback_update->gimbal_INT_angle_point + INS_PITCH_ADDRESS_OFFSET);
    gimbal_feedback_update->gimbal_pitch_motor.relative_angle = motor_ecd_to_angle_change(gimbal_feedback_update->gimbal_pitch_motor.gimbal_motor_measure->rotor_angle,
                                                                                          gimbal_feedback_update->gimbal_pitch_motor.offset_ecd);
//    gimbal_feedback_update->gimbal_pitch_motor.motor_gyro = *(gimbal_feedback_update->gimbal_INT_gyro_point + 2);//ԭΪY
		
    gimbal_feedback_update->gimbal_yaw_motor.absolute_angle = *(gimbal_feedback_update->gimbal_INT_angle_point + INS_YAW_ADDRESS_OFFSET);
    gimbal_feedback_update->gimbal_yaw_motor.relative_angle = motor_ecd_to_angle_change(gimbal_feedback_update->gimbal_yaw_motor.gimbal_motor_measure->rotor_angle,
                                                                                        gimbal_feedback_update->gimbal_yaw_motor.offset_ecd);
//    gimbal_feedback_update->gimbal_yaw_motor.motor_gyro = arm_cos_f32(gimbal_feedback_update->gimbal_pitch_motor.relative_angle) * 
//														(*(gimbal_feedback_update->gimbal_INT_gyro_point + 1))
//                                                        - arm_sin_f32(gimbal_feedback_update->gimbal_pitch_motor.relative_angle) * 
//														(*(gimbal_feedback_update->gimbal_INT_gyro_point + 0));//ԭΪX
		
	/***********************************************START***********************************************/
	/*���ܴ������ƣ��Ӿ���Ϣ����*/
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
*�� �� ��:GIMBAL_Cali_set(Gimbal_Control_t *gimbal_cali_set)
*����˵��:��̨���λ�����ü�����ֵ ��offset_ecdΪ��е�Ƕ�ֵ ������λΪ����
*��    ��:gimbal_cali_set
*�� �� ֵ:NULL
*����:		������
**********************************************************************************************************/
static void GIMBAL_Cali_Set(Gimbal_Control_t *gimbal_cali_set)
{
		if (gimbal_cali_set == NULL)
		{
				return;
		}
		//��̨��е��ֵ
		gimbal_cali_set->gimbal_yaw_motor.offset_ecd 						= YAW_ENCODE_OFFEST;
		gimbal_cali_set->gimbal_pitch_motor.offset_ecd 					= PITCH_ENCODE_OFFEST;
		//��̨��λֵ ��λΪ����
		gimbal_cali_set->gimbal_yaw_motor.max_relative_angle 		= rad_format(YAW_MAX_ENCODE_ANGLE);
		gimbal_cali_set->gimbal_yaw_motor.min_relative_angle 		= rad_format(YAW_MIN_ENCODE_ANGLE);
		gimbal_cali_set->gimbal_pitch_motor.max_relative_angle 	= rad_format(PITCH_MAX_ENCODE_ANGLE);
		gimbal_cali_set->gimbal_pitch_motor.min_relative_angle 	= rad_format(PITCH_MIN_ENCODE_ANGLE); 
}

/**********************************************************************************************************
*�� �� ��:GIMBAL_Init(Gimbal_Control_t *gimbal_init)
*����˵��:��̨������ʼ��
*��    ��:gimbal_init
*�� �� ֵ:NULL	
*����:		������
**********************************************************************************************************/
static void GIMBAL_Init(Gimbal_Control_t *gimbal_init)
{
		if (gimbal_init == NULL)
		{
				return;
		}
		//�������ָ���ȡ
    gimbal_init->gimbal_yaw_motor.gimbal_motor_measure = get_Yaw_Gimbal_Motor_Measure_Point();
    gimbal_init->gimbal_pitch_motor.gimbal_motor_measure = get_Pitch_Gimbal_Motor_Measure_Point();

		//����������ָ���ȡ
    gimbal_init->gimbal_INT_angle_point = get_INS_angle_point();
    gimbal_init->gimbal_INT_gyro_point = get_MPU6500_Gyro_Data_Point();
	
		//ң��������ָ���ȡ
    gimbal_init->gimbal_rc_ctrl = get_remote_control_point();
    
		//��ʼ��pitch���pid
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
				
    //��ʼ��pitch���pid
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
	
    //������̨����ĳ�ʼֵ
		GIMBAL_Cali_Set(gimbal_init);
		
    GIMBAL_Feedback_Update(gimbal_init);

}

/**********************************************************************************************************
*�� �� ��:GIMBAL_PAN_MOTOR_CONTROL(Gimbal_Control_t *gimbal_pan_motor_control)
*����˵��:��̨YAW��pitch�������ƣ���Gimbal_Motor_mode��־λ�ϱ���
*��    ��:NULL
*�� �� ֵ:NULL
*����:		������
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
*�� �� ��:GIMBAL_YAW_MOTOR_CONTROL(Gimbal_Control_t *gimbal_yaw_motor_control);
*����˵��:����YAW����
*��    ��:gimbal_yaw_motor_control
*�� �� ֵ:NULL
*����:		������
**********************************************************************************************************/
static void GIMBAL_YAW_MOTOR_CONTROL(Gimbal_Control_t *gimbal_yaw_motor_control)
{
		if (gimbal_yaw_motor_control == NULL)
		{
				return;
		}
		static int yaw_flag_status = 0;//yaw��̨��ֹ��־ά
		if(gimbal_yaw_motor_control->gimbal_rc_ctrl->ch3 == 0)
		{
			if(yaw_flag_status == 0)
			{
				gimbal_yaw_motor_control->gimbal_yaw_motor.relative_angle_set = rad_format(*(gimbal_yaw_motor_control->gimbal_INT_angle_point + INS_YAW_ADDRESS_OFFSET)*NEGATION_COEFFICIENT);
				//gimbal_yaw_motor_control->gimbal_yaw_motor.relative_angle;
				gimbal_motor_limited(gimbal_yaw_motor_control);//yaw��λ
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
*�� �� ��:GIMBAL_PITCH_MOTOR_CONTROL(Gimbal_Control_t *gimbal_pitch_motor_control);
*����˵��:����PITCH����
*��    ��:gimbal_pitch_motor_control
*�� �� ֵ:NULL
*����:		������
**********************************************************************************************************/
static void GIMBAL_PITCH_MOTOR_CONTROL(Gimbal_Control_t *gimbal_pitch_motor_control)
{
		if (gimbal_pitch_motor_control == NULL)
		{
				return;
		}
		static int pit_flag_status = 0;//pit��̨��ֹ��־ά
		if(gimbal_pitch_motor_control->gimbal_rc_ctrl->ch4 == 0)//���ң����û������
		{		
			if(pit_flag_status == 0)//ң��û�������ʱ��Ҫʵʱ��ȡ�����е�Ƕ�ֵ
			{
				gimbal_pitch_motor_control->gimbal_pitch_motor.relative_angle_set = gimbal_pitch_motor_control->gimbal_pitch_motor.relative_angle;
				//rad_format(*(gimbal_pitch_motor_control->gimbal_INT_angle_point+INS_PITCH_ADDRESS_OFFSET));
				gimbal_motor_limited(gimbal_pitch_motor_control);//pitch��λ
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
*�� �� ��:GIMBAL_Set_Motor(Gimbal_Control_t *gimbal_set_motor)
*����˵��:���յ�����ƺ���
*��    ��:gimbal_set_motor
*�� �� ֵ:NULL
*����:		������
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
		set_motor_voltage_CAN1(0, 													//���õ���ٶ�
							0, 
							0, 
							0, 
							0);
	}
	else if(gimbal_set_motor->Gimbal_Motor_mode == GIMBAL_MIXED_AB_RE_ANGLE)
//	else if(remote_control.switch_left == 3)
	{
		set_motor_voltage_CAN1(0, 													//���õ���ٶ�
							Yaw_Set_Current, /*Yaw_Set_Current*/
							Pitch_Set_Current, /*Pitch_Set_Current*/
							0, 
							0);
	}
}
