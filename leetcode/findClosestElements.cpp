//
// Created by Andy X on 8/12/17.
//

#include "all.h";

using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int index = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    int i = index - 1, j = index;
    while (k--) {
        (i < 0 || (j < arr.size() && abs(arr[i] - x) > abs(arr[j] - x))) ? ++j : --i;
    }
    return vector<int>(arr.begin() + i + 1, arr.begin() + j);
    
    
}

int main() {
    vector<int> vec = {0,0,1,2,3,3,4,7,7,8};
    auto res = findClosestElements(vec, 3, 5);
    print(res);

    return 0;
}
//Test 1
//Input:
//[0,1,1,1,2,3,6,7,8,9]
//9
//4
//Output:
//[1,1,2,3,6,7,8,9,81]
//Expected:
//[0,1,1,1,2,3,6,7,8]
//
//Test 2
//Input:
//[1,1,2,3,3,3,4,6,8,8]
//6
//1
//Output:
//[0,49,0,1,1,2]
//Expected:
//[1,1,2,3,3,3]
//
//Test 3
//[0,1,2,2,2,3,6,8,8,9]
//5
//9
//Output:
//[2,3,6,8,8]
//Expected:
//[3,6,8,8,9]
// Test 4
// Input:
// [1,2,3,3,6,6,7,7,9,9]
// 8
// 8
// Output:
// []
// Expected:
// [3,3,6,6,7,7,9,9]
// Test 5
// [0,0,1,2,3,3,4,7,7,8]
// 3
// 5
// Output:
// [0,0,1]
// Expected:
// [3,3,4]
