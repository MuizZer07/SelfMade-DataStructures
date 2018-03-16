#ifndef STACKTYPE_CPP
#define STACKTYPE_CPP

#include "StackType.h"

StackType::StackType()
{
    top = -1;
}
void StackType::makeEmpty()
{
    top = -1;
}
bool StackType::isEmpty()const
{
    return (top == -1);
}
bool StackType::isFull()const
{
    return (top == MAX_ITEMS-1);
}
void StackType::push(ItemType item)
{
    if(isFull()) throw FullStack();
    else{
        top++;
        info[top] = item;
    }
}
void StackType::pop()
{
    if(isEmpty()) throw EmptyStack();
    else top--;
}
ItemType StackType::Top()
{
    if(isEmpty()) throw EmptyStack();
    else return info[top];
}
#endif // STACKTYPE_CPP
