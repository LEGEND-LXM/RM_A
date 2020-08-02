

#include "trigonometric_funtion.h"

float My_Sin(int angle);
float My_Cos(int angle);
	

/**
	*正弦函数
	*angle ：角度，单位：度，范围（0-360）
	*/
float My_Sin(int angle)
{
	uint8_t Remainder;  // 余数
	uint8_t Quotient;   // 商
	Remainder = angle % 90 ;
	Quotient = angle / 90 ;
	if ( Remainder == 0)
	{
		switch(angle){
			case 0 :
				return 0.0000;
			case 90 :
				return 1.0000;
			case 180 :
				return 0.0000;
			case 270 :
				return -1.0000;
			case 360 :
				return 0.0000;
		}
	}else 
	{
		if ( Quotient < 1)
			{
				return my_Sin_value[Remainder-1];
			}
	else
			if(1 < Quotient && Quotient < 2)
			{
				return my_Sin_value[89-Remainder];
			}
	else
			if(2 < Quotient && Quotient < 3)
			{
				return -my_Sin_value[Remainder-1];
			}
	else
			if(Quotient > 3)
			{
				return -my_Sin_value[89-Remainder];
			}
	}
	
}

/**
	*余弦函数
	*angle ：角度，单位：度，范围（0-360）
	*/
float My_Cos(int angle)
{
	uint8_t Remainder;  // 余数
	uint8_t Quotient;   // 商
	Remainder = angle % 90 ;
	Quotient = angle / 90 ;
	if ( Remainder == 0)
	{
		switch(angle){
			case 0 :
				return 1.0000;
			case 90 :
				return 0.0000;
			case 180 :
				return -1.0000;
			case 270 :
				return 0.0000;
			case 360 :
				return 1.0000;
		}
	}else 
	{
		if ( Quotient < 1)
			{
				return my_Sin_value[89-Remainder];
			}
	else
			if(1 < Quotient && Quotient < 2)
			{
				return -my_Sin_value[Remainder-1];
			}
	else
			if(2 < Quotient && Quotient < 3)
			{
				return -my_Sin_value[89-Remainder];
			}
	else
			if(Quotient > 3)
			{
				return my_Sin_value[Remainder-1];
			}
	}
	
}
