/*
 * Interrupt.c
 *
 *  Created on: Oct 21, 2021
 *      Author: PC Khayam
 */

#include "Interrupt.h"

static uint16_t last_Mask_Reg  = C_Disable;

void All_Interrupt_Disable(void){
	uint8_t mask[2] = {0xff, 0xff};
	vpc3_Write_Array(Int_Mask_Reg_L, mask, 2);
}

void Ack_Interrupte(Set_Interrupte interrupte_vector){
	uint16_t address;
	uint8_t data;
	if(interrupte_vector <= S_DXB_Out ){
		address = Int_Ack_Reg_L;
		data = (uint8_t)interrupte_vector;
	}
	else{
		address = Int_Ack_Reg_H;
		data = interrupte_vector>>8;
	}

	vpc3_Write_Byte(address, data);
}

void Enable_Interrupte(Clear_Mask interrupte_vector){   // Mask Disable
	Int_Req_Reg IMR;
	IMR.Packet_16Bit = interrupte_vector & last_Mask_Reg;
	vpc3_Write_Array(Int_Mask_Reg_L, IMR.Byte, 2);
	last_Mask_Reg = IMR.Packet_16Bit;


}

