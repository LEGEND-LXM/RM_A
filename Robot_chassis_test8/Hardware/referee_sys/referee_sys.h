/*
*ʹ��˵�����������е���void ref_sys_init(void)�����Բ���ϵͳ���г�ʼ����
*��ʹ�ô���2��ȡ����ϵͳ���ݣ����ѳ�ʼ���ô���2�����Լ������
*����2�Ĵ��룬���Լ�����ز������ε���
*/
#ifndef __ROBMASTER_SYS_H
#define __ROBMASTER_SYS_H

/* Includes -----------------------------------------------------------*/
#include "usart.h"

/* �궨��������󳤶�*/
#define datamaxlen 255

//���������id
//�����û�����ʱʹ��
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

//�ͻ���id
#define CLIENT_RED_HERO				0x0101//1
#define CLIENT_RED_ENGINEER			0x0102//2
#define CLIENT_RED_INFANTRY1		0x0103//3
#define CLIENT_RED_INFANTRY2		0x0104//4
#define CLIENT_RED_INFANTRY3		0x0105//5
#define CLIENT_RED_AERIAL			0x0106//6
//#define CLIENT_RED_SENTRY			0x0107//�ڱ��޿ͻ���

#define CLIENT_BLUE_HERO			0x0111//7
#define CLIENT_BLUE_ENGINEER		0x0112//8
#define CLIENT_BLUE_INFANTRY1		0x0113//9
#define CLIENT_BLUE_INFANTRY2		0x0114//10
#define CLIENT_BLUE_INFANTRY3		0x0115//11
#define CLIENT_BLUE_AERIAL			0x0116//12
//#define CLIENT_BLUE_SENTRY		0x0117

/*���ݰ�������*/
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


/* �궨�����ݰ�CMD*/
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


#define cal_cmd_len(x)    5 + 2 + x + 2     //FH = 5 2��CMD x�����ȵ����� 2��CRC16У��

//1.����״̬���ݣ� 0x0001�� ����Ƶ�ʣ� 1Hz
typedef __packed struct
{
	uint8_t game_type;
	uint8_t game_progress;
	uint16_t stage_remain_time;
}ext_game_state_t;


//2. ����������ݣ� 0x0002�� ����Ƶ�ʣ�������������
typedef __packed struct
{
	uint8_t winner;
}ext_game_result_t;


//3. �����˴�����ݣ� 0x0003�� ����Ƶ�ʣ� 1Hz
typedef __packed struct
{
	uint16_t robot_legion;
}ext_game_robot_survivors_t;


//4. �����¼����ݣ� 0x0101�� ����Ƶ�ʣ��¼��ı����
typedef __packed struct
{
	uint32_t event_type;
}ext_event_data_t;


//5. ����վ������ʶ�� 0x0102�� ����Ƶ�ʣ������ı����
typedef __packed struct
{
	uint8_t supply_projectile_id;
	uint8_t supply_robot_id;
	uint8_t supply_projectile_step;
	uint8_t supply_projectile_num;
}ext_supply_projectile_action_t;


//6. ���󲹸�վ�����ӵ��� cmd_id (0x0103)������Ƶ�ʣ����� 10Hz�� RM �Կ�����δ����
typedef __packed struct
{
	uint8_t supply_projectile_id;
	uint8_t supply_robot_id;
	uint8_t supply_num;
}ext_supply_projectile_booking_t;


//7. ����������״̬�� 0x0201�� ����Ƶ�ʣ� 10Hz
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


//8. ʵʱ�����������ݣ� 0x0202�� ����Ƶ�ʣ� 50Hz
typedef __packed struct
{
	uint16_t chassis_volt;
	uint16_t chassis_current;
	float chassis_power;
	uint16_t chassis_power_buffer;
	uint16_t shooter_heat0;
	uint16_t shooter_heat1;
}ext_power_heat_data_t;


//9. ������λ�ã� 0x0203�� ����Ƶ�ʣ� 10Hz

typedef __packed struct
{
	float x;
	float y;
	float z;
	float yaw;
}ext_game_robot_pos_t;


//10. ���������棺 0x0204�� ����Ƶ�ʣ�״̬�ı��
typedef __packed struct
{
	uint8_t power_rune_buff;
}ext_buff_musk_t;


//11. ���л���������״̬�� 0x0205�� ����Ƶ�ʣ� 10Hz

typedef __packed struct
{
	uint8_t energy_point;
	uint8_t attack_time;
}aerial_robot_energy_t;


//12. �˺�״̬�� 0x0206�� ����Ƶ�ʣ��˺���������
typedef __packed struct
{
	uint8_t armor_id;
	uint8_t hurt_type;
}ext_robot_hurt_t;


//13. ʵʱ�����Ϣ�� 0x0207�� ����Ƶ�ʣ��������
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
	
//	ext_student_interactive_header_data_t	student_interactive_header_data_t;//���ݶ�ͷ�ṹ
	
//	client_custom_data_t					client_user_data_t;//
	
//	robot_interactive_data_t				interactive_data_t;

}refDataStruct;


extern refDataStruct  refSysData;

//��ȡһЩ�������
uint8_t read_robot_level(void);
float read_chassis_power(void);
uint16_t read_chassis_power_buffer(void);
uint16_t read_shooter_heat(char id);
uint16_t read_armor_hurt(void);

//��ʼ����غ������û�ֻ��Ҫ������������void ref_sys_init(void);����
void uart_receive_idle(UART_HandleTypeDef *huart);
void ref_sys_init(void);
void uart2_init(void);
void hal_uart2_MspInit(void);

extern int chassis_ref_flag;

//�����û�����
void Send_Date_To_Referee(float dete1,float dete2,float dete3,char dete4,char id);

#endif



