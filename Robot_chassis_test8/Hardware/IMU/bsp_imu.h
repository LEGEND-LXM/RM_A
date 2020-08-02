/**
 ***************************************(C) COPYRIGHT 2018 DJI***************************************
 * @file       bsp_imu.h
 * @brief      this file contains the common defines and functions prototypes for 
 *             the bsp_imu.c driver
 * @note         
 * @Version    V1.0.0
 * @Date       Jan-30-2018      
 ***************************************(C) COPYRIGHT 2018 DJI***************************************
 */

#ifndef __MPU_H__
#define __MPU_H__

#include "mytype.h"
#define MPU_DELAY(x) HAL_Delay(x)

//获取姿态角指针地址后，对应姿态角的地址偏移量 fp32类型
//这里对应发地址偏移量

/***********************************************START***********************************************/
/*功能代码名称：对应姿态角的地址偏移量*/
//需根据板子安装实际情况来设置
#define INS_YAW_ADDRESS_OFFSET 0
#define INS_PITCH_ADDRESS_OFFSET 1
#define INS_ROLL_ADDRESS_OFFSET 2

#define INS_GYRO_X_ADDRESS_OFFSET 0
#define INS_GYRO_Y_ADDRESS_OFFSET 1
#define INS_GYRO_Z_ADDRESS_OFFSET 2

#define INS_ACCEL_X_ADDRESS_OFFSET 0
#define INS_ACCEL_Y_ADDRESS_OFFSET 1
#define INS_ACCEL_Z_ADDRESS_OFFSET 2
/***********************************************END***************************************************/


typedef struct
{
	int16_t ax;
	int16_t ay;
	int16_t az;

	int16_t mx;
	int16_t my;
	int16_t mz;

	int16_t temp;

	int16_t gx;
	int16_t gy;
	int16_t gz;
	
	int16_t ax_offset;
	int16_t ay_offset;
	int16_t az_offset;

	int16_t gx_offset;
	int16_t gy_offset;
	int16_t gz_offset;
} mpu_data_t;

typedef struct
{
	int16_t ax;
	int16_t ay;
	int16_t az;

	int16_t mx;
	int16_t my;
	int16_t mz;

	float temp;

	float wx; /*!< omiga, +- 2000dps => +-32768  so gx/16.384/57.3 =	rad/s */
	float wy;
	float wz;

	float vx;
	float vy;
	float vz;
	
	float gx;//角速度  角度制 原始数据
	float gy;
	float gz;

	float rol;
	float pit;
	float yaw;
	
	float X_g_av_bpf;//带阻滤波后可用的加速度计值
	float Y_g_av_bpf;
	float Z_g_av_bpf;
	float X_g_av;//可用的加速度计值
	float Y_g_av;
	float Z_g_av;
	
	float X_w_av_bpf;//带阻滤波后可用的陀螺仪数值
	float Y_w_av_bpf;
	float Z_w_av_bpf;
	float X_w_av;//可用的陀螺仪数值
	float Y_w_av;
	float Z_w_av;
	
	float X_m_av;//经过滤波后的磁力计读数
	float Y_m_av;
	float Z_m_av;
} imu_t;

extern mpu_data_t mpu_data;
extern imu_t      imu;

uint8_t   mpu_device_init(void);
void init_quaternion(void);
void mpu_get_data(void);
void imu_ahrs_update(void);
void imu_attitude_update(void);
void mpu_offset_call(void);

void MPU6500_INITIAL(void);//陀螺仪初始化
void MPU6500_GET_DATA(void);//陀螺仪获取数据

extern const float *get_INS_angle_point(void);
extern const float *get_MPU6500_Gyro_Data_Point(void);
extern const float *get_MPU6500_Accel_Data_Point(void);

#endif


