#include<iostream>
#include<math.h>
#include "Hashtable.h"
#include<vector>
using namespace std;
const double A = 0.6180334887;
int hashfunction(string s, int size);
int main(){
        size_t size = 0;
	cout << "Enter the size of table:" << endl;
	cin >> size;
	Hashtable ht(size);
	int index = 0;
	string input = "";
	while(true){
		cout << "Enter a string: " << endl;
		cin >> input;
		if(input == "q") break;
		index = hashfunction(input, size);
		cout << "Index for " << input << " is " << index << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		ht.insert(input, index);
	
	}
	
	cout << endl;
	cout <<"table size =" << ht.getTableSize() << endl;
	cout << "All strings in the table are: " << endl;
	ht.printTable();

	while(true){
		cout << "Enter string to remove: " << endl;
		cin >> input;
		if (input == "q") break;
		ht.removeStr(input);
		ht.printTable();
	}
	return 0;
}

int hashfunction(string s, int size){
	int sum = 0;
	for(auto c : s) sum += c;
	return floor (size * (sum * A - floor(sum * A)));
}
