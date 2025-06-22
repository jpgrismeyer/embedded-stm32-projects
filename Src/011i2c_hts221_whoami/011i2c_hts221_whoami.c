#include "stm32l47xx.h"
#include "stm32l475xx_gpio_driver.h"
#include "stm32l47xx_i2c_driver.h"
#include "stm32l475xx_systick.h"

#define HTS221_ADDR     0x5F   // 7-bit address
#define WHO_AM_I_REG    0x0F

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

void I2C2_GPIOInits(void)
{
    GPIO_Handle_t I2CPins;
    I2CPins.pGPIOx = GPIOB;
    I2CPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
    I2CPins.GPIO_PinConfig.GPIO_PinAltFunMode = 4; // AF4 para I2C2
    I2CPins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
    I2CPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
    I2CPins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

    I2CPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_10; // SCL
    GPIO_Init(&I2CPins);

    I2CPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_11; // SDA
    GPIO_Init(&I2CPins);
}

void I2C2_Inits(void)
{
    I2C_Handle_t I2C2Handle;
    I2C2Handle.pI2Cx = I2C2;

    //I2C2Handle.I2CConfig.I2C_TIMINGR = 0x00303D5B;
    //I2C2Handle.I2CConfig.I2C_NoStretch = 0; // 0: NOSTRETCH disabled

    I2C_Init(&I2C2Handle);
}

int main(void)
{
    uint8_t who_am_i = 0;

    LED_Init();
    I2C2_GPIOInits();
    I2C2_Inits();

    delay_ms(100); // opcional, dar tiempo tras el reset del sensor

    uint8_t reg = WHO_AM_I_REG;

    I2C_MasterSendData(I2C2, &reg, 1, HTS221_ADDR, 0);
    I2C_MasterReceiveData(I2C2, &who_am_i, 1, HTS221_ADDR, 0);

    if (who_am_i == 0xBC)
    {
        GPIO_WriteToOutputPin(GPIOB, GPIO_PIN_NO_14, GPIO_PIN_SET); // Enciende LED
    }

    while (1);
}

