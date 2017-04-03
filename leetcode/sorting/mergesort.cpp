#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

void mergesort(vector<int>* arr);

int main()
{
	vector<int> arry{6,5,3,1,8,7,2,4};
  mergesort(&arry); 
  cout << "Result: " << endl;
  for(vector<int>::iterator it = arry.begin(); it != arry.end(); ++it)
      cout << *it << ", ";
    cout << endl;
}


void mergesort(vector<int>* arr)
{
  if(arr->size() > 1)
  {
    unsigned mid = ceil(arr->size() / 2);
    vector<int> leftHalf;
    vector<int> rightHalf;
    for(unsigned i = 0; i < mid; ++i)
      leftHalf.push_back(arr->at(i));
    for(unsigned i = mid; i < arr->size(); ++i)
      rightHalf.push_back(arr->at(i));
    cout << "\nsplitting " << endl;
    cout << "leftHalf: " << endl;
    for(vector<int>::iterator it = leftHalf.begin(); it != leftHalf.end(); ++it)
      cout << *it << ", ";
    
    cout << "\nrightHalf: " << endl;
    for(vector<int>::iterator it = rightHalf.begin(); it != rightHalf.end(); ++it)
      cout << *it << ", ";
    cout << endl;
    mergesort(&leftHalf);
    mergesort(&rightHalf);
    
    unsigned i = 0;
    unsigned j = 0;
    unsigned k = 0;
    
    while(i < leftHalf.size() && j < rightHalf.size())
    {
      if(leftHalf[i] < rightHalf[j])
      {
        arr->at(k) = leftHalf[i];
        ++i;
      }
      else
      {
        arr->at(k) = rightHalf[j];
        ++j;
      }
      ++k;
    }
    
    while(i < leftHalf.size())
    {
      arr->at(k) = leftHalf[i];
      ++i;
      ++k;
    }

    while(j < rightHalf.size())
    {
      arr->at(k) = rightHalf[j];
      ++j;
      ++k;
    }

    cout << " merging " << endl;
    for(vector<int>::iterator it = arr->begin(); it != arr->end(); ++it)
      cout << *it << ", ";
    cout << endl;
    
  }
}
