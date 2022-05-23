/*
 * Slave_Diag.h
 *
 *  Created on: Jan 31, 2022
 *      Author: Sajjad Prm
 */

#ifndef PROFIBUS_DPV0_SLAVE_DIAG_H_
#define PROFIBUS_DPV0_SLAVE_DIAG_H_
#include "vpc3_Controller/Status.h"
#include "vpc3_Controller/RAM_Config.h"
#include "vpc3_Controller/Interrupt.h"


void Diag_Buffer_Handle(void);

void Read_Diagnosis_Buffer(uint8_t*);

#endif /* PROFIBUS_DPV0_SLAVE_DIAG_H_ */
