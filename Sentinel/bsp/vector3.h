#ifndef __VECTOR3_H__
#define __VECTOR3_H__

//#include "mathTool.h"
#include "spi.h"
#include "bsp_can.h"
#include "led.h"
#include "power_ctrl.h"
#include "fric.h"
#include "buzzer.h"
#include "laser.h"
#include "user_lib.h"
#include "scope.h"
#include "Remote_Control.h"
#include "pid.h"
#include "timdelay.h"
#include "exti.h"
//#include "dmp_exti.h"
#include "mytype.h"
#include "main.h"



typedef struct {
    double x;
    double y;
    double z;
} Vector3d_t;

typedef struct {
    int16_t x;
    int16_t y;
    int16_t z;
} Vector3i_t;

typedef struct {
    int32_t x;
    int32_t y;
    int32_t z;
} Vector3l_t;

typedef struct {
    float x;
    float y;
    float z;
} Vector3f_t;
//void Vector3f_Normalize(Vector3f_t* vector);

//Vector3f_t Vector3iTo3f(Vector3i_t vector);
//Vector3i_t Vector3fTo3i(Vector3f_t vector);
//Vector3f_t Vector3f_Add(Vector3f_t v1, Vector3f_t v2);
//Vector3f_t Vector3f_Sub(Vector3f_t v1, Vector3f_t v2);

//Vector3f_t VectorCrossProduct(Vector3f_t a, Vector3f_t b);
//Vector3f_t Matrix3MulVector3(float* m, Vector3f_t vector);
//Vector3f_t VectorRotateToBodyFrame(Vector3f_t vector, Vector3f_t deltaAngle);
//Vector3f_t VectorRotateToEarthFrame(Vector3f_t vector, Vector3f_t deltaAngle);

//void EulerAngleToDCM(Vector3f_t angle, float* dcM);

//void AccVectorToRollPitchAngle(Vector3f_t* angle, Vector3f_t vector);
//void MagVectorToYawAngle(Vector3f_t* angle, Vector3f_t vector);


extern Vector3f_t gyro_status;//ÍÓÂÝÒÇ×´Ì¬½á¹¹Ìå
#endif


