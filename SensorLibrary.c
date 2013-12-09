/*
 * SensorLibrary.c
 *
 *  Created on: Dec 5, 2013
 *      Author: C15Kevin.Cooper
 */
#define FALSE 0
#define TRUE 1
#include <msp430.h>

//P1.4 - A5
char isCenterClose()
{
	  ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	  ADC10CTL1 = INCH_4;                       // input A4
	  ADC10AE0 |= BIT4;                         // PA.1 ADC option select
	  ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;                // Select SMCLK
	  //P1DIR |= 0x01;                            // Set P1.0 to output direction

	  for (;;)
	  {
	    ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	    __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit
	    if (ADC10MEM < 0x1FF)
	      return TRUE;                       // Clear P1.0 LED off
	    else
	      return FALSE;                        // Set P1.0 LED on
	  }
}
//P1.5 - A4
char isRightClose()
{
	//ADC10CTL0 &= ~ENC;
	  ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	  ADC10CTL1 = INCH_5;                       // input A4
	  ADC10AE0 |= BIT5;                         // PA.1 ADC option select
	  ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;                // Select SMCLK
	  //P1DIR |= 0x01;                            // Set P1.0 to output direction

	  for (;;)
	  {
	    ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	    __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit
	    if (ADC10MEM < 0x1FF)
	      return TRUE;                       // Clear P1.0 LED off
	    else
	      return FALSE;                        // Set P1.0 LED on
	  }
}

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
	__bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}

