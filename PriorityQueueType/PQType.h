#ifndef PQTYPE_H
#define PQTYPE_H

class FullPQ{};
class EmptyPQ{};
#include "HeapType.h"

template<class ItemType>
class PQType
{
public:
    PQType(int);
    ~PQType();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    void Enqueue(ItemType newItem);
    void Dequeue();
    ItemType Front();
private:
    int length;
    HeapType<ItemType> items;
    int maxItems;
};
#include "PQType.cpp"
#endif // PQTYPE_H
