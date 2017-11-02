#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<string> letterCombinations(string digits);

int main(){
  vector<string> result;
  result = letterCombinations("23");
  for(auto i : result)
    cout << i << endl;
}

vector<string> letterCombinations(string digits){
  map<char, string> combos;
  vector<string> strs;
  vector<string> result;
  if(digits == ""){
    result.push_back("");
    return result;
  }
  combos['2'] = "abc";
  combos['3'] = "def";
  combos['4'] = "ghi";
  combos['5'] = "jkl";
  combos['6'] = "mno";
  combos['7'] = "pqrs";
  combos['8'] = "tuv";
  combos['9'] = "wxyz";
  for(auto d:digits) strs.push_back(combos[d]);
  for(auto c : strs[0]){
    string s(1, c);
    result.push_back(s);
  }
  for(vector<string>::iterator it = strs.begin() + 1;it != strs.end(); ++it){
    vector<string> new_vec;
    for(auto c:*it){
      string s(1, c);
      vector<string>::iterator iter = result.begin();
      while(iter != result.end()){
        string str = *iter;
        str = str + s;
        new_vec.push_back(str);
        ++iter;
      }
    }
    result = new_vec;
  }
  return result;
}
