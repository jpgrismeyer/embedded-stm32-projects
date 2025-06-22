# STM32L4xx Bare-Metal Drivers & Projects 🚀

This repository showcases a collection of **bare-metal drivers** and **hands-on examples** written in **C** for **STM32L4xx microcontrollers**, specifically the **B-L475E-IOT01A2 Discovery board**.

The goal is to demonstrate a solid understanding of low-level embedded systems programming, with no use of HAL or abstraction libraries — everything is configured directly from the **Reference Manual**.

---

## 📁 Project Structure
stm32l47xx_drivers/
├── drivers/              ← Custom peripheral drivers
│   ├── Inc/
│   └── Src/
├── Src/                  ← Example applications
├── README.md             ← This file
└── Makefile / STM32CubeIDE project files


---


## ✅ Included Examples

| Example | Folder | Description | Peripherals |
|---------|--------|-------------|-------------|
| 🔹 GPIO Button Polling | `001_led_button_polling` | Toggle a LED with button input using polling | GPIO |
| 🔹 GPIO Button External | `002_led_button_ext` | Toggle LED from external button (simple logic) | GPIO |
| 🔹 GPIO Interrupt | `003_button_interrupt` | Use EXTI interrupt to toggle a LED | GPIO, EXTI |
| 🔹 SysTick LED Blinker | `004_led_toggle_systick` | Blink LED using SysTick delay | SysTick, GPIO |
| 🔹 SPI Transmit Test | `005_spi_tx` | Send “Hello world” over SPI using custom driver | SPI |
| 🔹 SPI TX/RX Loopback | `006_spi_tx_rx` | Full-duplex SPI with loopback and buffer check | SPI |
| 🔹 I²C WHO_AM_I Test | `007_i2c_check` | Read WHO_AM_I from HTS221 via I2C and toggle LED | I2C |
| 🔹 I²C Raw Sensor Data | `008_i2c_hts221_app` | Read raw temp/humidity from HTS221 | I2C, HTS221 |
| 🔹 I²C + UART Output | `009_hts221_usart` | Read HTS221 and print over USART | I2C, UART, HTS221 |
| 🔹 I²C Simple Check | `010_i2c_verification` | Transmit & receive one byte via I2C and blink LED | I2C |
| 🔹 I²C Sensor ID | `011_hts221_whoami` | LED lights up if HTS221 responds with correct ID | I2C, GPIO |
| 🔹 I²C Sensor Logic App | `012_i2c_hts221_readapp` | LED toggling logic based on HTS221 readings | I2C, HTS221 |
| 🔹 Final Sensor+UART App | `013_hts221_usart` | HTS221 data read and sent via UART with LED feedback | I2C, UART, HTS221 |


---

## ⚙️ Platform

- **MCU**: STM32L475VG (ARM Cortex-M4)
- **Board**: B-L475E-IOT01A2
- **Language**: C11
- **IDE**: STM32CubeIDE (optionally Makefile)
- **Debug**: ST-Link V2

---

## 🎯 Technical Goals

- Work directly with peripheral registers via datasheets/RM.
- Implement clean, modular, reusable drivers.
- Document all examples for educational and reference purposes.
- Build a portfolio aligned with real-world embedded software positions.

---

## 👨‍💻 Author

**Juan Pablo Grismeyer**  
Electronics Engineer | Embedded Software Developer (Junior)  
Based near Munich, Germany 🇩🇪  
[juampagrismeyer@gmail.com](mailto:juampagrismeyer@gmail.com)

---

## 🔜 Coming soon

- UART with interrupts  
- BME280 sensor via SPI  
- Final project: FreeRTOS-based environmental monitoring system  

---

🗒️ *This project is actively maintained and part of my portfolio as an embedded software engineer seeking to join the German job market. Feel free to reach out for collaboration or questions.*



