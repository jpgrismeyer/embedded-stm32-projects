/*
 * 008spi_tx_rx_testing.c
 *
 *  Created on: May 27, 2025
 *      Author: admin
 */

#include <string.h>
#include "stm32l47xx.h"
#include "stm32l475xx_gpio_driver.h"
#include "stm32l475xx_spi_driver.h"
#include "stm32l475xx_systick.h"

void SPI1_GPIOInits(void)
{
	GPIO_Handle_t SPIPins;
	SPIPins.pGPIOx = GPIOA;
	SPIPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	SPIPins.GPIO_PinConfig.GPIO_PinAltFunMode = 5;
	SPIPins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	SPIPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	SPIPins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5; // SCK
	GPIO_Init(&SPIPins);
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_6; // MISO
	GPIO_Init(&SPIPins);
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_7; // MOSI
	GPIO_Init(&SPIPins);
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_4; // NSS
	GPIO_Init(&SPIPins);
}

void SPI1_Inits(void)
{
	SPI_Handle_t SPI1handle;
	SPI1handle.pSPIx = SPI1;
	SPI1handle.SPIConfig.SPI_BusConfig = SPI_BUS_CONFIG_FD;
	SPI1handle.SPIConfig.SPI_DeviceMode = SPI_DEVICE_MODE_MASTER;
	SPI1handle.SPIConfig.SPI_SclkSpeed = SPI_SCLK_SPEED_DIV8;
	SPI1handle.SPIConfig.SPI_DFF = SPI_DFF_8BITS;
	SPI1handle.SPIConfig.SPI_CPOL = SPI_CPOL_LOW;
	SPI1handle.SPIConfig.SPI_CPHA = SPI_CPHA_LOW;
	SPI1handle.SPIConfig.SPI_SSM = SPI_SSM_EN;

	SPI_Init(&SPI1handle);
}

void LED_Init(void)
{
	GPIO_Handle_t GpioLED;
	GpioLED.pGPIOx = GPIOB;
	GpioLED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	GpioLED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLED.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLED.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOB, ENABLE);
	GPIO_Init(&GpioLED);
}

int main(void)
{
	//delay_init();
	LED_Init();
	SPI1_GPIOInits();
	SPI1_Inits();

	SPI_SSIConfig(SPI1, ENABLE);

	// Habilitamos el periférico SPI
	SPI_PeripheralControl(SPI1, ENABLE);

	char tx[] = "Hello";
	char rx[sizeof(tx)] = {0};

	for (uint32_t i = 0; i < sizeof(tx) - 1; i++)
	{
		// Transmitir 1 byte
		SPI_SendData(SPI1, (uint8_t*)&tx[i], 1);

		// Recibir 1 byte (requiere haber enviado algo antes)
		SPI_ReceiveData(SPI1, (uint8_t*)&rx[i], 1);
	}

	// Comparar los buffers
	if (memcmp(tx, rx, sizeof(tx) - 1) == 0)
	{
		while (1)
		{
			GPIO_ToggleOutputPin(GPIOB, GPIO_PIN_NO_14);
			delay_ms(500);
		}
	}
	else
	{
		GPIO_WriteToOutputPin(GPIOB, GPIO_PIN_NO_14, 1); // LED encendido fijo si falla
		while (1);
	}
}

