#include <iostream>
#include <vector>
#include <ctype.h>

using namespace std;

class Field {
    int n, m, mines;
    vector<vector<pair<bool,int>>> field;

public:
    Field(int n, int m, int mines) {
        this->n = n;
        this->m = m;
        this->mines = mines;
        field.resize(n, vector<pair<bool,int>>(n));
        for(int i=0; i<n; i++) {
            field[i].resize(m, make_pair(false, 0));
        }
    }

    bool randomBool() {
        return rand() > (RAND_MAX / 2);
    }

    void setupMines() {
        int count = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(randomBool()) {
                    field[i][j].second = 9;
                    count++;
                } 
                if(count == mines) return;
            }
        }
    }

    void setupHints() {
        int value = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                value = 0;

                if(field[i][j].second == 9) continue;
                if(i!=0 && field[i-1][j].second == 9) value++;
                if(i!=0 && j!=0 && field[i-1][j-1].second == 9) value++;
                if(j!=0 && field[i][j-1].second == 9) value++;
                if(i!=0 && j!=n-1 && field[i-1][j+1].second == 9) value++;
                if(i!=n-1 && j!=0 && field[i+1][j-1].second == 9) value++;
                if(i!=n-1 && field[i+1][j].second == 9) value++;
                if(i!=n-1 && j!=m-1 && field[i+1][j+1].second == 9) value++;
                if(j!=m-1 && field[i][j+1].second == 9) value++;

                field[i][j].second = value;
            }
        }
    }

    bool showValue(int x, int y) {
        return field[x][y].first;
    }

    void displayField() {
        cout<<"    ";
        for(int i=0; i<m; i++)
            cout<<char(i+65)<<" ";
        cout<<"\n  ";
        for(int i=0; i<m; i++)
            cout<<"--";
        cout<<"---\n";
        for(int i=0; i<n; i++) {
            cout<<char(i+65)<<" | ";
            for(int j=0; j<m; j++) {
                if(showValue(i,j))
                    cout<<field[i][j].second<<" ";
                else 
                    cout<<"- ";
            }
            cout<<"|\n";
        }
        cout<<"  ";
        for(int i=0; i<m; i++)
            cout<<"--";
        cout<<"---\n";
    }

    void pop(int x, int y) {
        if(x>=n || y>=m) {
            cout<<"\nInvalid input!\n";
            return;
        }
        field[x][y].first = true;
    }
};


int main() {
    int n, m, mines, choice;
    cout<<"1. Easy (9x9, 10mines)\n";
    cout<<"2. Medium (15x15, 40mines)\n";
    cout<<"3. Hard (15x26, 90mines)\n\n";
    cout<<"Enter Level: ";
    cin>>choice;

    switch(choice) {
        case 1: n=m=9; mines=10; break;
        case 2: n=15; m=15; mines=40; break;
        case 3: n=15; m=26; mines=90; break;
        default: cout<<"\nStarting Easy Level\n"; n=m=9; break;
    }
    
    Field f = Field(n, m, mines);
    
    f.setupMines();
    
    f.setupHints();
    
    f.displayField();
    
    string input;
    bool loop = true;
    int x, y;
    while(loop) {
        cout<<"Enter Co-ordinates (row x column.. eg. AC): ";
        cin>>input;
        x = int(toupper(input[0]))-65;
        y = int(toupper(input[1]))-65;
        cout<<x<<"-"<<y<<"\n";
        f.pop(x, y);
        f.displayField();
    }
    
    return 0;
}