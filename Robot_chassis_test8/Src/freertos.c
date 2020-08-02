/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */     
#include "Initial_Task.h"

#include "Chassis_Task.h"
#include "Gimbal_Task1.h"
#include "dji_remote.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
#define SYSTEM_TEST 0 		//测试程序，用来测试各个模块的状态通过0 1来控制
#define SYSTEM_PROTCET 1		//保护程序开启控制0 1控制
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId vStart_TaskHandle;
osThreadId vInitial_TaskHandle;
osThreadId vChassis_TaskHandle;
osThreadId vGimbal_TaskHandle;
osThreadId vProtect_TaskHandle;
osThreadId vTask_10msHandle;
osThreadId vOut_ControlHandle;
osThreadId vRevolver_TaskHandle;
osThreadId vTest_TaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void StartTask(void const * argument);
void Initial_Task(void const * argument);
void Chassis_Task(void const * argument);
void Gimbal_Task(void const * argument);
void Protect_Task(void const * argument);
void Task_10ms(void const * argument);
void Out_Control(void const * argument);
void Revolver_Task(void const * argument);
void Test_Task(void const * argument);

extern void MX_USB_DEVICE_Init(void);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* Hook prototypes */
void configureTimerForRunTimeStats(void);
unsigned long getRunTimeCounterValue(void);

/* USER CODE BEGIN 1 */
/* Functions needed when configGENERATE_RUN_TIME_STATS is on */
__weak void configureTimerForRunTimeStats(void)
{

}

__weak unsigned long getRunTimeCounterValue(void)
{
	return 0;
}
/* USER CODE END 1 */

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];
  
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}                   
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of vStart_Task */
  osThreadDef(vStart_Task, StartTask, osPriorityRealtime, 0, 128);
  vStart_TaskHandle = osThreadCreate(osThread(vStart_Task), NULL);
  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
	printf("Everything is ready!\nStart to fight!!!!!\n");
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartTask */
/**
  * @brief  Function implementing the vStart_Task thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_StartTask */
void StartTask(void const * argument)
{
    
                 
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();

  /* USER CODE BEGIN StartTask */
		portENTER_CRITICAL();
	/************程序测试任务**************/
	#if SYSTEM_TEST
		osThreadDef(vTest_Task, Test_Task, osPriorityNormal, 0, 128);
		vTest_TaskHandle = osThreadCreate(osThread(vTest_Task), NULL);
	#else
	/************初始化任务**************/
		HAL_GPIO_WritePin(GPIOG, LED1_Pin, GPIO_PIN_RESET);
		osThreadDef(vInitial_Task, Initial_Task, osPriorityRealtime, 0, 128);
		vInitial_TaskHandle = osThreadCreate(osThread(vInitial_Task), NULL);
		HAL_GPIO_WritePin(GPIOG, LED1_Pin, GPIO_PIN_SET);
		
	/************底盘任务****************/
		HAL_GPIO_WritePin(GPIOG, LED2_Pin, GPIO_PIN_RESET);
		osThreadDef(vChassis_Task, Chassis_Task, osPriorityNormal, 0, 128);
		vChassis_TaskHandle = osThreadCreate(osThread(vChassis_Task), NULL);
		HAL_GPIO_WritePin(GPIOG, LED2_Pin, GPIO_PIN_SET);

	/************云台任务****************/
		HAL_GPIO_WritePin(GPIOG, LED3_Pin, GPIO_PIN_RESET);
		osThreadDef(vGimbal_Task, Gimbal_Task, osPriorityAboveNormal, 0, 128);
		vGimbal_TaskHandle = osThreadCreate(osThread(vGimbal_Task), NULL);
		HAL_GPIO_WritePin(GPIOG, LED3_Pin, GPIO_PIN_SET);

	/************拨盘任务****************/
		HAL_GPIO_WritePin(GPIOG, LED4_Pin, GPIO_PIN_RESET);
		osThreadDef(vRevolver_Task, Revolver_Task, osPriorityHigh, 0, 128);
		vRevolver_TaskHandle = osThreadCreate(osThread(vRevolver_Task), NULL);
		HAL_GPIO_WritePin(GPIOG, LED4_Pin, GPIO_PIN_SET);

	/************10ms任务**************/
		HAL_GPIO_WritePin(GPIOG, LED5_Pin, GPIO_PIN_RESET);
		osThreadDef(vTask_10ms, Task_10ms, osPriorityHigh, 0, 128);
		vTask_10msHandle = osThreadCreate(osThread(vTask_10ms), NULL);
		HAL_GPIO_WritePin(GPIOG, LED5_Pin, GPIO_PIN_SET);
	#endif

	#if SYSTEM_PROTCET
	/************任务失控任务**************/
		osThreadDef(vOut_Control, Out_Control, osPriorityHigh, 0, 128);
		vOut_ControlHandle = osThreadCreate(osThread(vOut_Control), NULL);

	/************失控任务控制**************/
		osThreadDef(vProtect_Task, Protect_Task, osPriorityLow, 0, 128);
		vProtect_TaskHandle = osThreadCreate(osThread(vProtect_Task), NULL);
	#endif

	vTaskDelete(vStart_TaskHandle); //删除开始任务
  portEXIT_CRITICAL();
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTask */
}
/* USER CODE BEGIN Header_Protect_Task */
/**
* @brief Function implementing the vProtect_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Protect_Task */
void Protect_Task(void const * argument)
{
  /* USER CODE BEGIN Protect_Task */
	static portTickType System_Current_Time;
  /* Infinite loop */
  for(;;)
  {
		System_Current_Time = xTaskGetTickCount();	//获取当前系统时间	
//		printf("%d %d \n",System_Current_Time,Latest_Remote_Control_Pack_Time);//系统获取时间调试
		if(System_Current_Time - Latest_Remote_Control_Pack_Time >50)//接收机离线50ms
		{
			vTaskSuspend(vChassis_TaskHandle);		//将任务挂起
			vTaskSuspend(vGimbal_TaskHandle);
			vTaskSuspend(vRevolver_TaskHandle);
			vTaskSuspend(vTask_10msHandle);
			
			vTaskResume(vOut_ControlHandle);//解挂失控保护控制任务
//			HAL_GPIO_WritePin(GPIOG, LED6_Pin, GPIO_PIN_SET);
		}
		else 
		{
			vTaskResume(vChassis_TaskHandle);		//恢复任务
			vTaskResume(vGimbal_TaskHandle);
			vTaskResume(vRevolver_TaskHandle);
			vTaskResume(vTask_10msHandle);
			
			vTaskSuspend(vOut_ControlHandle);//挂起失控保护控制任务
//			HAL_GPIO_WritePin(GPIOG, LED6_Pin, GPIO_PIN_RESET);
		}
    osDelayUntil (&System_Current_Time,50);     //绝对延时50ms
  }

  /* USER CODE END Protect_Task */
}

/* USER CODE BEGIN Header_Task_10ms */
/**
* @brief Function implementing the vTask_10ms thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_10ms */
void Task_10ms(void const * argument)
{
  /* USER CODE BEGIN Task_10ms */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_10ms */
}

/* USER CODE BEGIN Header_Out_Control */
/**
* @brief Function implementing the vOut_Control thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Out_Control */
void Out_Control(void const * argument)
{
  /* USER CODE BEGIN Out_Control */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Out_Control */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
