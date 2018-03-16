#include <iostream>
#include "Itemtype.h"
#include "StackType.h"
#include <fstream>
using namespace std;

int main()
{
    ItemType item1, item2, item3;
    item1.initialize(2);
    item2.initialize(4);
    item3.initialize(7);
    StackType s;
    s.push(item1);
    s.push(item3);
    s.pop();
    ofstream out("text.txt");
    ItemType item = s.Top();
    item.print(out);
    return 0;
}
