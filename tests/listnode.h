#ifndef LISTNODE_H
#define LISTNODE_H

#include <vector>
using namespace std;

// Definition of ListNode structure
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Utility function declarations
ListNode* createList(const vector<int>& vals);
vector<int> toVector(ListNode* head);
void deleteList(ListNode* head);

#endif