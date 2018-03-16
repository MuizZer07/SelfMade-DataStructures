#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

#include "ItemType.h"
#include <iostream>
using namespace std;

const int MAX_ITEMS = 5;

class SortedType
{
  private:
    ItemType items[MAX_ITEMS];
    int length;
    int currentPos;
  public:
    SortedType();
    void makeEmpty();
    int getLength()const;
    bool isFull()const;
    void putItem(ItemType);
    void deleteItem(ItemType);
    ItemType getItem(ItemType, bool);
    void resetList();
    ItemType getNextItem();
    void printList(ofstream&);
};
#endif // SORTEDTYPE_H

