/*Implement atoi to convert a string to an integer.
 * Hint: Carefully consider all possible input cases. 
 * If you want a challenge, please do not see below and ask yourself 
 * what are the possible input cases.
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
 * You are responsible to gather all the input requirements up front.
 */
#include<iostream>
#include<string>
#include<climits>
using namespace std;

bool isDigit(char c){
  return c >= 48 && c <= 57;
}
int getDigit(char c){
  return c - 48;
}
string removeSpaces(string s){
  int pos = 0;
  for(unsigned i = 0; i < s.size() - 1; ++i){
    if(s[i] == ' ' && s[i + 1] == ' ') ++pos;
    else break; 
  }
  return s.substr(pos + 1);
}
bool isLetter(char c){
  return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}
string removeNonDigits(string s){
  for(int i = 1;i < s.size(); ++i){
    if(!isDigit(s[i])){
      return s.substr(0, i);
    }
  }
  return s;
}
int atoi(const char *str){
  if(str == NULL || str[0] == '\0')
    return 0;
  string s(str);
  int result = 0;
  bool negative = false;
  unsigned i = 0;
  if(s[0] == ' ') s = removeSpaces(s);
  if(s[0] == '-'){
    negative = true;
    i = 1;
  }
  if(s[0] == '+' || s[0] == '0') i = 1;
  if(isLetter(s[0])) return 0;
  
  s = removeNonDigits(s);
  cout << s << endl;
  for(; i < s.size(); i++){
    if(result > INT_MAX / 10){
      if(negative)
	return INT_MIN;
      return INT_MAX;
    }
  
    if(INT_MAX - getDigit(s[i]) <= result * 10){
      if(negative){
	if(INT_MAX - getDigit(s[i]) >= result * 10)
	  return -INT_MAX;
	return -INT_MAX -1;
      }
      return INT_MAX;
    }
    
    result = result * 10 + getDigit(s[i]);
    
  }
  
  if(negative) return -result;
  
  return result;
}

int main(){
  //const char* str = "-2147483647";
  const char* str = "      -11919730356x";
  int x = atoi(str);
  cout << "x = " << x << endl;
  //cout << removeNonDigits("  +93  374 ") << endl;
  return 0;
}