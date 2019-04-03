#include "ACTION.h"
#include "SERVO.h"
#include "stm32f4xx_hal.h"

/*
void action_Bar1(int angle)
{
    while (angle > angleLast1)
    {
        ++angleLast1;
        servoBar1_angle(angleLast1);
        HAL_Delay(20);
    }
    while (angle < angleLast1)
    {
        --angleLast1;
        servoBar1_angle(angleLast1);
        HAL_Delay(20);
    }
}

void action_Bar2(int angle)
{
    while (angle > angleLast2)
    {
        ++angleLast2;
        servoBar2_angle(angleLast2);
        HAL_Delay(20);
    }
    while (angle < angleLast2)
    {
        --angleLast2;
        servoBar2_angle(angleLast2);
        HAL_Delay(20);
    }
}*/

void action_still(void)
{
  //servoLeg_angle(110,130,130,110,50,50,50,50);  
	servoLeg_angle(85,85,85,85,50,50,50,50);
  //  action_Bar1(120);
   // action_Bar2(190);
}

void action_forward(void)
{
    servoLeg_angle(60,60,110,110,50,70,50,70);
    HAL_Delay(300);
    servoLeg_angle(60,60,110,110,50,50,50,50);
    HAL_Delay(200);
    servoLeg_angle(110,110,60,60,70,50,70,50);
    HAL_Delay(300);
    servoLeg_angle(110,110,60,60,50,50,50,50);
    HAL_Delay(200);
}

void action_backward(void)
{
    servoLeg_angle(60,60,110,110,70,50,70,50);
    HAL_Delay(300);
    servoLeg_angle(60,60,110,110,50,50,50,50);
    HAL_Delay(200);
    servoLeg_angle(110,110,60,60,50,70,50,70);
    HAL_Delay(300);
    servoLeg_angle(110,110,60,60,50,50,50,50);
    HAL_Delay(200);
}

void action_leftward(void)
{
    servoLeg_angle(60,110,60,110,70,50,70,50);
    HAL_Delay(300);
    servoLeg_angle(60,110,60,110,50,50,50,50);
    HAL_Delay(200);
    servoLeg_angle(110,60,110,60,50,70,50,70);
    HAL_Delay(300);
    servoLeg_angle(110,60,110,60,50,50,50,50);
    HAL_Delay(200);
}

void action_rightward(void)
{
    servoLeg_angle(60,110,60,110,50,70,50,70);
    HAL_Delay(300);
    servoLeg_angle(60,110,60,110,50,50,50,50);
    HAL_Delay(200);
    servoLeg_angle(110,60,110,60,70,50,70,50);
    HAL_Delay(300);
    servoLeg_angle(110,60,110,60,50,50,50,50);
    HAL_Delay(200);
}
/*
void action_uphill(int n)
{
    for(int i = 0; i<n; i++)
    {
        servoLeg_angle(110,110,60,60,60,100,120,40);
        HAL_Delay(300);
        servoLeg_angle(110,110,60,60,40,95,95,40);
        HAL_Delay(200);
        servoLeg_angle(60,60,110,110,40,115,95,60);
        HAL_Delay(300);
        servoLeg_angle(60,60,110,110,40,95,95,40);
        HAL_Delay(200);
    }
}
void action_downhill(int n)
{
    for(int i = 0; i<n; i++)
    {
			servoLeg_angle(110,60,110,160,100,95,95,100);
    HAL_Delay(200);

        servoLeg_angle(160,110,60,110,120,70,110,100);
        HAL_Delay(200);
        servoLeg_angle(160,110,60,110,100,50,50,100);
        HAL_Delay(200);
        servoLeg_angle(110,60,110,160,100,70,50,120);
        HAL_Delay(200);
        servoLeg_angle(110,60,110,160,100,50,50,100);
        HAL_Delay(200);
    }
}
void action_leap(void)
{
    servoLeg_angle(110,130,130,110,50,50,50,50);//初始姿态
    action_Bar1(120);
    //action_Bar1(190);
    HAL_Delay(500);
	servoLeg_angle(110,130,130,110,40,130,40,50);
	HAL_Delay(400);
	servoLeg_angle(110,40,130,110,40,130,40,40);
	HAL_Delay(500);
	servoLeg_angle(110,40,130,110,40,90,40,40);
	HAL_Delay(400);
	servoLeg_angle(110,40,130,110,40,90,130,40);
	HAL_Delay(400);
	servoLeg_angle(110,40,40,110,40,90,130,40);
	HAL_Delay(500);
	servoLeg_angle(110,40,40,110,40,90,90,40);
	HAL_Delay(400);
	servoLeg_angle(60,40,40,60,40,60,60,40);
	HAL_Delay(500);
	action_forward();
	//上垒结束
	servoLeg_angle(60,40,40,60,130,60,60,40);
	HAL_Delay(500);
	servoLeg_angle(160,40,40,60,130,60,60,40);
	HAL_Delay(500);
	servoLeg_angle(160,40,40,60,100,60,60,40);
	HAL_Delay(500);
		servoLeg_angle(160,40,40,60,100,60,60,130);
	HAL_Delay(500);
	servoLeg_angle(160,40,40,160,100,60,60,130);
	HAL_Delay(500);
	servoLeg_angle(160,40,40,160,100,60,60,100);
	HAL_Delay(500);
	
		servoLeg_angle(120,40,110,160,100,80,60,120);
	HAL_Delay(400);
	servoLeg_angle(120,40,110,160,100,60,60,100);
	HAL_Delay(400);
	servoLeg_angle(160,110,60,120,120,60,80,100);
	HAL_Delay(400);
	servoLeg_angle(160,110,60,120,100,60,60,100);
	HAL_Delay(400);
	
    servoLeg_angle(110,130,130,60,40,120,40,60);//右上抬
    HAL_Delay(900);
    servoLeg_angle(110,60,130,60,40,120,40,60);//右上前
    HAL_Delay(900);
    servoLeg_angle(110,60,130,60,40,95,40,40);//右上搭
    HAL_Delay(900);
    servoLeg_angle(110,60,130,110,40,95,40,60);//左下抬前
    action_Bar1(0);
    HAL_Delay(900);
    servoLeg_angle(110,60,130,110,40,95,40,40);//左下放
    HAL_Delay(900);
    servoLeg_angle(110,60,130,110,40,95,120,40);//左上抬
    HAL_Delay(900);
    servoLeg_angle(110,60,60,110,40,95,120,40);//左上前
    HAL_Delay(900);
    servoLeg_angle(110,60,60,110,40,95,95,40);//左上前
    HAL_Delay(900);

    action_uphill(3);

    servoLeg_angle(60,60,110,110,140,95,95,80);
    HAL_Delay(300);
    servoLeg_angle(160,110,60,60,140,90,120,80);
    HAL_Delay(500);
    servoLeg_angle(160,110,60,60,100,90,90,80);
    HAL_Delay(200);
    servoLeg_angle(160,110,60,60,100,95,95,140);
    HAL_Delay(300);
    servoLeg_angle(110,60,110,160,100,120,95,140);
    HAL_Delay(500);
    servoLeg_angle(110,60,110,160,100,95,95,100);
    HAL_Delay(200);

    action_downhill(3);
}*/
void action_turnL(void)
{
    servoLeg_angle(100,100,100,100,65,50,65,50);// 140, 20, 105, 75, 140, 20, 105);//??.5.??.1.????45,??.8??.4??45
    HAL_Delay(300);
    servoLeg_angle(100,100,100,100,50,50,50,50);//?????
    HAL_Delay(200);
    servoLeg_angle(55,55,55,55,50,65,50,65);//??.5.??.1.??45,??.8.??.4.????45
    HAL_Delay(300);
    servoLeg_angle(55,55,55,55,50,50,50,50);//?????
    HAL_Delay(200);
}
void action_turnR(void)
{
    servoLeg_angle(55,55,55,55,65,50,65,50);//??.5.??.1.??45,??.8.??.4.????45
    HAL_Delay(300);
    servoLeg_angle(55,55,55,55,50,50,50,50);//?????
    HAL_Delay(200);
    servoLeg_angle(100,100,100,100,50,65,50,65);// 140, 20, 105, 75, 140, 20, 105);//??.5.??.1.????45,??.8??.4??45
    HAL_Delay(300);
    servoLeg_angle(100,100,100,100,50,50,50,50);//?????
    HAL_Delay(200);
}
