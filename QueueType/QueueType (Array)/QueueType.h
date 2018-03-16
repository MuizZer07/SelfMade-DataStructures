#ifndef QUEUETYPE_H
#define QUEUETYPE_H

#include "ItemType.h"
#include <iostream>
using namespace std;

const int MAX_ITEMS = 5;

class FullQueue{};
class EmptyQueue{};

class QueueType
{
private:
    int rear;
    int front;
    int maxQue;
    ItemType* items;
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
