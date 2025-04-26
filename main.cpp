// this file should generate the first 25 fibonacci numbers
// insert them into the AVL tree
// print the tree out

#include <iostream>
#include <vector>
#include "AVL_Tree.hpp"

// should create a helper function to generate first n (in our case 25) fibonacci numbers
// store them in a vector
std::vector<int> generateFibonacciNums(int n)
{
    std::vector<int> fibNums;
    if (n <= 0)
    {
        return fibNums;
    }

    // put the "base case" fibonacci numbers here (first two -- 0 and 1)
    fibNums.push_back(0);
    if (n == 1)
    {
        return fibNums;
    }

    fibNums.push_back(1);

    // now we can make the loop to generate how many we want
    for (int i = 2; i < n; ++i)
    {
        fibNums.push_back(fibNums[i - 1] + fibNums[i - 2]);
    }

    return fibNums;
}

int main()
{
    AVLTree tree;

    // call generate function here
    std::vector<int> fibonacciNumbers = generateFibonacciNums(25);

    // loop through and add each fibonacci number to tree
    for (int num : fibonacciNumbers)
    {
        tree.insert(num);
    }

    // call print tree function from avl tree class
    std::cout << "This is the In-order traversal of an AVL tree after inserting the first 25 Fibonacci numbers:" << std::endl;
    tree.printTree();

    return 0;
}