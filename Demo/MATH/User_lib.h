#ifndef USER_LIB_H
#define USER_LIB_H
#include "main.h"
#define fp32   int32_t




typedef __packed struct
{
    fp32 input;        //输入数据
    fp32 out;          //输出数据
    fp32 min_value;    //限幅最小值
    fp32 max_value;    //限幅最大值
    float frame_period; //时间间隔
} ramp_function_source_t;

typedef __packed struct
{
    fp32 input;        //输入数据
    fp32 out;          //滤波输出的数据
    fp32 num[1];       //滤波参数
    fp32 frame_period; //滤波的时间间隔 单位 s
} first_order_filter_type_t;
//快速开方
 fp32 invSqrt(fp32 num);

//斜波函数初始化
void ramp_init(ramp_function_source_t *ramp_source_type, float frame_period, fp32 max, fp32 min);

//斜波函数计算
void ramp_calc(ramp_function_source_t *ramp_source_type, fp32 input);
//一阶滤波初始化
 void first_order_filter_init(first_order_filter_type_t *first_order_filter_type, fp32 frame_period, const fp32 num[1]);
//一阶滤波计算
 void first_order_filter_cali(first_order_filter_type_t *first_order_filter_type, fp32 input);
//绝对限制
 void abs_limit(fp32 *num, fp32 Limit);
//判断符号位
 fp32 sign(fp32 value);
//浮点死区
 fp32 fp32_deadline(fp32 Value, fp32 minValue, fp32 maxValue);
//int26死区
 int16_t int16_deadline(int16_t Value, int16_t minValue, int16_t maxValue);
//限幅函数
 fp32 fp32_constrain(fp32 Value, fp32 minValue, fp32 maxValue);
//限幅函数
 int16_t int16_constrain(int16_t Value, int16_t minValue, int16_t maxValue);
//循环限幅函数
 fp32 loop_fp32_constrain(fp32 Input, fp32 minValue, fp32 maxValue);
//角度 °限幅 180 ~ -180
 fp32 theta_format(fp32 Ang);

//弧度格式化为-PI~PI
#define rad_format(Ang) loop_fp32_constrain((Ang), -PI, PI)

extern ramp_function_source_t fric_pwm1; //摩擦轮斜波函数结构体
extern ramp_function_source_t fric_pwm2; //摩擦轮斜波函数结构体
#endif
