#include "Node.h"

Node::Node(ComplexKey key, std::string value) {
  this->key = key;
  this->value = value;
  nextNode = nullptr;
}

ComplexKey Node::getKey() { return key; }

std::string Node::getValue() { return value; }
