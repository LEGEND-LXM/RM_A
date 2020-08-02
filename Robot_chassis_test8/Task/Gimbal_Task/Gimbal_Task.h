#ifndef __Gimbal_Task_H
#define __Gimbal_Task_H
#ifdef __cplusplus
 extern "C" {
#endif
	 
/********freertos需要调用的库文件********/
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
/********外设驱动库文件********/
#include "dji_remote.h"
//#include "oled.h"
//#include "oledfont.h"	
#include "pid.h"
	 
//任务初始化 空闲一段时间
#define GIMBAL_TASK_INIT_TIME 201

//电机是否反装
#define PITCH_TURN 0
#define YAW_TURN 0
	 
//电机码盘值最大以及中值
#define Half_ecd_range 4096
#define ecd_range 8191

//云台电机的最初角度
#define YAW_ENCODE_OFFEST 			4766.0f			//YAW轴机械中值 
#define PITCH_ENCODE_OFFEST 		1120.0f			//pitch轴机械中值
#define YAW_MAX_ENCODE_ANGLE 		3828.0f							//机械最大最小值
#define YAW_MIN_ENCODE_ANGLE 		5720.0f
#define PITCH_MAX_ENCODE_ANGLE 	41.0f
#define PITCH_MIN_ENCODE_ANGLE 	2150.0f

	 
//pitch 速度环 PID参数以及 PID最大输出，积分输出
#define PITCH_SPEED_PID_KP 1220.0f//2000.0f
#define PITCH_SPEED_PID_KI 0.0f//20.0f
#define PITCH_SPEED_PID_KD 0.0f
#define PITCH_SPEED_PID_MAX_OUT 30000.f//30000.0f
#define PITCH_SPEED_PID_MAX_IOUT 5000.0f

//yaw 速度环 PID参数以及 PID最大输出，积分输出
#define YAW_SPEED_PID_KP 1000.0f
#define YAW_SPEED_PID_KI 0.0f//20.0f
#define YAW_SPEED_PID_KD 0.0f
#define YAW_SPEED_PID_MAX_OUT 30000.0f
#define YAW_SPEED_PID_MAX_IOUT 5000.0f

//pitch 角度环 角度由陀螺仪解算 PID参数以及 PID最大输出，积分输出
#define PITCH_GYRO_ABSOLUTE_PID_KP 15.0f
#define PITCH_GYRO_ABSOLUTE_PID_KI 0.0f
#define PITCH_GYRO_ABSOLUTE_PID_KD 0.0f

#define PITCH_GYRO_ABSOLUTE_PID_MAX_OUT 10.0f
#define PITCH_GYRO_ABSOLUTE_PID_MAX_IOUT 0.0f

//yaw 角度环 角度由陀螺仪解算 PID参数以及 PID最大输出，积分输出
#define YAW_GYRO_ABSOLUTE_PID_KP 10.0f
#define YAW_GYRO_ABSOLUTE_PID_KI 0.0f
#define YAW_GYRO_ABSOLUTE_PID_KD 0.3f
#define YAW_GYRO_ABSOLUTE_PID_MAX_OUT 10.0f
#define YAW_GYRO_ABSOLUTE_PID_MAX_IOUT 0.0f

//pitch 角度环 角度由编码器 PID参数以及 PID最大输出，积分输出
#define PITCH_ENCODE_RELATIVE_PID_KP 15.0f
#define PITCH_ENCODE_RELATIVE_PID_KI 0.00f
#define PITCH_ENCODE_RELATIVE_PID_KD 0.0f

#define PITCH_ENCODE_RELATIVE_PID_MAX_OUT 10.0f
#define PITCH_ENCODE_RELATIVE_PID_MAX_IOUT 0.0f

//yaw 角度环 角度由编码器 PID参数以及 PID最大输出，积分输出
#define YAW_ENCODE_RELATIVE_PID_KP 8.0f
#define YAW_ENCODE_RELATIVE_PID_KI 0.0f
#define YAW_ENCODE_RELATIVE_PID_KD 0.0f
#define YAW_ENCODE_RELATIVE_PID_MAX_OUT 10.0f
#define YAW_ENCODE_RELATIVE_PID_MAX_IOUT 0.0f
	 
//掉头180 按键
#define TurnKeyBoard KEY_PRESSED_OFFSET_F
//掉头云台速度
#define TurnSpeed 0.04f
//测试按键尚未使用
#define TestKeyBoard KEY_PRESSED_OFFSET_R
	 
//云台初始化回中值，允许的误差,并且在误差范围内停止一段时间以及最大时间6s后解除初始化状态，
#define GIMBAL_INIT_ANGLE_ERROR 0.1f
#define GIMBAL_INIT_STOP_TIME 100
#define GIMBAL_INIT_TIME 6000
	 
//云台初始化回中值的速度以及控制到的角度
#define GIMBAL_INIT_PITCH_SPEED 0.004f
#define GIMBAL_INIT_YAW_SPEED   0.005f
#define INIT_YAW_SET 0.0f
#define INIT_PITCH_SET 0.0f
	 
////云台校准中值的时候，发送原始电流值，以及堵转时间，通过陀螺仪判断堵转
//#define GIMBAL_CALI_MOTOR_SET 8000
//#define GIMBAL_CALI_STEP_TIME 2000
//#define GIMBAL_CALI_GYRO_LIMIT 0.1f

//#define GIMBAL_CALI_PITCH_MAX_STEP 1
//#define GIMBAL_CALI_PITCH_MIN_STEP 2
//#define GIMBAL_CALI_YAW_MAX_STEP 3
//#define GIMBAL_CALI_YAW_MIN_STEP 4

//#define GIMBAL_CALI_START_STEP GIMBAL_CALI_PITCH_MAX_STEP
//#define GIMBAL_CALI_END_STEP 5

//遥控器输入死区，因为遥控器存在差异，摇杆在中间，其值不一定为零
#define RC_deadband 10
//yaw，pitch角度与遥控器输入比例
#define Yaw_RC_SEN -0.000005f
#define Pitch_RC_SEN -0.000006f //0.005
//yaw,pitch角度和鼠标输入的比例
#define Yaw_Mouse_Sen 0.00005f
#define Pitch_Mouse_Sen 0.00015f

//判断遥控器无输入的时间以及遥控器无输入判断，设置云台yaw回中值以防陀螺仪漂移//暂时无人调用
#define GIMBAL_MOTIONLESS_RC_DEADLINE 10
#define GIMBAL_MOTIONLESS_TIME_MAX 3000

//电机编码值转化成角度值
#ifndef Motor_Ecd_to_Rad
#define Motor_Ecd_to_Rad 0.000766990394f //      2*  PI  /8192弧度制
#endif
	 
typedef enum
{
    GIMBAL_MOTOR_RAW      = 0, //电机原始值控制
    GIMBAL_MOTOR_GYRO     = 1, //电机陀螺仪角度控制
    GIMBAL_MOTOR_ENCONDE  = 2, //电机编码值角度控制
} gimbal_motor_mode_e;
	 
typedef struct
{
    fp32 kp;
    fp32 ki;
    fp32 kd;

    fp32 set;
    fp32 get;
    fp32 err;

    fp32 max_out;
    fp32 max_iout;

    fp32 Pout;
    fp32 Iout;
    fp32 Dout;

    fp32 out;
} Gimbal_PID_t;


typedef struct
{
    const moto_info_t *gimbal_motor_measure;
    Gimbal_PID_t gimbal_motor_absolute_angle_pid;
    Gimbal_PID_t gimbal_motor_relative_angle_pid;
    pid_struct_t gimbal_motor_gyro_pid;
    gimbal_motor_mode_e gimbal_motor_mode;
    gimbal_motor_mode_e last_gimbal_motor_mode;
    uint16_t offset_ecd;//相对角中值
    fp32 max_relative_angle; //rad//这两个值直接测出来，换电机的时候也要测注意都是 角度值
    fp32 min_relative_angle; //rad

    fp32 relative_angle;     //rad
    fp32 relative_angle_set; //rad
    fp32 absolute_angle;     //rad
    fp32 absolute_angle_set; //rad
    fp32 motor_gyro;         //rad/s
    fp32 motor_gyro_set;
    fp32 motor_speed;
    fp32 raw_cmd_current;
    fp32 current_set;
    int16_t given_current;

} Gimbal_Motor_t;
	
//云台设备的校准数据
typedef struct
{
    uint16_t yaw_offset;
    uint16_t pitch_offset;
    fp32 yaw_max_angle;
    fp32 yaw_min_angle;
    fp32 pitch_max_angle;
    fp32 pitch_min_angle;
} gimbal_cali_t;

//云台设备行程设置数据
typedef struct
{
    fp32 max_yaw;
    fp32 min_yaw;
    fp32 max_pitch;
    fp32 min_pitch;
    uint16_t max_yaw_ecd;
    uint16_t min_yaw_ecd;
    uint16_t max_pitch_ecd;
    uint16_t min_pitch_ecd;
    uint8_t step;
		//gimbal_cali_t local_cali_t;
} Gimbal_Cali_t;

typedef struct
{
    const RC_Type *gimbal_rc_ctrl;
    const fp32 *gimbal_INT_angle_point;
    const fp32 *gimbal_INT_gyro_point;
    Gimbal_Motor_t gimbal_yaw_motor;
    Gimbal_Motor_t gimbal_pitch_motor;
    Gimbal_Cali_t gimbal_cali;
} Gimbal_Control_t;


	 
extern const Gimbal_Motor_t *get_yaw_motor_point(void);
extern const Gimbal_Motor_t *get_pitch_motor_point(void);	 
extern osThreadId vGimbal_TaskHandle;
	 
void Gimbal_Task(void const * argument);
	 
#ifdef __cplusplus
}
#endif
#endif /*__Gimbal_Task_H */
