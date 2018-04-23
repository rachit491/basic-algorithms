#include <iostream>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

void display(vector<vector<int>> data, int n) {
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cout<<setw(3);
            cout<<data[i][j]<<" ";
        }
        cout<<endl;
    }
}

void transpose(vector<vector<int>> &data, int n) {
    for(int i=0; i<n; ++i) {
        for(int j=i+1; j<n; ++j) {
            swap(data[i][j], data[j][i]);
        }
    }
}

int main() {
    int n = 4;
    vector<vector<int>> data = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    
    display(data, n);
    
    // transpose(data, n);
    // cout<<"\nTranspose: \n\n";
    // display(data, n);

    // for(int i=0; i<n; ++i) {
    //     for(int j=0; j<n/2; ++j) {
    //         swap(data[i][j], data[i][n-1-j]);
    //     }
    // }
    
    // cout<<"\nRotate +90: \n\n";
    // display(data, n);
    
    transpose(data, n);
    cout<<"\nTranspose: \n\n";
    display(data, n);
    
    for(int i=0; i<n/2; ++i) {
        for(int j=0; j<n; ++j) {
            swap(data[i][j], data[n-1-i][j]);
        }
    }
    
    cout<<"\nRotate -90: \n\n";
    display(data, n);
    
    return 0;
}