/*
 * Problem 17
 */
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){
	vector<int> vec;
	int input = 0;
	while(true){
		cout << "Enter numbers: \n";
		cin >> input;
		if(input == -1) break;
		vec.push_back(input);
	}
	cout << "Enter sum: \n";
	int sum = 0;
	cin >> sum;
	unordered_map<int, int> dict;
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it){
		dict[sum - *it] = *it;
		if(dict[*it] == sum - *it){
			cout << "( " << sum - *it << ", " << *it << ")" << endl;
		}
	}
	return 0;
}
