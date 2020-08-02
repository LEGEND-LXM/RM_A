#include "Init.h"
#include "test_task.h"

uint8_t  pcWriteBuffer[200];
volatile unsigned long  ulHighFrequencyTimerTicks = 0ul;
extern moto_info_t motor_info[MOTOR_MAX_NUM];
extern float YAW_buffer_fdb[1000],YAW_buffer_ref[1000];
extern uint32_t count;
extern int32_t beep_flag;
volatile float Speed_yaw,Speed_pit,Magnetic;
void test_Task(void const * argument)
{
	double fabs(double x);
//	char RUNTIMEInfo[400];
	for(;;)
	{
//		printf("记录数据位 : %d",count);
//   if(count >= 5000)
//	 {
//		 printf("传输开始 \r\n");
//		 for(uint32_t i = 0;i<=999;i++) printf("%f \r\n",YAW_buffer_fdb[i]);
//	 }
/*********************************************时间统计**********************************/
//		num++;
//		taskENTER_CRITICAL();
//		printf("任务1执行了%d次 \r\n",num);
//		taskEXIT_CRITICAL();
////		delayXus(10000);
//		portCONFIGURE_TIMER_FOR_RUN_TIME_STATS();
//		portGET_RUN_TIME_COUNTER_VALUE(); 
////		memset(RUNTIMEInfo,0,400);  //信号缓冲区清零
//		vTaskGetRunTimeStats(RUNTIMEInfo);  //获取任务运行时间
//		printf("任务名       运行时间      运行所占百分比 \r\n");
//		printf("%s\r\n",RUNTIMEInfo);
//		vTaskDelay(200);
/***************************************************************************************/		
		
		/*****************************MPU取值*************************************/
		 MPU9250_GETDATA();
		  osDelay(10);                          //战术延时
		  Speed_yaw    =    mpu9250->gz;        //角速度
		  Speed_pit    =    mpu9250->gy;
		  Magnetic     =    mpu9250_data->mz;   //磁力计
	  /*****************************MPU取值*************************************/
			
			
			
			
/********************************任务状态查看与时间统计***************************************/
//	printf("=================================================\r\n");
//	printf("\r\ntask_name  \tstate\t prior\tstack\t Id\r\n");
//	vTaskList((char *)&pcWriteBuffer);
//	printf("%s\r\n", pcWriteBuffer);

//	printf("\r\ntask_name     time_count(10us) usage_pec\r\n");
//	vTaskGetRunTimeStats((char *)&pcWriteBuffer);
//	printf("%s\r\n", pcWriteBuffer);

/*******************************************************************************************/

	}
}

/**********************************freertos时间统计******************************/
void configureTimerForRunTimeStats(void)
{
  ulHighFrequencyTimerTicks = 0ul;
}
unsigned long getRunTimeCounterValue(void)
{
  return ulHighFrequencyTimerTicks;
}
/*******************************************************************************/

