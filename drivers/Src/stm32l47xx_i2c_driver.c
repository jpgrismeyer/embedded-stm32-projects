/*
 * stm32l47xx_i2c_driver.c
 *
 *  Created on: May 24, 2025
 *      Author: admin
 */


/*
 * stm32l475xx_i2c_driver.c
 *
 *  Created on: May 2025
 *      Author: Juan Pablo Grismeyer
 */

/*
 * stm32l475xx_i2c_driver.c
 *
 *  Created on: May 2025
 *      Author: Juan Pablo Grismeyer
 */

#include "stm32l47xx_i2c_driver.h"
#include"stm32l47xx_hts221.h"

void I2C_PeriClockControl(I2C_RegDef_t *pI2Cx, uint8_t EnorDi)
{
    if (EnorDi == ENABLE)
    {
        if (pI2Cx == I2C1) I2C1_PCLK_EN();
        else if (pI2Cx == I2C2) I2C2_PCLK_EN();
        else if (pI2Cx == I2C3) I2C3_PCLK_EN();
    }
}

void I2C_Init(I2C_Handle_t *pI2CHandle)
{

	    // Paso 1: Habilitar el reloj del periférico
	    I2C_PeriClockControl(pI2CHandle->pI2Cx, ENABLE);

	    // Paso 2: Deshabilitar el periférico I2C
	    pI2CHandle->pI2Cx->CR1 &= ~(1 << I2C_CR1_PE);

	    // Paso 3: Configurar filtros
	    pI2CHandle->pI2Cx->CR1 &= ~(1 << I2C_CR1_ANFOFF);        // ANFOFF = 0 (filtro analógico activado)
	    pI2CHandle->pI2Cx->CR1 &= ~(0xF << I2C_CR1_DNF);       // DNF[3:0] = 0000 (filtro digital desactivado)

	    // Paso 4: Configurar TIMINGR para 100kHz con reloj de 16 MHz
	    pI2CHandle->pI2Cx->TIMINGR = 0x00303D5B;

	    // Paso 5: Clock stretching permitido
	    pI2CHandle->pI2Cx->CR1 &= ~(1 << I2C_CR1_NOSTRETCH);        // NOSTRETCH = 0


	    // Paso 6: Habilitar el periférico
	    pI2CHandle->pI2Cx->CR1 |= (1 << 0);          // PE = 1


	}


void I2C_MasterSendData(I2C_RegDef_t *pI2Cx, uint8_t *pTxBuffer, uint32_t Len, uint8_t SlaveAddr, uint8_t Sr)
{

	// 1. Asegurarse que el peripheral esté listo (esperar que no esté ocupado)
	    while (pI2Cx->ISR & (1<< I2C_ISR_BUSY ));
	    GPIOB->ODR |= (1 << 14);
	    // 2. Limpiar el registro CR2 antes de configurar
	    pI2Cx->CR2 &= ~(0x3FF | (1 << 10) | (1 << 11) | (1 << 12) | (0xFF << 16) | (1 << 25) | (1 << 13));

	    // 3. Configurar dirección del esclavo, dirección de escritura, tamaño, AUTOEND, START
	    uint32_t tmpreg = 0;
	    tmpreg |= (SlaveAddr << I2C_CR2_SADD);     // SADD[9:0]
	    tmpreg |= (0 << I2C_CR2_RD_WRN);            // RD_WRN = 0 → write
	    tmpreg |= (0 << I2C_CR2_ADD10);            // ADD10 = 0 → 7-bit
	    tmpreg |= (0 << I2C_CR2_HEAD10R);            // HEAD10R = 0
	    tmpreg |= (Len << I2C_CR2_NBYTES);          // NBYTES
	    tmpreg |= (1 << I2C_CR2_AUTOEND);            // AUTOEND = 1
	    tmpreg |= (1 << I2C_CR2_START);            // START = 1

	    pI2Cx->CR2 |= tmpreg;

	    // 4. Enviar los datos
	    for (uint32_t i = 0; i < Len; i++)
	    {
	        // Esperar a que TXIS esté seteado
	        while (!(pI2Cx->ISR & I2C_ISR_TXIS));

	        // Cargar el byte al registro de datos
	        pI2Cx->TXDR = pTxBuffer[i];
	    }

	    // 5. Esperar a que se complete la transferencia (TC o STOPF)
	    while (!(pI2Cx->ISR & (1<<I2C_ISR_STOPF )));

	    // 6. Limpiar el flag STOPF escribiendo 1 en el bit correspondiente
	    pI2Cx->ICR |= (1<< 5);
	}



void I2C_MasterReceiveData(I2C_RegDef_t *pI2Cx, uint8_t *pRxBuffer, uint32_t Len, uint8_t SlaveAddr, uint8_t Sr)
{
	 // 1. Esperar si el periférico está ocupado
	    while (pI2Cx->ISR & I2C_ISR_BUSY);

	    // 2. Limpiar CR2
	    pI2Cx->CR2 &= ~(0x3FF | (1 << 10) | (1 << 11) | (1 << 12) | (0xFF << 16) | (1 << 25) | (1 << 13));

	    // 3. Configurar nueva transferencia: dirección, modo lectura, número de bytes, AUTOEND, START
	    uint32_t tmpreg = 0;
	    tmpreg |= (SlaveAddr << I2C_CR2_SADD);     // SADD[9:0]
	    tmpreg |= (1 << I2C_CR2_RD_WRN);            // RD_WRN = 1 → lectura
	    tmpreg |= (0 << I2C_CR2_ADD10);            // ADD10 = 0 (7-bit)
	    tmpreg |= (0 << I2C_CR2_HEAD10R);            // HEAD10R = 0
	    tmpreg |= (Len << I2C_CR2_NBYTES);          // NBYTES[7:0]
	    tmpreg |= (1 << I2C_CR2_AUTOEND);            // AUTOEND = 1 (genera STOP automáticamente)
	    tmpreg |= (1 << I2C_CR2_START);            // START = 1

	    pI2Cx->CR2 |= tmpreg;

	    // 4. Leer los datos entrantes
	    for (uint32_t i = 0; i < Len; i++)
	    {
	        // Esperar a que RXNE esté seteado (data disponible)
	        while (!(pI2Cx->ISR & (1<<I2C_ISR_RXNE)));

	        // Leer byte recibido
	        pRxBuffer[i] = pI2Cx->RXDR;
	    }

	    // 5. Esperar a que se genere el STOP (transferencia finalizada)
	    while (!(pI2Cx->ISR & I2C_ISR_STOPF));

	    // 6. Limpiar el flag STOPF
	    pI2Cx->ICR |= (1<< 5);
}






