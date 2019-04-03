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
#include "Supervise.h"
#include "UsartReceive.h"
#include "MR2Init.h"
#include "Mission.h"
#include "SendSignal.h"
#include "LED.h"
#include "tim.h"
#include "ACTION.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
int angleBar1=120;
int angleBar2=190;
int servo1;
int servo2=1000;
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
  * @brief  未定义留作备用线�?
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

    }
    /* USER CODE END LEDShow */
}

/* USER CODE BEGIN Header_MR1MainTask */
/**
* @brief MR1工作主线�?
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_MR1MainTask */
void MR1MainTask(void const * argument)
{
    /* USER CODE BEGIN MR1MainTask */
//angleLast1=angleBar1;
//	angleLast2=angleBar2;
    /* Infinite loop */
    for(;;)
    {
        if(MR2.Target.YSpeed>1000)
            action_forward();
        else if(MR2.Target.YSpeed<-1000)
            action_backward();
        else if(MR2.Target.XSpeed>1000)
            action_rightward();
        else if(MR2.Target.XSpeed<-1000)
            action_leftward();
        else if(MR2.Target.ASpeed>1000)
            action_turnR();
        else if(MR2.Target.ASpeed<-1000)
            action_turnL();

        /*else if((MR2.Target.BSpeed>1000)||(MR2.Target.BSpeed<-1000))
        {
            if (MR2.Target.BSpeed>1000)
        				{
                ++angleBar1;
        					HAL_Delay(20);
        				}
            else
        				{
        					--angleBar1;
        					HAL_Delay(20);
        				}

            if (angleBar1>135)
                angleBar1=135;
            else if (angleBar1<0)
                angleBar1=0;
            action_Bar1(angleBar1);
        }
        else if((MR2.Target.ASpeed>1000)||(MR2.Target.ASpeed<-1000))
        {
            if (MR2.Target.ASpeed>1000)
        				{
                ++angleBar2;
        					HAL_Delay(20);
        				}
            else
        				{
                --angleBar2;
        					HAL_Delay(20);
        				}
            if (angleBar2>190)
                angleBar2=190;
            else if (angleBar2<0)
                angleBar2=0;
            action_Bar2(angleBar2);
        }*/
        else
            action_still();

    }
    /* USER CODE END MR1MainTask */
}

/* SuperviseTask function */
void SuperviseTask(void const * argument)
{
    /* USER CODE BEGIN SuperviseTask */
    //  SuperVise();
    /* USER CODE END SuperviseTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
/**
* @brief USART涓插彛鎺ユ敹鍥炶皟鍑芥暟
* @param 涓插彛瀹炰緥鍙ユ焺
* @retval None
*/
void HAL_UART_RxCpltCallback (UART_HandleTypeDef *huart)
{
    if(huart == &huart1)          //涓插彛1浣滀负閬ユ帶鍣ㄦ帴鏀跺彞鏌?
    {
        HAL_UART_Receive_DMA(&huart1, UsartReceiveRemote, 18u);
        RemoteReceiveHandle();      //杩涘叆涓插彛鎺ユ敹瑙ｇ爜鍑芥暟
    }
//  else if(huart == &huart6)     //涓插彛6浣滀负闄€铻轰华鎺ユ敹鍙ユ焺
//	{
//		HAL_UART_Receive_DMA(&huart6, &GyroReceiveData, 1u);
//		GyroReceiveHandle();        //杩涘叆涓插彛鎺ユ敹瑙ｇ爜鍑芥暟
//	}
}
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
