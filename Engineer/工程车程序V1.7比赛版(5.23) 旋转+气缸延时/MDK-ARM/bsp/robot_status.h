#ifndef __ROBOT_STATUS_
#define __ROBOT_STATUS_
#include "robomaster_common.h"
#include "vector3.h"

typedef struct
{
    uint8_t  init;           //��ʼ��״̬
    uint8_t  imu_status;		 //imu����״̬
		uint8_t	 anomaly;				 //�쳣���״̬
    uint8_t  armed;          //�������״̬
    uint8_t  placement;      //����״̬
    uint8_t  posControl;     //λ�ÿ���״̬
    uint8_t  mode;					 //��������ģʽ
    uint32_t initFinishTime; //��ʼ�����ʱ��
	  uint8_t  control_mode;    //С������ģʽ����Ϊң�������ƺͼ��̿���
		uint8_t  vision_mode;     //�Ӿ�ʶ��ģʽ  
		uint8_t  fric_mode;				//Ħ����ģʽ
		uint8_t  fric_control_mode; //Ħ���ֿ���ģʽ
		uint8_t  rammer_mode;			//������ģʽ
		uint8_t  gun_heat_state;  //ǹ������״̬
} ROBOT_STATUS_t;


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
    MOTIONAL,		    			//�˶�
		STATIC 		            //��ֹ
};

//�����˶�ģʽ
enum
{	
	INITIAL,         			 //��ʼ��ģʽ
	REMOTE_CONTROL,		        //ң��������
  KEYBOARD_CONTROL,		    	//���̿���
	STANDBY,          		 //���̴���״̬
	FOLLOW,           		 //���̸�����̨
	TWIST,             		 //Ť��
	KEY_BOARD_CONTROL			 //���̿���״̬
};
//�����쳣ģʽ
//ǹ������״̬
enum
{
    UNSUPER_HEAT = 0,//δ������
    SUPER_HEAT 	 //������
} ;
//������ģʽ
enum
{			
    SAFETY,						//��ȫģʽ
		SINGLE_SHOT,		    //����
		THRICE_SHOT,				//���Զ�,����M16 3����
		AUTO_SHOT						//�Զ�
};

//Ħ����ģʽ  ���������
enum
{		
		STOP,		        				//ֹͣ
    CLOSE_FIRE,							//�����Ƶ� 10m/s
		MID_FIRE,								//�г��Ƶ� 15m/s
		REMOTE_FIRE,						//Զ���Ƶ� 20m/s
		INTERCONTINENTAL_FIRE		//�޼��Ƶ� 28m/s
};
enum
{
	NORMAL,								 //����״̬
	REMOTE_CONTROL_OFFLINE,//ң��������
	CHASSIS_MOTOR_OFFLINE, //���̵������
	PAN_TILT_OFFLINE			 //��̨�������
	
};
extern ROBOT_STATUS_t robot_status;
void PlaceStausCheck(Vector3f_t gyro_status);
void robot_status_init(void);
void robot_status_detection(void);
#endif

