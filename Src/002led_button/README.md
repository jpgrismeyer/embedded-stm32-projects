# STM32L4 - GPIO Toggle with Button Press

### 🛠 Description

This project demonstrates how to use **custom GPIO drivers** on the STM32L475VG microcontroller to toggle an LED when a button is pressed. No HAL or CubeMX was used — only low-level register access through your own abstraction layer.

### 🧰 Technologies Used

- **Microcontroller**: STM32L475VG
- **Language**: C (bare-metal)
- **IDE**: STM32CubeIDE
- **Peripherals**:
  - LED: PB14 (output)
  - Button: PC13 (input, active-low)
- **Drivers**: Custom GPIO driver (register-based)
- **Debugger**: ST-Link V2

---

### ⚙️ How It Works

- The program configures **PB14 as output** for driving an LED.
- **PC13 is configured as input** (no pull-up/down) to read a button press.
- On detecting a **falling edge (button press)**, the LED toggles.
- A simple software `delay()` is used for debouncing.

---

### 🔌 Pinout

| Pin  | Function    |
|------|-------------|
| PB14 | LED Output  |
| PC13 | Button Input (active low) |

> Note: On Nucleo boards, PC13 is often connected to the blue user button.

---

### ▶️ Build & Run

1. Open the project in **STM32CubeIDE**.
2. Connect your STM32L475VG board via **ST-Link**.
3. Build the project and flash it to the target.
4. Press the button → the LED on PB14 will toggle.

---

### 📸 Demo

> *(Insert a photo or short video here if available)*

---

### 📁 File structure

