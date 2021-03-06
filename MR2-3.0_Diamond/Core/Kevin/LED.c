/**
  ******************************************************************************
  * 文件名          : LED.c
  * 创建时间        : 2019.02.16
  * 作者            : 任云帆
  *-----------------------------------------------------------------------------
  * 最近修改时间    : 2019.02.16
  * 修改人          : 任云帆
  ******************************************************************************
	*																文件描述																		 *
	******************************************************************************
	*	简单添加了LED显示工作状态的功能。
	* 注意：开发板上的LED是下拉触发的，设置为RESET时才会亮。同理SET为灭。
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
#include "LED.h"
#include "MR2Init.h"
#include "main.h"


void LED_STOP()
{
    HAL_GPIO_WritePin(GPIOE,GPIO_PIN_11,GPIO_PIN_RESET);//停止状态红灯亮
    HAL_GPIO_WritePin(GPIOF,GPIO_PIN_14,GPIO_PIN_SET);
}

void LED_MANUAL()
{
    HAL_GPIO_WritePin(GPIOE,GPIO_PIN_11,GPIO_PIN_SET);//停止状态红灯亮
    HAL_GPIO_TogglePin(GPIOF,GPIO_PIN_14);//绿灯慢速闪烁手动状态
    HAL_Delay(500);
}
void LED_HIGH()
{
    HAL_GPIO_WritePin(GPIOE,GPIO_PIN_11,GPIO_PIN_SET);//停止状态红灯亮
    HAL_GPIO_TogglePin(GPIOF,GPIO_PIN_14);//绿灯快速闪烁高速状态
    HAL_Delay(100);
}

void LED_ERROR()
{
    HAL_GPIO_TogglePin(GPIOE,GPIO_PIN_11);//红灯快速闪烁错误状态
    HAL_Delay(100);
}

