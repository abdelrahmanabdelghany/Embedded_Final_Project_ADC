#include "stm32f4xx.h"
#include "gpio.h"

void GPIO_Init (GPIO_TypeDef * GPIOx,char pin,char dir,char enable_pin)
{
	//Enable clock to GBIOx
	RCC->AHB1ENR |= (1u<<enable_pin);

	switch(dir){
	case 0:
		{
			// input mode
			GPIOx->MODER &=~(1u<<(2*pin));
			GPIOx->MODER &=~(1u<<(2*pin+1));
			break;

		}
	case 1:
		{
			// output mode
			GPIOx->MODER |= (1u<<(2*pin));
			GPIOx->MODER &=~(1u<<(2*pin+1));
			break;

		}
	case 2:		{
			// alternate mode
			GPIOx->MODER &=~(1u<<(2*pin));
			GPIOx->MODER |= (1u<<(2*pin+1));
			break;

	}
	case 3:		{
			// analog mode
			GPIOx->MODER |= (1u<<(2*pin));
			GPIOx->MODER |= (1u<<(2*pin+1));
			break;

	}
	}
}

char GPIO_Write(GPIO_TypeDef * GPIOx,char pin,char state)
{
	if (GPIOx->MODER & (1u<<(2*pin)))
	{
		if(state)
			{
				GPIOx->ODR |=(1u<<pin);
			}
			else
			{
				GPIOx->ODR &=~(1u<<pin);
			}
		return 0;
	}
	else
	{
		return 1;
	}
}


char GPIO_Read(GPIO_TypeDef * GPIOx,char pin)
{
	if (GPIOx->MODER & ~(1<<(2*pin)))
	{
		return (GPIOx->IDR & (1<<pin));
	}
	else
	{
		return 0;
	}
}



