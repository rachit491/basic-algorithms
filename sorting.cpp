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
    
    bubbleSort(arr);
    selectionSort(arr);
    insertionSort(arr);
    
    cout<<"Sorted: ";
    for(i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
