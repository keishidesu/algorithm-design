#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include "ComplexKey.h"
#include <string>

class Node;

class LinkedList {
  public:
    LinkedList();
    LinkedList(Node* head);
    void insertNode(Node* node);
    Node* getNode(ComplexKey key);
  private:
    Node* head;
    Node* tail;
};

#endif