#include <iostream>
#include <vector>


using namespace std;

class Grid {
    int n = 3;
    vector<vector<int>> layout;
public:
    Grid() {
        layout.resize(n, vector<int>(n));
        for(int i=0; i<n; i++) {
            layout[i].resize(n, 2);
        }
    }
    
    int getSize() {
        return n;
    }
    
    bool isAvailable(int i, int j) {
        return (layout[i][j] == 0);
    }
    
    bool putValueAt(int i, int j, int value) {
        layout[i][j] = value;
        return checkCombo(i, j);
    }
    
    bool checkCombo(int x, int y) {
        bool rowWin = false;
        bool columnWin = false;
        bool diagonalWin = false;
        int i, r = 0, c = 0, dl = 0, dr = 0;
        
        int val = layout[x][y];
        
        for(i=0; i<n; i++) {
            if(layout[i][y] == val)
                r++;
            if(layout[x][i] == val)
                c++;
        }
        
        if(r == n)  rowWin = true;
        if(c == n)  columnWin = true;
        
        if(x == y || (x+y == n-1)) {
            for(i=0; i<n; i++) {
                if(layout[i][i] == val)
                    dl++;
                if(layout[i][n-i-1] == val)
                    dr++;
            }
        }
        
        if(dr == n || dl == n) diagonalWin = true;
        
        return (rowWin || columnWin || diagonalWin);
    }
    
    char getValue(int i, int j) {
        switch(layout[i][j]) {
            case 0: return ' ';
            case 1: return 'X';
            case 2: return 'O';
        }
    }
    
    void display() {
        char val;
        cout<<"    1   2   3  \n";
        cout<<"  ~~~~~~~~~~~~~\n";
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(j == 0) {
                    cout<<i+1<<" | ";
                }
                val = getValue(i, j);
                cout<<val<< " | ";
            }
            cout<<"\n  ~~~~~~~~~~~~~\n";
        }
    }
};

class Player {
    int id;
    char mark;
    int markValue;
    char type;
public:
    Player(int id, char m) {
        this->id = id;
        this->mark = m;
        this->type = 'p';
        switch(m) {
            case 'X' : markValue = 1; break;
            case 'O' : markValue = 2; break;
        }
    }
    
    char getMark() {
        return mark;
    }
    
    int putValuesAt(int i, int j, Grid &g) {
        int x = i-1;
        int y = j-1;
        if(g.isAvailable(x, y)) {
            if(g.putValueAt(x, y, markValue)) {
                switch(type) {
                    case 'p': cout<<"\nPLAYER "<<id<<" WINS!!\n"; break;
                    case 'c': cout<<"\nCOMPUTER WINS!!\n"; break;
                }
                g.display();
                //winner
                return 0;
            }
        } else {
            cout<<"Not a valid spot!\n";
            return -1;
        }
        g.display();
        return 1;
    }
};

class Computer : public Player {
    int id;
    char mark;
    int markValue;
public:    
    Computer(int id, char v) : Player(id, v) {
    }
    
    int chooseValue(Grid &g) {
        int x, y;
        x = (rand() % g.getSize());
        y = (rand() % g.getSize());
        while(!g.isAvailable(x, y)) {
            x = (rand() % g.getSize());
            y = (rand() % g.getSize());
        }
        cout<<"\nComputer placed O at "<<x<<" x "<<y<<"\n";
        return putValuesAt(x+1, y+1, g);
    }
};


int main() {
    int op, chance = 1;
    int r, c;
    bool loop = true;
    Grid g = Grid();
    cout<<"#### WELCOME TO TIC-TAC-TOE ####\n\n";
    g.display();
    cout<<"\n\n";
    while(true) {
        cout<<"1. Two player mode\n";
        cout<<"2. vs Computer\n";
        cout<<"Select option: ";
        cin>>op;
        if(op == 1) {
            Player p1 = Player(1, 'X');
            Player p2 = Player(2, 'O');
            cout<<"\n\n";
            cout<<"Player 1 marks X, Player 2 marks O\n";
            while(loop) {
                cout<<"\nPlayer "<<chance<<" enter position to place "<<p1.getMark()<<"\n";
                cout<<"Row: ";
                cin>>r;
                cout<<"Column: ";
                cin>>c;
                if(chance == 1) {
                    switch(p1.putValuesAt(r, c, g)) {
                        case 0: loop = false; break;
                        case 1: chance = 2; break;
                    }
                } else if(chance == 2) {
                    switch(p2.putValuesAt(r, c, g)) {
                        case 0: loop = false; break;
                        case 1: chance = 1; break;
                    }
                }
                else {
                    //invalid entry, same player's turn
                    loop = true;
                }
            }
            break;
        } else if(op == 2) {
            Player p = Player(1, 'X');
            Computer cp = Computer(2, 'O');
            cout<<"\n\n";
            cout<<"Player 1 marks X, Computer marks O\n";
            while(loop) {
                if(chance == 1) {
                    cout<<"\nPlayer 1 enter position to place "<<p.getMark()<<"\n";
                    cout<<"Row: ";
                    cin>>r;
                    cout<<"Column: ";
                    cin>>c;
                    switch(p.putValuesAt(r, c, g)) {
                        case 0: loop = false; break;
                        case 1: chance = 2; break;
                    }
                } else if(chance == 2) {
                    switch(cp.chooseValue(g)) {
                        case 0: loop = false; break;
                        case 1: chance = 1; break;
                    }
                }
                else {
                    //invalid entry, same player's turn
                    loop = true;
                }
            }
            break;
        } else {
            cout<<"Invalid option!\n\n";
        }
    }
    
    return 0;
}
