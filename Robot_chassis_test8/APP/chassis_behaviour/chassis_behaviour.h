#ifndef CHASSIS_BEHAVIOUR_H
#define CHASSIS_BEHAVIOUR_H
#include "main.h"
#include "chassis_task.h"

//���������ģʽ��ǩ
typedef enum
{
  CHASSIS_ZERO_FORCE,                  //��������
  CHASSIS_NO_MOVE,                     //���̱��ֲ���
  CHASSIS_INFANTRY_FOLLOW_GIMBAL_YAW,  //�����������̸�����̨
  CHASSIS_ENGINEER_FOLLOW_CHASSIS_YAW, //�����й��̵��̽Ƕȿ��Ƶ��̣����ڵ���δ�������ǣ��ʶ��Ƕ��Ǽ�ȥ��̨�Ƕȶ��õ�������е�������������µ��̵�yaw��pitch��roll�Ƕ�
  CHASSIS_NO_FOLLOW_YAW,               //���̲�����Ƕȣ��Ƕ��ǿ����ģ���ǰ�����������ٶȻ�
  CHASSIS_OPEN                         //ң������ֵ���Ա���ֱ�ӷ��͵�can������  ������
} chassis_behaviour_e;

#define CHASSIS_OPEN_RC_SCALE 10 //��chassis_open ģ���£�ң�������Ըñ������͵�can��

extern void chassis_behaviour_mode_set(chassis_move_t *chassis_move_mode);

extern void chassis_behaviour_control_set(fp32 *vx_set, fp32 *vy_set, fp32 *angle_set, chassis_move_t *chassis_move_rc_to_vector);

extern chassis_behaviour_e chassis_behaviour_mode;
#endif


