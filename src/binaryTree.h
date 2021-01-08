#ifdef BUILD_BINARYTREE

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>
#include "ComplexKey.h"

struct avlnode {
    avlnode(std::string n) { current = ComplexKey(n); left = right = nullptr; height = 1; email = n;}
    std::string email;
    ComplexKey current;
    avlnode *left;
    avlnode *right;
    unsigned int height;
};

class BinaryTree {
  public:
    struct avlnode *root;
    BinaryTree(std::string fileName);
    avlnode *insertElement(avlnode *node, std::string newNode);
    avlnode *balance(avlnode *node);
    avlnode *leftRotate(avlnode *node);
    avlnode *rightRotate(avlnode *node);
    // avlnode *leftRightRotate(avlnode *node);
    // avlnode *rightLeftRotate(avlnode *node);
    int balanceFactor(avlnode *node);
    unsigned int getHeight(avlnode *node);
    void updateHeight(avlnode *node);
    // void searchElement(avlnode *node, std::string searchNode, int height, int index, bool found);
    void searchElement(avlnode *node, std::string searchNode);
};


#endif
#endif
