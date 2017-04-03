/*
 * There are two sorted arrays A and B of size m and n respectively. 
 * Find the median of the two sorted arrays. 
 * The overall run time complexity should be O(log (m+n)).
 * 
 */
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

double findMedianSortedArrays(int A[], int m, int B[], int n) {
  int i = 0;
  int j = 0;
  int k = 0;
  int C[m + n];
  sort(A, A + m);
  sort(B, B + n);
  while(i < m && j < n){
    if(A[i] < B[j]){
      C[k] = A[i];
      ++i;
    }
    else{
      C[k] = B[j];
      ++j;
    }
    ++k;
  }
  
  while(i < m){
    C[k] = A[i];
    ++i;
    ++k;
  }
  
  while(j < n){
    C[k] = B[j];
    ++j;
    ++k;
  }
  if (m + n == 2) return (C[0] + C[1]) / 2.0;
  else if(m + n == 1) return C[0];
  else if((m + n) % 2 != 0) return C[(m + n) / 2];
  else return (C[((m + n) / 2)] + C[((m + n) / 2) - 1]) / 2.0;
 
}
int main(){
  int A[4] = {3,4,6,2};
  int m = 4;
  int B[5] = {54,76,32,86,25};
  int n = 5;
  int D[9] = {3,4,6,2,54,76,32,86,25};
  sort(D, D + 9);
  double result = 0;
  result = findMedianSortedArrays(A, m, B, n);
  cout << D[4] << " " << result << endl;
  
}