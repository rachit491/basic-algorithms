#include <iostream>

using namespace std;

int linearSearch(int arr[], int x) {
	int n = sizeof(arr)/sizeof(arr[0]);
	for(int i=0; i<n; i++) {
		if(x == arr[i]) {
			return i;
		}
	}
	return -1;
}

int main() {
	int i, n, pos;

	cout<<"Enter size of array: ";
	cin>>n;

	int arr[n];
	i=0;

	while(i<n) {
		cin>>arr[i];
		i++;
	}
	
	cout<<"Input number to be searched: ";
	cin>>i;

	pos = linearSearch(arr, i);

	if(pos == -1) {
		cout<<i<<" not found in array.";
	} else {
		cout<<i<<" found at "<<pos;
	}
	
	return 0;
}