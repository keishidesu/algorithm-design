#ifdef BUILD_HASHTABLE

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedList.h"
#include <vector>
#include <unordered_map>

class LinkedList;

class HashTable {
  public:
    HashTable();
    HashTable(int numItem);
    void insert(std::string email);
    bool hasItem(std::string email);
    void display();
    int hashFunction(std::string email);
  private:
    int numItem;
    int tableSize;
    LinkedList* hashTable;
};

#endif
#endif
