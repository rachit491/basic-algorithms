#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &nums, int left, int right) {
    int pivot = nums[left];
    int l = left + 1, r = right;
    while (l <= r) {
        if(nums[l] > pivot && nums[r] < pivot)
            swap(nums[l++], nums[r--]);
        if(nums[l] <= pivot) l++; 
        if(nums[r] >= pivot) r--;
    }
    swap(nums[left], nums[r]);
    return r;
}

int findKSmallest(vector<int> &arr, int k, int l, int r) {
	if(k > 0 && k <= r-l+1) {
		int pos = partition(arr, l, r);
        cout<<pos<<":"<< l<<":"<<r<<endl;
		if(pos == k-1) {
			return arr[pos];
		} else if (pos > k-1) {
			return findKSmallest(arr, k, l, --r);
		} else {
			return findKSmallest(arr, k, ++l, r);
		}
	}
}

int main() {
	vector<int> arr;
	int n, i;

	cout<<"Enter n value: ";
	cin>>n;

	cout<<"Input array: \n";
	while(n>0) {
		cin>>i;
		arr.push_back(i);
		n--;
	}

	cout<<"What smallest element you want? ";
	cin>>n;
	
	i = findKSmallest(arr, n, 0, arr.size()-1);

	cout<<n<<"-smallest element in array is: "<<i;

	return 0;
}