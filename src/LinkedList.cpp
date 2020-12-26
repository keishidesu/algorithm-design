#include "LinkedList.h"
#include "Node.h"
#include "ComplexKey.h"
#include <iostream>

LinkedList::LinkedList() {
  this->head = nullptr;
  this->tail = nullptr;
}

LinkedList::LinkedList(Node* head) {
  this->head = head;
  this->tail = head;
}

void LinkedList::insertNode(Node* node) {
  if (!head) { 
    this->head = node;
    this->tail = node;
    return;
  }
  this->tail->nextNode = node;
  this->tail = node;
}

Node* LinkedList::getNode(ComplexKey key) {
  Node* currentNode = this->head;
  if (!currentNode) return nullptr;
  do {
    if (currentNode->getKey() == key) return currentNode;
    currentNode = currentNode->nextNode;
  } while (currentNode);
  
  return nullptr;
}
