#include "robomaster_task.h"
#include "mpu9250.h"
#include "robomaster_common.h"


/**
  * @brief  TIM2�жϴ�������Ҫ���еĳ���5MSִ��һ��
  * @param  ��
  * @retval 
  * @usage  ���ڵ��̵����������imu���е��̿��ƣ����ڿ�������è��        
  *               
  */
int	cnt1=0,cnt2=0;
float mypitch=0.0,myroll=0.0,myyaw=0.0;
int testmpu;
int init_yaw=0;

void task() 
{	
	cnt1++;	
	Bling_Working(Bling_Mode);
	mpu_get_data();//���imuԭʼ����
	imu_ahrs_update(&imu);//������Ԫ����imu��̬	
	GetDistance();//��ȡ����
	Acquire1();  //ȡ����
	Acquire2();  //ȡС����
	if(robot_status.anomaly==NORMAL)
	{	
  Electromagnet_save();  //�������Ԯ
	Card_save();        //��Ԯ����Ԯ
	Ammunition_feed1();  //���
	Ammunition_feed2(); //��С��
	chassis_control();//���̿���+��̨����      Cģʽ�л�(��һ���л����ٰ��ջ�)
		
	}
   robot_status_detection();
}


