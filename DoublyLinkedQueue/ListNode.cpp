ListNode::ListNode(){};

ListNode::ListNode(int d){
  data = d;
  next = NULL;
  prev = NULL;
}

ListNode:~ListNode(){
  prev = NULL;
  next = NULL;
}
