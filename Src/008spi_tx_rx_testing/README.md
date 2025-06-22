# STM32L4 - SPI Full-Duplex TX/RX Test

### 🛠 Description

This project demonstrates **full-duplex SPI communication** on the STM32L475VG using custom drivers. It transmits the string `"Hello"` byte by byte and simultaneously receives data back (loopback or slave response). The transmission is validated, and an LED indicates success or failure.

---

### 🧰 Technologies Used

- **Microcontroller**: STM32L475VG
- **Language**: C (bare-metal)
- **IDE**: STM32CubeIDE
- **Drivers**: Custom SPI, GPIO, SysTick
- **Debugger**: ST-Link V2

---

### ⚙️ How It Works

- SPI1 is configured as **Master**, Full-Duplex, 8-bit frame, CPOL/CPHA = 0.
- SPI GPIOs (PA4–PA7) are set in **Alternate Function 5**.
- A test string `"Hello"` is sent and received.
- If TX and RX buffers match → LED on PB14 blinks.
- If mismatch → LED stays ON (error indication).

---

### 📡 SPI Pin Mapping

| Pin  | Function |
|------|----------|
| PA4  | NSS      |
| PA5  | SCK      |
| PA6  | MISO     |
| PA7  | MOSI     |

> This demo can run in **loopback mode** (connect MOSI to MISO), or with a properly configured slave device.

---

### 🔌 LED Indicator

| Pin   | Function         |
|-------|------------------|
| PB14  | Success/Error LED |

- **Blinks** if SPI loopback is successful  
- **Stays ON** if RX != TX

---

### ▶️ Build & Run

1. Connect MOSI to MISO for loopback test.
2. Open project in **STM32CubeIDE**.
3. Flash it to STM32L4 board.
4. Observe PB14:
   - Blinking = TX == RX
   - Solid ON = error

---

### 📁 File structure

/Core
└── Src
└── Inc
/Drivers
└── GPIO_Driver.c/.h
└── SPI_Driver.c/.h
└── SysTick_Driver.c/.h
main.c
README.md


---

### 📸 Demo

> *(Optional: Add a photo or video showing LED behavior + logic analyzer capture)*

---

### 📌 Author

Created and maintained by [Juan Pablo Grismeyer](https://github.com/jpgrismeyer) – Embedded Systems Engineer
