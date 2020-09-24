#include <msp430.h> 
#define SW1 (P1IN&BIT0)
#define SW2 (P1IN&BIT1)

int x = 1;

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;                                           // stop watchdog timer
	P2DIR |= BIT2;              										// P2.2 set up as output
	_EINT();                    										// enable interrupts

	P1IE |= BIT0 + BIT1;                                                // set up interrupts from port 1
	P1IES |= BIT0 + BIT1;
	P1IFG &= ~(BIT0 + BIT1);

	TB0CCTL0 = CCIE;            										// TB0 count triggers interrupt
	TB0CCR0 = 1000;             										// Set TB0 (and maximum) count value
	TB0CCTL1 = CCIE;            										// TB1 count triggers interrupt
	TB0CCR1 = 100;              										// value for led brightness

	TB0CTL = TBSSEL_2 + MC_1;   										// SMCLK is clock source, UP mode

	_BIS_SR(LPM0);              										// Low power mode 0
	
	return 0;
}


#pragma vector = PORT1_VECTOR
__interrupt void PORT1_ISR(void)
{
    P1IFG &= ~(BIT0 + BIT1);                                            // clear flags
    unsigned long int i = 0;

                                                                        // make led brighter
    if ((SW1) == 0)                                                     // if switch 1 is pressed
    {
        for (i = 0; i < 2000; i++);                                     // Debounce 20 ms
        if ((SW1) == 0)
        {
            x++;
        }
    }

                                                                        
    if ((SW2) == 0)
    {
        for (i = 0; i < 2000; i++);                                     // Debounce ~20 ms
        if ((SW2) == 0)
        {
            x--;
        }
    }

    if (x <= 1)
    {
        x = 1;
        TB0CCR1 = 100;          										// set to 10%
    }
    else if(x == 2)
        TB0CCR1 = 250;          										// set to 25%
    
    else if (x == 3)
    	TB0CCR1 = 500;          										// set to 50%
    
    else if (x == 4)
        TB0CCR1 = 750;          										// set to 75%
    
    else if (x >= 5)
    {
        x = 5;
        TB0CCR1 = 900;          										// set to max
    }

}


#pragma vector = TIMERB0_VECTOR
__interrupt void timerISR(void)
{
    P2OUT |= BIT2;              										// set P2.2 (led)
}
#pragma vector = TIMERB1_VECTOR
__interrupt void timerISR2(void)
{
    P2OUT &= ~BIT2;              										// clear the led
    TBCCTL1 &= ~CCIFG;          										// clear interrupt flag
}

