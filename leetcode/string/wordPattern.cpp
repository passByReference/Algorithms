#include "../all.h"

using namespace std;
bool wordPattern(string pattern, string str) {
    unordered_map<string, char> str_m;
    unordered_map<char, string> pat_m;
    size_t end = 0;
    int j = 0, start = 0;
    while ((end = str.find(" ", start)) != string::npos) {
        auto word = str.substr(start, end - start);
        if (str_m.find(word) != str_m.end()) {
            if (str_m[word] != pattern[j]) {
                return false;
            }
        } else {
            if (pat_m.find(pattern[j]) != pat_m.end()) {
                str_m[word] = pattern[j];
                pat_m[pattern[j]] = word;
            } else {
                return false;
            }

        }
        start = end + 1;
        ++j;
    }
    
    auto word = str.substr(start);
    if (str_m.find(word) != str_m.end()) {
        if (str_m[word] != pattern[j]) return false;
    } else {
        if (pat_m.find(pattern[j]) != pat_m.end()) {
                str_m[word] = pattern[j];
                pat_m[pattern[j]] = word;
            } else {
                return false;
            }
    }
    if (str_m.size() != pat_m.size()) return false;
    return true;
    
}
int main() {
    string pattern = "abba";
    string str = "dog cat cat dog";
    cout << wordPattern(pattern, str) << endl;
    return 0;
}
