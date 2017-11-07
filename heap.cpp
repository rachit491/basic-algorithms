#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

void minHeapify(vector<int> &arr, int n, int i) {
	int smallest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if(l<n && arr[l] < arr[smallest]) {
		smallest = l;
	}

	if(r<n && arr[r] < arr[smallest]) {
		smallest = r;
	}

	if(smallest != i) {
		swap(arr[i], arr[smallest]);
		minHeapify(arr, n, smallest);
	}
}

void maxHeapify(vector<int> &arr, int n, int i) {
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if(l<n && arr[l] > arr[largest]) {
		largest = l;
	}

	if(r<n && arr[r] > arr[largest]) {
		largest = r;
	}

	if(largest != i) {
		swap(arr[i], arr[largest]);
		maxHeapify(arr, n, largest);
	}
}

void buildHeap(vector<int> &arr, int n, bool isMin) {
	for(int i=(n/2)-1; i>=0; i--) {
		if(!isMin)
			maxHeapify(arr, n, i);
		else 
			minHeapify(arr, n, i);
	}
}

void heapSort(vector<int> &arr, int n) {
	buildHeap(arr, n, false);

	for(int i=n-1; i>=0; i--) {
		swap(arr[0], arr[i]);
		maxHeapify(arr, i, 0);
	}
}

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

	heapSort(arr, arr.size());

	cout<<"Result: ";
	for(int i=0; i<arr.size(); i++) {
		cout<<arr[i]<<" ";
	}

    return 0;
}