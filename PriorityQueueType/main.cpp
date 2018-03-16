#include <iostream>
#include "PQType.h"

using namespace std;

int main()
{
    PQType<int> p(5);

    p.Enqueue(1);
    p.Enqueue(34);
    p.Enqueue(2);
    p.Enqueue(5);
    p.Enqueue(3);


    cout << p.Front() << endl;
    p.Dequeue();

    cout << p.Front() << endl;
    return 0;
}
