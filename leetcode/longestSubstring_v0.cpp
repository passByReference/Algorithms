#include<iostream>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int lengthOfLongestSubstring(string s){
          unsigned max = 0;
          string s2 = "";
          char c = ' ';
          string str = s;
          map<char, int> s_map;
          while(!str.empty()){
              string s1 = str;
              while(!s1.empty()){
                  c = s1.back();
                  s1.pop_back();
		  map<char, int>::iterator it;
		  it = s_map.find(c);
                  if(it != s_map.end()){
                      if(s2.length() > max){
                        max = s2.length();
			cout << s2 << endl;
		      }
                      break;
                  }
                  else{
                      s2.push_back(c);
		      s_map[c] = 1;
                  }
                  
              }
              str.pop_back();
          }
          return max;
    }

int main(){
  string s = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
  cout << lengthOfLongestSubstring(s) << endl;
}