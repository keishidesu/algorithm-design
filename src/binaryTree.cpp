#ifdef BUILD_BINARYTREE

#include "binaryTree.h"
#include "ComplexKey.h"

#include <string>
#include <fstream>
#include <iostream>
#include <chrono>

BinaryTree::BinaryTree() {}

BinaryTree::BinaryTree(std::string fileName) {
  int x;
  std::string name = fileName;
  std::cout << "Inserting " << fileName << "..." << std::endl;
  auto start = std::chrono::system_clock::now();
  std::ifstream file(fileName);
  std::string email;
  while(std::getline(file, email)){
    // std::cout << email << std::endl;
    ComplexKey ck(email);
    // std::cout << ck.getNameA << std::endl;
    // std::cout << ck.getNameB << std::endl;
    // std::cout << ck.getNameDomain << std::endl;
    insertElement(root, email);
  }
  file.close();
  std::cout << "Insertion Complete" << std::endl;
  auto end = std::chrono::system_clock::now();

  std::chrono::duration<double> duration = end - start;
  
  std::cout << "Inserting Duration: " << duration.count() << "s\n";

  // search from respective file
  std::string searchFileName = "Old" + fileName;
  std::cout << "Searching from " << searchFileName << "..." << std::endl;
  start = std::chrono::system_clock::now();
  std::ifstream searchfile(searchFileName);
  std::string searchEmail;
  while(std::getline(file, searchEmail)){
    searchElement(root, searchEmail, 0, 1, false);
  }
  file.close();
  std::cout << "Searching Complete" << std::endl;
  end = std::chrono::system_clock::now();

  duration = end - start;
  
  std::cout << "Searching Duration: " << duration.count() << "s\n";
}

avlnode *BinaryTree::insertElement(avlnode *node, std::string newNode) {
  ComplexKey newCK(newNode);
  if (node == nullptr) { // if the node does not exist
    node = new avlnode;
    node -> current = newCK; 
    node -> left = nullptr;
    node -> right  = nullptr;
    std::cout << "Inserted " << newNode << std::endl;
  }
  else if (newCK < node->current)
    node -> left = insertElement(node -> left, newNode);
  else
    node -> right = insertElement(node -> right, newNode);
  return node;
}

void BinaryTree::searchElement(avlnode *node, std::string searchNode, int height, int index, bool found) {
  ComplexKey searchCK(searchNode);
  std::cout << "in SE" << std::endl;
  if (node == nullptr) {
    found = false;
    std::cout << "Email " << searchNode << " is not found." << std::endl;
  }
  else if (node -> current > searchCK) {
    searchElement(node -> left, searchNode, height + 1, index*2+1, found);
  }
  else if (node -> current < searchCK) {
    searchElement(node -> right, searchNode, height + 1, index*2+2, found);
  }
  else {
    found = true;
    std::cout << "Email " << searchNode << " is found at height " << height << ", index " << index << "." << std::endl;
  }
}

int BinaryTree::greater(int x, int y) {
  if ( x > y ) 
    return x;
  return y;
}

int BinaryTree::getHeight(avlnode *node) {
  int height = 0;
  if (node == nullptr) 
    return height;
  int leftHeight = getHeight(node -> left);
  int rightHeight = getHeight(node -> right);
  return greater(leftHeight, rightHeight) + 1;
}

int BinaryTree::balanceFactor(avlnode *node) {
  int leftHeight = getHeight(node -> left);
  int rightHeight = getHeight(node -> right);
  return rightHeight - leftHeight;
}

avlnode *BinaryTree::balance(avlnode *node) {
  int bf = balanceFactor(node);
  if (bf < -1) {
    if(balanceFactor(node -> left))
      node = rightRotate(node);
    else
      node = leftRightRotate(node);
  }
  else if (bf > 1) {
    if(balanceFactor(node -> right))
      node = rightLeftRotate(node);
    else
      node = leftRotate(node);
  }
  return node;
}

// Rotations functions
avlnode *BinaryTree::rightRotate(avlnode *node) {
  avlnode *temp =  node -> left;
  node -> left = temp -> right;
  temp -> right = node;
  return temp;
}

avlnode *BinaryTree::leftRotate(avlnode *node) {
  avlnode *temp =  node -> right;
  node -> right = temp -> left;
  temp -> left = node;
  return temp;
}

avlnode *BinaryTree::leftRightRotate(avlnode *node) {
  avlnode *temp = node -> left;
  node -> left = leftRotate(temp);
  return rightRotate(node);
}

avlnode *BinaryTree::rightLeftRotate(avlnode *node) {
  avlnode *temp = node -> right;
  node -> right = leftRotate(temp);
  return leftRotate(node);
}

#endif
 