/*
 * 005button_interrupt.c
 *
 *  Created on: Feb 11, 2025
 *      Author: admin
 */


#include "stm32l47xx.h"

void delay(void)
{
	for (uint32_t i=0; i<50000; i++);
}

int main(void){
GPIO_Handle_t Gpioled,GPIOBtn;
	//led02= PB14
	Gpioled.pGPIOx=GPIOB;
	Gpioled.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	Gpioled.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	Gpioled.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	Gpioled.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	Gpioled.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOB, ENABLE);

	GPIO_Init(&Gpioled);

	GPIOBtn.pGPIOx=GPIOB;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_PeriClockControl(GPIOB, ENABLE);

	GPIO_Init(&GPIOBtn);


	//IRQ configurations

	GPIO_IRQPriorityConfig(IRQ_NO_EXTI2, NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI2, ENABLE);

	while(1);


	return 0;
}

void EXTI2_IRQHandler (void) //from startup file
{
	GPIO_IRQHandling(GPIO_PIN_NO_2);
	GPIO_ToggleOutputPin(GPIOB, GPIO_PIN_NO_14);

}

