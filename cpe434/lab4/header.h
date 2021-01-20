typedef struct SharedData
{
    float value1, value2;
    float sum;
    
    /*
        2 if waiting on process 2,
        1 if wating on process 1,
        -1 if done
    */
    int flag;
}SharedData;

#define KEY (key_t)(1244)
#define STRUCTSIZE sizeof(SharedData)
