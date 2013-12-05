/*
 * SensorLibrary.c
 *
 *  Created on: Dec 5, 2013
 *      Author: C15Kevin.Cooper
 */

#define FALSE 0
#define TRUE 1

//P1.5 - A5
char isRightClose()
{
	  ADC10CTL1 = INCH_5;                       // input A5
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
	  ADC10CTL1 = INCH_4;                       // input A5
	  ADC10AE0 |= BIT4;                         // PA.1 ADC option select
	  ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;       // Select SMCLK
	  ADC10CTL0 |= ENC + ADC10SC;				// Sampling and conversion start
	  if (ADC10MEM < 0x1FF){
		  return TRUE;
	  }else{
		  return FALSE;
	  }
}
