#ifndef UNSORTEDTYPE_CPP
#define UNSORTEDTYPE_CPP

#include "UnsortedType.h"

UnsortedType::UnsortedType()
{
    length = 0;
    listdata = NULL;
    currentPos = NULL;
}
UnsortedType::~UnsortedType()
{
    NodeType* location;
    while(listdata != NULL)
    {
        location = listdata;
        listdata = listdata->next;
        delete location;
    }
}
void UnsortedType::makeEmpty()
{
    NodeType* location;
    while(listdata != NULL)
    {
        location = listdata;
        listdata = listdata->next;
        delete location;
    }
}
bool UnsortedType::isFull()const
{
    try{
        NodeType* temp;
        temp= new NodeType;
        delete temp;
        return false;
       }catch(bad_alloc ex){
            return true;
        }

}
int UnsortedType::getLength()const
{
    return length;
}
ItemType UnsortedType::getItem(ItemType item, bool& found)
{
    NodeType* location;
    location = listdata;
    bool moreToSearch;
    found = false;

    moreToSearch=(location != NULL);
    while(moreToSearch && !found)
    {
        switch(item.CompareTo(location->info))
        {
        case LESS:
        case GREATER:
            location = location->next;
            moreToSearch = (location != NULL);
            break;
        case EQUAL:
            found = true;
            item = location->info;
            break;
        }
    }
    return item;
}
void UnsortedType::putItem(ItemType item)
{
    NodeType* location;
    location = new NodeType;
    location->info = item;
    location->next=listdata;
    listdata = location;
    length++;
}
void UnsortedType::deleteItem(ItemType item)
{
    NodeType* location = listdata;
    NodeType* tempLocation;

    if(item.CompareTo(listdata->info) == EQUAL)
    {
       tempLocation = listdata;
       listdata = listdata->next;
    }
    else
    {
        while(item.CompareTo(location->next->info)!= EQUAL)
        {
            location = location->next;
        }

        tempLocation = location->next;
        location->next = location->next->next;
    }
    delete tempLocation;
    length--;
}
void UnsortedType::resetList()
{
    currentPos = NULL;
}
ItemType UnsortedType::getNextItem()
{
    if(currentPos==NULL) currentPos = listdata;
    else currentPos = currentPos->next;

    return currentPos->info;
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
#endif // UNSORTEDTYPE_CPP


