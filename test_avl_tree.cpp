#include "AVL_Tree.hpp"
#include <iostream>

bool testInsert()
{
    std::cout << "\nRunning Insert Node Test\n";
    // set up
    AVLTree tree;

    // execution
    tree.insert(15);
    tree.insert(5);
    tree.insert(75);

    // validation
    AVLNode *root = tree.getRoot();
    if (root->value != 10 || root->left->value != 5 || root->right->value != 20)
    {
        std::cerr << "Insert test failed: unexpected tree structure.\n";
        return false;
    }

    // clean up
    return true;
}

bool testRemove()
{
    std::cout << "\nRunning Remove Node Test\n";

    // set up
    AVLTree tree;

    // execution
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(15);
    tree.insert(25);
    tree.insert(35);

    // validation
    // case 1: remove a leaf node (e.g. 5)
    tree.remove(5);
    if (tree.getRoot()->left->left != nullptr)
    {
        std::cerr << "Remove test failed: leaf node not removed.\n";
        return false;
    }

    // case 2: remove node with one child
    tree.remove(25);
    if (tree.getRoot()->right->left != nullptr)
    {
        std::cerr << "Remove test failed: one-child node not removed properly.\n";
        return false;
    }

    // case 3: Remove a node with two children
    tree.remove(10);
    AVLNode *rootLeft = tree.getRoot()->left;
    if (!rootLeft || rootLeft->value != 15)
    {
        std::cerr << "Remove test failed: two-child node not handled correctly.\n";
        return false;
    }

    std::cout << "Remove test passed.\n";
    return true;
}

bool testLeftRotation()
{
    std::cout << "\nRunning Left Rotation Test\n";

    // set up
    AVLTree tree; // create a instance of AVL tree

    // execution
    tree.insert(5);
    tree.insert(15);
    tree.insert(75);
    // should be 5 -> 15 -> 75 so right heavy and trigger left rotation at 5 (root of subtree)

    // validation
    AVLNode *root = tree.getRoot();
    if (!root || root->value != 15)
        return false;
    if (!root->left || root->left->value != 5)
        return false;
    if (!root->right || root->right->value != 75)
        return false;

    // clean up
    return true;
}

bool testRightRotation()
{
    std::cout << "\nRunning Right Rotation Test\n";

    // set up
    AVLTree tree;

    // execution
    tree.insert(75);
    tree.insert(15);
    tree.insert(5); // triggers right rotation at 15

    // validation
    AVLNode *root = tree.getRoot();
    if (!root || root->value != 15)
        return false;
    if (!root->left || root->left->value != 5)
        return false;
    if (!root->right || root->right->value != 75)
        return false;

    // clean up
    return true;
}

bool testRebalanceLeftRight()
{
    // idk if we need to test left right or right left bc it should be based on single left right rotations?
    std::cout << "\nRunning Left-Right Rotation Test\n";

    // set up
    AVLTree tree;

    // execution
    tree.insert(30);
    tree.insert(10);
    tree.insert(20); // triggers Left-Right rotation at 30

    // validation
    AVLNode *root = tree.getRoot();
    if (!root || root->value != 20)
        return false;
    if (!root->left || root->left->value != 10)
        return false;
    if (!root->right || root->right->value != 30)
        return false;

    // clean up
    return true;
}

// calling tests here
bool testInsert();
bool testRemove();
bool testLeftRotation();
bool testRightRotation();
bool testRebalanceLeftRight();

int main()
{
    std::cout << "Running AVL Tree Tests...\n";

    if (testInsert())
        std::cout << "Insert test passed.\n";
    else
        std::cout << "Insert test failed.\n";

    if (testRemove())
        std::cout << "Remove test passed.\n";
    else
        std::cout << "Remove test failed.\n";

    if (testLeftRotation())
        std::cout << "Left rotation test passed.\n";
    else
        std::cout << "Left rotation test failed.\n";

    if (testRightRotation())
        std::cout << "Right rotation test passed.\n";
    else
        std::cout << "Right rotation test failed.\n";

    if (testRebalanceLeftRight())
        std::cout << "Left-Right rotation test passed.\n";
    else
        std::cout << "Double rotation test failed.\n";

    return 0;
}