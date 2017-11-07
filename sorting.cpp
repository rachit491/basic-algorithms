#include <iostream>
#include <vector>

using namespace std;

//bubble sort ascending
void bubbleSort(vector<int> &arr) {
    int i, j, n = arr.size();
    bool swapped;
    for(i=0; i<n-1; i++) {
        swapped = false;
        for(j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) {
            break;
        }
    }
}

//selection sort ascending
void selectionSort(vector<int> &arr) {
    int i, j;
    for(i=0; i<arr.size(); i++) {
        for(j=i+1; j<arr.size(); j++) {
            if(arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

//insertion sort
void insertionSort(vector<int> &arr) {
    int i, j, key;
    for(i=1; i<arr.size(); i++) {
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

//mergeSort
void merge(vector<int> &arr, int l, int mid, int r) {
    int i, j, k;
    vector<int> a, b;
    int n1 = mid - l + 1;
    int n2 = r - mid;

    for(i=0; i<n1; i++) {
        a.push_back(arr[l+i]);
    }

    for(i=0; i<n2; i++) {
        b.push_back(arr[mid+i+1]);
    }

    i=0;
    j=0;
    k=l;
    
    while(i < n1 && j < n2) {
        if(a[i] <= b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    while(i<n1) {
        arr[k] = a[i];
        i++;
        k++;
    }

    while(j<n2) {
        arr[k] = b[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int l, int r) {
    if (l < r) {
        int mid = l + (r-l)/2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);

        merge(arr, l, mid, r);
    }
}

//quick sort
int partition(vector<int> &arr, int p, int r) {
    int i = p-1;

    for(int j=p; j<r; j++) {
        if(arr[j] <= arr[r]) {              //Considering pivot as last element in array
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i+1], arr[r]);

    return (i+1);
}

void quickSort(vector<int> &arr, int p, int r) {
    if(p < r) {
        int q = partition(arr, p, r);

        quickSort(arr, p, q-1);
        quickSort(arr, q+1, r);
    }
}

int main() {
    int i, n;
    cout<<"Input number of inputs: ";
    cin>>n;
    
    vector<int> arr;
    
    while(n>0) {
        cin>>i;
        arr.push_back(i);
        n--;
    }
    
    //bubbleSort(arr);
    //selectionSort(arr);
    //insertionSort(arr);

    mergeSort(arr, 0, arr.size()-1);
    quickSort(arr, 0, arr.size()-1);
    
    cout<<"Sorted: ";
    for(i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
