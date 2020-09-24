#include "priorityq.h"

PriorityQ::PriorityQ()
{
    frontPtr = NULL;
    rearPtr = NULL;
    count = 0;
}
	

PriorityQ::~PriorityQ()
{
    if(rearPtr != NULL)
    {
        Node* temp = frontPtr;

        while(temp->nextPtr != NULL)
        {
            Node* s = temp->nextPtr; 
            delete temp;
            temp = s;
        }

        delete temp;
    }
}
	

void PriorityQ::MakeEmpty()
{
    if(rearPtr != NULL)
    {
        Node* temp = frontPtr;

        while(temp->nextPtr != NULL)
        {
            Node* s = temp->nextPtr; 
            delete temp;
            temp = s;
        }

        delete temp;
        frontPtr = NULL;
        rearPtr = NULL;
        count = 0;
    }
}


void PriorityQ::Enqueue(Message msg)
{
   Node* temp;

   if(IsFull())
   {
       throw(FullPQ());
   }

   else
   {
       temp = new Node;
   }
   

   temp->data = msg;
   if(count == 0)
   {
       frontPtr = rearPtr = temp;
       frontPtr->previousPtr= rearPtr->nextPtr = NULL;
   }

   else
   {
       if(rearPtr->data.GetPriority() >= msg.GetPriority())
       {
           rearPtr->nextPtr=temp;
           rearPtr->nextPtr->previousPtr = rearPtr;
           rearPtr = temp;
           rearPtr->nextPtr=NULL;
       }

       else if(frontPtr->data.GetPriority() >= msg.GetPriority())
       {
           Node* x = frontPtr;
           while(x->nextPtr->data.GetPriority() >= msg.GetPriority())
           {
               x = x->nextPtr;
           }

           x->nextPtr->previousPtr = temp;
           x->nextPtr->previousPtr->nextPtr = x->nextPtr;
           x->nextPtr->previousPtr->previousPtr = x;
           x->nextPtr = x->nextPtr->previousPtr;
       }

       else if(frontPtr->data.GetPriority() < msg.GetPriority())
       {
           frontPtr->previousPtr = temp;
           frontPtr->previousPtr->nextPtr = frontPtr;
           frontPtr = frontPtr->previousPtr;
           frontPtr->previousPtr=NULL;
       }
   }
   count++;
}
	

void PriorityQ::Dequeue()
{
    if(count == 0)
    {
        throw EmptyPQ();
    }

    else
    {
        if(count != 1)
        {
            frontPtr = frontPtr->nextPtr;
            delete frontPtr->previousPtr;
            frontPtr->previousPtr = NULL;
        }

        else 
        {
            delete frontPtr;
            frontPtr = rearPtr = NULL;

        }
    }
    count--;
}
	
void PriorityQ::Purge(Priorities p)
{
    if(count == 0) // checks if queue is empty
    {
        throw EmptyPQ();
    }

    Node* temp = frontPtr;

    while(temp != NULL)
    {
        Node* s = temp->nextPtr;
        Node* pr = temp->previousPtr;

        if((temp->data).GetPriority() == p)
        {
            if(s == NULL && pr == NULL) // case 1
            {
            rearPtr = NULL;
            frontPtr = NULL;
            delete temp;
            }

            else if(s == NULL) // case 2 
            {
                pr->nextPtr = NULL;
                rearPtr = pr;
                delete temp;
            }

            else if(pr == NULL) // case 3
            {
                s->previousPtr = NULL;
                frontPtr = s;
                delete temp;
            }

            else // case 4
            {
                pr->nextPtr = s;
                s->previousPtr = pr;
                delete temp;
            }
            count--;
        }  
         temp = s;
    }
}


Message PriorityQ::Front() const 
{
    if(count == 0)
    {
        throw EmptyPQ();
    }
    return (frontPtr->data);
}
	

Message PriorityQ::Rear() const
{
    if(count == 0)
    {
        throw EmptyPQ();
    }
    return (rearPtr->data);
}


Message PriorityQ::Peek(int n) const
{
    if(n >= count)
    {
        throw InvalidPeekPQ();

    }

    int count = 0;

    Node* temp = frontPtr;
    while(temp != NULL)
    {
        if(count == n)
        {
            return (temp->data);
        }
        temp = temp->nextPtr;
        count++;
    }
}
	
bool PriorityQ::IsFull() const
{
    try
    {
        Node* temp = new Node;
        delete temp;
        return false;
    }

    catch(std::bad_alloc)
    {
        return true;
    }
}
	

bool PriorityQ::IsEmpty() const
{
    return (count == 0);
}


int PriorityQ::Size() const
{
    return count;
}	


Message PriorityQ::IsPresent(int uid) const
{
    Node* temp = frontPtr;

    for(int i = 0; i < count; i++) // iterate throgh the nodes 
    {
        if(temp->data.GetUID() == uid) // check to see if the UID's are equal
        {
            return temp->data;
        }

        temp = temp->nextPtr;
    }
    throw(InvalidUIDPQ());
}
	