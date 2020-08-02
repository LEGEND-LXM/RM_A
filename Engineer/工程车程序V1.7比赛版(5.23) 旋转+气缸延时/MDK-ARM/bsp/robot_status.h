#ifndef __ROBOT_STATUS_
#define __ROBOT_STATUS_
#include "robomaster_common.h"
#include "vector3.h"

typedef struct
{
    uint8_t  init;           //初始化状态
    uint8_t  imu_status;		 //imu加热状态
		uint8_t	 anomaly;				 //异常检测状态
    uint8_t  armed;          //电机锁定状态
    uint8_t  placement;      //放置状态
    uint8_t  posControl;     //位置控制状态
    uint8_t  mode;					 //步兵运行模式
    uint32_t initFinishTime; //初始化完成时间
	  uint8_t  control_mode;    //小车控制模式，分为遥控器控制和键盘控制
		uint8_t  vision_mode;     //视觉识别模式  
		uint8_t  fric_mode;				//摩擦轮模式
		uint8_t  fric_control_mode; //摩擦轮控制模式
		uint8_t  rammer_mode;			//拨弹轮模式
		uint8_t  gun_heat_state;  //枪口热量状态
} ROBOT_STATUS_t;


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
    MOTIONAL,		    			//运动
		STATIC 		            //静止
};

//工程运动模式
enum
{	
	INITIAL,         			 //初始化模式
	REMOTE_CONTROL,		        //遥控器控制
  KEYBOARD_CONTROL,		    	//键盘控制
	STANDBY,          		 //工程待命状态
	FOLLOW,           		 //底盘跟随云台
	TWIST,             		 //扭腰
	KEY_BOARD_CONTROL			 //键盘控制状态
};
//工程异常模式
//枪口热量状态
enum
{
    UNSUPER_HEAT = 0,//未超热量
    SUPER_HEAT 	 //超热量
} ;
//拨弹轮模式
enum
{			
    SAFETY,						//安全模式
		SINGLE_SHOT,		    //点射
		THRICE_SHOT,				//半自动,例如M16 3连发
		AUTO_SHOT						//自动
};

//摩擦轮模式  激活或休眠
enum
{		
		STOP,		        				//停止
    CLOSE_FIRE,							//近程制导 10m/s
		MID_FIRE,								//中程制导 15m/s
		REMOTE_FIRE,						//远程制导 20m/s
		INTERCONTINENTAL_FIRE		//洲际制导 28m/s
};
enum
{
	NORMAL,								 //正常状态
	REMOTE_CONTROL_OFFLINE,//遥控器离线
	CHASSIS_MOTOR_OFFLINE, //底盘电机离线
	PAN_TILT_OFFLINE			 //云台电机离线
	
};
extern ROBOT_STATUS_t robot_status;
void PlaceStausCheck(Vector3f_t gyro_status);
void robot_status_init(void);
void robot_status_detection(void);
#endif

