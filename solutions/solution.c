#include <stdlib.h>

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
    // Create a dummy node to handle edge cases (like removing the head)
    struct ListNode dummy;
    dummy.next = head;
    
    // Use a current pointer to traverse the list
    struct ListNode* current = &dummy;
    
    // Traverse the list
    while (current->next != NULL) {
        // If the next node has the target value
        if (current->next->val == val) {
            // Save the node to be deleted
            struct ListNode* temp = current->next;
            
            // Bypass the node to be removed
            current->next = current->next->next;
            
            // Free the memory of the removed nodes
            free(temp);
        } else {
            // Move to the next node
            current = current->next;
        }
    }
    
    // Return the new head (dummy.next)
    return dummy.next;
}