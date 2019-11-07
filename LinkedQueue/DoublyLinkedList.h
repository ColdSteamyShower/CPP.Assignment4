#include "ListNode.h"
#include "listEmptyException.h"


template <typename T>
class DoublyLinkedList{
private:

  ListNode<T> *front;
  ListNode<T> *back;
  unsigned int size;

public:
  DoublyLinkedList();
  ~DoublyLinkedList();

  void insertFront(T d);
  T removeFront() throw(listEmptyException);
  void insertBack(T d);
  T removeBack() throw(listEmptyException);
  T remove(T value);
  T deletePos(int pos);

  unsigned int getSize();
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  while (front != NULL)
    removeFront();
}

template <typename T>
void DoublyLinkedList<T>::insertFront(T d){
  ListNode<T> *node = new ListNode<T>(d);
  if(size == 0) // empty list
  {
    front = node;
    back = node;
  } else { // not empty
    node->next = front;
    front = node;
  }
  ++size;
}

template <typename T>
T DoublyLinkedList<T>::removeFront() throw(listEmptyException)
{
  if(size == 0){
    throw listEmptyException();
  }
  T data = front->data;

  if(size==1)
  {
    front = NULL;
    back = NULL;
  }
  else
  {
    front->next->prev = NULL;
    front = front->next;
  }
  --size;
  return data;
}

template <typename T>
void DoublyLinkedList<T>::insertBack(T d)
{
  ListNode<T> *node = new ListNode<T>(d);

  if(size == 0)
  {
    front = node;
    back = node;
  }
  else
  {
    back->next = node;
    node->prev = back;
    back = node;
  }
  ++size;
}

template <typename T>
T DoublyLinkedList<T>::removeBack() throw(listEmptyException)
{
  if(size == 0){
    throw listEmptyException();
  }

  T data = back->data;

  if(size==1)
  {
    front = NULL;
    back = NULL;
  }
  else
  {
    back->prev->next = NULL;
    back = back->prev;
  }
  --size;
  return data;
}

template <typename T>
T DoublyLinkedList<T>::remove(T value) // d is the key
{
  if (size == 0) // if empty, we cant remove anything
    return;

  ListNode<T> *curr = front;

  while(curr->data != value)
  {
    curr = curr->next;

    if(curr == NULL) // we reached the end, didn't find the value
      return NULL;
  }

  // At this point, we've found the data

  if(curr == front)
  {
    return removeFront;
  }
  else if (curr == back)
  {
    return removeBack;
  }
  else
  {
    // its not the front or back
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
  }

  curr->next = NULL;
  curr->prev = NULL;
  --size;
  return curr->data;
}

template <typename T>
T DoublyLinkedList<T>::deletePos(int pos){
  unsigned int loc = 0;
  ListNode<T> *curr = front;
  while (loc != pos)
  {
    curr = curr->next;
  }

  // we have found the node to delete
  if(curr == front)
  {
    return removeFront;
  }
  else if (curr == back)
  {
    return removeBack;
  }
  else
  {
    // its not the front or back
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
  }

  curr->next = NULL;
  curr->prev = NULL;
  --size;
  return curr;
}

template <typename T>
unsigned int DoublyLinkedList<T>::getSize(){
  return size;
}
