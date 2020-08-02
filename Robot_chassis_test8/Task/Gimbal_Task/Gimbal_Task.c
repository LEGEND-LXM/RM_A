#include "Gimbal_Task.h"
#include "Gimbal_behaviour.h"
#include "bsp_imu.h"

#include "arm_math.h"
#include "user_lib.h"

//�������ֵ���� 0��8191
#define ECD_Format(ecd)         \
    {                           \
        if ((ecd) > ecd_range)  \
            (ecd) -= ecd_range; \
        else if ((ecd) < 0)     \
            (ecd) += ecd_range; \
    }

#define gimbal_total_pid_clear(gimbal_clear)                                                   \
    {                                                                                          \
        Gimbal_PID_clear(&(gimbal_clear)->gimbal_yaw_motor.gimbal_motor_absolute_angle_pid);   \
        Gimbal_PID_clear(&(gimbal_clear)->gimbal_yaw_motor.gimbal_motor_relative_angle_pid);   \
        pid_clear(&(gimbal_clear)->gimbal_yaw_motor.gimbal_motor_gyro_pid);                    \
                                                                                               \
        Gimbal_PID_clear(&(gimbal_clear)->gimbal_pitch_motor.gimbal_motor_absolute_angle_pid); \
        Gimbal_PID_clear(&(gimbal_clear)->gimbal_pitch_motor.gimbal_motor_relative_angle_pid); \
        pid_clear(&(gimbal_clear)->gimbal_pitch_motor.gimbal_motor_gyro_pid);                  \
    }		
		
//��̨���������������
static Gimbal_Control_t gimbal_control;
//���͵ĵ������
static int16_t Yaw_Set_Current = 0, Pitch_Set_Current = 0;
		
//��̨��ʼ��
static void GIMBAL_Init(Gimbal_Control_t *gimbal_init);
//��̨���ݸ���
static void GIMBAL_Feedback_Update(Gimbal_Control_t *gimbal_feedback_update);
//��̨״̬����
static void GIMBAL_Set_Mode(Gimbal_Control_t *gimbal_set_mode);
//��̨״̬�л��������ݣ������������״̬�л���������״̬����Ŀ��ֵ
static void GIMBAL_Mode_Change_Control_Transit(Gimbal_Control_t *gimbal_mode_change);
//������̨������
static void GIMBAL_Set_Contorl(Gimbal_Control_t *gimbal_set_control);
//��̨����pid����
static void GIMBAL_Control_loop(Gimbal_Control_t *gimbal_control_loop);
		
//��̨���λ�����ü�����ֵ
static void GIMBAL_Cali_set(Gimbal_Control_t *gimbal_cali_set);

static void gimbal_motor_absolute_angle_control(Gimbal_Motor_t *gimbal_motor);
static void gimbal_motor_relative_angle_control(Gimbal_Motor_t *gimbal_motor);
static void gimbal_motor_raw_angle_control(Gimbal_Motor_t *gimbal_motor);

//������̨��������ֵ����ԽǶ�
static fp32 motor_ecd_to_angle_change(uint16_t rotor_angle, uint16_t offset_ecd);

//�������ǽǶȿ����£��Կ��Ƶ�Ŀ��ֵ�������Է��������ԽǶ�
static void GIMBAL_absolute_angle_limit(Gimbal_Motor_t *gimbal_motor, fp32 add);
static void GIMBAL_relative_angle_limit(Gimbal_Motor_t *gimbal_motor, fp32 add);
static void GIMBAL_PID_Init(Gimbal_PID_t *pid, fp32 maxout, fp32 max_iout, fp32 kp, fp32 ki, fp32 kd);
static fp32 GIMBAL_PID_Calc(Gimbal_PID_t *pid, fp32 get, fp32 set, fp32 error_delta);

static void Gimbal_PID_clear(Gimbal_PID_t *gimbal_pid_clear);

void Gimbal_Task(void const * argument)
{
//	printf("In Gimbal_Task!\n");
	  //�ȴ������������������������
    osDelay(GIMBAL_TASK_INIT_TIME);
	  //��̨��ʼ��
    GIMBAL_Init(&gimbal_control);
	//���ﲦ���ŵ��Լ���������ȥ��
	//�˴�����Ҫ�ӵ��߼��
	for(;;)
	{
		MPU6500_GET_DATA();																	 //���������ǵ�����
		
		gimbal_control.gimbal_pitch_motor.relative_angle = motor_ecd_to_angle_change(gimbal_control.gimbal_pitch_motor.gimbal_motor_measure->rotor_angle,
                                                                                 gimbal_control.gimbal_pitch_motor.offset_ecd);    
		gimbal_control.gimbal_yaw_motor.relative_angle = motor_ecd_to_angle_change(gimbal_control.gimbal_yaw_motor.gimbal_motor_measure->rotor_angle,
                                                                               gimbal_control.gimbal_yaw_motor.offset_ecd);
		if(remote_control.ch4 == 0)
		{
			if(gimbal_control.gimbal_pitch_motor.relative_angle_set == 0)
				gimbal_control.gimbal_pitch_motor.relative_angle_set = gimbal_control.gimbal_pitch_motor.relative_angle;
				gimbal_control.gimbal_pitch_motor.given_current = pid_calc(&gimbal_control.gimbal_yaw_motor.gimbal_motor_gyro_pid,
																																gimbal_control.gimbal_pitch_motor.relative_angle_set,
																																gimbal_control.gimbal_pitch_motor.relative_angle);
		}
		else
		{
			gimbal_control.gimbal_pitch_motor.relative_angle_set = 0;
			gimbal_control.gimbal_pitch_motor.relative_angle_set = remote_control.ch4*0.0088228f;
		
		}	
		gimbal_control.gimbal_pitch_motor.given_current = pid_calc(&gimbal_control.gimbal_pitch_motor.gimbal_motor_gyro_pid,
																																gimbal_control.gimbal_pitch_motor.relative_angle_set,
																																imu.wx);
//		GIMBAL_Set_Mode(&gimbal_control);                    //������̨����ģʽ
//		GIMBAL_Mode_Change_Control_Transit(&gimbal_control); //����ģʽ�л� �������ݹ���
//    GIMBAL_Feedback_Update(&gimbal_control);             //��̨���ݷ���
//    GIMBAL_Set_Contorl(&gimbal_control);                 //������̨������
//    GIMBAL_Control_loop(&gimbal_control);                //��̨����PID����	
//		
//#if YAW_TURN
//        Yaw_Set_Current = gimbal_control.gimbal_yaw_motor.given_current;
//#else
//        Yaw_Set_Current = -gimbal_control.gimbal_yaw_motor.given_current;
//#endif

//#if PITCH_TURN
//        Pitch_Set_Current = gimbal_control.gimbal_pitch_motor.given_current;
//#else
//        Pitch_Set_Current = -gimbal_control.gimbal_pitch_motor.given_current;
//#endif
		if(remote_control .switch_left == 2)
		set_motor_voltage(0, 													//���õ���ٶ�
												0, 
												0, 
												0, 
												0);	
		else
		set_motor_voltage(0, 													//���õ���ٶ�
												-gimbal_control.gimbal_pitch_motor.given_current, 
												0, 
												0, 
												0);	
		
		wave_form_data[0] = gimbal_control.gimbal_pitch_motor.given_current;
		wave_form_data[1] = gimbal_control.gimbal_pitch_motor.gimbal_motor_measure->rotor_angle;
		
		wave_form_data[2] = gimbal_control.gimbal_pitch_motor.relative_angle_set*100;
		wave_form_data[3] = gimbal_control.gimbal_pitch_motor.relative_angle*100;

		wave_form_data[4] = imu.pit;
		wave_form_data[5] = imu.yaw;
		wave_form_data[6] = imu.rol;
		
		wave_form_data[7] = imu.temp;
		shanwai_send_wave_form();
		osDelay (10);
	}
}


const Gimbal_Motor_t *get_yaw_motor_point(void)
{
    return &gimbal_control.gimbal_yaw_motor;
}

const Gimbal_Motor_t *get_pitch_motor_point(void)
{
    return &gimbal_control.gimbal_pitch_motor;
}

static void GIMBAL_Init(Gimbal_Control_t *gimbal_init)
{
    //�������ָ���ȡ
	//������̨����ı����Ҫ���ݵ���ı��������
    gimbal_init->gimbal_yaw_motor.gimbal_motor_measure = get_Yaw_Gimbal_Motor_Measure_Point();
    gimbal_init->gimbal_pitch_motor.gimbal_motor_measure = get_Pitch_Gimbal_Motor_Measure_Point();
	
	//����������ָ���ȡ
    gimbal_init->gimbal_INT_angle_point = get_INS_angle_point();
    gimbal_init->gimbal_INT_gyro_point = get_MPU6500_Gyro_Data_Point();
	
    //ң��������ָ���ȡ
    gimbal_init->gimbal_rc_ctrl = get_remote_control_point();
    //��ʼ�����ģʽ
    gimbal_init->gimbal_yaw_motor.gimbal_motor_mode = gimbal_init->gimbal_yaw_motor.last_gimbal_motor_mode = GIMBAL_MOTOR_RAW;
    gimbal_init->gimbal_pitch_motor.gimbal_motor_mode = gimbal_init->gimbal_pitch_motor.last_gimbal_motor_mode = GIMBAL_MOTOR_RAW;

    //��ʼ��yaw���pid
    GIMBAL_PID_Init(&gimbal_init->gimbal_yaw_motor.gimbal_motor_absolute_angle_pid, 
										YAW_GYRO_ABSOLUTE_PID_MAX_OUT, 
										YAW_GYRO_ABSOLUTE_PID_MAX_IOUT, 
										YAW_GYRO_ABSOLUTE_PID_KP, 
										YAW_GYRO_ABSOLUTE_PID_KI, 
										YAW_GYRO_ABSOLUTE_PID_KD);
    GIMBAL_PID_Init(&gimbal_init->gimbal_yaw_motor.gimbal_motor_relative_angle_pid, 
										YAW_ENCODE_RELATIVE_PID_MAX_OUT, 
										YAW_ENCODE_RELATIVE_PID_MAX_IOUT, 
										YAW_ENCODE_RELATIVE_PID_KP, 
										YAW_ENCODE_RELATIVE_PID_KI, 
										YAW_ENCODE_RELATIVE_PID_KD);
		pid_init(&gimbal_init->gimbal_yaw_motor.gimbal_motor_gyro_pid, 
										YAW_SPEED_PID_KP,
										YAW_SPEED_PID_KI,
										YAW_SPEED_PID_KD,
										YAW_SPEED_PID_MAX_OUT,
										YAW_SPEED_PID_MAX_IOUT);
		
    //��ʼ��pitch���pid
    GIMBAL_PID_Init(&gimbal_init->gimbal_pitch_motor.gimbal_motor_absolute_angle_pid, 
										PITCH_GYRO_ABSOLUTE_PID_MAX_OUT, 
										PITCH_GYRO_ABSOLUTE_PID_MAX_IOUT, 
										PITCH_GYRO_ABSOLUTE_PID_KP, 
										PITCH_GYRO_ABSOLUTE_PID_KI, 
										PITCH_GYRO_ABSOLUTE_PID_KD);
    GIMBAL_PID_Init(&gimbal_init->gimbal_pitch_motor.gimbal_motor_relative_angle_pid, 
										PITCH_ENCODE_RELATIVE_PID_MAX_OUT, 
										PITCH_ENCODE_RELATIVE_PID_MAX_IOUT, 
										PITCH_ENCODE_RELATIVE_PID_KP, 
										PITCH_ENCODE_RELATIVE_PID_KI, 
										PITCH_ENCODE_RELATIVE_PID_KD);
    		pid_init(&gimbal_init->gimbal_pitch_motor.gimbal_motor_gyro_pid, 
										PITCH_SPEED_PID_KP,
										PITCH_SPEED_PID_KI,
										PITCH_SPEED_PID_KD,
										PITCH_SPEED_PID_MAX_OUT,
										PITCH_SPEED_PID_MAX_IOUT);
				
		//�������PID
    gimbal_total_pid_clear(gimbal_init);
		
		//������̨����ĳ�ʼֵ
		GIMBAL_Cali_set(gimbal_init);
		
    GIMBAL_Feedback_Update(gimbal_init);

    gimbal_init->gimbal_yaw_motor.absolute_angle_set = gimbal_init->gimbal_yaw_motor.absolute_angle;
    gimbal_init->gimbal_yaw_motor.relative_angle_set = gimbal_init->gimbal_yaw_motor.relative_angle;
    gimbal_init->gimbal_yaw_motor.motor_gyro_set = gimbal_init->gimbal_yaw_motor.motor_gyro;


    gimbal_init->gimbal_pitch_motor.absolute_angle_set = gimbal_init->gimbal_pitch_motor.absolute_angle;
    gimbal_init->gimbal_pitch_motor.relative_angle_set = gimbal_init->gimbal_pitch_motor.relative_angle;
    gimbal_init->gimbal_pitch_motor.motor_gyro_set = gimbal_init->gimbal_pitch_motor.motor_gyro;
}

static void GIMBAL_Set_Mode(Gimbal_Control_t *gimbal_set_mode)
{
    if (gimbal_set_mode == NULL)
    {
        return;
    }
    gimbal_behaviour_mode_set(gimbal_set_mode);
}


static void GIMBAL_Feedback_Update(Gimbal_Control_t *gimbal_feedback_update)
{
    if (gimbal_feedback_update == NULL)
    {
        return;
    }
    //��̨���ݸ���//�����off_set��ֵ������Ҫʵ�ʲ����ģ��������㷨���
		//pitch��
    gimbal_feedback_update->gimbal_pitch_motor.absolute_angle = *(gimbal_feedback_update->gimbal_INT_angle_point + INS_ROLL_ADDRESS_OFFSET);
    gimbal_feedback_update->gimbal_pitch_motor.relative_angle = motor_ecd_to_angle_change(gimbal_feedback_update->gimbal_pitch_motor.gimbal_motor_measure->rotor_angle,
                                                                                          gimbal_feedback_update->gimbal_pitch_motor.offset_ecd);
    gimbal_feedback_update->gimbal_pitch_motor.motor_gyro = *(gimbal_feedback_update->gimbal_INT_gyro_point + 2);//ԭΪY
		
    gimbal_feedback_update->gimbal_yaw_motor.absolute_angle = *(gimbal_feedback_update->gimbal_INT_angle_point + INS_YAW_ADDRESS_OFFSET);
    gimbal_feedback_update->gimbal_yaw_motor.relative_angle = motor_ecd_to_angle_change(gimbal_feedback_update->gimbal_yaw_motor.gimbal_motor_measure->rotor_angle,
                                                                                        gimbal_feedback_update->gimbal_yaw_motor.offset_ecd);
    gimbal_feedback_update->gimbal_yaw_motor.motor_gyro = arm_cos_f32(gimbal_feedback_update->gimbal_pitch_motor.relative_angle) * 
																																	(*(gimbal_feedback_update->gimbal_INT_gyro_point + 1))
                                                        - arm_sin_f32(gimbal_feedback_update->gimbal_pitch_motor.relative_angle) * 
																																	(*(gimbal_feedback_update->gimbal_INT_gyro_point + 0));//ԭΪX
}


//������ԽǶ�
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
//��̨״̬�л����棬����״̬�л�����
static void GIMBAL_Mode_Change_Control_Transit(Gimbal_Control_t *gimbal_mode_change)
{
    if (gimbal_mode_change == NULL)
    {
        return;
    }
    //yaw���״̬���л�������������
    if (gimbal_mode_change->gimbal_yaw_motor.last_gimbal_motor_mode != GIMBAL_MOTOR_RAW && 
				gimbal_mode_change->gimbal_yaw_motor.gimbal_motor_mode == GIMBAL_MOTOR_RAW)
    {
        gimbal_mode_change->gimbal_yaw_motor.raw_cmd_current = 
				gimbal_mode_change->gimbal_yaw_motor.current_set = 
				gimbal_mode_change->gimbal_yaw_motor.given_current;
    }
    else if (gimbal_mode_change->gimbal_yaw_motor.last_gimbal_motor_mode != GIMBAL_MOTOR_GYRO && 
						 gimbal_mode_change->gimbal_yaw_motor.gimbal_motor_mode == GIMBAL_MOTOR_GYRO)
    {
        gimbal_mode_change->gimbal_yaw_motor.absolute_angle_set = gimbal_mode_change->gimbal_yaw_motor.absolute_angle;
    }
    else if (gimbal_mode_change->gimbal_yaw_motor.last_gimbal_motor_mode != GIMBAL_MOTOR_ENCONDE && 
						 gimbal_mode_change->gimbal_yaw_motor.gimbal_motor_mode == GIMBAL_MOTOR_ENCONDE)
    {
        gimbal_mode_change->gimbal_yaw_motor.relative_angle_set = gimbal_mode_change->gimbal_yaw_motor.relative_angle;
    }
    gimbal_mode_change->gimbal_yaw_motor.last_gimbal_motor_mode = gimbal_mode_change->gimbal_yaw_motor.gimbal_motor_mode;

    //pitch���״̬���л���������
    if (gimbal_mode_change->gimbal_pitch_motor.last_gimbal_motor_mode != GIMBAL_MOTOR_RAW && 
				gimbal_mode_change->gimbal_pitch_motor.gimbal_motor_mode == GIMBAL_MOTOR_RAW)
    {
        gimbal_mode_change->gimbal_pitch_motor.raw_cmd_current = 
				gimbal_mode_change->gimbal_pitch_motor.current_set = 
				gimbal_mode_change->gimbal_pitch_motor.given_current;
    }
    else if (gimbal_mode_change->gimbal_pitch_motor.last_gimbal_motor_mode != GIMBAL_MOTOR_GYRO && 
						 gimbal_mode_change->gimbal_pitch_motor.gimbal_motor_mode == GIMBAL_MOTOR_GYRO)
    {
        gimbal_mode_change->gimbal_pitch_motor.absolute_angle_set = gimbal_mode_change->gimbal_pitch_motor.absolute_angle;
    }
    else if (gimbal_mode_change->gimbal_pitch_motor.last_gimbal_motor_mode != GIMBAL_MOTOR_ENCONDE && 
						 gimbal_mode_change->gimbal_pitch_motor.gimbal_motor_mode == GIMBAL_MOTOR_ENCONDE)
    {
        gimbal_mode_change->gimbal_pitch_motor.relative_angle_set = gimbal_mode_change->gimbal_pitch_motor.relative_angle;
    }

    gimbal_mode_change->gimbal_pitch_motor.last_gimbal_motor_mode = gimbal_mode_change->gimbal_pitch_motor.gimbal_motor_mode;
}

//��̨����������
static void GIMBAL_Set_Contorl(Gimbal_Control_t *gimbal_set_control)
{
    if (gimbal_set_control == NULL)
    {
        return;
    }

    fp32 add_yaw_angle = 0.0f;
    fp32 add_pitch_angle = 0.0f;

    gimbal_behaviour_control_set(&add_yaw_angle, &add_pitch_angle, gimbal_set_control);
    
		wave_form_data[6] = add_yaw_angle*100;
		wave_form_data[7] = add_pitch_angle*100;
		
//		shanwai_send_wave_form();
		//yaw���ģʽ����
    if (gimbal_set_control->gimbal_yaw_motor.gimbal_motor_mode == GIMBAL_MOTOR_RAW)
    {
        //rawģʽ�£�ֱ�ӷ��Ϳ���ֵ
        gimbal_set_control->gimbal_yaw_motor.raw_cmd_current = add_yaw_angle;
    }
    else if (gimbal_set_control->gimbal_yaw_motor.gimbal_motor_mode == GIMBAL_MOTOR_GYRO)
    {
        //gyroģʽ�£������ǽǶȿ���
        GIMBAL_absolute_angle_limit(&gimbal_set_control->gimbal_yaw_motor, add_yaw_angle);
    }
    else if (gimbal_set_control->gimbal_yaw_motor.gimbal_motor_mode == GIMBAL_MOTOR_ENCONDE)
    {
        //encondeģʽ�£��������Ƕȿ���
        GIMBAL_relative_angle_limit(&gimbal_set_control->gimbal_yaw_motor, add_yaw_angle);
    }

    //pitch���ģʽ����
    if (gimbal_set_control->gimbal_pitch_motor.gimbal_motor_mode == GIMBAL_MOTOR_RAW)
    {
        //rawģʽ�£�ֱ�ӷ��Ϳ���ֵ
        gimbal_set_control->gimbal_pitch_motor.raw_cmd_current = add_pitch_angle;
    }
    else if (gimbal_set_control->gimbal_pitch_motor.gimbal_motor_mode == GIMBAL_MOTOR_GYRO)
    {
        //gyroģʽ�£������ǽǶȿ���
        GIMBAL_absolute_angle_limit(&gimbal_set_control->gimbal_pitch_motor, add_pitch_angle);
    }
    else if (gimbal_set_control->gimbal_pitch_motor.gimbal_motor_mode == GIMBAL_MOTOR_ENCONDE)
    {
        //encondeģʽ�£��������Ƕȿ���
        GIMBAL_relative_angle_limit(&gimbal_set_control->gimbal_pitch_motor, add_pitch_angle);
    }
		
}

//������ ����������
static void GIMBAL_absolute_angle_limit(Gimbal_Motor_t *gimbal_motor, fp32 add)
{
    static fp32 bias_angle;
    static fp32 angle_set;
    if (gimbal_motor == NULL)
    {
        return;
    }
    //��ǰ�������Ƕ�
    bias_angle = rad_format(gimbal_motor->absolute_angle_set - gimbal_motor->absolute_angle);
    //��̨��ԽǶ�+ ���Ƕ� + �����Ƕ� ������� ����е�Ƕ�
    if (gimbal_motor->relative_angle + bias_angle + add > gimbal_motor->max_relative_angle)
    {
        //�����������е�Ƕȿ��Ʒ���
        if (add > 0.0f)
        {
            //�����һ��������ӽǶȣ�
            add = gimbal_motor->max_relative_angle - gimbal_motor->relative_angle - bias_angle;
        }
    }
    else if (gimbal_motor->relative_angle + bias_angle + add < gimbal_motor->min_relative_angle)
    {
        if (add < 0.0f)
        {
            add = gimbal_motor->min_relative_angle - gimbal_motor->relative_angle - bias_angle;
        }
    }
    angle_set = gimbal_motor->absolute_angle_set;
    gimbal_motor->absolute_angle_set = rad_format(angle_set + add);
}

static void GIMBAL_relative_angle_limit(Gimbal_Motor_t *gimbal_motor, fp32 add)
{
    if (gimbal_motor == NULL)
    {
        return;
    }
    gimbal_motor->relative_angle_set = gimbal_motor->relative_angle_set + add;
		    //�Ƿ񳬹���� ��Сֵ
    if (gimbal_motor->relative_angle_set > gimbal_motor->max_relative_angle)
    {
        gimbal_motor->relative_angle_set = gimbal_motor->max_relative_angle;
//				wave_form_data[7] = gimbal_motor->relative_angle_set*100000;
    }
    else if (gimbal_motor->relative_angle_set < gimbal_motor->min_relative_angle)
    {
        gimbal_motor->relative_angle_set = gimbal_motor->min_relative_angle;
//				wave_form_data[7] = gimbal_motor->relative_angle_set*100000;
    }
}
//�������Խ���̨�������Сֵ��¼����
static void GIMBAL_Cali_set(Gimbal_Control_t *gimbal_cali_set)
{
	 if (gimbal_cali_set == NULL)
   {
		return;
   }
       
	gimbal_control.gimbal_yaw_motor.offset_ecd 						= YAW_ENCODE_OFFEST;
	gimbal_control.gimbal_yaw_motor.max_relative_angle 		= rad_format(YAW_MAX_ENCODE_ANGLE);
	gimbal_control.gimbal_yaw_motor.min_relative_angle 		= rad_format(YAW_MIN_ENCODE_ANGLE);
	gimbal_control.gimbal_pitch_motor.offset_ecd 					= PITCH_ENCODE_OFFEST;
	gimbal_control.gimbal_pitch_motor.max_relative_angle 	= rad_format(PITCH_MAX_ENCODE_ANGLE);
	gimbal_control.gimbal_pitch_motor.min_relative_angle 	= rad_format(PITCH_MIN_ENCODE_ANGLE);
	 
	 
}



//��̨����״̬ʹ�ò�ͬ����pid
static void GIMBAL_Control_loop(Gimbal_Control_t *gimbal_control_loop)
{
    if (gimbal_control_loop == NULL)
    {
        return;
    }
    //yaw��ͬģʽ���ڲ�ͬ�Ŀ��ƺ���
    if (gimbal_control_loop->gimbal_yaw_motor.gimbal_motor_mode == GIMBAL_MOTOR_RAW)
    {
        //raw����
        gimbal_motor_raw_angle_control(&gimbal_control_loop->gimbal_yaw_motor);
    }
    else if (gimbal_control_loop->gimbal_yaw_motor.gimbal_motor_mode == GIMBAL_MOTOR_GYRO)
    {
        //gyro�Ƕȿ���
        gimbal_motor_absolute_angle_control(&gimbal_control_loop->gimbal_yaw_motor);
    }
    else if (gimbal_control_loop->gimbal_yaw_motor.gimbal_motor_mode == GIMBAL_MOTOR_ENCONDE)
    {
        //enconde�Ƕȿ���
        gimbal_motor_relative_angle_control(&gimbal_control_loop->gimbal_yaw_motor);
    }

    //pitch��ͬģʽ���ڲ�ͬ�Ŀ��ƺ���
    if (gimbal_control_loop->gimbal_pitch_motor.gimbal_motor_mode == GIMBAL_MOTOR_RAW)
    {
        //raw����
        gimbal_motor_raw_angle_control(&gimbal_control_loop->gimbal_pitch_motor);
    }
    else if (gimbal_control_loop->gimbal_pitch_motor.gimbal_motor_mode == GIMBAL_MOTOR_GYRO)
    {
        //gyro�Ƕȿ���
        gimbal_motor_absolute_angle_control(&gimbal_control_loop->gimbal_pitch_motor);
    }
    else if (gimbal_control_loop->gimbal_pitch_motor.gimbal_motor_mode == GIMBAL_MOTOR_ENCONDE)
    {
        //enconde�Ƕȿ���
        gimbal_motor_relative_angle_control(&gimbal_control_loop->gimbal_pitch_motor);
    }
}

static void gimbal_motor_absolute_angle_control(Gimbal_Motor_t *gimbal_motor)
{
    if (gimbal_motor == NULL)
    {
        return;
    }
    //�ǶȻ����ٶȻ�����pid����
    gimbal_motor->motor_gyro_set = GIMBAL_PID_Calc(&gimbal_motor->gimbal_motor_absolute_angle_pid, 
																										gimbal_motor->absolute_angle, 
																										gimbal_motor->absolute_angle_set, 
																										gimbal_motor->motor_gyro);
    gimbal_motor->current_set = pid_calc(&gimbal_motor->gimbal_motor_gyro_pid, 
																					gimbal_motor->motor_gyro_set,
																					gimbal_motor->motor_gyro);
    //����ֵ��ֵ
    gimbal_motor->given_current = (int16_t)(gimbal_motor->current_set);
}

static void gimbal_motor_relative_angle_control(Gimbal_Motor_t *gimbal_motor)
{
    if (gimbal_motor == NULL)
    {
        return;
    }

    //�ǶȻ����ٶȻ�����pid����
    gimbal_motor->motor_gyro_set = GIMBAL_PID_Calc(&gimbal_motor->gimbal_motor_relative_angle_pid, 
																										gimbal_motor->relative_angle, 
																										gimbal_motor->relative_angle_set, 
																										gimbal_motor->motor_gyro);
    gimbal_motor->current_set = pid_calc(&gimbal_motor->gimbal_motor_gyro_pid, 
																					gimbal_motor->motor_gyro_set, 
																					gimbal_motor->motor_gyro);
    //����ֵ��ֵ
    gimbal_motor->given_current = (int16_t)(gimbal_motor->current_set);
}
static void gimbal_motor_raw_angle_control(Gimbal_Motor_t *gimbal_motor)
{
    if (gimbal_motor == NULL)
    {
        return;
    }
    gimbal_motor->current_set = gimbal_motor->raw_cmd_current;
    gimbal_motor->given_current = (int16_t)(gimbal_motor->current_set);
}

//�����PID�õ����ڴ�.h�ļ������̨pid�ṹ��
static void GIMBAL_PID_Init(Gimbal_PID_t *pid, fp32 maxout, fp32 max_iout, fp32 kp, fp32 ki, fp32 kd)
{
    if (pid == NULL)
    {
        return;
    }
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;

    pid->err = 0.0f;
    pid->get = 0.0f;

    pid->max_iout = max_iout;
    pid->max_out = maxout;
}

static fp32 GIMBAL_PID_Calc(Gimbal_PID_t *pid, fp32 get, fp32 set, fp32 error_delta)
{
    fp32 err;
    if (pid == NULL)
    {
        return 0.0f;
    }
    pid->get = get;
    pid->set = set;

    err = set - get;
    pid->err = rad_format(err);
    pid->Pout = pid->kp * pid->err;
    pid->Iout += pid->ki * pid->err;
    pid->Dout = pid->kd * error_delta;
    abs_limit(&pid->Iout, pid->max_iout);
    pid->out = pid->Pout + pid->Iout + pid->Dout;
    abs_limit(&pid->out, pid->max_out);
    return pid->out;
}

//pid��������
static void Gimbal_PID_clear(Gimbal_PID_t *gimbal_pid_clear)
{
    if (gimbal_pid_clear == NULL)
    {
        return;
    }
    gimbal_pid_clear->err = gimbal_pid_clear->set = gimbal_pid_clear->get = 0.0f;
    gimbal_pid_clear->out = gimbal_pid_clear->Pout = gimbal_pid_clear->Iout = gimbal_pid_clear->Dout = 0.0f;
}

