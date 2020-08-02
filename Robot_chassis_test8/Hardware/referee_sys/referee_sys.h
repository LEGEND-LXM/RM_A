/*
*使用说明：主函数中调用void ref_sys_init(void)函数对裁判系统进行初始化，
*其使用串口2读取裁判系统数据，并已初始化好串口2，若自己有相关
*串口2的代码，则将自己的相关部分屏蔽掉。
*/
#ifndef __ROBMASTER_SYS_H
#define __ROBMASTER_SYS_H

/* Includes -----------------------------------------------------------*/
#include "usart.h"

/* 宏定义数据最大长度*/
#define datamaxlen 255

//自身机器人id
//发送用户数据时使用
#define RED_HERO			1
#define RED_ENGINEER		2
#define RED_INFANTRY1		3
#define RED_INFANTRY2		4
#define RED_INFANTRY3		5
#define RED_AERIAL			6
#define RED_SENTRY			7

#define BLUE_HERO			11
#define BLUE_ENGINEER		12
#define BLUE_INFANTRY1		13
#define BLUE_INFANTRY2		14
#define BLUE_INFANTRY3		15
#define BLUE_AERIAL			16
#define BLUE_SENTRY			17

//客户端id
#define CLIENT_RED_HERO				0x0101//1
#define CLIENT_RED_ENGINEER			0x0102//2
#define CLIENT_RED_INFANTRY1		0x0103//3
#define CLIENT_RED_INFANTRY2		0x0104//4
#define CLIENT_RED_INFANTRY3		0x0105//5
#define CLIENT_RED_AERIAL			0x0106//6
//#define CLIENT_RED_SENTRY			0x0107//哨兵无客户端

#define CLIENT_BLUE_HERO			0x0111//7
#define CLIENT_BLUE_ENGINEER		0x0112//8
#define CLIENT_BLUE_INFANTRY1		0x0113//9
#define CLIENT_BLUE_INFANTRY2		0x0114//10
#define CLIENT_BLUE_INFANTRY3		0x0115//11
#define CLIENT_BLUE_AERIAL			0x0116//12
//#define CLIENT_BLUE_SENTRY		0x0117

/*数据包命令码*/
#define Game_State					0x0001
#define Game_Result					0x0002
#define Game_Robot_Survivors		0x0003
#define Event_Data					0x0101
#define Supply_Projectile_Action	0x0102
#define Supply_Projectile_Booking	0x0103
#define Game_Robot_State			0x0201
#define Power_Heat_Data_t			0x0202
#define Game_Robot_Pos				0x0203
#define Buff_Musk					0x0204
#define Aerial_Robot_Energy			0x0205
#define Robot_Hurt					0x0206
#define Shoot_Data					0x0207


/* 宏定义数据包CMD*/
#define CMD1_LEN	3
#define CMD2_LEN	1
#define CMD3_LEN	2
#define CMD4_LEN	4
#define CMD5_LEN	3
#define CMD6_LEN	2
#define CMD7_LEN	15
#define CMD8_LEN	14
#define CMD9_LEN	16
#define CMD10_LEN	1
#define CMD11_LEN	3
#define CMD12_LEN	1
#define CMD13_LEN	6


#define cal_cmd_len(x)    5 + 2 + x + 2     //FH = 5 2个CMD x个长度的数据 2个CRC16校验

//1.比赛状态数据： 0x0001。 发送频率： 1Hz
typedef __packed struct
{
	uint8_t game_type;
	uint8_t game_progress;
	uint16_t stage_remain_time;
}ext_game_state_t;


//2. 比赛结果数据： 0x0002。 发送频率：比赛结束后发送
typedef __packed struct
{
	uint8_t winner;
}ext_game_result_t;


//3. 机器人存活数据： 0x0003。 发送频率： 1Hz
typedef __packed struct
{
	uint16_t robot_legion;
}ext_game_robot_survivors_t;


//4. 场地事件数据： 0x0101。 发送频率：事件改变后发送
typedef __packed struct
{
	uint32_t event_type;
}ext_event_data_t;


//5. 补给站动作标识： 0x0102。 发送频率：动作改变后发送
typedef __packed struct
{
	uint8_t supply_projectile_id;
	uint8_t supply_robot_id;
	uint8_t supply_projectile_step;
	uint8_t supply_projectile_num;
}ext_supply_projectile_action_t;


//6. 请求补给站补弹子弹： cmd_id (0x0103)。发送频率：上限 10Hz。 RM 对抗赛尚未开放
typedef __packed struct
{
	uint8_t supply_projectile_id;
	uint8_t supply_robot_id;
	uint8_t supply_num;
}ext_supply_projectile_booking_t;


//7. 比赛机器人状态： 0x0201。 发送频率： 10Hz
typedef __packed struct
{
	uint8_t robot_id;
	uint8_t robot_level;
	uint16_t remain_HP;
	uint16_t max_HP;
	uint16_t shooter_heat0_cooling_rate;
	uint16_t shooter_heat0_cooling_limit;
	uint16_t shooter_heat1_cooling_rate;
	uint16_t shooter_heat1_cooling_limit;
	uint8_t mains_power_gimbal_output;
	uint8_t mains_power_chassis_output;
	uint8_t mains_power_shooter_output;
}ext_game_robot_state_t;


//8. 实时功率热量数据： 0x0202。 发送频率： 50Hz
typedef __packed struct
{
	uint16_t chassis_volt;
	uint16_t chassis_current;
	float chassis_power;
	uint16_t chassis_power_buffer;
	uint16_t shooter_heat0;
	uint16_t shooter_heat1;
}ext_power_heat_data_t;


//9. 机器人位置： 0x0203。 发送频率： 10Hz

typedef __packed struct
{
	float x;
	float y;
	float z;
	float yaw;
}ext_game_robot_pos_t;


//10. 机器人增益： 0x0204。 发送频率：状态改变后发
typedef __packed struct
{
	uint8_t power_rune_buff;
}ext_buff_musk_t;


//11. 空中机器人能量状态： 0x0205。 发送频率： 10Hz

typedef __packed struct
{
	uint8_t energy_point;
	uint8_t attack_time;
}aerial_robot_energy_t;


//12. 伤害状态： 0x0206。 发送频率：伤害发生后发送
typedef __packed struct
{
	uint8_t armor_id;
	uint8_t hurt_type;
}ext_robot_hurt_t;


//13. 实时射击信息： 0x0207。 发送频率：射击后发送
typedef __packed struct
{
	uint8_t bullet_type;
	uint8_t bullet_freq;
	float bullet_speed;
}ext_shoot_data_t;


typedef __packed struct
{
    ext_game_state_t						game_state_t;
		
    ext_game_result_t						game_result_t;

	ext_game_robot_survivors_t				game_robot_survivors_t;

    ext_event_data_t						event_data_t;

	ext_supply_projectile_action_t			supply_projectile_action_t;

	ext_supply_projectile_booking_t			supply_projectile_booking_t;
		
	ext_game_robot_state_t					game_robot_state_t;
	
	ext_power_heat_data_t					power_heat_data_t;
	
	ext_game_robot_pos_t					game_robot_pos_t;
	
	ext_buff_musk_t							buff_musk_t;
	
	aerial_robot_energy_t					air_robot_energy_t;
	
	ext_robot_hurt_t						robot_hurt_t;
	
	ext_shoot_data_t						shoot_data_t;
	
//	ext_student_interactive_header_data_t	student_interactive_header_data_t;//数据段头结构
	
//	client_custom_data_t					client_user_data_t;//
	
//	robot_interactive_data_t				interactive_data_t;

}refDataStruct;


extern refDataStruct  refSysData;

//读取一些相关数据
uint8_t read_robot_level(void);
float read_chassis_power(void);
uint16_t read_chassis_power_buffer(void);
uint16_t read_shooter_heat(char id);
uint16_t read_armor_hurt(void);

//初始化相关函数，用户只需要在主函数调用void ref_sys_init(void);即可
void uart_receive_idle(UART_HandleTypeDef *huart);
void ref_sys_init(void);
void uart2_init(void);
void hal_uart2_MspInit(void);

extern int chassis_ref_flag;

//发送用户数据
void Send_Date_To_Referee(float dete1,float dete2,float dete3,char dete4,char id);

#endif



