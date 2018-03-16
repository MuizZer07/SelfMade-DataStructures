#ifndef TREETYPE_CPP
#define TREETYPE_CPP

#include "TreeType.h"

template<class ItemType>
TreeType<ItemType>::TreeType()
{
    root = NULL;
}
template<class ItemType>
void TreeType<ItemType>::destroy(TreeNode<ItemType>* &tree)
{
    if(tree != NULL)
    {
        destroy(tree->left);
        destroy(tree->right);
        delete tree;
    }
}
template<class ItemType>
TreeType<ItemType>::~TreeType()
{
    destroy(root);
}
template<class ItemType>
bool TreeType<ItemType>::isEmpty()const
{
    return (root ==  NULL);
}
template<class ItemType>
bool TreeType<ItemType>::isFull()const
{
    TreeNode<ItemType>* location;
    try{
        location = new TreeNode<ItemType>;
        delete location;
        return false;
    }catch(bad_alloc e)
    {
        return true;
    }
}
template <class ItemType>
int CountNodes(TreeNode<ItemType> *tree)
{
    if(tree == NULL) return 0;
    else return (CountNodes(tree->left) + CountNodes(tree->right)+ 1);
}
template<class ItemType>
int TreeType<ItemType>::getLength()const
{
    return CountNodes(root);
}
template <class ItemType>
void Retrieve(TreeNode<ItemType> *tree, ItemType& item, bool& found)
{
    if(tree == NULL) found = false;
    else if(item < tree->info) Retrieve(tree->left, item, found);
    else if(item > tree->info) Retrieve(tree->right, item, found);
    else
    {
        item = tree->info;
        found = true;
    }
}
template<class ItemType>
ItemType TreeType<ItemType>::getItem(ItemType item, bool& found)
{
    Retrieve(root, item, found);
    return item;
}



template<class ItemType>
void Insert(TreeNode<ItemType>* &tree, ItemType item)
{
    if(tree == NULL)
    {
        tree = new TreeNode<ItemType>;
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    }
    else if(item < tree->info) Insert(tree->left, item);

    else Insert(tree->right, item);
}
template<class ItemType>
void TreeType<ItemType>::putItem(ItemType item)
{
    Insert(root,item);
}



template<class ItemType>
void Delete(TreeNode<ItemType>*& tree, ItemType item)
{
    if(item < tree->info) Delete(tree->left, item);
    else if(item > tree->info) Delete(tree->right, item);
    else DeleteNode(tree);
}
template<class ItemType>
void DeleteNode(TreeNode<ItemType>*& tree)
{
      ItemType data;
    TreeNode<ItemType>* tempPtr;

    tempPtr = tree;
    if(tree->left == NULL)
    {
        tree = tree->right;
        delete tempPtr;
    }
    else if(tree->right == NULL){
        tree = tree->left;
        delete tempPtr;
    }
    else
    {
        GetPredecessor(tree->left, data);
        tree->info = data;
        Delete(tree->left, data);
    }
}
template<class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data)
{
    while(tree->right != NULL) tree=tree->right;
    data = tree->info;
}

template<class ItemType>
void TreeType<ItemType>::deleteItem(ItemType item)
{
  Delete(root, item);
}
template<class ItemType>
void printTree(TreeNode<ItemType>* tree, ofstream& out)
{
    if(tree != NULL)
    {
        printTree(tree->left, out);
        out << tree->info << " ";
        printTree(tree->right, out);
    }
}
template<class ItemType>
void TreeType<ItemType>::print(ofstream& out)const
{
    printTree(root, out);
}
#endif // TREETYPE_CPP
