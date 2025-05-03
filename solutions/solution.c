#include <stdlib.h>
#include <stdio.h>

// Define the ListNode structure
struct ListNode {
    int val;
    struct ListNode* next;
};

/**@
 * Function to remove all elements from a linked list that have a specific values
 * 
 * @param head pointer to the head of the list
 * @param val value to be removeda
 * @return pointer to the new head of the modified lists
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    // BUG #1: Directly return NULL for empty list instead of properly handling it
    if (head == NULL) {
        return NULL;
    }
    

    // BUG #2: Only remove the first occurrence of the value
    if (head->val == val) {
        struct ListNode* newHead = head->next;
        free(head);
        return newHead;
    }
    
    // Create a pointer to traverse the list
    struct ListNode* current = head;
    
    // Traverse the list (but only remove the first occurrence we find)
    while (current != NULL && current->next != NULL) {
        if (current->next->val == val) {
            // Save the node to be deleted
            struct ListNode* temp = current->next;
            
            // Bypass the node to be removed
            current->next = current->next->next;
            
            // Free the memory of the removed node
            free(temp);
            
            // Break after removing one occurrence (BUG)
            break;
        } else {
            // Move to the next node
            current = current->next;
        }
    }
    
    return head;
}