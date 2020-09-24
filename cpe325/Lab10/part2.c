#include <msp430.h>
#include <sine_lut_512.h>                   /*512 samples are stored in this table */
#define SW1 P1IN&BIT0
#define SW2 P1IN&BIT1

void TimerA_setup(void) {
    TACTL = TASSEL_2 + MC_1;                                            // SMCLK, up mode
    TACCR0 = 82;                                                        // Sets Timer Freq (1048576*0.04sec/512)
    TACCTL0 = CCIE;                                                     // CCR0 interrupt enabled
}

void DAC_setup(void) {
    ADC12CTL0 = REF2_5V + REFON;                                        // Turn on 2.5V internal ref volage
    unsigned int i = 0;
    for (i = 50000; i > 0; i--);                                        // Delay to allow Ref to settle
    DAC12_0CTL = DAC12IR + DAC12AMP_5 + DAC12ENC;                       //Sets DAC12
}

void main(void) {
    WDTCTL = WDTPW + WDTHOLD;                                           // Stop WDT
    TimerA_setup();                                                     // Set timer to uniformly distribute the samples
    DAC_setup();                                                        // Setup DAC

    unsigned int i = 0;
    while (1)
    {
        __bis_SR_register(LPM0_bits + GIE);                             // Enter LPM0, interrupts enabled

        if((SW1) != 0 & (SW2) != 0)                                     // if nothing is pressed
        {
            DAC12_0DAT = sinewave[i];
            i=(i+1)%512;
        }
        else if((SW2) != 0 & (SW1) == 0)                                // switch 1 is pressed
        {
            DAC12_0DAT = sawtooth[i];
            i=(i+1)%512;
        }
        else if((SW2) == 0 & (SW1) != 0)                                // switch 2 is pressed
        {
            DAC12_0DAT = halfsinewave[i];
            i=(i+1)%512;
        }
        else if((SW2) == 0 & (SW1) == 0)                                // switch 2 is pressed
        {
            DAC12_0DAT = halfsawtooth[i];
            i=(i+1)%512;
        }
    }
}

#pragma vector = TIMERA0_VECTOR
__interrupt void TA0_ISR(void) {
    __bic_SR_register_on_exit(LPM0_bits);                               // Exit LPMx, interrupts enabled
}
