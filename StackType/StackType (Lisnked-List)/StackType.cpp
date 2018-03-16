#ifndef STACKTYPE_CPP
#define STACKTYPE_CPP

#include "StackType.h"

StackType::StackType()
{
   topPtr = NULL;
}
StackType::~StackType()
{
    NodeType* temp;
    while(topPtr != NULL)
    {
        temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
    }

}
void StackType::makeEmpty()
{
    NodeType* temp;
    while(topPtr != NULL)
    {
        temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
    }
}
bool StackType::isEmpty()const
{
    return (topPtr == NULL);
}
bool StackType::isFull()const
{
    NodeType* newNode;
    try{
        newNode = new NodeType;
        delete newNode;
        return false;
    }catch(bad_alloc ex)
    {
        return true;
    }
}
void StackType::push(ItemType item)
{
    if(isFull()) throw FullStack();
    else{
        NodeType* location;
        location = new NodeType;
        location->info = item;
        location->next = topPtr;
        topPtr = location;
    }
}
void StackType::pop()
{
    if(isEmpty()) throw EmptyStack();
    else{
        NodeType* temp;
        temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
    }
}
ItemType StackType::Top()
{
    if(isEmpty()) throw EmptyStack();
    else return topPtr->info;
}
#endif // STACKTYPE_CPP

