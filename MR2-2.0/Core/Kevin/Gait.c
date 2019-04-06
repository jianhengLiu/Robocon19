#include "main.h"
#include "MR2Init.h"
/*
电机编号

										【1】
										 ||
					  	{POWER}||{CONTREO}
										 ||
									   ||
										 ||
	【2】=============[SE]===============【4】
										 ||
										 ||
										 ||
										 ||
										 ||
										 ||
										【3】

电机1：
	使能：PF0
	电平控制：PE4 PE12
	输出口：OUTPUT1
电机2：
	使能：PF1
	电平控制：PE5 PE6
	输出口：OUTPUT1
电机1：
	使能：PC0
	电平控制：PB0 PB1
	输出口：OUTPUT1
电机1：
	使能：PC4
	电平控制：PC2 PC3
	输出口：OUTPUT1
*/


/**
* @brief 电平改变操作接口函数
* @param None
* @retval None
*/

void MoveLeg(int motor,state_e state)
{
	switch(motor)
	{
		case 1:
		{
			if(state == U)
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

		case 2:
		{
			if(state == U)
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
		
		case 3:
		{
			if(state == U)
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
		
		case 4:
		{
			if(state == U)
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
			
	}
}


void StopLeg()
{
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_6,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_12,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_4,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
}

/**
* @brief MR2初始化四肢位置
* @param None
* @retval None
*/
void GetReady()
{
	int i;
	for(i = 1 ; i<5 ; i++)
	{
		MoveLeg(i,D);
	}
	HAL_Delay(8000);
	StopLeg();
	
	MoveLeg(3,U);
	while(MR2.Gyro.zangle < 30)
	{
	}
	StopLeg();
}

/**
* @brief MR2向前运动
* @param None
* @retval None
*/
void MoveForward()
{
	while(MR2.WorkState == MoveStright) 
	{
		MoveLeg(2,U);
		MoveLeg(4,U);
		HAL_Delay(1000);
		StopLeg();
		
		MoveLeg(2,D);
		MoveLeg(4,D);
		HAL_Delay(1000);
		StopLeg();
	}
}

/**
* @brief MR2跨障A
* @param None
* @retval None
*/
void MR2_CrossHill()
{
	// 提升整体高度预备跨障
		MoveLeg(3,U);
		MoveLeg(1,U);
		HAL_Delay(2000);
		StopLeg();
		
		int Error = MR2.Gyro.zangle - 30;
		if(Error > 0 ) // 倾角过大
		{
			while(Error > 1)
			{
				MoveLeg(2,U);
				Error  = MR2.Gyro.zangle - 30;
			}
			StopLeg();
		}
		else	//	倾角过小
		{
			while(Error > 1)
			{
				MoveLeg(2,D);
				Error  = MR2.Gyro.zangle - 30;
			}
			StopLeg();
		}
		
		MoveLeg(1,D);
		HAL_Delay(500);
		MoveLeg(3,D);
		HAL_Delay(2000);
		StopLeg();
		
		MoveLeg(3,U);
		MoveLeg(1,U);
		HAL_Delay(2000);
		StopLeg();
		
		Error = MR2.Gyro.zangle - 30;
		if(Error > 0 ) // 倾角过大
		{
			while(Error > 1)
			{
				MoveLeg(2,U);
				Error  = MR2.Gyro.zangle - 30;
			}
			StopLeg();
		}
		else	//	倾角过小
		{
			while(Error > 1)
			{
				MoveLeg(2,D);
				Error  = MR2.Gyro.zangle - 30;
			}
			StopLeg();
		}
	
		
}
