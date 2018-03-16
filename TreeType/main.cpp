#include <iostream>
#include "TreeType.h"
#include <fstream>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    TreeType<int> t;

    if(in.is_open())
    {
        while(in >> n)
        {
            t.putItem(n);
        }
    }
    else cout << "Unable to open the file." << endl;

    return 0;
}
