# STM32L4 - External Interrupt with Button (EXTI2)

### 🛠 Description

This project demonstrates the use of **external interrupts** on the STM32L475VG microcontroller to toggle an LED when a button is pressed. It uses **custom low-level drivers** to configure GPIO and NVIC, handling the interrupt via EXTI line 2.

---

### 🧰 Technologies Used

- **Microcontroller**: STM32L475VG
- **Language**: C (bare-metal)
- **IDE**: STM32CubeIDE
- **Drivers**: Custom GPIO & EXTI
- **Debugger**: ST-Link V2

---

### ⚙️ How It Works

- PB14 is set as a **digital output** to drive the LED.
- PB2 is configured as an **input with pull-up**, and **interrupt on falling edge** (button press).
- When the button connected to PB2 is pressed, the **EXTI2_IRQHandler()** is triggered.
- Inside the ISR, the pending interrupt is cleared and the LED toggles.

---

### 🔌 Pinout

| Pin  | Function                |
|------|-------------------------|
| PB14 | LED Output              |
| PB2  | Button Input (EXTI2)    |

> The button is active-low and requires a pull-up configuration (configured via GPIO_PIN_PU).

---

### ▶️ Build & Run

1. Open the project in **STM32CubeIDE**.
2. Flash the firmware to the STM32L4 board.
3. Press the button on PB2 → LED toggles via interrupt.

---

### 📁 File structure

/Core
└── Src
└── Inc
/Drivers
└── GPIO_Driver.c
└── GPIO_Driver.h
main.c
README.md


---

### 📸 Demo

> *(Optional: insert photo or short video of the interrupt behavior)*

---

### 📌 Author

Created and maintained by [Juan Pablo Grismeyer](https://github.com/jpgrismeyer) – Embedded Systems Engineer
