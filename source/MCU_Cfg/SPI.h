/*
 * SPI.h
 *
 *  Created on: Oct 18, 2021
 *      Author: PC Khayam
 */

#ifndef SPI_H_
#define SPI_H_



#endif /* SPI_H_ */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "peripherals.h"
#include "pin_mux.h"
#include "fsl_gpio.h"
#include "MKV31F12810.h"
#include "board.h"
#include "fsl_port.h"
#include "clock_config.h"
#include "fsl_dspi.h"

void SPI_Config(SPI_Type* SPIx);
void PIN_Config(void);
void SPI_Receive(uint8_t* rx_Buffer, uint8_t Length);
void SPI_Transfer_Recieve(uint8_t* tx_Buffer, uint8_t* rx_Buffer, uint8_t Length);
void SPI_Transmit(uint8_t* tx_Buffer, uint8_t Length);


#ifdef __cplusplus
}
#endif

