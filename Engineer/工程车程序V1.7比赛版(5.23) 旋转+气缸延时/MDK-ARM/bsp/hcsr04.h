#ifndef __HCSR04_H
#define __HCSR04_H

#include "mytype.h"
#include "stdio.h"
#include "delay.h"
enum {CAP_NO=0,CAP_UP,CAP_DOWN,CAP_CMPL};
extern TIM_HandleTypeDef htim3;
void GetDistance(void);
#endif

