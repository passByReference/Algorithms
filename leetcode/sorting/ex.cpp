#include "all.h"

using namespace std;

const int k = 20; //value range in counting sort
vector<int> counting_sort(vector<int>& nums) {
    vector<int> Counts;
    vector<int> Result;
    for (unsigned i = 0; i < nums.size(); ++i) {
        Result.push_back(0);
    }
    for (int i = 0; i < k; ++i) {
        Counts.push_back(0);
    }
    for (auto it = nums.cbegin(); it != nums.cend(); ++it) {
        ++Counts[*it];
    }

    /*
    for (unsigned i = 1; i < Counts.size(); ++i) {
        Counts[i] += Counts[i - 1];
    }
    */
    for (auto it = Counts.begin() + 1; it != Counts.end(); ++it) {
        *it += *(it - 1);
    }
    for (auto it = nums.end() - 1; it != nums.begin(); --it) {
        Result[Counts[*it]] = *it;
        Counts[*it] = Counts[*it] - 1;
    }
    return Result;
}

int main() {
    srand(time(NULL));
    vector<int> nums;
    while (nums.size() < 50) {
        nums.push_back(rand() % k);
    }
    for (auto i : counting_sort(nums)) 
        cout << i << ", ";
    cout << endl;
    return 0;
}
