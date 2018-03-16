#include <iostream>
#include "ItemType.h"
#include "QueueType.h"

using namespace std;

int main()
{
    ItemType item1, item2, item3;
    item1.initialize(2);
    item2.initialize(26);
    item3.initialize(23);
    QueueType q;
    q.EnQueue(item1);
    q.Dequeue(item1);
    q.EnQueue(item2);
    cout << q.isEmpty() << endl;
    return 0;
}
