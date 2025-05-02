#include <iostream>
#include <vector>
using namespace std;

// Use the same struct definition as in test.cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Implement the main solution function
ListNode* removeElements(ListNode* head, int val) {
    // Create a dummy node
    ListNode dummy(0);
    dummy.next = head;
    ListNode* current = &dummy;
    
    while (current->next) {
        if (current->next->val == val) {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
    
    return dummy.next;
}