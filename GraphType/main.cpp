#include <iostream>
#include "GraphType.h"
#include <queue>


using namespace std;

int main()
{
    GraphType<string> g;
    g.AddVertex("Dallas");
    g.AddVertex("New York");
    g.AddEdge("Dallas","New York", 2000);
    cout << g.GetWeight("Dallas", "New York");
    queue<int> q;

    string s = "Dallas";
    g.GetToVertices("Dallas", q );
    g.GetToVertices(s, q);
    return 0;
}
