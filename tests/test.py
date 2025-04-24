import sys
import os
import pytest

# Ensure solutions/ directory is in the path
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'solutions')))

from solution import Node, Solution, build_linked_list

def test_search_key():
    test_inputs = [
        [1, 3, 5, 7, 9],
        [100000],
        [1, 2, 3, 4, 5, 6],
        [10, 20, 30, 40, 50],
        [99999, 100000]
    ]
    sizes = [5, 1, 6, 5, 2]
    keys_to_search = [7, 99999, 10, 25, 100000]
    expected_results = [True, False, False, False, True]

    sol = Solution()
    failed = False

    for i in range(len(test_inputs)):
        head = build_linked_list(test_inputs[i])
        result = sol.searchKey(sizes[i], head, keys_to_search[i])
        
        print(f"\n-----------------------------")
        print(f"Test Case {i + 1}")
        print(f"Linked List: {test_inputs[i]}")
        print(f"Key to Search: {keys_to_search[i]}")
        print(f"Expected: {expected_results[i]}")
        print(f"Your Output: {result}")
        print("Test Case:", "✅ Passed" if result == expected_results[i] else "❌ Failed")
        
        if result != expected_results[i]:
            failed = True
        
        assert result == expected_results[i], f"Test Case {i + 1} failed: expected {expected_results[i]}, got {result}"

    if failed:
        sys.exit(1)

if __name__ == "__main__":
    pytest.main([__file__, "-v"])