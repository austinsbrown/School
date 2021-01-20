#include <stdio.h>
#include <iostream> 
#include <unistd.h> 
using namespace std; 

int main()
{
    int x; 
    x=0;
    fork(); 
    x++;
    //this should be printed twice, once by parent and once by child 
    cout<<"I am process "<<getpid()<<" and my x is "<<x<<endl; 
    return 0;
}
