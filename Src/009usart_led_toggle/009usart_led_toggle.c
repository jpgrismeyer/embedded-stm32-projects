/*
 * 009usart_led_toggle.c
 *
 *  Created on: May 30, 2025
 *      Author: admin
 */

#include "stm32l47xx.h"
#include "stm32l47xx_usart_driver.h"
#include "stm32l475xx_gpio_driver.h"
#include <string.h>

void delay(void)
{
	for (uint32_t i = 0; i < 50000; i++);
}

void USART1_GPIOInit(void)
{
	GPIO_Handle_t usart_gpios;

	usart_gpios.pGPIOx = GPIOA;
	usart_gpios.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	usart_gpios.GPIO_PinConfig.GPIO_PinAltFunMode = 7;
	usart_gpios.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	usart_gpios.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	usart_gpios.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	// TX -> PA9
	usart_gpios.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_9;
	GPIO_Init(&usart_gpios);

	// RX -> PA10
	usart_gpios.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_10;
	GPIO_Init(&usart_gpios);
}

void LED_GPIOInit(void)
{
	GPIO_Handle_t led;

	led.pGPIOx = GPIOB;
	led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	led.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	led.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	led.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	led.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOB, ENABLE);
	GPIO_Init(&led);
}

int main(void)
{
	char msg[] = "Hello from STM32!\r\n";

	USART1_GPIOInit();
	LED_GPIOInit();

	USART_Handle_t usart1;
	usart1.pUSARTx = USART1;
	usart1.USART_Config.USART_Baud = USART_STD_BAUD_115200;
	usart1.USART_Config.USART_HWFlowControl = USART_HW_FLOW_CTRL_NONE;
	usart1.USART_Config.USART_Mode = USART_MODE_TX;
	usart1.USART_Config.USART_NoOfStopBits = USART_STOPBITS_1;
	usart1.USART_Config.USART_ParityControl = USART_PARITY_DISABLE;
	usart1.USART_Config.USART_WordLength = USART_WORDLEN_8BITS;

	USART_Init(&usart1);

	USART_PeripheralControl(USART1, ENABLE);

	USART_SendData(USART1, (uint8_t*)msg, strlen(msg));

	// Encender el LED si se envió todo
	GPIO_WriteToOutputPin(GPIOB, GPIO_PIN_NO_14, 1);

	while (1);
}

