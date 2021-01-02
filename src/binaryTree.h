#ifdef BUILD_BINARYTREE

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>
#include "ComplexKey.h"

struct avlnode {
    ComplexKey current;
    avlnode *left;
    avlnode *right;
};

class BinaryTree {
  public:
    BinaryTree();
    BinaryTree(std::string fileName);
    struct avlnode *root = nullptr;
    avlnode *insertElement(avlnode *node, std::string newNode);
    avlnode *balance(avlnode *node);
    avlnode *leftRotate(avlnode *node);
    avlnode *rightRotate(avlnode *node);
    avlnode *leftRightRotate(avlnode *node);
    avlnode *rightLeftRotate(avlnode *node);
    int greater(int x, int y);
    int balanceFactor(avlnode *node);
    int getHeight(avlnode *node);
    void searchElement(avlnode *node, std::string searchNode, int height, int index, bool found);
    void printToFile(std::string fileName);
};


#endif
#endif
