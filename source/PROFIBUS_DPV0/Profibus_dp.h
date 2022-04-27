/*
 * PROFIBUS_DP.h
 *
 *  Created on: Dec 1, 2021
 *      Author: PC Khayam
 */

#ifndef PROFIBUS_DP_H_
#define PROFIBUS_DP_H_

//#include "MCU_Cfg/Port.h"
#include "Chk_Cfg.h"
#include "Set_Prm.h"
#include "DATA_Exchange.h"
#include "Slave_Diag.h"
#include "conf.h"
//#define GPIOD_IRQHANDLER vpc3_Interrupt

typedef enum{
	first_DX,
	Normal_DX
}DX_ERR;

//typedef enum{
//	before_Startup,
//	after_Startup,
//	inside_loop
//}Profibus_State;

typedef enum{
	IDLE,
	INT_HAMDLE
}PROFIBUS_SM;



typedef struct{
	PORT_Type* port_Interrupt;
	GPIO_Type* gpio_Interrupt;
	uint32_t Pin_Interrupt;
}Interrupt_Pin_Config;

typedef struct{
	SPI_Type* SPI_Base_Addr;
	uint8_t Slave_Address;
	RAM_Size RAM_size;

}vpc3_specification;
void vpc3_Initial(void);

void vpc3_Interrupt_Handler(void);
	//  Set_EOI();
	 /* Clear pin flags */
void MKV31f_Interrupt_Handler(void);

void Baudrate_ident_Callback(void);
void S_Go_Leave_DATA_EXCH_Callback(void);
void Diag_Buffer_Changed_Callback(void);

//Profibus_State Get_profibus_state(void);
//void Set_profibus_state(Profibus_State);
status_t PROFIBUS_manager(uint8_t*, uint8_t*, uint16_t);


#endif /* PROFIBUS_DP_H_ */