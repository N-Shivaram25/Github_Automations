#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// Define the ListNode structure here so it's available in the test file
struct ListNode {
    int val;
    struct ListNode* next;
};

// Declare the function that will be imported from solution.c
extern struct ListNode* removeElements(struct ListNode* head, int val);

// Function to create a new ListNode
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to create a linked list from an array of values
struct ListNode* createList(int* vals, int size) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* tail = &dummy;
    
    for (int i = 0; i < size; i++) {
        tail->next = createNode(vals[i]);
        tail = tail->next;
    }
    return dummy.next;
}

// Function to convert a linked list to an array
// Returns the size of the array through the size_ptr parameter
int* toArray(struct ListNode* head, int* size_ptr) {
    // Count the number of nodes
    int count = 0;
    struct ListNode* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    
    // Allocate memory for the array
    int* result = (int*)malloc(count * sizeof(int));
    if (!result) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    // Fill the array
    current = head;
    for (int i = 0; i < count; i++) {
        result[i] = current->val;
        current = current->next;
    }
    
    *size_ptr = count;
    return result;
}

// Function to delete a linked list to prevent memory leaks
void deleteList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to check if two arrays are equal
bool arraysEqual(int* arr1, int size1, int* arr2, int size2) {
    if (size1 != size2) {
        return false;
    }
    
    for (int i = 0; i < size1; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    
    return true;
}

// Function to print an array for debugging
void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    bool all_passed = true;

    // Test Case 1
    printf("Test Case 1: Remove all occurrences of value 6 from list [1,2,6,3,4,5,6]\n");
    int test1[] = {1, 2, 6, 3, 4, 5, 6};
    int expected1[] = {1, 2, 3, 4, 5};
    struct ListNode* head1 = createList(test1, 7);
    struct ListNode* result1 = removeElements(head1, 6);
    
    int result1_size;
    int* result1_arr = toArray(result1, &result1_size);
    
    if (arraysEqual(result1_arr, result1_size, expected1, 5)) {
        printf("✓ Passed\n");
    } else {
        printf("✗ Failed\n");
        printf("Expected: ");
        printArray(expected1, 5);
        printf("Got: ");
        printArray(result1_arr, result1_size);
        all_passed = false;
    }
    free(result1_arr);
    deleteList(result1);

    // Test Case 2
    printf("\nTest Case 2: Remove value 1 from empty list []\n");
    struct ListNode* head2 = NULL;
    struct ListNode* result2 = removeElements(head2, 1);
    
    int result2_size;
    int* result2_arr = toArray(result2, &result2_size);
    
    if (result2_size == 0) {
        printf("✓ Passed\n");
    } else {
        printf("✗ Failed\n");
        printf("Expected empty list, but got: ");
        printArray(result2_arr, result2_size);
        all_passed = false;
    }
    free(result2_arr);
    deleteList(result2);

    // Test Case 3
    printf("\nTest Case 3: Remove all occurrences of value 7 from list [7,7,7,7]\n");
    int test3[] = {7, 7, 7, 7};
    struct ListNode* head3 = createList(test3, 4);
    struct ListNode* result3 = removeElements(head3, 7);
    
    int result3_size;
    int* result3_arr = toArray(result3, &result3_size);
    
    if (result3_size == 0) {
        printf("✓ Passed\n");
    } else {
        printf("✗ Failed\n");
        printf("Expected empty list, but got: ");
        printArray(result3_arr, result3_size);
        all_passed = false;
    }
    free(result3_arr);
    deleteList(result3);

    // Test Case 4
    printf("\nTest Case 4: Remove all occurrences of value 2 from list [1,2,2,1]\n");
    int test4[] = {1, 2, 2, 1};
    int expected4[] = {1, 1};
    struct ListNode* head4 = createList(test4, 4);
    struct ListNode* result4 = removeElements(head4, 2);
    
    int result4_size;
    int* result4_arr = toArray(result4, &result4_size);
    
    if (arraysEqual(result4_arr, result4_size, expected4, 2)) {
        printf("✓ Passed\n");
    } else {
        printf("✗ Failed\n");
        printf("Expected: ");
        printArray(expected4, 2);
        printf("Got: ");
        printArray(result4_arr, result4_size);
        all_passed = false;
    }
    free(result4_arr);
    deleteList(result4);

    // Test Case 5
    printf("\nTest Case 5: Remove all occurrences of value 1 from list [1,1,1,1]\n");
    int test5[] = {1, 1, 1, 1};
    struct ListNode* head5 = createList(test5, 4);
    struct ListNode* result5 = removeElements(head5, 1);
    
    int result5_size;
    int* result5_arr = toArray(result5, &result5_size);
    
    if (result5_size == 0) {
        printf("✓ Passed\n");
    } else {
        printf("✗ Failed\n");
        printf("Expected empty list, but got: ");
        printArray(result5_arr, result5_size);
        all_passed = false;
    }
    free(result5_arr);
    deleteList(result5);

    // Test Case 6
    printf("\nTest Case 6: Remove value 3 from list [1,2,3,4,5]\n");
    int test6[] = {1, 2, 3, 4, 5};
    int expected6[] = {1, 2, 4, 5};
    struct ListNode* head6 = createList(test6, 5);
    struct ListNode* result6 = removeElements(head6, 3);
    
    int result6_size;
    int* result6_arr = toArray(result6, &result6_size);
    
    if (arraysEqual(result6_arr, result6_size, expected6, 4)) {
        printf("✓ Passed\n");
    } else {
        printf("✗ Failed\n");
        printf("Expected: ");
        printArray(expected6, 4);
        printf("Got: ");
        printArray(result6_arr, result6_size);
        all_passed = false;
    }
    free(result6_arr);
    deleteList(result6);

    // Test Case 7
    printf("\nTest Case 7: Remove all occurrences of value 3 from list [1,2,3,3,3,4]\n");
    int test7[] = {1, 2, 3, 3, 3, 4};
    int expected7[] = {1, 2, 4};
    struct ListNode* head7 = createList(test7, 6);
    struct ListNode* result7 = removeElements(head7, 3);
    
    int result7_size;
    int* result7_arr = toArray(result7, &result7_size);
    
    if (arraysEqual(result7_arr, result7_size, expected7, 3)) {
        printf("✓ Passed\n");
    } else {
        printf("✗ Failed\n");
        printf("Expected: ");
        printArray(expected7, 3);
        printf("Got: ");
        printArray(result7_arr, result7_size);
        all_passed = false;
    }
    free(result7_arr);
    deleteList(result7);

    // Test Case 8
    printf("\nTest Case 8: Remove non-existent value 40 from list [10,20,30]\n");
    int test8[] = {10, 20, 30};
    int expected8[] = {10, 20, 30};
    struct ListNode* head8 = createList(test8, 3);
    struct ListNode* result8 = removeElements(head8, 40);
    
    int result8_size;
    int* result8_arr = toArray(result8, &result8_size);
    
    if (arraysEqual(result8_arr, result8_size, expected8, 3)) {
        printf("✓ Passed\n");
    } else {
        printf("✗ Failed\n");
        printf("Expected: ");
        printArray(expected8, 3);
        printf("Got: ");
        printArray(result8_arr, result8_size);
        all_passed = false;
    }
    free(result8_arr);
    deleteList(result8);

    // Test Case 9
    printf("\nTest Case 9: Remove value 6 from single-node list [6]\n");
    int test9[] = {6};
    struct ListNode* head9 = createList(test9, 1);
    struct ListNode* result9 = removeElements(head9, 6);
    
    int result9_size;
    int* result9_arr = toArray(result9, &result9_size);
    
    if (result9_size == 0) {
        printf("✓ Passed\n");
    } else {
        printf("✗ Failed\n");
        printf("Expected empty list, but got: ");
        printArray(result9_arr, result9_size);
        all_passed = false;
    }
    free(result9_arr);
    deleteList(result9);

    // Test Case 10
    printf("\nTest Case 10: Remove all occurrences of value 6 from list [6,1,6,2,6,3,6]\n");
    int test10[] = {6, 1, 6, 2, 6, 3, 6};
    int expected10[] = {1, 2, 3};
    struct ListNode* head10 = createList(test10, 7);
    struct ListNode* result10 = removeElements(head10, 6);
    
    int result10_size;
    int* result10_arr = toArray(result10, &result10_size);
    
    if (arraysEqual(result10_arr, result10_size, expected10, 3)) {
        printf("✓ Passed\n");
    } else {
        printf("✗ Failed\n");
        printf("Expected: ");
        printArray(expected10, 3);
        printf("Got: ");
        printArray(result10_arr, result10_size);
        all_passed = false;
    }
    free(result10_arr);
    deleteList(result10);

    // Print summary
    printf("\nTest Summary:\n");
    if (all_passed) {
        printf("All test cases passed! ✓\n");
        return 0;
    } else {
        printf("Some test cases failed! ✗\n");
        return 1;
    }
}