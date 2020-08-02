#ifndef __ROBOMASTER_VISION_H
#define __ROBOMASTER_VISION_H
#include "bsp_headfile.h"


#define VISION_DETECT 1 //ʹ���Ӿ�ʶ��
#define ENEMYDATABUFFERLENGHT   60 //���������
#define ARMOUR_OFFSET -0.02F //�з�װ���������̨y���ƫ�� ��λm
#define VISION_YAW_TARGET 333 //�Ӿ�yaw��Ŀ��ֵ
#define VISION_PIT_TARGET 309 //�Ӿ�pit��Ŀ��ֵ
//�Ƕ����ݽṹ
typedef struct
{
		int16_t origin_yaw;
		int16_t origin_pitch;
    int16_t Yaw_Err;//yawƫ��
    int16_t Pitch_Err;
		int16_t VX;
		int16_t VY;
		int16_t HEIGHT;
		uint16_t Forcast_X;//��Ӧ��̨��YAW
		uint16_t Forcast_Y;//��Ӧ����̨��PIT
		uint16_t Forcast_Z;//��Ӧ����������װ�׵ľ���
}Angle_Err_Struct;
////�����ݽṹ
//typedef struct
//{
//    int16_t X;
//    int16_t Y;
//    int16_t Z;
//}Point_Struct;

typedef struct
{
    Angle_Err_Struct pan_tilt_angel_err;//��̨��װ�װ��yaw��pitch��ƫ��
	uint16_t distance;//���ղ�ഫ�����ľ��� ��λmm
	char recognition_success_flag; //ʶ��ɹ���־λ
	int check_sum;//���������Ƿ���ȷ
	uint32_t last_time;//��һ֡�����Ӿ���ʱ��
	uint32_t current_time;//��ʱ�����Ӿ���ʱ��
	uint16_t delta_time;//������֡���ݵļ��ʱ�� ms
	uint8_t vision_frame;//�Ӿ�֡��
		
}Vision_Attack;
////�Ӿ����ݽṹ
//typedef struct
//{
//    uint16_t X;//��Ӧ��̨��YAW
//	uint16_t Y;//��Ӧ����̨��PIT
//	fp32  	 Z;//��Ӧ����������װ�׵ľ��� 
//	int16_t VX;//YAW��ƽ���ٶ�
//	int16_t VY;//PIT���ٶ�
//	int16_t VZ;
//	int16_t HEIGHT;//װ�װ�߶�
//    int TimeStamp;
//    int Time;
//    char ID;
//    uint32_t Tick;
//}Enemy_Struct;
extern Vision_Attack Armour_attack;
extern uint8_t UART6_Date[12];//����6����pid��������
void get_armour_err(void);
void armour_attack(void);
#endif

