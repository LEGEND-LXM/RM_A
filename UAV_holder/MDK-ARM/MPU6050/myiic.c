#include "myiic.h"
#include "tim.h"
#include "gpio.h"
#include "TIM_delay.h"

//IIC��ʼ��
void IIC_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    //RCC->APB2ENR|=1<<4;//��ʹ������IO PORTCʱ��
	  __HAL_RCC_GPIOC_CLK_ENABLE(); 
	
	  GPIO_InitStructure.Pin = GPIO_PIN_2|GPIO_PIN_3;
    GPIO_InitStructure.Mode =GPIO_MODE_OUTPUT_PP ; //�������
    GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStructure);
	
    IIC_SCL=1;//PCout(2)
    IIC_SDA=1;//PCout(3)

}
//����IIC��ʼ�ź�
void IIC_Start(void)
{
	SDA_OUT();     //sda�����
	IIC_SDA=1;	  	  
	IIC_SCL=1;
	delayXus(4);
 	IIC_SDA=0;//START:when CLK is high,DATA change form high to low 
	delayXus(4);
	IIC_SCL=0;//ǯסI2C���ߣ�׼�����ͻ�������� 
}	  
//����IICֹͣ�ź�
void IIC_Stop(void)
{
	SDA_OUT();//sda�����
	IIC_SCL=0;
	IIC_SDA=0;//STOP:when CLK is high DATA change form low to high
 	delayXus(4);
	IIC_SCL=1; 
	delayXus(4);			
	IIC_SDA=1;//����I2C���߽����ź�				   	
}
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
uint8_t IIC_Wait_Ack(void)
{
	uint8_t ucErrTime=0;
	SDA_IN();      //SDA����Ϊ����  
	IIC_SDA=1;delayXus(1);	   
	IIC_SCL=1;delayXus(1);	 
	while(READ_SDA)
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			IIC_Stop();
			return 1;
		}
	}
	IIC_SCL=0;//ʱ�����0 	   
	return 0;  
} 
//����ACKӦ��
void IIC_Ack(void)
{
	IIC_SCL=0;
	SDA_OUT();
	IIC_SDA=0;
	delayXus(2);
	IIC_SCL=1;
	delayXus(2);
	IIC_SCL=0;
}
//������ACKӦ��		    
void IIC_NAck(void)
{
	IIC_SCL=0;
	SDA_OUT();
	IIC_SDA=1;
	delayXus(2);
	IIC_SCL=1;
	delayXus(2);
	IIC_SCL=0;
}					 				     
//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��			  
void IIC_Send_Byte(uint8_t txd)
{                        
    uint8_t t;   
	  SDA_OUT(); 	    
    IIC_SCL=0;//����ʱ�ӿ�ʼ���ݴ���
    for(t=0;t<8;t++)
    {              
        IIC_SDA=(txd&0x80)>>7;
        txd<<=1; 	  
		delayXus(2);   //��TEA5767��������ʱ���Ǳ����
		IIC_SCL=1;
		delayXus(2); 
		IIC_SCL=0;	
		delayXus(2);
    }	 
} 	    
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK   
uint8_t IIC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	SDA_IN();//SDA����Ϊ����
    for(i=0;i<8;i++ )
	{
        IIC_SCL=0; 
        delayXus(2);
		    IIC_SCL=1;
        receive <<= 1;
        if(READ_SDA)receive++;   
		delayXus(1); 
    }					 
    if (!ack)
        IIC_NAck();//����nACK
    else
        IIC_Ack(); //����ACK   
    return receive;
}

