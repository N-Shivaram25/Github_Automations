#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// Define the ListNode structure here so it's available in the test file
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Declare the functions that will be imported from solution.cpp
extern ListNode* removeElements(ListNode* head, int val);

// Define utility functions in the test file since they're needed for testing
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

    // Test Case 2
    cout << "\nTest Case 2: Remove value 1 from empty list []" << endl;
    try {
        ListNode* head = createList({});
        ListNode* result = removeElements(head, 1);
        assert(toVector(result) == vector<int>({}));
        cout << "✅ Passed" << endl;
        deleteList(result);
    } catch (const std::exception& e) {
        cout << "❌ Failed: Assertion failed" << endl;
        all_passed = false;
    }

    // Test Case 3
    cout << "\nTest Case 3: Remove all occurrences of value 7 from list [7,7,7,7]" << endl;
    try {
        ListNode* head = createList({7, 7, 7, 7});
        ListNode* result = removeElements(head, 7);
        assert(toVector(result) == vector<int>({}));
        cout << "✅ Passed" << endl;
        deleteList(result);
    } catch (const std::exception& e) {
        cout << "❌ Failed: Assertion failed" << endl;
        all_passed = false;
    }

    // Test Case 4
    cout << "\nTest Case 4: Remove all occurrences of value 2 from list [1,2,2,1]" << endl;
    try {
        ListNode* head = createList({1, 2, 2, 1});
        ListNode* result = removeElements(head, 2);
        assert(toVector(result) == vector<int>({1, 1}));
        cout << "✅ Passed" << endl;
        deleteList(result);
    } catch (const std::exception& e) {
        cout << "❌ Failed: Assertion failed" << endl;
        all_passed = false;
    }

    // Test Case 5
    cout << "\nTest Case 5: Remove all occurrences of value 1 from list [1,1,1,1]" << endl;
    try {
        ListNode* head = createList({1, 1, 1, 1});
        ListNode* result = removeElements(head, 1);
        assert(toVector(result) == vector<int>({}));
        cout << "✅ Passed" << endl;
        deleteList(result);
    } catch (const std::exception& e) {
        cout << "❌ Failed: Assertion failed" << endl;
        all_passed = false;
    }

    // Test Case 6
    cout << "\nTest Case 6: Remove value 3 from list [1,2,3,4,5]" << endl;
    try {
        ListNode* head = createList({1, 2, 3, 4, 5});
        ListNode* result = removeElements(head, 3);
        assert(toVector(result) == vector<int>({1, 2, 4, 5}));
        cout << "✅ Passed" << endl;
        deleteList(result);
    } catch (const std::exception& e) {
        cout << "❌ Failed: Assertion failed" << endl;
        all_passed = false;
    }

    // Test Case 7
    cout << "\nTest Case 7: Remove all occurrences of value 3 from list [1,2,3,3,3,4]" << endl;
    try {
        ListNode* head = createList({1, 2, 3, 3, 3, 4});
        ListNode* result = removeElements(head, 3);
        assert(toVector(result) == vector<int>({1, 2, 4}));
        cout << "✅ Passed" << endl;
        deleteList(result);
    } catch (const std::exception& e) {
        cout << "❌ Failed: Assertion failed" << endl;
        all_passed = false;
    }

    // Test Case 8
    cout << "\nTest Case 8: Remove non-existent value 40 from list [10,20,30]" << endl;
    try {
        ListNode* head = createList({10, 20, 30});
        ListNode* result = removeElements(head, 40);
        assert(toVector(result) == vector<int>({10, 20, 30}));
        cout << "✅ Passed" << endl;
        deleteList(result);
    } catch (const std::exception& e) {
        cout << "❌ Failed: Assertion failed" << endl;
        all_passed = false;
    }

    // Test Case 9
    cout << "\nTest Case 9: Remove value 6 from single-node list [6]" << endl;
    try {
        ListNode* head = createList({6});
        ListNode* result = removeElements(head, 6);
        assert(toVector(result) == vector<int>({}));
        cout << "✅ Passed" << endl;
        deleteList(result);
    } catch (const std::exception& e) {
        cout << "❌ Failed: Assertion failed" << endl;
        all_passed = false;
    }

    // Test Case 10
    cout << "\nTest Case 10: Remove all occurrences of value 6 from list [6,1,6,2,6,3,6]" << endl;
    try {
        ListNode* head = createList({6, 1, 6, 2, 6, 3, 6});
        ListNode* result = removeElements(head, 6);
        assert(toVector(result) == vector<int>({1, 2, 3}));
        cout << "✅ Passed" << endl;
        deleteList(result);
    } catch (const std::exception& e) {
        cout << "❌ Failed: Assertion failed" << endl;
        all_passed = false;
    }

    cout << "\nTest Summary:" << endl;
    if (all_passed) {
        cout << "All test cases passed! ✅" << endl;
    } else {
        cout << "Some test cases failed! ❌" << endl;
        exit(1); // Exit with error code to fail the GitHub Action
    }

    return 0;
}