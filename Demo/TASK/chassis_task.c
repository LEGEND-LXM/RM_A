/*��������ʾ��ͼ                               */
/* -    motor_1 **          ** motor_2         */
/*                **********                   */
/*                  ******                     */
/*                  ******                     */
/*                  ******                     */
/*                **********                   */
/* -    motor_3 **          ** motor_4         */

#include "chassis_task.h"

CHASSIS_Type CHASSIS_Ture ;
pid_struct_t Chassis_motor_PID[4] ;
uint16_t relative_angle(uint16_t angle);
uint16_t difference = 8192 - Yaw_Init_value;

void StartTask_Chassis(void const * argument) 
{
	osDelay(1);
	int32_t CH_Whole = 0 ;
	int16_t CH_X = 0;  // Xƽ�Ʒ����ٶȣ�����ǰ���ˣ�ǰ��Ϊ��
	int16_t CH_X1 = 0;  // �ݴ����ݼ���
	float CH_X_Proportion = 0;  // Xƽ�Ʒ����ٶ�ռ��
	int16_t CH_Y = 0;	 // yƽ�Ʒ����ٶȣ��������ҷ��� ����Ϊ��
	int16_t CH_Y1 = 0;  // �ݴ����ݼ���
	float CH_Y_Proportion = 0;  // yƽ�Ʒ����ٶ�ռ��
	int16_t CH_R = 0;  // ������ת�����ٶ�
	float CH_R_Proportion = 0;  // ������ת�����ٶ�ռ��
	CHASSIS_Ture.Mode = 1;  // ��ʼ���˶�ģʽ��1Ϊ��ͨģʽ��2ΪС����ģʽ��
/**********************************��ʼ�����̵��PID�ṹ��***************************************************/
/*        1�ŵ��\\				//2�ŵ��	
//
//
//
//				4�ŵ��//				\\3�ŵ��
*/	
		
	     pid_init(&Chassis_motor_PID[0] ,POSITION_PID      //1�ŵ��
																			,24            		 //Kp
																			,0            		 //Ki
																			,0            		 //Kd
																			,1000 ,20000 ,10); //��ʼ�����̵��PID�ṹ��
	     CHASSIS_Ture.Chassis_motor_voltage[0] = 0;
	
	     pid_init(&Chassis_motor_PID[1] ,POSITION_PID      //2�ŵ��      
																			,22                 //Kp
																			,0                 //Ki
																			,0                 //Kd
																			,1000 , 20000,10);  //��ʼ�����̵��PID�ṹ��
	     CHASSIS_Ture.Chassis_motor_voltage[1] = 0;
	
	     pid_init(&Chassis_motor_PID[2] ,POSITION_PID      //4�ŵ��
																			,23                 //Kp
																			,0                 //Ki
																			,0                 //Kd
																			,1000 , 20000,10);//��ʼ�����̵��PID�ṹ��
			 CHASSIS_Ture.Chassis_motor_voltage[2] = 0;	
			 
	     pid_init(&Chassis_motor_PID[3] ,POSITION_PID      //3�ŵ�� 
																			,26                 //Kp
																			,0                 //Ki
																			,0                 //Kd
																			,1000 ,20000 ,10);  //��ʼ�����̵��PID�ṹ��
	     CHASSIS_Ture.Chassis_motor_voltage[3] = 0;	
	



/*************************************************************************************************************/			

	for(;;)
  {
	if((remote_control.switch_left != 3 || remote_control.switch_right != 3)
    &&(remote_control.switch_left != 1 || remote_control.switch_right != 1)		)
	{
		osDelay(4);
//remote_control.ch2��ǰ��������
//remote_control.ch3������ת��
//remote_control.ch1������ƽ��
		CH_X = Dead_zone_immune(remote_control.ch2 ,10);
		CH_Y = Dead_zone_immune(remote_control.ch1 ,10);
		if(CHASSIS_Ture.Mode == 1)  // ��ͨģʽ�����̵���ת�ɲ����ֿ���
			{
				CH_X *= 0.707f;
				CH_Y *= 0.707f;
				CH_R = Dead_zone_immune(remote_control.ch3 ,10);
				if(Dead_zone_immune_angle(motor_info[6].rotor_angle - Yaw_Init_value, 0) 
					<= -114 && motor_info[6].rotor_angle > 1344)					 
				{  // �����̺���̨��нǴ���5��ʱ�����̸�����̨
					CH_R += 1.2;  // �˴�Ϊ����һ������Ĺ̶���ת������ٶ�
				} 
				else	
					if(Dead_zone_immune_angle(motor_info[6].rotor_angle - Yaw_Init_value, 0) >= 114 || 
						 (Dead_zone_immune_angle(motor_info[6].rotor_angle - Yaw_Init_value, 0) 
							<= -114 && motor_info[6].rotor_angle < 1344))
				{
					CH_R -= 1.2;  // �˴�Ϊ����һ������Ĺ̶���ת������ٶ�
				}			
			}
		else if(CHASSIS_Ture.Mode == 2) // С����ģʽ��������һ���̶��ٶ���ת������Ӱ������������˶���
			{
				CH_R = Dead_zone_immune(396 ,10);
				HALDER_Ture.halder_motor[1].standard_angle = relative_angle(motor_info[6].rotor_angle);
				CH_X1 = CH_X;
				CH_Y1 = CH_Y;
				CH_X = CH_X1*My_Cos(HALDER_Ture.halder_motor[1].standard_angle) 
							+ CH_Y1*My_Sin(HALDER_Ture.halder_motor[1].standard_angle);
				CH_Y = - CH_X1*My_Sin(HALDER_Ture.halder_motor[1].standard_angle) 
							+ CH_Y1*My_Cos(HALDER_Ture.halder_motor[1].standard_angle);
				
				
			}
		
		// �����ÿ�������ٶ�ռ����ı�����
		//��֤�˶��ϳ�ʱ����ı�������ϵ��ٶ�
		CH_Whole = CH_X + CH_Y + CH_R ;  
		CH_X_Proportion = CH_X/CH_Whole;
		CH_Y_Proportion = CH_Y/CH_Whole;
		CH_R_Proportion = CH_R/CH_Whole;
		
		CH_X *= CH_X_Proportion*1638;
		CH_Y *= CH_Y_Proportion*1638;
		CH_R *= CH_R_Proportion*1638;
		
		
/**********************************���̵���˶���ϣ�ң�أ�***************************************************/
		
/**********************************���̵���˶���ϣ�ң�أ�***************************************************/
  CHASSIS_Ture.Chassis_motor_voltage[0] = (CH_X - CH_Y - CH_R );  //1�ŵ��
	CHASSIS_Ture.Chassis_motor_voltage[0] = fp32_constrain( CHASSIS_Ture.Chassis_motor_voltage[0] ,-8192 ,8192 );
		
  CHASSIS_Ture.Chassis_motor_voltage[1] = (CH_X + CH_Y + CH_R );  //2�ŵ��
	CHASSIS_Ture.Chassis_motor_voltage[1] = fp32_constrain( CHASSIS_Ture.Chassis_motor_voltage[1] ,-8192 ,8192 );	
	
  CHASSIS_Ture.Chassis_motor_voltage[2] = (CH_X + CH_Y - CH_R) ;  //4�ŵ��
	CHASSIS_Ture.Chassis_motor_voltage[2] = fp32_constrain( CHASSIS_Ture.Chassis_motor_voltage[2] ,-8192 , 8192);
		
  CHASSIS_Ture.Chassis_motor_voltage[3] = (CH_X - CH_Y + CH_R) ;  //3�ŵ��
	CHASSIS_Ture.Chassis_motor_voltage[3] = fp32_constrain( CHASSIS_Ture.Chassis_motor_voltage[3] ,- 8192, 8192);
		
/*************************************************************************************************************/	
/**********************************���̵��PID����***************************************************/		

	    motor_info[0].set_voltage = pid_calc(&Chassis_motor_PID[0] 
																					,CHASSIS_Ture.Chassis_motor_voltage[0] 
																					,motor_info[0].rotor_speed );		 
	    motor_info[1].set_voltage = pid_calc(&Chassis_motor_PID[1] 
																					,CHASSIS_Ture.Chassis_motor_voltage[1] 
																					,motor_info[1].rotor_speed );			 
	    motor_info[2].set_voltage = pid_calc(&Chassis_motor_PID[2] 
																					,CHASSIS_Ture.Chassis_motor_voltage[2] 
																					,motor_info[2].rotor_speed );
	    motor_info[3].set_voltage = pid_calc(&Chassis_motor_PID[3] 
																					,CHASSIS_Ture.Chassis_motor_voltage[3] 
																					,motor_info[3].rotor_speed );	
		
/*************************************************************************************************************/	
		
		set_motor_voltage(1 ,motor_info[0].set_voltage 
												,motor_info[1].set_voltage 
												,motor_info[2].set_voltage 
												,motor_info[3].set_voltage
										 );
	HAL_GPIO_WritePin( GPIOG , LED5_Pin, GPIO_PIN_SET);
 
   
 }
	else
	{
		set_motor_voltage(1 ,0 
												,0 
												,0 
												,0
										 );
		HAL_GPIO_WritePin( GPIOG , LED5_Pin, GPIO_PIN_RESET);
	}
  }
	
}
//�����޶�������int16_t�ͣ�
// (CHx/100)*4250 �����Ϊ�÷����ٶ�Ϊ (CHx/132) m/s ʱ�ĸ�λ�õ�������ֵ 
int16_t Dead_zone_immune(int16_t CHx ,uint16_t Dead_line)     
{
	if( (CHx <=0) && (CHx+Dead_line >=0) )		
			return 0;
	else
		if( (CHx >0) && (CHx-Dead_line <=0) )
			return 0;
	else
		 return ((int)CHx/132);
}

uint16_t relative_angle(uint16_t angle)
{
	uint16_t value = 0;
	if( angle > 5440 )
	{
		return (angle - Yaw_Init_value)*0.0439;
	}
	else
		if( angle <  5440 )
		{
			return (angle + difference)*0.0439;
		}
	else
		if( angle == 5440 )
		{
			return 0;
		}
	
}
