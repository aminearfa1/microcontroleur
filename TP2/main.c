#include "Driver_GPIO.h"
#include "MyTimer.h"
#include <stm32f10x.h>
#include <stdio.h>

int main (void)
{
	
	
	//Activé les horloges
	
	//configuration Gpio & Timer &pwm
	
	
	//démarer le timer
	
	
/*	MyTimer_Struct_TypeDef Timer2;
	//PC.10
	MyGPIO_Struct_TypeDef pin10;
	pin10.GPIO=GPIOC;
	pin10.GPIO_Pin=10;
	pin10.GPIO_Conf=Out_PushPull;
	MyGPIO_Init(&pin10);
	
	

	Timer2.Timer=TIM2;
	Timer2.ARR=3998;
	Timer2.PSC=1000;
	MyTimer_Base_Init(&Timer2);
	*/
	/*MyTimer_Base_Stop(Timer2.Timer)*/
	
	/*Configuration de l’interruption dans le coeur*/
	/*TIM2->DIER |= TIM_DIER_UIE;
	NVIC->ISER[0] |= NVIC_ISER_SETENA_28;
	NVIC->IP[28] |= (7<<4);*/ /*priority 7 de l'interruption 28*/
	
	/*Lancement du timer*/
/*	MyTimer_Base_Start(Timer2.Timer)*/
	
	while(1)
		{
				
		}
}

void TIM2_IRQHandler(void)
{
	TIM2->SR &= ~TIM_SR_UIF; //scruter
	MyGPIO_Toggle(GPIOC,10);
}
