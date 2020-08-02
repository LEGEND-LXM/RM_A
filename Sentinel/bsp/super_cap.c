/**
  ******************************************************************************
  * @file	super_cap.c
  * @author  松小罗
  * @version V1.0.0
  * @date    2019/1/20
  * @brief   
  ******************************************************************************
  * @attention
  *改动：。。。。。。
  *在通过can发送电机数据前一步，调用void Super_Cap_control(int16_t *output)
  *其参数int16_t *output为需要发送的数据，若启用电容仍功率超限，函数内部会
  *对output进行限幅
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "super_cap.h"
#include "stdio.h"

ADC_HandleTypeDef hadc1;

void MX_ADC1_Init(void)
{
	ADC_ChannelConfTypeDef sConfig;
	GPIO_InitTypeDef GPIO_InitStruct;

	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_ADC1_CLK_ENABLE();
	
	GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	hadc1.Instance = ADC1;
	hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
	hadc1.Init.Resolution = ADC_RESOLUTION_12B;
	hadc1.Init.ScanConvMode = DISABLE;
	hadc1.Init.ContinuousConvMode = DISABLE;
	hadc1.Init.DiscontinuousConvMode = DISABLE;
	hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	hadc1.Init.NbrOfConversion = 1;
	hadc1.Init.DMAContinuousRequests = DISABLE;
	hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	if (HAL_ADC_Init(&hadc1) != HAL_OK)
	{
		_Error_Handler(__FILE__, __LINE__);
	}

	sConfig.Channel = ADC_CHANNEL_0;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
		_Error_Handler(__FILE__, __LINE__);
	}
}

void Super_Cap_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	//时钟已在别处打开
	GPIO_InitStruct.Pin =Super_Cap_Pin_OUT|Super_Cap_Pin_IN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(Super_Cap_Port, &GPIO_InitStruct);
	
	MX_ADC1_Init();
}

float Cap_Value=0;
//返回电压值，范围0~3.3V
float MY_ADC_GetValue(void)
{
	u8 i=50;
	u16 temp=0;
	
	HAL_ADC_Start(&hadc1);                               //开启ADC
	while(i)
		i--;
	i=50;
	HAL_ADC_PollForConversion(&hadc1,10);                //轮询转换
	while(i)
		i--;
	i=50;
	temp=(u16)HAL_ADC_GetValue(&hadc1);			         //返回最近一次ADC1规则组的转换结果
	while(i)
		i--;			//此处若不进行此操作会导致主任务中无法调用此函数（no why）
	return (float)temp*(3.3/4096);
}


#define CAP_MAX 120.0//电容最大容量
#define CAP_MIN 20.0
#define CHARGE_POWER_MAX 60.0//最大充电功率
#define CHARGE_POWER_MIN 0.0


u8 Cap_In_flag=0;//充电标志位
u8 Cap_Out_flag=0;//充电标志位
/*
//估算电容充电过程中消耗功率
参数：voltage：检测到的0-3.3范围的电压值
		 flag：是否处于充电状态
*/
float Calc_Cap_Power(float voltage,u8 flag)
{
	if(flag)
		return ((voltage*(100.0/2.4))*((CHARGE_POWER_MAX-CHARGE_POWER_MIN)/(CAP_MAX-CAP_MIN)))-(voltage*(100.0/2.4))*0.095;//补偿
	else
		return 0;
}

u8 control_state=0;//控制状态标志
void Super_Cap_control(int16_t *output)
{
	switch (control_state)
  {
    case 0://判断是否超功率
		{
			if(read_chassis_power_buffer()<150)
			{
				if(read_chassis_power()>20)//表明底盘功率已经超限
				{
					control_state=1;
				}
			}
			else
				control_state=0;//回到充电状态
		}
    break;

		case 1://检测是否任然超限
		{
			//printf("test.w\n");
			if(read_chassis_power_buffer()<150)//如果开启电容的情况下任然超限就需要输出限幅了
			{
				output[0]=output[0]*(1-(200.0-read_chassis_power_buffer())/200.0)*0.7;
				output[1]=output[1]*(1-(200.0-read_chassis_power_buffer())/200.0)*0.7;
			}
			else
				control_state=0;//回到充电状态
		}
			break;
  }
}
//调试时可打印以下值查看效果，注意调用此函数时关掉其他山外的打印活动
void Cap_Test(void)
{
	wave_form_data[0]=read_chassis_power();//功率
	wave_form_data[1]=read_chassis_power_buffer();//60J能量缓冲
	wave_form_data[2]=(MY_ADC_GetValue()*(100.0/2.4));//电容电量，人为放大100/2.4倍
	wave_form_data[3]=(Calc_Cap_Power(MY_ADC_GetValue(),Cap_In_flag));//电容实时充电功率（模拟计算出来的）
	wave_form_data[4]=control_state*10;//控制状态标志(*10倍放大)
	wave_form_data[5]=Cap_In_flag;//是否处于充电状态（1：充电状态，0：未充电状态）
	shanwai_send_wave_form();   //将数据传输到三外上位机，可以看到实时波形
}
