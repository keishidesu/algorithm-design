#ifdef BUILD_PRIORITYQUEUE

#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE

#include "Node.h"
#include <vector>
#include <string>

class PriorityQueue {
  public:
    std::vector<Node> heap; 
    PriorityQueue();
    PriorityQueue(std::vector<Node> heaps);
    PriorityQueue(std::string fileName);
    void enqueue(Node elem);
    Node dequeue();
    int size();
    Node getNode(std::string email);
    void print();
  private:
    void heapifyEnqueue(int index);
    void heapifyDequeue(int index);
};

#endif
#endif
