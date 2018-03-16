#ifndef UNSORTED_CPP
#define UNSORTED_CPP

#include "UnsortedType.h"

UnsortedType::UnsortedType()
{
    length = 0;
}
void UnsortedType::makeEmpty()
{
    length = 0;
}
bool UnsortedType::isFull()const
{
    return (length==MAX_ITEMS);
}
int UnsortedType::getLength()const
{
    return length;
}
ItemType UnsortedType::getItem(ItemType item, bool& found)
{
    bool moreToSearch;
    int location = 0;
    found = false;

    moreToSearch=(location < length);
    while(moreToSearch && !found)
    {
        switch(item.CompareTo(info[location]))
        {
        case LESS:
        case GREATER:
            location++;
            moreToSearch = (location<length);
            break;
        case EQUAL:
            found = true;
            item = info[location];
            break;
        }
    }
    return item;
}
void UnsortedType::putItem(ItemType item)
{
    info[length] = item;
    length++;
}
void UnsortedType::deleteItem(ItemType item)
{
    int location = 0;
    while(item.CompareTo(info[location])!=EQUAL) location++;

    info[location]=info[length-1];
    length--;
}
void UnsortedType::resetList()
{
    currentPos = -1;
}
ItemType UnsortedType::getNextItem()
{
    currentPos++;
    return info[currentPos];
}
void UnsortedType::printList(ofstream& out)
{
        resetList();
        for(int i=0; i<getLength(); i++)
        {
          getNextItem().print(out);
        }
        out << endl;
}
#endif // UNSORTED_CPP


