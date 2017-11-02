#include "all.h"

using namespace std;

string getString(char c) {
    switch(c) {
        case '2': return "abc";
        case '3': return "def";
        case '4': return "ghi";
        case '5': return "jkl";
        case '6': return "mno";
        case '7': return "pqrs";
        case '8': return "tuv";
        case '9': return "wxyz";
        default: return "";
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.empty()) return result;
    auto firstStr = getString(digits.front());
    cout << "size = " <<result.size() << endl;
    int n = firstStr.size();
    for (int i = 1; i < digits.size(); ++i) {
        string newDigitStr = getString(digits[i]);
        if (newDigitStr.empty()) continue;
        for (int j = 0; j < n; ++j) {
            string newStr;
            newStr.push_back(firstStr[j]); 
            for (int k = 0; k < newDigitStr.size(); ++k) {
                newStr.push_back(newDigitStr[k]);
                result.push_back(newStr);
                newStr.pop_back();
            }
        }
    }
    return result;
}

int main() {
    string s = "23";
    auto res = letterCombinations(s);
    for (auto s : res) {
        cout << s << endl;
    }
    return 0;
}
