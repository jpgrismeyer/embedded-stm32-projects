# STM32L4 - LED Toggle with SysTick Delay

### 🛠 Description

This project demonstrates the use of the **SysTick timer** on the STM32L475VG to toggle an LED every 500 milliseconds. A **custom SysTick-based delay function** is implemented instead of software `for` loops, providing better timing accuracy and scalability for embedded systems.

---

### 🧰 Technologies Used

- **Microcontroller**: STM32L475VG
- **Language**: C (bare-metal)
- **IDE**: STM32CubeIDE
- **Drivers**: Custom GPIO driver and SysTick driver
- **Debugger**: ST-Link V2

---

### ⚙️ How It Works

- PB14 is configured as a **digital output**.
- SysTick is configured to generate ticks at 1ms intervals.
- A `delay_ms()` function is implemented using the SysTick counter.
- In the `while(1)` loop, the LED toggles every 500 ms.

---

### 🔌 Pinout

| Pin  | Function    |
|------|-------------|
| PB14 | LED Output  |

> The LED toggles every 500ms using the system tick timer.

---

### ▶️ Build & Run

1. Clone or download the project.
2. Open it with **STM32CubeIDE**.
3. Flash the firmware to your board.
4. Observe the LED on PB14 toggling at 1Hz.

---

### 📁 File structure
/Core
└── Src
└── Inc
/Drivers
└── GPIO_Driver.c/.h
└── SysTick_Driver.c/.h
main.c
README.md


---

### 📸 Demo

> *(Optional: add a video showing 500ms LED blinking)*

---

### 📌 Author

Created and maintained by [Juan Pablo Grismeyer](https://github.com/jpgrismeyer) – Embedded Systems Engineer

