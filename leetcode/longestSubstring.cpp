#include<iostream>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    map<char, int> m;
    int maxLen = 0;
    int lastRepeatPos = -1;
    for(unsigned i=0; i<s.size(); i++){
        if (m.find(s[i])!=m.end() && lastRepeatPos < m[s[i]]) {//lastRepeatPos < m[s[i]]
            lastRepeatPos = m[s[i]];			       //so that lastRepeatPos always has 
							       //the pos of closet repeated character.
        }
        if ( i - lastRepeatPos > maxLen ){
            maxLen = i - lastRepeatPos;//stores maxLen after each run
        }
        m[s[i]] = i;
    }
    return maxLen;
}

int main(){
  string s = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
  cout << lengthOfLongestSubstring(s) << endl;
}