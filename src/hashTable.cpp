#ifdef BUILD_HASHTABLE

#define PRIME_CONSTANT 9277;

#include "HashTable.h"
#include "LinkedList.h"
#include "Node.h"
#include "ComplexKey.h"
#include <sstream>
#include <unordered_map>
#include <vector>

HashTable::HashTable() {}

HashTable::HashTable(int numItem) {
  this->numItem = numItem;
  this->tableSize = numItem*0.9;
  std::cout << "tablesize:" << tableSize << std::endl;
  this->hashTable = new LinkedList[tableSize];
}

void HashTable::insert(std::string email) {
  ComplexKey emailKey(email);
  int index = hashFunction(email);
  std::cout << "Index:" << index << std::endl;
  Node* node = new Node(emailKey, email);
  this->hashTable[index].insertNode(node);
}

bool HashTable::hasItem(std::string email) {
  ComplexKey emailKey(email);
  int index = hashFunction(email);
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
