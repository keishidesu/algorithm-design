#include <iostream>
#ifdef BUILD_GENERATOR
#include "generator.h"
#endif
#ifdef BUILD_HASHTABLE
#include "hashTable.h"
#endif
#ifdef BUILD_BINARYTREE
#include "binaryTree.h"
#endif
#ifdef BUILD_PRIORITYHEAP
#include "priorityHeap.h"
#endif

int main() {

  // example
  // Only run under generator build
  #ifdef BUILD_GENERATOR
  Generator obj;
  std::cout << "Generator Build: " << obj.value << std::endl;
  // Only run when debug build is enabled
  #ifdef BUILD_DEBUG
  std::cout << "Generator Build Debug" << std::endl;
  #endif
  #endif

  // same goes for the rest...
  #ifdef BUILD_HASHTABLE
  HashTable obj;
  std::cout << "Hash Table Build: " << obj.value << std::endl;
  #ifdef BUILD_DEBUG
  std::cout << "Hash Table Build Debug" << std::endl;
  #endif
  #endif

  #ifdef BUILD_BINARYTREE
  BinaryTree obj;
  std::cout << "Binary Tree Build: " << obj.value << std::endl;
  #ifdef BUILD_DEBUG
  std::cout << "Binary Tree Build Debug" << std::endl;
  #endif
  #endif

  #ifdef BUILD_PRIORITYHEAP
  PriorityHeap obj;
  std::cout << "Priority Heap Build: " << obj.value << std::endl;
  #ifdef BUILD_DEBUG
  std::cout << "Priority Heap Build Debug" << std::endl;
  #endif
  #endif

  // code that share amongst all the build
  // not warpped in any define
  std::cout << "Program ended!" << std::endl;
  return 0;

  // run "build" or "build debug" at root folder for some experimental examples...
}