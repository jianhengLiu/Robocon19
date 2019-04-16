/**
  ******************************************************************************
  * 文件名          : MR1Init.h
  * 创建时间        : 2019.02.12
  * 作者            : 任云帆
  *-----------------------------------------------------------------------------
  * 最近修改时间    : 2019.02.15
  * 修改人          : 任云帆
  ******************************************************************************
  *								文件描述     								   *
  ******************************************************************************
  *	本文件定义了MR1所有的全局变量和MR1初始化函数。
  ******************************************************************************
  * 1.本代码基于STM32F427IIH6开发，编译环境为Keil 5，基于FreeRTOS进行开发。
  * 2.本代码只适用于Robocon 2019MR1机器人，不建议用于其他用途
  * 3.本代码以UTF-8格式编码，请勿以ANSI编码形式打开
  * 4.本代码包含大量中文注释，请仔细通读代码后使用
  * 5.本代码最终解释权归哈尔滨工业大学（深圳）Robocon战队所有
  *
  * Copyright (c) 2019 哈尔滨工业大学（深圳）Robocon战队 版权所有
  ******************************************************************************
  */


#ifndef _MR1INIT_H_
#define _MR1INIT_H_

typedef unsigned char uint8_t;
typedef   signed          char int8_t;
typedef   signed short     int int16_t;

#define DIVIDSPEED 					10
#define DELAYTIME				  	 1
#define LOCKANGLE						 270

#define LEFT_FORWARD		 1
#define RIGHT_FORWARD		 2
#define LEFT_BACK				 3
#define RIGHT_BACK 			 4

#define HIP			1
#define TIGHT		2
#define	CALF		3

#define CALF_STILL	45
#define TIGHT_STILL 45

#define CALF_STRETCH 45
#define TIGHT_STRETCH 45

#define H10 134         //靠外侧时++
#define H20 127         //靠外侧时--
#define H30 146         //靠外侧时--
#define H40 132         //靠外侧时++


#define T10 144         //向前伸时--
#define T20 140         //向前伸时++
#define T30 140         //向前伸时--
#define T40 130         //向前伸时++

#define C10 132 				//向前角度--
#define C20	130					//向前角度++
#define C30 131 				//向前角度--
#define C40	135 				//向前角度++

#define TIGHTLEN			14
#define CALFLEN				15

//新增2019/4/15
#define PI 3.1415926535
#define SPACING 10 //两舵机间距


/*
大腿 14cm
小腿 15cm

*/



/**
* @brief MR1工作状态枚举类型
* @param None
* @retval None
*/
typedef enum 
{
	walk
}WorkState_e;

/**
* @brief 遥控器接收数据解析结构体
* @param None
* @retval None
*/
typedef struct 
{
    int YSpeed;
    int XSpeed;
    int ASpeed;
		int BSpeed;
}Target_s;

/**
* @brief 陀螺仪返回参数
* @param None
* @retval None
*/
typedef struct
{
	float pos_x;
	float pos_y;
	float zangle;
	float xangle;
	float yangle;
	float w_z;
}Gyro_s;


/**
* @brief MR2腿部状态结构体
* @param None
* @retval None
*/
typedef struct
{
	int Hip[4];
	int Tight[4];
	int Calf[4];
}Leg_s;


/**
* @brief MR2全部参数结构体
* @param None
* @retval None
*/
typedef struct
{
	Target_s Target;
	WorkState_e WorkState;
	Gyro_s GyroData;
	Leg_s LastPos;
	Leg_s TargetPos;
	double Angle[4][2];
	double OutPutAngle[4][2];

}MR2_s;


extern MR2_s MR2;
extern uint8_t UsartReceiveRemote[18];   
extern uint8_t UsartReceiveGyro;
extern int ZeroPos[4][3];

void RobotParamInit(void);


#endif
