import unittest
from solutions.solution import Solution

class TestSortedSquares(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_cases(self):
        test_cases = [
            ([-10, -3, -2, 0, 1, 5, 7, 12], [0, 1, 4, 9, 25, 49, 100, 144]),
            ([-10000, -500, -1, 0, 2, 3, 4000], [0, 1, 4, 9, 250000, 16000000, 100000000]),
            ([-9, -8, -5, -3, -2, 0, 1, 4, 6, 10], [0, 1, 4, 9, 16, 25, 36, 64, 81, 100]),
            ([-7, -3, 2, 3, 11], [4, 9, 9, 49, 121]),
            ([-6, -5, -3, -1, 0, 2, 3, 4, 8], [0, 1, 4, 9, 9, 16, 25, 36, 64]),
        ]

        for i, (nums, expected) in enumerate(test_cases):
            with self.subTest(f"Test Case {i+1}"):
                self.assertEqual(self.solution.sortedSquares(nums), expected)

if __name__ == "__main__":
    unittest.main()
