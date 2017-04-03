#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

string largestNumber(vector<int> &num);
static bool comp (string& s1, string& s2) { return s1 > s2; }

int main(){
  string s1 = "";
  string s2 = "";
  while(!(s1 == "q" || s2 == "q")){
    cout << "Enter s1: " << endl;
    cin >> s1;
    cout << "Enter s2: " << endl;
    cin >> s2;
    cout << comp(s1, s2) << endl;
  }
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