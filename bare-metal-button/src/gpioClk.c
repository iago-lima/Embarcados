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

void GPIO3_ModuleClkConfig(void){

    HWREG(SOC_CM_PER_REGS + CM_PER_GPIO3_CLKCTRL) |=
          CM_PER_GPIO3_CLKCTRL_MODULEMODE_ENABLE;

    HWREG(SOC_CM_PER_REGS + CM_PER_GPIO3_CLKCTRL) |=
          CM_PER_GPIO3_CLKCTRL_OPTFCLKEN_GPIO_3_GDBCLK;

}

void GPIO2_ModuleClkConfig(void){

    HWREG(SOC_CM_PER_REGS + CM_PER_GPIO2_CLKCTRL) |=
          CM_PER_GPIO2_CLKCTRL_MODULEMODE_ENABLE;

    HWREG(SOC_CM_PER_REGS + CM_PER_GPIO2_CLKCTRL) |=
          CM_PER_GPIO2_CLKCTRL_OPTFCLKEN_GPIO_2_GDBCLK;

}

void GPIO1_ModuleClkConfig(void){

    HWREG(SOC_CM_PER_REGS + CM_PER_GPIO1_CLKCTRL) |=
          CM_PER_GPIO1_CLKCTRL_MODULEMODE_ENABLE;

    HWREG(SOC_CM_PER_REGS + CM_PER_GPIO1_CLKCTRL) |=
          CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_1_GDBCLK;

}


void GPIO0_ModuleClkConfig(void){

    HWREG(SOC_CM_WKUP_REGS + CM_WKUP_GPIO0_CLKCTRL) |=
          CM_WKUP_GPIO0_CLKCTRL_MODULEMODE_ENABLE;

    HWREG(SOC_CM_WKUP_REGS + CM_WKUP_GPIO0_CLKCTRL) |=
          CM_WKUP_GPIO0_CLKCTRL_OPTFCLKEN_GPIO0_GDBCLK;

}

void gpioModuleClk(int moduleClk){

	switch(moduleClk){
		case MODULE0:
			GPIO0_ModuleClkConfig();
			break;
		case MODULE1:
			GPIO1_ModuleClkConfig();
			break;
		case MODULE2:
			GPIO2_ModuleClkConfig();
			break;
		case MODULE3:
			GPIO3_ModuleClkConfig();
			break;
	}

}
