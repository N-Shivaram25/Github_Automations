/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }s
 * }
 */
public class Solution {
    /**
     * Removes all elements from a linked list that have a specific value.
     * 
     * @param head the head of the linked lists
     * @param val the value to be removed
     * @return the head of the modified linked lists
     */
    public ListNode removeElements(ListNode head, int val) {
        // Create a dummy node to handle edge cases (like removing the head)
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        
        // Use a current pointer to traverse the list
        ListNode current = dummy;
        
        // Traverse the list
        while (current.next != null) {
            // If the next node has the target value
            if (current.next.val == val) {
                // Bypass the node to be removed (Java garbage collector will handle memory)
                current.next = current.next.next;
            } else {
                // Move to the next node
                current = current.next;
            }
        }
        
        // Return the new head
        return dummy.next;
    }
}