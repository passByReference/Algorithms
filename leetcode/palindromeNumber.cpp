//Determine whether an integer is a palindrome. Do this without extra space.

#include<iostream>
#include<climits>
using namespace std;

int reverse(int x){
  int r = 0;
  int result = 0;
  if(x == 0)
    return result;
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

bool isPalindrome(int x){
  if(x < 0)
    return false;
  int x_reversed = reverse(x);
  cout << x_reversed << endl;
  if(x_reversed == 0 && x != 0)
    return false;
  
  while(x != 0 && x_reversed != 0){
    if(x % 10 != x_reversed % 10)
      return false;
    x = x / 10;
    x_reversed = x_reversed / 10;
  }
  return true;
}

int main(){
  int x = 0;
  x = -2147447412;
  cout << isPalindrome(x) << endl;
}
