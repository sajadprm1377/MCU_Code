/*
 * Port.c
 *
 *  Created on: Dec 2, 2021
 *      Author: PC Khayam
 */
#include "Port.h"
void Config_Interrupt_PIN(PORT_Type* P_Base, GPIO_Type* G_Base, uint32_t PIN){
	CLOCK_EnableClock(kCLOCK_PortD);
	gpio_pin_config_t X_INT_config = {
		.pinDirection = kGPIO_DigitalInput,
	    .outputLogic = 0U
	};
	/* Initialize GPIO functionality on pin PTD2 (pin 59)  */
	GPIO_PinInit(G_Base, PIN, &X_INT_config);

    /* PORTD2 (pin 59) is configured as PTD2 */
    PORT_SetPinMux(P_Base, PIN , kPORT_MuxAsGpio);
    /* Interrupt configuration on PORTD2 (pin 59): Interrupt on rising edge */
    PORT_SetPinInterruptConfig(P_Base, PIN, kPORT_InterruptRisingEdge);
    NVIC_SetPriority(GPIOD_IRQN, 2);
    EnableIRQ(GPIOD_IRQN);
}
void Config_Reset_PIN(PORT_Type* PORTx, GPIO_Type* GPIOx, uint32_t PIN){
	gpio_pin_config_t RESET_config = {
			.pinDirection = kGPIO_DigitalOutput,
		    .outputLogic = 0U
	};
	/* Initialize GPIO functionality on pin PTD3 (pin 60)  */
	GPIO_PinInit(GPIOx, PIN, &RESET_config);
	/* PORTD3 (pin 60) is configured as PTD3 */
	PORT_SetPinMux(PORTx, PIN, kPORT_MuxAsGpio);
}

void Config_Reset_PIN_Default(void){
	gpio_pin_config_t RESET_config = {
			.pinDirection = kGPIO_DigitalOutput,
		    .outputLogic = 0U
	};
	/* Initialize GPIO functionality on pin PTD3 (pin 60)  */
	GPIO_PinInit(GPIO_Reset, PIN_Reset, &RESET_config);
	/* PORTD3 (pin 60) is configured as PTD3 */
	PORT_SetPinMux(PORT_Reset, PIN_Reset, kPORT_MuxAsGpio);

}

void PIN_Config(void){
	/* Port D Clock Gate Control: Clock enabled */
	CLOCK_EnableClock(kCLOCK_PortD);






	/* PORTD4 (pin 61) is configured as SPI1_PCS0 */
	PORT_SetPinMux(PORTD, 4U, kPORT_MuxAlt7);

	/* PORTD5 (pin 62) is configured as SPI1_SCK */
	PORT_SetPinMux(PORTD, 5U, kPORT_MuxAlt7);

	/* PORTD6 (pin 63) is configured as SPI1_SOUT */
	PORT_SetPinMux(PORTD, 6U, kPORT_MuxAlt7);

	/* PORTD7 (pin 64) is configured as SPI1_SIN */
	PORT_SetPinMux(PORTD, 7U, kPORT_MuxAlt7);
}


void GPIO_Set(GPIO_Type* GPIOx, uint32_t Pin){
	GPIO_PortSet(GPIOx, 1<<Pin);
}
void GPIO_Clear(GPIO_Type* GPIOx, uint32_t Pin){
	GPIO_PortClear(GPIOx, 1<<Pin);
}
