#include "all.h"

using namespace std;

int rob(vector<int>& nums) {
    if (nums.size() < 2) nums.empty() ? 0 : nums[0];
    vector<int> dp = {nums[0], max(nums[0], nums[1])};
    for (int i = 2; i < nums.size(); ++i) {
        dp.push_back(max(dp[i - 1], nums[i] + dp[i - 2]));
    }
    return dp.back();
                        
}

int main() {
    vector<int> nums{3,2,54,6,3,2,6,7,5,87};
    auto result = rob(nums);
    cout << "result: " << result << endl;

    return 0;
}
