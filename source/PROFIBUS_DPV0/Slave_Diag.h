/*
 * Slave_Diag.h
 *
 *  Created on: Jan 31, 2022
 *      Author: Sajjad Prm
 */

#ifndef PROFIBUS_DPV0_SLAVE_DIAG_H_
#define PROFIBUS_DPV0_SLAVE_DIAG_H_
#include "vpc3_Controller/Status.h"
#include "vpc3_Controller/RAM_Config.h"
#include "vpc3_Controller/Interrupt.h"
/*
void Chkek_Diag_Buffer_self(void){
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
	if(Diag_Buf1_Status == 1){
//		PRINTF("\n________________DIAG1____________________\n");
		add_diag1 = vpc3_Read_Byte(R_Diag_Buf_Ptr1);
//		PRINTF("\nAdd diag1 : %d\n", add_diag1);
		add = add_diag1 <<3;
		vpc3_Write_Byte(add, 0);
	}
	if(Diag_Buf2_Status == 1){
//		PRINTF("\n________________DIAG2____________________\n");
		add_diag2 = vpc3_Read_Byte(R_Diag_Buf_Ptr2);
//		PRINTF("\nAdd diag2 : %d\n", add_diag2);
		add = add_diag2 << 3;
		vpc3_Write_Byte(add, 0);
	}
	diag_status = vpc3_Read_Byte(New_Diag_Buffer_Cmd);
//	PRINTF("\nNew_Diag_Buffer_Cmd = %d\n", diag_status);
}
*/

#endif /* PROFIBUS_DPV0_SLAVE_DIAG_H_ */
