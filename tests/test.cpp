#include <iostream>
#include <vector>
#include <string>
#include <cassert>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// External function declarations (defined in solution.cpp)
extern ListNode* middleNode(ListNode* head);

// Using namespace for Solution class functions
namespace Solution {
    extern ListNode* buildList(const std::vector<int>& values);
    extern void printList(ListNode* head);
    extern void deleteList(ListNode* head);
}

// Helper function to check if two lists are identical
bool areListsEqual(ListNode* list1, ListNode* list2) {
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val != list2->val) return false;
        list1 = list1->next;
        list2 = list2->next;
    }
    return (list1 == nullptr && list2 == nullptr);
}

// Helper function to find the middle node using a different approach (for verification)
ListNode* getMiddleNodeReference(ListNode* head) {
    // If the list is empty
    if (head == nullptr) return nullptr;
    
    // Count the nodes
    int count = 0;
    ListNode* curr = head;
    while (curr != nullptr) {
        count++;
        curr = curr->next;
    }
    
    // Find the middle (count/2)
    int middle = count / 2;
    curr = head;
    for (int i = 0; i < middle; i++) {
        curr = curr->next;
    }
    
    return curr;
}

// Function to run a test case
bool runTest(const std::vector<int>& values, const std::string& testName) {
    // Create list from array
    ListNode* head = Solution::buildList(values);
    
    // Get the expected result
    ListNode* expected = getMiddleNodeReference(head);
    
    // Get the result from the solution
    ListNode* result = middleNode(head);
    
    // Check if they match
    bool passed = (result == expected);
    
    // Print test results with colored output
    std::cout << "Test Case " << testName << ": ";
    if (passed) {
        std::cout << "✅ PASSED" << std::endl;
        if (result != nullptr) {
            std::cout << "  Expected and actual middle nodes match at value: " << result->val << std::endl;
        } else {
            std::cout << "  Expected and actual middle nodes are both null" << std::endl;
        }
    } else {
        std::cout << "❌ FAILED" << std::endl;
        std::cout << "  Expected middle at value: " << (expected ? std::to_string(expected->val) : "nullptr");
        std::cout << ", got: " << (result ? std::to_string(result->val) : "nullptr") << std::endl;
    }
    
    // Clean up
    Solution::deleteList(head);
    
    return passed;
}

int main() {
    std::cout << "Running tests for middleNode function...\n\n";
    
    int testsPassed = 0;
    int totalTests = 5;
    
    // Test Case 1: Odd number of nodes
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    if (runTest(arr1, "1 (Odd length list)")) testsPassed++;
    
    // Test Case 2: Even number of nodes
    std::vector<int> arr2 = {1, 2, 3, 4, 5, 6};
    if (runTest(arr2, "2 (Even length list)")) testsPassed++;
    
    // Test Case 3: Single node
    std::vector<int> arr3 = {42};
    if (runTest(arr3, "3 (Single node)")) testsPassed++;
    
    // Test Case 4: Two nodes
    std::vector<int> arr4 = {10, 20};
    if (runTest(arr4, "4 (Two nodes)")) testsPassed++;
    
    // Test Case 5: 10 nodes
    std::vector<int> arr5 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    if (runTest(arr5, "5 (10 nodes)")) testsPassed++;
    
    // Summary
    std::cout << "\nTest Summary: " << testsPassed << "/" << totalTests << " tests passed" << std::endl;
    
    // Return 0 if all tests pass, 1 otherwise
    return (testsPassed == totalTests) ? 0 : 1;
}