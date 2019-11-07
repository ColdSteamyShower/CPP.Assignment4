#include <iostream>
#include "DoublyLinkedList.h"

template <typename T>
class LinkedQueue{
private:
  DoublyLinkedList<T> *queueList;
public:

  LinkedQueue();
  ~LinkedQueue();

  void enqueue(T value);
  T dequeue();
  T front();

  int size();
  bool empty();
};

template <typename T>
LinkedQueue<T>::LinkedQueue(){
  queueList = new DoublyLinkedList<T>();
}

template <typename T>
LinkedQueue<T>::~LinkedQueue(){
  delete queueList;
}

template <typename T>
void LinkedQueue<T>::enqueue(T value){
  queueList->insertBack(value);
}

template <typename T>
T LinkedQueue<T>::dequeue(){
  return queueList->removeFront();
}

template <typename T>
T LinkedQueue<T>::front(){
  queueList->getFront();
}

template <typename T>
int LinkedQueue<T>::size(){
  return queueList->getSize();
}

template <typename T>
bool LinkedQueue<T>::empty(){
  if (size() == 0)
    return true;
  else
    return false;
}
