#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int p, int r) {
    int i = p-1;

    for(int j=p; j<r; j++) {
        if(arr[j] <= arr[r]) {              //Considering pivot as last element in array
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    i++;
    swap(arr[i], arr[r]);

    return i;
}

int findKSmallest(vector<int> &arr, int k, int l, int r) {
	if(k > 0 && k <= r-l+1) {
		int pos = partition(arr, l, r);
        cout<<pos<<":"<<l<<":"<<r<<endl;
		if(pos-l == k-1) {
			return arr[k-1];
		} else if (pos-l > k-1) {
			return findKSmallest(arr, k, l, pos-1);
		} else {
			return findKSmallest(arr, k-pos+l+1, pos+1, r);
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