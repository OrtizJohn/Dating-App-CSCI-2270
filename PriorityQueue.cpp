#include <iostream>
#include <string>
#include "PriorityQueue.hpp"
using namespace std;

//helperFunctions
int parent(int i) { return (i-1)/2; }
int left(int i) { return (2*i+1); }
int right(int i) { return (2*i + 2); }

bool sameMajor(PersonVertex p1, PersonVertex p2)
{
  if(p1.h1.getMajor() == p2.h1.getMajor())
  {
    return true;
  }
  else
  {
    return false;
  }
}

void swap(PersonVertex *a, PersonVertex *b)
{
  PersonVertex temp = *a;
  *a = *b;
  *b = temp;
}

bool ageRange(PersonVertex p1, PersonVertex p2)
{
  if((p1.h1.getAge()+4) >= p2.h1.getAge() && (p1.h1.getAge()-4) <= p2.h1.getAge())
  {
    return true;
  }
  return false;
}

bool heightRange(PersonVertex p1, PersonVertex p2)
{
  if((p1.h1.getHeight()+6) >= p2.h1.getHeight() && (p1.h1.getHeight()-6) <= p2.h1.getHeight())
  {
    return true;
  }
  return false;
}

float findDiff(Human h1, Human h2) //finds the differenceValues for a pair of humans
{
  int *arr1 = h1.getQuestionAnswers();
  int *arr2 = h2.getQuestionAnswers();
  unsigned int diff = 0;
  for(int i = 0;i<10;i++)
  {
    diff += (*(arr1+i) - *(arr2+i));
  }
  diff /= 10.0;
  return diff;
}

Queue::Queue(int size, PersonVertex p1)
{
  maxSize = size;
  currentSize = 0;
  queue = new PersonVertex[size];
  pMain = p1;
}

Queue::~Queue()
{
  delete []queue;
}

void Queue::repairUpwards(int nodeIndex)
{
  int parentIndex = parent(nodeIndex);
  if(findDiff(queue[parentIndex].h1,pMain.h1) > findDiff(pMain.h1,queue[nodeIndex].h1))
  {
    swap(&queue[parentIndex], &queue[nodeIndex]);
    repairUpwards(parentIndex);
  }
  else if(findDiff(queue[parentIndex].h1,pMain.h1) == findDiff(pMain.h1,queue[nodeIndex].h1))
  {
    if(sameMajor(queue[parentIndex], pMain))
    {
      swap(&queue[parentIndex], &queue[nodeIndex]);
      repairUpwards(parentIndex);
    }
    else
    {
      if(ageRange(queue[parentIndex], pMain))
      {
        swap(&queue[parentIndex], &queue[nodeIndex]);
        repairUpwards(parentIndex);
      }
      else
      {
        if(heightRange(queue[parentIndex], pMain))
        {
          swap(&queue[parentIndex], &queue[nodeIndex]);
          repairUpwards(parentIndex);
        }
      }
    }
  }
  else
  {
    if(parentIndex != nodeIndex)
    {
      return;
    }
  }
}

void Queue::enqueue(PersonVertex p2)
{
  if(currentSize == maxSize)
  {
    cout << "Heap full, cannot enqueue" << endl;
    return;
  }
  else
  {
    //check if person 1 is into person 2's gender and person 2 is into person 1's gender
    if((pMain.h1.getSexualOrientation() == p2.h1.getGender()) && (p2.h1.getSexualOrientation() == pMain.h1.getGender()))
    {
      queue[currentSize] = p2;
      currentSize++;
      repairUpwards(currentSize);
    }
  }
}

void Queue::repairDownwards(int nodeIndex)
{
  int leftChild = left(nodeIndex);
  int rightChild = right(nodeIndex);
  int smallest = nodeIndex;
  if(findDiff(queue[leftChild].h1,pMain.h1) > findDiff(pMain.h1,queue[nodeIndex].h1))
  {
    smallest = leftChild;
  }
  else if(findDiff(queue[leftChild].h1,pMain.h1) == findDiff(pMain.h1,queue[nodeIndex].h1))
  {
    if(sameMajor(queue[leftChild], pMain))
    {
      smallest = leftChild;
    }
    else
    {
      if(ageRange(queue[leftChild], pMain))
      {
        smallest = leftChild;
      }
      else
      {
        if(heightRange(queue[leftChild], pMain))
        {
          smallest = leftChild;
        }
      }
    }
  }
  if(findDiff(queue[rightChild].h1,pMain.h1) > findDiff(pMain.h1,queue[nodeIndex].h1))
  {
    smallest = rightChild;
  }
  else if(findDiff(queue[rightChild].h1,pMain.h1) == findDiff(pMain.h1,queue[nodeIndex].h1))
  {
    if(sameMajor(queue[rightChild], pMain))
    {
      smallest = rightChild;
    }
    else
    {
      if(ageRange(queue[rightChild], pMain))
      {
        smallest = rightChild;
      }
      else
      {
        if(heightRange(queue[rightChild], pMain))
        {
          smallest = rightChild;
        }
      }
    }
  }
  if(smallest == nodeIndex)
  {
    return;
  }
  else
  {
    swap(&queue[smallest], &queue[nodeIndex]);
    repairDownwards(smallest);
  }
}

void Queue::dequeue()
{
  if(isEmpty())
  {
    cout << "Heap empty, cannot dequeue" << endl;
    return;
  }
  else
  {
    queue[0] = queue[currentSize-1];
    currentSize--;
    repairDownwards(-1);
  }
}

PersonVertex Queue::peek()
{
  if(currentSize == 0)
  {
    cout << "Heap empty, nothing to peek" << endl;
    return queue[0];
  }
  else
  {
    return queue[0];
  }
}

bool Queue::isFull()
{
  if(currentSize == maxSize)
  {
    return true;
  }
  return false;
}

bool Queue::isEmpty()
{
  if(currentSize == 0)
  {
    return true;
  }
  return false;
}
