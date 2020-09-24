#include <msp430.h> 

#define SW1 P1IN&BIT0
#define SW2 P1IN&BIT1

int x = 0;

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	                            // stop watchdog timer
	P2DIR |= BIT2 + BIT1;                                   // set bit 2 and 1 as output
	P2OUT = 0x04;
	FLL_CTL0 |= XCAP18PF;                                   // load capacitance
	SCFI0 &= ~FN_2;                                         // DCO range control
	SCFI0 &= ~FN_3;
	SCFI0 &= ~FN_4;
	SCFI0 &= ~FN_8;

	_EINT();                                                // enable interrupts
	P1IE |= BIT0;
	P1IES |= BIT0;                                          // hi/lo edge
	P1IFG &= ~BIT0;                                         // clear interrupt flag
	P1IE |= BIT1;
	P1IES |= BIT1;
	P1IFG &= ~BIT1;

	SCFQCTL = 14;                                           // 1MHz

	while(0==0)
	{
	    P2OUT |= BIT2;                                      // activate led 1
	    for(int i=0; i < 25000; i++);
	    P2OUT &= ~(BIT2);                                   // deactivate led 1
	    P2OUT |= BIT1;                                      // activate led 2
	    for(int i=0; i < 25000; i++);
	    P2OUT &= ~(BIT1);                                   // deactivate led 2

	}
}


#pragma vector = PORT1_VECTOR
__interrupt void PORT1_ISR (void)
{
    for(int i=0; i<2000; i++);

    if(!(P1IN & BIT0))                                      // if sw1 is pressed
    {
        if(x == 0)
        {
            SCFQCTL = (SCFQCTL + 1) * 2 - 1;                // double clk speed
            x++;                                            // increment x
        }
        else if(x == 1)
        {
            SCFQCTL = (SCFQCTL + 1) * 2 - 1;                // double clk speed
            x++;
        }
        else if(x == 2)
        {
            SCFQCTL = (SCFQCTL + 1) * 2 - 1;                // double clk speed
            x++;
        }
    }

    if(!(P1IN & BIT1) )                                     // if button 2 is pressed
    {
        if(x > 0)
        {
            SCFQCTL = (SCFQCTL + 1) / 2 - 1;                // divide clk speed by 2

        }
        if(x>0)
        {
            x--;                                            // decriment x
        }
    }

    SCFI0 &= ~FN_3;                                         // range control and return
    SCFI0 &= ~FN_4;
    SCFI0 &= ~FN_8;
    P1IES |= BIT0;
    P1IFG &= ~BIT0;
    P1IES |= BIT1;
    P1IFG &= ~BIT1;



}













