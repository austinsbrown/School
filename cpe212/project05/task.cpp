#include "task.h"

Task::Task()
{
    taskPriority = -1;
    taskName = "";

}


Task::Task(int priority, string name)
{
    taskPriority = priority;
    taskName = name;
}


Task::Task(const Task&  i)
{
    this->taskPriority = i.taskPriority;
    this->taskName = i.taskName;
}

bool operator==(const Task& leftop, const Task& rightop)
{
    if(leftop.taskPriority == rightop.taskPriority)
    {
        return true;
    }

    else {return false;}
}

bool operator<(const Task& leftop, const Task& rightop)
{
    if(leftop.taskPriority < rightop.taskPriority) {return true;}
    else {return false;}
}

bool operator<=(const Task& leftop, const Task& rightop)
{
    if(leftop.taskPriority <= rightop.taskPriority) {return true;}
    else {return false;}
}

bool operator>(const Task& leftop, const Task& rightop)
{
    if(leftop.taskPriority > rightop.taskPriority) {return true;}
    else {return false;}
}


void Task::operator=(const Task& op)
{
    this->taskName = op.taskName;
    this->taskPriority = op.taskPriority;
}
