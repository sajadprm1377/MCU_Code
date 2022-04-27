/*
 * Port.h
 *
 *  Created on: Dec 2, 2021
 *      Author: PC Khayam
 */

#ifndef MCU_CONFIG_PORT_H_
#define MCU_CONFIG_PORT_H_

#include <stdio.h>
#include "peripherals.h"
#include "pin_mux.h"
#include "fsl_gpio.h"
#include "MKV31F12810.h"
#include "board.h"
#include "fsl_port.h"
#include "clock_config.h"
#include "fsl_dspi.h"


#define PIN_Reset 3U
#define GPIO_Reset GPIOD
#define PORT_Reset PORTD

#ifdef GPIOD_IRQHANDLER
#define PROFIBUS_Interrupt_Handler	GPIOD_IRQHANDLER
#endif

#ifdef GPIOA_IRQHANDLER

#define PROFIBUS_Interrupt_Handler	GPIOA_IRQHANDLER

#endif

#ifdef GPIOB_IRQHANDLER

#define PROFIBUS_Interrupt_Handler	GPIOB_IRQHANDLER

#endif

#ifdef GPIOA_IRQHANDLER

#define PROFIBUS_Interrupt_Handler	GPIOC_IRQHANDLER

#endif


void Config_Interrupt_PIN(PORT_Type*, GPIO_Type*, uint32_t);
void Config_Reset_PIN(PORT_Type*, GPIO_Type*, uint32_t);
void Config_Reset_PIN_Default(void);
void PIN_Config(void);
void GPIO_Set(GPIO_Type*, uint32_t);
void GPIO_Clear(GPIO_Type*, uint32_t);
#endif /* MCU_CONFIG_PORT_H_ */
