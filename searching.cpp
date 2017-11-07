#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int linearSearch(vector<int> arr, int x) {
	int n = arr.size();
	for(int i=0; i<n; i++) {
		if(x == arr[i]) {
			return i;
		}
	}
	return -1;
}

int binarySearch(vector<int> arr, int x) {
	//sort first
	sort(arr.begin(), arr.end());
	int n = arr.size();
	int l = 0;
	int r = n-1;

	while(l <= r) {
		int mid = l + (r-l)/2;

		if(arr[mid] == x) {
			return mid;
		}

		if(arr[mid] > x) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	
	return -1;
}

int main() {
	int i, n;

	cout<<"Enter size of array: ";
	cin>>n;

	vector<int> arr;
	i=0;

	while(n > 0) {
		cin>>i;
		arr.push_back(i);
		n--;
	}
	
	cout<<"Input number to be searched: ";
	cin>>i;

	//pos = linearSearch(arr, i);
	n = binarySearch(arr, i);

	if(n == -1) {
		cout<<i<<" not found in array.";
	} else {
		cout<<i<<" found at "<<n;
	}
	
	return 0;
}