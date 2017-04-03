#include<iostream>
#include<vector>
#include <algorithm>  
using namespace std;

vector<vector<int>> threeSum(vector<int> &num){
  vector<vector<int> > result;
  if(num.size() == 0 || num.size() == 1) return result;
  sort(num.begin(), num.end());

  for(unsigned i = 0; i < num.size() - 2; ++i){
   if(i > 0 && num[i - 1] == num[i]) continue;
    int low = i + 1;
    int high = num.size() - 1;
    while(low < high){
      int a = num[i];
      int b = num[low];
      int c = num[high];
      if(a + b + c == 0){
	vector<int> triplet;
	triplet.push_back(a);
	triplet.push_back(b);
	triplet.push_back(c);
	result.push_back(triplet);
	while(low < num.size() && num[low] == num[low + 1]) ++low;
	while(high > 0 && num[high] == num[high - 1]) --high;
	++low;
	--high;
      }
      else if(a + b + c > 0){
	while(high > 0 && num[high] == num[high - 1]) --high;
	--high;
      }
      else{
	while(low < num.size() && num[low] == num[low + 1]) ++low;
	++low;
      }
    }
  }
  return result;
 }


int main(){
  vector<int> num = {-1,0,1,2,-1,-4};
  vector<vector<int>> result = threeSum(num);
  for(auto i : result){
    for(auto j : i){
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}