#include "all.h"

using namespace std;

void permute_helper(vector<int> nums, vector<int> out, 
                    vector<int> used, vector<vector<int>> &result) {
    if (out.size() == nums.size()) {
        result.push_back(out);
        return;
    }
    for (unsigned i = 0; i < nums.size(); ++i) {
        if (used[i]) continue;
        out.push_back(nums[i]);
        used[i] = 1;
        permute_helper(nums, out, used, result);
        used[i] = 0;
        out.pop_back();
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.empty()) return result;
    vector<int> out;
    vector<int> used (nums.size(), 0);
    permute_helper(nums, out, used, result);

}

int main() {
    vector<int> nums = {1,2,3,4};
    auto result = permute(nums);
    for (auto e : result) {
        for (auto n : e) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
