#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int i, n;
	vector<int> arr;

	cout<<"Enter n Value: ";
	cin>>n;

	while(n > 0) {
		cin>>i;
		arr.push_back(i);
		n--;
	}

	cout<<"Result: ";
	for(int i=0; i<arr.size(); i++) {
		cout<<arr[i]<<" ";
	}

    return 0;
}