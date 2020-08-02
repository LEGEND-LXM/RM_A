/************************************************
void oled_init(void);
void oled_write_byte(uint8_t dat, uint8_t cmd);
void oled_display_on(void);
void oled_display_off(void);
void oled_refresh_gram(void);
void oled_clear(Pen_Typedef pen);
void oled_drawpoint(int8_t x, int8_t y, Pen_Typedef pen);
void oled_drawline(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, Pen_Typedef pen);
void oled_showchar(uint8_t row, uint8_t col, uint8_t chr);
void oled_shownum(uint8_t row, uint8_t col, uint32_t num, uint8_t mode, uint8_t len);
void oled_showstring(uint8_t row, uint8_t col, uint8_t *chr);
void oled_printf(uint8_t row, uint8_t col, const char *fmt,...);
void oled_LOGO(void);
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);

************************************************/

#ifndef __TASK_TATAL
#define __TASK_TATAL


//�ṹ������
//extern SHOOT_Type SHOOT_Ture ;                      //��������ṹ��
//extern pid_struct_t Frictiongear_motor_PID[2] ;     //Ħ����PID�ṹ��
//extern pid_struct_t Ammunition_Booster_PID ;        //�������PID�ṹ��
//extern moto_info_t  Ammunition_Booster_info ;       //�������CAN�ṹ��
//extern HALDER_Type HALDER_Ture ;
//extern pid_struct_t Holder_motor_PID[2] ;
//extern moto_info_t  Holder_motor_info[2] ;
//extern VISUAL_Type VISUAL_Ture ;
#define PI                 3.14159265358979f



//ϵͳ���ɿ�
#include "main.h"
#include "usart.h"
#include "tim.h"
#include "usbd_cdc_if.h"
#include "usb_device.h"
#include "stdint.h"

//ʵʱϵͳtask��
#include "task_init.h"            //���񴴽�
#include "imu_task.h"             //������
#include "waveform_task.h"        //��������
#include "task_schedule.h"        //�������
#include "holder_task.h"          //��̨����
#include "chassis_task.h"         //��������
#include "shoot_task.h"           //�����������
#include "visual_task.h"          //�Ӿ�ͨ��
#include "examination_task.h"     //�������Լ�����

//bspӦ�ÿ�
#include "bsp_imu.h"
#include "bsp_can.h"
#include "bsp_tim.h"
#include "bsp_pwm.h"
#include "bsp_usart.h"
#include "bsp_key.h"
#include "robomaster_vcan.h"
#include "pid.h"


//freertos��
#include "cmsis_os.h"


//����Ӧ�ÿ�
#include "oled.h"
#include "user_lib.h"
#include "robomaster_filter.h"
#include "trigonometric_funtion.h"   // ���Ǻ����⣺cos��sin


#endif







