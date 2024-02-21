#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  smaller = new Node(0, nullptr); 
  larger = new Node(0, nullptr); 
  llpivotHelper(head, smaller, larger, pivot); 
  head = nullptr;
  smaller = smaller->next; 
  larger = larger->next;  
}

void llpivotHelper(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  if(head == nullptr) {
    smaller->next = nullptr; 
    larger->next = nullptr; 
    return; 
  }
  
  // checks if val is less than or equal to pivot
  if(head->val <= pivot) {
    smaller->next = head; 
    llpivotHelper(head->next, smaller->next, larger, pivot); 
  }

  // val is larger than pivot
  else {
    larger->next = head; 
    llpivotHelper(head->next, smaller, larger->next, pivot); 
  }
}
