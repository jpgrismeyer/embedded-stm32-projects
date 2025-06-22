# STM32L4 - I2C Master Send/Receive Test

### 🛠 Description

This project tests I2C communication using a **custom I2C driver** on the STM32L475VG. It sends a byte (`0xAA`) to a slave at address `0x50`, then reads a byte in return. Based on the received value, it uses an LED to indicate success or failure.

---

### 🧰 Technologies Used

- **Microcontroller**: STM32L475VG
- **Language**: C (bare-metal)
- **IDE**: STM32CubeIDE
- **Drivers**: Custom I2C + GPIO
- **Debugger**: ST-Link V2

---

### ⚙️ How It Works

1. GPIO PB6 and PB7 are configured in **Alternate Function 4** for I2C (SCL/SDA).
2. A single byte (`0xAA`) is transmitted to slave address `0x50`.
3. The master then reads back one byte.
4. If the received byte is different from `0x00`, the LED on PB14 **blinks**.
5. If it receives `0x00`, the LED is turned **on and held** (failure indication).

---

### 📡 I2C Pin Mapping

| Pin  | Function |
|------|----------|
| PB6  | I2C1_SCL |
| PB7  | I2C1_SDA |

> Pull-ups are enabled via GPIO configuration. External pull-ups (4.7kΩ typical) may be needed depending on your setup.

---

### 🔌 LED Indicator

| Pin   | Function            |
|-------|---------------------|
| PB14  | Blink = success / ON = fail |

---

### ▶️ Build & Run

1. Connect a test device to I2C1 or loop back using a mock/slave emulator.
2. Open and build the project in **STM32CubeIDE**.
3. Flash to your STM32L4 board.
4. Observe LED behavior:
   - **Blinking** → Received valid response.
   - **Stuck ON** → No or invalid response.

---

### 📁 File structure

/Core
└── Src
└── Inc
/Drivers
└── GPIO_Driver.c/.h
└── I2C_Driver.c/.h
main.c
README.md


---

### 📸 Demo

> *(Optional: Add video or oscilloscope capture showing I2C activity)*

---

### 📌 Author

Created and maintained by [Juan Pablo Grismeyer](https://github.com/jpgrismeyer) – Embedded Systems Engineer
