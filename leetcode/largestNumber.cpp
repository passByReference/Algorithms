/* Given a list of non negative integers, arrange them such that they form the largest number.
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 * Note: The result may be very large, so you need to return a string instead of an integer.
 * 
 * 
 * 1/14/2015
 * Points:
 * continue to work on if a max number occurs multiple times.
 * 
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

string largestNumber(vector<int> &num);
static bool comp (string& s1, string& s2) { return s1+s2 > s2+s1; }

int main(){
  vector<int> num = {3};
  string result = "";
  result = largestNumber(num);
  cout << result << endl;
}

string largestNumber(vector<int> &num) {

            //convert int to string
            vector<string> v;
            for (unsigned i=0; i<num.size(); i++) {
                v.push_back(to_string(num[i]));
            }

            //sort the string
            sort(v.begin(), v.end(), comp);

            //generate the result
            string result;
            for(unsigned i=0; i<v.size(); i++ ){
                result+=v[i];
            }

            //special case: start with zero (e.g. [0, 0])
            if (result[0]=='0') return "0";

            return result;
}