/*
 * 013_hts221_usart.c
 *
 *  Created on: Jun 10, 2025
 *      Author: admin
 */

#include "stm32l47xx.h"
#include "stm32l475xx_gpio_driver.h"
#include "stm32l47xx_i2c_driver.h"
#include "stm32l47xx_hts221.h"
#include "stm32l47xx_usart_driver.h"
#include "led.h"
#include <string.h>
#include <stdio.h>

extern void initialise_monitor_handles(void); // para semihosting si se quiere usar

I2C_Handle_t I2C2Handle;
USART_Handle_t USART2Handle;

void delay(void)
{
	for (uint32_t i = 0; i < 500000; i++);
}

void I2C2_GPIOInits(void)
{
	GPIO_Handle_t I2CPins;

	I2CPins.pGPIOx = GPIOB;
	I2CPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	I2CPins.GPIO_PinConfig.GPIO_PinAltFunMode = 4;
	I2CPins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
	I2CPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
	I2CPins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	// SCL
	I2CPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_10;
	GPIO_Init(&I2CPins);

	// SDA
	I2CPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_11;
	GPIO_Init(&I2CPins);
}

void I2C2_Inits(void)
{
	I2C2Handle.pI2Cx = I2C2;
	I2C2Handle.I2CConfig.I2C_SCLSpeed = I2C_SCL_SPEED_SM;
	I2C2Handle.I2CConfig.I2C_DeviceAddress = 0x00;

	I2C_Init(&I2C2Handle);
}

void USART2_GPIOInits(void)
{
	GPIO_Handle_t usart_gpios;

	usart_gpios.pGPIOx = GPIOA;
	usart_gpios.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	usart_gpios.GPIO_PinConfig.GPIO_PinAltFunMode = 7;
	usart_gpios.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	usart_gpios.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	usart_gpios.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	// TX
	usart_gpios.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2;
	GPIO_Init(&usart_gpios);

	// RX
	usart_gpios.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_3;
	GPIO_Init(&usart_gpios);
}

void USART2_Inits(void)
{
	USART2Handle.pUSARTx = USART2;
	USART2Handle.USART_Config.USART_Mode = USART_MODE_ONLY_TX;
	USART2Handle.USART_Config.USART_Baud = USART_STD_BAUD_115200;
	USART2Handle.USART_Config.USART_NoOfStopBits = USART_STOPBITS_1;
	USART2Handle.USART_Config.USART_ParityControl = USART_PARITY_DISABLE;
	USART2Handle.USART_Config.USART_WordLength = USART_WORDLEN_8BITS;
	USART2Handle.USART_Config.USART_HWFlowControl = USART_HW_FLOW_CTRL_NONE;

	USART_Init(&USART2Handle);
}

void uart_print(char *msg)
{
	USART_SendData(&USART2Handle, (uint8_t *)msg, strlen(msg));
}

int main(void)
{
	LED_Init();
	I2C2_GPIOInits();
	I2C2_Inits();
	USART2_GPIOInits();
	USART2_Inits();

	HTS221_PowerOn(&I2C2Handle);

	while (1)
	{
		int16_t temp_raw = HTS221_ReadTemperatureRaw(&I2C2Handle);
		int16_t hum_raw = HTS221_ReadHumidityRaw(&I2C2Handle);

		if (temp_raw != 0 && hum_raw != 0)
		{
			LED_On();
			char buffer[64];
			sprintf(buffer, "Temp raw: %d, Hum raw: %d\r\n", temp_raw, hum_raw);
			uart_print(buffer);
		}
		else
		{
			LED_Off();
		}

		delay();
	}

	return 0;
}
