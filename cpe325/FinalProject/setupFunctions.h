#include <stdio.h>
#include <stdlib.h>


#ifndef SETUPFUNCTIONS_H_
#define SETUPFUNCTIONS_H_

#define LED_ON_STATE 0x31                           // Character '1'
#define LED_OFF_STATE 0x30                          // Character '0'
#define LED_NUL_STATE 0x00                          // Character NULL - used for dummy write operation
#define LED_ON 0x01
#define LED_OFF 0x00

void UART_initialize()
{
    UCA0CTL1 |= UCSWRST;                    // set software reset during initialization
    P2SEL |= BIT4 | BIT5;                   // Set UC0TXD and UC0RXD to transmit and receive
    UCA0CTL1 |= UCSSEL_2;                   // clock source SMCLK
    UCA0BR0 = 0x09;                         // baud rate
    UCA0BR1 = 0x00;                         // upper byte
    UCA0MCTL = 0x02;                        // Modulation
    UCA0CTL1 &= ~UCSWRST;                   // clear software reset
}


void UART_sendCharacter(char s)
{
    while(!(IFG2 & UCA0TXIFG));             // previous character isn't transmitted
    UCA0TXBUF = s;                          // move c to tx buffer

}


char UART_getCharacter()
{
    while(!(IFG2 & UCA0RXIFG));             // previous character isn't transmitted
    char s;
    s = UCA0RXBUF;                          // get character
    return s;
}


void UART_sendString(char *string)
{
    for(int i=0; i < strlen(string); i++)
    {
        UART_sendCharacter(string[i]);
    }
}


void UART_getline(char *buffer, int limit)
{
    char s = UART_getCharacter();               // get a new character
    UART_sendCharacter(s);                      // send the character

    int i = 0;
    do
    {
        buffer[i] = s;                          // store the character to the buffer

        s = UART_getCharacter();                // get a new character
        UART_sendCharacter(s);                  // send the character

        if(i < limit)
            i++;
        else
            break;

    }while(s != '\r');

    UART_sendCharacter('\r');                   // send newline characters
    UART_sendCharacter('\n');
    buffer[i] = NULL;                           // set last character of buffer to NULL
}


void setupTimer()
{
    IE1 |= WDTIE;                               // wdtie interrupts
    _EINT();                                    // enable interrupts
    P2DIR |= BIT2;                              // set port 2 as output

    P1IE |= 0x03;                               //
    P1IFG &= ~0x03;                             // reset interrupt flag

    TB0CCR0 = 500;                              // pitch
    TB0CCTL4 = OUTMOD_4;                        // TB0 output mode
    TB0CTL = TBSSEL_2 + MC_1;                   // clock source and mode
}


void  mainMenu()
{
    UART_sendString("Welcome to the msp430 memory game!\r\n");
    UART_sendString("Each level will have its own directions so be sure to pay attention before starting!\r\n");
    UART_sendString("Enter a what difficulty you want! You can enter 1, 2, or 3\r\n");
    UART_getline(difficulty, 1);

    if(strcmp(difficulty, "1") == 0)
        difficultyTimer = 100000;

    if(strcmp(difficulty, "2") == 0)
        difficultyTimer = 50000;

    if(strcmp(difficulty, "3") == 0)
        difficultyTimer = 25000;


    UART_sendString("To choose a level, enter 1, 2, 3, 4, 5, 6, or 7.\r\n");
    UART_getline(currentLevel, 1);
}

int SPIGetState()
{
    while((P3IN & 0x01));                       // verifies the busy flag
    IFG2 &= ~UCB0RXIFG;
    UCB0TXBUF = LED_NUL_STATE;                  // Dummy write to start SPI
    while(!(IFG2 & UCB0RXIFG));                 // USCI_B0 TX buffer ready?
    return UCB0RXBUF;
}


void SPISetState(int state)
{
    while(P3IN & 0x01);                         // Verifies busy flag
    IFG2 &= ~UCB0RXIFG;
    UCB0TXBUF = state;                          // write new state
    while(!(IFG2 & UCB0RXIFG));                 // USCI_B0 TX buffer ready
}


void SPI_setup()
{
    UCB0CTL0 = UCMSB + UCMST + UCSYNC;          // SMCLK and Software reset
    UCB0CTL1 = UCSSEL_2 + UCSWRST;
    UCB0BR0 = 0x02;                             // Data rate = SMCLK/2 ~= 500kHz

    UCB0BR1 = 0x00;
    P3SEL |= BIT1 + BIT2 + BIT3;                // P3.1,P3.2,P3.3 option select
    UCB0CTL1 &= ~UCSWRST;

}

void UART_putCharacter(char c)
{
    while(!(IFG2 & UCA0TXIFG));         // Wait for previous character to be sent
    UCA0TXBUF = c;                      // Send byte to the buffer for transmitting
}


void ADC_setup(void)
{
    int i =0;

    P6DIR &= ~BIT3 + ~BIT7;             // Configure P6.3 and P6.7 as input pins
    P6SEL |= BIT3 + BIT7;               // Configure P6.3 and P6.7 as analog pins
    ADC12CTL0 = ADC12ON + SHT0_6 + MSC; // configure ADC converter
    ADC12CTL1 = SHP + CONSEQ_1;         // Use sample timer, single sequence
    ADC12MCTL0 = INCH_3;                // ADC A3 pin - Stick X-axis
    ADC12MCTL1 = INCH_7 + EOS;          // ADC A7 pin - Stick Y-axis
                                        // EOS - End of Sequence for Conversions
    ADC12IE |= 0x02;                    // Enable ADC12IFG.1
    for (i = 0; i < 0x3600; i++);       // Delay for reference start-up
    ADC12CTL0 |= ENC;                   // Enable conversions
}


void TimerA_setup(void)
{
    TACCR0 = 3277;                      // 3277 / 32768 Hz = 0.1s
    TACTL = TASSEL_1 + MC_1;            // ACLK, up mode
    TACCTL0 = CCIE;                     // Enabled interrupt
}


void sendData(void) {
    int i;
    Xper = (ADCXval*3.0/4095*100/3);    // Calculate percentage outputs
    Yper = (ADCYval*3.0/4095*100/3);


    if((Xper > 60))
    {
        if(creditNum == 1)
        {
            P2OUT |= BIT1;
            for(long int i = 0; i < 40000; i++);
            P2OUT &= ~BIT1;
            for(long int i = 0; i < 40000; i++);
            UART_sendString("Created By Austin Brown\r\n\r\n");
            creditNum++;
        }

        else if(creditNum == 2)
        {
            P2OUT |= BIT2;
            for(long int i = 0; i < 40000; i++);
            P2OUT &= ~BIT2;
            for(long int i = 0; i < 40000; i++);
            UART_sendString("Directed By Austin Brown\r\n\r\n");
            creditNum++;
        }

        else if(creditNum == 3)
        {
            P2OUT |= BIT2;
            for(long int i = 0; i < 40000; i++);
            P2OUT &= ~BIT2;
            for(long int i = 0; i < 40000; i++);
            UART_sendString("Original Soundtrack by Austin Brown\r\n\r\n");
            creditNum++;
        }

        else if(creditNum == 4)
        {
            P5OUT |= BIT1;
            for(long int i = 0; i < 40000; i++);
            P5OUT &= ~BIT1;
            for(long int i = 0; i < 40000; i++);
            UART_sendString("Artwork by Austin Brown\r\n\r\n");
            creditNum++;
        }

        else if(creditNum == 5)
        {
            P5OUT |= BIT1;
            for(long int i = 0; i < 40000; i++);
            P5OUT &= ~BIT1;
            for(long int i = 0; i < 40000; i++);
            UART_sendString("Special Thanks To Austin Brown\r\n\r\n");
            UART_sendString("The End\r\n\r\n");
            creditNum++;
        }
    }

}





















#endif /* SETUPFUNCTIONS_H_ */
