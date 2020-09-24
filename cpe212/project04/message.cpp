#include "message.h"

Message::Message()
{
    priority = UNKNOWN;
    message = "";
}                     

void Message::SetPriority(Priorities p)
{
    priority = p;
}

void Message::SetMessage(string msg)
{
    message = msg;
}

void Message::SetUID(int messageid)
{
    uid = messageid;
}

Priorities Message::GetPriority() const
{
    return priority;
}

string Message::GetMessage() const
{
    return message;
}

int Message::GetUID() const
{
    return uid;
}
