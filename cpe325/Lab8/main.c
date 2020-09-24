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


int test = 0;

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	            // stop watchdog timer

	UART_initialize();

	while(0==0)
	{
	    char string[50];

	    UART_sendString("\e[33mMe\e[0m: ");
	    UART_getline(string, 49);

	    if(strcmp(string, "1000") == 0 && test == 1)
	    {
	        UART_sendString("\e[34mBot\e[0m: That cannot be true!");
	        UART_sendString("\r\n");
	    }
	    else if(test == 1)
	    {
	        UART_sendString("\e[34mBot\e[0m: You are so young! I am 1");
	        UART_sendString(string);
	        UART_sendString(".");
	        UART_sendString("\r\n");
	    }
	    if(strcmp(string, "Hey, Bot!") == 0)
	    {
	        UART_sendString("\e[34mBot\e[0m: Hi, How old are you?");
	        UART_sendString("\r\n");
	        test = 1;
	    }
	    else
	        test = 0;
	}


}


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













