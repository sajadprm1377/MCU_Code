/*
 * Chk_Cfg.c
 *
 *  Created on: Nov 6, 2021
 *      Author: PC Khayam
 */

#include "Chk_Cfg.h"

extern uint8_t user_cfg[2];

Cfg_Status User_Cfg_Data_Okay_Cmd(void){
	return ((vpc3_Read_Byte(User_Cfg_Data_Okay))&3);
}
Cfg_Status User_Cfg_Data_Not_Okay_Cmd(void){
	return ((vpc3_Read_Byte(User_Cfg_Data_Not_Okay))&3);
}

void Chk_Cfg_Initial(Chk_Cfg_Setting* ccs){
	vpc3_Write_Byte(R_Cfg_Buf_Ptr, ccs->Seg_Base_Cfg_Buffer);
	vpc3_Write_Byte(R_Read_Cfg_Buf_Ptr, ccs->Seg_Base_Read_Cfg_Buffer);
}
uint8_t Check_Cfg_buffer(uint8_t* Cfg_buffer_from_Master, uint8_t* self_cfg_buffer, uint8_t length_buffer){
	for(uint8_t i=0; i<length_buffer; i++){
		if(Cfg_buffer_from_Master[i] != self_cfg_buffer[i])
			return 0;
	}
	return 1;
}
void Chk_Cfg_Handeler(void){
	Set_Res_User_WD();
	uint8_t length = vpc3_Read_Byte(R_Len_Cfg_Data);
	uint8_t *cfg_buffer = malloc(length);
	uint8_t add = vpc3_Read_Byte(R_Cfg_Buf_Ptr)<<3;
	vpc3_Read_Array(add, cfg_buffer, length);
//	Chk_Cfg_Callback(cfg_buffer, length);
	if(Check_Cfg_buffer(cfg_buffer, user_cfg, length))
		while(User_Cfg_Finished != User_Cfg_Data_Okay_Cmd());
	else
		while(User_Cfg_Finished != User_Cfg_Data_Not_Okay_Cmd());

	free(cfg_buffer);
}
