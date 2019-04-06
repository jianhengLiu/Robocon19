/**
  ******************************************************************************
  * 文件名          : Mission.c
  * 创建时间        : 2019.02.12
  * 作者            : 任云帆
  *-----------------------------------------------------------------------------
  * 最近修改时间    : 2019.02.15
  * 修改人          : 任云帆
  ******************************************************************************
	*																文件描述																		 *
	******************************************************************************
	*	本文件定义了MR1所有工作函数。
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

#include "Mission.h"
#include "SendSignal.h"				//使用SendSignal();函数
#include "MR2Init.h"
#include <math.h>

#include "tim.h"


/**
* @brief MR2手动模式
* @param None
* @retval None
*/
void MR2_MANUAL()
{
		if(MR2.Target.YSpeed>1000||MR2.Target.YSpeed<-1000)
		{
				if(MR2.Target.YSpeed>0)
				{
					HAL_GPIO_WritePin(GPIOE,GPIO_PIN_12,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOE,GPIO_PIN_4,GPIO_PIN_SET);
				}
				else
				{
					HAL_GPIO_WritePin(GPIOE,GPIO_PIN_12,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOE,GPIO_PIN_4,GPIO_PIN_RESET);
				}
		}
		else 
		{
					HAL_GPIO_WritePin(GPIOE,GPIO_PIN_4,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOE,GPIO_PIN_12,GPIO_PIN_RESET);
		}
		
		
				if(MR2.Target.ASpeed>1000||MR2.Target.ASpeed<-1000)
		{
				if(MR2.Target.ASpeed>0)
				{
					HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOE,GPIO_PIN_6,GPIO_PIN_SET);
				}
				else
				{
					HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOE,GPIO_PIN_6,GPIO_PIN_RESET);
				}
		}
		else 
		{
					HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOE,GPIO_PIN_6,GPIO_PIN_RESET);
		}
		
		if(MR2.Target.XSpeed>1000||MR2.Target.XSpeed<-1000)
		{
				if(MR2.Target.XSpeed>0)
				{
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
				}
				else
				{
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
				}
		}
		else 
		{
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
		}
		
		if(MR2.Target.BSpeed>1000||MR2.Target.BSpeed<-1000)
		{
				if(MR2.Target.BSpeed>0)
				{
					HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_SET);
				}
				else
				{
					HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_RESET);
				}
		}
		else 
		{
					HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_RESET);
		}
}







