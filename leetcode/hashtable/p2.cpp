/*
 * Problem 2: Given an array of characters, give an algorithm for 
 * removing the duplicates
 */
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
typedef std::unordered_map<char, int> charMap;
int main(){
	charMap dict;
	vector<char> arr = {'a','b','c','v','a'};
	char input = '\0';
	while(true){
		cin >> input;
		if(input == 'q') break;
		arr.push_back(input);

	}
	cout << "The array entered is: " << endl;
	for (auto c : arr) cout << c << ",";
	cout << endl;
	for (int i = 0; i < arr.size(); ++i){
		if (dict[arr[i]] == 1){
			arr.erase(arr.begin() + i);
			--i;
		}
		else
			dict[arr[i]] = 1;
			
	}
	cout << "The new array is: " << endl;
	for (auto c : arr) cout << c << ",";
	cout << endl;
	return 0;
}
