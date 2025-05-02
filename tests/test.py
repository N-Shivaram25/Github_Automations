import unittest
from typing import List, Optional
from solution import Solution, ListNode

class TestRemoveElements(unittest.TestCase):
    
    def create_linked_list(self, values: List[int]) -> Optional[ListNode]:
        """
        Helper function to create a linked list from a list of values.
        
        Args:
            values: A list of integer values
            
        Returns:
            The head of the created linked list, or None for empty list
        """
        if not values:
            return None
            
        head = ListNode(values[0])
        current = head
        
        for val in values[1:]:
            current.next = ListNode(val)
            current = current.next
            
        return head
    
    def linked_list_to_list(self, head: Optional[ListNode]) -> List[int]:
        """
        Convert a linked list to a regular list for easier comparison.
        
        Args:
            head: The head of the linked list
            
        Returns:
            A list containing all values from the linked list in order
        """
        result = []
        current = head
        
        while current:
            result.append(current.val)
            current = current.next
            
        return result
    
    def test_remove_multiple_occurrences(self):
        """Test removing multiple occurrences of a value from the middle of the list."""
        head = self.create_linked_list([1, 2, 6, 3, 4, 5, 6])
        solution = Solution()
        result = solution.removeElements(head, 6)
        self.assertEqual(self.linked_list_to_list(result), [1, 2, 3, 4, 5])
    
    def test_empty_list(self):
        """Test removing a value from an empty list."""
        head = self.create_linked_list([])
        solution = Solution()
        result = solution.removeElements(head, 1)
        self.assertEqual(self.linked_list_to_list(result), [])
    
    def test_remove_all_elements(self):
        """Test removing all elements when they all have the target value."""
        head = self.create_linked_list([7, 7, 7, 7])
        solution = Solution()
        result = solution.removeElements(head, 7)
        self.assertEqual(self.linked_list_to_list(result), [])
    
    def test_remove_consecutive_elements(self):
        """Test removing consecutive elements."""
        head = self.create_linked_list([1, 2, 2, 1])
        solution = Solution()
        result = solution.removeElements(head, 2)
        self.assertEqual(self.linked_list_to_list(result), [1, 1])
    
    def test_remove_all_same_value(self):
        """Test removing all elements when the list has only one value repeated."""
        head = self.create_linked_list([1, 1, 1, 1])
        solution = Solution()
        result = solution.removeElements(head, 1)
        self.assertEqual(self.linked_list_to_list(result), [])
    
    def test_remove_middle_element(self):
        """Test removing the middle element."""
        head = self.create_linked_list([1, 2, 3, 4, 5])
        solution = Solution()
        result = solution.removeElements(head, 3)
        self.assertEqual(self.linked_list_to_list(result), [1, 2, 4, 5])
    
    def test_remove_multiple_consecutive(self):
        """Test removing multiple consecutive occurrences."""
        head = self.create_linked_list([1, 2, 3, 3, 3, 4])
        solution = Solution()
        result = solution.removeElements(head, 3)
        self.assertEqual(self.linked_list_to_list(result), [1, 2, 4])
    
    def test_value_not_in_list(self):
        """Test removing a value that doesn't exist in the list."""
        head = self.create_linked_list([10, 20, 30])
        solution = Solution()
        result = solution.removeElements(head, 40)
        self.assertEqual(self.linked_list_to_list(result), [10, 20, 30])
    
    def test_remove_single_element(self):
        """Test removing a value from a single-element list."""
        head = self.create_linked_list([6])
        solution = Solution()
        result = solution.removeElements(head, 6)
        self.assertEqual(self.linked_list_to_list(result), [])
    
    def test_remove_alternating_elements(self):
        """Test removing elements that appear in an alternating pattern."""
        head = self.create_linked_list([6, 1, 6, 2, 6, 3, 6])
        solution = Solution()
        result = solution.removeElements(head, 6)
        self.assertEqual(self.linked_list_to_list(result), [1, 2, 3])

if __name__ == "__main__":
    unittest.main()