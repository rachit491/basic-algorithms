#include <iostream>
#include <vector>

using namespace std;

/**
 * Write an algorithm such that if an element in an MxN matrix is 0, its entire row and 
 * column is set to 0.
 * 1 2 3 4 5
 * 6 0 8 9 0
 * 2 3 7 8 9
 * 1 2 3 8 7
 */

int main() {
	int m, n, tmp;
	
	cout<<"Input rows(m), columns(n):";
	cin>>m>>n;

    int arr[m][n];
    vector<int> rows, columns; 
    
    //O(mn)
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>arr[i][j];
            if(arr[i][j] == 0) {
                rows.push_back(i);
                columns.push_back(j);
            }
        }
    }
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<columns.size(); j++) {
            arr[i][columns[j]] = 0;
        }
    }
    
    for(int i=0; i<rows.size(); i++) {
        for(int j=0; j<n; j++) {
            arr[rows[i]][j] = 0;
        }
    }
    
    cout<<"\nNew matrix: \n";
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
	return 0;
}