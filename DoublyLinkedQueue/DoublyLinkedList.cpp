DoublyLinkedList::DoublyLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;
}

DoublyLinkedList::~DoublyLinkedList(){
  //research it
  // you have to iterate through the list
}

void DoublyLinkedList::insertFront(int d){
  ListNode *node = new ListNode(d);
  if(size == 0) // empty list
  {
    back = node;
  } else { // not empty
    node->next = front;
    node->prev = back;
  }

  ++size;
}

int DoublyLinkedList::removeFront()
{
  ListNode *ft = front;
  if(size==1)
  {
    back = NULL;
  }
  else
  {
    front->next->prev = NULL;
  }
  front = front->next;
}

void DoublyLinkedList::insertBack(int d)
{
  ListNode *node = new ListNode(d);

  if(isEmpty()) // size == 0
  {
    front = node;
  }
  else
  {
    back->next = node;
    node->prev = back;
  }
}

ListNode* DoublyLinkedList::remove(int d) // aka int key
{
  // check if the list is not empty before attempting to remove
  ListNode *curr = front;

  while(curr->data != d)
  {
    curr = curr->next;

    if(curr == NULL) // we reached the end, didn't find the value
      return NULL;
  }

  // At this point, we've found the data

  if(curr == front)
  {
    front = curr->next;
  }
  else
  {
    // its not the front
    curr->prev->next = curr->next;
  }

  curr->next = NULL;
  curr->prev = NULL;
  --size;
  return curr;
}
