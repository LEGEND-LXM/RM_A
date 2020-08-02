#ifndef __Initial_Task_H
#define __Initial_Task_H
#ifdef __cplusplus
 extern "C" {
#endif
	 
/********freertos需要调用的库文件********/
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
/********外设驱动库文件********/
//#include "dji_remote.h"
//#include "oled.h"
//#include "oledfont.h"	
extern osThreadId vInitial_TaskHandle;
	 
void Initial_Task(void const * argument);
	 
#ifdef __cplusplus
}
#endif
#endif /*__ usart_H */
