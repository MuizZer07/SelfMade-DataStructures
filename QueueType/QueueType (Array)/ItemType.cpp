#ifndef ITEMTYPE_CPP
#define ITEMTYPE_CPP

#include "ItemType.h"

ItemType::ItemType()
{
    value = 0;
}
RelationType ItemType::CompareTo(ItemType newItem)const
{
    if(value > newItem.value) return GREATER;
    else if(value < newItem.value) return LESS;
    else return EQUAL;
}
void ItemType::print(ofstream& out)const
{
    out << value << endl;
}
void ItemType::initialize(int value)
{
    this->value = value;
}
#endif // ITEMTYPE_CPP


