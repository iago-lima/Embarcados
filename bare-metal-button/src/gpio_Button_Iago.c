/*******************************************************
*                                                      *
*   Criado em: Sáb 11/Jun/2016,  13:48 hs              *
*   Instituicao: Universidade Federal do Ceará         *
*   Autor: Robert Cabral                               *
*   email: robertcabral@alu.ufc.br                     *
*                                                      *
********************************************************/
#include "gpioFunctions.h"
#include "gpioLED.h"
#include "start.h"
#define MSEG                           (0x3FFFFFF)

static void Delay(volatile unsigned int count);
int getPin(int nGpio, int nModule);

int main(){

	ledInit(GPIO23, MODULE1);

	while(TRUE){
        
		if(getPin(GPIO12, MODULE1)){
			ledToggle(GPIO23, MODULE1);
		}

        Delay(MSEG);

    }
	

	return(0);

}

static void Delay(volatile unsigned int count){
    while(count--);
      asm("   nop");
}


int getPin(int nGpio, int nModule){
	int *end_teste = (GPIO_INSTANCE_ADDRESS(nModule) + GPIO_DATAIN);
	int teste = *end_teste;
	
	if(teste & (1<<nGpio)) return PIN_HIGH;
	else return PIN_LOW;
}
