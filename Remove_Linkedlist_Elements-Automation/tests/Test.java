import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Definition for singly-linked list.
 */
class ListNode {
    int val;
    ListNode next;
    
    ListNode() {}
    
    ListNode(int val) { 
        this.val = val; 
    }
    
    ListNode(int val, ListNode next) { 
        this.val = val; 
        this.next = next; 
    }
}

public class Test {
    
    /**
     * Creates a linked list from an array of integers.
     * 
     * @param values array of integer values
     * @return head of the created linked list
     */
    private static ListNode createList(int[] values) {
        if (values == null || values.length == 0) {
            return null;
        }
        
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        
        for (int val : values) {
            current.next = new ListNode(val);
            current = current.next;
        }
        
        return dummy.next;
    }
    
    /**
     * Converts a linked list to an array list for easier comparison.
     * 
     * @param head head of the linked list
     * @return list containing the values from the linked list
     */
    private static List<Integer> toList(ListNode head) {
        List<Integer> result = new ArrayList<>();
        ListNode current = head;
        
        while (current != null) {
            result.add(current.val);
            current = current.next;
        }
        
        return result;
    }
    
    /**
     * Asserts that two lists are equal.
     * 
     * @param actual actual result list
     * @param expected expected result list
     * @param message message to display on failure
     * @return true if the test passed, false otherwise
     */
    private static boolean assertEquals(List<Integer> actual, List<Integer> expected, String message) {
        if (actual.equals(expected)) {
            return true;
        } else {
            System.out.println("❌ FAILED: " + message);
            System.out.println("  Expected: " + expected);
            System.out.println("  Actual:   " + actual);
            return false;
        }
    }
    
    /**
     * Entry point for running the tests.
     */
    public static void main(String[] args) {
        boolean allTestsPassed = true;
        
        // Test Case 1: Remove all occurrences of value 6 from list [1,2,6,3,4,5,6]
        System.out.println("Test Case 1: Remove all occurrences of value 6 from list [1,2,6,3,4,5,6]");
        ListNode head1 = createList(new int[] {1, 2, 6, 3, 4, 5, 6});
        Solution solution = new Solution();
        ListNode result1 = solution.removeElements(head1, 6);
        List<Integer> expected1 = Arrays.asList(1, 2, 3, 4, 5);
        boolean test1Passed = assertEquals(toList(result1), expected1, "Test Case 1");
        if (test1Passed) {
            System.out.println("✅ PASSED");
        }
        allTestsPassed &= test1Passed;
        
        // Test Case 2: Remove value 1 from empty list []
        System.out.println("\nTest Case 2: Remove value 1 from empty list []");
        ListNode head2 = createList(new int[] {});
        ListNode result2 = solution.removeElements(head2, 1);
        List<Integer> expected2 = Arrays.asList();
        boolean test2Passed = assertEquals(toList(result2), expected2, "Test Case 2");
        if (test2Passed) {
            System.out.println("✅ PASSED");
        }
        allTestsPassed &= test2Passed;
        
        // Test Case 3: Remove all occurrences of value 7 from list [7,7,7,7]
        System.out.println("\nTest Case 3: Remove all occurrences of value 7 from list [7,7,7,7]");
        ListNode head3 = createList(new int[] {7, 7, 7, 7});
        ListNode result3 = solution.removeElements(head3, 7);
        List<Integer> expected3 = Arrays.asList();
        boolean test3Passed = assertEquals(toList(result3), expected3, "Test Case 3");
        if (test3Passed) {
            System.out.println("✅ PASSED");
        }
        allTestsPassed &= test3Passed;
        
        // Test Case 4: Remove all occurrences of value 2 from list [1,2,2,1]
        System.out.println("\nTest Case 4: Remove all occurrences of value 2 from list [1,2,2,1]");
        ListNode head4 = createList(new int[] {1, 2, 2, 1});
        ListNode result4 = solution.removeElements(head4, 2);
        List<Integer> expected4 = Arrays.asList(1, 1);
        boolean test4Passed = assertEquals(toList(result4), expected4, "Test Case 4");
        if (test4Passed) {
            System.out.println("✅ PASSED");
        }
        allTestsPassed &= test4Passed;
        
        // Test Case 5: Remove all occurrences of value 1 from list [1,1,1,1]
        System.out.println("\nTest Case 5: Remove all occurrences of value 1 from list [1,1,1,1]");
        ListNode head5 = createList(new int[] {1, 1, 1, 1});
        ListNode result5 = solution.removeElements(head5, 1);
        List<Integer> expected5 = Arrays.asList();
        boolean test5Passed = assertEquals(toList(result5), expected5, "Test Case 5");
        if (test5Passed) {
            System.out.println("✅ PASSED");
        }
        allTestsPassed &= test5Passed;
        
        // Test Case 6: Remove value 3 from list [1,2,3,4,5]
        System.out.println("\nTest Case 6: Remove value 3 from list [1,2,3,4,5]");
        ListNode head6 = createList(new int[] {1, 2, 3, 4, 5});
        ListNode result6 = solution.removeElements(head6, 3);
        List<Integer> expected6 = Arrays.asList(1, 2, 4, 5);
        boolean test6Passed = assertEquals(toList(result6), expected6, "Test Case 6");
        if (test6Passed) {
            System.out.println("✅ PASSED");
        }
        allTestsPassed &= test6Passed;
        
        // Test Case 7: Remove all occurrences of value 3 from list [1,2,3,3,3,4]
        System.out.println("\nTest Case 7: Remove all occurrences of value 3 from list [1,2,3,3,3,4]");
        ListNode head7 = createList(new int[] {1, 2, 3, 3, 3, 4});
        ListNode result7 = solution.removeElements(head7, 3);
        List<Integer> expected7 = Arrays.asList(1, 2, 4);
        boolean test7Passed = assertEquals(toList(result7), expected7, "Test Case 7");
        if (test7Passed) {
            System.out.println("✅ PASSED");
        }
        allTestsPassed &= test7Passed;
        
        // Test Case 8: Remove non-existent value 40 from list [10,20,30]
        System.out.println("\nTest Case 8: Remove non-existent value 40 from list [10,20,30]");
        ListNode head8 = createList(new int[] {10, 20, 30});
        ListNode result8 = solution.removeElements(head8, 40);
        List<Integer> expected8 = Arrays.asList(10, 20, 30);
        boolean test8Passed = assertEquals(toList(result8), expected8, "Test Case 8");
        if (test8Passed) {
            System.out.println("✅ PASSED");
        }
        allTestsPassed &= test8Passed;
        
        // Test Case 9: Remove value 6 from single-node list [6]
        System.out.println("\nTest Case 9: Remove value 6 from single-node list [6]");
        ListNode head9 = createList(new int[] {6});
        ListNode result9 = solution.removeElements(head9, 6);
        List<Integer> expected9 = Arrays.asList();
        boolean test9Passed = assertEquals(toList(result9), expected9, "Test Case 9");
        if (test9Passed) {
            System.out.println("✅ PASSED");
        }
        allTestsPassed &= test9Passed;
        
        // Test Case 10: Remove all occurrences of value 6 from list [6,1,6,2,6,3,6]
        System.out.println("\nTest Case 10: Remove all occurrences of value 6 from list [6,1,6,2,6,3,6]");
        ListNode head10 = createList(new int[] {6, 1, 6, 2, 6, 3, 6});
        ListNode result10 = solution.removeElements(head10, 6);
        List<Integer> expected10 = Arrays.asList(1, 2, 3);
        boolean test10Passed = assertEquals(toList(result10), expected10, "Test Case 10");
        if (test10Passed) {
            System.out.println("✅ PASSED");
        }
        allTestsPassed &= test10Passed;
        
        // Print summary
        System.out.println("\nTest Summary:");
        if (allTestsPassed) {
            System.out.println("All test cases passed! ✅");
            System.exit(0);
        } else {
            System.out.println("Some test cases failed! ❌");
            System.exit(1);
        }
    }
}