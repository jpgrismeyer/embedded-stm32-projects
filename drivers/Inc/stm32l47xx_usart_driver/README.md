# STM32L4 USART Driver

## Overview

This is a custom, bare-metal USART driver written in C for the STM32L4 microcontroller family (tested on STM32L475VG). It provides basic functionality to configure and use the USART peripheral for sending and receiving data over serial communication.

## Supported Features

- Initialization of USART peripheral (baud rate, word length, stop bits, parity, mode)
- Transmit data (polling-based)
- Receive data (polling-based)
- Peripheral clock control
- Enable/disable peripheral
- Software configuration of NSS (if using synchronous mode)

## API Functions

### Configuration

Initialize
void USART_Init(USART_Handle_t *pUSARTHandle);             //Initializes the USART peripheral with the parameters set in pUSARTHandle.

Clock Control
void USART_PeriClockControl(USART_RegDef_t *pUSARTx, uint8_t EnorDi);	//Enables or disables the peripheral clock.

Transmit / Receive
void USART_SendData(USART_RegDef_t *pUSARTx, uint8_t *pTxBuffer, uint32_t Len);
void USART_ReceiveData(USART_RegDef_t *pUSARTx, uint8_t *pRxBuffer, uint32_t Len);	//Sends or receives a buffer of data using polling.

Peripheral Control
void USART_PeripheralControl(USART_RegDef_t *pUSARTx, uint8_t EnOrDi);			//Enable or disable the USART peripheral (SPE bit).

##Configuration Structure
typedef struct {
    uint32_t USART_Baud;
    uint8_t  USART_Mode;
    uint8_t  USART_NoOfStopBits;
    uint8_t  USART_WordLength;
    uint8_t  USART_ParityControl;
    uint8_t  USART_HWFlowControl;
} USART_Config_t;

##Handle Structure
typedef struct {
    USART_RegDef_t *pUSARTx;
    USART_Config_t USART_Config;
} USART_Handle_t;

Supported Baud Rates
You can configure standard baud rates like:

9600

19200

38400

57600

115200

via the macro USART_STD_BAUD_115200 and similar.

Dependencies
stm32l47xx.h: CMSIS device header for STM32L4 series.

Custom macros/constants for USART register manipulation.

Notes
This driver uses polling (blocking) mode. Future versions may include interrupt-based or DMA-based handling.

Make sure the USART peripheral clock is enabled before initialization.

License
This driver is for educational and non-commercial use only.
