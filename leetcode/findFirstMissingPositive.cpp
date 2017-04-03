#include <iostream>
#include <vector>

using namespace std;

int findFirstMissingPositive(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        /* case {3, 4, 0, 1}
         * If use if instead of while, when on the second loop, 4 and 1 are swapped, 
         * 1 is not at its due place which is at index 0. Using while will keep the swapping
         * continue until the value's due position is reached.
         *
         * Checking nums[i] != nums[nums[i] - 1] will avoid infinite loop if they happen to be
         * the same
         *
         */
        while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
            cout << "swap " << i << " and " << nums[i] - 1 << endl;
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    return n + 1;
}


int main() {
    vector<int> vec = {3, 4, 0, 1};

    auto result = findFirstMissingPositive(vec);

    cout << result << endl;

    return 0;
}
