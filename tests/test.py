from typing import List, Optional
from solution import Solution, ListNode

def create_linked_list(values: List[int]) -> Optional[ListNode]:
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

def linked_list_to_list(head: Optional[ListNode]) -> List[int]:
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

def lists_equal(list1: List[int], list2: List[int]) -> bool:
    """
    Check if two lists are equal.
    
    Args:
        list1: First list
        list2: Second list
        
    Returns:
        True if lists are equal, False otherwise
    """
    return list1 == list2

def print_list(lst: List[int]) -> str:
    """
    Convert a list to a string representation.
    
    Args:
        lst: The list to convert
        
    Returns:
        String representation of the list
    """
    return str(lst)

def main():
    all_passed = True
    solution = Solution()
    
    # Test Case 1
    print("Test Case 1: Remove all occurrences of value 6 from list [1,2,6,3,4,5,6]")
    test1 = create_linked_list([1, 2, 6, 3, 4, 5, 6])
    expected1 = [1, 2, 3, 4, 5]
    result1 = solution.removeElements(test1, 6)
    result1_list = linked_list_to_list(result1)
    
    if lists_equal(result1_list, expected1):
        print("✅ Passed")
    else:
        print("❌ Failed")
        print(f"Expected: {print_list(expected1)}")
        print(f"Got: {print_list(result1_list)}")
        all_passed = False
    
    # Test Case 2
    print("\nTest Case 2: Remove value 1 from empty list []")
    test2 = create_linked_list([])
    expected2 = []
    result2 = solution.removeElements(test2, 1)
    result2_list = linked_list_to_list(result2)
    
    if lists_equal(result2_list, expected2):
        print("✅ Passed")
    else:
        print("❌ Failed")
        print(f"Expected: {print_list(expected2)}")
        print(f"Got: {print_list(result2_list)}")
        all_passed = False
    
    # Test Case 3
    print("\nTest Case 3: Remove all occurrences of value 7 from list [7,7,7,7]")
    test3 = create_linked_list([7, 7, 7, 7])
    expected3 = []
    result3 = solution.removeElements(test3, 7)
    result3_list = linked_list_to_list(result3)
    
    if lists_equal(result3_list, expected3):
        print("✅ Passed")
    else:
        print("❌ Failed")
        print(f"Expected: {print_list(expected3)}")
        print(f"Got: {print_list(result3_list)}")
        all_passed = False
    
    # Test Case 4
    print("\nTest Case 4: Remove all occurrences of value 2 from list [1,2,2,1]")
    test4 = create_linked_list([1, 2, 2, 1])
    expected4 = [1, 1]
    result4 = solution.removeElements(test4, 2)
    result4_list = linked_list_to_list(result4)
    
    if lists_equal(result4_list, expected4):
        print("✅ Passed")
    else:
        print("❌ Failed")
        print(f"Expected: {print_list(expected4)}")
        print(f"Got: {print_list(result4_list)}")
        all_passed = False
    
    # Test Case 5
    print("\nTest Case 5: Remove all occurrences of value 1 from list [1,1,1,1]")
    test5 = create_linked_list([1, 1, 1, 1])
    expected5 = []
    result5 = solution.removeElements(test5, 1)
    result5_list = linked_list_to_list(result5)
    
    if lists_equal(result5_list, expected5):
        print("✅ Passed")
    else:
        print("❌ Failed")
        print(f"Expected: {print_list(expected5)}")
        print(f"Got: {print_list(result5_list)}")
        all_passed = False
    
    # Test Case 6
    print("\nTest Case 6: Remove value 3 from list [1,2,3,4,5]")
    test6 = create_linked_list([1, 2, 3, 4, 5])
    expected6 = [1, 2, 4, 5]
    result6 = solution.removeElements(test6, 3)
    result6_list = linked_list_to_list(result6)
    
    if lists_equal(result6_list, expected6):
        print("✅ Passed")
    else:
        print("❌ Failed")
        print(f"Expected: {print_list(expected6)}")
        print(f"Got: {print_list(result6_list)}")
        all_passed = False
    
    # Test Case 7
    print("\nTest Case 7: Remove all occurrences of value 3 from list [1,2,3,3,3,4]")
    test7 = create_linked_list([1, 2, 3, 3, 3, 4])
    expected7 = [1, 2, 4]
    result7 = solution.removeElements(test7, 3)
    result7_list = linked_list_to_list(result7)
    
    if lists_equal(result7_list, expected7):
        print("✅ Passed")
    else:
        print("❌ Failed")
        print(f"Expected: {print_list(expected7)}")
        print(f"Got: {print_list(result7_list)}")
        all_passed = False
    
    # Test Case 8
    print("\nTest Case 8: Remove non-existent value 40 from list [10,20,30]")
    test8 = create_linked_list([10, 20, 30])
    expected8 = [10, 20, 30]
    result8 = solution.removeElements(test8, 40)
    result8_list = linked_list_to_list(result8)
    
    if lists_equal(result8_list, expected8):
        print("✅ Passed")
    else:
        print("❌ Failed")
        print(f"Expected: {print_list(expected8)}")
        print(f"Got: {print_list(result8_list)}")
        all_passed = False
    
    # Test Case 9
    print("\nTest Case 9: Remove value 6 from single-node list [6]")
    test9 = create_linked_list([6])
    expected9 = []
    result9 = solution.removeElements(test9, 6)
    result9_list = linked_list_to_list(result9)
    
    if lists_equal(result9_list, expected9):
        print("✅ Passed")
    else:
        print("❌ Failed")
        print(f"Expected: {print_list(expected9)}")
        print(f"Got: {print_list(result9_list)}")
        all_passed = False
    
    # Test Case 10
    print("\nTest Case 10: Remove all occurrences of value 6 from list [6,1,6,2,6,3,6]")
    test10 = create_linked_list([6, 1, 6, 2, 6, 3, 6])
    expected10 = [1, 2, 3]
    result10 = solution.removeElements(test10, 6)
    result10_list = linked_list_to_list(result10)
    
    if lists_equal(result10_list, expected10):
        print("✅ Passed")
    else:
        print("❌ Failed")
        print(f"Expected: {print_list(expected10)}")
        print(f"Got: {print_list(result10_list)}")
        all_passed = False
    
    # Print summary
    print("\nTest Summary:")
    if all_passed:
        print("All test cases passed! ✅")
        return 0
    else:
        print("Some test cases failed! ❌")
        return 1

if __name__ == "__main__":
    main()