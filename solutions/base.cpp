#include "listnode.h"

// Function for student to implement
ListNode* removeElements(ListNode* head, int val) {
    // TODO: Write your code here
    
    // Placeholder return (remove this when implementing your solution)s
    return head;
}

// Utility Functions (Do not modify below this line)
ListNode* createList(const vector<int>& vals) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

vector<int> toVector(ListNode* head) {
    vector<int> result;
    while (head) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}