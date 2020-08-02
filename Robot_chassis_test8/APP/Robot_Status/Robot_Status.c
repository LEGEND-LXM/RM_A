#include "Robot_Status.h"

#include "Chassis_Task.h"
#include "chassis_behaviour.h"

#include "Gimbal_Task1.h"

Robot_Status_t robot_status;

static void Robot_Status_First_Select(Robot_Status_t *robot_status_first_select);
static void Robot_Status_Second_Select(Robot_Status_t *robot_status_second_select);

/**********************************************************************************************************
*�� �� ��:PlaceStausCheck
*����˵��:����״̬��⣺��ֹ���˶�
*��    ��:���ٶ�
*�� �� ֵ:NULL
*����:		�ܺ�
**********************************************************************************************************/
void Place_Staus_Check(Vector3f_t gyro_status)
{
    Vector3f_t gyroDiff;
    static Vector3f_t lastGyro;
    static float threshold = 1.0f;
    static uint16_t checkNum = 0;
    static int16_t count = 0;

    gyroDiff.x = gyro_status.x - lastGyro.x;
    gyroDiff.y = gyro_status.y - lastGyro.y;
    gyroDiff.z = gyro_status.z - lastGyro.z;
    lastGyro = gyro_status;

    if(count < 100)
    {
        count++;
        //��������ֵ�仯������ֵ
        if(int_abs(gyroDiff.x) > threshold || int_abs(gyroDiff.y) > threshold || int_abs(gyroDiff.z) > threshold)
        {
            checkNum++;
        }
    }
    else
    {
        //���������ݶ�����������һ��ֵʱ��Ϊ���������ھ�ֹ״̬
        if(checkNum > 1)
            robot_status.placement = ROBOT_MOTIONAL;
        else
            robot_status.placement = ROBOT_STATIC;

        checkNum = 0;
        count = 0;
    }
}

/**********************************************************************************************************
*�� �� ��:Robot_Status_First_Select(Robot_Status_t *robot_status)
*����˵��:��ֹ�˶�ģʽ,���ڵ�һ��ѡ��ѡ��
*��    ��:robot_status
*�� �� ֵ:NULL
*����:		������
**********************************************************************************************************/
static void Robot_Status_First_Select(Robot_Status_t *robot_status_first_select)
{
	if(robot_status_first_select == NULL)	
	{
		return;
	}
	
	if(switch_is_down(remote_control.switch_left))
	{
		robot_status_first_select->Robot_Status_mode = ROBOT_STATIC;
	}
	else if(switch_is_mid(remote_control.switch_left)||switch_is_up(remote_control.switch_left))
	{
		robot_status_first_select->Robot_Status_mode = ROBOT_MOTIONAL;
	}
}

/**********************************************************************************************************
*�� �� ��:Robot_Status_Second_Select(Robot_Status_t *robot_status_second_select)
*����˵��:��̨���̵ڶ���ģʽѡ��
*��    ��:NULL
*�� �� ֵ:NULL
*����:		������
**********************************************************************************************************/
static void Robot_Status_Second_Select(Robot_Status_t *robot_status_second_select)
{
	if(robot_status_second_select == NULL)	
	{
		return;
	}
	
	if(robot_status_second_select->Robot_Status_mode == ROBOT_STATIC)
	{
		chassis_behaviour_mode = CHASSIS_ZERO_FORCE;
		gimbal_control.Gimbal_Motor_mode = GIMBAL_ZERO_FORCE;
	}else if(robot_status_second_select->Robot_Status_mode == ROBOT_MOTIONAL)
	{
		chassis_behaviour_mode = CHASSIS_INFANTRY_FOLLOW_GIMBAL_YAW;
		gimbal_control.Gimbal_Motor_mode = GIMBAL_MIXED_AB_RE_ANGLE;
	}
}

