#include "../all.h"

using namespace std;

vector<int> findAnagram(string s, string p) {
    vector<int> result;
    vector<int> m(128, 0);
    for (auto c : p) {
        ++m[c];
    }

    int left = 0, right = 0, count = p.size();

    while (right < s.size()) {
        if (m[s[right]] >= 1) {
            --count;
        }
        --m[s[right]];
        ++right;

        cout << "left: " << left << " right: " << right << endl;
        cout << "count: " << count << endl;
        if (count == 0) {
            result.push_back(left);
        }

        if (right - left == p.size()) {
            if (m[s[left]] >= 0) {
                ++count;
            }
            ++m[s[left]];
            ++left;
        }
    }

    return result;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";

    auto res = findAnagram(s, p);
    print(res);
    return 0;
}
