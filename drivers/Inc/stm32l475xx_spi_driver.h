/*
 * stm32l475xx_spi.h
 *
 *  Created on: Mar 17, 2025
 *      Author: admin
 */

#ifndef INC_STM32L475XX_SPI_DRIVER_H_
#define INC_STM32L475XX_SPI_DRIVER_H_

#include"stm32l47xx.h"

/*
 * Configuration structure for SPIx peripheral
 */


typedef struct
{
	uint8_t SPI_DeviceMode;
	uint8_t SPI_BusConfig;				/*<>*/
	uint8_t SPI_SclkSpeed;				/*<>*/
	uint8_t SPI_DFF;
	uint8_t SPI_CPOL;
	uint8_t SPI_CPHA;
	uint8_t SPI_SSM;
}SPI_Config_t;

/*
 * This is the handle structure for a SPIx peripheral
 */

typedef struct
{
	SPI_RegDef_t *pSPIx;		/*Holds the base address of SPIx (x: 0,1,2) peripheral*/
	SPI_Config_t SPIConfig;
}SPI_Handle_t;

/*
 * @SPI_DeviceMode
 */
#define SPI_DEVICE_MODE_MASTER 	1
#define SPI_DEVICE_MODE_SLAVE 	0

/*
 * @SPI_BusConfig
 */
#define SPI_BUS_CONFIG_FD 					1
#define SPI_BUS_CONFIG_HD 					2
#define SPI_BUS_CONFIG_SIMPLEX_TXONLY 		3
#define SPI_BUS_CONFIG_SIMPLEX_RXONLY 		4

/*
 * @SPI_SclkSpeed
 * The SPI sclck speed is the result of the bus speed divided by a preescaler
 */

#define SPI_SCLK_SPEED_DIV2 				0
#define SPI_SCLK_SPEED_DIV4 				1
#define SPI_SCLK_SPEED_DIV8 				2
#define SPI_SCLK_SPEED_DIV16 				3
#define SPI_SCLK_SPEED_DIV32 				4
#define SPI_SCLK_SPEED_DIV64 				5
#define SPI_SCLK_SPEED_DIV128 				6
#define SPI_SCLK_SPEED_DIV256 				7

/*
 * @SPI_DFF
 */

#define SPI_DFF_8BITS 						0
#define SPI_DFF_16BITS 						1

/*
 * @SPI_CPOL
 */

#define SPI_CPOL_LOW 						0
#define SPI_CPOL_HIGH 						1

/*
 * @SPI_CPHA
 */

#define SPI_CPHA_LOW 						0
#define SPI_CPHA_HIGH 						1

/*
 * @SPI_SSM
 */

#define SPI_SSM_DI 						0
#define SPI_SSM_EN 						1

/*
 * SPI related status flags definitions (MASKING DETAILS FOR SR REGISTER)
 */
#define SPI_TXE_FLAG		(1 << SPI_SR_TXE)
#define SPI_RXNE_FLAG		(1 << SPI_SR_RXNE)
#define SPI_BUSY_FLAG		(1 << SPI_SR_BSY)
/*Peripheral Clock setup
 *
 */

void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);

/*
 *Init and De-init
 */
void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_RegDef_t *pSPIx);

/*
 *Data Send and Receive
 */

void SPI_SendData (SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len);
void SPI_ReceiveData (SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len);

/*
 *IRQ Configuration and ISR handling
 */
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void SPI_IRQHandling(SPI_Handle_t *pHandle);

/*
*	Other Peripheral Control APIs
*/

void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t EnOrDi);
void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t EnOrDi);
void SPI_SSMConfig(SPI_RegDef_t *pSPIx, uint8_t EnOrDi);


#endif /* INC_STM32L475XX_SPI_DRIVER_H_ */
