class DoublyLinkedList{
private:
  ListNode *front;
  ListNode *back;
  unsigned int size;

public:
  DoublyLinkedList();
  ~DoublyLinkedList();

  void insertFront(int d);
  int removeFront();
  void insertBack(int d);
  int removeBack();
  int deletePos(int pos);
  int find (int d);

  bool isEmpty();
  void printList();
  unsigned int getSize();
};
