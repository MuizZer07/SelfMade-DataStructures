#ifndef PQTYPE_CPP
#define PQTYPE_CPP

#include "PQType.h"

template<class ItemType>
PQType<ItemType>::PQType(int max)
{
    maxItems = max;
    items.elements = new ItemType[max];
    length = 0;
}
template<class ItemType>
PQType<ItemType>::~PQType()
{
    delete [] items.elements;
}
template<class ItemType>
void PQType<ItemType>::MakeEmpty()
{
    length = 0;
}
template<class ItemType>
bool PQType<ItemType>::IsFull()
{
    return length == maxItems;
}
template<class ItemType>
bool PQType<ItemType>::IsEmpty()
{
    return length == 0;
}

template<class ItemType>
void PQType<ItemType>::Dequeue()
{
    if (length == 0)
        throw EmptyPQ();
    else
    {
        ItemType item = items.elements[0];
        items.elements[0] = items.elements[length-1];
        length--;
        items.ReheapDown(0, length-1);
    }
}
template<class ItemType>
void PQType<ItemType>::Enqueue(ItemType newItem)
{
    if (length == maxItems)
        throw FullPQ();
    else
    {
        length++;
        items.elements[length-1] = newItem;
        items.ReheapUp(0, length-1);
    }
}
template<class ItemType>
ItemType PQType<ItemType>::Front()
{
    return items.elements[0];
}
#endif // PQTYPE_CPP



