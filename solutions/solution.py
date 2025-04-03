from typing import List  

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [0] * n  # Create an output a
        left, right = 0, n - 1
        index = n - 1  # Start filling from the end

        while left <= right:
            left_square = nums[left] ** 2
            right_square = nums[right] ** 2

            if left_square > right_square:
                result[index] = left_square
                left += 1
            else:
                result[index] = right_square
                right -= 1

            index -= 1  # Move to t

        return result#4

# Testing the function
if __name__ == "__main__":
    solution = Solution()
    nums = [-4, -1, 0, 3, 10]
    result = solution.sortedSquares(nums)
    print("Sorted Squares:", result)
