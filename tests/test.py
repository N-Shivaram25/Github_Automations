import pytest
from solutions.solution import Solution, build_linked_list

@pytest.mark.parametrize(
    "test_input, size, key, expected",
    [
        ([1, 3, 5, 7, 9], 5, 7, True),
        ([100000], 1, 99999, False),
        ([1, 2, 3, 4, 5, 6], 6, 10, False),
        ([10, 20, 30, 40, 50], 5, 25, False),
        ([99999, 100000], 2, 100000, True),
    ],
    ids=[
        "Test Case 1: Key 7 in [1, 3, 5, 7, 9]",
        "Test Case 2: Key 99999 in [100000]",
        "Test Case 3: Key 10 in [1, 2, 3, 4, 5, 6]",
        "Test Case 4: Key 25 in [10, 20, 30, 40, 50]",
        "Test Case 5: Key 100000 in [99999, 100000]",
    ]
)
def test_search_key(test_input, size, key, expected):
    sol = Solution()
    head = build_linked_list(test_input)
    result = sol.searchKey(size, head, key)
    print(f"\n{'='*50}")
    print(f"Test Case: {pytest.current_test_id}")
    print(f"Linked List: {test_input}")
    print(f"Key to Search: {key}")
    print(f"Expected: {expected}")
    print(f"Your Output: {result}")
    if result == expected:
        print(f"Test Result: ✅ Passed")
    else:
        print(f"\n*** ❌ TEST FAILED ❌ ***")
        print(f"Test Result: ❌ Failed - Expected {expected}, but got {result}")
    print(f"{'='*50}")
    assert result == expected, f"Test failed: expected {expected}, got {result}"