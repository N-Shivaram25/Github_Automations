#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// Include the struct definition directly in test.cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Declare the functions implemented in solution.cpp
extern ListNode* removeElements(ListNode* head, int val);
extern ListNode* createList(const vector<int>& vals);
extern vector<int> toVector(ListNode* head);
extern void deleteList(ListNode* head);

int main() {
    bool all_passed = true;

    // Test Case 1
    cout << "Test Case 1: Remove all occurrences of value 6 from list [1,2,6,3,4,5,6]" << endl;
    try {
        ListNode* head = createList({1, 2, 6, 3, 4, 5, 6});
        ListNode* result = removeElements(head, 6);
        assert(toVector(result) == vector<int>({1, 2, 3, 4, 5}));
        cout << "✅ Passed" << endl;
        deleteList(result);
    } catch (const std::exception& e) {
        cout << "❌ Failed: Assertion failed" << endl;
        all_passed = false;
    }
    
    // [... rest of the test cases remain the same ...]

    cout << "\nTest Summary:" << endl;
    if (all_passed) {
        cout << "All test cases passed! ✅" << endl;
    } else {
        cout << "Some test cases failed! ❌" << endl;
        exit(1); // Exit with error code to fail the GitHub Action
    }

    return 0;
}