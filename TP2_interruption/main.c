#include "Driver_GPIO.h"
#include "MyTimer.h"
#include <stm32f10x.h>
#include <stdio.h>


MyGPIO_Struct_TypeDef led;
MyGPIO_Struct_TypeDef pwm;
MyTimer_Struct_TypeDef tim;

void callback(void){

MyGPIO_Toggle(led.GPIO, led.GPIO_Pin);
}

int main (void)
{
	// conf gpio led + horloge
	led.GPIO=GPIOC;
	led.GPIO_Conf=Out_PushPull;
	led.GPIO_Pin=10;
	MyGPIO_Init(&led);
	
	
	// conf gpio pwm + horloge
	pwm.GPIO=GPIOA;
	pwm.GPIO_Conf=AltOut_PushPull;
	pwm.GPIO_Pin=0;
	MyGPIO_Init(&pwm);

	tim.Timer=TIM2;
	tim.ARR=3998 ;
	tim.PSC= 1000;
	MyTimer_Base_Init(&tim);
	
	
	
//MyTimer_PWM_Init(tim.Timer, 1);
//MyTimer_PWM_ConfigureRatio(tim.Timer,1, 20);
	
	MyTimer_ActiveIT(tim.Timer, 3,callback); 
	MyTimer_Base_Start(tim.Timer);

	while(1)
		{
				
		}
}

