#ifndef ITEMTYPE_H
#define ITEMTYPE_H

using namespace std;
#include <fstream>
#include <iostream>

enum RelationType{ GREATER, LESS, EQUAL};

class ItemType
{
private:
    int value;
public:
    ItemType();
    RelationType CompareTo(ItemType)const;
    void print(ofstream&) const;
    void initialize(int);
};

#endif // ITEMTYPE_H

