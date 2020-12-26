#ifdef BUILD_HASHTABLE

#define PRIME_CONSTANT 9277;

#include "HashTable.h"
#include "LinkedList.h"
#include "Node.h"
#include "ComplexKey.h"
#include <sstream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <iostream>

HashTable::HashTable() {}

HashTable::HashTable(std::string fileName, int numItem) {
  this->numItem = numItem;
  this->tableSize = numItem*0.9;
  this->hashTable = new LinkedList[tableSize];

  std::ifstream file(fileName);
  std::string email;
  while(std::getline(file, email)) {
    insert(email);
    //std::cout << email << std::endl;
  }
}

void HashTable::insert(std::string email) {
  ComplexKey emailKey(email);
  int index = hashFunction(email);
  //std::cout << "Index: " << index << std::endl;
  Node* node = new Node(emailKey, email);
  this->hashTable[index].insertNode(node);
}

bool HashTable::hasItem(std::string email) {
  ComplexKey emailKey(email);
  int index = hashFunction(email);
  //std::cout << "finding item index:" << index << std::endl;
  if (this->hashTable[index].getNode(emailKey)) { return true; }
  return false;
}

int HashTable::hashFunction(std::string email) {
  ComplexKey emailKey(email);
  int nameA = emailKey.getNameA() % tableSize;
  int nameB = emailKey.getNameB() % tableSize;
  int nameDomain = emailKey.getNameDomain() % tableSize;
  unsigned long long int c = nameA * nameB * nameDomain * emailKey.getTopLevelDomain() * PRIME_CONSTANT;
  return c % tableSize;
}
#endif
