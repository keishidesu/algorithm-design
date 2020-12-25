#ifndef NODE_H
#define NODE_H

#include <string>
#include "ComplexKey.h"

class ComplexKey;

class Node {
  public:
    Node();
    Node(ComplexKey key, std::string value);
    ComplexKey getKey();
    std::string getValue();
    Node *nextNode;
  private:
    ComplexKey key;
    std::string value;
};

#endif