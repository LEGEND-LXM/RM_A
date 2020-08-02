#ifndef __SCOPE_H_
#define __SCOPE_H_ 1

#include "main.h"
#include "usart.h"


extern float Variable[16];
extern void my_putchar(uint8_t temp);
extern void my_putchar_usb(uint8_t temp);
extern void Send_Begin(void);
extern void Send_Variable(void);

extern short wave_form_data[8];
extern void shanwai_send_wave_form(void);

#endif
