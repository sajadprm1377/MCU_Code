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
typedef enum{
	IDLE,
	INT_HAMDLE
}PROFIBUS_SM;

void vpc3_Initial(void);

void vpc3_Interrupt_Handler(void);
	//  Set_EOI();
	 /* Clear pin flags */
void MCU_Interrupt_Handler(void);

void Baudrate_ident_Callback(void);
void S_Go_Leave_DATA_EXCH_Callback(void);
void Diag_Buffer_Changed_Callback(void);

status_t PROFIBUS_manager(uint8_t*, uint8_t*);


#endif /* PROFIBUS_DP_H_ */
