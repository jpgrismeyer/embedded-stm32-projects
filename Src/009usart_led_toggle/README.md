# 009usart_led_toggle

## Overview

This project demonstrates basic USART communication using the STM32L475 microcontroller. When the microcontroller receives a specific command via USART (e.g., a character), it toggles an LED connected to GPIOB pin 14.

This example is part of a bare-metal STM32 driver development series, and uses a custom USART driver implemented from scratch.

---

## Features

- USART1 peripheral initialized in TX-only or RX-only mode.
- Baud rate: 115200
- Word length: 8 bits
- No parity
- 1 stop bit
- No hardware flow control
- GPIOB pin 14 used to control an LED

---

## Hardware Setup

- STM32L475VG (on B-L475E-IOT01A board)
- PB14 connected to on-board or external LED
- USART1 (PA9 as TX, PA10 as RX)
- Serial terminal on PC (e.g., PuTTY, TeraTerm) with:
  - Baud: 115200
  - 8 data bits
  - No parity
  - 1 stop bit
  - No flow control

---

## Usage

1. Connect the STM32 board to your PC via USB.
2. Open a serial terminal and connect to the correct COM port at 115200 baud.
3. Send any character (e.g., `t`) from the terminal.
4. Each character received will toggle the state of the LED on PB14.

---

## File Structure

009usart_led_toggle/
├── 009usart_led_toggle.c # Main application code
├── README.md # This documentation file


---

## Dependencies

- Custom USART driver (`stm32l47xx_usart_driver.c/.h`)
- Custom GPIO driver (`stm32l475xx_gpio_driver.c/.h`)
- CMSIS device header for STM32L4 (`stm32l47xx.h`)

---

## License

This project is for educational and demonstration purposes.
