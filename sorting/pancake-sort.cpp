#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void flip(vector<int> &arr, int k) {
  int i = 0, tmp;
  int pivot = floor((k+1)/ 2);
  for(; i<pivot; ++i) {
    tmp = arr[i];
    arr[i] = arr[k - i];
    arr[k - i] = tmp;
  }
}

int findMax(vector<int> arr, int n) {
  int mx = 0;
  for(int i=0; i<=n; ++i) {
    if(arr[i] > arr[mx])
      mx = i;
  }
  return mx;
}

vector<int> pancakeSort( const vector<int>& arr ) {
  vector<int> ar = arr;
  int mx;
  
  for(int i=arr.size()-1; i>=1; --i) {
    mx = findMax(ar, i);
    flip(ar, mx);
    flip(ar, i);
  }
  
  return ar;
}

int main() {
  return 0;
}