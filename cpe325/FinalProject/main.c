#include <msp430.h> 
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char currentLevel[10];
char difficulty[5];
long int difficultyTimer;
int creditNum = 1;

volatile long int ADCXval, ADCYval;
volatile float Xper, Yper;

#include "setupFunctions.h"
#include "level.h"

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	                // stop watchdog timer

	UART_initialize();                          // set up UART
	P2DIR |= BIT2 + BIT1;                       // set LED1 and LED2 as the outputs
	P5DIR |= BIT1;
	P2OUT &= ~(BIT2 + BIT1);                    // ensures that both leds are initially off
	P5OUT &= ~BIT1;
	SPI_setup();
	SPISetState(0);


	while(1)
	{
        mainMenu();



        if(strcmp(currentLevel, "1") == 0)          // answer is 1121
        {
            level1();
        }

        if(strcmp(currentLevel, "2") == 0)          // answer is 221121
        {
            level2();
        }

        if(strcmp(currentLevel, "3") == 0)          // answer is 1323
        {
            level3();
        }

        if(strcmp(currentLevel, "4") == 0)          // answer is 311213
        {
            level4();
        }

        if(strcmp(currentLevel, "5") == 0)          // answer is 4132
        {
            level5();
        }

        if(strcmp(currentLevel, "6") == 0)          // answer is 142114
        {
            level6();
        }

        if(strcmp(currentLevel, "7") == 0)          // answer is 1b42bb
        {
            TB0CCR0 = 500;                              // pitch
            TB0CCTL4 = OUTMOD_4;                        // TB0 output mode
            TB0CTL = TBSSEL_2 + MC_1;                   // clock source and mode
            P3SEL &= ~BIT5;                              // select special button
            P3DIR |= BIT5;

            char answer[1];
            char passcode[50];

            UART_sendString("This level will use led 1, 2, 3, 4, and the buzzer. \r\n");
            UART_sendString("If you see led1 enter 1. If you see led2 enter 2. The pattern continues for led 3 and 4. If you hear the buzzer enter b\r\n");
            UART_sendString("You need to enter 5 characters\r\n");
            UART_sendString("Enter y to begin\r\n");
            UART_getline(answer, 1);

            if(strcmp(answer, "y") == 0)
            {
                P2OUT |= BIT2;                              // turn on led1
                for(long int i = 0; i < difficultyTimer; i++);
                P2OUT &= ~BIT2;
                for(long int i = 0; i < difficultyTimer; i++);
                P3SEL ^= BIT5;                              // turn buzzer on
                for(long int i = 0; i < difficultyTimer; i++);
                P3SEL ^= BIT5;
                for(long int i = 0; i < difficultyTimer; i++);
                P5OUT |= BIT1;                              // turn led4 on
                for(long int i = 0; i < difficultyTimer; i++);
                P5OUT &= ~BIT1;
                for(long int i = 0; i < difficultyTimer; i++);
                P2OUT |= BIT1;                              // turn led2 on
                for(long int i = 0; i < difficultyTimer; i++);
                P2OUT &= ~BIT1;
                for(long int i = 0; i < difficultyTimer; i++);
                P3SEL ^= BIT5;                              // turn buzzer on
                for(long int i = 0; i < difficultyTimer; i++);
                P3SEL ^= BIT5;
                for(long int i = 0; i < difficultyTimer; i++);
                P3SEL ^= BIT5;                              // turn buzzer
                for(long int i = 0; i < difficultyTimer; i++);
                P3SEL ^= BIT5;

                UART_sendString("Enter the five digit pass code: ");
                UART_getline(passcode, 49);

                if(strcmp(passcode, "1b42bb") == 0)
                {
                    UART_sendString("You have passed the level!\r\n\r\n");


                    UART_sendString("Welcome to the end credits\r\n");


                    char answer[1];
                    UART_sendString("Enter y and then move the joy stick to begin.\r\n");
                    UART_getline(answer, 1);


                    if(strcmp(answer, "y") == 0)
                    {
                        TimerA_setup();                         // Setup timer to send ADC data
                        ADC_setup();
                        _EINT();

                        while (1)
                        {
                            ADC12CTL0 |= ADC12SC;                       // Start conversions
                            __bis_SR_register(LPM0_bits + GIE);         // Enter LPM0
                        }
                    }

                }
                else
                    UART_sendString("You have failed!\r\n");
            }
        }
	}

	return 0;
}

#pragma vector = ADC12_VECTOR
__interrupt void ADC12ISR(void) {
    ADCXval = ADC12MEM0;                  // Move results, IFG is cleared
    ADCYval = ADC12MEM1;
    __bic_SR_register_on_exit(LPM0_bits); // Exit LPM0
}

#pragma vector = TIMERA0_VECTOR
__interrupt void timerA_isr() {
    sendData();                           // Send data to serial app
    __bic_SR_register_on_exit(LPM0_bits); // Exit LPM0
}





