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

| Example | File | Description | Peripheral |
|---------|------|-------------|------------|
| 🔹 GPIO Toggle LED | `001_gpio_led_toggle.c` | Toggle a GPIO pin to blink an LED using a custom driver | GPIO |
| 🔹 SPI Loopback Test | `002_spi_loopback_test.c` | Transmit and receive data over SPI using loopback (MOSI ↔ MISO) | SPI |
| 🔹 I²C Sensor Test | `003_i2c_hts221.c` | Read WHO_AM_I register from HTS221 sensor over I²C | I²C |
| 🔹 UART Echo | `004_uart_echo.c` | Basic UART echo program using custom driver | UART |
| 🔹 FreeRTOS Demo | `005_freertos_multitask.c` | FreeRTOS blink and multitask example | FreeRTOS |
| 🔹 ADC Test | `006_adc_temp_sensor.c` | Read internal temperature sensor using ADC | ADC |

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



