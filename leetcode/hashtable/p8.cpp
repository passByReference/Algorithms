/*
 * Problem 8
 */
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;

int main(){
	vector<vector<int>> list = {{1,3},{6,2},{8, 90}, {2,6}, {3,5},{7,4},{5,3}};
	unordered_map<int, int> pairDict;
	vector<vector<int>> result;
	for (auto pair : list){
		if (pairDict[pair[0]] != pair[1])
			pairDict[pair[0]] = pair[1];
		if (pairDict[pair[1]] == pair[0])
			result.push_back(pair);
		
	}
	cout << "Found pairs: " << endl;
	for (auto pair : result) 
		for (auto i : pair)
		       	cout << i << ",";
		cout << endl;	
        cout << endl;
	return 0;

}
