//
// Created by Andy X on 8/12/17.
//

#include "all.h";

using namespace std;
vector<int> result;

void fill_result(vector<int>::iterator iter, int k) {
    cout << "value found = " << *iter << endl;
    int steps = k / 2;
    int left, right;
    if (k == 1) {
        result.push_back(*iter);
    }
    else if (k % 2 == 0) {
        left = steps;
        right = 0;

        while (left > 0) {
            cout << *(iter - left) << endl;
            result.push_back(*(iter - left));
            --left;
        }

        while (right < steps) {
            cout << *(iter + right) << endl;
            result.push_back(*(iter + right));
            ++right;
        }
    } else {
        left = steps + 1;
        right = 0;

        while (left > 0) {
            cout << *(iter - left) << endl;
            result.push_back(*(iter - left));
            --left;
        }
        while (right < steps) {
            cout << *(iter + right) << endl;
            result.push_back(*(iter + right));
            ++right;
        }
    }


}

vector<int>::iterator find_closest(vector<int>& arr, int x) {
    int prev = INT_MAX;
    int dis = 0;
    for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
        dis = abs(*iter - x);
        cout << prev << ", " << dis << endl;
        if (dis > prev) return iter - 1;
        prev = dis;
    }
    return arr.end();
}

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    if (arr.empty()) return result;
    if (x < arr.front()) {
        return vector<int>(arr.begin(), arr.begin() + k);
    } else if (x > arr.back()) {
        return vector<int>(arr.end() - k, arr.end());
    } else {
        auto val_iter = find(arr.begin(), arr.end(), x);
        if (val_iter == arr.end()) {
            val_iter =  find_closest(arr, x);
        }
        if (val_iter != arr.end()) {
            fill_result(val_iter, k);
        }
    }

    return result;
}

int main() {
    vector<int> vec = {1};
    auto res = findClosestElements(vec, 1, 1);
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
