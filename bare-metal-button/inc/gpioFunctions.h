#ifndef GPIOFUNCTIONS_H_
#define GPIOFUNCTIONS_H_

#include "gpioLED.h"

void ledInit(int nGpio, int direction);
void Delay(volatile unsigned int count);
int getValue(unsigned int nGpio);

#endif //GPIOFUNCTIONS_H_