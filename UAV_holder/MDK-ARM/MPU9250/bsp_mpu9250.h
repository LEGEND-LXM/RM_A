#ifndef _BSP_MPU9250_H
#define _BSP_MPU9250_H
#include "stm32f1xx_hal.h"
#include "mpu9250.h"
#include "filter.h"
#include "stdio.h"


int abs(int i);                      //����int���͵�ȡ����ֵ
double fabs(double i);               //����double���͵�ȡ����ֵ
float fabsf(float i);                //����float���͵�ȡ����ֵ

#define INS_YAW_ADDRESS_OFFSET 0
#define INS_PITCH_ADDRESS_OFFSET 1
#define INS_ROLL_ADDRESS_OFFSET 2

#define INS_GYRO_X_ADDRESS_OFFSET 0
#define INS_GYRO_Y_ADDRESS_OFFSET 1
#define INS_GYRO_Z_ADDRESS_OFFSET 2

#define INS_ACCEL_X_ADDRESS_OFFSET 0
#define INS_ACCEL_Y_ADDRESS_OFFSET 1
#define INS_ACCEL_Z_ADDRESS_OFFSET 2

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
	
	float gx;//���ٶ�  �Ƕ��� ԭʼ����
	float gy;
	float gz;

	float rol;
	float pit;
	float yaw;
	
	float X_g_av_bpf;//�����˲�����õļ��ٶȼ�ֵ
	float Y_g_av_bpf;
	float Z_g_av_bpf;
	float X_g_av;//���õļ��ٶȼ�ֵ
	float Y_g_av;
	float Z_g_av;
	
	float X_w_av_bpf;//�����˲�����õ���������ֵ
	float Y_w_av_bpf;
	float Z_w_av_bpf;
	float X_w_av;//���õ���������ֵ
	float Y_w_av;
	float Z_w_av;
	
	float X_m_av;//�����˲���Ĵ����ƶ���
	float Y_m_av;
	float Z_m_av;
} mpu_t;

typedef struct mpu_data_t
{
	int16_t gx;
	int16_t gy;
	int16_t gz;
	int16_t ax;
	int16_t ay;
	int16_t az;
	int16_t mx;
	int16_t my;
	int16_t mz;
	
	int16_t temp;
	
	int16_t ax_offset;
	int16_t ay_offset;
	int16_t az_offset;

	int16_t gx_offset;
	int16_t gy_offset;
	int16_t gz_offset;
}mpu_data_t;
extern mpu_data_t  *mpu9250_data;     //ȡ�����ǵ�ַ��ֵ���ṹ��ָ��
extern mpu_t       *mpu9250;

void mpu9250_getdata(void);
void init_quaternion(void);
float inv_sqrt(float x);
void mpu9250_ahrs_update(void); 
void mpu9250_attitude_update(void);
int16_t MPU9250_INIT(void);
void MPU9250_GETDATA(void);
void mpu_offset_call(uint16_t count);
#endif
