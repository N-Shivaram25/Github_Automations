#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

extern ListNode* createList(const vector<int>& vals);
extern vector<int> toVector(ListNode* head);
extern void deleteList(ListNode* head);
extern ListNode* removeElements(ListNode* head, int val);

int main() {
    // Test Case 1
    {
        ListNode* head = createList({1, 2, 6, 3, 4, 5, 6});
        ListNode* result = removeElements(head, 6);
        assert(toVector(result) == vector<int>({1, 2, 3, 4, 5}));
        deleteList(result);
    }

    // Test Case 2
    {
        ListNode* head = createList({});
        ListNode* result = removeElements(head, 1);
        assert(toVector(result) == vector<int>({}));
        deleteList(result);
    }

    // Test Case 3
    {
        ListNode* head = createList({7, 7, 7, 7});
        ListNode* result = removeElements(head, 7);
        assert(toVector(result) == vector<int>({}));
        deleteList(result);
    }

    // Test Case 4
    {
        ListNode* head = createList({1, 2, 2, 1});
        ListNode* result = removeElements(head, 2);
        assert(toVector(result) == vector<int>({1, 1}));
        deleteList(result);
    }

    // Test Case 5
    {
        ListNode* head = createList({1, 1, 1, 1});
        ListNode* result = removeElements(head, 1);
        assert(toVector(result) == vector<int>({}));
        deleteList(result);
    }

    // Test Case 6
    {
        ListNode* head = createList({1, 2, 3, 4, 5});
        ListNode* result = removeElements(head, 3);
        assert(toVector(result) == vector<int>({1, 2, 4, 5}));
        deleteList(result);
    }

    // Test Case 7
    {
        ListNode* head = createList({1, 2, 3, 3, 3, 4});
        ListNode* result = removeElements(head, 3);
        assert(toVector(result) == vector<int>({1, 2, 4}));
        deleteList(result);
    }

    // Test Case 8
    {
        ListNode* head = createList({10, 20, 30});
        ListNode* result = removeElements(head, 40);
        assert(toVector(result) == vector<int>({10, 20, 30}));
        deleteList(result);
    }

    // Test Case 9
    {
        ListNode* head = createList({6});
        ListNode* result = removeElements(head, 6);
        assert(toVector(result) == vector<int>({}));
        deleteList(result);
    }

    // Test Case 10
    {
        ListNode* head = createList({6, 1, 6, 2, 6, 3, 6});
        ListNode* result = removeElements(head, 6);
        assert(toVector(result) == vector<int>({1, 2, 3}));
        deleteList(result);
    }

    cout << "All test cases passed!" << endl;
    return 0;
}
