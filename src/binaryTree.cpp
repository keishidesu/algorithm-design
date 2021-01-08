#ifdef BUILD_BINARYTREE

#include "binaryTree.h"
#include "ComplexKey.h"

#include <string>
#include <fstream>
#include <iostream>
#include <chrono>

BinaryTree::BinaryTree(std::string fileName) {
  root = nullptr;
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
    // searchElement(root, oldEmail, 0, 0, false);
       searchElement(root, oldEmail);
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
    // searchElement(root, newEmail, 0, 0, false);
    searchElement(root, newEmail);
  }
  oldFile.close();
  std::cout << "Searching Complete" << std::endl;
  auto newEnd = std::chrono::system_clock::now();

  std::chrono::duration<double> newDuration = newEnd - newStart;
  
  std::cout << "Searching Duration: " << newDuration.count() << "s\n";

}

avlnode *BinaryTree::insertElement(avlnode *node, std::string newNode) {
  if (!node) {
    std::cout << "Inserted " << newNode << std::endl;
    return new avlnode(newNode);
  }
  ComplexKey ck(newNode);
  if (ck < node -> current) {
    std::cout << "Go left" << std::endl;
    node -> left = insertElement(node -> left, newNode); 
  }
  else {
    std::cout << "Go Right" << std::endl;
    node -> right = insertElement(node -> right, newNode);
  }
  return balance(node);
}

// void BinaryTree::searchElement(avlnode *node, std::string searchNode, int height, int index, bool found) {
//   ComplexKey searchCK(searchNode);
//   if (node == nullptr) {
//     found = false;
//     std::cout << "Email " << searchNode << " is not found." << std::endl;
//   }
//   else if (node -> current > searchCK) {
//     searchElement(node -> left, searchNode, height + 1, (index*2)+1, found);
//     // std::cout << "Search Left " << std::endl;
//   }
//   else if (node -> current < searchCK) {
//     searchElement(node -> right, searchNode, height + 1, (index*2)+2, found);
//     // std::cout << "Search Right " << std::endl;
//   }
//   else {
//     found = true;
//     std::cout << "Email " << searchNode << " is found at height " << height << ", index " << index << "." << std::endl;
//   }
// }

void BinaryTree::searchElement(avlnode *node, std::string searchNode) {
  ComplexKey searchCK(searchNode);
  if (node == nullptr) {
    std::cout << "Email " << searchNode << " is not found." << std::endl;
  }
  else if (node -> current == searchCK) {
    std::cout << "Email " << searchNode << " is found." << std::endl;
    // std::cout << "Search Left " << std::endl;
  }
  else if (node -> current < searchCK) {
    searchElement(node -> right, searchNode);
    // std::cout << "Search Right " << std::endl;
  }
  else {
    searchElement(node -> left, searchNode);
  }
}

unsigned int BinaryTree::getHeight(avlnode *node) {
  // std::cout << "getting height" << std::endl;
  return node ? node -> height : 0;
  // if (node == nullptr) 
  //   return 0;
  // int leftHeight = getHeight(node -> left);
  // int rightHeight = getHeight(node -> right);
  // return std::max(leftHeight, rightHeight) + 1;
}

int BinaryTree::balanceFactor(avlnode *node) {
  // int leftHeight = getHeight(node -> left);
  // int rightHeight = getHeight(node -> right);
  // return rightHeight - leftHeight;
  return getHeight(node -> right) - getHeight(node -> left);
}

void BinaryTree::updateHeight(avlnode *node) {
  // std::cout << "updating height" << std::endl;
  // unsigned int leftHeight = getHeight(node->left);
  // unsigned int rightHeight = getHeight(node->right);
  node -> height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
}

avlnode *BinaryTree::balance(avlnode *node) {
  std::cout << "balancing" << std::endl;
  updateHeight(node);
  if (balanceFactor(node) < -1) {
    if(balanceFactor(node -> left) > 0)
      node -> left = leftRotate(node);
    return rightRotate(node);
  }
  else if (balanceFactor(node) > 1) {
    if(balanceFactor(node -> right) < 0)
      node -> right = rightRotate(node);
    return leftRotate(node);
  }
  return node;
}

// Rotations functions
avlnode *BinaryTree::rightRotate(avlnode *node) {
  std::cout << "right rotating "  << std::endl;
  avlnode *temp =  node -> left;
  node -> left = temp -> right;
  temp -> right = node;
  updateHeight(node);
  updateHeight(temp);
  return temp;
}

avlnode *BinaryTree::leftRotate(avlnode *node) {
  std::cout << "left rotating" << std::endl;
  avlnode *temp = node -> right;
  node -> right = temp -> left;
  temp -> left = node;
  updateHeight(node);
  updateHeight(temp);
  return temp;
}

// avlnode *BinaryTree::leftRightRotate(avlnode *node) {
//   // std::cout << "left right rotating" << std::endl;
//   avlnode *temp = node -> left;
//   node -> left = leftRotate(temp);
//   return rightRotate(node);
// }

// avlnode *BinaryTree::rightLeftRotate(avlnode *node) {
//   // std::cout << "right left rotating" << std::endl;
//   avlnode *temp = node -> right;
//   node -> right = rightRotate(temp);
//   return leftRotate(node);
// }

#endif
 