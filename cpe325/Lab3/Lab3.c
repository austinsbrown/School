/*------------------------------------------------------------------
* Instructor:  Austin Brown
* Program:     Links buttons to leds
* Date:        Sept 11, 2019
* Input:       None
* Output:      None
* Description: Links Button 1 to Led 1 and Button2 to Led 2
*-------------------------------------------------------------------*/

#include <msp430.h> 
#include <msp430xG46x.h>
#define SW1 P1IN&BIT0
#define SW2 P1IN&BIT1

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	                            // stop watchdog timer
	
	P2DIR |= BIT2 + BIT1;                                   // set LED1 and LED2 as the outputs
	P2OUT |= BIT1 + BIT2;                                   // turn them both on

	for(;;)
	{
	    if((SW1) == 0 & (SW2) != 0)                         //  true of switch 1 is pressed
	    {
	        while((SW1) == 0 & (SW2) !=0)
	        {
	            for(int i=0; i<10000; i++);                 // wait
	            P2OUT &= ~BIT2;                             // turn led off
	            for(int i=0; i<10000; i++);
	            P2OUT |= BIT2;
	        }
	    }

	    else if((SW2) == 0 & (SW1) == 0)                     // true if switch 2 is pressed
	    {
	        while((SW2) == 0 & (SW1) == 0)
	        {
	            for(long int i=0; i<50000; i++);            // wait
	            P2OUT &= ~(BIT1 + BIT2);                    // turn both lights off
	            for(long int i=0; i<50000; i++);
	            P2OUT |= BIT1 + BIT2;                       // turn them both on
	        }
	    }

	    else if((SW2) == 0 & (SW1) != 0)                    // true if switch 2 is pressed
	    {

	        while((SW2) == 0 & (SW1) != 0)
	        {
	            for(int i=0; i<25000; i++);                 // wait
	            P2OUT &= ~BIT1;                             // turn led 2 off
	            for(int i=0; i<25000; i++);
	            P2OUT |= BIT1;
	        }
	     }
	}
}







