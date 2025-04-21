#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

// Declare your searchKey and buildLinkedList function separately

void runTestCases() {
    int testInputs[5][10] = {
        {1, 3, 5, 7, 9},            // Test Case 1
        {100000},                  // Test Case 2: Single node, max value
        {1, 2, 3, 4, 5, 6},        // Test Case 3: Key not in list
        {10, 20, 30, 40, 50},      // Test Case 4: Key not found
        {99999, 100000}            // Test Case 5: Key at end
    };

    int sizes[5] = {5, 1, 6, 5, 2};
    int keysToSearch[5] = {7, 99999, 10, 25, 100000};
    bool expectedResults[5] = {true, false, false, false, true};

    for (int i = 0; i < 5; i++) {
        // buildLinkedList is assumed to create a linked list from testInputs[i]
        // and return head node (define it in your main code)
        struct Node* head = buildLinkedList(testInputs[i], sizes[i]);
        bool result = searchKey(sizes[i], head, keysToSearch[i]);

        printf("\n-----------------------------\n");
        printf("Test Case %d\n", i + 1);

        printf("Linked List: {");
        for (int j = 0; j < sizes[i]; j++) {
            printf("%d", testInputs[i][j]);
            if (j < sizes[i] - 1) printf(", ");
        }
        printf("}\n");

        printf("Key to Search: %d\n", keysToSearch[i]);
        printf("Expected: %s\n", expectedResults[i] ? "true" : "false");
        printf("Your Output: %s\n", result ? "true" : "false");
        printf("Test Case: %s\n", (result == expectedResults[i]) ? "✅ Passed" : "❌ Failed");
    }

    printf("\n-----------------------------\n");
}

int main() {
    runTestCases();
    return 0;
}
