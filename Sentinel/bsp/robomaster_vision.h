#ifndef __ROBOMASTER_VISION_H
#define __ROBOMASTER_VISION_H
#include "bsp_headfile.h"


#define VISION_DETECT 1 //使能视觉识别
#define ENEMYDATABUFFERLENGHT   60 //敌人数据�
#define ARMOUR_OFFSET -0.02F //敌方装甲相对于云台y轴的偏移 单位m
#define VISION_YAW_TARGET 333 //视觉yaw的目标值
#define VISION_PIT_TARGET 309 //视觉pit的目标值
//角度数据结构
typedef struct
{
		int16_t origin_yaw;
		int16_t origin_pitch;
    int16_t Yaw_Err;//yaw偏差
    int16_t Pitch_Err;
		int16_t VX;
		int16_t VY;
		int16_t HEIGHT;
		uint16_t Forcast_X;//对应云台的YAW
		uint16_t Forcast_Y;//对应于云台的PIT
		uint16_t Forcast_Z;//对应于相机相对于装甲的距离
}Angle_Err_Struct;
////点数据结构
//typedef struct
//{
//    int16_t X;
//    int16_t Y;
//    int16_t Z;
//}Point_Struct;

typedef struct
{
    Angle_Err_Struct pan_tilt_angel_err;//云台与装甲板的yaw，pitch轴偏差
	uint16_t distance;//接收测距传感器的距离 单位mm
	char recognition_success_flag; //识别成功标志位
	int check_sum;//检验数据是否正确
	uint32_t last_time;//上一帧接收视觉的时间
	uint32_t current_time;//此时接收视觉的时间
	uint16_t delta_time;//接收两帧数据的间隔时间 ms
	uint8_t vision_frame;//视觉帧率
		
}Vision_Attack;
////视觉数据结构
//typedef struct
//{
//    uint16_t X;//对应云台的YAW
//	uint16_t Y;//对应于云台的PIT
//	fp32  	 Z;//对应于相机相对于装甲的距离 
//	int16_t VX;//YAW的平移速度
//	int16_t VY;//PIT的速度
//	int16_t VZ;
//	int16_t HEIGHT;//装甲板高度
//    int TimeStamp;
//    int Time;
//    char ID;
//    uint32_t Tick;
//}Enemy_Struct;
extern Vision_Attack Armour_attack;
extern uint8_t UART6_Date[12];//串口6接收pid调参数据
void get_armour_err(void);
void armour_attack(void);
#endif

