/*
 * i2c_scanner.c
 *
 *  Created on: May 25, 2025
 *      Author: admin
 */


#include "stm32l47xx.h"
#include "stm32l47xx_i2c_driver.h"
#include "stm32l475xx_gpio_driver.h"
#include "stm32l475xx_systick.h"

void I2C1_GPIOInits(void)
{
    GPIO_Handle_t I2CPins;
    I2CPins.pGPIOx = GPIOB;
    I2CPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
    I2CPins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
    I2CPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
    I2CPins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    I2CPins.GPIO_PinConfig.GPIO_PinAltFunMode = 4;

    I2CPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_6; // SCL
    GPIO_Init(&I2CPins);
    I2CPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_7; // SDA
    GPIO_Init(&I2CPins);
}

void I2C1_Inits(void)
{
    I2C_Handle_t I2C1Handle;
    I2C1Handle.pI2Cx = I2C1;
    I2C1Handle.I2CConfig.I2C_ACKControl = I2C_ACK_ENABLE;
    I2C1Handle.I2CConfig.I2C_DeviceAddress = 0x61; // dummy slave address
    I2C1Handle.I2CConfig.I2C_SCLSpeed = I2C_SCL_SPEED_SM;
    I2C_Init(&I2C1Handle);
}

uint8_t I2C_CheckAddress(I2C_RegDef_t *pI2Cx, uint8_t addr)
{
    pI2Cx->ICR = 0xFFFFFFFF; // limpiar flags

    pI2Cx->CR2 = 0;
    pI2Cx->CR2 |= (addr << 1);       // SADD[7:1] shifted
    pI2Cx->CR2 |= (1 << 16);         // NBYTES = 1
    pI2Cx->CR2 &= ~(1 << 10);        // Write
    pI2Cx->CR2 |= (1 << 13);         // START
    pI2Cx->CR2 |= (1 << 25);         // AUTOEND

    int timeout = 100000;
    while (!(pI2Cx->ISR & ((1 << 0) | (1 << 4))) && timeout--); // wait TXE or NACKF

    if (pI2Cx->ISR & (1 << 4)) // NACKF
    {
        pI2Cx->ICR |= (1 << 4); // clear NACKF
        return 0; // no response
    }

    return 1; // responded
}

void LED_Init(void)
{
    GPIO_Handle_t Gpioled;
    Gpioled.pGPIOx = GPIOB;
    Gpioled.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
    Gpioled.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    Gpioled.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    Gpioled.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    Gpioled.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

    GPIO_PeriClockControl(GPIOB, ENABLE);
    GPIO_Init(&Gpioled);
}

int main(void)
{
    I2C1_GPIOInits();
    I2C1_Inits();
    LED_Init();

    uint8_t found = 0;

    for (uint8_t addr = 0x03; addr <= 0x77; addr++)
    {
        if (I2C_CheckAddress(I2C1, addr))
        {
            found = addr;  // dirección encontrada

            break;
        }
        delay_ms(50);
    }

    while (1)
    {
        if (found)
        {
            GPIO_ToggleOutputPin(GPIOB, GPIO_PIN_NO_14); // parpadea si encontró algo
            delay_ms(500);
        }
        else
        {
            GPIO_WriteToOutputPin(GPIOB, GPIO_PIN_NO_14, 1); // fijo si no encontró nada
        }
    }
}
