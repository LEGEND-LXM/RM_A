#ifndef __Robot_Status_H
#define __Robot_Status_H
#ifdef __cplusplus
 extern "C" {
#endif
/***********************************************START***********************************************/
/*���ܴ������ƣ�������������̬������������ÿ�*/
#include "dji_remote.h"
/***********************************************END***************************************************/

typedef struct {
    float x;
    float y;
    float z;
} Vector3f_t;

	 
//typedef enum
//{
//	ROBOT_STATUS_INIT = 		0,		//������������ʼ��״̬
//	ROBOT_STATUS_STOPED = 	1,	//����������ֹͣ
//	ROBOT_STATUS_MOVING = 	2,	//�����������˶�
//	ROBOT_STATUS_KILLED = 	3,	//��������������
//	ROBOT_STATUS_FAILRUE = 	4,	//�������������ֹ���,Ŀ�ⲻ̫��Ҫ
//	
//} Robot_Status_e;	 
//	 
typedef struct
{
	uint8_t  init;           //��ʼ��״̬
	uint8_t  imu_status;		 //imu����״̬
	uint8_t  placement;      //����״̬
	
	uint8_t Robot_Status_mode;
	
}Robot_Status_t;
	 
//imu��ʼ��״̬
enum
{		
    HEATING,		        //������
    HEAT_FINISH,		    //�������
    INIT_FINISH             //��ʼ����� ����ɼ��ٶ���ƫ���㣩
};
//����״̬
enum
{		
    ROBOT_MOTIONAL,		    			//�˶�
		ROBOT_STATIC 		            //��ֹ
};
//Ӣ��
enum
{	
	HREO_INITIAL,         			 //��ʼ��ģʽ
	HERO_STANDBY,          		 		//��������״̬
	HERO_CHASSIS_FOLLOW_GIMBAL,   //���̸�����̨
};


extern Robot_Status_t robot_status;
extern Vector3f_t gyro_status;//������״̬�ṹ��
void Place_Staus_Check(Vector3f_t gyro_status);

#ifdef __cplusplus
}
#endif
#endif /*__Robot_Status_H */
