#include "msp430.h"

#define LED_ON_STATE    0x31      // Character '1'
#define LED_OFF_STATE   0x30      // Character '0'
#define LED_NUL_STATE   0x00      // Character NULL - used for dummy write operation

#define LED_ON          0x01
#define LED_OFF         0x00

#define SET_BUSY_FLAG()   P1OUT |= 0x10
#define RESET_BUSY_FLAG() P1OUT &= ~0x10

#define SET_LED()       P1OUT |= 0x01
#define RESET_LED()     P1OUT &= ~BIT0

unsigned char LState;
unsigned char nextS;
int x;

void SPI_setup(void)
{
    USICTL0 |= USISWRST;                                // Set UCSWRST -- needed for re-configuration process
    USICTL0 |= USIPE5 + USIPE6 + USIPE7 + USIOE;        // SCLK-SDO-SDI port enable,MSB first
    USICTL1 = USIIE;                                    // USI  Counter Interrupt enable
    USICTL0 &= ~USISWRST;                               // **Initialize USCI state machine**
}

void SPI_initComm(void)
{
    USICNT = 8;                                         // Load bit counter, clears IFG
    USISRL = LState;                                    // Set LED state
    RESET_BUSY_FLAG();                                  // Reset busy flag
}

int main(void)
{
    SPI_setup();                                         // Setup USI module in SPI mode
    SPI_initComm();                                      // Initialization communication

    WDTCTL = WDTPW | WDTHOLD;                            // 32ms interval (default)
    P1DIR |= BIT0;                                       // Set P1.0 to output direction
    P1OUT &= ~BIT0;
    IE1 |= WDTIE;                                        // Enable WDT interrupt

    _BIS_SR(LPM0_bits + GIE);                            // Enter LPM0 with interrupt
    while(1)
    {
        _BIS_SR(LPM0_bits + GIE);                        // Enter LPM0 with interrupt
        if(nextS == 1)
            P1OUT |= BIT0;
        else if(nextS == 0)
            P1OUT &= ~BIT0;


    }
}


#pragma vector = USI_VECTOR
__interrupt void USI_ISR(void)
{
    SET_BUSY_FLAG();                        // Set busy flag - busy with new communication
    nextS = USISRL;                         // Read new command
    USICNT = 8;                             // Load bit counter for next TX
   _BIC_SR_IRQ(LPM0_bits);                  // Exit from LPM0 on RETI
}
