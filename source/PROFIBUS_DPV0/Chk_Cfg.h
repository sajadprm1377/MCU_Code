/*
 * Chk_Cfg.h
 *
 *  Created on: Nov 6, 2021
 *      Author: PC Khayam
 */

#ifndef CHK_CFG_H_
#define CHK_CFG_H_


#include "vpc3_Controller/Status.h"
#include "vpc3_Controller/RAM_Config.h"
#include "vpc3_Controller/Interrupt.h"



typedef enum{
	User_Cfg_Finished,
	Cfg_Conflict,
	_Not_Allowed
}Cfg_Status;
typedef enum{
	Special_Format,
	Input,
	Output,
	InputOutput
}Data_Direction;
typedef enum{
	Byte,
	Word
}Data_Type;
typedef enum{
	Consistency_of_ByteWord,
	Consistency_of_EntireLength
}Consistenciation;

typedef struct{
	Consistenciation Consistency;
	Data_Direction 	DIR;
	Data_Type   	data_type;
	uint8_t 		length;
	uint8_t 		Seg_Base_Cfg_Buffer;
	uint8_t 		Seg_Base_Read_Cfg_Buffer;
}Chk_Cfg_Setting;
typedef union{
	struct{
		uint8_t Consistency:1;
		uint8_t Data_type:1;
		uint8_t DIR:2;
		uint8_t lengh:4;
	};
	uint8_t cfg_data;
}Cfg_Compact_Format;

void Chk_Cfg_Initial(Chk_Cfg_Setting* );
void Config_Chk_Cfg_Buffer(uint8_t Base_Addr, uint8_t lengt);
//status_t Check_Prm_Buffer();
Cfg_Status User_Cfg_Data_Okay_Cmd(void);
Cfg_Status User_Cfg_Data_Not_Okay_Cmd(void);
uint8_t Check_Cfg_buffer(uint8_t*, uint8_t*, uint8_t);
void Chk_Cfg_Handeler(void);
void Chk_Cfg_Callback(uint8_t*, uint8_t);
#endif /* CHK_CFG_H_ */
