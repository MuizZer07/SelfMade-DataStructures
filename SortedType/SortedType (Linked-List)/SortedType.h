#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

#include "ItemType.h"
#include <iostream>
using namespace std;

struct NodeType{
    ItemType info;
    NodeType* next;
};

class SortedType
{
private:
    NodeType* listdata;
    NodeType* currentPos;
    int length;
public:
    SortedType();
    ~SortedType();
    void makeEmpty();
    int getLength()const;
    ItemType getItem(ItemType, bool);
    bool isFull()const;
    void putItem(ItemType);
    void deleteItem(ItemType);
    void resetList();
    ItemType getNextItem();
    void printList(ofstream&);
};
#endif // SORTEDTYPE_H
