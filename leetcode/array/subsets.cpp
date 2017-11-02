#include "../all.h"

using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    result.push_back({});
    int counter = nums.size();
    int prev_size = 0;
    while (counter-- > 0) {
        int res_size = result.size();
        cout << "size = " << res_size << endl;
        for (int i = prev_size; i < res_size; ++i) {
            for (auto num : nums) {
                if (find(result[i].begin(), result[i].end(), num) == result[i].end()) {
                    auto newVec = result[i];
                    newVec.push_back(num);
                    result.push_back(newVec);
                }
            }
        }
        prev_size = res_size;
    }
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    auto res = subsets(nums);
    for (auto vec : res) {
        print(vec);
    }
    return 0;
}
