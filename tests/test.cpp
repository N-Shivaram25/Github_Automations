#include <iostream>
#include <vector>
#include <cassert>
#include "solution.cpp" // Including the function definition

using namespace std;

void runTestCases() {
    vector<vector<int>> testCases = {
        {-10, -3, -2, 0, 1, 5, 7, 12},
        {-10000, -500, -1, 0, 2, 3, 4000},
        {-9, -8, -5, -3, -2, 0, 1, 4, 6, 10},
        {-7, -3, 2, 3, 11},
        {-6, -5, -3, -1, 0, 2, 3, 4, 8}
    };
    
    vector<vector<int>> expectedOutputs = {
        {0, 1, 4, 9, 25, 49, 100, 144},
        {0, 1, 4, 9, 250000, 16000000, 100000000},
        {0, 1, 4, 9, 16, 25, 36, 64, 81, 100},
        {4, 9, 9, 49, 121},
        {0, 1, 4, 9, 9, 16, 25, 36, 64}
    };
    
    for (size_t i = 0; i < testCases.size(); i++) {
        vector<int> result = sortedSquares(testCases[i]);

        cout << "\n------------------------------" << endl;
        cout << "Test Case " << (i + 1) << endl;
        cout << "Given Input: {";
        for (size_t j = 0; j < testCases[i].size(); j++) {
            cout << testCases[i][j] << (j < testCases[i].size() - 1 ? ", " : "");
        }
        cout << "}" << endl;

        cout << "Expected Output: {";
        for (size_t j = 0; j < expectedOutputs[i].size(); j++) {
            cout << expectedOutputs[i][j] << (j < expectedOutputs[i].size() - 1 ? ", " : "");
        }
        cout << "}" << endl;

        cout << "Your Output: {";
        for (size_t j = 0; j < result.size(); j++) {
            cout << result[j] << (j < result.size() - 1 ? ", " : "");
        }
        cout << "}" << endl;

        if (result == expectedOutputs[i]) {
            cout << "Test Case: ✅ Passed" << endl;
        } else {
            cout << "Test Case: ❌ Failed" << endl;
        }

        assert(result == expectedOutputs[i]); // Ensure test passes
    }
    cout << "\n------------------------------" << endl;
}

int main() {
    runTestCases();
    return 0;
}
