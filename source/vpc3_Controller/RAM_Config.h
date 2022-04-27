/****************************************************
 *  RAM_Config.h
 *  Created on: 19-Oct-2021 8:31:52 PM
 *  Implementation of the Class RAM_Config
 *  Original author: PC Khayam
 ****************************************************/

#if !defined(EA_33384B92_F401_426c_9EAA_EA44380A31A0__INCLUDED_)
#define EA_33384B92_F401_426c_9EAA_EA44380A31A0__INCLUDED_


#ifdef __cplusplus
extern "C" {
#endif

#include "vpc3_drive.h"
//#include "Interrupt.h"


typedef enum{
	_2kByte = 0,
	_4kByte
}RAM_Size;



typedef union {
	struct{
    	uint16_t Dis_Start_Control  	: 1;
    	uint16_t Dis_Stop_Control   	: 1;
    	uint16_t WD_Base 				: 1;
    	uint16_t CS_Supported 			: 1;
    	uint16_t Int_Pol 				: 1;
    	uint16_t Early_Rdy 				: 1;
    	uint16_t Sync_Supported			: 1;
    	uint16_t Freeze_Supported 		: 1;
    	uint16_t DP_Mode  				: 1;
    	uint16_t EOI_Time_Base  		: 1;
		uint16_t User_Time_Base  		: 1;
		uint16_t Set_Ext_Prm_Supported  : 1;
		uint16_t Spec_Prm_Buf_Mode      : 1;
		uint16_t Spec_Clear_Mode   		: 1;
		uint16_t PrmCmd_Supported 		: 1;
		uint16_t reserved 				: 1;
	}configBit;
	uint16_t Packet_16Bit;
	uint8_t Byte[2];
}Mode_Reg_0;

typedef union{
	struct{
		uint8_t START_VPC3			: 1;
		uint8_t EOI 				: 1;
		uint8_t Go_Offline 			: 1;
		uint8_t User_LEAVEMASTER	: 1;
		uint8_t En_Change_Cfg_Buffer: 1;
		uint8_t Res_User_WD 		: 1;
	}configBit;
	uint8_t Packet_8Bit;
}Mode_Reg_1;

typedef union {
	struct{
    	uint8_t GC_Int_Mode   		  : 1;
    	uint8_t No_Check_GC_Reserved  : 1;
    	uint8_t DX_Int_Mode  		  : 1;
    	uint8_t DX_Int_Port  		  : 1;
    	uint8_t SYNC_Ena  			  : 1;
    	uint8_t SYNC_Pol  			  : 1;
    	uint8_t No_Check_Prm_Reserved : 1;
    	uint8_t _4kB_Mode  			  : 1;
	}configBit;
	uint8_t Packet_8Bit;
}Mode_Reg_2;

typedef union {
	struct{
    	uint8_t GC_Int_Mode_Ext : 1;
    	uint8_t DX_Int_Mode_2   : 1;
    	uint8_t En_Chk_SSAP   	: 1;
    	uint8_t PLL_Supported   : 1;
    	uint8_t ReservedBit  	: 4;
	}configBit;
	uint8_t Packet_8Bit;
}Mode_Reg_3;

//typedef struct{
//	uint16_t Ident_Number;
//	uint8_t  Slave_Address;
//	uint8_t  MinTsdr;
//	uint16_t R_User_WD_Value;
//	RAM_Size ram_size;
//	uint8_t   WD_BAUD_CONTROL_val;
//}vpc3_specific;


typedef union {
	struct {
		uint8_t Len_Dout_Buf;
		uint8_t Dout_Buf_Ptr1;
		uint8_t Dout_Buf_Ptr2;
		uint8_t Dout_Buf_Ptr3;
	}conf;
	uint8_t pack[4];
}SAP_Dout_Buffer;


typedef union {
	struct{
		uint8_t Len_Din_Buf;
		uint8_t Din_Buf_Ptr1;
		uint8_t Din_Buf_Ptr2;
		uint8_t Din_Buf_Ptr3;
	}conf;
	uint8_t pack[4];
}SAP_Din_Buffer;

typedef union{
	struct{
		uint8_t Len_DXBout_Buf;
		uint8_t DXBout_Buf_Ptr1;
	}conf;
	uint8_t pack[2];
}SAP_DXBout_Buffer;

typedef union{
	struct{
		uint8_t Len_Diag_Buf1;
		uint8_t	Len_Diag_Buf2;
		uint8_t	Diag_Buf_Ptr1;
		uint8_t Diag_Buf_Ptr2;
	}conf;
	uint8_t pack[4];
}SAP_Diag_Buffer;


typedef union {
	struct{
		uint8_t Len_Cntrl_Buf1;
		uint8_t Len_Cntrl_Buf2;
		uint8_t Aux_Buf_Sel;
		uint8_t Aux_Buf_Ptr1;
		uint8_t Aux_Buf_Ptr2;
	}conf;
	uint8_t pack[5];
}SAP_Aux_Buffer;

typedef union{
	struct {
		uint8_t Len_SSA_Data;
		uint8_t SSA_Buf_Ptr ;
	}conf;
	uint8_t pack[2];
}SAP_SSA_Buffer;

typedef union{
	struct{
		uint8_t Len_Prm_Data ;
		uint8_t Prm_Buf_Ptr ;
	}conf;
	uint8_t pack[2];
}SAP_Prm_Buffer;

typedef union {
	struct{
		uint8_t Len_Cfg_Data;
		uint8_t Cfg_Buf_Ptr ;
		uint8_t Len_Read_Cfg_Data ;
		uint8_t Read_Cfg_Buf_Ptr;
	}conf;
	uint8_t pack[4];
}SAP_Cfg_Buffer;

typedef struct{
	SAP_Dout_Buffer 	Dout_Buffer;
	SAP_Din_Buffer  	Din_Buffer;
	SAP_DXBout_Buffer 	Dxbout_Buffer;
	SAP_Diag_Buffer 	Diag_Buffer;
	SAP_Aux_Buffer  	Aux_Buffer;
	SAP_SSA_Buffer  	SSA_Buffer;
	SAP_Prm_Buffer  	Prm_Buffer;
	SAP_Cfg_Buffer		Cfg_Buffer;
}SAP_Buffer;
typedef struct{
	uint8_t Slave_Address;

}x;

typedef enum{
	disable = 0,
	enable
}enable_disable_mode;


void Default_config_DPV1();
void Default_config_DPV0(void);
void Config_ModeReg0(Mode_Reg_0);
void Config_ModeReg2(Mode_Reg_2);
void Config_ModeReg3(Mode_Reg_3);
void Set_RAM_Size(RAM_Size);
RAM_Size Get_RAM_Size(void);
void Set_MinTsdr(uint8_t);
void set_Sync_PW_Reg(uint8_t x);
void Get_Control_Command_Reg(uint8_t x);
void Set_Slave_Address(uint8_t);
void Set_VPC3_Start(void);
void Set_Res_User_WD(void);
void Reset_VPC3_Start(void);
void Set_EOI(void);
void Set_Go_Offline(void);
void DP_Mode_Enable(enable_disable_mode);
void Set_Ident_Number(uint16_t ident_num);
void Set_SAP_List_Ptr(uint8_t _SAP_List_Ptr);
void Set_Group_Select_Reg(uint8_t);
void Set_WD_BAUD_CONTROL_Val(uint8_t);
void Set_R_User_WD_Value(uint16_t);
void Config_Aux_Buffer(uint8_t len1, uint8_t len2, uint8_t Ptr1, uint8_t Ptr2, uint8_t Buf_Select);
void Config_SSA_Buffer(uint8_t len, uint8_t Ptr);
void Config_Prm_Buffer(uint8_t len, uint8_t Ptr);
void Config_Cfg_Buffer(uint8_t len, uint8_t Ptr, uint8_t read_Cfg_len, uint8_t read_cfg_ptr);
void Config_Diag_Buffer(uint8_t len1, uint8_t Ptr1,uint8_t len2, uint8_t Ptr2);
void Config_Dout_Buffer(uint8_t len, uint8_t Ptr1, uint8_t Ptr2, uint8_t Ptr3);
void Config_Din_Buffer(uint8_t len, uint8_t Ptr1, uint8_t Ptr2, uint8_t Ptr3);

#ifdef __cplusplus
}
#endif


#endif /*!defined(EA_33384B92_F401_426c_9EAA_EA44380A31A0__INCLUDED_)*/
