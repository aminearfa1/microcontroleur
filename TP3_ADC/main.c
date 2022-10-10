#include <Driver_GPIO.h>
#include "MyTimer.h"
#include <stm32f10x.h>
#include <MyADC.h>


MyGPIO_Struct_TypeDef led;
MyGPIO_Struct_TypeDef pwm;
MyTimer_Struct_TypeDef tim;
MyGPIO_Struct_TypeDef adc;

/*void callback(void){

MyGPIO_Toggle(led.GPIO, led.GPIO_Pin);
}*/

int main (void)
{
	int signal=0;
	
	
	//Adc config
	adc.GPIO=GPIOB;	
	adc.GPIO_Conf=In_Analog;
	adc.GPIO_Pin=0;
	MyGPIO_Init(&adc);
	
	
	
	
	// conf gpio pwm + horloge
	pwm.GPIO=GPIOA;
	pwm.GPIO_Conf=AltOut_PushPull;
	pwm.GPIO_Pin=0;
	MyGPIO_Init(&pwm);

	tim.Timer=TIM2;
	tim.ARR= (720-1);
	tim.PSC= 0;
	MyTimer_Base_Init(&tim);
	
	
	
MyTimer_PWM_Init(tim.Timer, 1);
MyTimer_PWM_ConfigureRatio(tim.Timer,1, 0);
	
//MyTimer_ActiveIT(tim.Timer, 3,callback); 

//ADC Initialisation
ADC_Init();

//start pwm
MyTimer_Base_Start(tim.Timer);




	while(1)
		{
				signal = single_conversion();
			MyTimer_PWM_ConfigureRatio(tim.Timer,1, 100 * signal / 0xFFF); // pour varier l'intensité entre 0 et 100;

		}
}

