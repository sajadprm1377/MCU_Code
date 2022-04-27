/*
 * Status.c
 *
 *  Created on: Oct 18, 2021
 *      Author: PC Khayam
 */

#include "Status.h"


uint16_t Get_interrupte_Reg(void){
	uint8_t Byte[2];
	uint16_t IR;
	Byte[0] = vpc3_Read_Byte(Int_Reg_L);
	Byte[1] = vpc3_Read_Byte(Int_Reg_H);
	IR = Byte[0] | (Byte[1] <<8);
	return IR;
}
uint16_t Get_interrupte_Req_Reg(void){
	uint8_t Byte[2];
	uint16_t IRR;
	Byte[0] = vpc3_Read_Byte(Int_Reg_L);
	Byte[1] = vpc3_Read_Byte(Int_Reg_H);
	IRR = Byte[0] | (Byte[1] <<8);
	return IRR;

}

uint8_t Get_Slave_Address(void){
	uint8_t addr = vpc3_Read_Byte(R_TS_Adr);
	return addr;
}

Baudrate_Val Get_Baudrate(void){
	uint8_t temp = 0;
	temp = vpc3_Read_Byte(Status_Reg_H);
	return temp & 0x0F;
}

uint8_t Get_vpc3_Release(void){
	uint8_t temp = 0;
	temp = vpc3_Read_Byte(Status_Reg_H);
	return ((temp & 0xF0)>> 4 );
}
DP_State Get_DP_state(void){
	uint8_t temp = 0;
	temp = vpc3_Read_Byte(Status_Reg_L);
	return ((temp & 0b00110000) >> 4);

}
Diag_Flag Get_Diag_flag(void){
	uint8_t temp = 0;
	temp = vpc3_Read_Byte(Status_Reg_L);
	return ((temp & 00000100) >> 2);
}

Offline_PassiveIdel Passive_Idle_State(void){
	uint8_t temp = 0;
	temp = vpc3_Read_Byte(Status_Reg_L);
	return (temp & 0b00000001);
}

WD_State Get_WD_state(void){
	uint8_t temp = 0;
	temp = vpc3_Read_Byte(Status_Reg_L);
	return ((temp & 0b11000000) >> 6);
}

uint16_t Get_Ident_Number(void){
	Ident_Number ident_number;
	vpc3_Read_Array(R_Ident_Low, ident_number.Byte, 2);
	return ident_number.Word;
}


