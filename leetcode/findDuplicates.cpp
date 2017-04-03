#include <iostream>
#include <vector>

using namespace std;

int findDuplicates(vector<int>& nums) {
    int slow = 0;
    int fast = 1;
    size_t length = nums.size();

    while (slow < length && fast < length) {
        if (slow != fast && nums[slow] == nums[fast]) return nums[slow];
        cout << "nums[slow] = " << nums[slow] << endl;
        cout << "nums[fast] = " << nums[fast] << endl;
        ++slow;
        fast += 2;
        if (slow >= length) slow = 0;
        if (fast >= length) fast = 1;
        cout << "end while slow = " << slow << endl;
        cout << "end while fast = " << fast << endl;
    }
    return -1;
}

int main() {
    // [9,4,9,5,7,2,8,9,3,9], [4, 3, 1, 4, 2]
    vector<int> nums = {9, 4, 9, 5, 7, 2, 8, 9, 3, 9};
    cout << findDuplicates(nums) << endl;
    return 0;
}
