#include <vector>
#include <cmath>

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int left = 0, right = nums.size() - 1, pos = nums.size() - 1;
    vector<int> result(nums.size());
//sdfsdf
    while (left <= right) {
        if (abs(nums[left]) > abs(nums[right])) {
            result[pos] = nums[left] * nums[left];
            left++;//ss
        } else {
            result[pos] = nums[right] * nums[right];
            right--;
        }
        pos--;
    }

    return result;//vdsvd
}
