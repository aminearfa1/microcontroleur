#include <STM32f10x.h>
int main (void)
	
{
//activation horloge A et C.
RCC->APB2ENR = RCC->APB2ENR | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPCEN;

	
	
	//green led pc10
GPIOC->CRH = GPIOC->CRH & ~(0xF << 8); //  push-pull b0001
GPIOC->CRH = GPIOC->CRH | (0x02 << 8); //  push-pull b0001

	//bouton poussoir pc8
GPIOC->CRH = GPIOC->CRH & ~(0xF << 0);  //  floating b0100
GPIOC->CRH = GPIOC->CRH | (0x04 << 0); //  floating b0100


	while (1) {
	
	if (GPIOC->IDR &	(1<<8)	){
	if (GPIOC->ODR &	(1<<10))
			GPIOC->ODR = GPIOC->ODR & ~(1<<10);

	}
	else {
		GPIOC->ODR = GPIOC->ODR | (1<<10);
	}
		
	
	
}
	}