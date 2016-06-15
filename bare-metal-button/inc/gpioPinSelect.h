#ifndef GPIOPINSELECT_H_
#define GPIOPINSELECT_H_


#include "gpioLED.h"
#include "gpioFunctions.h"

void selectUART(int nGpio);
void selectCSN(int nGpio);
void selectMII(int nGpio);
void selectXDMA(int nGpio);
void selectMDIO(int nGpio);
void selectSPI0(int nGpio);
void selectGPMC(int nGpio);
void selectMII1RXD(int nGpio);
void selectLCD(int nGpio);
void selectMMC0(int nGpio);
void selectMII1(int nGpio);
void selectI2C0(int nGpio);
void selectMCASPO(int nGpio);

#endif //GPIOPINSELECT_H_
