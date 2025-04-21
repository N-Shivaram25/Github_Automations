import sys
sys.path.append("../solutions")  # Adding the Solutions folder to the path

from solution import Node, Solution, build_linked_list

def run_test_cases():
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

    for i in range(5):
        head = build_linked_list(test_inputs[i])
        result = sol.searchKey(sizes[i], head, keys_to_search[i])

        print("\n-----------------------------")
        print(f"Test Case {i + 1}")
        print(f"Linked List: {test_inputs[i]}")
        print(f"Key to Search: {keys_to_search[i]}")
        print(f"Expected: {expected_results[i]}")
        print(f"Your Output: {result}")
        print("Test Case:", "✅ Passed" if result == expected_results[i] else "❌ Failed")

if __name__ == "__main__":
    run_test_cases()
