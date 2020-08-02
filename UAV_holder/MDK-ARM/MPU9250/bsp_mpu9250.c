#include "bsp_mpu9250.h"
#include "TIM_delay.h"
#define BOARD_DOWN   1
#define BUTTEREORTH_FILTER 1
#define Kp 2.0f                                              
#define Ki 0.01f  

mpu_data_t  data, *mpu9250_data = &data;          //取陀螺仪地址赋值给结构体指针
mpu_t       Data, *mpu9250      = &Data;

uint8_t               mpu_buff[14];  

float X_g_av,Y_g_av,Z_g_av;												//可用的加速度计值
float X_g_av_bpf,Y_g_av_bpf,Z_g_av_bpf;						//带阻滤波后可用的加速度计值
float X_w_av,Y_w_av,Z_w_av;												//可用的陀螺仪数值
float X_w_av_bpf,Y_w_av_bpf,Z_w_av_bpf;						//带阻滤波后可用的陀螺仪数值
float X_m_av,Y_m_av,Z_m_av;												//经过滤波后的磁力计读数

volatile float        q0 = 1.0f;
volatile float        q1 = 0.0f;
volatile float        q2 = 0.0f;
volatile float        q3 = 0.0f;
volatile float        exInt, eyInt, ezInt;                     /* error integral */
static volatile float gx, gy, gz, ax, ay, az, mx, my, mz;  
volatile uint32_t     last_update, now_update; 

void mpu9250_getdata(void);
void init_quaternion(void);
float inv_sqrt(float x);
void mpu9250_ahrs_update(void); 
void mpu9250_attitude_update(void);
int16_t MPU9250_INIT(void);
void MPU9250_GETDATA(void);
void mpu_offset_call(uint16_t count);

int16_t MPU9250_INIT(void)
{
	int16_t res;
	res = MPU9250_Init();       //九轴通信初始化
	init_quaternion();          //四元数初始化
	mpu_offset_call(300);          //零漂处理
	
	return res;
}
void MPU9250_GETDATA(void)    //得到角速度和角度
{
	mpu9250_getdata();
	mpu9250_ahrs_update();
	mpu9250_attitude_update();
}
void mpu9250_getdata(void)
{
	int16_t roll_data,pitch_data,yaw_data;
	MPU_Get_Accelerometer();   
	MPU_Get_Gyroscope();
  MPU_Get_Magnetometer();	
	
	roll_data = (mpu9250_data->gx)-(mpu9250_data->gx_offset);
	pitch_data= (mpu9250_data->gy)-(mpu9250_data->gy_offset);
	yaw_data  = (mpu9250_data->gz)-(mpu9250_data->gz_offset);
	
	
	/***********************************陀螺仪滤波*************************************************/
	mpu9250->X_w_av_bpf = Butterworth_Filter(roll_data, &Gyro_BufferData_BPF[0],&Bandstop_Filter_Parameter_30_98);
	mpu9250->Y_w_av_bpf = Butterworth_Filter(pitch_data,&Gyro_BufferData_BPF[1],&Bandstop_Filter_Parameter_30_98);
  mpu9250->Z_w_av_bpf = Butterworth_Filter(yaw_data,  &Gyro_BufferData_BPF[2],&Bandstop_Filter_Parameter_30_98);
	
	mpu9250->X_w_av     = Butterworth_Filter(mpu9250->X_w_av_bpf,&Gyro_BufferData[0],&Gyro_Parameter);
	mpu9250->Y_w_av     = Butterworth_Filter(mpu9250->Y_w_av_bpf,&Gyro_BufferData[1],&Gyro_Parameter);
	mpu9250->Z_w_av     = Butterworth_Filter(mpu9250->Z_w_av_bpf,&Gyro_BufferData[2],&Gyro_Parameter); 
	
	
	
	/************************************加速度计滤波***********************************************/
	mpu9250->X_g_av_bpf = Butterworth_Filter(mpu9250_data->ax,&Accel_BufferData_BPF[0],&Bandstop_Filter_Parameter_30_94);
	mpu9250->Y_g_av_bpf = Butterworth_Filter(mpu9250_data->ay,&Accel_BufferData_BPF[1],&Bandstop_Filter_Parameter_30_94);
	mpu9250->Z_g_av_bpf = Butterworth_Filter(mpu9250_data->az,&Accel_BufferData_BPF[2],&Bandstop_Filter_Parameter_30_94);
	
	mpu9250->X_g_av     = Butterworth_Filter(mpu9250->X_g_av_bpf,&Accel_BufferData[0],&Accel_Parameter);
	mpu9250->Y_g_av     = Butterworth_Filter(mpu9250->Y_g_av_bpf,&Accel_BufferData[1],&Accel_Parameter);
	mpu9250->Z_g_av     = Butterworth_Filter(mpu9250->Z_g_av_bpf,&Accel_BufferData[2],&Accel_Parameter);
	
	/* 2000dps -> rad/s */  //弧度制
	mpu9250->wx         = mpu9250->X_w_av / 16.384f / 57.3f;
	mpu9250->wy         = mpu9250->Y_w_av / 16.384f / 57.3f;
	mpu9250->wz         = mpu9250->Z_w_av / 16.384f / 57.3f;
	
			/* 2000dps -> rad/s */  //角度制
  mpu9250->gx         = mpu9250->X_w_av / 16.384f; 
  mpu9250->gy         = mpu9250->Y_w_av / 16.384f; 
  mpu9250->gz         = mpu9250->Z_w_av / 16.384f;
}
/**
  * @brief  fast inverse square-root, to calculate 1/Sqrt(x)
  * @param  x: the number need to be calculated
  * @retval 1/Sqrt(x)
  * @usage  call in imu_ahrs_update() function
  */
float inv_sqrt(float x) 
{
	float halfx = 0.5f * x;
	float y     = x;
	long  i     = *(long*)&y;
	
	i = 0x5f3759df - (i >> 1);
	y = *(float*)&i;
	y = y * (1.5f - (halfx * y * y));
	
	return y;
}
/**
	* @brief  Initialize quaternion
  * @param  
	* @retval 
  * @usage  call in main() function
	*/
void init_quaternion(void)
{
	int16_t hx, hy;
	
	hx = mpu9250->mx;
	hy = mpu9250->my;
//  hz = mpu9250_t.mz;
	
	#ifdef BOARD_DOWN
	if (hx < 0 && hy < 0) 
	{
		if (fabs(hx / hy) >= 1)
		{
			q0 = -0.005;
			q1 = -0.199;
			q2 = 0.979;
			q3 = -0.0089;
		}
		else
		{
			q0 = -0.008;
			q1 = -0.555;
			q2 = 0.83;
			q3 = -0.002;
		}
		
	}
	else if (hx < 0 && hy > 0)
	{
		if (fabs(hx / hy)>=1)   
		{
			q0 = 0.005;
			q1 = -0.199;
			q2 = -0.978;
			q3 = 0.012;
		}
		else
		{
			q0 = 0.005;
			q1 = -0.553;
			q2 = -0.83;
			q3 = -0.0023;
		}
		
	}
	else if (hx > 0 && hy > 0)
	{
		if (fabs(hx / hy) >= 1)
		{
			q0 = 0.0012;
			q1 = -0.978;
			q2 = -0.199;
			q3 = -0.005;
		}
		else
		{
			q0 = 0.0023;
			q1 = -0.83;
			q2 = -0.553;
			q3 = 0.0023;
		}
		
	}
	else if (hx > 0 && hy < 0)
	{
		if (fabs(hx / hy) >= 1)
		{
			q0 = 0.0025;
			q1 = 0.978;
			q2 = -0.199;
			q3 = 0.008;			
		}
		else
		{
			q0 = 0.0025;
			q1 = 0.83;
			q2 = -0.56;
			q3 = 0.0045;
		}		
	}
	#else
		if (hx < 0 && hy < 0)
	{
		if (fabs(hx / hy) >= 1)
		{
			q0 = 0.195;
			q1 = -0.015;
			q2 = 0.0043;
			q3 = 0.979;
		}
		else
		{
			q0 = 0.555;
			q1 = -0.015;
			q2 = 0.006;
			q3 = 0.829;
		}
		
	}
	else if (hx < 0 && hy > 0)
	{
		if(fabs(hx / hy) >= 1)
		{
			q0 = -0.193;
			q1 = -0.009;
			q2 = -0.006;
			q3 = 0.979;
		}
		else
		{
			q0 = -0.552;
			q1 = -0.0048;
			q2 = -0.0115;
			q3 = 0.8313;
		}
		
	}
	else if (hx > 0 && hy > 0)
	{
		if(fabs(hx / hy) >= 1)
		{
			q0 = -0.9785;
			q1 = 0.008;
			q2 = -0.02;
			q3 = 0.195;
		}
		else
		{
			q0 = -0.9828;
			q1 = 0.002;
			q2 = -0.0167;
			q3 = 0.5557;
		}
		
	}
	else if (hx > 0 && hy < 0)
	{
		if(fabs(hx / hy) >= 1)
		{
			q0 = -0.979;
			q1 = 0.0116;
			q2 = -0.0167;
			q3 = -0.195;			
		}
		else
		{
			q0 = -0.83;
			q1 = 0.014;
			q2 = -0.012;
			q3 = -0.556;
		}		
	}
	#endif
}
/**
	* @brief  update imu AHRS
  * @param  
	* @retval 
  * @usage  call in main() function
	*/
void mpu9250_ahrs_update(void) 
{
	float norm;
	float hx, hy, hz, bx, bz;
	float vx, vy, vz, wx, wy, wz;
	float ex, ey, ez, halfT;
	float tempq0,tempq1,tempq2,tempq3;

	float q0q0 = q0*q0;   //数据更新
	float q0q1 = q0*q1;
	float q0q2 = q0*q2;
	float q0q3 = q0*q3;
	float q1q1 = q1*q1;
	float q1q2 = q1*q2;
	float q1q3 = q1*q3;
	float q2q2 = q2*q2;   
	float q2q3 = q2*q3;
	float q3q3 = q3*q3;   

	gx = mpu9250->wx;
	gy = mpu9250->wy;
	gz = mpu9250->wz;
	ax = mpu9250->ax;
	ay = mpu9250->ay;
	az = mpu9250->az;
	mx = mpu9250->mx;
	my = mpu9250->my;
	mz = mpu9250->mz;

	now_update  = HAL_GetTick(); //ms
	halfT       = ((float)(now_update - last_update) / 2000.0f);
	last_update = now_update;
	
	/* Fast inverse square-root */
	norm = inv_sqrt(ax*ax + ay*ay + az*az);       
	ax = ax * norm;
	ay = ay * norm;
	az = az * norm;
	
	#ifdef IST8310
		norm = inv_sqrt(mx*mx + my*my + mz*mz);          
		mx = mx * norm;
		my = my * norm;
		mz = mz * norm; 
	#else
		mx = 0;
		my = 0;
		mz = 0;		
	#endif
	/* compute reference direction of flux */
	hx = 2.0f*mx*(0.5f - q2q2 - q3q3) + 2.0f*my*(q1q2 - q0q3) + 2.0f*mz*(q1q3 + q0q2);
	hy = 2.0f*mx*(q1q2 + q0q3) + 2.0f*my*(0.5f - q1q1 - q3q3) + 2.0f*mz*(q2q3 - q0q1);
	hz = 2.0f*mx*(q1q3 - q0q2) + 2.0f*my*(q2q3 + q0q1) + 2.0f*mz*(0.5f - q1q1 - q2q2);         
	bx = sqrt((hx*hx) + (hy*hy));
	bz = hz; 
	
	/* estimated direction of gravity and flux (v and w) */
	vx = 2.0f*(q1q3 - q0q2);
	vy = 2.0f*(q0q1 + q2q3);
	vz = q0q0 - q1q1 - q2q2 + q3q3;
	wx = 2.0f*bx*(0.5f - q2q2 - q3q3) + 2.0f*bz*(q1q3 - q0q2);
	wy = 2.0f*bx*(q1q2 - q0q3) + 2.0f*bz*(q0q1 + q2q3);
	wz = 2.0f*bx*(q0q2 + q1q3) + 2.0f*bz*(0.5f - q1q1 - q2q2);  
	
	/* 
	 * error is sum of cross product between reference direction 
	 * of fields and direction measured by sensors 
	 */
	ex = (ay*vz - az*vy) + (my*wz - mz*wy);
	ey = (az*vx - ax*vz) + (mz*wx - mx*wz);
	ez = (ax*vy - ay*vx) + (mx*wy - my*wx);

	/* PI */
	if(ex != 0.0f && ey != 0.0f && ez != 0.0f)
	{
		exInt = exInt + ex * Ki * halfT;
		eyInt = eyInt + ey * Ki * halfT;	
		ezInt = ezInt + ez * Ki * halfT;
		
		gx = gx + Kp*ex + exInt;
		gy = gy + Kp*ey + eyInt;
		gz = gz + Kp*ez + ezInt;
	}
	
	tempq0 = q0 + (-q1*gx - q2*gy - q3*gz) * halfT;
	tempq1 = q1 + (q0*gx + q2*gz - q3*gy) * halfT;
	tempq2 = q2 + (q0*gy - q1*gz + q3*gx) * halfT;
	tempq3 = q3 + (q0*gz + q1*gy - q2*gx) * halfT;  

	/* normalise quaternion */
	norm = inv_sqrt(tempq0*tempq0 + tempq1*tempq1 + tempq2*tempq2 + tempq3*tempq3);
	q0 = tempq0 * norm;
	q1 = tempq1 * norm;
	q2 = tempq2 * norm;
	q3 = tempq3 * norm;
}	

void mpu9250_attitude_update(void)
{
	/* yaw    -pi----pi */
	mpu9250->yaw = -atan2(2*q1*q2 + 2*q0*q3, -2*q2*q2 - 2*q3*q3 + 1)*57.3; 
	/* pitch  -pi/2----pi/2 */
	mpu9250->pit = -asin(-2*q1*q3 + 2*q0*q2)*57.3;   
	/* roll   -pi----pi  */	
	mpu9250->rol =  atan2(2*q2*q3 + 2*q0*q1, -2*q1*q1 - 2*q2*q2 + 1)*57.3;
}
/**
	* @brief  get the offset data of MPU6500
  * @param  
	* @retval 
  * @usage  call in main() function
	*/
void mpu_offset_call(uint16_t count)
{
	int i;
	for (i=0; i<count;i++)
	{

	  MPU_Get_Accelerometer();   
	  MPU_Get_Gyroscope();
		
		mpu9250_data->ax_offset += mpu9250_data->ax;
		mpu9250_data->ay_offset += mpu9250_data->ay;
		mpu9250_data->az_offset += mpu9250_data->az;
	
		mpu9250_data->gx_offset += mpu9250_data->gx;
		mpu9250_data->gy_offset += mpu9250_data->gy;
		mpu9250_data->gz_offset += mpu9250_data->gz;

		delayXms(5);
	}
	mpu9250_data->ax_offset=mpu9250_data->ax_offset / 300;
	mpu9250_data->ay_offset=mpu9250_data->ay_offset / 300;
	mpu9250_data->az_offset=mpu9250_data->az_offset / 300;
	mpu9250_data->gx_offset=mpu9250_data->gx_offset / 300;
	mpu9250_data->gy_offset=mpu9250_data->gy_offset / 300;
	mpu9250_data->gz_offset=mpu9250_data->gz_offset / 300;
	
}

