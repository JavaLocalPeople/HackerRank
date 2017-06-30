// PASS

/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int CompareLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
  
    // Pointer for the 2 Linked List
    Node *aPtr = headA;
    Node *bPtr = headB;
    
    // go until aPtr is empty
    while (aPtr != NULL)
    {
        
        if (bPtr == NULL) {
            return 0;
        }
        
        if (bPtr->data != aPtr->data)
        {
            return 0;
        }
        
        aPtr = aPtr->next;
        bPtr = bPtr->next;
    }
    
    
    // Include 2 conditions: 1). test headA & headB is NULL. If aPtr is empty, then it already
    //pass the while loop above. so if bPtr is not empty, then the linked list is different
    // 2). test whether the size is different between headA & headB
    if (bPtr != NULL)
    {
        return 0;
    }
    return 1;
    
    
}
