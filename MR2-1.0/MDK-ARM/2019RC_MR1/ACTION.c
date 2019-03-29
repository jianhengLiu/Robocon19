#include "ACTION.h"
#include "SERVO.h"
#include "stm32f4xx_hal.h"

void action_Bar1(int angle)
{
    servoBar1_angle(angle);
}

void action_Bar2(int angle)
{
    servoBar2_angle(angle);
}

void action_still(void)
{
    servoLeg_angle(85,85,85,85,40,40,40,40);
}

void action_forward(void)
{
	servoLeg_angle(60,60,110,110,40,60,40,60);
    HAL_Delay(300);
    servoLeg_angle(60,60,110,110,40,40,40,40);
    HAL_Delay(200);
    servoLeg_angle(110,110,60,60,60,40,60,40);
    HAL_Delay(300);
    servoLeg_angle(110,110,60,60,40,40,40,40);
    HAL_Delay(200);
}

void action_backward(void)
{
	servoLeg_angle(60,60,110,110,60,40,60,40);
    HAL_Delay(300);
    servoLeg_angle(60,60,110,110,40,40,40,40);
    HAL_Delay(200);
    servoLeg_angle(110,110,60,60,40,60,40,60);
    HAL_Delay(300);
    servoLeg_angle(110,110,60,60,40,40,40,40);
    HAL_Delay(200);
    
}

void action_creep(int n)
{
    for(int i = 0; i<n; i++)
    {
        servoLeg_angle(110,110,60,60,50,100,120,40);
        HAL_Delay(300);
        servoLeg_angle(110,110,60,60,40,100,100,40);
        HAL_Delay(200);
        servoLeg_angle(60,60,110,110,40,120,100,50);
        HAL_Delay(300);
        servoLeg_angle(60,60,110,110,40,100,100,40);
        HAL_Delay(200);
    }
}
void action_leap(void)
{
    //servoLeg_angle(110,130,130,60,40,40,40,40);//初始姿态
	//action_Bar1(90);
	//	action_Bar1(190);
    //HAL_Delay(900);
    servoLeg_angle(110,130,130,60,40,120,40,60);//右上抬
    //HAL_Delay(900);
    //servoLeg_angle(110,40,130,60,40,120,40,60);//右上前
    //HAL_Delay(900);
   // servoLeg_angle(110,40,130,60,40,100,40,60);//右上搭
    //HAL_Delay(900);
    //servoLeg_angle(60,50,100,60,40,100,120,40);//左上抬
    //HAL_Delay(900);
    //servoLeg_angle(60,50,50,60,40,100,120,40);//左上前
    //HAL_Delay(900);
    //servoLeg_angle(60,50,50,60,40,100,100,40);//左上搭
    //HAL_Delay(900);

    //action_creep(1);

    //servoLeg_angle(60,60,110,110,120,100,120,40);//
    //HAL_Delay(200);
    //servoLeg_angle(60,60,60,110,120,100,120,40);//
    //HAL_Delay(200);
    //servoLeg_angle(60,60,60,110,120,100,100,40);//
    //HAL_Delay(200);
    //servoLeg_angle(110,60,110,110,100,100,100,40);//
    //HAL_Delay(200);
		
		
    /*servo_angle(50,100,100,50,40,40,40,40);//30, 160, 20, 110, 70, 160, 20, 150);//????
    HAL_Delay(900);
    servo_angle(50,100,100,50,40,40,40,130);//(30, 160, 20, 110, 70, 160, 80, 150);//???
    HAL_Delay(900);
    servo_angle(50,100,100,100,40,40,40,130);//(30, 160, 20, 110, 70, 160, 80, 110);//???
    HAL_Delay(900);
    servo_angle(50,100,100,100,40,40,40,40);//(30, 160, 20, 110, 70, 160, 20, 110);//???
    HAL_Delay(900);
    servo_angle(50,100,100,100,40,40,130,40);//(30, 160, 20, 110, 70, 100, 20, 110);//???
    HAL_Delay(900);
    servo_angle(50,100,50,100,40,40,130,40);//(30, 160, 20, 110, 40, 100, 20, 110);//???
    HAL_Delay(900);
    servo_angle(50,100,50,100,40,40,40,40);//(30, 160, 20, 110, 40, 160, 20, 110);//???
    HAL_Delay(900);
    servo_angle(50,100,50,100,130,40,40,40);//(30, 100, 20, 110, 40, 160, 20, 110);//???
    HAL_Delay(900);
    servo_angle(100,100,50,100,130,40,40,40);//(70, 100, 20, 110, 40, 160, 20, 110);//???
    HAL_Delay(900);
    servo_angle(100,100,50,100,40,40,40,40);//(70, 160, 20, 110, 40, 160, 20, 110); //???
    HAL_Delay(900);
    servo_angle(100,100,50,100,40,130,40,40);//(70, 160, 80, 110, 40, 160, 20, 110);//???
    HAL_Delay(900);
    servo_angle(100,50,50,100,40,130,40,40);//(70, 160, 80, 140, 40, 160, 20, 110);//???
    HAL_Delay(900);
    servo_angle(100,50,50,100,40,40,40,40);//(70, 160, 20, 140, 40, 160, 20, 110);//???
    HAL_Delay(900);*/
}
void action_turnL(void)
{
    servoLeg_angle(100,100,100,100,55,40,55,40);// 140, 20, 105, 75, 140, 20, 105);//??.5.??.1.????45,??.8??.4??45
    HAL_Delay(300);
    servoLeg_angle(100,100,100,100,40,40,40,40);//?????
    HAL_Delay(200);
    servoLeg_angle(55,55,55,55,40,55,40,55);//??.5.??.1.??45,??.8.??.4.????45
    HAL_Delay(300);
    servoLeg_angle(55,55,55,55,40,40,40,40);//?????
    HAL_Delay(200);
}
void action_turnR(void)
{
    servoLeg_angle(55,55,55,55,55,40,55,40);//??.5.??.1.??45,??.8.??.4.????45
    HAL_Delay(300);
    servoLeg_angle(55,55,55,55,40,40,40,40);//?????
    HAL_Delay(200);
    servoLeg_angle(100,100,100,100,40,55,40,55);// 140, 20, 105, 75, 140, 20, 105);//??.5.??.1.????45,??.8??.4??45
    HAL_Delay(300);
    servoLeg_angle(100,100,100,100,40,40,40,40);//?????
    HAL_Delay(200);
}
