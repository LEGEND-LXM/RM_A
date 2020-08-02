#include "User_task.h"
#include "oled.h"
#include "bsp_imu.h"

#include "robomaster_vcan.h"

extern imu_t      imu;

void User_Task(void const * argument)
{
  /* USER CODE BEGIN User_Task */
	
	printf ("In User_Task!\r\n");
  /* Infinite loop */
  for(;;)
  {
		MPU6500_GET_DATA();
		osDelay(5);
		printf(" Roll: %8.3lf  Pitch: %8.3lf  Yaw: %8.3lf\n", imu.rol, imu.pit, imu.yaw);
		
		wave_form_data[0]=imu.rol;
		wave_form_data[1]=imu.pit;
		wave_form_data[2]=imu.yaw;
		wave_form_data[3]=imu.temp;
		wave_form_data[4]=mpu_data.gz;
		shanwai_send_wave_form();
    osDelay(10);
  }
  /* USER CODE END User_Task */
}


