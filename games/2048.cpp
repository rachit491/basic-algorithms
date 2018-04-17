#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;
enum Move { UP, DOWN, RIGHT, LEFT };

class Board {
    int n;
    vector<vector<int>> grid;
    
public:
    Board(int n) {
        this->n = n;
        grid.resize(n, vector<int>(n, 0));
    }
    
    void setupBoard() {
        int placed = 0;
        while(placed != 6) {
            srand(time(NULL));
            int random = rand() % (n*n);
            int x = (random / n);
            int y = (random % n);
            if(grid[x][y] == 0) {
                grid[x][y] = 2;
                srand(time(NULL));
                ++placed;
            }
        }
    }
    
    void set() {
        grid[0][0] = 2048;
    }
    
    void generateTwo() {
        while(true) {
            srand(time(NULL));
            int random = rand() % (n*n);
            int x = (random / n);
            int y = (random % n);
            if(grid[x][y] == 0) {
                grid[x][y] = 1024;
                srand(time(NULL));
                break;
            }
        }
    }
    
    bool checkWin() {
        vector<int> mx;
        for(int i=0; i<n; ++i) {
            auto res = max_element(grid[i].begin(), grid[i].end());
            mx.push_back(grid[i][distance(grid[i].begin(), res)]);
        }
        return (*max_element(mx.begin(), mx.end()) == 2048);
    }
    
    void removeSpace(Move dir) {
        switch(dir) {
            case UP :
                for(int k=0; k<n; ++k)
                    for(int i=n-1; i>0; --i) {
                        for(int j=0; j<n; ++j) {
                            if(grid[i-1][j] == 0) {
                                grid[i-1][j] = grid[i][j];
                                grid[i][j] = 0;
                            }
                        }
                    }
                break;
            case DOWN :
                for(int k=0; k<n; ++k)
                    for(int i=0; i<n-1; ++i) {
                        for(int j=0; j<n; ++j) {
                            if(grid[i+1][j] == 0) {
                                grid[i+1][j] = grid[i][j];
                                grid[i][j] = 0;
                            }
                        }
                    }
                break;
            case LEFT :
                for(int k=0; k<n; ++k)
                    for(int i=0; i<n; ++i) {
                        for(int j=n-1; j>0; --j) {
                            if(grid[i][j-1] == 0) {
                                grid[i][j-1] = grid[i][j];
                                grid[i][j] = 0;
                            }
                        }
                    }
                break;
            case RIGHT :
                for(int k=0; k<n; ++k)
                    for(int i=0; i<n; ++i) {
                        for(int j=0; j<n-1; ++j) {
                            if(grid[i][j+1] == 0) {
                                grid[i][j+1] = grid[i][j];
                                grid[i][j] = 0;
                            }
                        }
                    }
                break;
        }
    }
    
    void add(Move dir) {
        switch(dir) {
            case UP :
                for(int i=0; i<n-1; ++i) {
                    for(int j=0; j<n; ++j) {
                        if(grid[i][j] == grid[i+1][j]) {
                            grid[i][j] *= 2;
                            grid[i+1][j] = 0;
                        }
                    }
                }
                break;
            case DOWN :
                for(int i=n-1; i>0; --i) {
                    for(int j=0; j<n; ++j) {
                        if(grid[i][j] == grid[i-1][j]) {
                            grid[i][j] *= 2;
                            grid[i-1][j] = 0;
                        }
                    }
                }
                break;
            case RIGHT :
                for(int i=0; i<n; ++i) {
                    for(int j=n-1; j>0; --j) {
                        if(grid[i][j-1] == grid[i][j]) {
                            grid[i][j] *= 2;
                            grid[i][j-1] = 0;
                        }
                    }
                }
                break;
            case LEFT :
                for(int i=0; i<n; ++i) {
                    for(int j=0; j<n-1; ++j) {
                        if(grid[i][j+1] == grid[i][j]) {
                            grid[i][j] *= 2;
                            grid[i][j+1] = 0;
                        }
                    }
                }
                break;
        }
    }
    
    void move(Move dir) {
        removeSpace(dir);
        add(dir);
        removeSpace(dir);
        generateTwo();
    }
    
    void display() {
        cout<<"-----------------------------"<<endl;
        for(int i=0; i<n; ++i) {
            cout<<"| ";
            for(int j=0; j<n; ++j) {
                cout<<setw(4);
                if(grid[i][j])
                    cout<<grid[i][j]<< " | ";
                else 
                    cout<<"     | ";
            }
            cout<<endl;
            cout<<"-----------------------------"<<endl;
        }
    }
};

int main() {
    Board b(4);
    b.setupBoard();
    b.display();
    
    bool win = false;
    char in;
    
    while(!win) {
        cout<<"Input your move: ";
        cin>>in;
        switch(in) {
            case 'a': b.move(LEFT); break;
            case 's': b.move(DOWN); break;
            case 'd': b.move(RIGHT); break;
            case 'w': b.move(UP); break;
            case 'q': cout<<"Quiting!!"<<endl; return -1;
            default: 
                cout<<"Invalid key, use 's' to move down, 'a' to move left, 'd' to move right or 'w' to move up.."<<endl;
                break;
        }
        
        win = b.checkWin();
        b.display();
        if(win) {
            cout<<endl<<"YOU WIN!!"<<endl;
        }
    }
    
    return 0;
}