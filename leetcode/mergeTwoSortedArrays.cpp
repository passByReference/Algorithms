#include<iostream> 
#include<vector>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size();
    int size2 = nums2.size();

    vector<int> result;
    int i = 0, j = 0;
    while (i < size1 && j < size2) {
        if (nums1[i] < nums2[j]) {
            ++i;
        }
        else if ((nums1[i] == nums2[j] && result.empty()) || (nums1[i] == nums2[j] && !result.empty() && result.back() != nums1[i])) {
            result.push_back(nums1[i]);
            ++i;
            ++j;
        }
        else if (nums1[i] > nums2[j]) ++j;
        else {
            ++i;
            ++j;
        }
    }
    return result;
}

int main() {
    vector<int> nums1 = {2,3,3,5,5,6,7,7,8,12};
    vector<int> nums2 = {5, 5, 6, 8, 8, 9, 10, 10};
    auto result = intersect(nums1, nums2);
    for (auto v : result) {
        cout << v << ", ";
    }
    cout << endl;
    return 0;
}
