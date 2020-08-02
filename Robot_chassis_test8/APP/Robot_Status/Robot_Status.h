#ifndef __Robot_Status_H
#define __Robot_Status_H
#ifdef __cplusplus
 extern "C" {
#endif
/***********************************************START***********************************************/
/*功能代码名称：机器人任务形态分配器所需调用库*/
#include "dji_remote.h"
/***********************************************END***************************************************/

typedef struct {
    float x;
    float y;
    float z;
} Vector3f_t;

	 
//typedef enum
//{
//	ROBOT_STATUS_INIT = 		0,		//机器人整车初始化状态
//	ROBOT_STATUS_STOPED = 	1,	//机器人整车停止
//	ROBOT_STATUS_MOVING = 	2,	//机器人整车运动
//	ROBOT_STATUS_KILLED = 	3,	//机器人整车死亡
//	ROBOT_STATUS_FAILRUE = 	4,	//机器人整车出现故障,目测不太需要
//	
//} Robot_Status_e;	 
//	 
typedef struct
{
	uint8_t  init;           //初始化状态
	uint8_t  imu_status;		 //imu加热状态
	uint8_t  placement;      //放置状态
	
	uint8_t Robot_Status_mode;
	
}Robot_Status_t;
	 
//imu初始化状态
enum
{		
    HEATING,		        //加热中
    HEAT_FINISH,		    //加热完成
    INIT_FINISH             //初始化完成 （完成加速度零偏计算）
};
//放置状态
enum
{		
    ROBOT_MOTIONAL,		    			//运动
		ROBOT_STATIC 		            //静止
};
//英雄
enum
{	
	HREO_INITIAL,         			 //初始化模式
	HERO_STANDBY,          		 		//步兵待命状态
	HERO_CHASSIS_FOLLOW_GIMBAL,   //底盘跟随云台
};


extern Robot_Status_t robot_status;
extern Vector3f_t gyro_status;//陀螺仪状态结构体
void Place_Staus_Check(Vector3f_t gyro_status);

#ifdef __cplusplus
}
#endif
#endif /*__Robot_Status_H */
