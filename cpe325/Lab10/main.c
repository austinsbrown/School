#include <msp430xG46x.h>
#include <math.h>
#define SW1 P1IN&BIT0

volatile long int ADCXval, ADCYval, ADCZval;
volatile float Xper, Yper, Zper;

void TimerA_setup(void) {
    TACCR0 = 3277;                                  // 3277 / 32768 Hz = 0.1s
    TACTL = TASSEL_1 + MC_1;                        // ACLK, up mode
    TACCTL0 = CCIE;                                 // Enabled interrupt
}

void ADC_setup(void) {
    int i =0;

    P2DIR |= BIT2;
    P2OUT = 0x00;
    _EINT();                                        // enable interrupts
    P1IE |= BIT0;
    P1IFG &= ~BIT0;                                 // clear interrupt flag
    P1IE |= BIT1;
    P6DIR &= ~BIT3 + ~BIT7 + ~BIT5;                 // Configure P6.3 and P6.7 as input pins
    P6SEL |= BIT3 + BIT7 + BIT5;                    // Configure P6.3 and P6.7 as analog pins
    ADC12CTL0 = ADC12ON + SHT0_6 + MSC;             // configure ADC converter
    ADC12CTL1 = SHP + CONSEQ_1;                     // Use sample timer, single sequence
    ADC12MCTL0 = INCH_3;                            // ADC A3 pin - Stick X-axis
    ADC12MCTL1 = INCH_5;
    ADC12MCTL2 = INCH_7 + EOS;                      // ADC A7 pin - Stick Y-axis
                                                    // EOS - End of Sequence for Conversions
    ADC12IE |= 0x02;                                // Enable ADC12IFG.1
    for (i = 0; i < 0x3600; i++);                   // Delay for reference start-up
    ADC12CTL0 |= ENC;                               // Enable conversions
}

void UART_putCharacter(char c)
{
    while(!(IFG2 & UCA0TXIFG));                     // Wait for previous character to be sent
    UCA0TXBUF = c;                                  // Send byte to the buffer for transmitting
}

void UART_setup(void) {
    P2SEL |= BIT4 + BIT5;                           // Set up Rx and Tx bits
    UCA0CTL0 = 0;                                   // Set up default RS-232 protocol
    UCA0CTL1 |= BIT0 + UCSSEL_2;                    // Disable device, set clock
    UCA0BR0 = 27;                                   // 1048576 Hz / 38400
    UCA0BR1 = 0;
    UCA0MCTL = 0x94;
    UCA0CTL1 &= ~BIT0;                              // Start UART device
}

void sendData(void) {
    int i;
    float g;
    Xper = (ADCXval*3.0/4095-1/3) - .5;                // Calculate percentage outputs
    Yper = (ADCYval*3.0/4095-1/3) + .3;
    Zper = (ADCZval*3.0/4095-1/3) - .7;

    g = sqrt(Xper*Xper + Yper*Yper + Zper*Zper);
    if(g >= 2)
        P2OUT = 0x04;

                                                    // Use character pointers to send one byte at a time
    char *xpointer=(char *)&Xper;
    char *ypointer=(char *)&Yper;
    char *zpointer=(char *)&Zper;

    UART_putCharacter(0x55);                        // Send header
    for(i = 0; i < 4; i++) {                        // Send x percentage - one byte at a time
        UART_putCharacter(xpointer[i]);
    }
    for(i = 0; i < 4; i++) {                        // Send y percentage - one byte at a time
        UART_putCharacter(ypointer[i]);
    }
    for(i = 0; i < 4; i++) {                        // Send y percentage - one byte at a time
        UART_putCharacter(zpointer[i]);
    }
}

void main(void) {
    WDTCTL = WDTPW +WDTHOLD;                        // Stop WDT
    TimerA_setup();                                 // Setup timer to send ADC data
    ADC_setup();                                    // Setup ADC
    UART_setup();                                   // Setup UART for RS-232
    _EINT();

    while (1){
        ADC12CTL0 |= ADC12SC;                       // Start conversions
        __bis_SR_register(LPM0_bits + GIE);         // Enter LPM0
    }
}

#pragma vector = ADC12_VECTOR
__interrupt void ADC12ISR(void)
{
    ADCXval = ADC12MEM0;                  // Move results, IFG is cleared
    ADCYval = ADC12MEM1;
    ADCZval = ADC12MEM2;
    __bic_SR_register_on_exit(LPM0_bits); // Exit LPM0
}

#pragma vector = TIMERA0_VECTOR
__interrupt void timerA_isr()
{
    sendData();                           // Send data to serial app
    __bic_SR_register_on_exit(LPM0_bits); // Exit LPM0
}

#pragma vector = PORT1_VECTOR
__interrupt void PORT1_ISR (void)
{
    if(!(P1IN & BIT0))
        P2OUT = 0x00;

    P1IES |= BIT0;
    P1IFG &= ~BIT0;
    P1IES |= BIT1;
    P1IFG &= ~BIT1;
}
