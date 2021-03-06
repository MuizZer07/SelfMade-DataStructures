#include <iostream>
#include "ItemType.h"
#include "SortedType.h"
#include <fstream>

using namespace std;

int main()
{
    ItemType item1, item2, item3;
    item1.initialize(3);
    item2.initialize(4);
    item3.initialize(1);

    ofstream out("output.txt");

    SortedType u;
    u.putItem(item2);
    u.putItem(item1);
    u.putItem(item3);
    u.printList(out);
    u.deleteItem(item1);
    u.printList(out);
    u.makeEmpty();
    return 0;
}
