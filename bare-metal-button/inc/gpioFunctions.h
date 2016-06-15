#ifndef GPIOFUNCTIONS_H_
#define GPIOFUNCTIONS_H_

#include "gpioLED.h"

void ledInit(int nGpio, int GPIOModule, int direction);
void modulo0(int nGpio);
void modulo1(int nGpio);
void modulo2(int nGpio);
void modulo3(int nGpio);
void Delay(volatile unsigned int count);
int getValue(unsigned int nGpio, unsigned int nModule);

#endif //GPIOFUNCTIONS_H_
