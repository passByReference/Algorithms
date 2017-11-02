#include "all.h"

using namespace std;


vector<int> findAnagrams(string s, string p) {
    vector<int> m(128, 0);
    vector<int> result;
    
    for (auto c : p) {
        ++m[c];
    }
    
    int left = 0, right = 0, count = p.size();
    while (right < s.size()) {
        //move right everytime, if the character exists in p's hash, decrease the count
        //current hash value >= 1 means the character is existing in p
        if (m[s[right]] >= 1) {
            --count;
        } 
        cout << "s[right]: " << s[right] << " m[s[right]]: " << m[s[right]] << endl;
        cout << "s[left]: " << s[left] << " m[s[left]] = " << m[s[left]] << endl;
        cout << "count: " << count << endl;
        --m[s[right]]; //if a char is not in p, it could go below 0
        ++right;
        
        //when the count is down to 0, means we found the right anagram
        //then add window's left to result
        if (count == 0) {
            result.push_back(left);
        }
        
        // within p's size, if there is some char matched some char not, then when right - left equals p's size
        // it is time to reset the window.
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
    auto res = findAnagrams(s, p);
    print(res);
    return 0;

}
