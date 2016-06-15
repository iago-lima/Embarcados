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


void GPIO1_ModuleClkConfig(void){

    HWREG(SOC_CM_PER_REGS + CM_PER_GPIO1_CLKCTRL) |=
          CM_PER_GPIO1_CLKCTRL_MODULEMODE_ENABLE;

    HWREG(SOC_CM_PER_REGS + CM_PER_GPIO1_CLKCTRL) |=
          CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_1_GDBCLK;

}


void gpioModuleClk(int moduleClk){

	switch(moduleClk){

			GPIO1_ModuleClkConfig();
	
  }

}
