#ifndef GPIOLED_H_
#define GPIOLED_H_

/*
 * =====================================================================================
 *
 *       Filename:  gpioLED.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/05/2016 20:03:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Francisco Helder (), helderhdw@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "hw_control_AM335x.h"
#include "soc_AM335x.h"
#include "hw_cm_wkup.h"
#include "hw_gpio_v2.h"
#include "beaglebone.h"
#include "hw_cm_per.h"
#include "hw_types.h"


/* This is used to configure a GPIO pin as an input pin. */
#define DIR_INPUT                1
/* This is used to configure a GPIO pin as an output pin.*/
#define DIR_OUTPUT               0

/* This is used to write a logic 0 to a pin.*/
#define PIN_LOW                  0

/* This is used to write a logic 1 to a pin.*/
#define PIN_HIGH                 1


#define GPIO_INSTANCE_ADDRESS           (SOC_GPIO_1_REGS)
#define GPIO_INSTANCE_PIN_NUMBER(n)        (n)
#define TOGGLE                          (0x01u)

typedef enum Pinos pinos;

enum pinos{GPIO0, GPIO1, GPIO2, GPIO3, GPIO4, GPIO5, GPIO6, GPIO7,
  GPIO8, GPIO9, GPIO10, GPIO11, GPIO12, GPIO13, GPIO14, GPIO15,
  GPIO16, GPIO17, GPIO18, GPIO19, GPIO20, GPIO21, GPIO22, GPIO23,
  GPIO24, GPIO25, GPIO26, GPIO27, GPIO28, GPIO29, GPIO30, GPIO31};


int ledInit();
void ledToggle();


#endif //GPIOLED_H_

