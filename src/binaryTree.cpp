#ifdef BUILD_BINARYTREE

#include "binaryTree.h"
#include "ComplexKey.h"

#include <string>
#include <fstream>
#include <iostream>
#include <chrono>

BinaryTree::BinaryTree() {}

BinaryTree::BinaryTree(std::string fileName) {
  root = nullptr;
  int x;
  std::string name = fileName;
  std::cout << "Inserting " << fileName << "..." << std::endl;
  auto start = std::chrono::system_clock::now();
  std::ifstream file(fileName);
  std::string email;
  while(std::getline(file, email)){
    // ComplexKey ck(email);
    root = insertElement(root, email);
    // std::cout << email << std::endl;
  }
  file.close();
  std::cout << "Insertion Complete" << std::endl;
  auto end = std::chrono::system_clock::now();

  std::chrono::duration<double> duration = end - start;
  
  std::cout << "Inserting Duration: " << duration.count() << "s\n";

  // search existed email from respective file
  std::string oldFileName = "Old" + fileName;
  std::cout << "Searching from " << oldFileName << "..." << std::endl;
  auto oldStart = std::chrono::system_clock::now();
  std::ifstream oldFile(oldFileName);
  std::string oldEmail;
  while(std::getline(oldFile, oldEmail)){
    searchElement(root, oldEmail, 0, 0, false);
  }
  oldFile.close();
  std::cout << "Searching Complete" << std::endl;
  auto oldEnd = std::chrono::system_clock::now();

  std::chrono::duration<double> oldDuration = oldEnd - oldStart;
  
  std::cout << "Searching Duration: " << oldDuration.count() << "s\n";

  // search not existing email from respective file
  std::string newFileName = "New" + fileName;
  std::cout << "Searching from " << newFileName << "..." << std::endl;
  auto newStart = std::chrono::system_clock::now();
  std::ifstream newFile(newFileName);
  std::string newEmail;
  while(std::getline(newFile, newEmail)){
    searchElement(root, newEmail, 0, 0, false);
  }
  oldFile.close();
  std::cout << "Searching Complete" << std::endl;
  auto newEnd = std::chrono::system_clock::now();

  std::chrono::duration<double> newDuration = newEnd - newStart;
  
  std::cout << "Searching Duration: " << newDuration.count() << "s\n";

}

avlnode *BinaryTree::insertElement(avlnode *node, std::string newNode) {
  ComplexKey newCK(newNode);
  if (node == nullptr) { // if the node does not exist
    node = new avlnode;
    node -> email = newNode;
    node -> current = newCK; 
    node -> left = nullptr;
    node -> right  = nullptr;
    // std::cout << "Inserted " << newNode << std::endl;
    return node;
  }
  else if (newCK < node -> current) {
    // std::cout << "Go left " << std::endl;
    node -> left = insertElement(node -> left, newNode);
    node = balance(node);
  }
  else if (newCK > node -> current || newCK == node -> current) {
    // std::cout << "Go right " << std::endl;
    node -> right = insertElement(node -> right, newNode);
    node = balance(node);
  }
  return node;
}

void BinaryTree::searchElement(avlnode *node, std::string searchNode, int height, int index, bool found) {
  ComplexKey searchCK(searchNode);
  if (node == nullptr) {
    found = false;
    std::cout << "Email " << searchNode << " is not found." << std::endl;
  }
  else if (node -> current > searchCK) {
    searchElement(node -> left, searchNode, height + 1, (index*2)+1, found);
    // std::cout << "Search Left " << std::endl;
  }
  else if (node -> current < searchCK) {
    searchElement(node -> right, searchNode, height + 1, (index*2)+2, found);
    // std::cout << "Search Right " << std::endl;
  }
  else {
    found = true;
    std::cout << "Email " << searchNode << " is found at height " << height << ", index " << index << "." << std::endl;
  }
}

int BinaryTree::getHeight(avlnode *node) {
  if (node == nullptr) 
    return 0;
  int leftHeight = getHeight(node -> left);
  int rightHeight = getHeight(node -> right);
  return std::max(leftHeight, rightHeight) + 1;
  }

int BinaryTree::balanceFactor(avlnode *node) {
  int leftHeight = getHeight(node -> left);
  int rightHeight = getHeight(node -> right);
  return rightHeight - leftHeight;
}

avlnode *BinaryTree::balance(avlnode *node) {
  // std::cout << "balancing" << std::endl;
  int bf = balanceFactor(node);
  if (bf < -1) {
    if(balanceFactor(node -> left) < 0)
      node = rightRotate(node);
    else
      node = leftRightRotate(node);
  }
  else if (bf > 1) {
    if(balanceFactor(node -> right) < 0)
      node = rightLeftRotate(node);
    else
      node = leftRotate(node);
  }
  return node;
}

// Rotations functions
avlnode *BinaryTree::rightRotate(avlnode *node) {
  // std::cout << "right rotating " << node -> left -> email << " and " << node -> email << std::endl;
  avlnode *temp =  node -> left;
  node -> left = temp -> right;
  temp -> right = node;
  return temp;
}

avlnode *BinaryTree::leftRotate(avlnode *node) {
  // std::cout << "left rotating" << node -> right -> email << " and " << node -> email << std::endl;
  avlnode *temp =  node -> right;
  node -> right = temp -> left;
  temp -> left = node;
  return temp;
}

avlnode *BinaryTree::leftRightRotate(avlnode *node) {
  // std::cout << "left right rotating" << std::endl;
  avlnode *temp = node -> left;
  node -> left = leftRotate(temp);
  return rightRotate(node);
}

avlnode *BinaryTree::rightLeftRotate(avlnode *node) {
  // std::cout << "right left rotating" << std::endl;
  avlnode *temp = node -> right;
  node -> right = rightRotate(temp);
  return leftRotate(node);
}

#endif
 