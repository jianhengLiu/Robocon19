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


/**
* @brief MR1工作状态枚举类型
* @param None
* @retval None
*/
typedef enum 
{
	MoveStright,
	TurnLeft,
	TurnRight,
	CrossHill,
	CrossLine,
	ClimbHill,
}WorkState_e;

/**
* @brief MR2电机升降状态枚举类型
* @param None
* @retval None
*/
typedef enum {
	U,
	D
}state_e;


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
* @brief MR2全部参数结构体
* @param None
* @retval None
*/
typedef struct
{
		WorkState_e WorkState;
		Target_s Target;
		Gyro_s Gyro;
}MR2_s;


extern MR2_s MR2;
extern uint8_t UsartReceiveRemote[18];   
extern uint8_t UsartReceiveGyro;
extern unsigned char sign;
extern char Re_buf[11];

void RobotParamInit(void);


#endif
