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

int main(){

	//INICIALIZANDO O LED DA PLACA, GPIO1_23
	ledInit(GPIO1_23, MODULE1, DIR_OUTPUT);
	//INICIALIZANDO O BOTÃO NO GPIO1_14, PASSANDO INPUT
	ledInit(GPIO1_14, MODULE1, DIR_INPUT);

	while(TRUE){
        switch((getValue(GPIO1_14, MODULE1))){
			case PIN_HIGH:		
	        GPIOPinWrite(GPIO_INSTANCE_ADDRESS(MODULE1),
		            GPIO_INSTANCE_PIN_NUMBER(GPIO1_23),
			        PIN_HIGH);		
			case PIN_LOW:
			GPIOPinWrite(GPIO_INSTANCE_ADDRESS(MODULE1),
		            GPIO_INSTANCE_PIN_NUMBER(GPIO1_23),
			        PIN_LOW);		
		}
		
        Delay(MSEG);
    }
	
	return(0);
}
