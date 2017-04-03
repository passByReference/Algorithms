#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int lengthOfLastWord(string s) {
    int length = 0;
    if (s.empty()) return length;

    int index = s.size() - 1;
    while (s[index] == ' ') --index;
    cout << index << endl;
    while (s[index] != ' ' && index >= 0) {
        cout << index << " " << s[index] << endl;
        --index;
        ++length;
    }
    cout << length << endl;
    return length;
}

int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    if (haystack.empty()) return -1;
    for (int i = 0; i < haystack.size(); ++i) {
        if (haystack[i] == needle[0] && 
                (i + needle.size()) <= haystack.size()) {
            bool match = true;
            for (int j = i, k = 0; k < needle.size(); ++j, ++k) {
                if (haystack[j] != needle[k]) {
                    match = false;
                    break;
                }
            }
            cout << "match = " << match << endl;
            cout << "i = " << i << endl;
            if (match) return i;
        }
    }
    return -1;
}

bool isPalindrome(string s) {
    if (s.empty()) return true;
    if (all_of(s.begin(), s.end(), [](char c) {return (!isalpha(c));}))
        return true;
    for (int left = 0, right = s.size() - 1; left <= right; 
            ++left, --right) {
        if (!isalpha(s[left])) ++left;
        if (!isalpha(s[right])) --right;
        s[left] = tolower(s[left]);
        s[right] = tolower(s[right]);
        cout << s[left] << " " << s[right] << endl;
        cout << (s[left] == s[right]) << endl;
        if (s[left] != s[right]) return false;
        if (left == right) break;
    }
    return true;
}

string clean(string s) {
    if (s.size() > 1 && s[0] == '0') {
        int cnt = 0;
        int i = 0;
        while(s[i] == '0') {
            ++cnt;
            ++i;
        }
        if (cnt >= s.size()) return "0";
        cout << "im here " << s.substr(cnt) << endl;
        return s.substr(cnt);
    }
    return s;
}
int compareVersion(string version1, string version2) {
    cout << version1 << " " << version2 << endl;
    if (version1.empty() && !version2.empty()) {
        if (all_of(version2.begin(), version2.end(), 
                    [](char c){return c == '0' || c == '.';}))
            return 0;
        cout << "im here1" << endl;
        cout << version2 << endl;
        return -1;
    }
    else if (!version1.empty() && version2.empty()){
        if (all_of(version1.begin(), version1.end(),
                    [](char c){return c == '0' || c == '.';}))
            return 0;
        return 1;
    }
    else if (version1.empty() && version2.empty()) return 0;
    auto i1 = version1.find(".");
    auto i2 = version2.find(".");
    string s1 = "", s2 = "";
    if (i1 == string::npos && i2 != string::npos) {
        s1 = version1;
        i1 = version1.size() - 1;
        s2 = version2.substr(0, i2);
    }
    else if (i1 != string::npos && i2 == string::npos) {
        s1 = version1.substr(0, i1);
        s2 = version2;
        i2 = version2.size() - 1;
    }
    else if (i1 != string::npos && i2 != string::npos) {
        s1 = version1.substr(0, i1);
        s2 = version2.substr(0, i2);
    }
    else {
        s1 = version1;
        i1 = version1.size() - 1;
        s2 = version2;
        i2 = version2.size() - 1;
    }
    s1 = clean(s1);
    s2 = clean(s2);
    if (stoi(s1) > stoi(s2)) return 1;
    else if (stoi(s2) > stoi(s1))
    {
        cout << "im here2" << endl;
        return -1;
    }
    else return compareVersion(version1.substr(i1 + 1), version2.substr(i2 + 1));
}

void reverseWords(string &s) {
    if (s.empty()) return;
    if (all_of(s.begin(), s.end(), [](char c){return isspace(c);})) {
        s = "";
        return;
    }
    string result = "";
    int i = 0, j = s.size() - 1;
    while (isspace(s[i])) ++i;
    while (isspace(s[j])) --j;
    s = s.substr(i, j - i + 1);
    j = s.size();
    for (i = s.size() - 1; i >= 0; --i) {
        if (isspace(s[i])) {
            result += s.substr(i + 1, j - i - 1) + " ";
            j = i;
        }
        cout << i << endl;
        cout << s[i] << endl;
        cout << result << endl;
    }
    result += s.substr(0, j);
    for (auto it = result.begin() + 1; it != result.end(); ++it) {
        if (isspace(*it) && (isspace(*(it - 1)) || *(it - 1) == '@')) {
            *it = '@';
        }
    }
    while (result.find('@') != string::npos) {
        result.erase(result.find("@"), 1);
    }
    cout << s << endl;
    cout << "result: " << result << endl;
    s = result;
}

string multiply(string num1, string num2) {
    long long n1, n2;
    try {
         n1 = stoll(num1);

    } catch (exception& e) {
        cout <<"n1 " << e.what() << endl;
        long long(n1) = stoll(num1);
    }

    try {
         n2 = stoll(num2);
    } catch (exception& e) {
        cout << "n2 " << e.what() << endl;
    }
    cout << "num1 = " << num1 << " n1 = " << n1 << endl;
    cout << "num2 = " << num2 << " n2 = " << n2 << endl;
    if (n2 != 0) {
        if (n1 >= (INT_MAX / n2)) 
            return to_string((long long)(n1) * (long long)(n2));
    }
    return to_string(n1 * n2);
}

int titleToNumber(string s) {
    if (s.empty()) return 0;
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<char, int> m;
    int col = 0;
    for (int i = 0; i < letters.size(); ++i) {
        m[letters[i]] = i + 1;
    }
    for (int i = s.size() - 1; i >= 0; --i) {
        col += m[s[i]] * pow(26, s.size() - i - 1);
    }
    return col;
}

string converToTitle(int n) {
    if (n == 0) return "";
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<int, char> m;
    m[0] = 'Z';
    for (int i = 0; i < letters.size() - 1; ++i) {
        m[i + 1] = letters[i];
    }
    string result = "";
    if (n == 26) return "Z";
    while (n != 0) {
        result = m[n % 26] + result;
        if (n % 26 == 0) {
            n = n / 26 - 1;
        }
        else {
            n = n / 26;
        }

    }
    return result;
}

string countAndSay(int n) {
    unordered_map<int, int> m;
    string result = "";
    while (n != 0) {
        ++m[n % 10];
        n = n / 10;
    }
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second > 0) {
            string s = to_string(it->second) + to_string(it->first);
            result += s;
        }
    }
    return result;
}

string reverse(string str) {
    unsigned n = str.size();
    for (unsigned i = 0, j = n - 1; i < j; ++i, --j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    return str;
}

void parCombo(vector<string>& result, string combo, int size, int n, int numLeftPar, int numRightPar) {
    if (size == 2 * n) {
        result.push_back(combo);
        return;
    }
    if (numLeftPar < n) {
        combo.push_back('(');
        parCombo(result, combo, size + 1, n, numLeftPar + 1, numRightPar);
        combo.pop_back();
    }
    if (numRightPar < numLeftPar) {
        combo.push_back(')');
        parCombo(result, combo, size + 1, n, numLeftPar, numRightPar + 1);
        combo.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string combo = "";
    if (n != 0) parCombo(result, combo, 0, n, 0, 0);
    return result;
}

int main(){
    string s = "mississippi";
    string s2 = "issip";
    string s3 = "the   sky is    blue";
    string s4 = "  a    b";
    cout << strStr(s, s2) << endl;
    //string s3 = "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";//for compareVersion
    //string s4 = "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";// for compareVersion
    //string s5 = "01";
    //string s6 = "1";
    //cout << lengthOfLastWord(s) << endl;
    //cout << strStr (s, s2) << endl;
    //cout << isPalindrome(s3) << endl;
    //cout << compareVersion(s3, s4) << endl;
    //reverseWords(s4);
    //cout << multiply("6913259244", "71103343");
    //cout << titleToNumber("AA") << endl;
    //cout << converToTitle(52) << endl;
    //cout << countAndSay(112211);
    auto res = generateParenthesis(3);
    return 0;
}
