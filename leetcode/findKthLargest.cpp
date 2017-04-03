#include "all.h"

using namespace std;

void print(vector<int>& nums) {
    for (auto v : nums) {
        cout << v << ", ";
    }
    cout << endl;
}

int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int new_pivot_idx = left;

    for (int i = left; i < right; ++i) {
        if (nums[i] > pivot) { // use greater than instead of less than here
            swap(nums[i], nums[new_pivot_idx++]);
        }
    }
    swap(nums[new_pivot_idx], nums[right]);
    return new_pivot_idx;
}

int findKthLargest (vector<int>& nums, int k) {
    int left = 0, right = nums.size() - 1;
    int result = 0;
    while (left <= right) {
        result = partition(nums, left, right);
        if (result == k - 1) return nums[result];
        else if (result > k - 1) right = result - 1;
        else left = result + 1;
    }
}

int main() {
    vector<int> nums {2, 1};
    auto result = findKthLargest(nums, 1);
    cout << result << endl;
    return 0;
}
