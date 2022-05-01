/*
 * Set_Prm.c
 *
 *  Created on: Nov 3, 2021
 *      Author: PC Khayam
 */

#include "Set_Prm.h"
static uint8_t User_Prm_Data_Len;
uint8_t User_Prm_Data_buffer[];
Prm_Status User_Prm_Data_Okay_Cmd(void){
	return (vpc3_Read_Byte(User_Prm_Data_Okay))&3;
}
Prm_Status User_Prm_Data_Not_Okay_Cmd(void){
	return (vpc3_Read_Byte(User_Prm_Data_Not_Okay))&3;
}
uint8_t Check_Prm_buffer(uint8_t* Prm_buffer_from_Master, uint8_t* self_Prm_Buffer,uint8_t length_Buffer){
	for(uint8_t i=7; i<length_Buffer; i++){
		if(Prm_buffer_from_Master[i] != self_Prm_Buffer[i-7])
			return 0;
	}
	return 1;
}


Status_Prm Set_Prm_Handler(){
	Set_Res_User_WD();
	uint8_t length = vpc3_Read_Byte(R_Len_Prm_Data);
	uint8_t *prm_buffer = malloc(length);
	uint16_t Address = (vpc3_Read_Byte(R_Prm_Buf_Ptr))<<3;
	vpc3_Read_Array(Address, prm_buffer, length);
	if(Check_Prm_buffer(prm_buffer, User_Prm_Data_buffer, length)){
//		Set_Prm_Callback(prm_buffer, length);
		while(User_Prm_Finished != User_Prm_Data_Okay_Cmd());
		return Succrssful_PRM;
	}
	else{
		while(User_Prm_Finished != User_Prm_Data_Not_Okay_Cmd());
		return Error_PRM;
	}
	free(prm_buffer);
}



void Set_Prm_Initial(Prm_specific* prm_spec, User_Prm_Data* upd){
	Set_Ident_Number(prm_spec->Ident_Number);
	Set_MinTsdr(prm_spec->Min_Tsdr);
	Set_R_User_WD_Value(prm_spec->R_User_WD_Value);
	vpc3_Write_Byte(R_Prm_Buf_Ptr, prm_spec->Seg_Base_Prm_Buffer);
	User_Prm_Data_Len = upd->Length;
	for(int i=0; i<User_Prm_Data_Len; i++)
		*(User_Prm_Data_buffer + i) = *(upd->Buffer + i);

}
