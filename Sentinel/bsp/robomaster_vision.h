#ifndef __ROBOMASTER_VISION_H
#define __ROBOMASTER_VISION_H
#include "bsp_headfile.h"


#define VISION_DETECT 1 //Ê¹ÄÜÊÓ¾õÊ¶±ğ
#define ENEMYDATABUFFERLENGHT   60 //µĞÈËÊı¾İÖ
#define ARMOUR_OFFSET -0.02F //µĞ·½×°¼×Ïà¶ÔÓÚÔÆÌ¨yÖáµÄÆ«ÒÆ µ¥Î»m
#define VISION_YAW_TARGET 333 //ÊÓ¾õyawµÄÄ¿±êÖµ
#define VISION_PIT_TARGET 309 //ÊÓ¾õpitµÄÄ¿±êÖµ
//½Ç¶ÈÊı¾İ½á¹¹
typedef struct
{
		int16_t origin_yaw;
		int16_t origin_pitch;
    int16_t Yaw_Err;//yawÆ«²î
    int16_t Pitch_Err;
		int16_t VX;
		int16_t VY;
		int16_t HEIGHT;
		uint16_t Forcast_X;//¶ÔÓ¦ÔÆÌ¨µÄYAW
		uint16_t Forcast_Y;//¶ÔÓ¦ÓÚÔÆÌ¨µÄPIT
		uint16_t Forcast_Z;//¶ÔÓ¦ÓÚÏà»úÏà¶ÔÓÚ×°¼×µÄ¾àÀë
}Angle_Err_Struct;
////µãÊı¾İ½á¹¹
//typedef struct
//{
//    int16_t X;
//    int16_t Y;
//    int16_t Z;
//}Point_Struct;

typedef struct
{
    Angle_Err_Struct pan_tilt_angel_err;//ÔÆÌ¨Óë×°¼×°åµÄyaw£¬pitchÖáÆ«²î
	uint16_t distance;//½ÓÊÕ²â¾à´«¸ĞÆ÷µÄ¾àÀë µ¥Î»mm
	char recognition_success_flag; //Ê¶±ğ³É¹¦±êÖ¾Î»
	int check_sum;//¼ìÑéÊı¾İÊÇ·ñÕıÈ·
	uint32_t last_time;//ÉÏÒ»Ö¡½ÓÊÕÊÓ¾õµÄÊ±¼ä
	uint32_t current_time;//´ËÊ±½ÓÊÕÊÓ¾õµÄÊ±¼ä
	uint16_t delta_time;//½ÓÊÕÁ½Ö¡Êı¾İµÄ¼ä¸ôÊ±¼ä ms
	uint8_t vision_frame;//ÊÓ¾õÖ¡ÂÊ
		
}Vision_Attack;
////ÊÓ¾õÊı¾İ½á¹¹
//typedef struct
//{
//    uint16_t X;//¶ÔÓ¦ÔÆÌ¨µÄYAW
//	uint16_t Y;//¶ÔÓ¦ÓÚÔÆÌ¨µÄPIT
//	fp32  	 Z;//¶ÔÓ¦ÓÚÏà»úÏà¶ÔÓÚ×°¼×µÄ¾àÀë 
//	int16_t VX;//YAWµÄÆ½ÒÆËÙ¶È
//	int16_t VY;//PITµÄËÙ¶È
//	int16_t VZ;
//	int16_t HEIGHT;//×°¼×°å¸ß¶È
//    int TimeStamp;
//    int Time;
//    char ID;
//    uint32_t Tick;
//}Enemy_Struct;
extern Vision_Attack Armour_attack;
extern uint8_t UART6_Date[12];//´®¿Ú6½ÓÊÕpidµ÷²ÎÊı¾İ
void get_armour_err(void);
void armour_attack(void);
#endif

