#include <iostream>
#include <fstream>
#include <chrono> 

#ifdef BUILD_GENERATOR
#include "generator.h"
#endif
#ifdef BUILD_HASHTABLECHAIN
#include "hashTableChain.h"
#endif
#ifdef BUILD_HASHTABLELINEAR
#include "hashTableLinear.h"
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
  Generator generator;
  // Only run when debug build is enabled
  #ifdef BUILD_DEBUG
  std::cout << "Generator Build Debug" << std::endl;
  #endif
  #endif

  // same goes for the rest...
  #ifdef BUILD_HASHTABLECHAIN

  //setA
  auto insertStart = std::chrono::steady_clock::now();
  HashTableChain hashTableChain("SetA.txt", 100);
  auto insertStop = std::chrono::steady_clock::now();
  auto insertDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(insertStop - insertStart); 
  std::cout << "Time taken for hashtable insertion: " << insertDuration.count() << " nanoseconds" << std::endl; 

  //Existing Email from SetA.txt
  auto findEmailStart1 = std::chrono::steady_clock::now();
  if (hashTableChain.hasItem("GLO1.KLo9z@twqi.org")) {
    std::cout << "Has Email 1" << std::endl;
  } else {
    std::cout << "No Email 1" << std::endl;
  }
  auto findEmailStop1 = std::chrono::steady_clock::now();
  auto findEmailDuration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(findEmailStop1 - findEmailStart1); 
  std::cout << "Time taken for hashtable search: " << findEmailDuration1.count() << " nanoseconds" << std::endl; 

  //Non-Existing Email from NewSetA.txt
  auto findEmailStart2 = std::chrono::steady_clock::now();
  if (hashTableChain.hasItem("Z8Ym.X3rmT@9RbS.my")) {
    std::cout << "Has Email 2" << std::endl;
  } else {
    std::cout << "No Email 2" << std::endl;
  }
  auto findEmailStop2 = std::chrono::steady_clock::now();
  auto findEmailDuration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(findEmailStop2 - findEmailStart2); 
  std::cout << "Time taken for hashtable search: " << findEmailDuration2.count() << " nanoseconds" << std::endl; 

  #ifdef BUILD_DEBUG  

  std::ifstream file("SetA.txt");
  std::string email;
  while(std::getline(file, email)) {
    if (hashTableChain.hasItem(email)) {
      std::cout << "has item: " << email << std::endl;
    } else {
      std::cout << "No item: " << email << std::endl;
    }
  }

  std::ifstream file2("NewSetA.txt");
  std::string email2;
  while(std::getline(file2, email2)) {
    if (hashTableChain.hasItem(email2)) {
      std::cout << "has item: " << email2 << std::endl;
    } else {
      std::cout << "No item: " << email2 << std::endl;
    }
  }
  
  #endif
  #endif

  #ifdef BUILD_HASHTABLELINEAR
  #ifdef BUILD_DEBUG
  HashTableLinear hashTableLinear("SetA.txt", 100);
  std::ifstream file("SetA.txt");
  std::string email;
  while(true) {
    if (!std::getline(file, email)) {
      break;
    }
    if (hashTableLinear.hasItem(email)) {
      std::cout << "has item: " << email << std::endl;
    } else {
      std::cout << "No item: " << email << std::endl;
    }
  }

  std::ifstream file2("NewSetA.txt");
  std::string email2;
  while(std::getline(file2, email2)) {
    if (hashTableLinear.hasItem(email2)) {
      std::cout << "has item: " << email2 << std::endl;
    } else {
      std::cout << "No item: " << email2 << std::endl;
    }
  }
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