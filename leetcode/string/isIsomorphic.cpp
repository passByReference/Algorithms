#include "../all.h"

using namespace std;

bool isIsomorphic(string s, string t) {
    unordered_map<char, vector<int>> m;
    for (int i = 0; i < s.size(); ++i) {
        m[s[i]].push_back(i);
    }
    for (auto rec : m) {
        cout << rec.first;
        for (auto v : rec.second)
            cout << " " << v << endl;
    }
    return true;
}

int main() {
    string s1 = "egg";
    string s2 = "add";
    isIsomorphic(s1, s2);
    return 0;
}
