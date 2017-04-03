/*
 * Problem 5: Given two arrays of unordered numbers, check whether both arrays
 * have the same set of numbers
 */
#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>
typedef std::unordered_map<int, int> intMap;
typedef std::unordered_set<int> set;
using namespace std;
int main(){
	vector<int> v1 = {2,5,6,8,10,2,2};
	vector<int> v2 = {2,5,5,8,10,5,6};
	set result;
	intMap dict;
	for(auto i : v1){
		if (dict[i] == 1) continue;
		else dict[i] = 1;
	}
	for(auto i : v2) {
		if (dict[i] == 1)
			result.insert(i);
	}
	for(auto i : result) cout << i << ",";
	cout << endl;
	return 0;
}
