#ifdef BUILD_PRIORITYQUEUE

#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE

#include "Node.h"
#include <vector>
#include <string>

class PriorityQueue {
  public:
    std::vector<Node> heap; 
    std::string name;
    PriorityQueue();
    PriorityQueue(std::string fileName);
    void enqueue(Node elem);
    void dequeue();
    void dequeue(int percentage);
    int size();
    void print();
    void printToFile(std::string filename);
  private:
    void heapifyEnqueue(int index);
    void heapifyDequeue(int index);
    Node getNode(std::string email);
};

#endif
#endif
