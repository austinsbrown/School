#define MTEXTSIZE 100
#define QUEUEKEY (key_t)1234 

struct TextMessage
{
    long mtype; // type of message being sent
    char mtext[QUEUEKEY]; // the message to be sent
};
