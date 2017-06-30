// PASS

/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
    Node *cur = head;
    Node *nextNode = new Node();
    Node *pre = NULL;
    while (cur != NULL)
    {
        nextNode = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nextNode;
    }
    return pre;
}
