#ifndef GRAPHTYPE_CPP
#define GRAPHTYPE_CPP

#include "GraphType.h"

const int NULL_EDGE = 0;


template<class VertexType>
GraphType<VertexType>::GraphType()
{
    int maxV = 50;
    numVertices = 0;
    maxVertices = maxV;
    vertices = new VertexType[maxV];
    edges = new int*[maxV];

    for(int i = 0; i < maxV; i++)
    edges[i] = new int[maxV];

    marks = new bool[maxV];
}
template<class VertexType>
GraphType<VertexType>::GraphType(int maxV)
{
    numVertices = 0;
    maxVertices = maxV;
    vertices = new VertexType[maxV];
    edges = new int*[maxV];

    for(int i = 0; i < maxV; i++)
    edges[i] = new int[maxV];

    marks = new bool[maxV];
}

template<class VertexType>
GraphType<VertexType>::~GraphType()
{
    delete [] vertices;

    for(int i = 0; i < maxVertices; i++)
    delete [] edges[i];

    delete [] edges;
    delete [] marks;
}

template<class VertexType>
void GraphType<VertexType>::AddVertex(VertexType
vertex)
{
    vertices[numVertices] = vertex;
    for(int index = 0; index < numVertices; index++)
    {
        edges[numVertices][index] = NULL_EDGE;
        edges[index][numVertices] = NULL_EDGE;
    }
    numVertices++;
}
template<class VertexType>
int IndexIs(VertexType* vertices, VertexType vertex)
{
    int index = 0;
    while(!(vertex == vertices[index])) index++;

    return index;
}
template<class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromVertex, VertexType toVertex, int weight)
{
    int row;
    int col;
    row = IndexIs(vertices, fromVertex);
    col = IndexIs(vertices, toVertex);
    edges[row][col] = weight;
}

template<class VertexType>
int GraphType<VertexType>::GetWeight(VertexType fromVertex, VertexType toVertex)
{
    int row;
    int col;
    row = IndexIs(vertices, fromVertex);
    col = IndexIs(vertices, toVertex);
    return edges[row][col];
}

template<class VertexType>
void GraphType<VertexType>::GetToVertices(VertexType vertex, queue<VertexType>& adjvertices)
{
    int fromIndex;
    int toIndex;
    fromIndex = IndexIs(vertices, vertex);

    for(toIndex = 0; toIndex < numVertices; toIndex++)
        if(edges[fromIndex][toIndex] != NULL_EDGE)
           adjvertices.push(vertices[toIndex]);
}
template<class VertexType>
void GraphType<VertexType>::GetFromVertices(VertexType vertex, queue<VertexType>& adjvertices)
{
    int fromIndex;
    int toIndex;
    fromIndex = IndexIs(vertices, vertex);

    for(toIndex = 0; toIndex < numVertices; toIndex++)
        if(edges[toIndex][fromIndex] != NULL_EDGE)
           adjvertices.push(vertices[fromIndex]);
}

template<class VertexType>
bool GraphType<VertexType>::IsEdge(VertexType from, VertexType to)const
{
    int fromIndex;
    int toIndex;

    toIndex = IndexIs(vertices, to);
    fromIndex = IndexIs(vertices, from);

    if(edges[fromIndex][toIndex] != NULL_EDGE)
        return 1;
    else return 0;
}
template<class VertexType>
void GraphType<VertexType>::MarkVertex(VertexType vertex)
{
    int in = IndexIs(vertices, vertex);
    marks[in] = true;
}
template<class VertexType>
bool GraphType<VertexType>::IsMarked(VertexType vertex)const
{
    int in = IndexIs(vertices, vertex);
    return marks[in];
}
template<class VertexType>
void GraphType<VertexType>::ClearMarks()
{
    for(int i=0; i<numVertices; i++)
    {
        marks[i] = false;
    }
}
#endif // GRAPHTYPE_CPP
