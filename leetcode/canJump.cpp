#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
bool canJump(vector<int>& nums) {
    if (nums.empty()) return false;
    size_t i = 0;
    while (i < nums.size() - 1) {
        if (i != nums.size() - 1 && nums[i] == 0) return false;
        cout << i << endl;
        vector<int> moves;
        int j = nums[i];
        while (j >= 0 && (i + j) < nums.size()) {
            cout << "in while " << nums[i + j] << endl;
            moves.push_back(nums[i + j]);
            --j;
        }
        if (!moves.empty()) {
            int maxStep = *max_element(moves.begin(), moves.end());
            cout << "maxStep = " << maxStep << endl;
            if (maxStep != 0) i += maxStep;
            else i += nums[i];
        }
        else i += nums[i];
    }
    return i >= (nums.size() - 1);
} 
*/
bool canJump(vector<int>& nums) {
    int reach = 0;
    size_t length = nums.size();
    // just iterate and update the maximal index that I can reach
    for (int i = 0; i < length && i <= reach; ++i) { // / the condition i <= reach means traverse all of covered position and not exceeding coverd positions 
        reach = max(i + nums[i], reach); // because each time i is incremented by 1, the algorithm will examine each step within reach
                                         // so if i + nums[i] == 0, it doesn't matter. The algo will examine (i, i + nums[i]] later
        if (reach >= (length - 1)) return true;
    }

    return false;
}

int main() {
    // [2, 0], [1, 0, 2], [2, 0, 0, [2, 5, 0, 0]
    vector<int> nums = {2, 5, 0, 0};
    cout << "result = " << canJump(nums) << endl;
    return 0;
}
