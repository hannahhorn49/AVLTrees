#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

class AVLNode
{
public:
    int value;
    int height;
    AVLNode *left;
    AVLNode *right;
    AVLNode *parent;

    // need a AVLNode constructor here?
};

class AVLTree
{
private:
    AVLNode *root;

    // if we want to do recursive -- helper, main functions here
    // need a insert node, delete node, rotate left, rotate right, rebalance
    // get height, get balance factor, printing function

public:
    // need a constructor and destructor for the avl tree
};

#endif