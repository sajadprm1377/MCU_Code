/*
 * DATA_Exchange.c
 *
 *  Created on: Nov 26, 2021
 *      Author: PC Khayam
 */
#include "DATA_Exchange.h"



Dout_Buffer_Assignment Get_Dout_Buffer_Assignment(Dout_Buffer_type buffer){
	switch(buffer){
	case D_Buffer:
		return (vpc3_Read_Byte(Dout_Buffer_SM) & 3);
	case N_Buffer:
		return ((vpc3_Read_Byte(Dout_Buffer_SM) & 12)>>N_Buffer);
	case U_Buffer:
		return ((vpc3_Read_Byte(Dout_Buffer_SM) & 48)>>U_Buffer);
	case F_Buffer:
		return ((vpc3_Read_Byte(Dout_Buffer_SM) & 192)>>F_Buffer);
	default:
		return Nil;
	}
}




void DXOut_Handeler(void){
	Ack_Interrupte(S_DX_Out);
	Set_Res_User_WD();
	Set_EOI();
}




uint8_t Fetch_Dout_buffer(void){
	return vpc3_Read_Byte(Next_Dout_Buffer_Cmd);
}


uint8_t Make_Din_buffer(void){
	return vpc3_Read_Byte(New_Din_Buffer_Cmd);
}



void Put_Input_Data(uint8_t* Din_Buffer){
	uint8_t Din_Buffer_cmd = Make_Din_buffer();
	Din_Buffer_Assignment Ind_U_Buffer = GET_U_BUFFER(Din_Buffer_cmd);
	uint8_t add = 0;
	switch(Ind_U_Buffer){
	case Din_Buf_Ptr1:
		add = vpc3_Read_Byte(R_Din_Buf_Ptr1)<<3;((_2kByte == Get_RAM_Size()) ? 3 : 4);
		break;
	case Din_Buf_Ptr2:
		add = vpc3_Read_Byte(R_Din_Buf_Ptr2)<<((_2kByte == Get_RAM_Size()) ? 3 : 4);
		break;
	case Din_Buf_Ptr3:
		add = vpc3_Read_Byte(R_Din_Buf_Ptr3)<<((_2kByte == Get_RAM_Size()) ? 3 : 4);
		break;
	default:
		add = 0x00;
	}
	if (add)
		vpc3_Write_Array(add, Din_Buffer, 2);

}
void Get_Output_Data(uint8_t* Dout_Buffer){
	uint8_t Dout_Buffer_cmd = Fetch_Dout_buffer();
	Dout_Buffer_Assignment Ind_U_Buffer = GET_U_BUFFER(Dout_Buffer_cmd);
	uint8_t add = 0;
	switch(Ind_U_Buffer){
	case Dout_Buf_Ptr1:
		add = vpc3_Read_Byte(R_Dout_Buf_Ptr1)<<((_2kByte == Get_RAM_Size()) ? 3 : 4);
		break;
	case Dout_Buf_Ptr2:
		add = vpc3_Read_Byte(R_Dout_Buf_Ptr2)<<((_2kByte == Get_RAM_Size()) ? 3 : 4);
		break;
	case Dout_Buf_Ptr3:
		add = vpc3_Read_Byte(R_Dout_Buf_Ptr3)<<((_2kByte == Get_RAM_Size()) ? 3 : 4);
		break;
	default:
		add = 0x00;
	}
	if(add)
		vpc3_Read_Array(add, Dout_Buffer, 2);
}
