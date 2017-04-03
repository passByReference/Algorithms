#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

/*
 * Problem 4 on p284 Data Structures and Algorithms Made Easy
 */
void checkDuplicates(vector<int> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[abs(vec[i])] < 0) {
            cout << "Duplicates exist: " << abs(vec[i]) << endl;
            return;
        }
        else vec[abs(vec[i])] = -vec[abs(vec[i])];
    }
    cout << "No duplicates found." << endl;
}
/*
 *  Problem 8 on p285 Data Structures and Algorithms Made Easy
 */
int MaxRepetitions (vector<int> vec) {
    decltype(vec.size()) length = vec.size(), maxIndex;
    int max = 0;
    for (decltype(vec.size()) i = 0; i < length; ++i) {
        vec[vec[i]] += length; 
    }
    for (decltype(vec.size()) i = 0; i < length; ++i) {
        if (vec[i] / length > max){
            max = vec[i] / length;
            maxIndex = i;
        }
    }
    cout << "im here" << endl;
    cout << max << endl;
    return max;
}


int main() {
    vector<int> vec = {3,2,1,2,2,3};
    //checkDuplicates (vec);
    //int n = MaxRepetitions(vec);
   // cout << MaxRepetitions(vec) << endl;
    int XOR = vec[0];
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        XOR ^= *it;
        cout << XOR << endl;
    }
    return 0;
}
