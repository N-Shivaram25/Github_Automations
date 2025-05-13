from typing import Optional

# Definition for singly-linked listss.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        """
        Remove all elements from a linked list that have value equal to val.
        
        Args:
            head: The head of the linked list
            val: The value to remove
            
        Returns:
            The head of the modified linked list
        """
        # Create a dummy node to handle edge cases (like removing the head)
        dummy = ListNode(0)
        dummy.next = head
        
        # Use a current pointer to traverse the list
        current = dummy
        
        # Traverse the listsss
        while current.next:
            # If the next node has the target values
            if current.next.val == val:
                # Bypass the node to be removed (Python will handle memory management)ss
                current.next = current.next.next
            else:
                # Move to the next nodesssss
                current = current.next
        
        # Return the new heads
        return dummy.next
    
    #vvvv