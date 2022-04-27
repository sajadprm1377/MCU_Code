/*
 * SPI.c
 *
 *  Created on: Oct 18, 2021
 *      Author: PC Khayam
 */
#include "SPI.h"
#include "Port.h"
static SPI_Type* SPI_x;

void SPI_Config(SPI_Type* SPIx){
	PIN_Config();
	SPI_x = SPIx;
	const dspi_master_config_t SPI1_config = {
	  .whichCtar = kDSPI_Ctar0,
	  .ctarConfig = {
	    .baudRate = 6000000UL,
	    .bitsPerFrame = 8UL,
	    .cpol = kDSPI_ClockPolarityActiveHigh,
	    .cpha = kDSPI_ClockPhaseFirstEdge,
	    .direction = kDSPI_MsbFirst,
	    .pcsToSckDelayInNanoSec = 0UL,
	    .lastSckToPcsDelayInNanoSec = 0UL,
	    .betweenTransferDelayInNanoSec = 0UL
	  },
	  .whichPcs = kDSPI_Pcs0,
	  .pcsActiveHighOrLow = kDSPI_PcsActiveLow,
	  .enableContinuousSCK = false,
	  .enableRxFifoOverWrite = false,
	  .enableModifiedTimingFormat = false,
	  .samplePoint = kDSPI_SckToSin0Clock
	};

	DSPI_MasterInit(SPIx, &SPI1_config, SPI1_CLK_FREQ);
}



void SPI_Receive(uint8_t* rx_Buffer, uint8_t Length){
	dspi_transfer_t spi_cfg;
	spi_cfg.configFlags = kDSPI_MasterCtar0 | kDSPI_MasterPcs0 | kDSPI_MasterPcsContinuous;  // = 1U << 20;
	spi_cfg.dataSize = Length;
	spi_cfg.rxData = rx_Buffer;
	spi_cfg.txData = NULL;
	DSPI_MasterTransferBlocking(SPI_x, &spi_cfg);

}
void SPI_Transfer_Recieve(uint8_t* tx_Buffer, uint8_t* rx_Buffer, uint8_t Length){
	dspi_transfer_t spi_cfg;
	spi_cfg.configFlags = kDSPI_MasterCtar0 | kDSPI_MasterPcs0 | kDSPI_MasterPcsContinuous;  // = 1U << 20;
	spi_cfg.dataSize = Length;
	spi_cfg.rxData = rx_Buffer;
	spi_cfg.txData = tx_Buffer;
	DSPI_MasterTransferBlocking(SPI_x, &spi_cfg);

}
void SPI_Transmit(uint8_t* tx_Buffer, uint8_t Length){
	dspi_transfer_t spi_cfg;
	spi_cfg.configFlags = kDSPI_MasterCtar0 | kDSPI_MasterPcs0 | kDSPI_MasterPcsContinuous;  // = 1U << 20;
	spi_cfg.dataSize = Length;
	spi_cfg.rxData = NULL;
	spi_cfg.txData = tx_Buffer;
	DSPI_MasterTransferBlocking(SPI_x, &spi_cfg);

}
