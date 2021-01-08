#ifdef BUILD_BINARYTREE

#include "binaryTree.h"
#include "ComplexKey.h"

#include <string>
#include <fstream>
#include <iostream>
#include <chrono>

BinaryTree::BinaryTree(std::string fileName) {
  AvlNode *root = NULL;
  std::cout << "Inserting " << fileName << "..." << std::endl;
  auto start = std::chrono::system_clock::now();
  std::ifstream file("output/" + fileName);
  std::string email;
  while(std::getline(file, email)){
    root = insertElement(root, email);
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
  std::ifstream oldFile("output/" + oldFileName);
  std::string oldEmail;
  while(std::getline(oldFile, oldEmail))
    searchElement(root, oldEmail, 0);
  oldFile.close();
  std::cout << "Searching Complete" << std::endl;
  auto oldEnd = std::chrono::system_clock::now();

  std::chrono::duration<double> oldDuration = oldEnd - oldStart;
  
  std::cout << "Searching Duration: " << oldDuration.count() << "s\n";

  // search not existing email from respective file
  std::string newFileName = "New" + fileName;
  std::cout << "Searching from " << newFileName << "..." << std::endl;
  auto newStart = std::chrono::system_clock::now();
  std::ifstream newFile("output/" + newFileName);
  std::string newEmail;
  while(std::getline(newFile, newEmail))
    searchElement(root, newEmail, 0);
  oldFile.close();
  std::cout << "Searching Complete" << std::endl;
  auto newEnd = std::chrono::system_clock::now();

  std::chrono::duration<double> newDuration = newEnd - newStart;
  
  std::cout << "Searching Duration: " << newDuration.count() << "s\n";

}

unsigned int BinaryTree::getHeight(AvlNode *node) {return (node) ? node->height : 0;}

int BinaryTree::balanceFactor(AvlNode *node) {
  if(node == NULL) return 0;
  return getHeight(node -> left) - getHeight(node -> right);
}

AvlNode *BinaryTree::rightRotate(AvlNode *node) {
  AvlNode *temp = node -> left;
  AvlNode *temp2 = temp -> right;
  temp -> right = node;
  node -> left = temp2;
  node -> height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
  temp -> height = std::max(getHeight(temp->left), getHeight(temp->right)) + 1;
  return temp;
}

AvlNode *BinaryTree::leftRotate(AvlNode *node) {
  AvlNode *temp = node -> right;
  AvlNode *temp2 = temp -> left;
  temp -> left = node;
  node -> right = temp2;
  node -> height = std::max(getHeight(node -> left), getHeight(node -> right)) + 1;
  temp -> height = std::max(getHeight(temp -> left), getHeight(temp -> right)) + 1;
  return temp;
}

AvlNode *BinaryTree::insertElement(AvlNode *node, std::string newNode) {
  if (node == NULL)
    return (new AvlNode(newNode));

  ComplexKey ck(newNode);
  if (ck < node -> current)
    node -> left = insertElement(node -> left, newNode);
  else
    node -> right = insertElement(node -> right, newNode);

  // update parent node height
  node -> height = std::max(getHeight(node->left), getHeight(node -> right)) + 1;

  int bal = balanceFactor(node);
  if (bal > 1) {
    if (ck > node -> left -> current) 
      node -> left = leftRotate(node -> left); 
    return rightRotate(node);
  }
  else if (bal < -1)
  {
    if (ck < node -> right -> current)
      node -> right = rightRotate(node -> right);
    return leftRotate(node);
  }

  return node;  
}

void BinaryTree::searchElement(AvlNode *node, std::string searchNode, int index) {
  ComplexKey searchCK(searchNode);
  if (node == nullptr) {
    std::cout << "No item: " << searchNode << std::endl;
  }
  else if (node -> current > searchCK)
    searchElement(node -> left, searchNode, (index * 2) + 1);
  else if (node -> current < searchCK)
    searchElement(node -> right, searchNode, (index * 2) + 2);
  else {
    std::cout << "Has item: " << searchNode << " at height " << node->height << ", index " << index << "." << std::endl;
  }
}

#endif
 