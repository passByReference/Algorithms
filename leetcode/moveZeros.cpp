//
// Created by Andy X on 8/12/17.
//
#include "all.h";
using namespace std;
void moveZeros(vector<int>& nums) {
    for (int i = 0, j = 0; i < nums.size() - 1; ++i) {
        // j stores the first zero to be swapped.
        if (nums[i] != 0) {
            swap(nums[j++], nums[i]);
        }
    }

}

int main() {
    vector<int> vec = {4,2,4,0,0,3,0,5,1,0};
    moveZeros(vec);
    print(vec);

    return 0;
}




