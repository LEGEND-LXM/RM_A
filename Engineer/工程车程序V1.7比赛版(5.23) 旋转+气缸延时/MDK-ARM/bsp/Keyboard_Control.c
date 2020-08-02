#include "Keyboard_Control.h"
#include "pid.h"
#include "Remote_Control.h"

Keybroad_Control kb;
#define kbspeed  7500           //键盘控制速度系数
float s_up = 1.65f ;                //键盘加速系数，即按下“shift”键
float kbshootspeed=1.4f;

void Keyboard_value_Init(void)                                                  //键盘结构体变量初始值
{
	//视野俯仰
	kb.q=1;
	kb.q_flag=0;
	//闭锁
	kb.e=1;
	kb.e_flag=0;
	//一键定高
	kb.Shift_r=1;
	kb.Shift_r_flag=0;
	//一键上岛
	kb.Ctrl=1;
	kb.Ctrl_flag=0;
	//涵道
	kb.z=1;
	kb.z_flag=0;
	//弹舱
	kb.x=1;
	kb.x_flag=0;
	//切换模式
	kb.c=1;
	kb.c_flag=0;
	//取弹 1 2排
	kb.b=1;
	kb.b_flag=0;
	kb.v=1;
	kb.v_flag=0;
	//抬升
	kb.r=1;
	kb.r_flag=0;
	//下降
	kb.f=1;
	kb.f_flag=0;

	kb.speed=kbspeed;
	
	kb.mousel_flag   =   0;
	kb.mouser_flag   =   0;
}

void Keyboard_Init(void)
{
	keyboard_chassis();
	keyboard_mouse();
	
		if(remote_control.keyBoard.key_code==0x40&&kb.q==1)                                   //按下"Q"视野俯仰
	{
		kb.q_flag=!kb.q_flag;
		kb.q=0;
	}	
	else if(remote_control.keyBoard.key_code!=0x40)
		kb.q=1;
	
	if(remote_control.keyBoard.key_code==0x80&&kb.e==1)                                    //按下"E"闭锁开启/关闭
	{
		kb.e_flag=!kb.e_flag;
		kb.e=0;
	}	
	else if(remote_control.keyBoard.key_code!=0x80)
		kb.e=1;
	
	if(remote_control.keyBoard.key_code==0x800&&kb.z==1)                                     //按下"Z"涵道开启/关闭
	{
		kb.z_flag=!kb.z_flag;
		kb.z=0;
	}	
	else if(remote_control.keyBoard.key_code!=0x800)
		kb.z=1;
	
	if(remote_control.keyBoard.key_code==0x1000&&kb.x==1)                                     //按下"X"弹舱开启/关闭
	{
		kb.x_flag=!kb.x_flag;
		kb.x=0;
	}	
	else if(remote_control.keyBoard.key_code!=0x1000)
		kb.x=1;
	
	
	if(remote_control.keyBoard.key_code==0x100&&kb.r==1)                                     //按下"R"抬升开启/关闭
	{
		kb.r_flag=!kb.r_flag;
		kb.r=0;
	}	
	else if(remote_control.keyBoard.key_code!=0x200)
		kb.r=1;
	
		if(remote_control.keyBoard.key_code==0x200&&kb.f==1)                                     //按下"F"下降开启/关闭
	{
		kb.f_flag=!kb.f_flag;
		kb.f=0;
	}	
	else if(remote_control.keyBoard.key_code!=0x100)
		kb.f=1;
	
	
	if(remote_control.keyBoard.key_code==0x2000&&kb.c==1)                                     //按下"C"前进方式1开启/关闭
	{
		kb.c_flag=!kb.c_flag;
		kb.c=0;
	}	
	else if(remote_control.keyBoard.key_code!=0x2000)
		kb.c=1;
//	
//	
	if(remote_control.keyBoard.key_code==0x8000&&kb.b==1)                                      //按下"B"第二排开启/关闭
	{
		kb.b_flag=!kb.b_flag;
		kb.b=0;
	}	
	else if(remote_control.keyBoard.key_code!=0x8000)
		kb.b=1;
		
	if(remote_control.keyBoard.key_code==0x4000&&kb.v==1)                                     //按下"V"第一排开启/关闭
	{
		kb.v_flag=!kb.v_flag;
		kb.v=0;
	}	
	else if(remote_control.keyBoard.key_code!=0x4000)
		kb.v=1;	

	if (remote_control.keyBoard.key_code==0x20&&kb.Ctrl==1) 			                             //按下“CTRL”一键上岛
	{
		kb.Ctrl_flag=!kb.Ctrl_flag;
		kb.Ctrl=0;
	}
	else if(remote_control.keyBoard.key_code!=0x20)
	  kb.Ctrl=1;	
	
	if (remote_control.keyBoard.key_code==0x110&&kb.Shift_r==1) 			                             //按下“Shift+R”一键上岛
	{
		kb.Shift_r_flag=!kb.Shift_r_flag;
		kb.Shift_r=0;
	}
	else if(remote_control.keyBoard.key_code!=0x110)
	  kb.Shift_r=1;	


}

void keyboard_chassis(void)
{
		//前
	if(kb.c_flag==0)//C不按
	{
		if (remote_control.keyBoard.key_code==0x01)                                  //按下“W”。车子前进
			{
//				kb.speed=0;
//				kb.speed++;
//				if(kb.speed>4000)kb.speed=4000;
				motor_pid[2].target = kb.speed;
				motor_pid[3].target =-kb.speed;
				motor_pid[0].target =-kb.speed;
				motor_pid[1].target = kb.speed;
			}
			
			else if (remote_control.keyBoard.key_code==0x02)                             //按下“S”。车子后退
			{
				motor_pid[2].target =-kb.speed;
				motor_pid[3].target = kb.speed;
				motor_pid[0].target = kb.speed;
				motor_pid[1].target =-kb.speed;
			}			

			else if (remote_control.keyBoard.key_code==0x04)                              //按下“A”。车子左移
			{
				motor_pid[2].target =-kb.speed;
				motor_pid[3].target =-kb.speed;
				motor_pid[0].target = kb.speed;
				motor_pid[1].target = kb.speed;
			}

			else if (remote_control.keyBoard.key_code==0x08)                              //按下“D”。车子右移
			{
				motor_pid[2].target = kb.speed;
				motor_pid[3].target = kb.speed;
				motor_pid[0].target =-kb.speed;
				motor_pid[1].target =-kb.speed;
			}
			
			
			else if (remote_control.keyBoard.key_code==0x11)                               //按下“SHIFT+W”。加速前进
			{
				motor_pid[2].target = kb.speed*s_up;
				motor_pid[3].target =-kb.speed*s_up;
				motor_pid[0].target =-kb.speed*s_up;
				motor_pid[1].target = kb.speed*s_up;
			}
			
			else if (remote_control.keyBoard.key_code==0x12)                               //按下“SHIFT+S”。加速后退
			{
				motor_pid[2].target =-kb.speed*s_up;
				motor_pid[3].target = kb.speed*s_up;
				motor_pid[0].target = kb.speed*s_up;
				motor_pid[1].target =-kb.speed*s_up;
			}
			
			else if (remote_control.keyBoard.key_code==0x14)                               //按下“SHIFT+A”。加速左移
			{
				motor_pid[2].target =-kb.speed*s_up;
				motor_pid[3].target =-kb.speed*s_up;
				motor_pid[0].target = kb.speed*s_up;
				motor_pid[1].target = kb.speed*s_up;
			}
			
			else if (remote_control.keyBoard.key_code==0x18)                               //按下“SHIFT+D”。加速右移
			{
				motor_pid[2].target = kb.speed*s_up;
				motor_pid[3].target = kb.speed*s_up;
				motor_pid[0].target =-kb.speed*s_up;
				motor_pid[1].target =-kb.speed*s_up;
			}
			
			else if (remote_control.keyBoard.key_code==0x05)                               //按下“W+A”。左上平移动
			{
				motor_pid[2].target =       0;
				motor_pid[3].target =-kb.speed;
				motor_pid[0].target =       0;
				motor_pid[1].target = kb.speed;
			}	
			
			else if (remote_control.keyBoard.key_code==0x09)                               //按下“W+D”。右上平移动
			{
				motor_pid[2].target = kb.speed;
				motor_pid[3].target =       0;
				motor_pid[0].target =-kb.speed;
				motor_pid[1].target =       0;
			}	
			
			else if (remote_control.keyBoard.key_code==0x06)                               //按下“A+S”。左下平移动
			{
				motor_pid[2].target =-kb.speed;
				motor_pid[3].target =       0;
				motor_pid[0].target = kb.speed;
				motor_pid[1].target =       0;
			}
			
			else if (remote_control.keyBoard.key_code==0x0A)                               //按下“D+S”。右下平移动
			{
				motor_pid[2].target =       0;
				motor_pid[3].target = kb.speed;
				motor_pid[0].target =       0;
				motor_pid[1].target =-kb.speed;
			}
			
			
			else if (remote_control.keyBoard.key_code==0x15)                               //按下“W+A+SHIIFT”。加速左上平移动
			{
				motor_pid[2].target =       0;
				motor_pid[3].target =-kb.speed*s_up;
				motor_pid[0].target =       0;
				motor_pid[1].target = kb.speed*s_up;
			}	
			
			else if (remote_control.keyBoard.key_code==0x19)                               //按下“W+D+SHIFT”。加速右上平移动
			{
				motor_pid[2].target = kb.speed*s_up;
				motor_pid[3].target =       0;
				motor_pid[0].target =-kb.speed*s_up;
				motor_pid[1].target =       0;
			}	
			
			else if (remote_control.keyBoard.key_code==0x16)                               //按下“A+S+SHIFT”。加速左下平移动
			{
				motor_pid[2].target =-kb.speed*s_up;
				motor_pid[3].target =       0;
				motor_pid[0].target = kb.speed*s_up;
				motor_pid[1].target =       0;
			}
			
			else if (remote_control.keyBoard.key_code==0x1A)                               //按下“D+S+SHIFT”。加速右下平移动
			{
				motor_pid[2].target =       0;
				motor_pid[3].target = kb.speed*s_up;
				motor_pid[0].target =       0;
				motor_pid[1].target =-kb.speed*s_up;
			}                                                                              
			
			
			
			
			else                                                                            //否则速度停止
			{
				motor_pid[2].target =       0;
				motor_pid[3].target =       0;
				motor_pid[0].target =       0;
				motor_pid[1].target =       0;
			}
	}
	
if(kb.c_flag==1)//C不按
	{
		if (remote_control.keyBoard.key_code==0x01)                                  //按下“W”。车子前进
			{
				motor_pid[0].target = kb.speed;
				motor_pid[1].target =-kb.speed;
				motor_pid[2].target =-kb.speed;
				motor_pid[3].target = kb.speed;
			}
			
			else if (remote_control.keyBoard.key_code==0x02)                             //按下“S”。车子后退
			{
				motor_pid[0].target =-kb.speed;
				motor_pid[1].target = kb.speed;
				motor_pid[2].target = kb.speed;
				motor_pid[3].target =-kb.speed;
			}			

			else if (remote_control.keyBoard.key_code==0x04)                              //按下“A”。车子左移
			{
				motor_pid[0].target =-kb.speed;
				motor_pid[1].target =-kb.speed;
				motor_pid[2].target = kb.speed;
				motor_pid[3].target = kb.speed;
			}

			else if (remote_control.keyBoard.key_code==0x08)                              //按下“D”。车子右移
			{
				motor_pid[0].target = kb.speed;
				motor_pid[1].target = kb.speed;
				motor_pid[2].target =-kb.speed;
				motor_pid[3].target =-kb.speed;
			}
			
			
			else if (remote_control.keyBoard.key_code==0x11)                               //按下“SHIFT+W”。加速前进
			{
				motor_pid[0].target = kb.speed*s_up;
				motor_pid[1].target =-kb.speed*s_up;
				motor_pid[2].target =-kb.speed*s_up;
				motor_pid[3].target = kb.speed*s_up;
			}
			
			else if (remote_control.keyBoard.key_code==0x12)                               //按下“SHIFT+S”。加速后退
			{
				motor_pid[0].target =-kb.speed*s_up;
				motor_pid[1].target = kb.speed*s_up;
				motor_pid[2].target = kb.speed*s_up;
				motor_pid[3].target =-kb.speed*s_up;
			}
			
			else if (remote_control.keyBoard.key_code==0x14)                               //按下“SHIFT+A”。加速左移
			{
				motor_pid[0].target =-kb.speed*s_up;
				motor_pid[1].target =-kb.speed*s_up;
				motor_pid[2].target = kb.speed*s_up;
				motor_pid[3].target = kb.speed*s_up;
			}
			
			else if (remote_control.keyBoard.key_code==0x18)                               //按下“SHIFT+D”。加速右移
			{
				motor_pid[0].target = kb.speed*s_up;
				motor_pid[1].target = kb.speed*s_up;
				motor_pid[2].target =-kb.speed*s_up;
				motor_pid[3].target =-kb.speed*s_up;
			}
			
			else if (remote_control.keyBoard.key_code==0x05)                               //按下“W+A”。左上平移动
			{
				motor_pid[0].target =       0;
				motor_pid[1].target =-kb.speed;
				motor_pid[2].target =       0;
				motor_pid[3].target = kb.speed;
			}	
			
			else if (remote_control.keyBoard.key_code==0x09)                               //按下“W+D”。右上平移动
			{
				motor_pid[0].target = kb.speed;
				motor_pid[1].target =       0;
				motor_pid[2].target =-kb.speed;
				motor_pid[3].target =       0;
			}	
			
			else if (remote_control.keyBoard.key_code==0x06)                               //按下“A+S”。左下平移动
			{
				motor_pid[0].target =-kb.speed;
				motor_pid[1].target =       0;
				motor_pid[2].target = kb.speed;
				motor_pid[3].target =       0;
			}
			
			else if (remote_control.keyBoard.key_code==0x0A)                               //按下“D+S”。右下平移动
			{
				motor_pid[0].target =       0;
				motor_pid[1].target = kb.speed;
				motor_pid[2].target =       0;
				motor_pid[3].target =-kb.speed;
			}
			
			
			else if (remote_control.keyBoard.key_code==0x15)                               //按下“W+A+SHIIFT”。加速左上平移动
			{
				motor_pid[0].target =       0;
				motor_pid[1].target =-kb.speed*s_up;
				motor_pid[2].target =       0;
				motor_pid[3].target = kb.speed*s_up;
			}	
			
			else if (remote_control.keyBoard.key_code==0x19)                               //按下“W+D+SHIFT”。加速右上平移动
			{
				motor_pid[0].target = kb.speed*s_up;
				motor_pid[1].target =       0;
				motor_pid[2].target =-kb.speed*s_up;
				motor_pid[3].target =       0;
			}	
			
			else if (remote_control.keyBoard.key_code==0x16)                               //按下“A+S+SHIFT”。加速左下平移动
			{
				motor_pid[0].target =-kb.speed*s_up;
				motor_pid[1].target =       0;
				motor_pid[2].target = kb.speed*s_up;
				motor_pid[3].target =       0;
			}
			
			else if (remote_control.keyBoard.key_code==0x1A)                               //按下“D+S+SHIFT”。加速右下平移动
			{
				motor_pid[0].target =       0;
				motor_pid[1].target = kb.speed*s_up;
				motor_pid[2].target =       0;
				motor_pid[3].target =-kb.speed*s_up;
			}                                                                              
			
			
			
			
			else                                                                            //否则速度停止
			{
				motor_pid[0].target =       0;
				motor_pid[1].target =       0;
				motor_pid[2].target =       0;
				motor_pid[3].target =       0;
			}
	}	
}

void keyboard_mouse(void)
{
	if(remote_control.mouse.press_left==1)
	{
		kb.mousel_flag   =   1;
		kb.mousel        =   0;
	}
	
	else if(remote_control.mouse.press_right==1)
	{
		kb.mouser_flag   =   1;
		kb.mouser        =   0;
	}
	
	else
	{
		kb.mousel_flag   =   0;
		kb.mousel        =   1;
		kb.mouser_flag   =   0;
		kb.mouser        =   1;
	}	
}
