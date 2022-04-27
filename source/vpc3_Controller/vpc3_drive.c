/*
 * vpc3_drive.c
 *
 *  Created on: Oct 18, 2021
 *      Author: PC Khayam
 */


/****************************************************
 *  vpc3_control.c
 *  Created on: 18-Oct-2021 1:15:18 AM
 *  Implementation of the Class vpc3_control
 *  Original author: PC Khayam
 ****************************************************/

#include "vpc3_drive.h"






void vpc3_Read_Array(uint16_t Address, uint8_t* Data, uint8_t Length)
{
	uint8_t AddrLow = 0x00FF & Address;
	uint8_t AddrHigh = (uint8_t)(Address >> 8);
	uint8_t TxBuffer[Length + 3];
	uint8_t RxBuffer[Length + 3];
	*TxBuffer = READ_ARRAY;
	*(TxBuffer + 1) = AddrHigh;
	*(TxBuffer + 2) = AddrLow;
	SPI_Transfer_Recieve(TxBuffer, RxBuffer, Length+3);
	for(int i = 0; i < Length; i++)
		*(Data + i) = RxBuffer[3 + i];

}

uint8_t vpc3_Read_Byte(uint16_t Address)
{
	uint8_t AddrLow = 0x00FF & Address;
	uint8_t AddrHigh = (uint8_t)(Address >> 8);
	uint8_t TxBuffer[3];
	uint8_t RxBuffer[4];
	*TxBuffer = READ_BYTE;
	*(TxBuffer + 1) = AddrHigh;
	*(TxBuffer + 2) = AddrLow;

	SPI_Transfer_Recieve(TxBuffer, RxBuffer, 4);
	return RxBuffer[3];
}



void vpc3_Write_Array(uint16_t Address, uint8_t* Data, uint8_t Length)
{
	uint8_t AddrLow = 0x00FF & Address;
	uint8_t AddrHigh = (uint8_t)(Address >> 8);
	uint8_t TxBuffer[Length+3];
	*TxBuffer = WRITE_ARRAY;
	*(TxBuffer + 1) = AddrHigh;
	*(TxBuffer + 2) = AddrLow;
	for(int i = 0; i < (Length); i++)
		*(TxBuffer + i + 3) = *(Data + i);

	SPI_Transmit(TxBuffer, Length + 3);

}

void vpc3_Write_Byte(uint16_t Address, uint8_t Data)
{
	uint8_t AddrLow = 0x00FF & Address;
	uint8_t AddrHigh = (uint8_t)(Address >> 8);
	uint8_t TxBuffer[4];
	*TxBuffer = WRITE_BYTE;
	*(TxBuffer + 1) = AddrHigh;
	*(TxBuffer + 2) = AddrLow;
	*(TxBuffer + 3) = Data;
	SPI_Transmit(TxBuffer, 4);

}

void vpc3_Reset(void){
	GPIO_Set(BOARD_INITPINS_RESET_GPIO, 1<<BOARD_INITPINS_RESET_PIN);
	for(int x = 0; x<100; x++);
	GPIO_PortClear(BOARD_INITPINS_RESET_GPIO, 1<<BOARD_INITPINS_RESET_PIN);
}
