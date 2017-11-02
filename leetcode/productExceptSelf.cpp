#include "all.h"

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result;
    if (nums.empty()) return result;
    int leftTotal = 1, rightTotal = 1;
    result.push_back(leftTotal);

    for (int i = 1; i < nums.size(); ++i) {
        leftTotal *= nums[i - 1];
        result.push_back(leftTotal);
    }
    for (int i = nums.size() - 2; i >= 0; --i) {
        rightTotal *= nums[i + 1];
        result[i] *= rightTotal;
    }

    return result;
}

