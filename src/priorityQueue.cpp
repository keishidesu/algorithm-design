#ifdef BUILD_PRIORITYQUEUE

#include "priorityQueue.h"
#include "Node.h"
#include "ComplexKey.h"

#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <cmath>

PriorityQueue::PriorityQueue() {

}

PriorityQueue::PriorityQueue(std::string fileName) {
  name = fileName;
  std::cout << "Inserting " << fileName << "..." << std::endl;
  auto start = std::chrono::system_clock::now();
  std::ifstream file(fileName);
  std::string email;
  while(std::getline(file, email)){
    enqueue(getNode(email));
  }
  file.close();
  auto end = std::chrono::system_clock::now();

  std::chrono::duration<double> duration = end - start;
  
  std::cout << "Duration: " << duration.count() << "s\n";
}

Node PriorityQueue::getNode(std::string email) {
  ComplexKey emailKey(email);
  Node node(emailKey, email);
  return node;
}

void PriorityQueue::enqueue(Node elem) {
  heap.push_back(elem);
  heapifyEnqueue(heap.size() - 1);
}

void PriorityQueue::dequeue() {
  // Node removed_element = heap[0];
  heap[0] = heap[heap.size() - 1];
  heap.pop_back();
  heapifyDequeue(0);
  // return removed_element;
}

void PriorityQueue::dequeue(int percentage) {
  std::cout << "Dequeuing " << percentage << "% from " << name << "..." << std::endl;
  auto start = std::chrono::system_clock::now();
  int numToDq = ceil(heap.size() * percentage / 100);

  for(int i = 0; i < numToDq; i++) 
    dequeue();

  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> duration = end - start;
  std::cout << "Duration: " << duration.count() << "s\n";
}

void PriorityQueue::heapifyEnqueue(int index) {
  if (index == 0) return;
  int parent = (index - 1) >> 2;

  if(heap[index].getKey() > heap[parent].getKey()) {
    std::swap(heap[index], heap[parent]);
    heapifyEnqueue(parent);
  }
}

void PriorityQueue::heapifyDequeue(int index) {
  int left = index << 1 + 1;
  int right = index << 1 + 2;
  int max = 0;

  if(right < heap.size()) {
    if(heap[left].getKey() > heap[right].getKey()) max = left;
    else max = right;
    if(heap[index].getKey() > heap[max].getKey()) max = index;
  }
  else if(left < heap.size()) {
    if(heap[left].getKey() > heap[index].getKey()) max = left;
    else max = index;
  }
  else max = index;

  if(max != index) {
    std::swap(heap[max], heap[index]);
    heapifyDequeue(max);
  }
}

int PriorityQueue::size() {
  return heap.size();
}

void PriorityQueue::print() {
  for (int i = 0; i < heap.size(); i++)
    std::cout << heap[i].getValue() << " ";
  std::cout << std::endl;
}

void PriorityQueue::printToFile(std::string filename) {
  std::ofstream file(filename + ".txt");
  for (int i = 0; i < heap.size(); i++)
    file << heap[i].getValue() << std::endl;
}

#endif