#ifdef BUILD_HASHTABLECHAIN

#ifndef HASHTABLECHAIN_H
#define HASHTABLECHAIN_H

#include "LinkedList.h"

class LinkedList;

class HashTableChain {
  public:
    HashTableChain();
    HashTableChain(std::string fileName, int numItem);
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
