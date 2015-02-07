/* 
* File:   initLab0.h
// Date:         2/6/2015
// Authors:      Sean Kenney - smk12
* Created on December 27, 2014, 1:31 PM
*/

#ifndef INITLAB0_H
#define	INITLAB0_H


//Use defines for pin settings to make your code
#define LED4 LATBbits.LATB15
#define LED5 LATBbits.LATB14
#define LED6 LATBbits.LATB13
#define LED7 LATBbits.LATB12

#define OFF 1;
#define ON 0;
#define PRESSED 0
#define RELEASED 1

void initLEDs();
void initSW1();
void initTimer1();
void turnOnLED(int led);

#endif	/* INITLAB0_H */

