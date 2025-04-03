import java.util.*;

public class Test {
    public static int[] sortedSquares(int[] nums) {
        int left = 0, right = nums.length - 1, pos = nums.length - 1;
        int[] result = new int[nums.length];
        
        while (left <= right) {
            if (Math.abs(nums[left]) > Math.abs(nums[right])) {
                result[pos] = nums[left] * nums[left];
                left++;
            } else {
                result[pos] = nums[right] * nums[right];
                right--;
            }
            pos--;
        }
        
        return result;
    }
    
    public static void runTestCases() {
        int[][] testCases = {
            {-10, -3, -2, 0, 1, 5, 7, 12},
            {-10000, -500, -1, 0, 2, 3, 4000},
            {-9, -8, -5, -3, -2, 0, 1, 4, 6, 10},
            {-7, -3, 2, 3, 11},
            {-6, -5, -3, -1, 0, 2, 3, 4, 8}
        };
        
        int[][] expectedOutputs = {
            {0, 1, 4, 9, 25, 49, 100, 144},
            {0, 1, 4, 9, 250000, 16000000, 100000000},
            {0, 1, 4, 9, 16, 25, 36, 64, 81, 100},
            {4, 9, 9, 49, 121},
            {0, 1, 4, 9, 9, 16, 25, 36, 64}
        };
        
        for (int i = 0; i < testCases.length; i++) {
            int[] result = sortedSquares(testCases[i]);
            
            System.out.println("\n------------------------------");
            System.out.println("Test Case " + (i + 1));
            System.out.println("Given Input: " + Arrays.toString(testCases[i]));
            System.out.println("Expected Output: " + Arrays.toString(expectedOutputs[i]));
            System.out.println("Your Output: " + Arrays.toString(result));
            
            if (Arrays.equals(result, expectedOutputs[i])) {
                System.out.println("Test Case: ✅ Passed");
            } else {
                System.out.println("Test Case: ❌ Failed");
            }
        }
        System.out.println("\n------------------------------");
    }
    
    public static void main(String[] args) {
        runTestCases();
    }
}