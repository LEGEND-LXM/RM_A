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
//		printf("��¼����λ : %d",count);
//   if(count >= 5000)
//	 {
//		 printf("���俪ʼ \r\n");
//		 for(uint32_t i = 0;i<=999;i++) printf("%f \r\n",YAW_buffer_fdb[i]);
//	 }
/*********************************************ʱ��ͳ��**********************************/
//		num++;
//		taskENTER_CRITICAL();
//		printf("����1ִ����%d�� \r\n",num);
//		taskEXIT_CRITICAL();
////		delayXus(10000);
//		portCONFIGURE_TIMER_FOR_RUN_TIME_STATS();
//		portGET_RUN_TIME_COUNTER_VALUE(); 
////		memset(RUNTIMEInfo,0,400);  //�źŻ���������
//		vTaskGetRunTimeStats(RUNTIMEInfo);  //��ȡ��������ʱ��
//		printf("������       ����ʱ��      ������ռ�ٷֱ� \r\n");
//		printf("%s\r\n",RUNTIMEInfo);
//		vTaskDelay(200);
/***************************************************************************************/		
		
		/*****************************MPUȡֵ*************************************/
		 MPU9250_GETDATA();
		  osDelay(10);                          //ս����ʱ
		  Speed_yaw    =    mpu9250->gz;        //���ٶ�
		  Speed_pit    =    mpu9250->gy;
		  Magnetic     =    mpu9250_data->mz;   //������
	  /*****************************MPUȡֵ*************************************/
			
			
			
			
/********************************����״̬�鿴��ʱ��ͳ��***************************************/
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

/**********************************freertosʱ��ͳ��******************************/
void configureTimerForRunTimeStats(void)
{
  ulHighFrequencyTimerTicks = 0ul;
}
unsigned long getRunTimeCounterValue(void)
{
  return ulHighFrequencyTimerTicks;
}
/*******************************************************************************/

