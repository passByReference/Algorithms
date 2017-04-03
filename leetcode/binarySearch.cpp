#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int> vec, int number){
  auto beg = vec.begin(), end = vec.end();
  auto mid = vec.begin() + (end - beg) / 2;
  
  while(mid != end && *mid != number){
    if(number < *mid){
      end = mid;
    }
    else
      beg = mid + 1;
    mid = (beg + end) / 2;
  }
  return *mid;
}

int main(){
  vector<int> vec = {3,5,7,8,9,12,15};
  int number = 0;
  cout << " Enter number to search: " << endl;
  cin >> number;
  cout << binarySearch(vec,number) << endl;
  
  
}