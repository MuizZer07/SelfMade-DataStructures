#ifndef QUEUETYPE_CPP
#define QUEUETYPE_CPP

#include "QueueType.h"

QueueType::QueueType()
{
    rear = NULL;
    front = NULL;
}
QueueType::~QueueType()
{
    NodeType* temp;
    while(front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}
void QueueType::makeEmpty()
{
    NodeType* temp;
    while(front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}
bool QueueType::isEmpty()const
{
    return (front == NULL);
}
bool QueueType::isFull()const
{
    NodeType* location;
    try{
        location = new NodeType;
        delete location;
        return false;
    }catch(bad_alloc ex)
    {
        return true;
    }
}
void QueueType::EnQueue(ItemType item)
{
    if(isFull()) throw FullQueue();
    else{
        NodeType* newNode;
        newNode = new NodeType;
        newNode->info = item;
        newNode->next = NULL;

        if(rear == NULL) front = newNode;
        else {
            rear->next = newNode;
            newNode = rear;
        }
    }
 }
void QueueType::Dequeue(ItemType item)
{
    if(isEmpty()) throw EmptyQueue();
    else{
        NodeType* temp;

        temp = front;
        item = front->info;
        front = front->next;
        if(front == NULL) rear = NULL;
        delete temp;
    }
}
#endif // QUEUETYPE_CPP

