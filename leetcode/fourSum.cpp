#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<vector<int>> fourSum(vector<int> &num, int target){
	sort(num.begin(), num.end());
	vector<int> select;
	vector<vector<int>> result;
	int current_target = target;
	int i = 0;
	while(i < num.size()){	
		cout << "im in " << endl;
		if(num[i] > current_target){
			select.clear();
			++i;
			continue;
		}
		select.push_back(num[i]);
		current_target = current_target - num[i];
		cout << "i = " << i << endl;
		int cur_i = i;
		int j = cur_i + 1;
		while(j < num.size()){ 
			cout << "im here " << j << " " << num.size() << endl;
			if(num[j] > current_target || select.size() >= 4){
				select.erase(select.end() - 1, select.end());
				++cur_i;
				j = cur_i;
				cout << j << endl;
				
			}
			else if(num[j] == current_target && select.size() == 3){
				select.push_back(num[j]);
				result.push_back(select);
				select.clear();
				break;
			}
			select.push_back(num[j]);
			current_target = current_target - num[j];
			 ++j;
		}
		cout << " im out " << endl;
		++i;
		select.clear();
	}
	return result;

}

int main(){
	vector<int> input = {1,0,-1,0,-2,2};
	int target = 0;
	//cout << "Enter target" << endl;
	//cin >> target;
	vector<vector<int>> result;
	result = fourSum(input, target);
	for(auto s : result){
		cout << "( ";
		for(auto n : s)
			cout << n << ",";
		cout << " )" << endl;
	}
	return 0;

}
