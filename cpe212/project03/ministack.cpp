#include "ministack.h"

MiniStack::MiniStack()
{
    top = -1;
    stackPtr = new char[MINI_STACK_SIZE];
}

void MiniStack::Push(char ch)
{
    if(top != MINI_STACK_SIZE-1)
    {
        top++;
        stackPtr[top] = ch;
        return;
    }

    else
    {
        throw MiniStackFull();
    }
    
}

void MiniStack::Pop()
{
    if(top != -1)
    {
        top--;
    }
    else
    {
        {
            throw MiniStackEmpty();
        }
    }
    
}

void MiniStack::MakeEmpty()
{
    top = -1;
}

char MiniStack::Top() const
{
    if(top != -1)
    {
        return stackPtr[top];
    }
    else
    {
        throw MiniStackEmpty();
    }
    
}

bool MiniStack::IsFull() const
{
    return {top == MINI_STACK_SIZE-1};
}

bool MiniStack::IsEmpty() const
{
    return {top == -1};
}

int MiniStack::Size() const
{   int temp = top + 1;
    return temp;
}

MiniStack::~MiniStack()
{
    delete [] stackPtr;
    stackPtr = NULL;
}