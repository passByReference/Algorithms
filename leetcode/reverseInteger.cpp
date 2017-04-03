/*
 * Reverse digits of an integer.
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 */

#include<iostream>
#include<climits>

using namespace std;
int reverse(int x){
  int r = 0;
  int result = 0;
  if(x == 0)
    return result;
  /*
  while(x % 10 == 0){
    x = x / 10;
    if(x == 1 || x == 0)
      break;
  }
  */
  while(x != 0){
    r = x % 10;
    if(result > INT_MAX / 10 || result < INT_MIN / 10)
      return 0;
    result = result * 10 + r;
    x = x / 10; 
  }
  if(x < 0)
    return -result;
  return result;
}

int main(){
  int x = 1534236469;
  cout << reverse(x) << endl;
 
}