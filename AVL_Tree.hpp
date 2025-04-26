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

    // need an AVL node constructor
    AVLNode(int val, AVLNode *par = nullptr)
    {
        value = val; // integer storing in node
        height = 1;
        // shouldn't be pointing to any children in constructor
        left = nullptr;
        right = nullptr;
        parent = par; // pointer to the node's parent
    }
};

class AVLTree
{
private:
    AVLNode *root;

    // recursive helpers here
    AVLNode *insertNode(AVLNode *node, int value, AVLNode *parent); // note: pass the parent pointer
    AVLNode *removeNode(AVLNode *node, int value);

    AVLNode *rotateLeft(AVLNode *node);
    AVLNode *rotateRight(AVLNode *node);

    AVLNode *rebalance(AVLNode *node);
    int getHeight(AVLNode *node);
    int getBalanceFactor(AVLNode *node);
    void printInOrder(AVLNode *node);
    void destroyTree(AVLNode *node);

public:
    // need a constructor and destructor for the avl tree??
    AVLTree();
    ~AVLTree();

    // public operations (will call recursive helpers, tree.insert(20) will call insertNode(root, 25))
    void insert(int value);
    void remove(int value);
    void printTree();
    AVLNode *getRoot(); // this is to make testing easier
};

#endif