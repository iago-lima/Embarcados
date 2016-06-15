/*******************************************************
*                                                      *
*   Criado em: Seg 13/Jun/2016,  08:29 hs              *
*   Instituicao: Universidade Federal do Ceará         *
*   Autor: Robert Cabral                               *
*   email: robertcabral@alu.ufc.br                     *
*                                                      *
********************************************************/

#include "gpioLED.h"
#include "gpioFunctions.h"

void selectUART(int nGpio){
    switch(nGpio){
//MODULO 1
        case GPIO8:
            GPIOPinMuxSetup(CONTROL_CONF_UART_CTSN(0), CONTROL_CONF_MUXMODE(7));
            break;
        case GPIO9:
            GPIOPinMuxSetup(CONTROL_CONF_UART_RTSN(0), CONTROL_CONF_MUXMODE(7));        
            break;
        case GPIO10:
            GPIOPinMuxSetup(CONTROL_CONF_UART_RXD(0), CONTROL_CONF_MUXMODE(7));
            break;
        case GPIO11:
            GPIOPinMuxSetup(CONTROL_CONF_UART_TXD(0), CONTROL_CONF_MUXMODE(7));
            break;
//FIM MODULO 1

//MODULO 0
		  case GPIO12:
            GPIOPinMuxSetup(CONTROL_CONF_UART_CTSN(1), CONTROL_CONF_MUXMODE(7));
				break;
		  case GPIO13:
				GPIOPinMuxSetup(CONTROL_CONF_UART_RTSN(1), CONTROL_CONF_MUXMODE(7));
				break;
		  case GPIO14:
            GPIOPinMuxSetup(CONTROL_CONF_UART_RXD(1), CONTROL_CONF_MUXMODE(7));
				break;
		  case GPIO15:
            GPIOPinMuxSetup(CONTROL_CONF_UART_TXD(1), CONTROL_CONF_MUXMODE(7));			
				break;
//FIM MODULO 0

    }
}

//MODULO 1
void selectCSN(int nGpio){
    switch(nGpio){
        case GPIO29:
            GPIOPinMuxSetup(CONTROL_CONF_GPMC_CSN(0), CONTROL_CONF_MUXMODE(7));
            break;
        case GPIO30:
            GPIOPinMuxSetup(CONTROL_CONF_GPMC_CSN(1), CONTROL_CONF_MUXMODE(7));
            break;
        case GPIO31:
            GPIOPinMuxSetup(CONTROL_CONF_GPMC_CSN(2), CONTROL_CONF_MUXMODE(7));
            break;
    }    
}

// MODULO 0
void selectMII(int nGpio){
	switch(nGpio){
		case GPIO16:
			GPIOPinMuxSetup(CONTROL_CONF_MII1_TXD3, CONTROL_CONF_MUXMODE(7));
			break;
		case GPIO17:
			GPIOPinMuxSetup(CONTROL_CONF_MII1_TXD2, CONTROL_CONF_MUXMODE(7));
			break;
		case GPIO21:
			GPIOPinMuxSetup(CONTROL_CONF_MII1_TXD1, CONTROL_CONF_MUXMODE(7));
			break;
		case GPIO28:
			GPIOPinMuxSetup(CONTROL_CONF_MII1_TXD0, CONTROL_CONF_MUXMODE(7));
			break;
	}
	
}


//MODULO 0
void selectXDMA(int nGpio){
	switch(nGpio){
		case GPIO19:
			GPIOPinMuxSetup(CONTROL_CONF_XDMA_EVENT_INTR(0), CONTROL_CONF_MUXMODE(7));
			break;
		case GPIO20:
			GPIOPinMuxSetup(CONTROL_CONF_XDMA_EVENT_INTR(1), CONTROL_CONF_MUXMODE(7));
			break;
	}
}


//MODULO 0
void selectMDIO(int nGpio){
	switch(nGpio){
		case GPIO0:
			GPIOPinMuxSetup(CONTROL_CONF_MDIO_DATA, CONTROL_CONF_MUXMODE(7));
			break;
		case GPIO1:
			GPIOPinMuxSetup(CONTROL_CONF_MDIO_CLK, CONTROL_CONF_MUXMODE(7));
			break;
	}
}


//MODULO 0
void selectSPI0(int nGpio){
	switch(nGpio){
		case GPIO2:
			GPIOPinMuxSetup(CONTROL_CONF_SPI0_SCLK, CONTROL_CONF_MUXMODE(7));
			break;
		case GPIO3:
			GPIOPinMuxSetup(CONTROL_CONF_SPI0_D0, CONTROL_CONF_MUXMODE(7));
			break;
		case GPIO4:
			GPIOPinMuxSetup(CONTROL_CONF_SPI0_D1, CONTROL_CONF_MUXMODE(7));
			break;
		case GPIO5:
			GPIOPinMuxSetup(CONTROL_CONF_SPI0_CS0, CONTROL_CONF_MUXMODE(7));
			break;
		case GPIO6:
			GPIOPinMuxSetup(CONTROL_CONF_SPI0_CS1, CONTROL_CONF_MUXMODE(7));
			break;
	}
}

//MODULO 2
void selectGPMC(int nGpio){
    switch(nGpio){
        case GPIO0:
            GPIOPinMuxSetup(CONTROL_CONF_GPMC_CSN(3), CONTROL_CONF_MUXMODE(7));
        break;

        case GPIO1:
            GPIOPinMuxSetup(CONTROL_CONF_GPMC_CLK, CONTROL_CONF_MUXMODE(7));
        break;

        case GPIO2:
            GPIOPinMuxSetup(CONTROL_CONF_GPMC_ADVN_ALE, CONTROL_CONF_MUXMODE(7));
        break;
        
        case GPIO3:
            GPIOPinMuxSetup(CONTROL_CONF_GPMC_OEN_REN, CONTROL_CONF_MUXMODE(7));
        break;
        
        case GPIO4:
            GPIOPinMuxSetup(CONTROL_CONF_GPMC_WEN, CONTROL_CONF_MUXMODE(7));
        break;
        
        case GPIO5:
            GPIOPinMuxSetup(CONTROL_CONF_GPMC_BE0N_CLE, CONTROL_CONF_MUXMODE(7));
        break;
    }
}

//MODULO 2
void selectMII1RXD(int nGpio){
    switch(nGpio){
        case GPIO18:
            GPIOPinMuxSetup(CONTROL_CONF_MII1_RXD3, CONTROL_CONF_MUXMODE(7));
        break;

        case GPIO19:
            GPIOPinMuxSetup(CONTROL_CONF_MII1_RXD2, CONTROL_CONF_MUXMODE(7));
        break;

        case GPIO20:
            GPIOPinMuxSetup(CONTROL_CONF_MII1_RXD1, CONTROL_CONF_MUXMODE(7));
        break;
        
        case GPIO21:
            GPIOPinMuxSetup(CONTROL_CONF_MII1_RXD0, CONTROL_CONF_MUXMODE(7));
        break;
    }
}

//MODULO 2
void selectLCD(int nGpio){
    switch(nGpio){
        case GPIO22:
            GPIOPinMuxSetup(CONTROL_CONF_LCD_VSYNC, CONTROL_CONF_MUXMODE(7));
        break;

        case GPIO23:
            GPIOPinMuxSetup(CONTROL_CONF_LCD_HSYNC, CONTROL_CONF_MUXMODE(7));
        break;

        case GPIO24:
            GPIOPinMuxSetup(CONTROL_CONF_LCD_PCLK, CONTROL_CONF_MUXMODE(7));
        break;

        case GPIO25:
            GPIOPinMuxSetup(CONTROL_CONF_LCD_AC_BIAS_EN, CONTROL_CONF_MUXMODE(7));
        break;
    }
}

//MODULO 2
void selectMMC0(int nGpio){
    switch(nGpio){
        case GPIO26:
            GPIOPinMuxSetup(CONTROL_CONF_MMC0_DAT3 , CONTROL_CONF_MUXMODE(7));
        break;

        case GPIO27:
            GPIOPinMuxSetup(CONTROL_CONF_MMC0_DAT2 , CONTROL_CONF_MUXMODE(7));
        break;

        case GPIO28:
            GPIOPinMuxSetup(CONTROL_CONF_MMC0_DAT1, CONTROL_CONF_MUXMODE(7));
        break;
        
        case GPIO29:
            GPIOPinMuxSetup(CONTROL_CONF_MMC0_DAT0 , CONTROL_CONF_MUXMODE(7));
        break;
        
        case GPIO30:
            GPIOPinMuxSetup(CONTROL_CONF_MMC0_CLK, CONTROL_CONF_MUXMODE(7));
        break;
        
        case GPIO31:
            GPIOPinMuxSetup(CONTROL_CONF_MMC0_CMD, CONTROL_CONF_MUXMODE(7));
        break;
    }
}

//MODULO 3
void selectMII1(int nGpio){
    switch(nGpio){
        case GPIO0:
            GPIOPinMuxSetup(CONTROL_CONF_MII1_COL, CONTROL_CONF_MUXMODE(7));
        break;

        case GPIO1:
            GPIOPinMuxSetup(CONTROL_CONF_MII1_CRS , CONTROL_CONF_MUXMODE(7));
        break;

        case GPIO2:
            GPIOPinMuxSetup(CONTROL_CONF_MII1_RXERR, CONTROL_CONF_MUXMODE(7));
        break;
        
        case GPIO3:
            GPIOPinMuxSetup(CONTROL_CONF_MII1_TXEN, CONTROL_CONF_MUXMODE(7));
        break;
        
        case GPIO4:
            GPIOPinMuxSetup(CONTROL_CONF_MII1_RXDV, CONTROL_CONF_MUXMODE(7));
        break;

        case GPIO9:
            GPIOPinMuxSetup(CONTROL_CONF_MII1_TXCLK, CONTROL_CONF_MUXMODE(7));
        break;

        case GPIO10:
            GPIOPinMuxSetup(CONTROL_CONF_MII1_RXCLK, CONTROL_CONF_MUXMODE(7));
        break;
    }
}

//MODULO 3
void selectI2C0(int nGpio){
    switch(nGpio){
        case GPIO7:
            GPIOPinMuxSetup(CONTROL_CONF_I2C0_SDA, CONTROL_CONF_MUXMODE(7));
        break;

        case GPIO8:
            GPIOPinMuxSetup(CONTROL_CONF_I2C0_SCL, CONTROL_CONF_MUXMODE(7));
        break;

    }
}

//MODULO 3
void selectMCASPO(int nGpio){
    switch(nGpio){
        case GPIO14:
            GPIOPinMuxSetup(CONTROL_CONF_MCASP0_ACLKX, CONTROL_CONF_MUXMODE(7));
        break;

        case GPIO15:
            GPIOPinMuxSetup( CONTROL_CONF_MCASP0_FSX, CONTROL_CONF_MUXMODE(7));
        break;

        case GPIO16:
            GPIOPinMuxSetup(CONTROL_CONF_MCASP0_AXR0, CONTROL_CONF_MUXMODE(7));
        break;
        
        case GPIO17:
            GPIOPinMuxSetup(CONTROL_CONF_MCASP0_AHCLKR, CONTROL_CONF_MUXMODE(7));
        break;
        
        case GPIO18:
            GPIOPinMuxSetup(CONTROL_CONF_MCASP0_ACLKR, CONTROL_CONF_MUXMODE(7));
        break;

        case GPIO19:
            GPIOPinMuxSetup(CONTROL_CONF_MCASP0_FSR, CONTROL_CONF_MUXMODE(7));
        break;

        case GPIO20:
            GPIOPinMuxSetup(CONTROL_CONF_MCASP0_AXR1, CONTROL_CONF_MUXMODE(7));
        break;

        case GPIO21:
            GPIOPinMuxSetup(CONTROL_CONF_MCASP0_AHCLKX, CONTROL_CONF_MUXMODE(7));
        break;
    }
}

