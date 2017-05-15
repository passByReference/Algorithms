#include "all.h"
using std::cout;
using std::endl;
using std::vector;

vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        bool found = false;
        for (int j = i; j < nums.size(); ++j) {
            if (nums[j] > nums[i]) {
                result.push_back(nums[j]);
                found = true;
                break;
            }
        }
        if (!found) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] > nums[i]) {
                    result.push_back(nums[j]);
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            result.push_back(-1);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1,2,3,4,3};
    auto result = nextGreaterElements(nums);
    for (auto n : result) {
        cout << n << ", ";
    }
    cout << endl;
    return 0;
}
