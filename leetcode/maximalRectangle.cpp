#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<char> a = {"1"};
	vector<vector<char> > b;
	b.push_back(a);
	cout << b[0][0] << endl;

	return 0;
}
