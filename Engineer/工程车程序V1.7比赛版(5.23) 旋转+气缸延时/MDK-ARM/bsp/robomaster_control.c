
#include "robomaster_control.h"
#include "robomaster_common.h"


u8 footstep_target_flag=0;
#define twist_speed        1000
#define chassis_limit      1000       //走猫步时的底盘限位机械角度
#define chassis_dead_band  100        //底盘机械角度的死区
#define twist_dead_band    150				//用于猫步中识别遥控器操作时底盘与云台位置的误差

//摩擦轮初始化

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
*函 数 名: chassis_control
*功能说明:  1(yaw轴)的角度换和角速度环控制，底盘加入速度环进行控制
*形    参: 需要yaw轴角度，角速度，电机速度反馈
*返 回 值: 电流输出 
**********************************************************************************************************/
extern int16_t moto_ctr[6];
int32_t set_spd = 0;//速度参数
int32_t turn=0;     //转弯
long yaw_flag=0;
extern int cnt1;
extern int cnt2;
char cnt_steer=0;
int yaw_cnt=0;
int chassis_yaw_correct=0;
u16 save_flag1=0;//救援flag
void chassis_control()
{

	Keyboard_Init();
	
	if(remote_control.switch_right==3)
	{
	if(cnt1==100)//0.5s进入一次，使第4个led以2HZ频率闪烁，判断底盘程序正常运行
		{
				HAL_GPIO_TogglePin(GPIOG,GPIO_PIN_4);
				cnt1=0;
		}
		Bling_Set(&Light_G,2000,1000,0.5,0,LED_USER_GPIO_PORT,LED_G_Pin,1);//设置ledG闪烁频率
	DBUS_Deal();//获取遥控器的数据并将数据赋值给电机的目标转速
	if(remote_control.switch_left==1)
	Keyboard_Init();	
	
	if(remote_control.mouse.x==0&&remote_control.ch3<5&&remote_control.ch3>-5)//走直线 if(remote_control.ch3<5&&remote_control.ch3>-5)
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
		chassis_yaw.f_cal_pid(&chassis_yaw,imu.yaw);    //偏航角度控制
		chassis_yaw_speed.target=chassis_yaw.output;//偏航角速度环期望，来源于偏航角度控制器输出 
	}
	else
	{
		footstep_target_flag=RESET;//抬升定高
		chassis_yaw.target=0;//偏航角期望给0,不进行角度控制
  	chassis_yaw_speed.target=0/*remote_control.ch3*800/660*/;//yaw_control;//偏航角速度环期望，直接来源于遥控器打杆量
		
		
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
	
	
	chassis_yaw_speed.f_cal_pid(&chassis_yaw_speed,-imu.gz);//yaw对应输出	
	
	motor_pid[0].f_cal_pid(&motor_pid[0],moto_chassis[0].speed_rpm);    //遥控值对应输出
	motor_pid[1].f_cal_pid(&motor_pid[1],moto_chassis[1].speed_rpm);   
	motor_pid[2].f_cal_pid(&motor_pid[2],moto_chassis[2].speed_rpm);    
	motor_pid[3].f_cal_pid(&motor_pid[3],moto_chassis[3].speed_rpm);    
		

	set_moto_current(&hcan1,motor_pid[0].output+chassis_yaw_speed.output,   //遥控+yaw    +chassis_yaw_speed.output
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
*函 数 名: GildeAverageValueFilter
*功能说明: 底盘速度环控制
*形    参: 
*返 回 值: 电流输出
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
*函 数 名: set_chassis_moto_target_zero
*功能说明:设置底盘电机目标值为0  当步兵失控时会调用此函数
*形    参: 
*返 回 值: 
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
//	CAN_Send_Msg(&hcan1, MotorTxData, MOTORID, 8);  //向底盘电机发送给定的电流值
//	//CAN_Send_Msg(&hcan1,HeadTxData,HEADID,8);
//}

///**********************************************************************************************************
//*函 数 名: Acquire
//*功能说明:获取大弹丸
//*形    参: 
//*返 回 值: 
//**********************************************************************************************************/

//u32 tim=0;
//u16 acquire_flag=0;  //取弹标志位


//void Acquire1()  //获取第一排弹丸  
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
//   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);  //抬高 
//   tim++;
//	if(tim>=300)
//	{
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //前旋
//			tim++;
//		if(tim>=700)
//		{
//				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET); //夹紧
//				tim++;
//				if(tim>1500)
//				{
//						HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //后旋
//						tim++; 
//					if(tim>=2500)
//					{
//					  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //前旋
//					  tim++;	
//					   if(tim>=3500)	 
//				    	{
//					      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET); //松开
//					      tim++;
//					      	if(tim>=4200)
//						     {
//							     HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //后旋
//									 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET); //下降
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
	CAN_Send_Msg(&hcan1, MotorTxData, MOTORID, 8);  //向底盘电机发送给定的电流值
	//CAN_Send_Msg(&hcan1,HeadTxData,HEADID,8);
}
/**********************************************************************************************************
*函 数 名: pinch_control1()
*功能说明：取弹电机工作
*形    参: 
*返 回 值: 
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
*函 数 名: pinch_control2（）
*功能说明:弹射电机工作
*形    参: 
*返 回 值: 
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
*函 数 名: Acquire1（）
*功能说明:获取大弹丸
*形    参: 
*返 回 值: 
**********************************************************************************************************/
u32 tim=0;

void Acquire2()//取大弹丸
{
    if((remote_control.switch_left==1&&(remote_control.switch_right==1)  //取弹模式
{

  pinch_control1(-175);                                   //夹取电机旋转
				tim++;
				if(tim1>=500)
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_SET);   //夹取弹丸
				tim++;
}
				if(tim1>=1000)
	{
				pinch_control1(0);                                   //夹取电机旋转
				tim++;
	}
				if(tim1>=1500)
				{
				pinch_control2(85);                    //弹射电机工作
				tim++;
				}
				if(tim1>=1200)
			{
				pinch_control2(0);                    //弹射电机复位
			}

 }
}





//u32 tim=0;
//u16 acquire_flag=0;  //取弹标志位


//void Acquire1()  //获取弹丸  
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
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //前旋
//			tim++;
//		if(tim>=400)
//		{
//				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET); //夹紧
//				tim++;
//				if(tim>1400)
//				{
//						HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //后旋
//						tim++; 
//					if(tim>=2400)
//					{
//					  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //前旋
//					  tim++;	
//					   if(tim>=2800)	 
//				    	{
//					      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET); //松开
//					      tim++;
//					      	if(tim>=3800)
//						     {
//							     HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //后旋

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
//u16 acquire_flag=0;  //取弹标志位


//void Acquire1()  //获取第一排弹丸  
//{
//if(remote_control.switch_left==2&&remote_control.switch_right==1)
//{   
//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);  //抬高 
//tim++;
//	if(tim>=300)
//	{
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //前旋
//			tim++;
//	}
//		if(tim>=800)
//		{
//				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET); //夹紧
//				tim++;
//		}
//				if(tim>=1300)
//				{
//						HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //后旋
//						tim++;
//				}
//					if(tim>=2300)
//					{
//					  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //前旋
//					  tim++;
//					}					
//					   if(tim>=2700)	 
//				    	{
//					      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET); //松开
//					      tim++;
//							}
//					      	if(tim>=3700)
//						     {
//									 
//							     HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //后旋
//									 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET); //下降
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










//void Acquire2()  //获取第二排弹丸  
//{
//if(remote_control.switch_left==3&&remote_control.switch_right==1)
//{         
//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);  //抬高
//	HAL_Delay (500);
//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);  //抬高
//	HAL_Delay (500);	
//tim++;
//	if(tim==2000)
//	{
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET); //伸出
//		tim++;
//		if(tim==4000)
//		{
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //前旋
//			tim++;
//			if(tim==7000)
//			{
//				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET); //夹紧
//				tim++;
//				if(tim==10000)
//				{
//					HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET); //缩回
//					tim++;
//					if(tim==13000)
//					{
//						HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //后旋
//						tim++;

//					}
//				}
//			}
//		 }
//	 }
//					acquire_flag=1; //弹丸已入仓
//					tim++;
//					if(acquire_flag==1&&tim==18000)
//					{
//					  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //前旋
//					  tim++;	
//					   if(tim==18200)	 
//				    	{
//					      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET); //松开
//					      tim++;
//					      	if(tim==20200)
//						     {
//							     HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //后旋
//						      }
//				     	}
//					}
//        acquire_flag=0;   //取弹结束
//} 
//}


/**********************************************************************************************************
*函 数 名: Acquire2（）
*功能说明:获取小弹丸
*形    参: 
*返 回 值: 
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
*函 数 名:Ammunition_feed1
*功能说明:给予大弹丸
*形    参: 
*返 回 值: 
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
*函 数 名:Ammunition_feed1
*功能说明:给予小弹丸
*形    参: 
*返 回 值: 
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
*函 数 名:Electromagnet—save
*功能说明:电磁铁救援
*形    参: 
*返 回 值: 
**********************************************************************************************************/

void Electromagnet_save()
{
	
	
if(remote_control.switch_left==1&&remote_control.switch_right==3)
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);	//电磁铁打开
	}
else if(remote_control.switch_left==2&&remote_control.switch_right==3)	//电磁铁关闭
		{
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
		}
		
}






/**********************************************************************************************************
*函 数 名:Card_save
*功能说明:场地交互卡救援（PD14下降   PD15伸出）
*形    参: 
*返 回 值: 
**********************************************************************************************************/
u32 tim1;
u16 card_save_flag=0;  //交互卡救援标志位
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
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);		//下降
			tim1++; 
			if(tim1>=500)
			{
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);	//伸出
			}
		}
		
if(card_save_flag==0)
{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);		//缩回
			tim1++; 
			if(tim1>=500)
			{
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);	//上升
			}
		}
	
	}  
