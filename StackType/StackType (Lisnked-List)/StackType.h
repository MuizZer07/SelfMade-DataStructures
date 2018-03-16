#ifndef STACKTYPE_H
#define STACKTYPE_H

#include "Itemtype.h"
#include <iostream>
using namespace std;

struct NodeType{
    ItemType info;
    NodeType* next;
};
class FullStack{};
class EmptyStack{};

class StackType
{
private:
    NodeType* topPtr;
public:
    StackType();
    ~StackType();
    void makeEmpty();
    bool isFull()const;
    bool isEmpty()const;
    void push(ItemType);
    void pop();
    ItemType Top();
};
#endif // STACKTYPE_H

