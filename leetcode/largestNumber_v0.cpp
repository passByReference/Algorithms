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

using namespace std;

string largestNumber(vector<int> &num);
vector<int> separateDigits(int number);
int sum(vector<int> vec);
int max(vector<int>& vec);
int numberOfOccur(vector<int> vec, int val);
void addToCurrentDigits(vector<int> &currentDigits, vector<vector<int>> digitNums);

int main(){
  vector<int> num = {3, 30, 34, 5, 9};
  string result = "";
  result = largestNumber(num);
}

string largestNumber(vector<int> &num){
  vector<vector<int>> digitNums;
  string result_str = "";//stores the final result in string
  vector<int> result_vec;//stores the final result in vector
  vector<int> numberSizes;
  for(auto val : num){
    vector<int> digitNum = separateDigits(val);
    numberSizes.push_back(digitNum[int(digitNum.size() - 1)]);
    digitNum.pop_back();
    digitNums.push_back(digitNum);
  }
  /* print all digits in digitNums
  for(auto val : digitNums){
    for(vector<int>::iterator it = val.end() - 1; it >= val.begin(); --it)
      cout << *it;
    cout << endl;
  }
  */
  int numOfDigits = 0;
  int maxDigit = 0;
  vector<int> currentDigits;//stores digits at one comparison
  while(numOfDigits < sum(numberSizes)){
    addToCurrentDigits(currentDigits, digitNums);
    maxDigit = max(currentDigits);
    if(numberOfOccur(currentDigits, maxDigit) == 1)
      result_vec.push_back(maxDigit);
    else{
      //here
    }
    
  }
  
  return result;
}

int sum(vector<int> vec){
  int sum = 0;
  for(auto i : vec){
    sum += i;
  }
  return sum;
}

int max(vector<int>& vec){
  int max = 0;
  for(auto i : vec){
    if(i > max)
      max = i;
  }
  return max;
}

int numberOfOccur(vector<int> vec, int val){
  int counter = 0;
  for(auto i : vec){
    if(i == val)
      ++counter;
  }
  return counter;
}
void addToCurrentDigits(vector<int> &currentDigits, vector<vector<int>> digitNums){
  for(auto number : digitNums){
    currentDigits.push_back(number[int(number.size() - 1)]);
  }
}

vector<int> separateDigits(int number){
  int digit = 0;
  vector<int> digits;
  int digitCounter = 0;
  while(number > 0){
    digit = number % 10;
    digits.push_back(digit);
    number /= 10;
    ++digitCounter;
  }
  digits.push_back(digitCounter);
  return digits;
}