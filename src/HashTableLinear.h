#ifdef BUILD_HASHTABLELINEAR

#ifndef HASHTABLELINEAR_H
#define HASHTABLELINEAR_H

#include "LinkedList.h"
#include "ComplexKey.h"

class LinkedList;

class HashTableLinear {
  public:
    HashTableLinear();
    HashTableLinear(std::string fileName, int numItem);
    void insert(std::string email);
    bool hasItem(std::string email);
    void display();
    int hashFunction(std::string email);
  private:
    int numItem;
    int tableSize;
    Node** hashTable;
};

#endif
#endif
