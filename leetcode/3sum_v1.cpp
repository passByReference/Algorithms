#include<iostream>
#include<vector>
#include <algorithm>  
using namespace std;

vector<vector<int>> threeSum(vector<int> &num){
  vector<vector<int> > result;
  if(num.size() == 0 || num.size() == 1) return result;
  sort(num.begin(), num.end());
  int first = 0;
  int pre_first = -1000000;
  vector<int> triplet;
  for(unsigned i = 0; i < num.size() - 2; ++i){
    triplet.push_back(num[i]);
    for(unsigned x = i + 1; x < num.size(); ++x){
      first = num[i] + num[x];
      if(first == pre_first) continue;
      pre_first = first;
      if(first > 0) break;
      triplet.push_back(num[x]);
      for(unsigned j = x + 1; j < num.size(); ++ j){
	if(num[j] + first == 0){
	  cout << i << " " << x << " " << j << " " << first << " " << num[j] << endl;
	  triplet.push_back(num[j]);
	  result.push_back(triplet);
	  triplet.pop_back();
	  break;
	}
      }
      triplet.pop_back();
    }
    triplet.clear();
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