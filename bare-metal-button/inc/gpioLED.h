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

enum moduleClk{MODULE1}moduleClk;

enum pin{
		GPIO1_0, GPIO1_1, GPIO1_2, GPIO1_3, GPIO1_4, GPIO1_5, GPIO1_6, GPIO1_7, GPIO1_8, 
		GPIO1_9, GPIO1_10, GPIO1_11, GPIO1_12, GPIO1_13, GPIO1_14, GPIO1_15, GPIO1_16, 
		GPIO1_17, GPIO1_18, GPIO1_19, GPIO1_20, GPIO1_21, GPIO1_22, GPIO1_23, GPIO1_24, 
		GPIO1_25, GPIO1_26, GPIO1_27, GPIO1_28, GPIO1_29, GPIO1_30, GPIO1_31
		}pin;

void ledToggle(int nGpio, int GPIOModule);
void GPIOPinMuxSetup(unsigned int offsetAddr, unsigned int padConfValue);
void GPIOPinMuxSetup0(unsigned int offsetAddr, unsigned int padConfValue);
void GPIOModuleEnable(unsigned int baseAdd);
void GPIOModuleReset(unsigned int baseAdd);
void GPIODirModeSet(unsigned int baseAdd, unsigned int pinNumber, unsigned int pinDirection
					);
void GPIOPinWrite(unsigned int baseAdd, unsigned int pinNumber, unsigned int pinValue);
void ledToggle();



#endif //GPIOLED_H_
