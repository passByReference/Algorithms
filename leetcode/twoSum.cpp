#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void findIndices(int n1, int n2, vector<int> &original, vector<int> &indices){
	indices.clear();
        for(unsigned i = 0; i < original.size(); ++i){
	    if(indices.size() >= 2) break;
            if(original[i] == n1)
                indices.push_back(i + 1);
            else if(original[i] == n2)
                indices.push_back(i + 1);
        }
    }
    
void print(vector<int> vec){
  for(auto i : vec)
    cout << i << " ";
}
vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> original(numbers);
        sort(numbers.begin(), numbers.end());
        vector<int> indices = {0, 0};
        for(unsigned i = 0; i < numbers.size() - 1 ; ++i){
            unsigned j = i + 1;
            for(;j < numbers.size(); ++j){
                if(numbers[i] + numbers[j] == target){
                    findIndices(numbers[i], numbers[j], original, indices);
                    return indices;
                }
                else if(numbers[i] > target) break;
            }
        }
        return indices;
        
}

int main(){
  vector<int> numbers = {3, 2, 4};
  vector<int> result;
  result = twoSum(numbers, 6);
  print(result);
  return 0;
}