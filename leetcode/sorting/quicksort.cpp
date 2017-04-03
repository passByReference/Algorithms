#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

void quicksort(vector<int>& arr, int p, int r);
int partition(vector<int>& arr, int p, int r);
void print(vector<int>& arr) {
    for (auto v : arr) {
        cout << v << ", ";
    }
    cout << endl;
}
int main() {
    vector<int> arr{6, 5, -1, 3, 2, 3 ,100, 7, 9, 8, 20, 0, 99, 12, 43, 5, 1, 33, 88, 14, 6, -99};
    quicksort(arr, 0, arr.size());
    cout << "Result: " << endl;
    for (vector<int>::const_iterator it = arr.cbegin(); it != arr.cend(); ++it) {
        cout << *it << ", ";
    }
    cout << endl;
}

int partition(vector<int>& arr, int p, int r) {
    int x = arr[r - 1]; // set the last element of the range as the pivot
                        // note: in CLRS's psudocode, arr starts at 1, in my code arr starts at 0, 
                        // so last element of the subarray is r - 1 instead of r
    int i = p - 1;

    for (int j = p; j < r - 1; ++j) {
        if (arr[j] <= x) {
            ++i;
            swap(arr[i], arr[j]);
        }
        print (arr);
    }
    swap(arr[i + 1], arr[r - 1]);
    return i + 1; // q

}

void quicksort(vector<int>& arr, int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quicksort(arr, p, q);
        quicksort(arr, q + 1, r);
    }
}
