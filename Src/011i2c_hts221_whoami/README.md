# STM32L4 - HTS221 WHO_AM_I Read (I2C Sensor ID Check)

### 🛠 Description

This project performs a **basic identification check** by reading the `WHO_AM_I` register (0x0F) of the **HTS221** humidity and temperature sensor over **I2C2**. If the returned ID is correct (`0xBC`), an LED on PB14 is turned ON.

---

### 🧰 Technologies Used

- **Microcontroller**: STM32L475VG
- **Language**: C (bare-metal)
- **IDE**: STM32CubeIDE
- **Drivers**: Custom I2C + GPIO + SysTick
- **Debugger**: ST-Link V2

---

### ⚙️ How It Works

1. Initializes I2C2 (PB10 = SCL, PB11 = SDA) to communicate with the HTS221.
2. Sends register address `0x0F` to the slave (`0x5F`).
3. Reads one byte from the sensor.
4. If the value is `0xBC`, the **LED on PB14 is turned ON**.

---

### 📡 Pin Mapping

| Pin   | Function           |
|--------|--------------------|
| PB10   | I2C2_SCL (HTS221)  |
| PB11   | I2C2_SDA (HTS221)  |
| PB14   | Status LED         |

---

### 🧪 Expected Behavior

- If the **HTS221 is present and responds correctly**, the LED lights up.
- Otherwise, the LED remains OFF (and no loop retry is attempted).

---

### ▶️ Build & Run

1. Connect the HTS221 sensor to I2C2 on PB10/PB11.
2. Flash the firmware to the STM32L475 board.
3. If the sensor is detected (ID = `0xBC`), LED on PB14 turns ON.

---

### 📁 File structure

/Core
└── Src
└── Inc
/Drivers
└── GPIO_Driver.c/.h
└── I2C_Driver.c/.h
└── SysTick_Driver.c/.h
main.c
README.md


---

### 📝 Notes

- This is a minimal test project to verify **low-level I2C communication** with the HTS221.
- Can be extended to read calibrated temperature/humidity data or integrate into larger systems.

---

### 📸 Demo

> *(Optional: photo of LED lit + logic analyzer I2C trace)*

---

### 📌 Author

Created and maintained by [Juan Pablo Grismeyer](https://github.com/jpgrismeyer) – Embedded Systems Engineer
