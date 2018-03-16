#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

#include "ItemType.h"
#include <iostream>
using namespace std;

const int MAX_ITEMS = 5;
class UnsortedType
{
private:
    ItemType info[MAX_ITEMS];
    int length;
    int currentPos;
public:
    UnsortedType();
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
#endif // UNSORTEDTYPE_H

