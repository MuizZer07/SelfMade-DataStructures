#ifndef STACKTYPE_H
#define STACKTYPE_H

#include "Itemtype.h"
#include <iostream>
using namespace std;

const int MAX_ITEMS = 5;
class FullStack{};
class EmptyStack{};

class StackType
{
private:
    int top;
    ItemType info[MAX_ITEMS];
public:
    StackType();
    void makeEmpty();
    bool isFull()const;
    bool isEmpty()const;
    void push(ItemType);
    void pop();
    ItemType Top();
};
#endif // STACKTYPE_H
