#include <msp430.h> 
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void UART_initialize();
void UART_sendCharacter(char);
char UART_getCharacter();
void UART_sendString(char *);
void UART_getline(char *, int);
int SPIGetState();
void SPISetState(int );
void SPI_setup();

#define LED_ON_STATE 0x31 							// Character '1'
#define LED_OFF_STATE 0x30							// Character '0'
#define LED_NUL_STATE 0x00							// Character NULL - used for dummy write operation
#define LED_ON 0x01
#define LED_OFF 0x00


int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;						// stop watchdog timer
	UART_initialize();
	SPI_setup();
	
	while(1)
	{
	    UART_sendString("Beacon pause: ");
		char string[50];
		UART_getline(string, 49);
		int num = atoi(string);

		if(strcmp(string, "?") == 0)
		{
			SPISetState(0);
			for(int i=1000; i>0; i--);
			sprintf(string, "%03d", SPIGetState());
			UART_sendString(string);
			UART_sendString("\r\n");
		}

		else if(strcmp(string, "-") == 0)
		{
			SPISetState(255);
			for(int i=1000; i>0; i--);
			UART_sendCharacter(SPIGetState());
		}
		else if(num > 0 && num < 101)
		{
			SPISetState(num);
			for(int i=1000; i>0; i--);
		}
		else 
		{
			UART_sendString("Invalid pause entered. \r\n");
		}
	}
}


void UART_initialize()
{
    UCA0CTL1 |= UCSWRST;                    	// set software reset during initialization
    P2SEL |= BIT4 | BIT5;                   	// Set UC0TXD and UC0RXD to transmit and receive
    UCA0CTL1 |= UCSSEL_2;                   	// clock source SMCLK
    UCA0BR0 = 0x09;                         	// baud rate
    UCA0BR1 = 0x00;                         	// upper byte
    UCA0MCTL = 0x02;                        	// Modulation
    UCA0CTL1 &= ~UCSWRST;                   	// clear software reset
}


void UART_sendCharacter(char s)
{
    while(!(IFG2 & UCA0TXIFG));             	// previous character isn't transmitted
    UCA0TXBUF = s;                          	// move c to tx buffer

}


char UART_getCharacter()
{
    while(!(IFG2 & UCA0RXIFG));             	// previous character isn't transmitted
    char s;
    s = UCA0RXBUF;                          	// get character
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


int SPIGetState()
{
	while((P3IN & 0x01));						// verifies the busy flag
	IFG2 &= ~UCB0RXIFG;
	UCB0TXBUF = LED_NUL_STATE;    				// Dummy write to start SPI
	while(!(IFG2 & UCB0RXIFG));     			// USCI_B0 TX buffer ready?
	return UCB0RXBUF;
}	


void SPISetState(int state)
{
	while(P3IN & 0x01);          				// Verifies busy flag
	IFG2 &= ~UCB0RXIFG;
	UCB0TXBUF = state;    						// write new state
	while(!(IFG2 & UCB0RXIFG));    				// USCI_B0 TX buffer ready
}


void SPI_setup()
{
	UCB0CTL0 = UCMSB + UCMST + UCSYNC;			// SMCLK and Software reset
	UCB0CTL1 = UCSSEL_2 + UCSWRST;
	UCB0BR0 = 0x02;								// Data rate = SMCLK/2 ~= 500kHz

	UCB0BR1 = 0x00;
	P3SEL |= BIT1 + BIT2 + BIT3; 				// P3.1,P3.2,P3.3 option select
	UCB0CTL1 &= ~UCSWRST;
 
}
