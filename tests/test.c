#include <stdio.h>
#include <stdlib.h>


void runTestCases() {
    int testCases[5][10] = {
        {-10, -3, -2, 0, 1, 5, 7, 12}, // Test case 1
        {-10000, -500, -1, 0, 2, 3, 4000}, // Test case 2
        {-9, -8, -5, -3, -2, 0, 1, 4, 6, 10}, // Test case 3
        {-7, -3, 2, 3, 11}, // Test case 4
        {-6, -5, -3, -1, 0, 2, 3, 4, 8} // Test case 5 d
    };

    int sizes[5] = {8, 7, 10, 5, 9};

    int expectedOutputs[5][10] = {
        {0, 1, 4, 9, 25, 49, 100, 144},  // Expected for test case 1
        {0, 1, 4, 9, 250000, 16000000, 100000000},  // Test case 2
        {0, 1, 4, 9, 16, 25, 36, 64, 81, 100},  // Test case 3
        {4, 9, 9, 49, 121},  // Test case 4
        {0, 1, 4, 9, 9, 16, 25, 36, 64}  // Test case 5
    };

    for (int i = 0; i < 5; i++) {
        int result[10] = {0};
        sortedSquares(testCases[i], sizes[i], result);

        printf("\n-------------------------------\n");
        printf("Test Case %d\n", i + 1);

        printf("Given Input: {");
        for (int j = 0; j < sizes[i]; j++) {
            printf("%d", testCases[i][j]);
            if (j < sizes[i] - 1) printf(", ");
        }
        printf("}\n");

        printf("Expected Output: {");
        for (int j = 0; j < sizes[i]; j++) {
            printf("%d", expectedOutputs[i][j]);
            if (j < sizes[i] - 1) printf(", ");
        }
        printf("}\n");

        printf("Your Output: {");
        for (int j = 0; j < sizes[i]; j++) {
            printf("%d", result[j]);
            if (j < sizes[i] - 1) printf(", ");
        }
        printf("}\n");

        // Check if the result matches expected output
        int passed = 1;
        for (int j = 0; j < sizes[i]; j++) {
            if (result[j] != expectedOutputs[i][j]) {
                passed = 0;
                break;
            }
        }

        printf("Test Case: %s\n", passed ? "✅ Passed" : "❌ Failed");
    }
    printf("\n-------------------------------\n");
}

int main() {
    runTestCases();
    return 0;
}
