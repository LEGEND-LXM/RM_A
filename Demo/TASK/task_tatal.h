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


//结构体声明
//extern SHOOT_Type SHOOT_Ture ;                      //射击机构结构体
//extern pid_struct_t Frictiongear_motor_PID[2] ;     //摩擦轮PID结构体
//extern pid_struct_t Ammunition_Booster_PID ;        //拨弹电机PID结构体
//extern moto_info_t  Ammunition_Booster_info ;       //拨弹电机CAN结构体
//extern HALDER_Type HALDER_Ture ;
//extern pid_struct_t Holder_motor_PID[2] ;
//extern moto_info_t  Holder_motor_info[2] ;
//extern VISUAL_Type VISUAL_Ture ;
#define PI                 3.14159265358979f



//系统生成库
#include "main.h"
#include "usart.h"
#include "tim.h"
#include "usbd_cdc_if.h"
#include "usb_device.h"
#include "stdint.h"

//实时系统task库
#include "task_init.h"            //任务创建
#include "imu_task.h"             //陀螺仪
#include "waveform_task.h"        //波形助手
#include "task_schedule.h"        //任务调度
#include "holder_task.h"          //云台任务
#include "chassis_task.h"         //地盘任务
#include "shoot_task.h"           //发射机构任务
#include "visual_task.h"          //视觉通信
#include "examination_task.h"     //机器人自检任务

//bsp应用库
#include "bsp_imu.h"
#include "bsp_can.h"
#include "bsp_tim.h"
#include "bsp_pwm.h"
#include "bsp_usart.h"
#include "bsp_key.h"
#include "robomaster_vcan.h"
#include "pid.h"


//freertos库
#include "cmsis_os.h"


//其它应用库
#include "oled.h"
#include "user_lib.h"
#include "robomaster_filter.h"
#include "trigonometric_funtion.h"   // 三角函数库：cos、sin


#endif







