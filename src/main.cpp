#include <iostream>
#include <fstream>
#include <chrono> 
#include <Windows.h> 

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
  std::cout << "Generator Builded!" << std::endl;
  // Only run when debug build is enabled
  #ifdef BUILD_DEBUG
  std::cout << "Generator Build Debug" << std::endl;
  #endif
  #endif

  // same goes for the rest...
  #ifdef BUILD_HASHTABLECHAIN

  constexpr int runs = 2000;

  // insertion
  auto insertStart = std::chrono::system_clock::now();
  HashTableChain hashTableChain("SetA.txt", 100);
  auto insertStop = std::chrono::system_clock::now();
  auto insertDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(insertStop - insertStart); 
  std::cout << "Time taken for hashtable chain insertion: " << insertDuration.count() << " nanoseconds" << std::endl; 

  //find exist email
  auto findExistEmailStart = std::chrono::system_clock::now();
  std::ifstream oldFile("OldSetA.txt");
  std::string oldEmail;
  for (int i = 0; i < runs; ++i) {
    while(std::getline(oldFile, oldEmail)) {
      if (hashTableChain.hasItem(oldEmail)) {
        std::cout << "has item: " << oldEmail << std::endl;
      } else {
        std::cout << "No item: " << oldEmail << std::endl;
      }
    }
  }
  auto findExistEmailStop = std::chrono::system_clock::now();
  auto findExistEmailDuration = findExistEmailStop - findExistEmailStart; 
  std::cout << "Average time taken for finding existing email with hashtable chain: " << std::chrono::duration<double, std::nano>(findExistEmailDuration).count()/runs << " nanoseconds" << std::endl; 
  
  //find non exist email
  auto findEmailStart = std::chrono::system_clock::now();
  std::ifstream newFile("NewSetA.txt");
  std::string newEmail;
  for (int i = 0; i < runs; ++i) {
    while(std::getline(newFile, newEmail)) {
      if (hashTableChain.hasItem(newEmail)) {
        std::cout << "has item: " << newEmail << std::endl;
      } else {
        std::cout << "No item: " << newEmail << std::endl;
      }
    }
  }
  auto findEmailStop = std::chrono::system_clock::now();
  auto findEmailDuration = findEmailStop - findEmailStart; 
  std::cout << "Average time taken for finding non-existing email with hashtable chain: " << std::chrono::duration<double, std::nano>(findEmailDuration).count()/runs << " nanoseconds" << std::endl; 

  
  #ifdef BUILD_DEBUG  
  
  #endif
  #endif

  #ifdef BUILD_HASHTABLELINEAR

  constexpr int runs = 2000;

  // insertion
  auto insertStart = std::chrono::steady_clock::now();
  HashTableLinear hashTableLinear("SetA.txt", 100);
  auto insertStop = std::chrono::steady_clock::now();
  auto insertDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(insertStop - insertStart); 
  std::cout << "Time taken for hashtable linear insertion: " << insertDuration.count() << " nanoseconds" << std::endl; 

  //find exist email
  auto findExistEmailStart = std::chrono::system_clock::now();
  std::ifstream oldFile("OldSetA.txt");
  std::string oldEmail;
  for (int i = 0; i < runs; ++i) {
    while(std::getline(oldFile, oldEmail)) {
      if (hashTableLinear.hasItem(oldEmail)) {
        std::cout << "has item: " << oldEmail << std::endl;
      } else {
        std::cout << "No item: " << oldEmail << std::endl;
      }
    }
  }
  auto findExistEmailStop = std::chrono::system_clock::now();
  auto findExistEmailDuration = findExistEmailStop - findExistEmailStart; 
  std::cout << "Average time taken for finding existing email with hashtable linear: " << std::chrono::duration<double, std::nano>(findExistEmailDuration).count()/runs << " nanoseconds" << std::endl; 
  
  //find non exist email
  auto findEmailStart = std::chrono::system_clock::now();
  std::ifstream newFile("NewSetA.txt");
  std::string newEmail;
  for (int i = 0; i < runs; ++i) {
    while(std::getline(newFile, newEmail)) {
      if (hashTableLinear.hasItem(newEmail)) {
        std::cout << "has item: " << newEmail << std::endl;
      } else {
        std::cout << "No item: " << newEmail << std::endl;
      }
    }
  }
  auto findEmailStop = std::chrono::system_clock::now();
  auto findEmailDuration = findEmailStop - findEmailStart; 
  std::cout << "Average time taken for finding non-existing email with hashtable linear: " << std::chrono::duration<double, std::nano>(findEmailDuration).count()/runs << " nanoseconds" << std::endl; 

  #ifdef BUILD_DEBUG
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