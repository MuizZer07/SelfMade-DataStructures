#ifndef TREETYPE_H
#define TREETYPE_H

#include <iostream>
#include <fstream>
using namespace std;

template<class ItemType>
struct TreeNode
{
public:
    ItemType info;
    TreeNode* left;
    TreeNode* right;
};

template<class ItemType>
class TreeType
{
public:
     TreeType();
     ~TreeType();
     void destroy(TreeNode<ItemType>* &tree);
     bool isEmpty()const;
     bool isFull() const;
     int getLength()const;
     ItemType getItem(ItemType, bool&);
     void putItem(ItemType);
     void deleteItem(ItemType);
     void print(ofstream& out) const;
private:
    TreeNode<ItemType> *root;
};
#include "TreeType.cpp"
#endif // TREETYPE_H
