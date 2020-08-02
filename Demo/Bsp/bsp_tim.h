#ifndef __BSP_TIM
#define __BSP_TIM

#include "task_tatal.h"
//PWM输入捕获

#define Left  0
#define Right  1

#define FALLIN  0
#define RISING  1

typedef struct {
	
	uint8_t uhCaptureIndex ;      //检测转换标志位
	uint32_t uwIC2Value_High[2] ; //相邻两次高电平寄存器保留值
	uint32_t uwIC2Value_Low ;     //相邻两次高电平间低电平寄存器保留值
	uint32_t High_Time ;          //一个周期内高电平时间
	uint32_t Low_Time ;           //一个周期内低电平时间
	uint32_t re_speed ;           //目标转速
	float fe_speed ;           //反馈转速
	float period ;                //周期
  float frequency ;             //频率
	float Coefficient ;           //转速比例系数
	
}PWM_INPUT_Type;

extern PWM_INPUT_Type PWM_INPUT_Ture[2];


void user_ic_config(TIM_HandleTypeDef *htim ,uint32_t Channel ,uint16_t value) ;//捕获状态切换
void Computation_period_frequency(PWM_INPUT_Type* PWM_INPUT ,uint32_t* Value_High ,uint32_t Value_Low ); //计算摩擦轮周期、频率、转数
#endif





