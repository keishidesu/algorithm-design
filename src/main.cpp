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
  Generator generator;
  // Only run when debug build is enabled
  #ifdef BUILD_DEBUG
  std::cout << "Generator Build Debug" << std::endl;
  #endif
  #endif

  // same goes for the rest...
  #ifdef BUILD_HASHTABLE
  #ifdef BUILD_DEBUG  
  HashTable hashTable(10);

  std::string testEmailList[] = {
    "PCOS.bXWMe@gRBO.com",
    "sYSU.Azpug@Jxbd.org",
    "3pMt.nEG3G@mygr.org",
    "41OP.Wkad6@ZlsC.org",
    "GLO1.KLo9z@twqi.org",
    "rzwS.Tko9M@nUOu.my",
    "PEQX.HvjYk@lWVs.org",
    "hLp8.mKNHq@wIAY.com",
    "nZAm.Iyolb@AIWZ.my",
    "I8RP.cHnUM@kLWH.org"
  };

  for (int i = 0 ; i < 10 ; i++) {
    std::cout << testEmailList[i] << std::endl;
    hashTable.insert(testEmailList[i]);
  }

  if (hashTable.hasItem("hLp8.mKNHq@wIAY.com")) {
    std::cout << "Has Item 1";
  }

  if (hashTable.hasItem("LE75.3I8vE@rgWT.org")) {
    std::cout << "Has Item 2";
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