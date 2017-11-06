#include <iostream>
#include <vector>

using namespace std;

//bubble sort ascending
void bubbleSort(vector<int> &arr) {
    int i, j;
    for(i=0; i<arr.size(); i++) {
        for(j=0; j<arr.size(); j++) {
            if(arr[i] < arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
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
    
    cout<<"Sorted: ";
    for(i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
