#include "Revolver_Task.h"
#include "Gimbal_Task1.h"
#include "Chassis_Task.h"

#include "user_lib.h"

#include "arm_math.h"
#include "robomaster_vcan.h"


static int16_t UP_Set_Current = 0, DOWN_Set_Current = 0;
static int16_t PAN_TRIGGER_Set_Current = 0,TRIGGER_Set_Current = 0;
/***********************************************START***********************************************/
/*���ܴ������ƣ�*/
Shooting_Control_t shooting_control;
static void Shooting_Initial(Shooting_Control_t *shooting_init);
static void Shooting_feedback_update(Shooting_Control_t *shooting_update);
static void Shooting_set_contorl(Shooting_Control_t *shooting_run_control);
static void Shooting_control_loop(Shooting_Control_t *shooting_run_control_loop);
static void Shooting_Motor_set(Shooting_Control_t *shooting_motor_set);
/***********************************************END***************************************************/

void Revolver_Task(void const * argument)
{
//	printf("In Revolver_Task!\n");
	osDelay(REVOLVER_TASK_INIT_TIME);
	Shooting_Initial(&shooting_control);
	
	for(;;)
	{
		Shooting_feedback_update(&shooting_control);
		Shooting_set_contorl(&shooting_control);
		Shooting_control_loop(&shooting_control);
		Shooting_Motor_set(&shooting_control);
		
		HAL_GPIO_TogglePin(GPIOG, LED4_Pin);
		osDelay(REVOLVER_CONTROL_TIME_MS);
		
		wave_form_data[0] = shooting_control.shooting_up_motor.shooting_motor_measure->rotor_speed;
		wave_form_data[1] = shooting_control.shooting_down_motor.shooting_motor_measure->rotor_speed;
//		wave_form_data[3] = TRIGGER_Set_Current;
		shanwai_send_wave_form();	
	}
}

	/**********************************************************************************************************
*�� �� ��:Shooting_Initial(Shooting_Control_t *shooting_init)
*����˵��:ǹ�ܳ�ʼ��
*��    ��:shooting_init
*�� �� ֵ:NULL
*����:		������
**********************************************************************************************************/
static void Shooting_Initial(Shooting_Control_t *shooting_init)
{
	if(shooting_init == NULL)	
	{
		return;
	}
	//��ȡң����ָ��
  shooting_init->shooting_RC = get_remote_control_point();
	
	//����Ħ����
	shooting_init->shooting_up_motor.shooting_motor_measure = get_Shooting_Up_Motor_Measure_Point();
	shooting_init->shooting_down_motor.shooting_motor_measure = get_Shooting_Down_Motor_Measure_Point();
	
		
	//��������͵��ֵ������ָ���ȡ
	shooting_init->pan_trigger_motor.shooting_motor_measure = get_PAN_Trigger_Motor_Measure_Point();
	shooting_init->trigger_motor.shooting_motor_measure = get_Trigger_Motor_Measure_Point();
	
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
	//���ֵ������
	pid_init(&shooting_init->pan_trigger_pid,
						PAN_TRIGGER_PID_KP,
						PAN_TRIGGER_PID_KI,
						PAN_TRIGGER_PID_KD,
						PAN_TRIGGER_PID_MAX_IOUT,
						PAN_TRIGGER_PID_MAX_OUT);
	//����������					׼��̬pid
	pid_init(&shooting_init->trigger_pid,
						TRIGGER_ANGLE_PID_KP,
						TRIGGER_ANGLE_PID_KI,
						TRIGGER_ANGLE_PID_KD,
						TRIGGER_ANGLE_PID_MAX_IOUT,
						TRIGGER_ANGLE_PID_MAX_OUT);
							
	 //��һ���˲�����б����������
  first_order_filter_init(&shooting_init->shooting_cmd_slow_set_up, REVOLVER_CONTROL_TIME, shooting_up_order_filter);
  first_order_filter_init(&shooting_init->shooting_cmd_slow_set_down, REVOLVER_CONTROL_TIME, shooting_down_order_filter);
	
	shooting_init->shooting_speed_up_set = SPEED_NUM_UP_0;
	shooting_init->shooting_speed_down_set = SPEED_NUM_DOWN_0;
	shooting_init->pan_trigger_speed_set =  SPEED_NUM_UP_0;
	shooting_init->trigger_speed_set = SPEED_NUM_UP_0;
	
	//�ʼʱ��������ǽ�ֹ�����
	shooting_init->shooting_mode = SHOOTING_FORBID;

	//��������������ͳ�ʼ������
	shooting_init->ball_num_last = 0;
	shooting_init->ball_num_limit = BALL_MAX;
	//��������ſ���ʱ��
	shooting_init->key_time = 0;
	//����һ������
  Shooting_feedback_update(shooting_init);
	//�����õ�
	HAL_GPIO_WritePin(GPIOG, LED6_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOG, LED7_Pin, GPIO_PIN_SET);
	
}
/**********************************************************************************************************
*�� �� ��:Shooting_feedback_update(Shooting_Control_t *shooting_update)
*����˵��:����ǹ������,���Ӿ���Ϣ
*��    ��:shooting_update
*�� �� ֵ:NULL
*����:		������
**********************************************************************************************************/
static void Shooting_feedback_update(Shooting_Control_t *shooting_update)
{
	if(shooting_update == NULL)	
	{
		return;
	}
	shooting_update->shooting_up_speed = shooting_update->shooting_up_motor.shooting_motor_measure->rotor_speed;
	shooting_update->shooting_down_speed = shooting_update->shooting_down_motor.shooting_motor_measure->rotor_speed;
	
	/*�������Է��ص��ֵ*/
	shooting_update->pan_trigger_speed = shooting_update->pan_trigger_motor.shooting_motor_measure->rotor_speed;
	shooting_update->pan_trigger_angle = shooting_update->pan_trigger_motor.shooting_motor_measure->rotor_angle;
	shooting_update->trigger_speed = shooting_update->trigger_motor.shooting_motor_measure->rotor_speed;
	shooting_update->trigger_angle = shooting_update->trigger_motor.shooting_motor_measure->rotor_angle;
	
	/***********************************************START***********************************************/
  /*���ܴ������ƣ����ֹ�������*/
	//������жϸ���
	shooting_update->key_up = LIMIT_UP_JUDGE;
	shooting_update->key_down = LIMIT_DOWN_JUDGE;
	
	//���Ϲ���ŵĿ���ʱ���ʱ
	if(shooting_update->key_up == 0)
	{
		shooting_update->key_time++;
	}
	//���¹���ŵĿ���ʱ���ʱ
	if(shooting_update->key_down == 0)
	{
		shooting_update->run_time++;
	}
  /***********************************************END***************************************************/

}
/**********************************************************************************************************
*�� �� ��:Shooting_set_contorl(Shooting_Control_t *shooting_run_control)
*����˵��:NULL
*��    ��:shooting_run_control
*�� �� ֵ:NULL
*����:		������
**********************************************************************************************************/
static void Shooting_set_contorl(Shooting_Control_t *shooting_run_control)
{
	if(shooting_run_control == NULL)	
	{
		return;
	}	
	//��һ�����ϲ��ǿ������ڶ����ǹر�
	static int8_t last_s = RC_SW_UP;
	if((switch_is_up(shooting_run_control->shooting_RC->switch_right) && 
			!switch_is_up(last_s) && 
			shooting_run_control->shooting_mode == SHOOTING_FORBID))
	{
		shooting_run_control->shooting_mode = SHOOTING_READY;
		HAL_GPIO_WritePin(GPIOG, LED6_Pin, GPIO_PIN_RESET);
	}
	else if
		(switch_is_up(shooting_run_control->shooting_RC->switch_right) && 
		!switch_is_up(last_s) && 
		shooting_run_control->shooting_mode !=SHOOTING_FORBID)
	{
		shooting_run_control->shooting_mode = SHOOTING_FORBID;
		HAL_GPIO_WritePin(GPIOG, LED6_Pin, GPIO_PIN_SET);
	}
	last_s = shooting_run_control->shooting_RC->switch_right;
		
	
	if(shooting_run_control->shooting_mode == SHOOTING_FORBID)
	{
		shooting_run_control->pan_trigger_speed_set = 0.0f;
		shooting_run_control->trigger_speed_set = 0.0f;
		
		shooting_run_control->shooting_speed_up_set = SPEED_NUM_UP_0;
		shooting_run_control->shooting_speed_down_set = SPEED_NUM_DOWN_0;
		
	}
	else if(shooting_run_control->shooting_mode == SHOOTING_READY)//׼��̬ʱ���õ��ֵ�����й�����Ħ�������������治��
	{
		//����Ħ����
		shooting_run_control->shooting_speed_up_set = SPEED_NUM_UP_1;
		shooting_run_control->shooting_speed_down_set = SPEED_NUM_DOWN_1;	
		
		//����ż�ʱ����400msʱ������Ϊ��ʱ�����ٹ���
		if(shooting_run_control->key_time >= 100)
		{
			shooting_run_control->pan_trigger_speed_set = 0;//ֹͣ���ֵ������
			shooting_run_control->shooting_mode = SHOOTING_ALLOWED;
		}
		else
		{
			shooting_run_control->pan_trigger_speed_set = PAN_TRIGGER_SPEED;//���������ʹ����һֱ����
		}
	}

//	if(shooting_run_control->shooting_mode == SHOOTING_ALLOWED)//��Ԥ��̬�²�������	
//	{	
//		
//	}	
	
		//��Ԥ������£�ͨ�����ϰ�ť���Ʋ���
		if(switch_is_up(remote_control.switch_left))
		{
			int i=0;
			i++;
			if(i >= 80)
			{
				shooting_run_control->trigger_speed_set = 0;
				i = 0;
			}
			else
			{
				shooting_run_control->trigger_speed_set = TRIGGER_SPEED;
			}
			shooting_run_control->key_time = 0;
			shooting_run_control->shooting_mode = SHOOTING_READY; //���굯�����½���׼��״̬
		}
		else
		{
			shooting_run_control->trigger_speed_set = 0;
		}
	
	
}


/**********************************************************************************************************
*�� �� ��:Shooting_control_loop(Shooting_Control_t *shooting_run_control_loop);
*����˵��:NULL
*��    ��:shooting_run_control_loop
*�� �� ֵ:NULL
*����:		������
**********************************************************************************************************/
static void Shooting_control_loop(Shooting_Control_t *shooting_run_control_loop)
{
	if(shooting_run_control_loop == NULL)	
	{
		return;
	}
	//Ħ����
	shooting_run_control_loop->shooting_up_motor.given_current = 
					(int16_t)pid_calc(&shooting_run_control_loop->shooting_speed_up_pid, 
														shooting_run_control_loop->shooting_speed_up_set, 
														shooting_run_control_loop->shooting_up_speed);
	
	shooting_run_control_loop->shooting_down_motor.given_current = 
					(int16_t)pid_calc(&shooting_run_control_loop->shooting_speed_down_pid, 
														shooting_run_control_loop->shooting_speed_down_set, 
														-shooting_run_control_loop->shooting_down_speed);
	
	shooting_run_control_loop->pan_trigger_motor.given_current =
					(int16_t)pid_calc(&shooting_run_control_loop->pan_trigger_pid, 
														shooting_run_control_loop->pan_trigger_speed_set, 
														shooting_run_control_loop->pan_trigger_motor.shooting_motor_measure ->rotor_speed);
//�������
	shooting_run_control_loop->trigger_motor.given_current = 
					(int16_t)pid_calc(&shooting_run_control_loop->trigger_pid, 
														shooting_run_control_loop->trigger_speed_set, 
														shooting_run_control_loop->trigger_motor.shooting_motor_measure->rotor_speed);
}

/**********************************************************************************************************
*�� �� ��:Shooting_Motor_set(Shooting_Control_t *shooting_motor_set)
*����˵��:���õ������ֵ
*��    ��:Nshooting_motor_set
*�� �� ֵ:NULL
*����:		������
**********************************************************************************************************/
static void Shooting_Motor_set(Shooting_Control_t *shooting_motor_set)
{
	if(shooting_motor_set == NULL)	
	{
		return;
	}	
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

	//������
	#if TRIGGER_TURN
		TRIGGER_Set_Current = -shooting_motor_set->trigger_motor.given_current;
	#else
		TRIGGER_Set_Current = shooting_motor_set->trigger_motor.given_current;
	#endif	
	
	#if PAN_TRIGGER_TURN
		PAN_TRIGGER_Set_Current = -shooting_motor_set->pan_trigger_motor.given_current;
	#else
		PAN_TRIGGER_Set_Current = shooting_motor_set->pan_trigger_motor.given_current;
	#endif	
//	if(shooting_motor_set->shooting_RC->switch_right == 2)
	if(shooting_motor_set->shooting_mode == SHOOTING_FORBID)
	{
		set_motor_voltage_CAN2(2, 													//���õ���ٶ�
							0, 
							0, 
							0, 
							0);
	}
//	else if(shooting_motor_set->shooting_RC->switch_right == 3)
	else
	{
		set_motor_voltage_CAN2(2, 													//���õ���ٶ�
							0, 			/*������*/
							DOWN_Set_Current,		 	/**/
							UP_Set_Current, 			/**/
							0);
		set_motor_voltage_CAN2(0, 													//���õ���ٶ�
					0, 			/*������*/
					0,		 	/**/
					TRIGGER_Set_Current, 			/**/
					0);//TRIGGER_Set_Current
		
		set_motor_voltage_CAN1(0, 													//���õ���ٶ�
							0, 
							0, 
							PAN_TRIGGER_Set_Current, 	/*�������*/
							0);
	}
}

/***********************************************END***************************************************/

