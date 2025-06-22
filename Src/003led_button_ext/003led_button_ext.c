/*
 * 003led_button_ext.c
 *
 *  Created on: Feb 9, 2025
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
	Gpioled.pGPIOx=GPIOA;
	Gpioled.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_4;
	Gpioled.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	Gpioled.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	Gpioled.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	Gpioled.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);

	GPIO_Init(&Gpioled);

	GPIOBtn.pGPIOx=GPIOB;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOB, ENABLE);

	GPIO_Init(&GPIOBtn);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOB, GPIO_PIN_NO_2)==1)
		{
		delay();
		GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_4);
		}
	}
	return 0;
}
