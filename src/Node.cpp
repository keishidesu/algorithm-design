#include "Node.h"

Node::Node() {
  isEmpty = true;
}

Node::Node(ComplexKey key, std::string value) {
  this->key = key;
  this->value = value;
  nextNode = nullptr;
  isEmpty = false;
}

ComplexKey Node::getKey() { return key; }

std::string Node::getValue() { return value; }

bool Node::getIsEmpty() {
  return isEmpty;
}
