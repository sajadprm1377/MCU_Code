/*
 * Slave_Diag.c
 *
 *  Created on: Jan 31, 2022
 *      Author: Sajjad Prm
 */

#include "Slave_Diag.h"



void Diag_Buffer_Handle(void){
	uint8_t Diag_SM;
	uint8_t Diag_Buf1_Status;
	uint8_t Diag_Buf2_Status;
	uint16_t add = 0;
	Diag_SM = vpc3_Read_Byte(Diag_Buffer_SM);
	Diag_Buf1_Status = Diag_SM & 3;
	Diag_Buf2_Status = (Diag_SM & 12)>>2;
	uint8_t add_diag1;
	uint8_t add_diag2;
	uint8_t diag_status;

	uint8_t buffer[6];
	if(Diag_Buf1_Status == 1){
			add_diag1 = vpc3_Read_Byte(R_Diag_Buf_Ptr1);
			add = add_diag1 <<3;
			vpc3_Read_Array(add, buffer, 6);
			Diag_Buffer_Monitor(buffer);
			vpc3_Write_Byte(add, 0);
	}
	if(Diag_Buf2_Status == 1){
		add_diag2 = vpc3_Read_Byte(R_Diag_Buf_Ptr2);
		add = add_diag2 << 3;
		vpc3_Read_Array(add, buffer, 6);
		Diag_Buffer_Monitor(buffer);
		vpc3_Write_Byte(add, 0);
	}


		diag_status = vpc3_Read_Byte(New_Diag_Buffer_Cmd);
}
