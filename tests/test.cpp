#include <iostream>
#include "../solutions/solution.cpp"  // Make sure path is correct

using namespace std;

// Helper function to build linked list from array
Node* buildLinkedList(int arr[], int size) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < size; i++) {
        Node* newNode = new Node{arr[i], nullptr};
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void runTestCases() {
    int testInputs[5][10] = {
        {1, 3, 5, 7, 9},          // Test Case 1
        {100000},                // Test Case 2
        {1, 2, 3, 4, 5, 6},      // Test Case 3
        {10, 20, 30, 40, 50},    // Test Case 4
        {99999, 100000}          // Test Case 5
    };

    int sizes[5] = {5, 1, 6, 5, 2};
    int keysToSearch[5] = {7, 99999, 10, 25, 100000};
    bool expectedResults[5] = {true, false, false, false, true};

    Solution sol;

    for (int i = 0; i < 5; i++) {
        Node* head = buildLinkedList(testInputs[i], sizes[i]);
        bool result = sol.searchKey(sizes[i], head, keysToSearch[i]);

        cout << "\n-----------------------------\n";
        cout << "Test Case " << i + 1 << endl;

        cout << "Linked List: {";
        for (int j = 0; j < sizes[i]; j++) {
            cout << testInputs[i][j];
            if (j < sizes[i] - 1) cout << ", ";
        }
        cout << "}" << endl;

        cout << "Key to Search: " << keysToSearch[i] << endl;
        cout << "Expected: " << (expectedResults[i] ? "true" : "false") << endl;
        cout << "Your Output: " << (result ? "true" : "false") << endl;
        cout << "Test Case: " << ((result == expectedResults[i]) ? "✅ Passed" : "❌ Failed") << endl;
    }
}

int main() {
    runTestCases();
    return 0;
}
