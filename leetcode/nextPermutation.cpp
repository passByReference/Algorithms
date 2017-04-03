#include "all.h"

using namespace std;

void print(const vector<int>& nums) {
    for (auto val : nums) {
        cout << val << ", ";
    }
    cout << endl;
}
void nextPermutation(vector<int>& nums) {
    print(nums);
    int k = -1;

    for (int i = nums.size() - 1; i > 0; --i) {
        if (nums[i - 1] < nums[i]) {
            k = i - 1;
            break;
        }
    }
    if (k == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }
    int minSoFarIndex = k;
    for (int i = nums.size() - 1; i > k; --i) {
        cout << "nums[i]: " << nums[i] << endl;
        if (nums[i] > nums[k]) {
            minSoFarIndex = i;
            break;
        }
    }
    cout << "k = " << k << endl;
    cout << "minsofarindex: " << minSoFarIndex << endl;
    swap(nums[k], nums[minSoFarIndex]);
    print(nums);
    sort(nums.begin() + k + 1, nums.end());
    
    cout << "next permutation" << endl;
}


int main() {
    vector<int> v{1, 2};
    nextPermutation(v);

    print(v);


    return 0;


}
