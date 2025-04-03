def sorted_squares(nums):
    left, right = 0, len(nums) - 1
    result = [0] * len(nums)
    pos = len(nums) - 1
    
    while left <= right:
        if abs(nums[left]) > abs(nums[right]):
            result[pos] = nums[left] ** 2
            left += 1
        else:
            result[pos] = nums[right] ** 2
            right -= 1
        pos -= 1
    
    return result

def run_test_cases():
    test_cases = [
        [-10, -3, -2, 0, 1, 5, 7, 12],
        [-10000, -500, -1, 0, 2, 3, 4000],
        [-9, -8, -5, -3, -2, 0, 1, 4, 6, 10],
        [-7, -3, 2, 3, 11],
        [-6, -5, -3, -1, 0, 2, 3, 4, 8]
    ]
    
    expected_outputs = [
        [0, 1, 4, 9, 25, 49, 100, 144],
        [0, 1, 4, 9, 250000, 16000000, 100000000],
        [0, 1, 4, 9, 16, 25, 36, 64, 81, 100],
        [4, 9, 9, 49, 121],
        [0, 1, 4, 9, 9, 16, 25, 36, 64]
    ]
    
    for i, test_case in enumerate(test_cases):
        result = sorted_squares(test_case)
        
        print("\n" + "-" * 30)
        print(f"Test Case {i + 1}")
        print(f"Given Input: {test_case}")
        print(f"Expected Output: {expected_outputs[i]}")
        print(f"Your Output: {result}")
        
        if result == expected_outputs[i]:
            print("Test Case: ✅ Passed")
        else:
            print("Test Case: ❌ Failed")
    
    print("\n" + "-" * 30)

if __name__ == "__main__":
    run_test_cases()