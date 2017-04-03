#include<iostream>
#include<map>
using namespace std;

bool isValid(string s);

bool isValid(string s){
	int len = s.length();
	if (len == 1) return false;
	if(s == ""|| len == 0) return true;
	else if(s[0] == '('){
		if(s[1] == ')') return isValid(s.substr(2, len - 2));
		else if(s[len - 1] == ')') return isValid(s.substr(1, len - 2));
		else{
		cout <<"im here" << endl;
			bool found = false;
			unsigned i = 2;
			unsigned counter = 0;
			while(i < len) {
				if(s[i] == ')'){
					found = true;
					break;
				}
				if(s[i] == '(') counter = 1;
				++i;
				++counter;
			}

			if(!found) return false;
			cout << s << endl;
			string s1 = s.substr(1, i - 1) + s.substr(i + 1);
			cout << s1 << " in (" << endl;
			cout << i << endl;
			if(counter % 2 == 0) return false;
			return isValid(s.substr(1, i - 1) +
				s.substr(i + 1));
		}

	}else if(s[0] == '{'){
		if(s[1] == '}') return isValid(s.substr(2, len - 2));
		else if(s[len - 1] == '}') return isValid(s.substr(1, len - 2));
		else{
			bool found = false;
			unsigned i = 2;
			unsigned counter = 0;
			while(i < len){
				if(s[i] == '}'){
					found = true;
					break;
				}
				if(s[i] == '{') counter = 1;
				++i;
				++counter;
			}
			cout << len << endl;
			if(!found) return false;
			cout << s << endl;
			string s1 = s.substr(1, i - 1) + s.substr(i + 1);
			cout << s1 << endl;
			cout << "counter = " << counter << endl;
			if(counter % 2 == 0) return false;
			return isValid(s.substr(1, i - 1) +
				s.substr(i + 1));
		}

	}
	else if(s[0] == '['){
		if(s[1] == ']') return isValid(s.substr(2, len - 2));
		else if(s[len - 1] == ']') return isValid(s.substr(1, len - 2));
		else{
			bool found = false;
			unsigned i = 2;
			unsigned counter = 0;
			while(i < len) {
				if(s[i] == ']'){
					found = true;
					break;
				}
				if(s[i] == '[') counter = 1;
				++i;
				++counter;
			}
			cout << i << " " << found << endl;
			if(!found) return false;
			string s1 = s.substr(1, i - 1) + 
			s.substr(i + 1);
			cout << s1 << endl;
			
			if(counter % 2 == 0) return false;
			return isValid(s.substr(1, i - 1) +
				s.substr(i + 1));
		}

	}
	else return false;
}

int main(){
	cout << "Enter a string: " << endl;
	string str = "";
	while(str != "q"){
		cin >> str;
		cout << isValid(str) << endl;
	}
	return 0;
}
