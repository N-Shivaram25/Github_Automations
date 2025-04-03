#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);/***nothing i am doing */
        int left = 0, right = n - 1;
        int index = n - 1;

        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare) {
                result[index--] = leftSquare;
                left++;
            } else {
                result[index--] = rightSquare;//fsfsdafdddddd
                right--;
            }
        }/*head to safe jpne*/

        return result;
    }/*lets see now*/
};


void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Main function to test the sortedSquares function
int main() {
    Solution solution;
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = solution.sortedSquares(nums);

    cout << "Sorted Squares: ";
    printVector(result);

    return 0;
}
