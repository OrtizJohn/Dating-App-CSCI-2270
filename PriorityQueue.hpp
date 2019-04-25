#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP
#include <vector>
#include <string>
#include "connectivityGraph.hpp"
using namespace std;

class Queue
{
public:
  Queue(int size, PersonVertex pMain);
  ~Queue();
  void enqueue(PersonVertex pMain); //figure out what to check
  void dequeue();
  PersonVertex peek();
  bool isFull();
  bool isEmpty();
  void printMaxSize();
  void printCurrentSize();

private:
  void repairUpwards(int nodeIndex);
  void repairDownwards(int nodeIndex);
  PersonVertex *queue;
  int currentSize;
  int maxSize;
  PersonVertex pMain;
};
#endif
