#include <iostream>
#include <string>
#include <unordered_map>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int DP_LCSLength (string s1, string s2) {
    vector<vector<int>> c;
    unsigned m = s1.size(), n = s2.size();
    for (unsigned i = 0; i <= m; ++i) {
        vector<int> vec(s2.size() + 1, 0);
        c.push_back(vec);
    }
    cout << c[m][n] << endl;
    for (unsigned i = 0; i <= m; ++i) {
        for (unsigned j = 0; j<= n; ++j) {
            if (i == 0 || j == 0) {
                c[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            }
            else {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }
    return c[m][n];
}

int LCSLength(string s1, string s2, unsigned i, unsigned j) {
    if (i == s1.size() || j == s2.size()) return 0;
    else if (s1[i] == s2[j]) {
        return 1 + LCSLength(s1, s2, i + 1, j + 1);
    }
    else {
        return max(LCSLength(s1, s2, i + 1, j),
                   LCSLength(s1, s2, i, j + 1));
    }
}

int main() {
    string s1 = "", s2 = "";
    int len1 = 0, len2 = 0;
    srand(time(NULL));
    cout << "Enter length for string 1: " << endl;
    cin >> len1;
    char c;
    for (unsigned i = 0; i < len1; ++i) {
        c = rand() % 26 + 65;
        s1.push_back(c);
    }
    //s1 = "AGGTAB";
    //s1 = "ABCDGH";
    cout << "s1: " << s1 << endl;
    cout << "Enter length for string 2: " << endl;
    cin >> len2;
    for (unsigned i = 0; i < len2; ++i) {
        c = rand() % 26 + 65;
        s2.push_back(c);
    }
    //s2 = "GXTXAYB";
    //s2 = "AEDFHR";
    cout << "s2: " << s2 << endl;
    cout << endl;
    cout << "LCS of " << endl;
    cout << "       " << s1 << endl;
    cout << "         and " << endl;
    cout << "       " << s2 << endl;
    cout << "         is " << DP_LCSLength(s1, s2) << endl;
    return 0;

}
