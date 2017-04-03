#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

void mergesort(vector<int>& arr);

int main() {
  vector<int> arr{6,5,3,1,8,7,2,4};
  mergesort(arr); 
  cout << "Result: " << endl;
  for(vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
      cout << *it << ", ";
    cout << endl;
}
void print_vec(vector<int>& vec) {
    for (auto v : vec) cout << v << ", ";
    cout << endl;
}
void mergesort(vector<int>& arr) {
    cout << "merge sort" << endl;
    if (arr.size() < 2) return;
    auto mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
    print_vec(left);
    print_vec(right);

    cout << "im here" << endl;
    mergesort(left);
    mergesort(right);
    // int i, j, k = 0; This is WRONG!i and j are not initialized
    unsigned i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            ++i;
        } else {
            arr[k] = right[j];
            ++j;
        }
        ++k;
    }
    while (i < left.size()){
        arr[k] = left[i];
        ++i;
        ++k;
    }
    while (j < right.size()) {
        arr[k] = right[j];
        ++j;
        ++k;
    }
    print_vec(arr);
}



