#include <iostream> 
#include <stdlib.h> 
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main(int argc, char * argv[]) 
{
    pid_t c_pid;

    cout << "The pid of the parent is " << getpid() << endl;
    c_pid = fork();
    if (c_pid == 0)
    { 
        fork();
        cout << "I am the child; my parents pid was " << getppid() << endl; 
        exit(0);
    }

    cout << "I am the parent, the childs pid is " << c_pid << endl;
    exit(0);
}
