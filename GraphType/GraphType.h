#ifndef GRAPHTYPE_H
#define GRAPHTYPE_H
#include <queue>
#include <iostream>
using namespace std;

template<class VertexType>
class GraphType {

public:
    GraphType();
    GraphType(int);
    ~GraphType();
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    void AddVertex(VertexType);
    void AddEdge(VertexType, VertexType, int);
    int GetWeight(VertexType, VertexType);
    bool IsEdge(VertexType from, VertexType to)const;
    void GetToVertices(VertexType, queue<VertexType>&);
    void GetFromVertices(VertexType, queue<VertexType>&);
    void ClearMarks();
    void MarkVertex(VertexType);
    bool IsMarked(VertexType) const;

private:
    int numVertices;
    int maxVertices;
    VertexType* vertices;
    int **edges;
    bool* marks;
};
#endif // GRAPHTYPE_H
#include "GraphType.cpp"

