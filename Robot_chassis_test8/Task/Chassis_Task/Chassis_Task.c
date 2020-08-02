#include "Chassis_Task.h"
#include "chassis_behaviour.h"

#include "Gimbal_Task1.h"

#include "bsp_can.h"
#include "oled.h"
#include "robomaster_vcan.h"
#include "bsp_imu.h"

#include "arm_math.h"

/**********�����˶�����**********/
static chassis_move_t chassis_move;
		
/***********С���ݵ��̲����õ�����������**********/
extern imu_t      imu;


/**********�����˶���ʼ��**********/
static void Chassis_Init(chassis_move_t *chassis_move_init);

/**********�������ݸ���***********/
static void chassis_feedback_update(chassis_move_t *chassis_move_update);

/**********����״̬��ѡ��ͨ��ң�����Ŀ���**********/
static void chassis_set_mode(chassis_move_t *chassis_move_mode);

/**********����״̬�ı����������ĸı�static**********/
void chassis_mode_change_control_transit(chassis_move_t *chassis_move_transit);
	
/**********�������ø���ң����������**********/
static void chassis_set_contorl(chassis_move_t *chassis_move_control);

/**********����PID�����Լ��˶��ֽ�**********/
static void chassis_control_loop(chassis_move_t *chassis_move_control_loop);


void Chassis_Task(void const * argument)
{
  /* USER CODE BEGIN Chassis_Task */
	
//	printf("In Chassis_Task!\r\n");
	osDelay (CHASSIS_TASK_INIT_TIME);
	Chassis_Init (&chassis_move);
	//�˴�����Ҫ�ӵ��߼��
	
  /* Infinite loop */
  for(;;)
  {
		
		//ң��������״̬
    chassis_set_mode(&chassis_move);
		//ң����״̬�л����ݱ���
		chassis_mode_change_control_transit(&chassis_move);
		//�������ݸ���
		chassis_feedback_update(&chassis_move);		
		//���̿���������
		chassis_set_contorl(&chassis_move);
		//���̿���PID����
    chassis_control_loop(&chassis_move);
		
		set_motor_voltage_CAN1(2, 													//���õ���ٶ�		
										(uint16_t)chassis_move.motor_chassis[0].give_current, 
										(uint16_t)chassis_move.motor_chassis[1].give_current, 
										(uint16_t)chassis_move.motor_chassis[2].give_current, 
										(uint16_t)chassis_move.motor_chassis[3].give_current);
		
		 		
//		wave_form_data[1] = chassis_move.chassis_yaw;
//		wave_form_data[2] = chassis_move.wz;
//		wave_form_data[3] = chassis_move.wz_set;
//   	wave_form_data[4] = gimbal_control.gimbal_rc_ctrl->switch_right;
		
		HAL_GPIO_TogglePin(GPIOG, LED2_Pin);
		osDelay(CHASSIS_CONTROL_TIME_MS);
	}
  /* USER CODE END Chassis_Task */
}



/**********�����˶���ʼ������**********/
static void Chassis_Init(chassis_move_t *chassis_move_init)
{
	if (chassis_move_init == NULL)	{return;}
		
	  const static fp32 chassis_x_order_filter[1] = {CHASSIS_ACCEL_X_NUM};
    const static fp32 chassis_y_order_filter[1] = {CHASSIS_ACCEL_Y_NUM};
    uint8_t i;
		
    //���̿���״̬Ϊֹͣ
    chassis_move_init->chassis_mode = CHASSIS_VECTOR_RAW;
		//��ȡң����ָ��
    chassis_move_init->chassis_RC = get_remote_control_point();
//    //��ȡ��������̬��ָ��
    chassis_move_init->chassis_INS_angle = get_INS_angle_point();
		    //��ȡ��̨�������ָ��
    chassis_move_init->chassis_yaw_motor = get_yaw_motor_point();
    chassis_move_init->chassis_pitch_motor = get_pitch_motor_point();
		
		//��ʼ��PID�˶�
		for(i=0;i<4;i++)
		{
			chassis_move_init->motor_chassis[i].chassis_motor_measure = get_Chassis_Motor_Measure_Point(i);
			pid_init(&chassis_move_init->motor_speed_pid[i],
								M3508_MOTOR_SPEED_PID_KP,
								M3508_MOTOR_SPEED_PID_KI,
								M3508_MOTOR_SPEED_PID_KP,
								M3508_MOTOR_SPEED_PID_MAX_IOUT,
								M3508_MOTOR_SPEED_PID_MAX_OUT);
		}		
		
		//��ʼ����תPID
    pid_init(&chassis_move_init->chassis_angle_pid, 
							CHASSIS_FOLLOW_GIMBAL_PID_KP,
							CHASSIS_FOLLOW_GIMBAL_PID_KI,
							CHASSIS_FOLLOW_GIMBAL_PID_KD,
							CHASSIS_FOLLOW_GIMBAL_PID_MAX_IOUT,
							CHASSIS_FOLLOW_GIMBAL_PID_MAX_OUT);
    //��һ���˲�����б����������
    first_order_filter_init(&chassis_move_init->chassis_cmd_slow_set_vx, CHASSIS_CONTROL_TIME, chassis_x_order_filter);
    first_order_filter_init(&chassis_move_init->chassis_cmd_slow_set_vy, CHASSIS_CONTROL_TIME, chassis_y_order_filter);

		chassis_move_init->vx_max_speed = NORMAL_MAX_CHASSIS_SPEED_X;
    chassis_move_init->vx_min_speed = -NORMAL_MAX_CHASSIS_SPEED_X;
		
		chassis_move_init->vy_max_speed = NORMAL_MAX_CHASSIS_SPEED_Y;
    chassis_move_init->vy_min_speed = -NORMAL_MAX_CHASSIS_SPEED_Y;
		
		//����һ������
    chassis_feedback_update(chassis_move_init);
}


static void chassis_feedback_update(chassis_move_t *chassis_move_update)
{
	if (chassis_move_update == NULL)	{return;}

    uint8_t i = 0;
    for (i = 0; i < 4; i++)
    {
			//���µ���ٶȣ����ٶ����ٶȵ�PID΢��
			chassis_move_update->motor_chassis[i].speed = CHASSIS_MOTOR_RPM_TO_VECTOR_SEN * chassis_move_update->motor_chassis[i].chassis_motor_measure->rotor_speed;
			chassis_move_update->motor_chassis[i].accel = (chassis_move_update->motor_speed_pid[i].err[0] - chassis_move_update->motor_speed_pid[i].err[1]) * CHASSIS_CONTROL_FREQUENCE;
    }

    //���µ���ǰ���ٶ� x�� ƽ���ٶ�y����ת�ٶ�wz������ϵΪ����ϵ
    chassis_move_update->vx = (-chassis_move_update->motor_chassis[0].speed + chassis_move_update->motor_chassis[1].speed + chassis_move_update->motor_chassis[2].speed - chassis_move_update->motor_chassis[3].speed) * MOTOR_SPEED_TO_CHASSIS_SPEED_VX;
    chassis_move_update->vy = (-chassis_move_update->motor_chassis[0].speed - chassis_move_update->motor_chassis[1].speed + chassis_move_update->motor_chassis[2].speed + chassis_move_update->motor_chassis[3].speed) * MOTOR_SPEED_TO_CHASSIS_SPEED_VY;
    chassis_move_update->wz = (-chassis_move_update->motor_chassis[0].speed - chassis_move_update->motor_chassis[1].speed - chassis_move_update->motor_chassis[2].speed - chassis_move_update->motor_chassis[3].speed) * MOTOR_SPEED_TO_CHASSIS_SPEED_WZ / MOTOR_DISTANCE_TO_CENTER;

//    //���������̬�Ƕ�, �����������������������ⲿ�ִ���
		//��������İ�װ��ʽ����Ҫ��yaw��ȡ�� NEGATION_COEFFICIENT
    chassis_move_update->chassis_yaw = rad_format(*(chassis_move_update->chassis_INS_angle + INS_YAW_ADDRESS_OFFSET)*NEGATION_COEFFICIENT) - 
																										chassis_move_update->chassis_yaw_motor->relative_angle;
    chassis_move_update->chassis_pitch = rad_format(*(chassis_move_update->chassis_INS_angle + INS_PITCH_ADDRESS_OFFSET)) - 
																											chassis_move_update->chassis_pitch_motor->relative_angle;
		
    chassis_move_update->chassis_roll = *(chassis_move_update->chassis_INS_angle + INS_ROLL_ADDRESS_OFFSET);

}

//ң���������ݴ���ɵ��̵�ǰ��vx�ٶȣ�vy�ٶ�ע�����ﻻ�����m/s
void chassis_rc_to_control_vector(fp32 *vx_set, fp32 *vy_set, chassis_move_t *chassis_move_rc_to_vector)
{
    if (chassis_move_rc_to_vector == NULL || vx_set == NULL || vy_set == NULL)
    {
        return;
    }
    //ң����ԭʼͨ��ֵ
    int16_t vx_channel, vy_channel;
    fp32 vx_set_channel, vy_set_channel;
		//��ʱΪch1��ch2
    //�������ƣ���Ϊң�������ܴ��ڲ��� ҡ�����м䣬��ֵ��Ϊ0 
		rc_deadline_limit(chassis_move_rc_to_vector->chassis_RC->ch1,vx_channel,CHASSIS_RC_DEADLINE);
		rc_deadline_limit(chassis_move_rc_to_vector->chassis_RC->ch2,vy_channel,CHASSIS_RC_DEADLINE);
		
    vx_set_channel = vx_channel * CHASSIS_VX_RC_SEN;
    vy_set_channel = vy_channel * -CHASSIS_VY_RC_SEN;

    if (chassis_move_rc_to_vector->chassis_RC->keyBoard.key_code & CHASSIS_FRONT_KEY)
    {
        vx_set_channel = chassis_move_rc_to_vector->vx_max_speed;
    }
    else if (chassis_move_rc_to_vector->chassis_RC->keyBoard.key_code & CHASSIS_BACK_KEY)
    {
        vx_set_channel = chassis_move_rc_to_vector->vx_min_speed;
    }

    if (chassis_move_rc_to_vector->chassis_RC->keyBoard.key_code & CHASSIS_LEFT_KEY)
    {
        vy_set_channel = chassis_move_rc_to_vector->vy_max_speed;
    }
    else if (chassis_move_rc_to_vector->chassis_RC->keyBoard.key_code & CHASSIS_RIGHT_KEY)
    {
        vy_set_channel = chassis_move_rc_to_vector->vy_min_speed;
    }

    //һ�׵�ͨ�˲�����б����Ϊ�����ٶ�����
    first_order_filter_cali(&chassis_move_rc_to_vector->chassis_cmd_slow_set_vx, vx_set_channel);
    first_order_filter_cali(&chassis_move_rc_to_vector->chassis_cmd_slow_set_vy, vy_set_channel);

    //ֹͣ�źţ�����Ҫ�������٣�ֱ�Ӽ��ٵ���
    if (vx_set_channel < CHASSIS_RC_DEADLINE * CHASSIS_VX_RC_SEN && vx_set_channel > -CHASSIS_RC_DEADLINE * CHASSIS_VX_RC_SEN)
    {
        chassis_move_rc_to_vector->chassis_cmd_slow_set_vx.out = 0.0f;
    }

    if (vy_set_channel < CHASSIS_RC_DEADLINE * CHASSIS_VY_RC_SEN && vy_set_channel > -CHASSIS_RC_DEADLINE * CHASSIS_VY_RC_SEN)
    {
        chassis_move_rc_to_vector->chassis_cmd_slow_set_vy.out = 0.0f;
    }

    *vx_set = chassis_move_rc_to_vector->chassis_cmd_slow_set_vx.out;
    *vy_set = chassis_move_rc_to_vector->chassis_cmd_slow_set_vy.out;
		
}


static void chassis_set_mode(chassis_move_t *chassis_move_mode)
{
    if (chassis_move_mode == NULL)	{return;}
    chassis_behaviour_mode_set(chassis_move_mode);
}

static void chassis_mode_change_control_transit(chassis_move_t *chassis_move_transit)
{
    if (chassis_move_transit == NULL)	{return;}

    if (chassis_move_transit->last_chassis_mode == chassis_move_transit->chassis_mode)	{return;}

    //���������̨ģʽ
    if ((chassis_move_transit->last_chassis_mode != CHASSIS_VECTOR_FOLLOW_GIMBAL_YAW) && chassis_move_transit->chassis_mode == CHASSIS_VECTOR_FOLLOW_GIMBAL_YAW)
    {
        chassis_move_transit->chassis_relative_angle_set = 0.0f;//rad
    }
    //���������̽Ƕ�ģʽ
    else if ((chassis_move_transit->last_chassis_mode != CHASSIS_VECTOR_FOLLOW_CHASSIS_YAW) && chassis_move_transit->chassis_mode == CHASSIS_VECTOR_FOLLOW_CHASSIS_YAW)
    {
        chassis_move_transit->chassis_yaw_set = chassis_move_transit->chassis_yaw;//rad
    }
    //���벻������̨ģʽ
    else if ((chassis_move_transit->last_chassis_mode != CHASSIS_VECTOR_NO_FOLLOW_YAW) && chassis_move_transit->chassis_mode == CHASSIS_VECTOR_NO_FOLLOW_YAW)
    {
        chassis_move_transit->chassis_yaw_set = chassis_move_transit->chassis_yaw;//rad
    }

    chassis_move_transit->last_chassis_mode = chassis_move_transit->chassis_mode;
}

//����ң�������������
static void chassis_set_contorl(chassis_move_t *chassis_move_control)
{
	 if (chassis_move_control == NULL)	{return;}
	   //�����ٶ�
    fp32 vx_set = 0.0f, vy_set = 0.0f, angle_set = 0.0f;
    chassis_behaviour_control_set(&vx_set, &vy_set, &angle_set, chassis_move_control);
	 
	    //������̨ģʽ
    if (chassis_move_control->chassis_mode == CHASSIS_VECTOR_FOLLOW_GIMBAL_YAW)
    {
			fp32 sin_yaw = 0.0f, cos_yaw = 0.0f;
			//��ת���Ƶ����ٶȷ��򣬱�֤ǰ����������̨�����������˶�ƽ��
			sin_yaw = arm_sin_f32(-chassis_move_control->chassis_yaw_motor->relative_angle);
			cos_yaw = arm_cos_f32(-chassis_move_control->chassis_yaw_motor->relative_angle);
			chassis_move_control->vx_set = cos_yaw * vx_set + sin_yaw * vy_set;
			chassis_move_control->vy_set = -sin_yaw * vx_set + cos_yaw * vy_set;
			//���ÿ��������̨�Ƕ�
			chassis_move_control->chassis_relative_angle_set = rad_format(angle_set);
			
			//������תPID���ٶ�
			chassis_move_control->wz_set = -pid_calc(&chassis_move_control->chassis_angle_pid,
																								chassis_move_control->chassis_relative_angle_set,
																								chassis_move_control->chassis_yaw_motor->relative_angle);
			//�ٶ��޷�
			chassis_move_control->vx_set = fp32_constrain(chassis_move_control->vx_set, chassis_move_control->vx_min_speed, chassis_move_control->vx_max_speed);
			chassis_move_control->vy_set = fp32_constrain(chassis_move_control->vy_set, chassis_move_control->vy_min_speed, chassis_move_control->vy_max_speed);
    }
    else if (chassis_move_control->chassis_mode == CHASSIS_VECTOR_FOLLOW_CHASSIS_YAW)
    {
			fp32 delat_angle = 0.0f;
			//����������̨
			//���õ��̿��ƵĽǶ�
			chassis_move_control->chassis_yaw_set = rad_format(angle_set);
			delat_angle = rad_format(chassis_move_control->chassis_yaw_set - chassis_move_control->chassis_yaw);
			//������ת�Ľ��ٶ�
			chassis_move_control->wz_set = pid_calc(&chassis_move_control->chassis_angle_pid, delat_angle, 0.0f);
			//���õ����˶����ٶ�
			chassis_move_control->vx_set = fp32_constrain(vx_set, chassis_move_control->vx_min_speed, chassis_move_control->vx_max_speed);
			chassis_move_control->vy_set = fp32_constrain(vy_set, chassis_move_control->vy_min_speed, chassis_move_control->vy_max_speed);
    }
    else if (chassis_move_control->chassis_mode == CHASSIS_VECTOR_NO_FOLLOW_YAW)
    {
			//����������̨
			//���ģʽ�£��Ƕ����õ�Ϊ ���ٶ�
			fp32 chassis_wz = angle_set;
			chassis_move_control->wz_set = chassis_wz;
			chassis_move_control->vx_set = fp32_constrain(vx_set, chassis_move_control->vx_min_speed, chassis_move_control->vx_max_speed);
			chassis_move_control->vy_set = fp32_constrain(vy_set, chassis_move_control->vy_min_speed, chassis_move_control->vy_max_speed);
    }
    else if (chassis_move_control->chassis_mode == CHASSIS_VECTOR_RAW)
    {
			chassis_move_control->vx_set = vx_set;
			chassis_move_control->vy_set = vy_set;
			chassis_move_control->wz_set = angle_set;
			chassis_move_control->chassis_cmd_slow_set_vx.out = 0.0f;
			chassis_move_control->chassis_cmd_slow_set_vy.out = 0.0f;
    }

}

static void chassis_vector_to_mecanum_wheel_speed(const fp32 vx_set, const fp32 vy_set, const fp32 wz_set, fp32 wheel_speed[4])
{
    //��ת��ʱ�� ������̨��ǰ��������ǰ������ 0 ��1 ��ת���ٶȱ����� �������� 2,3 ��ת���ٶȱ��
		wheel_speed[0] = +vx_set - vy_set + (CHASSIS_WZ_SET_SCALE - 1.0f) * MOTOR_DISTANCE_TO_CENTER * wz_set;
    wheel_speed[1] = +vx_set + vy_set + (CHASSIS_WZ_SET_SCALE - 1.0f) * MOTOR_DISTANCE_TO_CENTER * wz_set;
    wheel_speed[2] = -vx_set - vy_set + (-CHASSIS_WZ_SET_SCALE - 1.0f) * MOTOR_DISTANCE_TO_CENTER * wz_set;
    wheel_speed[3] = -vx_set + vy_set + (-CHASSIS_WZ_SET_SCALE - 1.0f) * MOTOR_DISTANCE_TO_CENTER * wz_set;
}


static void chassis_control_loop(chassis_move_t *chassis_move_control_loop)
{
    fp32 max_vector = 0.0f, vector_rate = 0.0f;
    fp32 temp = 0.0f;
    fp32 wheel_speed[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    uint8_t i = 0;
		
		
    //�����˶��ֽ�
    chassis_vector_to_mecanum_wheel_speed(chassis_move_control_loop->vx_set,
                                          chassis_move_control_loop->vy_set, 
																					chassis_move_control_loop->wz_set, 
																					wheel_speed);

    if (chassis_move_control_loop->chassis_mode == CHASSIS_VECTOR_RAW)
    {
        //��ֵ����ֵ
        for (i = 0; i < 4; i++)
        {
            chassis_move_control_loop->motor_chassis[i].give_current = (int16_t)(wheel_speed[i]);
        }
        //raw����ֱ�ӷ���
        return;
    }

    //�������ӿ�������ٶȣ�������������ٶ�
    for (i = 0; i < 4; i++)
    {
        chassis_move_control_loop->motor_chassis[i].speed_set = wheel_speed[i];
        temp = fabs(chassis_move_control_loop->motor_chassis[i].speed_set);
        if (max_vector < temp)
        {
            max_vector = temp;
        }
    }
		
    if (max_vector > MAX_WHEEL_SPEED)
    {
        vector_rate = MAX_WHEEL_SPEED / max_vector;
        for (i = 0; i < 4; i++)
        {
            chassis_move_control_loop->motor_chassis[i].speed_set *= vector_rate;
        }
    }

    for (i = 0; i < 4; i++)
    {
        chassis_move_control_loop->motor_chassis[i].give_current = 
					(int16_t)pid_calc(&chassis_move_control_loop->motor_speed_pid[i], chassis_move_control_loop->motor_chassis[i].speed_set, chassis_move_control_loop->motor_chassis[i].speed);
    }
}


