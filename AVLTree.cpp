#include "AVL_Tree.hpp"

// constructor
AVLTree::AVLTree()
{
    root = nullptr;
}

// destructor??
AVLTree::~AVLTree()
{
    // need a function to destroy the tree here?
}

// do we need a destroytree function implementation for the deconstructor here??

// implementation of public insert (most of work in recursive function)
void AVLTree::insert(int value)
{
    root = insertNode(root, value, nullptr);
}

AVLNode *AVLTree::insertNode(AVLNode *node, int value, AVLNode *parent)
{
    // to do: implement the recusive version of binary search tree insert, rebalance if needed
}

// implementation of public remove (most of work in recursive function)
void AVLTree::remove(int value)
{
    root = removeNode(root, value);
}

AVLNode *AVLTree::removeNode(AVLNode *node, int value)
{
    // to do: implement recursive version of binary search tree remove, rebalance if needed
}

AVLNode *AVLTree::rotateLeft(AVLNode *node)
{
    // to do: rotate node to the left
}

AVLNode *AVLTree::rotateRight(AVLNode *node)
{
    // to do: rotate node to the right
}

AVLNode *AVLTree::rebalance(AVLNode *node)
{
    // to do: check balance factor and rotate if necessary
}

int AVLTree::getHeight(AVLNode *node)
{
    // to do: return height or 0 if node is null
    return 0;
}

int AVLTree::getBalanceFactor(AVLNode *node)
{
    // to do: balance = height(left) - height(right)
    return 0;
}

// do we need a print in order implementation that we call in print tree??

void AVLTree::printTree()
{
    // to do: someway to print in order function call here
}

AVLNode *AVLTree::getRoot()
{
    return root;
}
