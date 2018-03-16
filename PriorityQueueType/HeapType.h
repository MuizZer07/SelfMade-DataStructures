#ifndef HEAPTYPE_H
#define HEAPTYPE_H

using namespace std;

template <class ItemType>
struct HeapType
{
    void ReheapDown(int root, int bottom);
    void ReheapUp(int root, int bottom);
    ItemType* elements;
    int numElements;
};
#include "HeapType.cpp"
#endif // HEAPTYPE_H
