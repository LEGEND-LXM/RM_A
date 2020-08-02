#include "main.h"
#include "bsp_init.h"
#include "bsp_headfile.h"
#include "gimbal_task.h"
#include "Robomaster_Control.h"

extern int remote_speed;  //遥控器计算的角度
extern int remote_yaw;


extern RC_Type remote_control;
extern int cnt1;
extern int count2;
extern int HP_error;
extern int flagfalg;
uint16_t SYSTEM_STATION=0;
uint16_t count_1 = 0; //状态灯计数器 
uint8_t IO_value_1,IO_value_2;

int main(void)
{
	int cnt=0;
	//单片机基本系统初始化
  system_init(); 
  HAL_TIM_Base_Start_IT(&htim2);
  while (1)
  {
		cnt++;
		if(cnt==100)    //0.5s进入一次，使第7个等以2HZ频率闪烁，从而判断中断程序正常运行
			{
				cnt=0;
				HAL_GPIO_TogglePin(GPIOG,GPIO_PIN_7);
			}
		IO_value_1=HAL_GPIO_ReadPin(GPIOI,GPIO_PIN_2);
		IO_value_2=HAL_GPIO_ReadPin(GPIOI,GPIO_PIN_7);
//		printf("%d    %d\n",IO_value_1,IO_value_2);
		
		
		
		count_1++;//YAW=205  	PITCH=206
//上位机参量填入区
//			Variable[0]=remote_control.switch_left;        
//	  	Variable[1]=remote_control.switch_right;      
//      Variable[2]=remote_control.ch1;	    
//	  	Variable[3]=remote_control.ch2;	              
//	  	Variable[4]=remote_control.ch3;	
//    	Variable[5]=remote_control.ch4;			
		
//			Variable[0]=cnt1;        
//		Variable[0]=fric_pwm.out;
//		Variable[1]=motor_info[2].rotor_angle;//YAW=2
//		Variable[2]=motor_info[YAW].rotor_angle;
//		Variable[3]=motor_info[moto1].torque_current;
//	  Variable[0]=motor_info[YAW].rotor_angle; 
//	  Variable[1]=motor_info[PITCH].rotor_angle;      
//    Variable[2]=check_pitch.pos_out;	    		
//		Variable[3]=mpuspeed_yaw;	
//		Variable[4]=gyro_mpu[2];
//		Variable[5]=accel_mpu[0];
//		Variable[6]=remote_control.ch1;
//		Variable[7]=pid_yuntai_yaw_speed.pos_out;
			wave_form_data[0]=(short)imu.gx;
//		wave_form_data[1]=(short)remote_yaw;
				wave_form_data[2]=(short)motor_info[PITCH].rotor_angle;//mpuspeed_yaw;
				wave_form_data[3]=(short)pid_yuntai_pitch_speed.pos_out;
//		wave_form_data[0]=(short)motor_info[YAW].rotor_angle;;
//		wave_form_data[1]=(short)motor_info[PITCH].rotor_angle;
//		wave_form_data[2]=(short)imu.ax;//mpuspeed_yaw;
//		wave_form_data[3]=(short)imu.ay;//-pid_yuntai_pitch_speed.pos_out;
//    wave_form_data[4]=(short)imu.gx;//-pid_yuntai_pitch_speed.pos_out;
//		wave_form_data[4]=(short)Armour_attack.pan_tilt_angel_err.Yaw_Err;//pid_yuntai_pitch_speed.pos_out;
//		wave_form_data[5]=(short)Armour_attack.pan_tilt_angel_err.Pitch_Err;//pid_yuntai_yaw_speed.pos_out; 
//		wave_form_data[4]=(short)motor_info[YAW].rotor_angle;//pid_yuntai_pitch_speed.pos_out;
//		wave_form_data[5]=(short)motor_info[PITCH].rotor_angle;//pid_yuntai_yaw_speed.pos_out; 
//		wave_form_data[6]=(short)robot_status.vision_status;//(short)IO_value_1;
		wave_form_data[4]=(short)remote_control.ch4;//pid_yuntai_pitch_speed.pos_out;
		wave_form_data[5]=(short)remote_yaw;//pid_yuntai_yaw_speed.pos_out; 
		wave_form_data[6]=(short)pid_yuntai_pitch.pos_out;//(short)IO_value_1;
//		wave_form_data[6]=(short)Armour_attack.vision_frame;//pid_yuntai_yaw_speed.pos_out;
//		wave_form_data[6]=(short)count2;
//		wave_form_data[7]=(short)pid_yuntai_pitch_speed.pos_out;
  	shanwai_send_wave_form();
		HAL_Delay(10);
//

//		printf("%f,%d\n",refSysData.power_heat_data_t.chassis_power,refSysData.power_heat_data_t.chassis_power_buffer);
//    printf("0: %d\n",refSysData.power_heat_data_t.shooter_heat0);
//		printf("1: %d\n",refSysData.power_heat_data_t.shooter_heat1);
//printf("power: %f         buffer: %d   \n",refSysData.power_heat_data_t.chassis_power,refSysData.power_heat_data_t.chassis_power_buffer);
			//普通心跳程序
//			if (count_1==500)
//			{HAL_GPIO_TogglePin(SINGLE_RED_GPIO_Port, SINGLE_RED_Pin);
//				count_1=0;}
			
	
  }
}









/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 6;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}
/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}
#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
