# STM32L4 - HTS221 Sensor Reading via I2C + UART Output

### 🛠 Description

This project reads raw temperature and humidity data from the **HTS221 environmental sensor** over **I2C2**, and sends the values over **USART2** to a terminal. It uses **custom drivers** for I2C, USART, GPIO and the HTS221 sensor.

A status LED indicates if valid data was received.

---

### 🧰 Technologies Used

- **Microcontroller**: STM32L475VG
- **Language**: C (bare-metal)
- **IDE**: STM32CubeIDE
- **Interfaces**: I2C2 (PB10/PB11), USART2 (PA2/PA3)
- **Drivers**: Custom GPIO, I2C, USART, HTS221, LED
- **Debugger**: ST-Link V2 or semihosting (optional)

---

### ⚙️ How It Works

1. Initializes I2C2 and communicates with **HTS221** sensor.
2. Sends a `Power On` command to activate the sensor.
3. Periodically reads:
   - Raw temperature value
   - Raw humidity value
4. If both values are non-zero:
   - LED turns ON
   - Data is sent via **USART2** as formatted string
5. If any value is zero:
   - LED stays OFF (sensor not detected or not responding)

---

### 🔌 Pin Mapping

| Pin   | Function         |
|--------|------------------|
| **PB10** | I2C2_SCL (HTS221) |
| **PB11** | I2C2_SDA (HTS221) |
| **PA2**  | USART2_TX         |
| **PA3**  | USART2_RX (not used) |
| **PB14** | Status LED        |

---

### 🧪 Example UART Output

Temp raw: 1243, Hum raw: 653
Temp raw: 1250, Hum raw: 657
…


> Use **PuTTY**, **TeraTerm**, or STM32CubeIDE’s serial monitor at **115200-8-N-1**.

---

### ▶️ Build & Run

1. Flash the project to your STM32L475 board.
2. Open a terminal (115200 baud) on your PC.
3. Observe raw temperature and humidity readings printed periodically.
4. LED ON = sensor OK, LED OFF = no data.

---

### 📁 File structure

/Core
└── Src
└── Inc
/Drivers
└── GPIO_Driver.c/.h
└── I2C_Driver.c/.h
└── USART_Driver.c/.h
└── HTS221.c/.h
└── led.c/.h
main.c
README.md


---

### 📝 Future Improvements

- Convert raw data to °C and %RH using calibration registers
- Display values on LCD or OLED
- Add error handling or retry logic

---

### 📸 Demo

> *(Optional: insert serial terminal screenshot + board photo)*

---

### 📌 Author

Created and maintained by [Juan Pablo Grismeyer](https://github.com/jpgrismeyer) – Embedded Systems Engineer
