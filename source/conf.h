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
//PORT_Type*  PORT_Interrupt = PORTD;
#define  GPIO_Interrupt  GPIOD
//uint32_t 	PIN_Interrupt  = X_INT_PIN;
#define  SPI_Base_Add 	SPI1_PERIPHERAL
/****************************************************************************************************/
/*********     vpc3 Config         ********************************************************/
/****************************************************************************************************/
#define Slave_Address 	 4
#define RAM_size  		_2kByte
#define Interrupt_Mask_Disable   C_BaudRate_detect & C_New_Prm_Data & C_New_Cfg_Data &C_DX_Out &C_Go_Leave_DATA_EXCH & C_WD_DP_CONTROL_Timeout& C_Diag_Buffer_Changed
/****************************************************************************************************/
/***************		Parameterization Setting		******************************************/
/****************************************************************************************************/
#define  ident_num 			0xabcd
#define min_Tsdr 11
#define R_user_WD_value 		 	0xefff
#define seg_base_prm_buffer 	 	30
#define user_prm_data_len 		4
//uint8_t user_prm[5] 	= {1,2,3,4};
/****************************************************************************************************/
/***************		Configuration Setting		******************************************/
/****************************************************************************************************/
#define User_Cfg_Data_len 		2
//uint8_t User_Cfg[User_Cfg_Data_len] = {33,17};
#define input_data_len 2
#define output_data_len 2
/****************************************************************************************************/
/***************		SAP Buffer Config		******************************************/
/****************************************************************************************************/
#define Ptr_Cfg_Buffer 		 40
#define Ptr_Read_Cfg_Buffer  40
#define Ptr_Aux1 			 10
#define Ptr_Aux2 			 20
#define Len_Aux1 			 20
#define Len_Aux2 			 20
#define Buf_Select_Aux  	 1


#endif /* CONF_H_ */
