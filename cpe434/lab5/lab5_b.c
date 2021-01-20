#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

int main()	 
{  
	int queueID;
    int recieveSataus;	
 	struct TextMessage message;
     
	queueID = msgget(QUEUEKEY, 0);
	if (queueID == -1)   
    {  
        printf("Could not attach to message queue!\n");
        exit(-1);   
    }
	
    while(!(strcasecmp(message.mtext, "EXIT") == 0))
    {
        recieveSataus = msgrcv(queueID, &message, MTEXTSIZE, 1, 0);
        if (recieveSataus < 0 )        
        {  
            printf("Could not recieve message from queue!\n");
            exit(-1);
        }
        else
        {
            if(strcasecmp(message.mtext, "EXIT") == 0)
            {
                printf("Exiting.\n");
                break;
            }
            printf("Process A: %s\n", message.mtext);
        }

        printf("Process B: ");
        fgets(message.mtext, MTEXTSIZE, stdin);
        message.mtext[strcspn(message.mtext, "\n")] = 0; // get rid of newline character
        message.mtype = 2;
        if (msgsnd(queueID, &message, strlen(message.mtext)+1, 0) < 0)
        {
			printf("Error: Failed to send message. Terminating...\n");
			break;
		}

    }
	msgctl(queueID, IPC_RMID, 0 ); 
    return 0;
}
