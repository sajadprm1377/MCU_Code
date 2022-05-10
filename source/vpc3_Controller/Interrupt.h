/*
 * Interrupt.h
 *
 *  Created on: Oct 21, 2021
 *      Author: PC Khayam
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "vpc3_drive.h"
#define X_INT_PIN 2U                   /*!<@brief PORT pin number */

typedef enum{
	S_Disable				 = 0b0000000000000000,
	S_MAC_Reset_ClockSync	 = 0b0000000000000001,
	S_Go_Leave_DATA_EXCH     = 0b0000000000000010,
	S_BaudRate_detect        = 0b0000000000000100,
	S_WD_DP_CONTROL_Timeout  = 0b0000000000001000,
	S_UserTimerClock         = 0b0000000000010000,
	S_DXB_Link_Error         = 0b0000000000100000,
	S_New_Ext_Prm_Data       = 0b0000000001000000,
	S_DXB_Out                = 0b0000000010000000,
	S_New_GC_Command         = 0b0000000100000000,
	S_New_SSA_Data           = 0b0000001000000000,
	S_New_Cfg_Data           = 0b0000010000000000,
	S_New_Prm_Data           = 0b0000100000000000,
	S_Diag_Buffer_Changed    = 0b0001000000000000,
	S_DX_Out                 = 0b0010000000000000,
	S_Poll_End_Ind           = 0b0100000000000000,
	S_FDL_Ind                = 0b1000000000000000
}Set_Interrupte;


typedef enum{
	C_Disable				 = 0b1111111111111111,
	C_MAC_Reset_ClockSync	 = 0b1111111111111110,
	C_Go_Leave_DATA_EXCH     = 0b1111111111111101,
	C_BaudRate_detect        = 0b1111111111111011,
	C_WD_DP_CONTROL_Timeout  = 0b1111111111110111,
	C_UserTimerClock         = 0b1111111111101111,
	C_DXB_Link_Error         = 0b1111111111011111,
	C_New_Ext_Prm_Data       = 0b1111111110111111,
	C_DXB_Out                = 0b1111111101111111,
	C_New_GC_Command         = 0b1111111011111111,
	C_New_SSA_Data           = 0b1111110111111111,
	C_New_Cfg_Data           = 0b1111101111111111,
	C_New_Prm_Data           = 0b1111011111111111,
	C_Diag_Buffer_Changed    = 0b1110111111111111,
	C_DX_Out                 = 0b1101111111111111,
	C_Poll_End_Ind           = 0b1011111111111111,
	C_FDL_Ind                = 0b0111111111111111,
	C_Enable_All			 = 0b1111111111111111
}Clear_Mask;


typedef union {
    struct{
    	uint16_t MAC_Reset_ClockSync 	: 1;
    	uint16_t Go_Leave_DATA_EXCH  	: 1;
    	uint16_t BaudRate_detect		: 1;
    	uint16_t WD_DP_CONTROL_Timeout	: 1;
    	uint16_t UserTimerClock			: 1;
    	uint16_t DXB_Link_Error 		: 1;
    	uint16_t New_Ext_Prm_Data 		: 1;
    	uint16_t DXB_Out 				: 1;
    	uint16_t New_GC_Command 		: 1;
    	uint16_t New_SSA_Data 			: 1;
		uint16_t New_Cfg_Data 			: 1;
		uint16_t New_Prm_Data 			: 1;
		uint16_t Diag_Buffer_Changed    : 1;
		uint16_t DX_Out  				: 1;
		uint16_t Poll_End_Ind			: 1;
		uint16_t FDL_Ind 				: 1;
    }configBit;
    uint16_t Packet_16Bit;
	uint8_t Byte[2];
}Int_Req_Reg;




void Ack_Interrupte(Set_Interrupte);
void Enable_Interrupte(Clear_Mask);   // Mask Disable



//void Config_Mask_Reg(Int_Req_Reg);
void All_Interrupt_Disable(void);

#endif /* INTERRUPT_H_ */




