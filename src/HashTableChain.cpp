#ifdef BUILD_HASHTABLECHAIN

#define PRIME_CONSTANT 9277;

#include "HashTableChain.h"
#include "LinkedList.h"
#include "Node.h"
#include "ComplexKey.h"
#include <sstream>
#include <fstream>
#include <iostream>

HashTableChain::HashTableChain() {}

HashTableChain::HashTableChain(std::string fileName, int numItem) {
  this->numItem = numItem;
  this->tableSize = numItem*0.9;
  this->hashTable = new LinkedList[tableSize];

  std::ifstream file(fileName);
  std::string email;
  while(std::getline(file, email)) {
    insert(email);
  }
}

void HashTableChain::insert(std::string email) {
  ComplexKey emailKey(email);
  int index = hashFunction(email);
  Node* node = new Node(emailKey, email);
  this->hashTable[index].insertNode(node);
}

bool HashTableChain::hasItem(std::string email) {
  ComplexKey emailKey(email);
  int index = hashFunction(email);
  if (this->hashTable[index].getNode(emailKey)) { return true; }
  return false;
}

int HashTableChain::hashFunction(std::string email) {
  ComplexKey emailKey(email);
  int nameA = emailKey.getNameA() % tableSize;
  int nameB = emailKey.getNameB() % tableSize;
  int nameDomain = emailKey.getNameDomain() % tableSize;
  unsigned long long int c = nameA * nameB * nameDomain * emailKey.getTopLevelDomain() * PRIME_CONSTANT;
  return c % tableSize;
}
#endif
