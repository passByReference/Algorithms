#include "all.h"

using namespace std;
/*
 * My solution
void combine_helper2(vector<int> nums, vector<int> out, 
                    vector<int> used, vector<vector<int>> &result, unsigned k) {
    if (out.size() == k) {
        result.push_back(out);
        return;
    }
    for (unsigned i = 0; i < nums.size(); ++i) {
        if (used[i]) continue;
        out.push_back(nums[i]);
        used[i] = 1;
        combine_helper2(nums, out, used, result, k);
        used[i] = 0;
        out.pop_back();
    }
}

vector<vector<int>> combine_helper1(vector<int> nums, unsigned k) {
    vector<vector<int>> result;
    if (nums.empty()) return result;
    vector<int> out;
    vector<int> used (nums.size(), 0);
    combine_helper2(nums, out, used, result, k);
    return result;

}

vector<vector<int>> combine(vector<int> nums) {
    vector<vector<int>> result;
    if (nums.empty()) return result;
    unsigned k = 1;
    while (k <= nums.size()) {
        auto temp = combine_helper1(nums, k);
        result.reserve(result.size() + temp.size());
        result.insert(result.end(), temp.cbegin(), temp.cend());
        ++k;
    }
    return result;
}
*/

/* better solution
void combine_helper(vector<int> nums, vector<int> out, vector<vector<int>>& result, int start) {
    for (int i = start; i < nums.size(); ++i){
        out.push_back(nums[i]);
        result.push_back(out);
        combine_helper(nums, out, result, i + 1);
        out.pop_back();
    }
}
vector<vector<int>> combine(vector<int> nums) {
    vector<vector<int>> result;
    vector<int> out;
    combine_helper(nums, out, result, 0);
    return result;
}
*/

/* Leetcode combinatiosn
 * Given two integers n and k, return all possible combinations of k
 * numbers out of 1...n
 */

void combine_helper(vector<int> nums, vector<int> out,
        vector<vector<int>> &result, int start, int k) {
    for (int i = start; i < nums.size(); ++i) {
        out.push_back(nums[i]);
        if (out.size() > k) return; 
        else result.push_back(out);
        combine_helper(nums, out, result, i + 1, k);
        out.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> temp, result;
    vector<int> nums;
    for (int i = 1; i <= n; ++i) nums.push_back(i);
    vector<int> out;
    combine_helper(nums, out, temp, 0, k);
    for (auto e : temp) {
        if (e.size() == k) 
            result.push_back(e);
    }
    temp.clear();
    return result;
}

int main() {
    vector<int> nums = {1,2,3};
    auto result = combine(4,2);
    for (auto e : result) {
        for (auto n : e) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
