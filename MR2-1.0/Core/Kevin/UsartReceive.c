/**
  ******************************************************************************
  * 文件名          : UsartReceive.c
  * 文件描述        : 遥控器数据解析
  * 创建时间        : 2019.01.16
  * 作者            : 任云帆
  *-----------------------------------------------------------------------------
  * 最近修改时间    : 2019.02.15
  * 修改人          : 任云帆
  ******************************************************************************
  *									文件描述							       *
  ******************************************************************************
  *	对遥控器接收数据进行解码，并实时更新机器人状态
  ******************************************************************************
  * 1.本代码基于STM32F427IIH6开发，编译环境为Keil 5，基于FreeRTOS进行开发。
  * 2.本代码只适用于Robocon 2019MR1机器人，不建议用于其他用途
  * 3.本代码以UTF-8格式编码，请勿以ANSI编码形式打开
  * 4.本代码包含大量中文注释，请仔细通读代码后使用
  * 5.本代码最终解释权归哈尔滨工业大学（深圳）Robocon所有
  *
  * Copyright (c) 2019 哈尔滨工业大学（深圳）Robocon版权所有
  ******************************************************************************
  */

#include "UsartReceive.h"
#include "stm32f4xx_hal_uart.h"
#include "Supervise.h"
#include "usart.h"
#include "main.h"
#include "MR2Init.h"
float a[3],w[3],angle[3],T;        

Remote_s Raw_Data;

/**
* @brief 遥控器数据具体解析函数
* @param None
* @retval None
*/
void RemoteReceiveHandle()
{
	Raw_Data.ch0 = ((int16_t)UsartReceiveRemote[0] | ((int16_t)UsartReceiveRemote[1] << 8)) & 0x07FF; 
	Raw_Data.ch1 = (((int16_t)UsartReceiveRemote[1] >> 3) | ((int16_t)UsartReceiveRemote[2] << 5)) & 0x07FF;
	Raw_Data.ch2 = (((int16_t)UsartReceiveRemote[2] >> 6) | ((int16_t)UsartReceiveRemote[3] << 2) |
											 ((int16_t)UsartReceiveRemote[4] << 10)) & 0x07FF;
	Raw_Data.ch3 = (((int16_t)UsartReceiveRemote[4] >> 1) | ((int16_t)UsartReceiveRemote[5]<<7)) & 0x07FF;
	Raw_Data.left = ((UsartReceiveRemote[5] >> 4) & 0x000C) >> 2;
	Raw_Data.right = ((UsartReceiveRemote[5] >> 4) & 0x0003);
	//LostCounterFeed(RC_INDEX);  //每次接收到数据就重置遥控器计数器
  MR2.Target.YSpeed = (Raw_Data.ch1 - CH0_BIAS) * 5;
  MR2.Target.XSpeed = (Raw_Data.ch0 - CH1_BIAS) * 5;
  MR2.Target.ASpeed = (Raw_Data.ch2 - CH3_BIAS) * 5;
  MR2.Target.BSpeed = (Raw_Data.ch3 - CH3_BIAS) * 5;
}



void GyroReceiveHandle()
{

     if(Re_buf[0]==0x55)      //检查帧头
     {  
			switch(Re_buf [1])
			{
				case 0x51:
				a[0] = ((short)(Re_buf[3]<<8| Re_buf [2]))/ 32768.0*16;
				a[1] = ((short)(Re_buf[5]<<8| Re_buf [4]))/ 32768.0*16;
				a[2] = ((short)(Re_buf [7]<<8| Re_buf [6]))/32768.0*16;
				T = ((short)(Re_buf [9]<<8| Re_buf [8]))/340.0+36.25;
				break;
				
				case 0x52:
				w[0] = ((short)(Re_buf [3]<<8| Re_buf [2]))/32768.0*2000;
				w[1] = ((short)(Re_buf [5]<<8| Re_buf [4]))/32768.0*2000;
				w[2] = ((short)(Re_buf [7]<<8| Re_buf [6]))/32768.0*2000;
				T = ((short)(Re_buf [9]<<8| Re_buf [8]))/340.0+36.25;
				break;
				
				case 0x53:
				angle[0] = ((short)(Re_buf [3]<<8| Re_buf [2]))/32768.0*180;
				angle[1] = ((short)(Re_buf [5]<<8| Re_buf [4]))/32768.0*180;
				angle[2] = ((short)(Re_buf [7]<<8| Re_buf [6]))/32768.0*180;
				T = ((short)(Re_buf [9]<<8| Re_buf [8]))/340.0+36.25;
				break;
			} 
    }
       
     

}



