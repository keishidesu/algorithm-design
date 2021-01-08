#ifdef BUILD_HASHTABLELINEAR

#define PRIME_CONSTANT 9277;

#include "HashTableLinear.h"
#include "LinkedList.h"
#include "Node.h"
#include "ComplexKey.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstring>

HashTableLinear::HashTableLinear() {}

HashTableLinear::HashTableLinear(std::string fileName, int numItem) {
  int numEmail = 0;
  this->numItem = numItem;
  this->tableSize = numItem*1.5;
  this->hashTable = new Node*[tableSize](); 

  std::ifstream file(fileName);
  std::string email;
  while(std::getline(file, email)) {
    if (numEmail > numItem) break;
    numEmail++;
    insert(email);
  }
}

void HashTableLinear::insert(std::string email) {
  ComplexKey emailKey(email);
  int index = hashFunction(email);
  while (hashTable[index] != nullptr && hashTable[index]->getKey() != emailKey) {
    std::cout << tableSize;
    if (++index >= tableSize) { 
      index = 0;
    }
  }
  hashTable[index] = new Node(emailKey, email);
}

bool HashTableLinear::hasItem(std::string email) {
  ComplexKey emailKey(email);
  int index = hashFunction(email);
  int i = index;
  while (true) {
    if (hashTable[i] != nullptr) {
      if (hashTable[i]->getKey() == emailKey) { return true; }
    }
    i++;
    if (i >= tableSize) i = 0;
    if (i == index) { break; }
  }
  return false;
}

int HashTableLinear::hashFunction(std::string email) {
  ComplexKey emailKey(email);
  int nameA = emailKey.getNameA() % tableSize;
  int nameB = emailKey.getNameB() % tableSize;
  int nameDomain = emailKey.getNameDomain() % tableSize;
  unsigned long long int c = nameA * nameB * nameDomain * emailKey.getTopLevelDomain() * PRIME_CONSTANT;
  return c % tableSize;
}
#endif
