#include <iostream>

using namespace std;

/**
 * Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
 * write a method to rotate the image by 90 degrees. Can you do this in place?
 */

int main() {
	int n, tmp;
	
	cout<<"Input n:";
	cin>>n;

    int arr[n][n];
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>arr[i][j];
        }
    }
    
    //rotating 90deg
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            tmp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = tmp;
        }
    }
    
    cout<<"\nResult 90deg rotation: \n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
	return 0;
}