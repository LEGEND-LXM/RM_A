/*********************************************************************************************************************
 * 
 * @file       		scope.c
 *  				     ��λ������
 ********************************************************************************************************************/
#include "scope.h"
#include "stdio.h"

float Variable[16];

/***********************************************
*
*           ���ſƴ���λ�����ͺ���
*
************************************************/
//ȡһ�����ݵĸ���λ
#define BYTE0(Temp)       (*(char *)(&Temp))     
#define BYTE1(Temp)       (*((char *)(&Temp) + 1))
#define BYTE2(Temp)       (*((char *)(&Temp) + 2))
#define BYTE3(Temp)       (*((char *)(&Temp) + 3))

//���ɽ��������ַ��Ͳ���
short  wave_form_data[8] = {0};

//���ſƴ���λ��
void my_putchar(uint8_t temp)
{
	HAL_UART_Transmit(&huart8,&temp,1,10);	
   // uart_putchar(uart1,temp); //����ʵ�ʵĴ��ں�������
}

/*����֪ͨ��λ���µ�һ�����ݿ�ʼ��Ҫ�������ݱ��뷢����*/

void Send_Begin()
{
  my_putchar(0x55);
  my_putchar(0xaa);
  my_putchar(0xae);
}


void Send_Variable()
{
  uint8_t i=0,ch=0;
  float temp=0;
  uint8_t Variable_num=8;
  my_putchar(0x55);
  my_putchar(0xaa);
  my_putchar(0xad);
  my_putchar(Variable_num);
  

  
 for(i=0;i<Variable_num;i++)
  {
    temp=Variable[i];
    ch=BYTE0(temp);
      my_putchar(ch);
    ch=BYTE1(temp);
      my_putchar(ch);
    ch=BYTE2(temp);
      my_putchar(ch);
    ch=BYTE3(temp);
      my_putchar(ch);
  }
     my_putchar(0x0d);
}

void send_data(uint8_t date)
{
	HAL_UART_Transmit(&huart8,&date,1,10);
	//while( USART_GetFlagStatus(USART1,USART_FLAG_TC)!= SET);  
	
}

//ɽ����λ��
void shanwai_send_wave_form(void)
{
	uint8_t i;
	
	send_data(0x03);
	send_data(0xfc);
	for(i = 0;i<8;i++)
	{
	  send_data((wave_form_data[i]&0xff)); //�ַ��͵�λ�ڷ��͸�λ
	  send_data((wave_form_data[i]>>8));
		
	  
	}
	send_data(0xfc);
	send_data(0x03);
}	

/// �ض���c�⺯��printf��USART1
//�������´���,֧��printf����,������Ҫѡ��use MicroLIB	  
//#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)	
#if 1
#pragma import(__use_no_semihosting)             
//��׼����Ҫ��֧�ֺ���                 
struct __FILE 
{ 
	int handle; 
}; 

FILE __stdout;       
//����_sys_exit()�Ա���ʹ�ð�����ģʽ    
void _sys_exit(int x)
{ 
	x = x;
} 
//�ض���fputc���� 
int fputc(int ch, FILE *f)
{ 	
	while((UART8->SR&0X40)==0);//ѭ������,ֱ���������   
	UART8->DR = (uint8_t) ch;      
	return ch;
}
#endif
