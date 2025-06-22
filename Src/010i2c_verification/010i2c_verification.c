/*
 * 010i2c_verification.c
 *
 *  Created on: May 30, 2025
 *      Author: admin
 */
#include"stm32l47xx.h"
#include"stm32l475xx_gpio_driver.h"
#include"stm32l47xx_i2c_driver.h"



#define SLAVE_ADDR  0x50  // Dirección ficticia
#define LED_PIN     GPIO_PIN_NO_14

void delay(void)
{
    for (uint32_t i = 0; i < 500000; i++);
}

void LED_Init(void)
{
    GPIO_Handle_t GpioLED;
    GpioLED.pGPIOx = GPIOB;
    GpioLED.GPIO_PinConfig.GPIO_PinNumber = LED_PIN;
    GpioLED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLED.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GpioLED.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

    GPIO_PeriClockControl(GPIOB, ENABLE);
    GPIO_Init(&GpioLED);
}

void I2C1_GPIOInits(void)
{
    GPIO_Handle_t I2CPins;
    I2CPins.pGPIOx = GPIOB;
    I2CPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
    I2CPins.GPIO_PinConfig.GPIO_PinAltFunMode = 4;
    I2CPins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
    I2CPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
    I2CPins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

    // SCL -> PB6
    I2CPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_6;
    GPIO_Init(&I2CPins);

    // SDA -> PB7
    I2CPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_7;
    GPIO_Init(&I2CPins);
}

void I2C1_Inits(void)
{
    I2C_Handle_t I2C1handle;
    I2C1handle.pI2Cx = I2C1;
    I2C1handle.I2CConfig.I2C_ACKControl = I2C_ACK_ENABLE;

    I2C_Init(&I2C1handle);
}

int main(void)
{
    LED_Init();
    I2C1_GPIOInits();
    I2C1_Inits();

    uint8_t txData = 0xAA;
    uint8_t rxData = 0;

    // Envío
    I2C_MasterSendData(I2C1, &txData, 1, SLAVE_ADDR, 0);

    // Recepción
    I2C_MasterReceiveData(I2C1, &rxData, 1, SLAVE_ADDR, 0);

    // Si recibió algo distinto de 0x00, hacer parpadear LED
    if (rxData != 0x00)
    {
        while (1)
        {
            GPIO_ToggleOutputPin(GPIOB, LED_PIN);
            delay();
        }
    }
    else
    {
        // Si no recibió nada útil, dejar LED encendido
        GPIO_WriteToOutputPin(GPIOB, LED_PIN, GPIO_PIN_SET);
        while (1);
    }
}

