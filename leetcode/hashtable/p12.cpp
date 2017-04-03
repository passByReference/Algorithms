/*
 * Problem 12
 */

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main(){
	vector<int> A = {1,2,3,4,5,6,7,8,9,10};
	vector<int> B = {5,3,2,1,5,7,8,4,9,3};
	unordered_map<int, int> dict;
	cout << "Enter k: \n";
	int k = 0;
	cin >> k;
	for(vector<int>::iterator it = A.begin(); it != A.end(); ++it){
		dict[k - *it] = *it;
	}
	cout << "result:\n";
	for(vector<int>::iterator it = B.begin(); it != B.end(); ++it){
		if (dict[*it] = k - *it)
			cout << *it << endl;
	}
	return 0;

}
