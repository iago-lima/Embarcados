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
#define MSEG (0x3FFFFFF)
int main(){

	//INICIALIZANDO O LED DA PLACA, GPIO1_23
	ledInit(GPIO1_23, DIR_OUTPUT);
	//INICIALIZANDO O BOTÃO NO GPIO1_12, PASSANDO INPUT
	ledInit(GPIO1_12, DIR_INPUT);
	while(1){
		if (getValue(GPIO1_12) == 1){
			GPIOPinWrite(GPIO_INSTANCE_ADDRESS, GPIO_INSTANCE_PIN_NUMBER(23),
                		PIN_HIGH);
		}else{
			GPIOPinWrite(GPIO_INSTANCE_ADDRESS, GPIO_INSTANCE_PIN_NUMBER(23),
                		PIN_LOW);
		}
		Delay(MSEG);
		}
	}