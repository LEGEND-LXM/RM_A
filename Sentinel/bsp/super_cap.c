/**
  ******************************************************************************
  * @file	super_cap.c
  * @author  ��С��
  * @version V1.0.0
  * @date    2019/1/20
  * @brief   
  ******************************************************************************
  * @attention
  *�Ķ���������������
  *��ͨ��can���͵������ǰһ��������void Super_Cap_control(int16_t *output)
  *�����int16_t *outputΪ��Ҫ���͵����ݣ������õ����Թ��ʳ��ޣ������ڲ���
  *��output�����޷�
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
	//ʱ�����ڱ𴦴�
	GPIO_InitStruct.Pin =Super_Cap_Pin_OUT|Super_Cap_Pin_IN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(Super_Cap_Port, &GPIO_InitStruct);
	
	MX_ADC1_Init();
}

float Cap_Value=0;
//���ص�ѹֵ����Χ0~3.3V
float MY_ADC_GetValue(void)
{
	u8 i=50;
	u16 temp=0;
	
	HAL_ADC_Start(&hadc1);                               //����ADC
	while(i)
		i--;
	i=50;
	HAL_ADC_PollForConversion(&hadc1,10);                //��ѯת��
	while(i)
		i--;
	i=50;
	temp=(u16)HAL_ADC_GetValue(&hadc1);			         //�������һ��ADC1�������ת�����
	while(i)
		i--;			//�˴��������д˲����ᵼ�����������޷����ô˺�����no why��
	return (float)temp*(3.3/4096);
}


#define CAP_MAX 120.0//�����������
#define CAP_MIN 20.0
#define CHARGE_POWER_MAX 60.0//����繦��
#define CHARGE_POWER_MIN 0.0


u8 Cap_In_flag=0;//����־λ
u8 Cap_Out_flag=0;//����־λ
/*
//������ݳ����������Ĺ���
������voltage����⵽��0-3.3��Χ�ĵ�ѹֵ
		 flag���Ƿ��ڳ��״̬
*/
float Calc_Cap_Power(float voltage,u8 flag)
{
	if(flag)
		return ((voltage*(100.0/2.4))*((CHARGE_POWER_MAX-CHARGE_POWER_MIN)/(CAP_MAX-CAP_MIN)))-(voltage*(100.0/2.4))*0.095;//����
	else
		return 0;
}

u8 control_state=0;//����״̬��־
void Super_Cap_control(int16_t *output)
{
	switch (control_state)
  {
    case 0://�ж��Ƿ񳬹���
		{
			if(read_chassis_power_buffer()<150)
			{
				if(read_chassis_power()>20)//�������̹����Ѿ�����
				{
					control_state=1;
				}
			}
			else
				control_state=0;//�ص����״̬
		}
    break;

		case 1://����Ƿ���Ȼ����
		{
			//printf("test.w\n");
			if(read_chassis_power_buffer()<150)//����������ݵ��������Ȼ���޾���Ҫ����޷���
			{
				output[0]=output[0]*(1-(200.0-read_chassis_power_buffer())/200.0)*0.7;
				output[1]=output[1]*(1-(200.0-read_chassis_power_buffer())/200.0)*0.7;
			}
			else
				control_state=0;//�ص����״̬
		}
			break;
  }
}
//����ʱ�ɴ�ӡ����ֵ�鿴Ч����ע����ô˺���ʱ�ص�����ɽ��Ĵ�ӡ�
void Cap_Test(void)
{
	wave_form_data[0]=read_chassis_power();//����
	wave_form_data[1]=read_chassis_power_buffer();//60J��������
	wave_form_data[2]=(MY_ADC_GetValue()*(100.0/2.4));//���ݵ�������Ϊ�Ŵ�100/2.4��
	wave_form_data[3]=(Calc_Cap_Power(MY_ADC_GetValue(),Cap_In_flag));//����ʵʱ��繦�ʣ�ģ���������ģ�
	wave_form_data[4]=control_state*10;//����״̬��־(*10���Ŵ�)
	wave_form_data[5]=Cap_In_flag;//�Ƿ��ڳ��״̬��1�����״̬��0��δ���״̬��
	shanwai_send_wave_form();   //�����ݴ��䵽������λ�������Կ���ʵʱ����
}
