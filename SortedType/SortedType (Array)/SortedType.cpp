#ifndef SORTEDTYPE_CPP
#define SORTEDTYPE_CPP

#include "SortedType.h"

SortedType::SortedType()
{
    length = 0;
    currentPos = -1;
}
void SortedType::makeEmpty()
{
    length = 0;
}
int SortedType::getLength()const
{
    return length;
}
bool SortedType::isFull()const
{
    return (length == MAX_ITEMS);
}
void SortedType::putItem(ItemType item)
{
   int location = 0;
   bool moretosearch = (location < length);

   while(moretosearch)
   {
       switch(item.CompareTo(items[location]))
       {
       case LESS:
            moretosearch = false;
            break;
       case GREATER:
            location++;
            moretosearch = (location < length);
            break;
       }
   }
   for(int i = length; i > location; i--)
   {
       items[i] = items[i-1];
   }
   items[location] = item;
   length++;
}
void SortedType::deleteItem(ItemType item)
{
    int location =0;
    bool moretosearch = (location < length);

    while(item.CompareTo(items[location])!= EQUAL) location++;

    for(int i=location; i<length; i++)
    {
        items[i] = items[location+1];
    }
    length--;
}
ItemType SortedType::getItem(ItemType item, bool found)
{
    int midpoint, first = 0, last = length-1;
    bool moretosearch = ( first <= last);
    found = false;

    while(moretosearch && !found)
    {
        midpoint = (first+last)/2;
        switch(item.CompareTo(items[midpoint]))
        {
        case LESS:
            last = midpoint-1;
            moretosearch = (first <= last);
            break;
        case GREATER:
            first = midpoint + 1;
            moretosearch = (first <= last);
            break;
        case EQUAL:
            found = true;
            item = items[midpoint];
        }
    }
    return item;
}
void SortedType::resetList()
{
    currentPos = -1;
}
ItemType SortedType::getNextItem()
{
    currentPos++;
    return items[currentPos];
}
void SortedType::printList(ofstream& out)
{
    resetList();
    for(int i= 0; i<getLength();i++)
    {
        getNextItem().print(out);
    }
}
#endif // SORTEDTYPE_CPP
