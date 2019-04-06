#ifndef _ACTION_H_
#define _ACTION_H_

#define shank_vertical 0
#define shank_liftLow 20
#define shank_liftHigh 90
#define thigh_initAngle 45
#define amplitudeHalf_M 25  //行进幅度为25*2=50
#define amplitudeHalf_T 15  //转向幅度为15*2=30
#define delayL 300
#define delayS 200

void action_still(void);
void action_forward(void);
void action_backward(void);
//void action_leap(void);
void action_turnL(void);
void action_turnR(void);
void action_leftward(void);
void action_rightward(void);
//void action_Bar1(int angle);
//void action_Bar2(int angle);
//void action_uphill(int n);
//void action_downhill(int n);

//static int angleLast1;
//static int angleLast2;
#endif
