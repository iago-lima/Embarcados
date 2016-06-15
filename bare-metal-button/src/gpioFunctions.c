/*******************************************************
*                                                      *
*   Criado em: Seg 13/Jun/2016,  08:03 hs              *
*   Instituicao: Universidade Federal do Ceará         *
*   Autor: Robert Cabral                               *
*   email: robertcabral@alu.ufc.br                     *
*                                                      *
********************************************************/

#include "gpioFunctions.h"
#include "gpioLED.h"
#include "gpioClk.h"
#include "gpioPinSelect.h"

void ledInit(int nGpio, int GPIOModule){

    gpioModuleClk(GPIOModule);
	
	//CONFIGURAR O PINO gpioPinSelect.c
/*	switch(GPIOModule){
		case MODULE0:
			modulo0(nGpio);			
			break;
		case MODULE1:
			modulo1(nGpio);
			break;
		case MODULE2:
			modulo2(nGpio);
			break;
		case MODULE3:
			modulo3(nGpio);
			break;
	}
  */ 
    GPIOPinMuxSetup0(CONTROL_CONF_GPMC_AD(12), CONTROL_CONF_MUXMODE(7));
    GPIOPinMuxSetup(CONTROL_CONF_GPMC_A(7), CONTROL_CONF_MUXMODE(7));	

	
 
    GPIOModuleEnable(GPIO_INSTANCE_ADDRESS(GPIOModule));

    GPIOModuleReset(GPIO_INSTANCE_ADDRESS(GPIOModule));

    GPIODirModeSet(GPIO_INSTANCE_ADDRESS(1),
               GPIO_INSTANCE_PIN_NUMBER(23),
               DIR_OUTPUT);    

    GPIODirModeSet(GPIO_INSTANCE_ADDRESS(1),
               GPIO_INSTANCE_PIN_NUMBER(12),
               DIR_INPUT);

}


void modulo0(int nGpio){
	int num = 0;
	switch(nGpio){
		case GPIO0 ... GPIO1:
		selectMDIO(nGpio);
		break;

		case GPIO2 ... GPIO6:
		selectSPI0(nGpio);
		break;
				
		case GPIO7:
		GPIOPinMuxSetup(CONTROL_CONF_ECAP0_IN_PWM0_OUT, CONTROL_CONF_MUXMODE(7));
		break;

		case GPIO8 ... GPIO11:
		num = nGpio + 4;
		GPIOPinMuxSetup(CONTROL_CONF_LCD_DATA(num), CONTROL_CONF_MUXMODE(7));	
		break;

		case GPIO12 ... GPIO15:
		selectUART(nGpio);
		break;

		case GPIO16:
		selectMII(nGpio);
		break;

		case GPIO17: 
		selectMII(nGpio);
		break;

		case GPIO21:
		selectMII(nGpio);
		break;

		case GPIO28:
		selectMII(nGpio);
		break;

		case GPIO22 ... GPIO23:
		num = nGpio - 14;
		GPIOPinMuxSetup(CONTROL_CONF_GPMC_AD(num), CONTROL_CONF_MUXMODE(7));
		break;

		case GPIO26 ... GPIO27:
		num = nGpio - 16;
		GPIOPinMuxSetup(CONTROL_CONF_GPMC_AD(num), CONTROL_CONF_MUXMODE(7));
		break;

		case GPIO18:
		GPIOPinMuxSetup(CONTROL_CONF_USB_DRVVBUS(0), CONTROL_CONF_MUXMODE(7));	
		break;

		case GPIO19 ... GPIO20:
		selectXDMA(nGpio);
		break;

		case GPIO29:
		GPIOPinMuxSetup(CONTROL_CONF_RMII1_REFCLK, CONTROL_CONF_MUXMODE(7));
		break;

		case GPIO30:
		GPIOPinMuxSetup(CONTROL_CONF_GPMC_WAIT0, CONTROL_CONF_MUXMODE(7));
		break;

		case GPIO31:
		GPIOPinMuxSetup(CONTROL_CONF_GPMC_WPN, CONTROL_CONF_MUXMODE(7));
		break;
		
	}
}

void modulo1(int nGpio){
	int num = 0;
	switch(nGpio){
		case GPIO0 ... GPIO7:
        GPIOPinMuxSetup(CONTROL_CONF_GPMC_AD(nGpio), CONTROL_CONF_MUXMODE(7));		
		break;

		case GPIO12 ... GPIO15:
        GPIOPinMuxSetup0(CONTROL_CONF_GPMC_AD(nGpio), CONTROL_CONF_MUXMODE(7));
	    GPIOPinMuxSetup(CONTROL_CONF_GPMC_A(7), CONTROL_CONF_MUXMODE(7));	
		break;

		case GPIO8 ... GPIO11:
		selectUART(nGpio);
		break;
		
		case GPIO16 ... GPIO27:
		num = nGpio - 16;
        GPIOPinMuxSetup(CONTROL_CONF_GPMC_A(num), CONTROL_CONF_MUXMODE(7));
		break;

		case GPIO28:
		GPIOPinMuxSetup(CONTROL_CONF_GPMC_BE1N, CONTROL_CONF_MUXMODE(7));
		break;
		
		case GPIO29 ... GPIO31:
		selectCSN(nGpio);
		break;
	}
}

void modulo2(int nGpio){
	int num = 0;
	switch(nGpio){
		case GPIO0 ... GPIO5:
		selectGPMC(nGpio);
		break;
		
		case GPIO6 ... GPIO17:
		num = nGpio - 6;
        GPIOPinMuxSetup(CONTROL_CONF_LCD_DATA(num), CONTROL_CONF_MUXMODE(7));
		break;

		case GPIO18 ... GPIO21:
		num = nGpio - 18;
        selectMII1RXD(nGpio);
		break;
		
		case GPIO22 ... GPIO25:
        selectLCD(nGpio);
		break;

		case GPIO26 ... GPIO31:
		selectMMC0(nGpio);
		break;
	}

}

void modulo3(int nGpio){
	switch(nGpio){
		case GPIO0 ... GPIO4:
		selectMII1(nGpio);
		break;
	
		case GPIO9 ... GPIO10:
		selectMII1(nGpio);
		break;

		case GPIO5 ... GPIO6:
		selectI2C0(nGpio);
		break;
	
		case GPIO7 ... GPIO8:
		GPIOPinMuxSetup(CONTROL_CONF_EMU(0), CONTROL_CONF_MUXMODE(7));
		break;

		case GPIO13:
		GPIOPinMuxSetup(CONTROL_CONF_USB_DRVVBUS(1), CONTROL_CONF_MUXMODE(7));
		break;

		case GPIO14 ... GPIO21:
        selectMCASPO(nGpio);
		break;
	}

}
