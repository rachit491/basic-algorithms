#include <iostream>
#include <vector>

using namespace std;

bool randomBool() {
   return rand() > (RAND_MAX / 2);
}

void setupMines(vector<vector<int>> &field, int size) {
    int mines = 10;
    int count = 0;
    for(int i=0; i<field.size(); i++) {
        for(int j=0; j<field[i].size(); j++) {
            if(randomBool()) {
                field[i][j] = 9;
                count++;
            } 
            if(count == mines) return;
        }
    }
}

void setupHints(vector<vector<int>> &field) {
    int value = 0;
    int m;
    int n = field.size();
    for(int i=0; i<n; i++) {
        m = field[i].size();
        for(int j=0; j<m; j++) {
            value = 0;
            if(field[i][j] == 9) continue;
            if(i!=0 && field[i-1][j] == 9) value++;
            if(i!=0 && j!=0 && field[i-1][j-1] == 9) value++;
            if(j!=0 && field[i][j-1] == 9) value++;
            if(i!=0 && j!=n-1 && field[i-1][j+1] == 9) value++;
            if(i!=n-1 && j!=0 && field[i+1][j-1] == 9) value++;
            if(i!=n-1 && field[i+1][j] == 9) value++;
            if(i!=n-1 && j!=m-1 && field[i+1][j+1] == 9) value++;
            if(j!=m-1 && field[i][j+1] == 9) value++;
            field[i][j] = value;
        }
    }
}

void displayField(vector<vector<int>> field) {
    for(int i=0; i<field[0].size(); i++)
        cout<<"--";
    cout<<"---\n";
    for(int i=0; i<field.size(); i++) {
        cout<<"| ";
        for(int j=0; j<field[i].size(); j++) {
            cout<<field[i][j]<<" ";
        }
        cout<<"|\n";
    }
    for(int i=0; i<field[0].size(); i++)
        cout<<"--";
    cout<<"---\n";
}

int main() {
    int n, m;
    cout<<"Enter rows x columns : ";
    cin>>n>>m;
    n=m=9;
    
    vector<vector<int>> field;
    field.resize(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        field[i].resize(m, 0);
    }
    
    setupMines(field, n*m);
    
    setupHints(field);
    
    displayField(field);
    
    return 0;
}