/*
 * conf.h
 *
 *  Created on: Jan 23, 2022
 *      Author: Sajjad Prm
 */

#ifndef CONF_H_
#define CONF_H_
#include "PROFIBUS_DPV0/Chk_Cfg.h"
#include "PROFIBUS_DPV0/Set_Prm.h"
#include "PROFIBUS_DPV0/DATA_Exchange.h"


/****************************************************************************************************/
/*********		Hardware Config 		*********************************************************/
/****************************************************************************************************/
PORT_Type*  PORT_Interrupt = PORTD;
GPIO_Type*  GPIO_Interrupt = GPIOD;
uint32_t 	PIN_Interrupt  = X_INT_PIN;
SPI_Type* SPI_Base_Add = SPI1_PERIPHERAL;
/****************************************************************************************************/
/*********     vpc3 Config         ********************************************************/
/****************************************************************************************************/
uint8_t Slave_Address = 4;
RAM_Size RAM_size = _2kByte;
uint16_t Interrupt_Mask_Disable =  C_BaudRate_detect&
							       C_New_Prm_Data &
							       C_New_Cfg_Data &
							       C_DX_Out &
							       C_Go_Leave_DATA_EXCH &
							       C_WD_DP_CONTROL_Timeout&
							       C_Diag_Buffer_Changed;
/****************************************************************************************************/
/***************		Parameterization Config		******************************************/
/****************************************************************************************************/
uint16_t Ident_Num 		= 0xabcd;
uint8_t Min_Tsdr 			= 11;
uint16_t R_User_WD_Value 		= 0xefff;
uint8_t	Seg_Base_Prm_Buffer 	= 30;
uint8_t User_Prm_Data_len = 4;
uint8_t user_prm[5] 	= {1,2,3,4};
/****************************************************************************************************/
/***************		SAP Buffer Config		******************************************/
/****************************************************************************************************/
uint8_t Ptr_Cfg_Buffer = 40;
uint8_t Ptr_Read_Cfg_Buffer = 40;
uint8_t Ptr_Aux1 = 10;
uint8_t Ptr_Aux2 = 20;
uint8_t Len_Aux1 = 20;
uint8_t Len_Aux2 = 20;
uint8_t Buf_Select_Aux = 1;


#endif /* CONF_H_ */
