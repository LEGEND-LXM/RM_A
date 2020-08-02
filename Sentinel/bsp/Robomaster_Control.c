#include "Robomaster_Control.h"
#include "bsp_headfile.h"
#include "gimbal_task.h"

extern uint16_t SYSTEM_STATION;
extern uint16_t count_1; //״̬�Ƽ����� 

int	cnt1=1,cnt2=0;
void task(void)
{
	cnt1++;
	mpu_get_data();//���imuԭʼ����
	imu_ahrs_update(&imu);//������Ԫ����imu��̬
	
	
	
	fric1_on(1400);       //���
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
			else if(remote_control.switch_left==1){SYSTEM_STATION=MOCALUN_CONTROL;} //���ϰ�ȫ����
			else if(remote_control.switch_left==3){SYSTEM_STATION=MPU_CONTROL;} //�����ֶ�����
			else if(remote_control.switch_left==2){SYSTEM_STATION=MOTO_CONTROL;}//���������ǿ���
					
			// ����SYSTEM_STATION�����ת
			switch ( SYSTEM_STATION )            
      {
					 case LOSSLINE:      offline_control(); break; //���ߡ�����ȫģʽ
 					 case MOCALUN_CONTROL: manual_control(); break; //���ϵ���ȫģʽ
					 case MPU_CONTROL:   offline_control(); break; //����mpu������ģʽ  				
//					 case MPU_CONTROL:   MPU6050_control(); break; //����mpu������ģʽ  
					//case MOTO_CONTROL:  decision(); break;		
           case MOTO_CONTROL:  shoot_control(); break;					
//				case MOTO_CONTROL:  bodan_control(); break;	
					 default: break;  
      }

	   robot_status_detection();
}