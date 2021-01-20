#include <iostream> 
#include <stdlib.h> 
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main() 
{
    pid_t c_pid;

    cout << "The PID of the parent is " << getpid() << endl << endl;
    for(int i=0; i<10; i++)
    {
        c_pid = fork();
        if (c_pid == 0)
        { 
            cout << "Child PID: " << getpid() << endl;
            cout << "Serial Number " << i << endl << endl;
            exit(0);
        }
    }
    exit(0);
}