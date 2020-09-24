#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	
	WDTCTL = WDT_ADLY_1000;                     // 1 second interval
	IE1 |= WDTIE;                               // wdtie interrupts
	_EINT();                                    // enable interrupts
	P2DIR |= BIT2;                              // set port 2 as output

	P1IE |= 0x03;                               //
	P1IFG &= ~0x03;                             // reset interrupt flag
	P3SEL |= BIT5;                              // select special button
	P3DIR |= BIT5;                              // set the output for the buzzer

	TB0CCR0 = 500;                              // pitch
	TB0CCTL4 = OUTMOD_4;                        // TB0 output mode
	TB0CTL = TBSSEL_2 + MC_1;                   // clock source and mode
	P2OUT &= BIT2;



	_BIS_SR(LPM1_bits + GIE);                   // Enter LPM0 with interrupt
}


#pragma vector = WDT_VECTOR
__interrupt void watchdog_timer (void)
{
    P2OUT ^= BIT2;                              // alternate the state of the led
    P3DIR ^= BIT5;                              // alternate the state of the buzzer
}




















