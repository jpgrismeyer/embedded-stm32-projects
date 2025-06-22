# STM32L4 - SPI Master Transmission ("Hello World")

### 🛠 Description

This project demonstrates how to configure the **SPI1 peripheral** on the STM32L475VG microcontroller in **master mode** using custom drivers. It transmits the string `"Hello world"` via SPI to a slave device. The implementation is done without HAL, using low-level access and custom abstraction layers.

---

### 🧰 Technologies Used

- **Microcontroller**: STM32L475VG
- **Language**: C (bare-metal)
- **IDE**: STM32CubeIDE
- **Drivers**: Custom SPI + GPIO
- **Debugger**: ST-Link V2

---

### ⚙️ How It Works

- SPI1 is configured in **Full-Duplex Master mode**, 8-bit data frame, CPOL = 0, CPHA = 0.
- GPIOs PA4–PA7 are configured in **Alternate Function 5** for SPI:
  - PA5 → SCLK
  - PA6 → MISO
  - PA7 → MOSI
  - PA4 → NSS (software-managed)
- The SPI peripheral sends `"Hello world"` once at startup, then disables the interface.

---

### 📡 Pin Mapping

| Pin  | Function |
|------|----------|
| PA4  | NSS      |
| PA5  | SCK      |
| PA6  | MISO     |
| PA7  | MOSI     |

> Make sure the slave device is ready and properly wired to receive the transmission.

---

### ▶️ Build & Run

1. Clone or open the project in **STM32CubeIDE**.
2. Flash to the STM32L4 target board.
3. Connect a logic analyzer or slave SPI device.
4. Observe SPI frames transmitting `"Hello world"`.

---

### 📁 File structure

/Core
└── Src
└── Inc
/Drivers
└── GPIO_Driver.c/.h
└── SPI_Driver.c/.h
main.c
README.md


---

### 📸 Demo

> *(Optional: add screenshot or logic analyzer output showing SPI frames)*

---

### 📌 Author

Created and maintained by [Juan Pablo Grismeyer](https://github.com/jpgrismeyer) – Embedded Systems Engineer
