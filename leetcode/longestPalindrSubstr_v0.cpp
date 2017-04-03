/*Given a string S, find the longest palindromic substring in S.
 * You may assume that the maximum length of S is 1000, 
 * and there exists one unique longest palindromic substring.
 */
#include<iostream>

using namespace std;

bool isLetter(char c){
  if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
    return true;
  else
    return false;
}

bool isPalindrome(string s){
  size_t length = s.size();
  if(length == 1)
    return true;
  else if(length == 2){
    if(s[0] == s[1] || !isLetter(s[0]) | !isLetter(s[1]))
      return true;
    else
      return false;
  }
  else {
    int start = 0;
    int end = length - 1;
    while(!isLetter(s[start])) ++start;
    while(!isLetter(s[end])) --end;
      
    if(tolower(s[start]) == tolower(s[end])){
      return isPalindrome(s.substr(start + 1, end - 1 - start));
    }
    else
      return false;
  }
}


string longestPalindrome(string s) {
  size_t length = s.size();
  unsigned max_size = 0;
  string substring = "";
  string result = "";
  for(unsigned start = 0; start < length; ++start){
    for(unsigned end = 0; end < length; ++end){
      substring = s.substr(start, length - start - end);
      if(isPalindrome(substring) && substring.size() > max_size){
	max_size = substring.size();
	result = substring;
      } 
    }
  }
  return result;
       
}


int main(){
  string s = "cyyoacmjwjubfkzrrbvquqkwhsxvmytmjvbborrtoiyotobzjmohpadfrvmxuagbdczsjuekjrmcwyaovpiogspbslcppxojgbfxhtsxmecgqjfuvahzpgprscjwwutwoiksegfreortttdotgxbfkisyakejihfjnrdngkwjxeituomuhmeiesctywhryqtjimwjadhhymydlsmcpycfdzrjhstxddvoqprrjufvihjcsoseltpyuaywgiocfodtylluuikkqkbrdxgjhrqiselmwnpdzdmpsvbfimnoulayqgdiavdgeiilayrafxlgxxtoqskmtixhbyjikfmsmxwribfzeffccczwdwukubopsoxliagenzwkbiveiajfirzvngverrbcwqmryvckvhpiioccmaqoxgmbwenyeyhzhliusupmrgmrcvwmdnniipvztmtklihobbekkgeopgwipihadswbqhzyxqsdgekazdtnamwzbitwfwezhhqznipalmomanbyezapgpxtjhudlcsfqondoiojkqadacnhcgwkhaxmttfebqelkjfigglxjfqegxpcawhpihrxydprdgavxjygfhgpcylpvsfcizkfbqzdnmxdgsjcekvrhesykldgptbeasktkasyuevtxrcrxmiylrlclocldmiwhuizhuaiophykxskufgjbmcmzpogpmyerzovzhqusxzrjcwgsdpcienkizutedcwrmowwolekockvyukyvmeidhjvbkoortjbemevrsquwnjoaikhbkycvvcscyamffbjyvkqkyeavtlkxyrrnsmqohyyqxzgtjdavgwpsgpjhqzttukynonbnnkuqfxgaatpilrrxhcqhfyyextrvqzktcrtrsbimuokxqtsbfkrgoiznhiysfhzspkpvrhtewthpbafmzgchqpgfsuiddjkhnwchpleibavgmuivfiorpteflholmnxdwewj";
  cout << longestPalindrome(s) << endl;
}