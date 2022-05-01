/*
 * PROFIBUS_DP.c
 *
 *  Created on: Dec 1, 2021
 *      Author: PC Khayam
 */

#include "Profibus_dp.h"



static GPIO_Type* GPIO__Interrupt;
//static Profibus_State profibus_state = before_Startup;

static PROFIBUS_SM profibus_sm = IDLE;

static DX_ERR dx_err = first_DX;

extern uint8_t user_prm[5];


void vpc3_Initial(void){

//    Config_Interrupt_PIN(PORT_Interrupt, GPIOD, PIN_Interrupt);
	SPI_Config(SPI_Base_Add);
	Config_Reset_PIN_Default();
	vpc3_Reset();
	Default_config_DPV0();
	Set_Slave_Address(Slave_Address);
	Set_RAM_Size(RAM_size);
	Prm_specific prm;
	prm.Ident_Number = Ident_Num;
	prm.Min_Tsdr = Min_Tsdr;
	prm.R_User_WD_Value = R_User_WD_Value;
	prm.Seg_Base_Prm_Buffer = Seg_Base_Prm_Buffer;

	User_Prm_Data upd;
	upd.Length = User_Prm_Data_len;
	upd.Buffer = user_prm;
	Set_Prm_Initial(&prm, &upd);


    Chk_Cfg_Setting Cfg_Config;
    Cfg_Config.Seg_Base_Cfg_Buffer 		= Ptr_Cfg_Buffer;
    Cfg_Config.Seg_Base_Read_Cfg_Buffer = Ptr_Read_Cfg_Buffer;


    Chk_Cfg_Initial(&Cfg_Config);
	Enable_Interrupte(Interrupt_Mask_Disable);
	Config_Aux_Buffer(Len_Aux1, Len_Aux2, Ptr_Aux1, Ptr_Aux2, Buf_Select_Aux);
	Config_Cfg_Buffer(2, 40, 2, 41);
	Config_Dout_Buffer(2, 20, 21, 22);
	Config_Din_Buffer(2, 23, 24, 25);
	Config_Diag_Buffer(6, 60, 6, 61);




    Set_Res_User_WD();
    Set_VPC3_Start();

//    Config_Interrupt_PIN(PORT_Interrupt, GPIOD, PIN_Interrupt);
//    profibus_sm = INT_HAMDLE;

}

//Profibus_State Get_profibus_state(void){
//	return profibus_state;
//}
//
//void Set_profibus_state(Profibus_State ps){
//	profibus_state = ps;
//}

void vpc3_Interrupt_Handler(void){
	 /* Clear pin flags */
profibus_sm = INT_HAMDLE;

}



status_t PROFIBUS_manager(uint8_t* din_Buffer, uint8_t* dout_Buffer, uint16_t irr){
	if (profibus_sm == INT_HAMDLE){
		profibus_sm = IDLE;
		uint16_t IRR = Get_interrupte_Req_Reg();

		if (IRR & S_BaudRate_detect){
			Ack_Interrupte(S_BaudRate_detect);
		}
		if(IRR & S_DX_Out){
			if (dx_err == first_DX){
				DXOut_Handeler();
				dx_err = Normal_DX;
			}
			else{
				Get_Output_Data(dout_Buffer);
				Put_Input_Data(din_Buffer);
				DXOut_Handeler();
			}
		}
		if(IRR & S_New_Prm_Data){
			Set_Prm_Handler();
		}
		if(IRR & S_New_Cfg_Data)
			Chk_Cfg_Handeler();
		if(IRR & S_Go_Leave_DATA_EXCH){
			Ack_Interrupte(S_Go_Leave_DATA_EXCH);
			S_Go_Leave_DATA_EXCH_Callback();
			if (WAIT_PRM == Get_DP_state()){
				Set_Go_Offline();
				Set_VPC3_Start();
			}
		 }
		 if(IRR & S_WD_DP_CONTROL_Timeout){
			 Ack_Interrupte(S_WD_DP_CONTROL_Timeout);
		  }
		 if (IRR & S_Diag_Buffer_Changed){
			 Ack_Interrupte(S_Diag_Buffer_Changed);
		 }
		 return 1;
	}
	else
		return 0;
















/*
	switch (profibus_sm) {
		case INT_HAMDLE:

			if (Get_interrupte_Req_Reg() & S_BaudRate_detect){
				Ack_Interrupte(S_BaudRate_detect);
			}
			if(Get_interrupte_Req_Reg() & S_DX_Out){
				DXOut_Handeler();
				Data_Exchange_CallBack();
			}
			if(Get_interrupte_Req_Reg() & S_New_Prm_Data){
				Set_Prm_Handler();
			}

			if(Get_interrupte_Req_Reg() & S_New_Cfg_Data)
				Chk_Cfg_Handeler();
			if(Get_interrupte_Req_Reg() & S_Go_Leave_DATA_EXCH){
				Ack_Interrupte(S_Go_Leave_DATA_EXCH);
				S_Go_Leave_DATA_EXCH_Callback();
				Set_profibus_state(after_Startup);

				if (WAIT_PRM == Get_DP_state()){
					Set_Go_Offline();
					Set_VPC3_Start();
				}
			 }
			 if(Get_interrupte_Req_Reg() & S_WD_DP_CONTROL_Timeout){

				 Ack_Interrupte(S_WD_DP_CONTROL_Timeout);
			  }
			 if (Get_interrupte_Req_Reg() & S_Diag_Buffer_Changed){
				 Ack_Interrupte(S_Diag_Buffer_Changed);
			 }

			 profibus_sm = RUN;
			break;



		default:
			break;
	}

	*/
}

void MKV31f_Interrupt_Handler(void){

	/* Get pin flags */
	uint32_t pin_flags = GPIO_PortGetInterruptFlags(GPIO_Interrupt);
	GPIO_PortClearInterruptFlags(GPIOD, pin_flags);
	#if defined __CORTEX_M && (__CORTEX_M == 4U)
	__DSB();
	#endif
}


/* PORTD_IRQn interrupt handler */
//void GPIOD_IRQHANDLER(void) {
//	MKV31f_Interrupt_Handler();
//	vpc3_Interrupt_Handler();
//}
/* PORTD_IRQn interrupt handler */
void PROFIBUS_Interrupt_Handler(void) {
	MKV31f_Interrupt_Handler();
	vpc3_Interrupt_Handler();
}


