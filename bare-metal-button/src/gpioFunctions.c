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
#include "gpioPinSelect.h"

void ledInit(int nGpio, int GPIOModule, int direction){

    gpioModuleClk(GPIOModule);
	
	switch(nGpio){
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
        case GPIO1_29:
            GPIOPinMuxSetup(CONTROL_CONF_GPMC_CSN(0), CONTROL_CONF_MUXMODE(7));
            break;
        case GPIO1_30:
            GPIOPinMuxSetup(CONTROL_CONF_GPMC_CSN(1), CONTROL_CONF_MUXMODE(7));
            break;
        case GPIO1_31:
            GPIOPinMuxSetup(CONTROL_CONF_GPMC_CSN(2), CONTROL_CONF_MUXMODE(7));
            break;
    }
		
		 
    GPIOModuleEnable(GPIO_INSTANCE_ADDRESS(GPIOModule));

    GPIOModuleReset(GPIO_INSTANCE_ADDRESS(GPIOModule));

    GPIODirModeSet(GPIO_INSTANCE_ADDRESS(GPIOModule), GPIO_INSTANCE_PIN_NUMBER(nGpio),
					direction);    

}


void modulo1(int nGpio){
	int num = 0;
	switch(nGpio){
		case GPIO1_0 ... GPIO1_7:
        GPIOPinMuxSetup(CONTROL_CONF_GPMC_AD(nGpio), CONTROL_CONF_MUXMODE(7));		
		break;

		case GPIO1_12 ... GPIO1_15:
	    GPIOPinMuxSetup(CONTROL_CONF_GPMC_A(7), CONTROL_CONF_MUXMODE(7));	
		break;

		case GPIO1_8 ... GPIO1_11:
		selectUART(nGpio);
		break;
		
		case GPIO1_16 ... GPIO1_27:
		num = nGpio - 16;
        GPIOPinMuxSetup(CONTROL_CONF_GPMC_A(num), CONTROL_CONF_MUXMODE(7));
		break;

		case GPIO1_28:
		GPIOPinMuxSetup(CONTROL_CONF_GPMC_BE1N, CONTROL_CONF_MUXMODE(7));
		break;
		
		case GPIO1_29 ... GPIO1_31:
		selectCSN(nGpio);
		break;
	}
}

void Delay(volatile unsigned int count){
    while(count--);
      asm("   nop");
}


int getValue(unsigned int nGpio, unsigned int nModule){
	int* end_teste = (int*)(GPIO_INSTANCE_ADDRESS(nModule) + GPIO_DATAIN);
	int teste = *end_teste;
	
	if(teste & (1<<nGpio)) return PIN_HIGH;
	else return PIN_LOW;
}
