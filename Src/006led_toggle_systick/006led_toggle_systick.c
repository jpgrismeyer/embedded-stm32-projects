/*
 * 006led_toggle_systick.c
 *
 *  Created on: May 24, 2025
 *      Author: admin
 */

#include "stm32l475xx_gpio_driver.h"
#include "stm32l475xx_systick.h"


int main(void) {
	GPIO_Handle_t Gpioled;
		//led02= PB14
		Gpioled.pGPIOx=GPIOB;
		Gpioled.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
		Gpioled.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		Gpioled.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
		Gpioled.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
		Gpioled.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

		GPIO_PeriClockControl(GPIOB, ENABLE);

		GPIO_Init(&Gpioled);

    while (1) {
        GPIO_ToggleOutputPin(GPIOB, GPIO_PIN_NO_14);  // o acceso directo a ODR
        delay_ms(500);
    }
}
