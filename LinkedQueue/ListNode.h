template <typename T>
class ListNode{
public:
  T data;
  ListNode *next;
  ListNode *prev;

  ListNode();
  ListNode(T d);
  ~ListNode();
};

template <typename T>
ListNode<T>::ListNode(){};

template <typename T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;
  prev = NULL;
}

template <typename T>
ListNode<T>::~ListNode(){
  prev = NULL;
  next = NULL;
}
