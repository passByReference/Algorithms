#include "all.h"

using namespace std;

int lengthOfLongestSubstring(const string& s) {
    int max_val = 0;
    unordered_map<char, int> m;
    for (int i = 0; i < s.size(); ++i) {
        int j = i + 1;
        m[s[i]] = 1;
        while (j < s.size() && !m[s[j]]) {
            m[s[j]] = 1;
            ++j;
        }
        cout << "i = " << i << " j = " << j << endl;
        max_val = max(max_val, j - i);
        cout << "max = " << max_val << endl;
        m.clear();
    }
    return max_val;
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
