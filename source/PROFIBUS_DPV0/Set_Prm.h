/*
 * Set_Prm.h
 *
 *  Created on: Nov 3, 2021
 *      Author: PC Khayam
 */

#ifndef SET_PRM_H_
#define SET_PRM_H_
#include "vpc3_Controller/Status.h"
#include "vpc3_Controller/RAM_Config.h"
#include "vpc3_Controller/Interrupt.h"
typedef enum{
	User_Prm_Finished,
	Prm_Conflict,
	Not_Allowed
}Prm_Status;
typedef enum{
	Fail_Safe_No_Supp = 0U,
	Fail_Safe_Supp
}Special_Clear_Mode;

typedef enum{
	Error_User_Prm_Data,
	Succrssful_User_Prm_Data
}Status_Set_Prm;

typedef struct{
	uint16_t Ident_Number;
	uint8_t Min_Tsdr;
	uint8_t Seg_Base_Prm_Buffer;
	uint16_t R_User_WD_Value;

}Prm_specific;

typedef struct{
	uint8_t Length;
	uint8_t* Buffer;
}User_Prm_Data;


void Enable_Fail_Safe_Mode(Special_Clear_Mode);		/*VPC3+S will accept data telegrams with data unit = 0 */
void Set_Prm_Initial(Prm_specific*, User_Prm_Data*);
void Set_Prm_Handler();
void Set_Prm_Callback(uint8_t*, uint8_t);
Prm_Status User_Prm_Data_Okay_Cmd(void);
Prm_Status User_Prm_Data_Not_Okay_Cmd(void);

#endif /* SET_PRM_H_ */
