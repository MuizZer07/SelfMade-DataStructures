#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

#include "ItemType.h"
#include <iostream>
using namespace std;

struct NodeType{
    ItemType info;
    NodeType* next;
};
class UnsortedType
{
private:
    NodeType* listdata;
    int length;
    NodeType* currentPos;
public:
    UnsortedType();
    ~UnsortedType();
    int getLength()const;
    bool isFull()const;
    ItemType getItem(ItemType, bool&);
    void deleteItem(ItemType);
    void putItem(ItemType);
    void makeEmpty();
    void resetList();
    ItemType getNextItem();
    void printList(ofstream&);
};
#endif // UNSORTEDTYPEL_H


