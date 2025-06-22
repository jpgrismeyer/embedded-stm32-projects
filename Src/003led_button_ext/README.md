# STM32L4 - Toggle LED with Button (PA4, PB2)

### 🛠 Description

This bare-metal embedded project demonstrates the use of **custom GPIO drivers** on the STM32L475VG microcontroller to toggle an LED connected to **PA4** when a button on **PB2** is pressed. No HAL or CubeMX used — all hardware control is done through register-level access.

---

### 🧰 Technologies Used

- **Microcontroller**: STM32L475VG
- **Language**: C (bare-metal)
- **IDE**: STM32CubeIDE
- **Peripherals**:
  - LED on PA4 (configured as output)
  - Button on PB2 (configured as input, active-high)
- **Drivers**: Custom GPIO driver
- **Debugger**: ST-Link V2

---

### ⚙️ How It Works

- **PA4** is initialized as a digital output pin to drive an LED.
- **PB2** is configured as an input without pull-up/down.
- When PB2 is **high** (logic level 1), the LED toggles.
- A simple software delay is used for debouncing.

---

### 🔌 Pinout

| Pin  | Function    |
|------|-------------|
| PA4  | LED Output  |
| PB2  | Button Input (active high) |

> Ensure PB2 is pulled high when pressed, either externally or by internal hardware.

---

### ▶️ Build & Run

1. Open the project in **STM32CubeIDE**.
2. Connect your STM32L475 board via **ST-Link**.
3. Build and flash the firmware.
4. Press the button connected to PB2 → LED on PA4 toggles.

---

### 📸 Demo

> *(Insert a photo or video showing the LED toggle)*

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

### 📌 Author

Made with ❤️ by [@jpgrismeyer](https://github.com/jpgrismeyer)
