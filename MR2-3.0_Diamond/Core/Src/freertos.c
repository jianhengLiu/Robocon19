/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * 文件�?          : freertos.c
  * 创建时间        : 2019.02.12
  * 作�??            : 任云�?
  *-----------------------------------------------------------------------------
  * �?近修改时�?    : 2019.02.15
  * 修改�?          : 任云�?
  ******************************************************************************
  *									文件描述								   *
  ******************************************************************************
  *	freertos操作系统，MR1�?有工作的循环进行位置
  ******************************************************************************
  * 1.本代码基于STM32F427IIH6�?发，编译环境为Keil 5，基于FreeRTOS进行�?发�??
  * 2.本代码只适用于Robocon 2019MR1机器人，不建议用于其他用�?
  * 3.本代码以UTF-8格式编码，请勿以ANSI编码形式打开
  * 4.本代码包含大量中文注释，请仔细�?�读代码后使�?
  * 5.本代码最终解释权归哈尔滨工业大学（深圳）Robocon战队�?�?
  *
  * Copyright (c) 2019 哈尔滨工业大学（深圳）Robocon战队 版权�?�?
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */     
#include "gpio.h"
#include "usart.h"
#include "UsartReceive.h"
#include "MR2Init.h"
#include "Action.h"
#include "LED.h"
#include "SendSignal.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define CHASSIS
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId MR1OtherHandle;
osThreadId LEDShowTaskHandle;
osThreadId RobotTaskHandle;
osTimerId SuperviseTimerHandle;
osSemaphoreId JudgeSignalHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void MR1OtherTask(void const * argument);
void LEDShow(void const * argument);
void MR1MainTask(void const * argument);
void SuperviseTask(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* definition and creation of JudgeSignal */
  osSemaphoreDef(JudgeSignal);
  JudgeSignalHandle = osSemaphoreCreate(osSemaphore(JudgeSignal), 1);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* Create the timer(s) */
  /* definition and creation of SuperviseTimer */
  osTimerDef(SuperviseTimer, SuperviseTask);
  SuperviseTimerHandle = osTimerCreate(osTimer(SuperviseTimer), osTimerPeriodic, NULL);

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
		osTimerStart(SuperviseTimerHandle, 2);                   //���ϵͳÿ2msִ��һ��
  /* USER CODE END RTOS_TIMERS */

  /* Create the thread(s) */
  /* definition and creation of MR1Other */
  osThreadDef(MR1Other, MR1OtherTask, osPriorityNormal, 0, 128);
  MR1OtherHandle = osThreadCreate(osThread(MR1Other), NULL);

  /* definition and creation of LEDShowTask */
  osThreadDef(LEDShowTask, LEDShow, osPriorityNormal, 0, 128);
  LEDShowTaskHandle = osThreadCreate(osThread(LEDShowTask), NULL);

  /* definition and creation of RobotTask */
  osThreadDef(RobotTask, MR1MainTask, osPriorityNormal, 0, 4096);
  RobotTaskHandle = osThreadCreate(osThread(RobotTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
}

/* USER CODE BEGIN Header_MR1OtherTask */
/**
  * @brief  Function implementing the MR1Other thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_MR1OtherTask */
void MR1OtherTask(void const * argument)
{

  /* USER CODE BEGIN MR1OtherTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END MR1OtherTask */
}

/* USER CODE BEGIN Header_LEDShow */
/**
* @brief LED闪烁线程
* @param None
* @retval None
*/
/* USER CODE END Header_LEDShow */
void LEDShow(void const * argument)
{
  /* USER CODE BEGIN LEDShow */
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_11,GPIO_PIN_SET);//初始化为熄灭
	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_14,GPIO_PIN_SET);//停止状�?�红灯亮
  /* Infinite loop */
  for(;;)
  {
    /*
		switch(MR1.WorkState)
		{
			case L1_R2_MANUAL:
				LED_MANUAL();break;
			case L2_Rx_STOP:
				LED_STOP();break;
			case L3_R2_Move:
				LED_HIGH();break;
			default:;
		}*/
               HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_1);
               HAL_Delay(SPEED);
               HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_2);
               HAL_Delay(SPEED);
               HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_3);
               HAL_Delay(SPEED);
               HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_4);
               HAL_Delay(SPEED);
               HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_5);
               HAL_Delay(SPEED);
               HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_6);
               HAL_Delay(SPEED);
               HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_7);
               HAL_Delay(SPEED);
               HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_8);
  }
  /* USER CODE END LEDShow */
}

/* USER CODE BEGIN Header_MR1MainTask */
/**
* @brief Function implementing the RobotTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_MR1MainTask */
void MR1MainTask(void const * argument)
{
		/* USER CODE BEGIN MR1MainTask */
  /* Infinite loop */
//	int countt = 1;
  for(;;)
  {
		testServos(0);
//		countt = -countt;
//		SquatRise(countt);
	  //MR2.Angle[1][1] = 20;
		//setAngle(1);
		//sendAngle(1,3,MR2.OutPutAngle[1][1]);
//    osDelay(1);
  }
  /* USER CODE END MR1MainTask */
}

/* SuperviseTask function */
void SuperviseTask(void const * argument)
{
  /* USER CODE BEGIN SuperviseTask */

  /* USER CODE END SuperviseTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
