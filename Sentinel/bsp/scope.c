/*********************************************************************************************************************
 * 
 * @file       		scope.c
 *  				     上位机程序
 ********************************************************************************************************************/
#include "scope.h"
#include "stdio.h"

float Variable[16];

/***********************************************
*
*           名优科创上位机发送函数
*
************************************************/
//取一个数据的各个位
#define BYTE0(Temp)       (*(char *)(&Temp))     
#define BYTE1(Temp)       (*((char *)(&Temp) + 1))
#define BYTE2(Temp)       (*((char *)(&Temp) + 2))
#define BYTE3(Temp)       (*((char *)(&Temp) + 3))

//配合山外调试助手发送波形
short  wave_form_data[8] = {0};

//名优科创上位机
void my_putchar(uint8_t temp)
{
	HAL_UART_Transmit(&huart8,&temp,1,10);	
   // uart_putchar(uart1,temp); //根据实际的串口号来设置
}

/*用来通知上位机新的一组数据开始，要保存数据必须发送它*/

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

//山外上位机
void shanwai_send_wave_form(void)
{
	uint8_t i;
	
	send_data(0x03);
	send_data(0xfc);
	for(i = 0;i<8;i++)
	{
	  send_data((wave_form_data[i]&0xff)); //现发送低位在发送高位
	  send_data((wave_form_data[i]>>8));
		
	  
	}
	send_data(0xfc);
	send_data(0x03);
}	

/// 重定向c库函数printf到USART1
//加入以下代码,支持printf函数,而不需要选择use MicroLIB	  
//#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)	
#if 1
#pragma import(__use_no_semihosting)             
//标准库需要的支持函数                 
struct __FILE 
{ 
	int handle; 
}; 

FILE __stdout;       
//定义_sys_exit()以避免使用半主机模式    
void _sys_exit(int x)
{ 
	x = x;
} 
//重定义fputc函数 
int fputc(int ch, FILE *f)
{ 	
	while((UART8->SR&0X40)==0);//循环发送,直到发送完毕   
	UART8->DR = (uint8_t) ch;      
	return ch;
}
#endif
