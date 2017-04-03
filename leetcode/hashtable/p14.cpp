/*
 * Problem 14
 */
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
	cout << "Enter a string: \n";
	string str = "";
	cin >> str;
	unordered_map<char, int> dict;
	for(string::iterator it = str.begin(); it != str.end(); ++it){
		++dict[*it];
	}
	for(auto c : str){
		if(dict[c] == 1){
			cout << c << endl;
			break;
		}
	}
	return 0;
}
