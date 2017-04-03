#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isIsomorphic (string s, string t) {
    if (s == "" || t == "") return true;
    unordered_map<char, int> m1, m2;
    for (int i = 0; i < s.size(); ++i) {
        if (m1[s[i]] != m2[t[i]]) return false;
        else {
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
    }
    return true;
}

int main () {
    string s1 = "a";
    string s2 = "a";
    cout << isIsomorphic(s1, s2) << endl;
    
    return 0;
}
