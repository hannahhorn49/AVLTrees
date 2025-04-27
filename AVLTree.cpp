#include "AVL_Tree.hpp"
#include <iostream>

// constructor
AVLTree::AVLTree()
{
    root = nullptr;
}

// destructor
AVLTree::~AVLTree()
{
    destroyTree(root);
}

void AVLTree::destroyTree(AVLNode *node)
{
    // base case here (already nullptr just return)
    if (node == nullptr)
    {
        return;
    }
    // recursively call destroy tree on left and right nodes
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

// implementation of public insert (most of work in recursive function)
void AVLTree::insert(int value)
{
    root = insertNode(root, value, nullptr);
}

AVLNode *AVLTree::insertNode(AVLNode *node, int value, AVLNode *parent)
{
    // to do: implement the recusive version of binary search tree insert, rebalance if needed
    // start with the base case (reached place to insert in tree)
    if (node == nullptr)
    {
        return new AVLNode(value, parent); // creates the new node here
    }

    // start recursive cases here (if value is less than/greater than current node)
    if (value < node->value) // if smaller -> insert to left subtree
    {
        node->left = insertNode(node->left, value, node);
    }
    else if (value > node->value) // if greater -> insert to the right subtree
    {
        node->right = insertNode(node->right, value, node);
    }
    else
    {
        return node;
    }

    // after insertion need to update the height
    // if a child was added then that child's height is 1 and its parent height must be updated and so on up the tree
    // get height of left and right subtree and the max takes the taller of the two
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

    // need to check if rebalance this node is needed?
    return rebalance(node);
}

// implementation of public remove (most of work in recursive function)
void AVLTree::remove(int value)
{
    root = removeNode(root, value);
}

AVLNode *AVLTree::removeNode(AVLNode *node, int value)
{
    // to do: implement recursive version of binary search tree remove, rebalance if needed
    // base case (if tree is empty or node to remove not found)
    if (node == nullptr)
    {
        return nullptr;
    }

    // start recursive calls here to search tree for value
    if (value < node->value) // if value smaller -> go left
    {
        node->left = removeNode(node->left, value);
    }
    else if (value > node->value) // if value greater -> go right
    {
        node->right = removeNode(node->right, value);
    }
    else
    {
        // this block is when we have found the node to delete
        // case 1: node to remove is a leaf node (no children)
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;    // no children so can just delete
            return nullptr; // return the nullptr so the parent doesn't point to anything
        }

        // case 2: node has one child (child takes node to delete place)
        else if (node->left == nullptr)
        {
            AVLNode *temp = node->right; // save the right child (this is what we replace the deleted node with)
            temp->parent = node->parent; // re connect the original node's parent to the new node
            delete node;
            return temp; // right child replaces current node
        }
        else if (node->right == nullptr)
        {
            AVLNode *temp = node->left; // this time save the left child
            temp->parent = node->parent;
            delete node;
            return temp; // left child replaces current node
        }

        // case 3: node has two children (replace with in order successor)
        else
        {
            // find in order successor (left most -- smallest-- value int he right subtree)
            AVLNode *in_order_successor = node->right;
            while (in_order_successor->left != nullptr) // means it hasn't reached smallest value
            {
                in_order_successor = in_order_successor->left; // continue left to reach smallest value
            }

            // replace current node (want to delete) value with in order successor value
            node->value = in_order_successor->value;

            // recurisvely delete the in order successor's node
            node->right = removeNode(node->right, in_order_successor->value);
        }
    }

    // need to update the height after removal
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

    // rebalance current node if needed
    return rebalance(node);
}

AVLNode *AVLTree::rotateLeft(AVLNode *node)
{
    // to do: rotate node to the left (ex. 10, 20, 30)
    // first need to find the new root of the subtree
    AVLNode *newRoot = node->right; // right child becomes new root (20)
    node->right = newRoot->left;

    if (newRoot->left != nullptr)
    {
        newRoot->left->parent = node;
    }

    newRoot->left = node;           // the current node (10) becomes the left child of the new root (20)
    newRoot->parent = node->parent; // re link the parent connection
    node->parent = newRoot;         // update the curent node parents

    // update heights
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    newRoot->height = std::max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

    return newRoot; // newRoot becomes the subtree root
}

AVLNode *AVLTree::rotateRight(AVLNode *node)
{
    // to do: rotate node to the right (ex. 30, 20, 10)
    AVLNode *newRoot = node->left; // left child becomes the new root (20)
    node->left = newRoot->right;
    if (newRoot->right != nullptr)
    {
        newRoot->right->parent = node;
    }

    newRoot->right = node;          // current node (30) becomes right child of newRoot
    newRoot->parent = node->parent; // link newRoot's parent
    node->parent = newRoot;         // update current node's parent

    // update heights
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    newRoot->height = std::max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

    return newRoot; // newRoot becomes the subtree root
}

AVLNode *AVLTree::rebalance(AVLNode *node)
{
    // to do: check balance factor and rotate if necessary
    int balance = getBalanceFactor(node);

    // case 1: left heavy (so need RIGHT rotation)
    if (balance > 1)
    {
        if (getBalanceFactor(node->left) < 0)
        {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }

    // case 2: right heavy (so need LEFT rotation)
    if (balance < -1)
    {
        if (getBalanceFactor(node->right) > 0)
        {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }

    // if after checks already balanced just return unchanged node
    return node;
}

int AVLTree::getHeight(AVLNode *node)
{
    // to do: return height or 0 if node is null
    if (node == nullptr)
    {
        return 0;
    }
    return node->height; // return stored height inside that node (already calculated when inserting, deleting, and rotating)
}

int AVLTree::getBalanceFactor(AVLNode *node)
{
    // to do: balance = height(left) - height(right)
    if (node == nullptr)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

void AVLTree::printInOrder(AVLNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    printInOrder(node->left);
    std::cout << node->value << " ";
    printInOrder(node->right);
}

void AVLTree::printTree()
{
    printInOrder(root);
    std::cout << std::endl;
}

AVLNode *AVLTree::getRoot()
{
    return root;
}
