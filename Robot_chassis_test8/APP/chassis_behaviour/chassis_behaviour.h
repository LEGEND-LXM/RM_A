#ifndef CHASSIS_BEHAVIOUR_H
#define CHASSIS_BEHAVIOUR_H
#include "main.h"
#include "chassis_task.h"

//底盘最基本模式标签
typedef enum
{
  CHASSIS_ZERO_FORCE,                  //底盘无力
  CHASSIS_NO_MOVE,                     //底盘保持不动
  CHASSIS_INFANTRY_FOLLOW_GIMBAL_YAW,  //正常步兵底盘跟随云台
  CHASSIS_ENGINEER_FOLLOW_CHASSIS_YAW, //控制中工程底盘角度控制底盘，由于底盘未有陀螺仪，故而角度是减去云台角度而得到，如果有底盘陀螺仪请更新底盘的yaw，pitch，roll角度
  CHASSIS_NO_FOLLOW_YAW,               //底盘不跟随角度，角度是开环的，但前后左右是有速度环
  CHASSIS_OPEN                         //遥控器的值乘以比例直接发送到can总线上  空置中
} chassis_behaviour_e;

#define CHASSIS_OPEN_RC_SCALE 10 //在chassis_open 模型下，遥控器乘以该比例发送到can上

extern void chassis_behaviour_mode_set(chassis_move_t *chassis_move_mode);

extern void chassis_behaviour_control_set(fp32 *vx_set, fp32 *vy_set, fp32 *angle_set, chassis_move_t *chassis_move_rc_to_vector);

extern chassis_behaviour_e chassis_behaviour_mode;
#endif


