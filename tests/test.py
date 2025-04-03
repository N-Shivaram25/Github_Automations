import pytest
from solutions.solution import Solution  # Ensure correct import

# Function to test
def test_sorted_squares():
    test_cases = [
        ([-10, -3, -2, 0, 1, 5, 7, 12], [0, 1, 4, 9, 25, 49, 100, 144]),
        ([-10000, -500, -1, 0, 2, 3, 4000], [0, 1, 4, 9, 250000, 16000000, 100000000]),
        ([-9, -8, -5, -3, -2, 0, 1, 4, 6, 10], [0, 1, 4, 9, 16, 25, 36, 64, 81, 100]),
        ([-7, -3, 2, 3, 11], [4, 9, 9, 49, 121]),
        ([-6, -5, -3, -1, 0, 2, 3, 4, 8], [0, 1, 4, 9, 9, 16, 25, 36, 64])
    ]

    solution = Solution()  # Initialize solution class

    for i, (input_data, expected_output) in enumerate(test_cases, 1):
        output = solution.sortedSquares(input_data)  # Run the function
        print("\n------------------------------")
        print(f"Test Case {i}")
        print(f"Given Input: {input_data}")
        print(f"Expected Output: {expected_output}")
        print(f"Your Output: {output}")

        assert output == expected_output, f"Test Case {i} Failed ❌"
        print(f"Test Case: ✅ Passed")

if __name__ == "__main__":
    test_sorted_squares()
