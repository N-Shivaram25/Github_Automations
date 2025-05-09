#include <stdlib.h>
#include <stdio.h>
//01
// Define the ListNode structure
struct ListNode {
    int val;
    struct ListNode* next;
};

/**
 * Function to remove all elements from a linked list that have a specific value
 * 
 * @param head pointer to the head of the list
 * @param val value to be removed
 * @return pointer to the new head of the modified list
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
      // Create a dummy node that points to the head
      struct ListNode dummy;
      dummy.next = head;
  
      // Use a pointer to traverse the list
      struct ListNode* current = &dummy;
  
      while (current->next != NULL) {
          if (current->next->val == val) {
              // Remove the node by skipping it
              struct ListNode* temp = current->next;
              current->next = current->next->next;
              free(temp); // Free the removed node
          } else {
              // Move to the next node
              current = current->next;
          }
      }
  
      return dummy.next;
}