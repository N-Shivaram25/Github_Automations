#include <stdlib.h>
#include "solution.h" // Optional if you have a header file

// Define the ListNode structure again if not using a header
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    // Create a dummy node to simplify deletion (even at the head)
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* current = dummy;

    while (current->next != NULL) {
        if (current->next->val == val) {
            struct ListNode* toDelete = current->next;
            current->next = current->next->next;
            free(toDelete);
        } else {
            current = current->next;
        }
    }

    struct ListNode* newHead = dummy->next;
    free(dummy);
    return newHead;
}
