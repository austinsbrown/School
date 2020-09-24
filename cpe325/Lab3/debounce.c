/*------------------------------------------------------------------------------
 * File:        debounce.c
 * Description: This example demonstrates when debounce technique is
 *              is necessary and when it is not
 * Clocks:      ACLK = 32.768kHz, MCLK = SMCLK = default DCO (~1 MHz)
 * Author:      Igor Semenov, is0031@uah.edu
 *------------------------------------------------------------------------------*/
#include <msp430.h>

#define SW1_BIT BIT0
#define SW1_PRESSED ((P1IN & SW1_BIT) == 0)

#define SW2_BIT BIT1
#define SW2_PRESSED ((P1IN & SW2_BIT) == 0)

int main(void)
{
    // Turn off watchdog
    WDTCTL = WDTPW | WDTHOLD;

    // Switch ports to the output mode for controlling LEDs
    P2DIR |= BIT2 | BIT1;

    while(1)
    {
        /*** LED1 is toggled when SW1 is pressed ***/
        // In such operation mode debounce is crucial,
        // because each spike of the noise from sw1 changes the LED's state.
        // Thus, depending on the number of spikes (which is random),
        // the LED may end up in the opposite state (it is what we need),
        // or remain in the old state (user presses the switch, but nothing happens).
        // Try to comment out both delays below and observe how unstable the program becomes
        // by pressing SW1 many times.
        if (SW1_PRESSED)
        {
            // Toggle LED
            P2OUT ^= BIT2;

            // Wait until the noise from the switch subsides
            __delay_cycles(2000);

            // Wait until the switch is released
            while(SW1_PRESSED);

            // Wait until the noise from the switch subsides
            __delay_cycles(2000);
        }



        /*** LED2 follows the state of sw2 (LED is on when sw2 is pressed and off when it is released) ***/
        // For this example we do not need the debounce. Even though the LED will turn on and off when the
        // switch produces noise, this period is short, so such blinking is not noticeable for the user.

        // If sw2 is pressed, turn on LED2
        if (SW2_PRESSED) P2OUT |= BIT1;
        // If sw2 is released, turn off LED2
        else P2OUT &= ~BIT1;
    }
}
