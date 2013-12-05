/*
 * SensorLibrary.c
 *
 *  Created on: Dec 5, 2013
 *      Author: C15Kevin.Cooper
 */
#define FALSE 0
#define TRUE 1
#include <msp430.h>
//P1.5 - A5
char isRightClose()
{
	  ADC10CTL0 &= ~ENC;
      ADC10CTL1 &= ~INCH_4;
	  ADC10CTL1 |= INCH_5;                       // input A5
	  ADC10AE0 |= BIT4;                         // PA.1 ADC option select
	  ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;       // Select SMCLK
	  ADC10CTL0 |= ENC + ADC10SC;				// Sampling and conversion start
	  if (ADC10MEM < 0x1FF){
		  return TRUE;
	  }else{
		  return FALSE;
	  }
}
//P1.4 - A4
char isCenterClose()
{
	  ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	  ADC10CTL1 = INCH_4;                       // input A4
	  ADC10AE0 |= BIT4;                         // PA.1 ADC option select
	  ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;                // Select SMCLK
	  ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	  __delay_cycles(64);
      __bis_SR_register(CPUOFF + GIE);
	  if (ADC10MEM < 0x1FF){
		  return TRUE;
	  }else{
		  return FALSE;
	  }
}

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}
