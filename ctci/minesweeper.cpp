#include <iostream>
#include <vector>

using namespace std;

bool randomBool() {
   return rand() > (RAND_MAX / 2);
}

void setupMines(vector<vector<int>> &field, int mines) {
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
    int n, m, mines, choice;
    cout<<"1. Easy (9x9, 10mines)\n2. Medium (16x15, 40mines)\n3. Hard (16x30, 99mines)\n\n";
    cout<<"Enter Level: ";
    cin>>choice;

    switch(choice) {
        case 1: n=m=9; mines=10; break;
        case 2: n=16; m=15; mines=40; break;
        case 3: n=16; m=30; mines=99; break;
        default: cout<<"\nStarting Easy Level\n"; n=m=9; break;
    }
    
    vector<vector<int>> field;
    field.resize(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        field[i].resize(m, 0);
    }
    
    setupMines(field, mines);
    
    setupHints(field);
    
    displayField(field);
    
    return 0;
}