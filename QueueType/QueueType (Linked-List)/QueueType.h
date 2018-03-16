#ifndef QUEUETYPE_H
#define QUEUETYPE_H

#include "ItemType.h"
#include <iostream>
using namespace std;

struct NodeType{
    ItemType info;
    NodeType* next;
};
class FullQueue{};
class EmptyQueue{};

class QueueType
{
private:
    NodeType* front;
    NodeType* rear;
public:
    QueueType();
    ~QueueType();
    void makeEmpty();
    bool isFull()const;
    bool isEmpty()const;
    void EnQueue(ItemType);
    void Dequeue(ItemType);
};

#endif // QUEUETYPE_H

