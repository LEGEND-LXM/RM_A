#include "Robomaster_Control.h"
#include "bsp_headfile.h"
#include "gimbal_task.h"

extern uint16_t SYSTEM_STATION;
extern uint16_t count_1; //状态灯计数器 

int	cnt1=1,cnt2=0;
void task(void)
{
	cnt1++;
	mpu_get_data();//获得imu原始数据
	imu_ahrs_update(&imu);//更新四元数和imu姿态
	
	
	
	fric1_on(1400);       //输出
	fric2_on(1400);
	
	
	
//	if(HAL_GetTick() - Latest_Remote_Control_Pack_Time >500)
//	{SYSTEM_STATION=LOSSLINE; buzzer_on(0, 20000);}
//	else
//	{SYSTEM_STATION=ONLINE;buzzer_off();}	
//	if(cnt1>=100)
//	{
	HAL_GPIO_WritePin(GPIOG, GREENLED5_Pin|GREENLED4_Pin|GREENLED3_Pin|GREENLED2_Pin 
	                     |GREENLED1_Pin, GPIO_PIN_RESET);
//		cnt1=0;
	
	    if (remote_control.switch_left==0){SYSTEM_STATION=LOSSLINE;}
			else if(remote_control.switch_left==1){SYSTEM_STATION=MOCALUN_CONTROL;} //左上安全回中
			else if(remote_control.switch_left==3){SYSTEM_STATION=MPU_CONTROL;} //左中手动控制
			else if(remote_control.switch_left==2){SYSTEM_STATION=MOTO_CONTROL;}//左下陀螺仪控制
					
			// 根据SYSTEM_STATION结果跳转
			switch ( SYSTEM_STATION )            
      {
					 case LOSSLINE:      offline_control(); break; //离线——安全模式
 					 case MOCALUN_CONTROL: manual_control(); break; //左上挡安全模式
					 case MPU_CONTROL:   offline_control(); break; //左下mpu陀螺仪模式  				
//					 case MPU_CONTROL:   MPU6050_control(); break; //左下mpu陀螺仪模式  
					//case MOTO_CONTROL:  decision(); break;		
           case MOTO_CONTROL:  shoot_control(); break;					
//				case MOTO_CONTROL:  bodan_control(); break;	
					 default: break;  
      }

	   robot_status_detection();
}