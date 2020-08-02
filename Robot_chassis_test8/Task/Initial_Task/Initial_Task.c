#include "Initial_Task.h"
#include "Chassis_Task.h"

#include "oled.h"
#include "bsp_imu.h"

#include "robomaster_vcan.h"

void Initial_Task(void const * argument)
{
  /* USER CODE BEGIN Initial_Task */
	printf("In Initial_Task\r\n");
  oled_init();
	oled_clear(Pen_Clear);
	oled_LOGO();
	osDelay (10);
	HAL_GPIO_WritePin(POWER1_CTRL_GPIO_Port, POWER1_CTRL_Pin, GPIO_PIN_SET);//拨弹轮电机供电初始化
	MPU6500_INITIAL();//陀螺仪初始化
	oled_clear(Pen_Clear);
	oled_refresh_gram();
	
  /* Infinite loop */
  for(;;)
  {
		vTaskSuspend(vInitial_TaskHandle);//执行完基本设置初始化后就挂起
    osDelay(1);
  }
  /* USER CODE END Initial_Task */
}

