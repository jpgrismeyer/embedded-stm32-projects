# 🟢 GPIO Toggle Example – STM32L4xx

This project demonstrates how to toggle a GPIO output pin using a custom bare-metal driver on the **STM32L475VG** microcontroller (B-L475E-IOT01A2 board).

It is a basic example that shows the fundamental process of configuring a GPIO pin for output and toggling it at a fixed interval — without using STM32 HAL or CubeMX.

---

## 📌 Project Summary

- **Board**: B-L475E-IOT01A2 (STM32L475VG)
- **Pin used**: PB14 (on-board LED2)
- **Driver**: Custom GPIO driver (register-level)
- **Language**: C11
- **IDE**: STM32CubeIDE or Makefile-based
- **Goal**: Toggle an LED using a GPIO output pin with a manual delay

---

## 📁 File Structure

```text
001_gpio_led_toggle/
├── main.c         ← Application code
└── README.md      ← This file
