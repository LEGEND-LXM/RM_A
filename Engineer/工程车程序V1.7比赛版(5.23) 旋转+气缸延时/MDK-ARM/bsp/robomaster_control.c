
#include "robomaster_control.h"
#include "robomaster_common.h"


u8 footstep_target_flag=0;
#define twist_speed        1000
#define chassis_limit      1000       //��è��ʱ�ĵ�����λ��е�Ƕ�
#define chassis_dead_band  100        //���̻�е�Ƕȵ�����
#define twist_dead_band    150				//����è����ʶ��ң��������ʱ��������̨λ�õ����

//Ħ���ֳ�ʼ��

void PWM_SetDuty(TIM_HandleTypeDef *tim,uint32_t tim_channel,float duty)
	{
	switch(tim_channel){	
		case TIM_CHANNEL_1: tim->Instance->CCR1 = duty - 1;break;
		case TIM_CHANNEL_2: tim->Instance->CCR2 = duty  - 1;break;
		case TIM_CHANNEL_3: tim->Instance->CCR3 = duty  - 1;break;
		case TIM_CHANNEL_4: tim->Instance->CCR4 = duty  - 1;break;
	}	
}



/**********************************************************************************************************
*�� �� ��: chassis_control
*����˵��:  1(yaw��)�ĽǶȻ��ͽ��ٶȻ����ƣ����̼����ٶȻ����п���
*��    ��: ��Ҫyaw��Ƕȣ����ٶȣ�����ٶȷ���
*�� �� ֵ: ������� 
**********************************************************************************************************/
extern int16_t moto_ctr[6];
int32_t set_spd = 0;//�ٶȲ���
int32_t turn=0;     //ת��
long yaw_flag=0;
extern int cnt1;
extern int cnt2;
char cnt_steer=0;
int yaw_cnt=0;
int chassis_yaw_correct=0;
u16 save_flag1=0;//��Ԯflag
void chassis_control()
{

	Keyboard_Init();
	
	if(remote_control.switch_right==3)
	{
	if(cnt1==100)//0.5s����һ�Σ�ʹ��4��led��2HZƵ����˸���жϵ��̳�����������
		{
				HAL_GPIO_TogglePin(GPIOG,GPIO_PIN_4);
				cnt1=0;
		}
		Bling_Set(&Light_G,2000,1000,0.5,0,LED_USER_GPIO_PORT,LED_G_Pin,1);//����ledG��˸Ƶ��
	DBUS_Deal();//��ȡң���������ݲ������ݸ�ֵ�������Ŀ��ת��
	if(remote_control.switch_left==1)
	Keyboard_Init();	
	
	if(remote_control.mouse.x==0&&remote_control.ch3<5&&remote_control.ch3>-5)//��ֱ�� if(remote_control.ch3<5&&remote_control.ch3>-5)
	{
		if(yaw_cnt<500)
		yaw_cnt++;
		if(kb.z_flag==1)
		{
		chassis_yaw.target=0;
		}
			if(kb.Ctrl_flag==1)
			{
			chassis_yaw.target=imu.yaw+10;
			}
		if(chassis_yaw.target==0)
		{
			chassis_yaw.target=imu.yaw;
		}
		chassis_yaw.f_cal_pid(&chassis_yaw,imu.yaw);    //ƫ���Ƕȿ���
		chassis_yaw_speed.target=chassis_yaw.output;//ƫ�����ٶȻ���������Դ��ƫ���Ƕȿ�������� 
	}
	else
	{
		footstep_target_flag=RESET;//̧������
		chassis_yaw.target=0;//ƫ����������0,�����нǶȿ���
  	chassis_yaw_speed.target=0/*remote_control.ch3*800/660*/;//yaw_control;//ƫ�����ٶȻ�������ֱ����Դ��ң���������
		
		
		if(save_flag1==0)//
		{
	 motor_pid[0].target=motor_pid[0].target+remote_control.mouse.x*185;
   motor_pid[1].target=motor_pid[1].target+remote_control.mouse.x*185;
   motor_pid[2].target=motor_pid[2].target+remote_control.mouse.x*185;
   motor_pid[3].target=motor_pid[3].target+remote_control.mouse.x*185;
		}
		if(save_flag1==1)//
		{
	 motor_pid[0].target=motor_pid[0].target+remote_control.mouse.x*260;
   motor_pid[1].target=motor_pid[1].target+remote_control.mouse.x*260;
   motor_pid[2].target=motor_pid[2].target+remote_control.mouse.x*260;
   motor_pid[3].target=motor_pid[3].target+remote_control.mouse.x*260;
		}
		
	}	
	
	
	chassis_yaw_speed.f_cal_pid(&chassis_yaw_speed,-imu.gz);//yaw��Ӧ���	
	
	motor_pid[0].f_cal_pid(&motor_pid[0],moto_chassis[0].speed_rpm);    //ң��ֵ��Ӧ���
	motor_pid[1].f_cal_pid(&motor_pid[1],moto_chassis[1].speed_rpm);   
	motor_pid[2].f_cal_pid(&motor_pid[2],moto_chassis[2].speed_rpm);    
	motor_pid[3].f_cal_pid(&motor_pid[3],moto_chassis[3].speed_rpm);    
		

	set_moto_current(&hcan1,motor_pid[0].output+chassis_yaw_speed.output,   //ң��+yaw    +chassis_yaw_speed.output
													motor_pid[1].output+chassis_yaw_speed.output,
													motor_pid[2].output+chassis_yaw_speed.output,
													motor_pid[3].output+chassis_yaw_speed.output);	
	}
	if(kb.z_flag==1)
	{
	chassis_yaw.target=0;
	}
	else
		set_moto_current(&hcan1,0,0,0,0);		
}



/**********************************************************************************************************
*�� �� ��: GildeAverageValueFilter
*����˵��: �����ٶȻ�����
*��    ��: 
*�� �� ֵ: �������
**********************************************************************************************************/
float Data[N];
float GildeAverageValueFilter(float NewValue,float *Data)
{
  float max,min;
  float sum;
  unsigned char i;
  Data[0]=NewValue;
  max=Data[0];
  min=Data[0];
  sum=Data[0];
  for(i=N-1;i!=0;i--)
  {
    if(Data[i]>max) max=Data[i];
    else if(Data[i]<min) min=Data[i];
    sum+=Data[i];
    Data[i]=Data[i-1];
  }
  i=N-2;
  sum=sum-max-min;
  sum=sum/i;
  return(sum);
}



/**********************************************************************************************************
*�� �� ��: set_chassis_moto_target_zero
*����˵��:���õ��̵��Ŀ��ֵΪ0  ������ʧ��ʱ����ô˺���
*��    ��: 
*�� �� ֵ: 
**********************************************************************************************************/
//void set_chassis_moto_target_zero()
//{
//	char i;
//	for(i=0;i<8;i++)
//	{
//		MotorTxData[i]=0;
//		//HeadTxData[i]=0;
//		//CAN_Send_Msg(&hcan1,0,HEADID,8);
//		
//	}
//	CAN_Send_Msg(&hcan1, MotorTxData, MOTORID, 8);  //����̵�����͸����ĵ���ֵ
//	//CAN_Send_Msg(&hcan1,HeadTxData,HEADID,8);
//}

///**********************************************************************************************************
//*�� �� ��: Acquire
//*����˵��:��ȡ����
//*��    ��: 
//*�� �� ֵ: 
//**********************************************************************************************************/

//u32 tim=0;
//u16 acquire_flag=0;  //ȡ����־λ


//void Acquire1()  //��ȡ��һ�ŵ���  
//{
//if(remote_control.switch_left==2&&remote_control.switch_right==1)
//{   
//  acquire_flag=1;
//}
//else if(remote_control.switch_left==2&&remote_control.switch_right==3)
//{
//	tim=0;
//	acquire_flag=0;
//}
//	
//	if(acquire_flag==1)
//	{
//   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);  //̧�� 
//   tim++;
//	if(tim>=300)
//	{
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //ǰ��
//			tim++;
//		if(tim>=700)
//		{
//				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET); //�н�
//				tim++;
//				if(tim>1500)
//				{
//						HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //����
//						tim++; 
//					if(tim>=2500)
//					{
//					  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //ǰ��
//					  tim++;	
//					   if(tim>=3500)	 
//				    	{
//					      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET); //�ɿ�
//					      tim++;
//					      	if(tim>=4200)
//						     {
//							     HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //����
//									 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET); //�½�
//						     }
//				     	}
//					}
//					
//         }
//			 }
//	}
//  }
//	
//	else {
//		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
//	     }
//	
//}

void set_chassis_moto_target_zero()
{
	char i;
	for(i=0;i<8;i++)
	{
		MotorTxData[i]=0;
		//HeadTxData[i]=0;
		//CAN_Send_Msg(&hcan1,0,HEADID,8);
		
	}
	CAN_Send_Msg(&hcan1, MotorTxData, MOTORID, 8);  //����̵�����͸����ĵ���ֵ
	//CAN_Send_Msg(&hcan1,HeadTxData,HEADID,8);
}
/**********************************************************************************************************
*�� �� ��: pinch_control1()
*����˵����ȡ���������
*��    ��: 
*�� �� ֵ: 
**********************************************************************************************************/
void  pinch_control1(int pinch_target)
{ 
	motor_pid[5].target= pinch_target;
  motor_pid[5].f_cal_pid(&motor_pid[4],moto_chassis[4].total_angle);
	pid_speed.target=motor_pid[4].output*5000/4500;
	pid_speed.f_cal_pid(&pid_speed,moto_chassis[4].speed_rpm);
	set_upthrow_current(&hcan1,pid_speed.output,carry_cut);	

}
/**********************************************************************************************************
*�� �� ��: pinch_control2����
*����˵��:����������
*��    ��: 
*�� �� ֵ: 
**********************************************************************************************************/
void  pinch_control2(int pinch_target)
{ 
	motor_pid[4].target= pinch_target;
	motor_pid[4].f_cal_pid(&motor_pid[4],moto_chassis[4].total_angle);
	pid_speed.target=motor_pid[4].output*5000/4500;
	pid_speed.f_cal_pid(&pid_speed,moto_chassis[4].speed_rpm);
	set_upthrow_current(&hcan1,pid_speed.output,carry_cut);	
}


/**********************************************************************************************************
*�� �� ��: Acquire1����
*����˵��:��ȡ����
*��    ��: 
*�� �� ֵ: 
**********************************************************************************************************/
u32 tim=0;

void Acquire2()//ȡ����
{
    if((remote_control.switch_left==1&&(remote_control.switch_right==1)  //ȡ��ģʽ
{

  pinch_control1(-175);                                   //��ȡ�����ת
				tim++;
				if(tim1>=500)
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_SET);   //��ȡ����
				tim++;
}
				if(tim1>=1000)
	{
				pinch_control1(0);                                   //��ȡ�����ת
				tim++;
	}
				if(tim1>=1500)
				{
				pinch_control2(85);                    //����������
				tim++;
				}
				if(tim1>=1200)
			{
				pinch_control2(0);                    //��������λ
			}

 }
}





//u32 tim=0;
//u16 acquire_flag=0;  //ȡ����־λ


//void Acquire1()  //��ȡ����  
//{
//if(remote_control.switch_left==2&&remote_control.switch_right==1)
//{   
//  acquire_flag=1;
//}
//else if(remote_control.switch_left==2&&remote_control.switch_right==3)
//{
//	tim=0;
//	acquire_flag=0;
//}
//	
//	if(acquire_flag==1)
//	{
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //ǰ��
//			tim++;
//		if(tim>=400)
//		{
//				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET); //�н�
//				tim++;
//				if(tim>1400)
//				{
//						HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //����
//						tim++; 
//					if(tim>=2400)
//					{
//					  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //ǰ��
//					  tim++;	
//					   if(tim>=2800)	 
//				    	{
//					      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET); //�ɿ�
//					      tim++;
//					      	if(tim>=3800)
//						     {
//							     HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //����

//						     }
//				     	}
//					}
//					
//         }
//			 }
//	}
//	
//	else {
//		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
//	     }
//	
//}

//u32 tim=0;
//u16 acquire_flag=0;  //ȡ����־λ


//void Acquire1()  //��ȡ��һ�ŵ���  
//{
//if(remote_control.switch_left==2&&remote_control.switch_right==1)
//{   
//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);  //̧�� 
//tim++;
//	if(tim>=300)
//	{
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //ǰ��
//			tim++;
//	}
//		if(tim>=800)
//		{
//				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET); //�н�
//				tim++;
//		}
//				if(tim>=1300)
//				{
//						HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //����
//						tim++;
//				}
//					if(tim>=2300)
//					{
//					  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //ǰ��
//					  tim++;
//					}					
//					   if(tim>=2700)	 
//				    	{
//					      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET); //�ɿ�
//					      tim++;
//							}
//					      	if(tim>=3700)
//						     {
//									 
//							     HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //����
//									 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET); //�½�
//								 }
//				     	
//					
//}
//	if(remote_control.switch_left==2&&remote_control.switch_right==1)
//	{
//		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
//	}
//}










//void Acquire2()  //��ȡ�ڶ��ŵ���  
//{
//if(remote_control.switch_left==3&&remote_control.switch_right==1)
//{         
//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);  //̧��
//	HAL_Delay (500);
//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);  //̧��
//	HAL_Delay (500);	
//tim++;
//	if(tim==2000)
//	{
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET); //���
//		tim++;
//		if(tim==4000)
//		{
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //ǰ��
//			tim++;
//			if(tim==7000)
//			{
//				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET); //�н�
//				tim++;
//				if(tim==10000)
//				{
//					HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET); //����
//					tim++;
//					if(tim==13000)
//					{
//						HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //����
//						tim++;

//					}
//				}
//			}
//		 }
//	 }
//					acquire_flag=1; //���������
//					tim++;
//					if(acquire_flag==1&&tim==18000)
//					{
//					  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //ǰ��
//					  tim++;	
//					   if(tim==18200)	 
//				    	{
//					      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET); //�ɿ�
//					      tim++;
//					      	if(tim==20200)
//						     {
//							     HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //����
//						      }
//				     	}
//					}
//        acquire_flag=0;   //ȡ������
//} 
//}


/**********************************************************************************************************
*�� �� ��: Acquire2����
*����˵��:��ȡС����
*��    ��: 
*�� �� ֵ: 
**********************************************************************************************************/
void Acquire2()
{
	if(remote_control.switch_left==2&&remote_control.switch_right==3)
	{
		PWM_SetDuty(&htim5,TIM_CHANNEL_4,1500);		
	}
	if(remote_control.switch_left==3&&remote_control.switch_right==2)
	{
	PWM_SetDuty(&htim5,TIM_CHANNEL_4,150);
}
}


/**********************************************************************************************************
*�� �� ��:Ammunition_feed1
*����˵��:�������
*��    ��: 
*�� �� ֵ: 
**********************************************************************************************************/
void Ammunition_feed1()
{
	if(remote_control.switch_left==3&&remote_control.switch_right==3)
	{
		PWM_SetDuty(&htim5,TIM_CHANNEL_4,2200);		
	}
	if(remote_control.switch_left==3&&remote_control.switch_right==1)
	{
	PWM_SetDuty(&htim5,TIM_CHANNEL_4,450);
}
}


/**********************************************************************************************************
*�� �� ��:Ammunition_feed1
*����˵��:����С����
*��    ��: 
*�� �� ֵ: 
**********************************************************************************************************/
u8  fee_flag=0;
void Ammunition_feed2()
{
 if(remote_control.switch_left==1&&remote_control.switch_right==2)
	{
   fee_flag=1;
  }
	else if(remote_control.switch_left==1&&remote_control.switch_right==1)
	{
		fee_flag=0;
	}
	 if(fee_flag ==1)
	 {
		 set_upthrow_current(&hcan1 ,-1000);
	 }
	 else  set_upthrow_current(&hcan1 ,0);
}
/**********************************************************************************************************
*�� �� ��:Electromagnet��save
*����˵��:�������Ԯ
*��    ��: 
*�� �� ֵ: 
**********************************************************************************************************/

void Electromagnet_save()
{
	
	
if(remote_control.switch_left==1&&remote_control.switch_right==3)
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);	//�������
	}
else if(remote_control.switch_left==2&&remote_control.switch_right==3)	//������ر�
		{
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
		}
		
}






/**********************************************************************************************************
*�� �� ��:Card_save
*����˵��:���ؽ�������Ԯ��PD14�½�   PD15�����
*��    ��: 
*�� �� ֵ: 
**********************************************************************************************************/
u32 tim1;
u16 card_save_flag=0;  //��������Ԯ��־λ
void Card_save()
{
if(remote_control.switch_left==2&&remote_control.switch_right==2)
		{
			card_save_flag=1; 
		}
				if(remote_control.switch_left==3&&remote_control.switch_right==2)
		{
		  card_save_flag=0; 
			tim1=0;
		}
		
	if(card_save_flag==1)
		{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);		//�½�
			tim1++; 
			if(tim1>=500)
			{
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);	//���
			}
		}
		
if(card_save_flag==0)
{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);		//����
			tim1++; 
			if(tim1>=500)
			{
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);	//����
			}
		}
	
	}  
