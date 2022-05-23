/*
 * DATA_Exchange.h
 *
 *  Created on: Nov 26, 2021
 *      Author: PC Khayam
 */

#ifndef DATA_EXCHANGE_H_
#define DATA_EXCHANGE_H_
#define GET_U_BUFFER(BUFFER) BUFFER & 3
#include "vpc3_Controller/Status.h"
#include "vpc3_Controller/RAM_Config.h"
#include "vpc3_Controller/Interrupt.h"
#include "conf.h"
//#include "Profibus_dp.h"

typedef enum{
	Nil = 0U,
	Dout_Buf_Ptr1,
	Dout_Buf_Ptr2,
	Dout_Buf_Ptr3
}Dout_Buffer_Assignment;
typedef enum{
	Nil_ = 0U,
	Din_Buf_Ptr1,
	Din_Buf_Ptr2,
	Din_Buf_Ptr3
}Din_Buffer_Assignment;
typedef enum{
	D_Buffer = 0U,
	N_Buffer = 2U,
	U_Buffer = 4U,
	F_Buffer = 6U
}Dout_Buffer_type;

typedef enum{
	D = 3,
	N = 0b1100,
	U = 0b001100,
	F = 0b11000000
}Buffer_position;





Dout_Buffer_Assignment Get_Dout_Buffer_Assignment(Dout_Buffer_type);


uint8_t Fetch_Dout_buffer(void);
uint8_t Make_Din_buffer(void);

void DXOut_Handeler(void);
void DX_Get_Data(uint8_t* );
void Data_Exchange_CallBack(void/*uint8_t* , uint8_t* */);
void Put_Input_Data(uint8_t*);
void Get_Output_Data(uint8_t*);
#endif /* DATA_EXCHANGE_H_ */
