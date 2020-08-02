#include "imu_task.h"

IMU_Type IMU_Ture;

extern imu_t imu;

char buf[300];

void StartTask_Imu(void const * argument) 
{
	osDelay(1);
	for(;;)
  {	
		if(imu.temp > 51 )HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
			else HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
			
  mpu_get_data();
	imu_ahrs_update();
	imu_attitude_update(); 
  HAL_GPIO_WritePin( GPIOG , LED3_Pin, GPIO_PIN_SET);
  osDelay(1);
		
  }
	
	
}









