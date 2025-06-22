/*
 * 012i2c_hts221_readapp.c
 *
 *  Created on: Jun 2, 2025
 *      Author: admin
 */

#include "stm32l47xx.h"
#include "stm32l475xx_gpio_driver.h"
#include "stm32l47xx_i2c_driver.h"
#include "stm32l47xx_hts221.h"
#include "led.h"
#include <stdint.h>


I2C_Handle_t I2C2Handle;

void I2C2_GPIOInits(void)
{
    GPIO_Handle_t I2CPins;

    I2CPins.pGPIOx = GPIOB;
    I2CPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
    I2CPins.GPIO_PinConfig.GPIO_PinAltFunMode = 4;
    I2CPins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
    I2CPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
    I2CPins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

    I2CPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_10;
    GPIO_Init(&I2CPins);

    I2CPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_11;
    GPIO_Init(&I2CPins);
}

int main(void)
{
    LED_Init();

    I2C2_GPIOInits();

    I2C2Handle.pI2Cx = I2C2;
    I2C_Init(&I2C2Handle);

    uint8_t whoami = HTS221_ReadWHOAMI(&I2C2Handle);
    if (whoami == 0xBC)
    {
        LED_On();
    }
    else
    {
        LED_Off();
    }

    HTS221_PowerOn(&I2C2Handle);

    while (1)
    {
        int16_t temp_raw = HTS221_ReadTemperatureRaw(&I2C2Handle);
        int16_t hum_raw = HTS221_ReadHumidityRaw(&I2C2Handle);

        if (temp_raw > 1000 || hum_raw > 1000)
        {
            LED_On();
        }
        else
        {
            LED_Off();
        }
    }
}
