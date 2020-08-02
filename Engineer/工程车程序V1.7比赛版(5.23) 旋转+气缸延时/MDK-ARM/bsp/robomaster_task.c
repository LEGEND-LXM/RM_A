#include "robomaster_task.h"
#include "mpu9250.h"
#include "robomaster_common.h"


/**
  * @brief  TIM2中断处理函数主要运行的程序，5MS执行一次
  * @param  无
  * @retval 
  * @usage  用于底盘的驱动，结合imu进行底盘控制，后期可用来走猫步        
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
	mpu_get_data();//获得imu原始数据
	imu_ahrs_update(&imu);//更新四元数和imu姿态	
	GetDistance();//获取距离
	Acquire1();  //取大弹丸
	Acquire2();  //取小弹丸
	if(robot_status.anomaly==NORMAL)
	{	
  Electromagnet_save();  //电磁铁救援
	Card_save();        //救援卡救援
	Ammunition_feed1();  //予大弹
	Ammunition_feed2(); //予小弹
	chassis_control();//底盘控制+云台控制      C模式切换(按一次切换，再按收回)
		
	}
   robot_status_detection();
}


