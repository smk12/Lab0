/*
* File:   initLab0.c
// Date:         2/6/2015
// Authors:      Sean Kenney - smk12
* Created on December 27, 2014, 1:31 PM
*/

#include "p24fj64ga002.h"
#include "initLab0.h"

#define FCY 14745600.0
#define ONE_MILLISECOND 57
#define TIME_DELAY 2

void initLEDs()
{

    TRISBbits.TRISB15 = 0;
    TRISBbits.TRISB14 = 0;
    TRISBbits.TRISB13 = 0;
    TRISBbits.TRISB12 = 0;

    LATBbits.LATB15 = OFF;
    LATBbits.LATB14 = OFF;
    LATBbits.LATB13 = OFF;
    LATBbits.LATB12 = OFF;

}

void initSW1()
{
    /* Initialize the pin on the development board to be an input. According to
     * the datasheet, this is RB5 or pin 14
     */
    TRISBbits.TRISB5 = 1;

    //Put the overall CN Interrupt flag down (set it to 0)
    IFS1bits.CNIF = 0;

    //Enable the overall change notification interrupt
    IEC1bits.CNIE = 1;

    /* Enable the change notification interrupt for the switch 1 connected to
     * the development board. This corresponds to CN27 according to the PIC24F
     * datasheet. The internal pull-up should not be used for the switch
     * on the development board because one is already there.
     */
    CNEN2bits.CN27IE = 1;
}


void initTimer1()
{
    //TODO: Initialize the timer
    unsigned int prVal = (FCY*TIME_DELAY)/256.0 - 1;
    PR1 = prVal;
    T1CONbits.TCKPS = 0b11; //prescalar 256
    IEC0bits.T1IE = 1; // Enable the interrupt
    IFS0bits.T1IF = 0; // Put the interrupt flag down
    T1CONbits.TON = 0;
}

void turnOnLED(int led){
    if(led == 4){
        LATBbits.LATB15 = ON;
        LATBbits.LATB14 = OFF;
        LATBbits.LATB13 = OFF;
        LATBbits.LATB12 = OFF;
    }
    else if(led == 5){
        LATBbits.LATB15 = OFF;
        LATBbits.LATB14 = ON;
        LATBbits.LATB13 = OFF;
        LATBbits.LATB12 = OFF;
    }
    else if(led == 6){
        LATBbits.LATB15 = OFF;
        LATBbits.LATB14 = OFF;
        LATBbits.LATB13 = ON;
        LATBbits.LATB12 = OFF;
    }
    else if(led == 7){
        LATBbits.LATB15 = OFF;
        LATBbits.LATB14 = OFF;
        LATBbits.LATB13 = OFF;
        LATBbits.LATB12 = ON;
    }
}
