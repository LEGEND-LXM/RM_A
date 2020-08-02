#include "Keyboard_Control.h"
#include "pid.h"
#include "Remote_Control.h"

Keybroad_Control kb;
#define kbspeed  7500           //���̿����ٶ�ϵ��
float s_up = 1.65f ;                //���̼���ϵ���������¡�shift����
float kbshootspeed=1.4f;

void Keyboard_value_Init(void)                                                  //���̽ṹ�������ʼֵ
{
	//��Ұ����
	kb.q=1;
	kb.q_flag=0;
	//����
	kb.e=1;
	kb.e_flag=0;
	//һ������
	kb.Shift_r=1;
	kb.Shift_r_flag=0;
	//һ���ϵ�
	kb.Ctrl=1;
	kb.Ctrl_flag=0;
	//����
	kb.z=1;
	kb.z_flag=0;
	//����
	kb.x=1;
	kb.x_flag=0;
	//�л�ģʽ
	kb.c=1;
	kb.c_flag=0;
	//ȡ�� 1 2��
	kb.b=1;
	kb.b_flag=0;
	kb.v=1;
	kb.v_flag=0;
	//̧��
	kb.r=1;
	kb.r_flag=0;
	//�½�
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
	
		if(remote_control.keyBoard.key_code==0x40&&kb.q==1)                                   //����"Q"��Ұ����
	{
		kb.q_flag=!kb.q_flag;
		kb.q=0;
	}	
	else if(remote_control.keyBoard.key_code!=0x40)
		kb.q=1;
	
	if(remote_control.keyBoard.key_code==0x80&&kb.e==1)                                    //����"E"��������/�ر�
	{
		kb.e_flag=!kb.e_flag;
		kb.e=0;
	}	
	else if(remote_control.keyBoard.key_code!=0x80)
		kb.e=1;
	
	if(remote_control.keyBoard.key_code==0x800&&kb.z==1)                                     //����"Z"��������/�ر�
	{
		kb.z_flag=!kb.z_flag;
		kb.z=0;
	}	
	else if(remote_control.keyBoard.key_code!=0x800)
		kb.z=1;
	
	if(remote_control.keyBoard.key_code==0x1000&&kb.x==1)                                     //����"X"���տ���/�ر�
	{
		kb.x_flag=!kb.x_flag;
		kb.x=0;
	}	
	else if(remote_control.keyBoard.key_code!=0x1000)
		kb.x=1;
	
	
	if(remote_control.keyBoard.key_code==0x100&&kb.r==1)                                     //����"R"̧������/�ر�
	{
		kb.r_flag=!kb.r_flag;
		kb.r=0;
	}	
	else if(remote_control.keyBoard.key_code!=0x200)
		kb.r=1;
	
		if(remote_control.keyBoard.key_code==0x200&&kb.f==1)                                     //����"F"�½�����/�ر�
	{
		kb.f_flag=!kb.f_flag;
		kb.f=0;
	}	
	else if(remote_control.keyBoard.key_code!=0x100)
		kb.f=1;
	
	
	if(remote_control.keyBoard.key_code==0x2000&&kb.c==1)                                     //����"C"ǰ����ʽ1����/�ر�
	{
		kb.c_flag=!kb.c_flag;
		kb.c=0;
	}	
	else if(remote_control.keyBoard.key_code!=0x2000)
		kb.c=1;
//	
//	
	if(remote_control.keyBoard.key_code==0x8000&&kb.b==1)                                      //����"B"�ڶ��ſ���/�ر�
	{
		kb.b_flag=!kb.b_flag;
		kb.b=0;
	}	
	else if(remote_control.keyBoard.key_code!=0x8000)
		kb.b=1;
		
	if(remote_control.keyBoard.key_code==0x4000&&kb.v==1)                                     //����"V"��һ�ſ���/�ر�
	{
		kb.v_flag=!kb.v_flag;
		kb.v=0;
	}	
	else if(remote_control.keyBoard.key_code!=0x4000)
		kb.v=1;	

	if (remote_control.keyBoard.key_code==0x20&&kb.Ctrl==1) 			                             //���¡�CTRL��һ���ϵ�
	{
		kb.Ctrl_flag=!kb.Ctrl_flag;
		kb.Ctrl=0;
	}
	else if(remote_control.keyBoard.key_code!=0x20)
	  kb.Ctrl=1;	
	
	if (remote_control.keyBoard.key_code==0x110&&kb.Shift_r==1) 			                             //���¡�Shift+R��һ���ϵ�
	{
		kb.Shift_r_flag=!kb.Shift_r_flag;
		kb.Shift_r=0;
	}
	else if(remote_control.keyBoard.key_code!=0x110)
	  kb.Shift_r=1;	


}

void keyboard_chassis(void)
{
		//ǰ
	if(kb.c_flag==0)//C����
	{
		if (remote_control.keyBoard.key_code==0x01)                                  //���¡�W��������ǰ��
			{
//				kb.speed=0;
//				kb.speed++;
//				if(kb.speed>4000)kb.speed=4000;
				motor_pid[2].target = kb.speed;
				motor_pid[3].target =-kb.speed;
				motor_pid[0].target =-kb.speed;
				motor_pid[1].target = kb.speed;
			}
			
			else if (remote_control.keyBoard.key_code==0x02)                             //���¡�S�������Ӻ���
			{
				motor_pid[2].target =-kb.speed;
				motor_pid[3].target = kb.speed;
				motor_pid[0].target = kb.speed;
				motor_pid[1].target =-kb.speed;
			}			

			else if (remote_control.keyBoard.key_code==0x04)                              //���¡�A������������
			{
				motor_pid[2].target =-kb.speed;
				motor_pid[3].target =-kb.speed;
				motor_pid[0].target = kb.speed;
				motor_pid[1].target = kb.speed;
			}

			else if (remote_control.keyBoard.key_code==0x08)                              //���¡�D������������
			{
				motor_pid[2].target = kb.speed;
				motor_pid[3].target = kb.speed;
				motor_pid[0].target =-kb.speed;
				motor_pid[1].target =-kb.speed;
			}
			
			
			else if (remote_control.keyBoard.key_code==0x11)                               //���¡�SHIFT+W��������ǰ��
			{
				motor_pid[2].target = kb.speed*s_up;
				motor_pid[3].target =-kb.speed*s_up;
				motor_pid[0].target =-kb.speed*s_up;
				motor_pid[1].target = kb.speed*s_up;
			}
			
			else if (remote_control.keyBoard.key_code==0x12)                               //���¡�SHIFT+S�������ٺ���
			{
				motor_pid[2].target =-kb.speed*s_up;
				motor_pid[3].target = kb.speed*s_up;
				motor_pid[0].target = kb.speed*s_up;
				motor_pid[1].target =-kb.speed*s_up;
			}
			
			else if (remote_control.keyBoard.key_code==0x14)                               //���¡�SHIFT+A������������
			{
				motor_pid[2].target =-kb.speed*s_up;
				motor_pid[3].target =-kb.speed*s_up;
				motor_pid[0].target = kb.speed*s_up;
				motor_pid[1].target = kb.speed*s_up;
			}
			
			else if (remote_control.keyBoard.key_code==0x18)                               //���¡�SHIFT+D������������
			{
				motor_pid[2].target = kb.speed*s_up;
				motor_pid[3].target = kb.speed*s_up;
				motor_pid[0].target =-kb.speed*s_up;
				motor_pid[1].target =-kb.speed*s_up;
			}
			
			else if (remote_control.keyBoard.key_code==0x05)                               //���¡�W+A��������ƽ�ƶ�
			{
				motor_pid[2].target =       0;
				motor_pid[3].target =-kb.speed;
				motor_pid[0].target =       0;
				motor_pid[1].target = kb.speed;
			}	
			
			else if (remote_control.keyBoard.key_code==0x09)                               //���¡�W+D��������ƽ�ƶ�
			{
				motor_pid[2].target = kb.speed;
				motor_pid[3].target =       0;
				motor_pid[0].target =-kb.speed;
				motor_pid[1].target =       0;
			}	
			
			else if (remote_control.keyBoard.key_code==0x06)                               //���¡�A+S��������ƽ�ƶ�
			{
				motor_pid[2].target =-kb.speed;
				motor_pid[3].target =       0;
				motor_pid[0].target = kb.speed;
				motor_pid[1].target =       0;
			}
			
			else if (remote_control.keyBoard.key_code==0x0A)                               //���¡�D+S��������ƽ�ƶ�
			{
				motor_pid[2].target =       0;
				motor_pid[3].target = kb.speed;
				motor_pid[0].target =       0;
				motor_pid[1].target =-kb.speed;
			}
			
			
			else if (remote_control.keyBoard.key_code==0x15)                               //���¡�W+A+SHIIFT������������ƽ�ƶ�
			{
				motor_pid[2].target =       0;
				motor_pid[3].target =-kb.speed*s_up;
				motor_pid[0].target =       0;
				motor_pid[1].target = kb.speed*s_up;
			}	
			
			else if (remote_control.keyBoard.key_code==0x19)                               //���¡�W+D+SHIFT������������ƽ�ƶ�
			{
				motor_pid[2].target = kb.speed*s_up;
				motor_pid[3].target =       0;
				motor_pid[0].target =-kb.speed*s_up;
				motor_pid[1].target =       0;
			}	
			
			else if (remote_control.keyBoard.key_code==0x16)                               //���¡�A+S+SHIFT������������ƽ�ƶ�
			{
				motor_pid[2].target =-kb.speed*s_up;
				motor_pid[3].target =       0;
				motor_pid[0].target = kb.speed*s_up;
				motor_pid[1].target =       0;
			}
			
			else if (remote_control.keyBoard.key_code==0x1A)                               //���¡�D+S+SHIFT������������ƽ�ƶ�
			{
				motor_pid[2].target =       0;
				motor_pid[3].target = kb.speed*s_up;
				motor_pid[0].target =       0;
				motor_pid[1].target =-kb.speed*s_up;
			}                                                                              
			
			
			
			
			else                                                                            //�����ٶ�ֹͣ
			{
				motor_pid[2].target =       0;
				motor_pid[3].target =       0;
				motor_pid[0].target =       0;
				motor_pid[1].target =       0;
			}
	}
	
if(kb.c_flag==1)//C����
	{
		if (remote_control.keyBoard.key_code==0x01)                                  //���¡�W��������ǰ��
			{
				motor_pid[0].target = kb.speed;
				motor_pid[1].target =-kb.speed;
				motor_pid[2].target =-kb.speed;
				motor_pid[3].target = kb.speed;
			}
			
			else if (remote_control.keyBoard.key_code==0x02)                             //���¡�S�������Ӻ���
			{
				motor_pid[0].target =-kb.speed;
				motor_pid[1].target = kb.speed;
				motor_pid[2].target = kb.speed;
				motor_pid[3].target =-kb.speed;
			}			

			else if (remote_control.keyBoard.key_code==0x04)                              //���¡�A������������
			{
				motor_pid[0].target =-kb.speed;
				motor_pid[1].target =-kb.speed;
				motor_pid[2].target = kb.speed;
				motor_pid[3].target = kb.speed;
			}

			else if (remote_control.keyBoard.key_code==0x08)                              //���¡�D������������
			{
				motor_pid[0].target = kb.speed;
				motor_pid[1].target = kb.speed;
				motor_pid[2].target =-kb.speed;
				motor_pid[3].target =-kb.speed;
			}
			
			
			else if (remote_control.keyBoard.key_code==0x11)                               //���¡�SHIFT+W��������ǰ��
			{
				motor_pid[0].target = kb.speed*s_up;
				motor_pid[1].target =-kb.speed*s_up;
				motor_pid[2].target =-kb.speed*s_up;
				motor_pid[3].target = kb.speed*s_up;
			}
			
			else if (remote_control.keyBoard.key_code==0x12)                               //���¡�SHIFT+S�������ٺ���
			{
				motor_pid[0].target =-kb.speed*s_up;
				motor_pid[1].target = kb.speed*s_up;
				motor_pid[2].target = kb.speed*s_up;
				motor_pid[3].target =-kb.speed*s_up;
			}
			
			else if (remote_control.keyBoard.key_code==0x14)                               //���¡�SHIFT+A������������
			{
				motor_pid[0].target =-kb.speed*s_up;
				motor_pid[1].target =-kb.speed*s_up;
				motor_pid[2].target = kb.speed*s_up;
				motor_pid[3].target = kb.speed*s_up;
			}
			
			else if (remote_control.keyBoard.key_code==0x18)                               //���¡�SHIFT+D������������
			{
				motor_pid[0].target = kb.speed*s_up;
				motor_pid[1].target = kb.speed*s_up;
				motor_pid[2].target =-kb.speed*s_up;
				motor_pid[3].target =-kb.speed*s_up;
			}
			
			else if (remote_control.keyBoard.key_code==0x05)                               //���¡�W+A��������ƽ�ƶ�
			{
				motor_pid[0].target =       0;
				motor_pid[1].target =-kb.speed;
				motor_pid[2].target =       0;
				motor_pid[3].target = kb.speed;
			}	
			
			else if (remote_control.keyBoard.key_code==0x09)                               //���¡�W+D��������ƽ�ƶ�
			{
				motor_pid[0].target = kb.speed;
				motor_pid[1].target =       0;
				motor_pid[2].target =-kb.speed;
				motor_pid[3].target =       0;
			}	
			
			else if (remote_control.keyBoard.key_code==0x06)                               //���¡�A+S��������ƽ�ƶ�
			{
				motor_pid[0].target =-kb.speed;
				motor_pid[1].target =       0;
				motor_pid[2].target = kb.speed;
				motor_pid[3].target =       0;
			}
			
			else if (remote_control.keyBoard.key_code==0x0A)                               //���¡�D+S��������ƽ�ƶ�
			{
				motor_pid[0].target =       0;
				motor_pid[1].target = kb.speed;
				motor_pid[2].target =       0;
				motor_pid[3].target =-kb.speed;
			}
			
			
			else if (remote_control.keyBoard.key_code==0x15)                               //���¡�W+A+SHIIFT������������ƽ�ƶ�
			{
				motor_pid[0].target =       0;
				motor_pid[1].target =-kb.speed*s_up;
				motor_pid[2].target =       0;
				motor_pid[3].target = kb.speed*s_up;
			}	
			
			else if (remote_control.keyBoard.key_code==0x19)                               //���¡�W+D+SHIFT������������ƽ�ƶ�
			{
				motor_pid[0].target = kb.speed*s_up;
				motor_pid[1].target =       0;
				motor_pid[2].target =-kb.speed*s_up;
				motor_pid[3].target =       0;
			}	
			
			else if (remote_control.keyBoard.key_code==0x16)                               //���¡�A+S+SHIFT������������ƽ�ƶ�
			{
				motor_pid[0].target =-kb.speed*s_up;
				motor_pid[1].target =       0;
				motor_pid[2].target = kb.speed*s_up;
				motor_pid[3].target =       0;
			}
			
			else if (remote_control.keyBoard.key_code==0x1A)                               //���¡�D+S+SHIFT������������ƽ�ƶ�
			{
				motor_pid[0].target =       0;
				motor_pid[1].target = kb.speed*s_up;
				motor_pid[2].target =       0;
				motor_pid[3].target =-kb.speed*s_up;
			}                                                                              
			
			
			
			
			else                                                                            //�����ٶ�ֹͣ
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
