#ifdef __cplusplus
extern "C" {
#endif

#include "MCU_Cfg/SPI.h"
#include "MCU_Cfg/Port.h"
#define READ_BYTE 		0b00010011
#define WRITE_BYTE 		0b00010010
#define READ_ARRAY		0b00000011
#define WRITE_ARRAY		0b00000010
#define ENABLE 	1
#define DISABLE 0








/*------------ Address Control Parameter Read ------------*/
#define Int_Req_Reg_L			0x0000		// for read and write
#define Int_Req_Reg_H			0x0001		// for read and write
#define Int_Reg_L				0x0002
#define Int_Reg_H				0x0003
#define Status_Reg_L 			0x0004
#define Status_Reg_H 			0x0005
#define Mode_Reg0_L				0x0006		// for read and write
#define Mode_Reg0_H				0x0007		// for read and write
#define Din_Buffer_SM			0x0008
#define New_Din_Buffer_Cmd		0x0009
#define Dout_Buffer_SM			0x000A
#define Next_Dout_Buffer_Cmd 	0x000B
#define Diag_Buffer_SM 			0x000C
#define New_Diag_Buffer_Cmd 	0x000D
#define User_Prm_Data_Okay 		0x000E
#define User_Prm_Data_Not_Okay	0x000F
#define User_Cfg_Data_Okay 		0x0010
#define User_Cfg_Data_Not_Okay 	0x0011
#define DXBout_Buffer_SM 		0x0012		// for profibus DPV2
#define Next_DXBout_Buffer_Cmd 	0x0013
#define SSA_Buffer_Free_Cmd 	0x0014
#define Mode_Reg1 				0x0015


/*------------ Address Control Parameter Write ------------*/
#define	Int_Ack_Reg_L			0x0002
#define	Int_Ack_Reg_H			0x0003
#define	Int_Mask_Reg_L			0x0004
#define	Int_Mask_Reg_H			0x0005
#define	Mode_Reg1_S				0x0008
#define	Mode_Reg1_R				0x0009
#define	WD_BAUD_CONTROL_Val 	0x000A
#define	MinTsdr_Val 			0x000B
#define	Mode_Reg2				0x000C
#define	Sync_PW_Reg 			0x000D
#define	Control_Command_Reg 	0x000E
#define	Group_Select_Reg 		0x000F
#define	Mode_Reg3				0x0012

/*------------ Organizational Parameters (RAM) ------------*/
#define R_TS_Adr 				0x0016
#define SAP_List_Ptr 			0x0017
#define	R_User_WD_Value_L		0x0018
#define	R_User_WD_Value_H		0x0019
#define	R_Len_Dout_Buf			0x001A	// length of 3 Dout Buffer
#define	R_Dout_Buf_Ptr1 		0x001B
#define	R_Dout_Buf_Ptr2			0x001C
#define	R_Dout_Buf_Ptr3			0x001D
#define	R_Len_Din_Buf 			0x001E
#define	R_Din_Buf_Ptr1 			0x001F
#define	R_Din_Buf_Ptr2			0x0020
#define	R_Din_Buf_Ptr3 			0x0021
#define	R_Len_DXBout_Buf		0x0022
#define	R_DXBout_Buf_Ptr1 		0x0023
#define	R_Len_Diag_Buf1			0x0024
#define	R_Len_Diag_Buf2			0x0025
#define	R_Diag_Buf_Ptr1			0x0026
#define	R_Diag_Buf_Ptr2 		0x0027
#define	R_Len_Cntrl_Buf1 		0x0028
#define	R_Len_Cntrl_Buf2 		0x0029
#define R_Aux_Buf_Sel 			0x002A
#define R_Aux_Buf_Ptr1			0x002B
#define R_Aux_Buf_Ptr2			0x002C
#define R_Len_SSA_Data 			0x002D
#define R_SSA_Buf_Ptr 			0x002E
#define R_Len_Prm_Data 			0x002F
#define	R_Prm_Buf_Ptr 			0x0030
#define	R_Len_Cfg_Data			0x0031
#define	R_Cfg_Buf_Ptr 			0x0032
#define	R_Len_Read_Cfg_Data 	0x0033
#define	R_Read_Cfg_Buf_Ptr 		0x0034
#define	R_Len_DXB_Link_Buf 		0x0035
#define	R_DXB_Link_Buf_Ptr 		0x0036
#define	R_Len_DXB_Status_Buf 	0x0037
#define	R_DXB_Status_Buf_Ptr 	0x0038
#define	R_Real_No_Add_Change 	0x0039
#define	R_Ident_Low 			0x003A
#define	R_Ident_High 			0x003B
#define	R_GC_Command 			0x003C
#define	R_Len_Spec_Prm_Buf 		0x003D
#define	R_DXBout_Buf_Ptr2 		0x003E
#define R_DXBout_Buf_Ptr3		0x003F

void vpc3_Read_Array(uint16_t Address, uint8_t* Data, uint8_t Length);
uint8_t vpc3_Read_Byte(uint16_t Address);
void vpc3_Write_Array(uint16_t Address, uint8_t* Data, uint8_t Length);
void vpc3_Write_Byte(uint16_t Address, uint8_t Data);
void vpc3_Reset(void);

#ifdef __cplusplus
}
#endif
