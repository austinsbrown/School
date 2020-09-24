#ifndef LEVEL_H_
#define LEVEL_H_

void level1()
{
    char answer[1];
    char passcode[50];

    UART_sendString("This level will use led 1 and 2\r\n");
    UART_sendString("If you see led1 enter 1. If you see led2 enter 2\r\n");
    UART_sendString("You need to enter 4 characters\r\n");
    UART_sendString("Enter y to begin\r\n\r\n");
    UART_getline(answer, 1);


    if(strcmp(answer, "y") == 0)
    {
        P2OUT |= BIT2;
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT &= ~BIT2;
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT |= BIT2;
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT &= ~BIT2;
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT |= BIT1;
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT &= ~BIT1;
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT |= BIT2;
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT &= ~BIT2;
    }

    UART_sendString("Enter the four digit pass code: ");
    UART_getline(passcode, 49);

    if(strcmp(passcode, "1121") == 0)
    {
        UART_sendString("You have passed the level!\r\n");
    }
    else
        UART_sendString("You have failed!\r\n\r\n");
}


void level2()
{
    char answer[1];
    char passcode[50];

    UART_sendString("This level will use led 1 and 2\r\n");
    UART_sendString("If you see led1 enter 1. If you see led2 enter 2\r\n");
    UART_sendString("You need to enter 6 characters\r\n");
    UART_sendString("Enter y to begin\r\n");
    UART_getline(answer, 1);

    if(strcmp(answer, "y") == 0)
    {
        P2OUT |= BIT1;                          // turn led2 on
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT &= ~BIT1;
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT |= BIT1;                          // turn led2 on
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT &= ~BIT1;
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT |= BIT2;                          // turn led1 on
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT &= ~BIT2;
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT |= BIT2;                          // turn led1 on
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT &= ~BIT2;
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT |= BIT1;                          // turn led2 on
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT &= ~BIT1;
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT |= BIT2;
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT &= ~BIT2;

        UART_sendString("Enter the four digit pass code: ");
        UART_getline(passcode, 49);

        if(strcmp(passcode, "221121") == 0)
        {
            UART_sendString("You have passed the level!\r\n");
        }
        else
            UART_sendString("You have failed!\r\n\r\n");
    }
}


void level3()
{
    char answer[1];
    char passcode[50];

    UART_sendString("This level will use led 1, 2, and 3.\r\n");
    UART_sendString("If you see led1 enter 1. If you see led2 enter 2\r\n");
    UART_sendString("You need to enter 4 characters\r\n");
    UART_sendString("Enter y to begin\r\n");
    UART_getline(answer, 1);

    if(strcmp(answer, "y") == 0)
    {
        P2OUT |= BIT2;                              // turn on led1
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT &= ~BIT2;
        for(long int i = 0; i < difficultyTimer; i++);
        SPISetState(1);                             // turn on led3
        for(long int i = 0; i < difficultyTimer; i++);
        SPISetState(0);
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT |= BIT1;                              // turn on led 2
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT &= ~BIT1;
        for(long int i = 0; i < difficultyTimer; i++);
        SPISetState(1);                             // turn on led3
        for(long int i = 0; i < difficultyTimer; i++);
        SPISetState(0);

        UART_sendString("Enter the four digit pass code: ");
        UART_getline(passcode, 49);

        if(strcmp(passcode, "1323") == 0)
        {
            UART_sendString("You have passed the level!\r\n");
        }
        else
            UART_sendString("You have failed!\r\n\r\n");
    }
}


void level4()
{
    char answer[1];
    char passcode[50];

    UART_sendString("This level will use led 1, 2, and 3\r\n");
    UART_sendString("If you see led1 enter 1. If you see led2 enter 2. If you see led3, enter 3.\r\n");
    UART_sendString("You need to enter 6 characters\r\n");
    UART_sendString("Enter y to begin\r\n");
    UART_getline(answer, 1);

    if(strcmp(answer, "y") == 0)
    {
        SPISetState(1);                         // turn led3 on
        for(long int i = 0; i < difficultyTimer; i++);
        SPISetState(0);
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT |= BIT2;                          // turn led1 on
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT &= ~BIT2;
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT |= BIT2;                          // turn led1 on
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT &= ~BIT2;
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT |= BIT1;                          // turn led2 on
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT &= ~BIT1;
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT |= BIT2;                          // turn led1 on
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT &= ~BIT2;
        for(long int i = 0; i < difficultyTimer; i++);
        SPISetState(1);                         // turn led3 off
        for(long int i = 0; i < difficultyTimer; i++);
       SPISetState(0);

        UART_sendString("Enter the six digit pass code: ");
        UART_getline(passcode, 49);

        if(strcmp(passcode, "311213") == 0)
        {
            UART_sendString("You have passed the level!\r\n");
        }
        else
            UART_sendString("You have failed!\r\n\r\n");
    }
}


void level5()
{
    char answer[1];
    char passcode[50];

    UART_sendString("This level will use led 1, 2, 3, and 4\r\n");
    UART_sendString("If you see led1 enter 1. If you see led2 enter 2. The pattern continues for led3 and led4.\r\n");
    UART_sendString("You need to enter 4 characters\r\n");
    UART_sendString("Enter y to begin\r\n");
    UART_getline(answer, 1);


    if(strcmp(answer, "y") == 0)
    {
        P5OUT |= BIT1;                          // turn on led4
        for(long int i = 0; i < difficultyTimer; i++);
        P5OUT &= ~BIT1;
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT |= BIT2;                          // turn on led1
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT &= ~BIT2;
        for(long int i = 0; i < difficultyTimer; i++);
        SPISetState(1);                         // turn on led3
        for(long int i = 0; i < difficultyTimer; i++);
        SPISetState(0);
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT |= BIT1;                          // turn on led2
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT &= ~BIT1;
    }

    UART_sendString("Enter the four digit pass code: ");
    UART_getline(passcode, 49);

    if(strcmp(passcode, "4132") == 0)
    {
        UART_sendString("You have passed the level!\r\n");
    }
    else
        UART_sendString("You have failed!\r\n\r\n");
}


void level6()
{
    char answer[1];
    char passcode[50];

    UART_sendString("This level will use led 1, 2, 3, and 4\r\n");
    UART_sendString("If you see led1 enter 1. If you see led2 enter 2. The pattern continues for led 3 and 4.\r\n");
    UART_sendString("You need to enter 6 characters\r\n");
    UART_sendString("Enter y to begin\r\n");
    UART_getline(answer, 1);

    if(strcmp(answer, "y") == 0)
    {
        P2OUT |= BIT2;                          // turn on led1
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT &= ~BIT2;
        for(long int i = 0; i < difficultyTimer; i++);
        P5OUT |= BIT1;                          // turn led4 on
        for(long int i = 0; i < difficultyTimer; i++);
        P5OUT &= ~BIT1;
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT |= BIT1;                          // turn led2 on
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT &= ~BIT1;
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT |= BIT2;                          // turn led1 on
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT &= ~BIT2;
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT |= BIT2;                          // turn led1 on
        for(long int i = 0; i < difficultyTimer; i++);
        P2OUT &= ~BIT2;
        for(long int i = 0; i < difficultyTimer; i++);
        P5OUT |= BIT1;                          // turn led4 off
        for(long int i = 0; i < difficultyTimer; i++);
        P5OUT &= ~BIT1;

        UART_sendString("Enter the six digit pass code: ");
        UART_getline(passcode, 49);

        if(strcmp(passcode, "142114") == 0)
        {
            UART_sendString("You have passed the level!\r\n");
        }
        else
            UART_sendString("You have failed!\r\n\r\n");
    }
}



#endif /* LEVEL_H_ */
