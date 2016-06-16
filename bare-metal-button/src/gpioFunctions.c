/*******************************************************
*                                                      *
*   Criado em: Sáb 11/Jun/2016,  13:48 hs              *
*   Instituicao: Universidade Federal do Ceará         *
*   Autor: Iago O. Lima                                *
*   email: iago.oliveira@alu.ufc.br                    *
*                                                      *
********************************************************/

#include "gpioFunctions.h"
#include "gpioLED.h"
#include "gpioClk.h"	

void ledInit(int nPin, int direction){
	int aux;
    GPIO1_ModuleClkConfig();
	
	switch(nPin){
        
        case GPIO1_0 ... GPIO1_7 :
	        GPIOPinMuxSetup(CONTROL_CONF_GPMC_AD(nPin), CONTROL_CONF_MUXMODE(7));		
			break;

        case GPIO1_8:
        	GPIOPinMuxSetup(CONTROL_CONF_UART_CTSN(0), CONTROL_CONF_MUXMODE(7));
        	break;

        case GPIO1_9:
        	GPIOPinMuxSetup(CONTROL_CONF_UART_RTSN(0), CONTROL_CONF_MUXMODE(7));
        	break;
    		
           case GPIO1_10:
        	GPIOPinMuxSetup(CONTROL_CONF_UART_RXD(0), CONTROL_CONF_MUXMODE(7));
        	break;
    		
        case GPIO1_11:
        	GPIOPinMuxSetup(CONTROL_CONF_UART_TXD(0), CONTROL_CONF_MUXMODE(7));
        	break;

        case GPIO1_12 ... GPIO1_15:
		    GPIOPinMuxSetup(CONTROL_CONF_GPMC_AD(nPin), CONTROL_CONF_MUXMODE(7));	
			break;

		case GPIO1_16 ... GPIO1_27:
			aux = nPin - 16;
	        GPIOPinMuxSetup(CONTROL_CONF_GPMC_A(aux), CONTROL_CONF_MUXMODE(7));
			break;
		
		case GPIO1_28:
       		GPIOPinMuxSetup(CONTROL_CONF_GPMC_BE1N, CONTROL_CONF_MUXMODE(7));
   			break;
		
		case GPIO1_29 ... GPIO1_31:
			aux = nPin-29;
    		GPIOPinMuxSetup(CONTROL_CONF_GPMC_CSN(aux), CONTROL_CONF_MUXMODE(7));
			break;
}
		
	/* Enabling the GPIO module. */
    GPIOModuleEnable(GPIO_INSTANCE_ADDRESS);

    /* Resetting the GPIO module. */
    GPIOModuleReset(GPIO_INSTANCE_ADDRESS);

    /* Setting the GPIO pin as an output pin. */
    GPIODirModeSet(GPIO_INSTANCE_ADDRESS, GPIO_INSTANCE_PIN_NUMBER(pin),
				  direction);
}

void Delay(volatile unsigned int count){
    while(count--);
      asm("   nop");
}


int getValue(unsigned int nGpio){
	int *end_valor = (int*)(GPIO_INSTANCE_ADDRESS + GPIO_DATAIN);
	int valorpin = *end_valor;
	
	if(valorpin & (1<<nGpio)) return PIN_HIGH;
	else return PIN_LOW;
}
