#include "SERVO.h"
#include "tim.h"
#include "stm32f4xx_hal.h"

void servo_init(void)
{
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
    HAL_TIM_PWM_Start(&htim5,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim5,TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim5,TIM_CHANNEL_3);	
    HAL_TIM_PWM_Start(&htim5,TIM_CHANNEL_4);
    HAL_TIM_PWM_Start(&htim8,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim8,TIM_CHANNEL_2);
}

void servoLeg_angle(int angleL1, int angleL2, int angleL3, int angleL4, int angleF1, int angleF2, int angleF3, int angleF4)
{
	//右后腿L1-->TIM5_CHANNEL3-->PH12-->B
	//右前腿L2-->TIM5_CHANNEL2-->PH11-->C
	//左前腿L3-->TIM2_CHANNEL2-->PA1 -->T
	//左后腿L4-->TIM2_CHANNEL3-->PA2 -->U
	
	//右后脚F1-->TIM5_CHANNEL4-->PI0 -->A
	//右前脚F2-->TIM5_CHANNEL1-->PH10-->D
	//左前脚F3-->TIM2_CHANNEL1-->PA0 -->S
	//左后脚F4-->TIM2_CHANNEL4-->PA3 -->V
	
//T=2000;
//0.5ms--------------0;2.5%
//2.5ms-----------270;12.5%
    __HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_3,(int)(angleL1*2000/270+500));
    __HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_4,(int)((270-angleF1)*2000/270+500));
    __HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_1,(int)(angleF2*2000/270+500));
    __HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_2,(int)((270-angleL2)*2000/270+500));
    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,(int)(angleL3*2000/270+500));
    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,(int)((270-angleF3)*2000/270+500));
    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,(int)(angleF4*2000/270+500));
    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,(int)((270-angleL4)*2000/270+500));
}

void servoBar1_angle(int angle)
{
	//W
    __HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_1,(int)(angle*4000/270+500));
}

void servoBar2_angle(int angle)
{
	//X
    __HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_2,(int)(angle*4000/270+500));
}
