/****************************************************
 *  RAM_Config.c
 *  Created on: 19-Oct-2021 8:31:52 PM
 *  Implementation of the Class RAM_Config
 *  Original author: PC Khayam
 ****************************************************/

#include "RAM_Config.h"

static uint8_t last_mr2 = 0;
static uint8_t last_mr3 = 0;




void Default_config_DPV0()
{
	uint8_t Zero[200] = {0};
	vpc3_Write_Array(0x0016, Zero, 200);
//	Int_Req_Reg IMR;
//	IMR.Packet_16Bit = 0xffff;
//	Config_Mask_Reg(IMR);
	Mode_Reg_0 mr0;
	mr0.Packet_16Bit = 0;
	mr0.configBit.DP_Mode = ENABLE;
	mr0.configBit.Int_Pol = ENABLE;  //  The interrupt output is high-active
//	mr0.configBit.Freeze_Supported = 1;
//	mr0.configBit.Sync_Supported = 1;
	Config_ModeReg0(mr0);

	/* set WD_BAUD_CONTROL_Val  */
	Set_WD_BAUD_CONTROL_Val(5);
	Set_Group_Select_Reg(0);
	Mode_Reg_2 mr2;
	mr2.Packet_8Bit = 0;
//	mr2.configBit.DX_Int_Mode = 1;
	Config_ModeReg2(mr2);

	Mode_Reg_3 mr3;
	mr3.Packet_8Bit = 0;
	Config_ModeReg3(mr3);
/***************************************************************************/



	/*  config Parameter SAP */
	vpc3_Write_Array(16<<3, Zero, 100);
}



void Config_Aux_Buffer(uint8_t len1, uint8_t len2, uint8_t Ptr1, uint8_t Ptr2, uint8_t Buf_Select){
	vpc3_Write_Byte(R_Aux_Buf_Sel, 0);
	SAP_Aux_Buffer Aux_buffer;
	Aux_buffer.conf.Len_Cntrl_Buf1 = len1;
	Aux_buffer.conf.Len_Cntrl_Buf2 = len2;
	Aux_buffer.conf.Aux_Buf_Sel = Buf_Select;
	Aux_buffer.conf.Aux_Buf_Ptr1  = Ptr1;
	Aux_buffer.conf.Aux_Buf_Ptr2 = Ptr2;
	vpc3_Write_Array(R_Len_Cntrl_Buf1, Aux_buffer.pack, 5);
}

//void Config_SSA_Buffer(uint8_t len, uint8_t Ptr){
//	SAP_SSA_Buffer SSA_buffer;
//	SSA_buffer.conf.SSA_Buf_Ptr = Ptr;
//	SSA_buffer.conf.Len_SSA_Data = len ;
//	vpc3_Write_Array(R_Len_SSA_Data, SSA_buffer.pack, 2);
//}

void Config_Prm_Buffer(uint8_t len, uint8_t Ptr){
	SAP_Prm_Buffer Prm_buffer;
	Prm_buffer.conf.Len_Prm_Data = len;
	Prm_buffer.conf.Prm_Buf_Ptr = Ptr;
	vpc3_Write_Array(R_Len_Prm_Data, Prm_buffer.pack, 2);
}

void Config_Cfg_Buffer(uint8_t len, uint8_t Ptr, uint8_t read_Cfg_len, uint8_t read_cfg_ptr){
	SAP_Cfg_Buffer cfg_buffer;
	cfg_buffer.conf.Len_Cfg_Data = len;
	cfg_buffer.conf.Cfg_Buf_Ptr = Ptr;
	cfg_buffer.conf.Len_Read_Cfg_Data = read_Cfg_len;
	cfg_buffer.conf.Read_Cfg_Buf_Ptr = read_cfg_ptr;
	vpc3_Write_Array(R_Len_Cfg_Data, cfg_buffer.pack , 4);
}
void Config_Diag_Buffer(uint8_t len1, uint8_t Ptr1,uint8_t len2, uint8_t Ptr2){
	SAP_Diag_Buffer Diag_buffer;
	Diag_buffer.conf.Diag_Buf_Ptr1 = Ptr1;
	Diag_buffer.conf.Len_Diag_Buf1 = len1;
	Diag_buffer.conf.Diag_Buf_Ptr2 = Ptr2;
	Diag_buffer.conf.Len_Diag_Buf2 = len2;
	vpc3_Write_Array(R_Len_Diag_Buf1 , Diag_buffer.pack, 4);
}
void Config_Dout_Buffer(uint8_t len, uint8_t Ptr1, uint8_t Ptr2, uint8_t Ptr3){
	SAP_Dout_Buffer dout_buffer;
	dout_buffer.conf.Len_Dout_Buf = len;
	dout_buffer.conf.Dout_Buf_Ptr1 = Ptr1;
	dout_buffer.conf.Dout_Buf_Ptr2 = Ptr2;
	dout_buffer.conf.Dout_Buf_Ptr3 = Ptr3;
	vpc3_Write_Array(R_Len_Dout_Buf, dout_buffer.pack, 4);
}
void Config_Din_Buffer(uint8_t len, uint8_t Ptr1, uint8_t Ptr2, uint8_t Ptr3){
	SAP_Din_Buffer din_Buffer;
	din_Buffer.conf.Len_Din_Buf = len;
	din_Buffer.conf.Din_Buf_Ptr1 = Ptr1;
	din_Buffer.conf.Din_Buf_Ptr2 = Ptr2;
	din_Buffer.conf.Din_Buf_Ptr3 = Ptr3;
	vpc3_Write_Array(R_Len_Din_Buf, din_Buffer.pack, 4);
}

void Default_config_DPV1()
{

}

void Config_ModeReg0(Mode_Reg_0 mode_reg0){
	Mode_Reg_0	r_mr0 ;
	r_mr0.Byte[0] = vpc3_Read_Byte(Mode_Reg0_L);
	r_mr0.Byte[1] = vpc3_Read_Byte(Mode_Reg0_H);
	mode_reg0.Packet_16Bit = mode_reg0.Packet_16Bit | r_mr0.Packet_16Bit;
	vpc3_Write_Array(Mode_Reg0_L, mode_reg0.Byte, 2);
}
void Config_ModeReg2(Mode_Reg_2 mode_reg2){
	mode_reg2.Packet_8Bit = mode_reg2.Packet_8Bit | last_mr2;
	vpc3_Write_Byte(Mode_Reg2, mode_reg2.Packet_8Bit);
	last_mr2 = mode_reg2.Packet_8Bit;
}

void Config_ModeReg3(Mode_Reg_3 mode_reg3){
	mode_reg3.Packet_8Bit = mode_reg3.Packet_8Bit | last_mr3;
	vpc3_Write_Byte(Mode_Reg2, mode_reg3.Packet_8Bit);
	last_mr3 = mode_reg3.Packet_8Bit;
}

void Set_SAP_List_Ptr(uint8_t _SAP_List_Ptr){
	vpc3_Write_Byte(SAP_List_Ptr, _SAP_List_Ptr);
}

void Set_Group_Select_Reg(uint8_t gsr){
	vpc3_Write_Byte(Group_Select_Reg, gsr);
}
void Set_RAM_Size(RAM_Size ram_size)
{
	Mode_Reg_2 mode_reg2;
	mode_reg2.configBit._4kB_Mode = ram_size;
	mode_reg2.Packet_8Bit = mode_reg2.Packet_8Bit | last_mr2;
	vpc3_Write_Byte(Mode_Reg2, mode_reg2.Packet_8Bit);
	last_mr2 = mode_reg2.Packet_8Bit;
}

void Set_MinTsdr(uint8_t Tsdr)
{
	vpc3_Write_Byte(MinTsdr_Val, Tsdr);
}

void Set_Sync_PW_Reg(uint8_t x){
	vpc3_Write_Byte(Sync_PW_Reg, x);
}
void Get_Control_Command_Reg(uint8_t x){
	vpc3_Write_Byte(Control_Command_Reg, x);
}


void Set_Slave_Address(uint8_t Slave_Address)
{
	vpc3_Write_Byte(R_TS_Adr, Slave_Address);
}


void Set_VPC3_Start(void)
{
	Mode_Reg_1 mr1;
	mr1.Packet_8Bit = 0;
	mr1.configBit.START_VPC3 = 1;
	vpc3_Write_Byte(Mode_Reg1_S, mr1.Packet_8Bit);
}
void Set_Go_Offline(void){
	Mode_Reg_1 mr1;
	mr1.Packet_8Bit = 0;
	mr1.configBit.Go_Offline = 1;
	vpc3_Write_Byte(Mode_Reg1_S, mr1.Packet_8Bit);
}
void Set_R_User_WD_Value(uint16_t user_wd_value)
{
	uint8_t data[2] = { user_wd_value && 0x00ff ,  user_wd_value>>8 };
	vpc3_Write_Array(R_User_WD_Value_L, data, 2);
}

void Set_WD_BAUD_CONTROL_Val(uint8_t data)
{
	vpc3_Write_Byte(WD_BAUD_CONTROL_Val, data);
}
void Set_Res_User_WD(void){
	Mode_Reg_1 mr1;
	mr1.Packet_8Bit = 0;
	mr1.configBit.Res_User_WD = 1;
	vpc3_Write_Byte(Mode_Reg1_S, mr1.Packet_8Bit);
}
void Reset_VPC3_Start(void){
	Mode_Reg_1 mr1;
	mr1.Packet_8Bit = 0;
	mr1.configBit.START_VPC3 = 1;
	vpc3_Write_Byte(Mode_Reg1_R, mr1.Packet_8Bit);
}



void Set_Ident_Number(uint16_t ident_num){
	uint8_t data[2] = { ident_num & 0x00ff ,  ident_num>>8 };
	vpc3_Write_Array(R_Ident_Low, data, 2);
}

void Set_EOI(void){
	Mode_Reg_1 mr1;
	mr1.Packet_8Bit = 0;
	mr1.configBit.EOI = 1;
	vpc3_Write_Byte(Mode_Reg1_S, mr1.Packet_8Bit);

}
void DP_Mode_Enable(enable_disable_mode mode){
	Mode_Reg_0 mr0;
	mr0.configBit.DP_Mode = mode;
	uint8_t lastData = vpc3_Read_Byte(Mode_Reg0_H);
	vpc3_Write_Byte(Mode_Reg0_H, (mr0.Byte[2])|(lastData) );
}

RAM_Size Get_RAM_Size(void){
	return last_mr2 & 0x80;
}
