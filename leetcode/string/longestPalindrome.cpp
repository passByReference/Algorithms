#include "../all.h"

using namespace std;


bool isPalindrome(const string& s, int start, int end) {
    while (start <= end) {
        cout << start << ", " << end << endl;
        if (s[start++] != s[end--]) return false;
    }
    return true;
}

string longestPalindrome(string s) {
    if (s.size() <= 1) return s;
    string res;
    res.push_back(s.front());
    for (int i = 0; i < s.size() - 1; ++i) {
        int start = i, end = i + 1;
        while ((end = s.find(s[start], end)) != string::npos) {
            cout << "start = " << start << " end = " << end << endl;
            if (isPalindrome(s, start, end) && end - start >= res.size()) {
                cout << "palaindrome: " << start << ", " << end << endl;
                res = s.substr(start, end - start + 1);
            }
            ++end;
        }
    }
    return res;
}

int main() {
    string s = "aaa";
    cout << "haha: " << isPalindrome(s, 0, 2) << endl;
    cout << longestPalindrome(s) << endl;

    return 0;
}
