#include <stdlib.h>
#include <stdio.h>

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
    // Handle empty list case
    if (head == NULL) {
        return NULL;
    }
    
    // Remove all matching nodes at the beginning of the list
    while (head != NULL && head->val == val) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
    
    // If the list becomes empty after removing nodes from the beginning
    if (head == NULL) {
        return NULL;
    }
    
    // Create a pointer to traverse the list
    struct ListNode* current = head;
    
    // Traverse the list and remove all occurrences
    while (current != NULL && current->next != NULL) {
        if (current->next->val == val) {
            // Save the node to be deleted
            struct ListNode* temp = current->next;
            
            // Bypass the node to be removed
            current->next = current->next->next;
            
            // Free the memory of the removed node
            free(temp);
            
            // Don't move current as we need to check the new next node
            // (removed the break statement that was causing the bug)
        } else {
            // Move to the next node
            current = current->next;
        }
    }
    
    return head;
}