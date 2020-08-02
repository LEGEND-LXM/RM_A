#ifndef _PAN_TILT_CONTROL
#define _PAN_TILT_CONTROL
#include "robomaster_common.h"

#define Motor_Ecd_to_Rad	 0.000766990394f //      2*  PI  /8192
#define Motor_Ecd_to_Angel 0.0439453125f   //360/8192
typedef struct
{
//    const motor_measure_t *gimbal_motor_measure;
//    Gimbal_PID_t gimbal_motor_absolute_angle_pid;
//    Gimbal_PID_t gimbal_motor_relative_angle_pid;
//    PidTypeDef gimbal_motor_gyro_pid;
//    gimbal_motor_mode_e gimbal_motor_mode;
//    gimbal_motor_mode_e last_gimbal_motor_mode;
    uint16_t offset_ecd;
    float max_relative_angle; //rad
    float min_relative_angle; //rad

    float relative_angle;     //rad
    float relative_angle_set; //rad
		float relative_radian;//弧度
		float relative_radian_set; //rad
    float absolute_angle;     //rad
    float absolute_angle_set; //rad
		float absolute_radian;//弧度
		float absolute_radian_set; //rad
    float motor_gyro;         //rad/s
    float motor_gyro_set;
    float motor_speed;
    float raw_cmd_current;
    float current_set;
    int16_t given_current;

} Gimbal_Motor_t;

typedef struct
{
//    const RC_ctrl_t *gimbal_rc_ctrl;
//    const fp32 *gimbal_INT_angle_point;
//    const fp32 *gimbal_INT_gyro_point;
    Gimbal_Motor_t gimbal_yaw_motor;
    Gimbal_Motor_t gimbal_pitch_motor;
//    Gimbal_Cali_t gimbal_cali;
} Gimbal_Control_t;

extern float PIT_SPEED_KP;//PIT串级PID参数
extern float PIT_SPEED_KI;
extern float PIT_ANGEL_KP;
extern float PIT_ANGEL_KI;

extern int yaw_velocity_target;//yaw轴角速度输入目标值
extern int pitch_velocity_target;//pitch轴角速度输入目标值
extern float pitch_angle_target;//pitch轴角度输入目标值
extern Gimbal_Control_t gimbal_control;
void PID_Pitch_control(void);
void pan_tilt_machine_home(void);
void pan_tilt_yaw_imu_angle_control(void);
void pan_tilt_yaw_mechanical_angle_control(void);
void pan_tilt_pitch_imu_angle_control(void);
void pan_tilt_pitch_mechanical_angle_control(void);
void pan_tilt_lock_control(void);
void pan_tilt_init(void);
void GIMBAL_Feedback_Update(void);
float motor_ecd_to_angle_change(uint16_t ecd, uint16_t offset_ecd);
float BulletModel(float x, float v, float angle);
float GetPitch(float x, float y, float v);
void fight_back(void);
float fp32_constrain(float Value, float minValue, float maxValue);
#endif
