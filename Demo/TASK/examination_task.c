
#include "examination_task.h"

uint16_t testArray[4] = {0};
uint8_t value = 0;
void StartTask_Examination(void const * argument)
{
	osDelay(1);
	uint_8 i = 0;
	for(;;)
	{
		motor_info[0].rotor_speed = 0;
		motor_info[1].rotor_speed = 0;
		motor_info[2].rotor_speed = 0;
		motor_info[3].rotor_speed = 0;
		osDelay(5);
		// 底盘电机自检
		while(value == 1)
		{
			
			for(i = 0; i < 4 ; i++)
			{
				set_motor_voltage(1 ,100
														,100 
														,-100 
														,-100
													);
				osDelayUntil(&SosKernelSysTick() ,50);
				testArray[i] = motor_info[i].rotor_speed;
			}
			if(testArray[0] > 0 && testArray[1] > 0 && testArray[2] > 0 && testArray[2] > 0)
			{
				value = 1;
			} else 
				value = 0;
			
		}
		// 云台电机自检
		value = 0;
		while(value == 1)
		{
			testArray[2] = motor_info[4].rotor_angle;
			testArray[3] = motor_info[6].rotor_angle;
			for(i = 0; i < 2 ; i++)
			{
				set_motor_voltage(2 ,0
														,0 
														,1000 
														,0
													);
				set_motor_voltage(0 ,1000
														,0 
														,0 
														,0
													);
				osDelayUntil(&SosKernelSysTick() ,200);
				testArray[i] = (i == 0)?(motor_info[4].rotor_angle):(motor_info[6].rotor_angle);
				
			}
			if((testArray[0] != testArray[2])&&(testArray[1] != testArray[3]))
			{
				value = 1;
				
			} else
					value = 0;
		}
		
		// 摩擦轮及拨弹电机自检
		value = 0;
		while(value == 1)
		{
			testArray[1] = motor_info[5].rotor_angle;
			for(i = 0; i < 2 ; i++)
			{
				set_motor_voltage(0 ,0
														,1000
														,0 
														,0
													);
				osDelayUntil(&SosKernelSysTick() ,50);
				testArray[0] = motor_info[5].rotor_angle;
			}
			if(testArray[0] != testArray[1])
			{
				value = 1;
			} else
				value = 1;
		}
		vTaskDelete(Task_Task_Examination);
	}
}











