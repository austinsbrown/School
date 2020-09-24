#include "bigstack.h"

BigStack::BigStack()
{
    headPtr = NULL;
}


void BigStack::Push(char ch)
{
    if(headPtr==NULL)
    {
        headPtr = new ListNode;
        headPtr->stackPtr = new MiniStack();
        headPtr->nextPtr = headPtr->previousPtr = NULL;
    }
    if(headPtr->stackPtr->IsFull())
    {
        headPtr->previousPtr = new ListNode;
        headPtr->previousPtr->stackPtr = new MiniStack();
        headPtr->previousPtr->nextPtr = headPtr;
        headPtr=headPtr->previousPtr;
        headPtr->previousPtr = NULL;
    }
    headPtr->stackPtr->Push(ch);
}   

void BigStack::Pop()
{
    if(headPtr!=NULL)
    {
        headPtr->stackPtr->Pop();
        if(headPtr->stackPtr->Size() == 0)
        {
            delete headPtr->stackPtr;
            if(headPtr->nextPtr != NULL)
            {
                ListNode* tempPtr = headPtr;
                headPtr = headPtr->nextPtr;
                delete headPtr;
                headPtr->previousPtr=NULL;
                delete tempPtr;
            }
            else
            {
                delete headPtr->stackPtr;
                delete headPtr;
                headPtr = NULL;
            }
            
        }
    }
}    

char BigStack::Top()
{
   return headPtr->stackPtr->Top();
} 

void BigStack::MakeEmpty()
{
        while(headPtr->nextPtr != NULL)
        {
            headPtr = headPtr->nextPtr;
            delete headPtr ->previousPtr->stackPtr;
            delete headPtr->previousPtr;
            headPtr->previousPtr = NULL;
        }
         delete headPtr->stackPtr;
         delete headPtr;
         headPtr = NULL;
    
}   

bool BigStack::IsFull() const
{
    ListNode*  tempPtr;

    try
    {
        tempPtr = new ListNode;
        delete tempPtr;
        return false;
    }
    catch(std::bad_alloc)
    {
        return true;
    }  
}   

bool BigStack::IsEmpty() const
{
    return (headPtr == NULL);
}

int BigStack::Size() const
{
    if(headPtr != NULL)
    {
        int size = headPtr->stackPtr->Size();
        ListNode* tempPtr = headPtr->nextPtr;

        while(tempPtr != NULL)
        {
            size += tempPtr -> stackPtr -> Size();
            tempPtr = tempPtr->nextPtr;
        }

        return size;
    }return 0;
}   

BigStack::~BigStack()
{
    if(headPtr != NULL)
    {
        while(headPtr->previousPtr != NULL)
        {
            headPtr = headPtr->previousPtr;
            delete headPtr->nextPtr->stackPtr;
            delete headPtr->nextPtr->nextPtr;
            headPtr->nextPtr = NULL;

        }
        delete headPtr->stackPtr;
        delete headPtr;
    }
    else
    {
        delete headPtr;
    }
    
}