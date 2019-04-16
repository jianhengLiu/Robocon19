/**
  ******************************************************************************
  * 文件名          : SendSignal.c
  * 创建时间        : 2018.12.16
  * 作者            : 谢胜
  *-----------------------------------------------------------------------------
  * 最近修改时间    : 2019.02.15
  * 修改人          : 任云帆
  ******************************************************************************
  *									文件描述							       *
  ******************************************************************************
  *	定义了电机速度发送函数
  ******************************************************************************
  * 1.本代码基于STMF405RGT6开发，编译环境为Keil 5，基于FreeRTOS进行开发。
  * 2.本代码只适用于RoboMaster 2019步兵机器人，不建议用于其他用途
  * 3.本代码以UTF-8格式编码，请勿以ANSI编码形式打开
  * 4.本代码包含大量中文注释，请仔细通读代码后使用
  * 5.本代码最终解释权归哈尔滨工业大学（深圳）南工骁鹰战队所有
  *
  * Copyright (c) 2019 哈尔滨工业大学（深圳）南工骁鹰战队 版权所有
  ******************************************************************************
  */

#include "SendSignal.h"
#include "MR2Init.h"
#include "usart.h"
#include "string.h"
#include "tim.h"

/**
* @brief 一次性发送所有电机信息
* @param None
* @retval None
* @TODO None
*/
int h1 = 134,h2 = 127,h3 = 146,h4 = 132;
int t1=144,t2=140,t3=140,t4=130,c1=132,c2=130,c3=131,c4=135;
void SendAll(int angleH1, int angleH2, int angleH3, int angleH4,
             int angleT1, int angleT2, int angleT3, int angleT4,
             int angleC1, int angleC2, int angleC3, int angleC4)
{
//T=2000;
//0.5ms--------------0;2.5%
//2.5ms-----------270;12.5%

    /* 1号 左前腿 C B A*/
    __HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_2,(int)((h1+angleH1)*2000/LOCKANGLE+500));				//B 右后腿
    __HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_3,(int)((t1-angleT1)*2000/LOCKANGLE+500));				//
    __HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_4,(int)((c1-angleC1)*2000/LOCKANGLE+500));
    /* 2号 右前腿 X Y Z*/
    __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_3,(int)((h2-angleH2)*2000/LOCKANGLE+500));
    __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_4,(int)((t2+angleT2)*2000/LOCKANGLE+500));
    __HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_1,(int)((c2+angleC2)*2000/LOCKANGLE+500));
    /* 3号 左后腿 G H V*/
    __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,(int)((h3-angleH3)*2000/LOCKANGLE+500));
    __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_1,(int)((t3-angleT3)*2000/LOCKANGLE+500));
    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,(int)((c3-angleC3)*2000/LOCKANGLE+500));
    /* 4号 右后腿 U S T*/
    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,(int)((h4+angleH4)*2000/LOCKANGLE+500));				//
    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,(int)((t4+angleT4)*2000/LOCKANGLE+500));
    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,(int)((c4+angleC4)*2000/LOCKANGLE+500));

}


/**
* @brief 按编号发送电机信息
* @param None
* @retval None
* @TODO None
*/
void sendAngle(int legNumber,int jointNumber,int angle)
{

    switch(legNumber) {
    case 1:	//如果是1号腿
    {
        switch(jointNumber) {
        case 1://臀部
            __HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_2,(int)(angle*2000/LOCKANGLE+500));
            break;
        case 2://大腿
            __HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_3,(int)(angle*2000/LOCKANGLE+500));
            break;
        case 3://小腿
            __HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_4,(int)(angle*2000/LOCKANGLE+500));
            break;
        default:
            ;
        }
    }

    case 2:	//如果是2号腿
    {
        switch(jointNumber) {
        case 1://臀部
            __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_3,(int)(angle*2000/LOCKANGLE+500));
            break;
        case 2://大腿
            __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_4,(int)(angle*2000/LOCKANGLE+500));
            break;
        case 3://小腿
            __HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_1,(int)(angle*2000/LOCKANGLE+500));
            break;
        default:
            ;
        }
    }

    case 3:	//如果是3号腿
    {
        switch(jointNumber) {
        case 1://臀部
            __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,(int)(angle*2000/LOCKANGLE+500));
            break;
        case 2://大腿
            __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_1,(int)(angle*2000/LOCKANGLE+500));
            break;
        case 3://小腿
            __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,(int)(angle*2000/LOCKANGLE+500));
            break;
        default:
            ;
        }
    }

    case 4:	//如果是4号腿
    {
        switch(jointNumber) {
        case 1://臀部
            __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,(int)(angle*2000/LOCKANGLE+500));
            break;
        case 2://大腿
            __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,(int)(angle*2000/LOCKANGLE+500));
            break;
        case 3://小腿
            __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,(int)(angle*2000/LOCKANGLE+500));
            break;
        default:
            ;
        }
    }
    }
}

void SendSignal()
{
	for(int i=0;i<4;i++)
	{
		sendAngle(i,2,MR2.OutPutAngle[i][0]);
		sendAngle(i,3,MR2.OutPutAngle[i][1]);
	}
}
