#ifndef  __keyboard_control
#define  __keyboard_control

#include "stm32f4xx_hal.h"
//#include "robomaster_common.h"
/* ----------------------- PC Key Definition-------------------------------- */
#define KEY_PRESSED_OFFSET_W ((uint16_t)1 << 0)
#define KEY_PRESSED_OFFSET_S ((uint16_t)1 << 1)
#define KEY_PRESSED_OFFSET_A ((uint16_t)1 << 2)
#define KEY_PRESSED_OFFSET_D ((uint16_t)1 << 3)
#define KEY_PRESSED_OFFSET_SHIFT ((uint16_t)1 << 4)
#define KEY_PRESSED_OFFSET_CTRL ((uint16_t)1 << 5)
#define KEY_PRESSED_OFFSET_Q ((uint16_t)1 << 6)
#define KEY_PRESSED_OFFSET_E ((uint16_t)1 << 7)
#define KEY_PRESSED_OFFSET_R ((uint16_t)1 << 8)
#define KEY_PRESSED_OFFSET_F ((uint16_t)1 << 9)
#define KEY_PRESSED_OFFSET_G ((uint16_t)1 << 10)
#define KEY_PRESSED_OFFSET_Z ((uint16_t)1 << 11)
#define KEY_PRESSED_OFFSET_X ((uint16_t)1 << 12)
#define KEY_PRESSED_OFFSET_C ((uint16_t)1 << 13)
#define KEY_PRESSED_OFFSET_V ((uint16_t)1 << 14)
#define KEY_PRESSED_OFFSET_B ((uint16_t)1 << 15)
/* ----------------------- Data Struct ------------------------------------- */
void Keyboard_Init(void);
void Keyboard_value_Init(void);
void keyboard_chassis(void);
void keyboard_mouse(void);


typedef struct {
	uint8_t q;
	uint8_t q_flag;
	
	uint8_t r;
	uint8_t r_flag;
	
	uint8_t f;
	uint8_t f_flag;
	
	uint8_t g;
	uint8_t g_flag;
	
	uint8_t z;
	uint8_t z_flag;
	
	uint8_t x;
	uint8_t x_flag;
	
	uint8_t c;
	uint8_t c_flag;
	
	uint8_t v;
  uint8_t v_flag;	
	
	uint8_t b;
	uint8_t b_flag;
	
	uint8_t Ctrl;  //һ���ϵ�
	uint8_t Ctrl_flag;
	
	uint8_t Shift_r;
	uint8_t Shift_r_flag;
	
	uint8_t e;  //����
	uint8_t e_flag;
	
	uint8_t mousel;
	uint8_t mousel_flag;
	
	uint8_t mouser;
	uint8_t mouser_flag;
	
	uint16_t speed;
	
	float yaw;
	float pitch;

	
}Keybroad_Control;

extern Keybroad_Control kb;

extern float kbshootspeed;

#endif
