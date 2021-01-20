#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

int main() 
{
    int queueID; // id of a message queue
    int sendStatus; // return variable for msgsnd
    struct TextMessage message; 

    if((queueID = msgget(QUEUEKEY, IPC_CREAT | 0666)) == -1) // create message queue
    {
        printf("An error has occured!\n"); // error handling
        exit(-1);
    }

    printf("Queue Created.\n");

    for(;;)
    {
        printf("Process A: ");
        fgets(message.mtext, MTEXTSIZE, stdin); // get input from the user
        message.mtext[strcspn(message.mtext, "\n")] = 0; // get rid of newline character
        message.mtype = 1; // set message type

        sendStatus = msgsnd(queueID, &message, strlen(message.mtext)+1, 0); // send a message
        if(sendStatus < 0)
        {
            printf("Could not send Message!\n");
            exit(-1);
        }

        if(msgrcv(queueID, &message, MTEXTSIZE, 2, 0) < 0) // try to recieve message
        {
            printf("An error has occured. Could not recieve message\n.");
            exit(-1);
        }

        else
        {
            if(strcasecmp(message.mtext, "EXIT") == 0)
            {
                printf("Exiting...\n");
                break;
            }

            printf("Process B: %s\n", message.mtext);
        }
    }

    msgctl(queueID, IPC_RMID, NULL); // delete the message queue
    return 0;
}