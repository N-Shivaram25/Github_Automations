#include <stdio.h>

// External function declarations (defined in solution.c)
extern struct ListNode* middleNode(struct ListNode* head);
extern struct ListNode* buildList(int* arr, int size);
extern void printList(struct ListNode* head);

int main() {
    // Test Case 1: Odd number of nodes
    int arr1[] = {1, 2, 3, 4, 5};
    printf("Test Case 1 (Odd count): ");
    printList(middleNode(buildList(arr1, 5))); // Expected: 3 4 5

    // Test Case 2: Even number of nodes
    int arr2[] = {1, 2, 3, 4, 5, 6};
    printf("Test Case 2 (Even count): ");
    printList(middleNode(buildList(arr2, 6))); // Expected: 4 5 6

    // Test Case 3: Single node
    int arr3[] = {42};
    printf("Test Case 3 (Single node): ");
    printList(middleNode(buildList(arr3, 1))); // Expected: 42

    // Test Case 4: Two nodes
    int arr4[] = {10, 20};
    printf("Test Case 4 (Two nodes): ");
    printList(middleNode(buildList(arr4, 2))); // Expected: 20

    // Test Case 5: 100 nodes
    int arr5[100];
    for (int i = 0; i < 100; i++) arr5[i] = i + 1;
    printf("Test Case 5 (100 nodes): ");
    printList(middleNode(buildList(arr5, 100))); // Expected: 51 to 100

    return 0;
}
