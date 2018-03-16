#ifndef SORTEDTYPE_CPP
#define SORTEDTYPE_CPP

#include "SortedType.h"

SortedType::SortedType()
{
    length = 0;
    listdata = NULL;
}
SortedType::~SortedType()
{
   NodeType* temp;
    while(listdata != NULL)
    {
        temp = listdata;
        listdata = listdata->next;
        delete temp;
    }
}
void SortedType::makeEmpty()
{
    NodeType* temp;
    while(listdata != NULL)
    {
        temp = listdata;
        listdata = listdata->next;
        delete temp;
    }
}
int SortedType::getLength()const
{
    return length;
}
ItemType SortedType::getItem(ItemType item, bool found)
{
    NodeType* location = listdata;
    bool moretosearch = (location != NULL);
    found = false;

    while(moretosearch && !found)
    {
        switch(item.CompareTo(location->info))
        {
        case LESS:
            moretosearch = false;
            break;
        case GREATER:
            location = location->next;
            moretosearch = (location != NULL);
            break;
        case EQUAL:
            found = true;
            item = location->info;
            break;
        }
    }
    return item;
}
void SortedType::putItem(ItemType item)
{
    NodeType* location = listdata;
    NodeType* predLoc = NULL;
    NodeType* newNode;

    bool moretosearch = (location != NULL);
    while(moretosearch)
    {
        switch(item.CompareTo(location->info))
        {
        case LESS:
            moretosearch = false;
            break;
        case GREATER:
            predLoc = location;
            location = location->next;
            moretosearch = (location != NULL);
            break;
        }
    }
    newNode =  new NodeType;
    newNode->info = item;

    if(predLoc == NULL){
        newNode->next = listdata;
        listdata = newNode;
    }
    else
    {
        newNode->next = location;
        predLoc = newNode;
    }
    length++;
}
void SortedType::deleteItem(ItemType item)
{
    NodeType* location = listdata;
    NodeType* temp;

    if(item.CompareTo(location->info)==EQUAL)
    {
        temp = listdata;
        listdata = listdata->next;
    }
    else
    {
        while(item.CompareTo(location->next->info) != EQUAL) location = location->next;

        temp = location->next;
        location->next = location->next->next;
    }
    delete temp;
    length--;
}
bool SortedType::isFull()const
{
    NodeType* newNode;
    try{
        newNode = new NodeType;
        delete newNode;
        return false;
    }catch(bad_alloc ex){
        return true;
    }
}
void SortedType::resetList()
{
    currentPos = NULL;
}
ItemType SortedType::getNextItem()
{
    if(currentPos == NULL) currentPos = listdata;
    else currentPos = currentPos->next;

    return currentPos->info;
}
void SortedType::printList(ofstream& out)
{
    resetList();
    for(int i=0; i<length; i++)
    {
        getNextItem().print(out);
    }
}
#endif // SORTEDTYPE_CPP
