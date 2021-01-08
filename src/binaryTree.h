#ifdef BUILD_BINARYTREE

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>
#include "ComplexKey.h"

class AvlNode {
    public:
    // AvlNode(std::string n) { current = ComplexKey(n); left = right = nullptr; height = 1; email = n;}
    std::string email;
    ComplexKey current;
    AvlNode *left;
    AvlNode *right;
    unsigned int height;
    AvlNode(std::string newNode) {current = ComplexKey(newNode); left = right = NULL; height = 1; email = newNode;}
};

class BinaryTree {
  public:
    unsigned int getHeight(AvlNode *node);
    BinaryTree(std::string fileName);
    AvlNode *insertElement(AvlNode *node, std::string newNode);
    AvlNode *leftRotate(AvlNode *node);
    AvlNode *rightRotate(AvlNode *node);
    int balanceFactor(AvlNode *node);
    void searchElement(AvlNode *node, std::string searchNode, int index);
    // void searchElement(AvlNode *node, std::string searchNode);
};


#endif
#endif