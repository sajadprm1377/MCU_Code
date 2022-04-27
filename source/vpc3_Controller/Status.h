
/*
 * Status.h
 *
 *  Created on: Oct 17, 2021
 *      Author: PC Khayam
 */

#ifndef STATUS_H_
#define STATUS_H_
#include "vpc3_drive.h"

typedef enum{
	 _12MBit    = 0000,
	 _6MBit     = 0001,
	 _3MBit     = 0010,
	 _1500KBit  = 0011,
	 _500kBit   = 0100,
	 _187500Bit = 0101,
	 _93750Bit  = 0110,
	 _45450Bit  = 0111,
	 _19200Bit  = 1000,
	 _9600Bit   = 1001,
	 AfterReset = 1111
}Baudrate_Val;

typedef enum {
	WAIT_PRM = 0,
	WAIT_CFG = 1,
	DATA_EXCH = 2,
	Not_possible = 3
}DP_State;

typedef enum E_WD_State{
	BAUD_SEARCH = 0,
	BAUD_CONTROL = 1,
	DP_CONTROL = 2,
	Notp_ossible = 3
}WD_State;

typedef enum E_Offline_PassiveIdel{
	offline = 0,
	PassiveIdel = 1
}Offline_PassiveIdel;

typedef enum E_Diag_Flag{
	fetched_by_DP_Master = 0,
	Not_fetched_by_DP_Master = 1
}Diag_Flag;


	typedef union {
		uint8_t Byte[2];
		uint16_t Word;
	}Ident_Number;

	Baudrate_Val 		Get_Baudrate(void);
	WD_State 			Get_WD_state(void);
	DP_State 			Get_DP_state(void);
	Diag_Flag			Get_Diag_flag(void);
	Offline_PassiveIdel Passive_Idle_State(void);
	uint8_t Get_vpc3_Release(void);
	uint8_t Get_Slave_Address(void);
	uint16_t Get_interrupte_Reg(void);
	uint16_t Get_interrupte_Req_Reg(void);
	uint16_t Get_Ident_Number(void);

#endif /* STATUS_H_ */

