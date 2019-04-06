#ifndef _SERVO_H_
#define _SERVO_H_
#include "tim.h"

#define lockAngle 90

void servo_init(void);
void servoLeg_angle(int angle1, int angle2, int angle3, int angle4, int angle5, int angle6, int angle7, int angle8);
void servoBar1_angle(int angle);
void servoBar2_angle(int angle);
#endif
