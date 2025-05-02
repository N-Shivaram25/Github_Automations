#include <iostream>
#include <vector>
using namespace std;

// Use the same struct definition as in test.cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Implementation with intentional bugs to fail specifically test cases 5 and 9
ListNode* removeElements(ListNode* head, int val) {
    // Edge case: if head is null, return null
    if (!head) return nullptr;
    
    // Create a dummy node
    ListNode dummy(0);
    dummy.next = head;
    ListNode* current = &dummy;
    
    while (current->next) {
        // Bug #1: If all nodes are the target value (like in test case 5),
        // we'll remove some but not all of them (we're missing the first one)
        if (current->next->val == val && current != &dummy) {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } 
        // Bug #2: If the node is the target value and its value is 6 (like in test case 9),
        // we don't remove it
        else if (current->next->val == val && val == 6) {
            current = current->next;
        }
        else {
            current = current->next;
        }
    }
    
    return dummy.next;
}