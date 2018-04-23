#include <iostream>
#include <vector>

using namespace std;

class Position {
public:
    int x, y;
    Position(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

class Player {
    int id;
    bool isHuman;
public:
    Player(int id, bool isHuman) {
        this->id = id;
        this->isHuman = isHuman;
        cout<<endl<<"Player "<<id<<" using "<<id<<" as its symbol"<<endl;
    }
    
    int getID() {
        return id;
    }
    
    Position getRandomPosition() {
        if(!isHuman) {
            
        }
    }
};

class Board {
    int n;
    int ones, twos;
    vector<vector<int>> grid;
    vector<vector<int>> dir = {{1,1}, {0,1}, {0,-1}, {-1,-1}, {1,-1}, {-1,1}, {1,0}, {-1,0}};
    
public:
    Board(int n = 8) {
        this->n = n;
        ones = 0;
        twos = 0;
        grid.resize(n, vector<int> (n, -1));
    }
    
    void reset() {
        int center = n/2;
        grid[center][center] = 1;
        grid[center-1][center-1] = 1;
        ones = 2;
        grid[center][center-1] = 2;
        grid[center-1][center] = 2;
        twos = 2;
    }
    
    bool checkWin() {
        if(ones == 0 || twos == 0 || ones+twos == n*n)
            return true;
        return false;
    }
    
    vector<int> count() {
        return {max(ones, twos), min(ones, twos)};
    }
    
    bool checkBoundaries(int x, int y) {
        return (x>=0 && y>=0 && y<n && x<n);
    }
    
    bool validMove(Position p, int val) {
        int count = 0, x, y;
        vector<vector<int>> currDir;
        
        if(grid[p.x][p.y] != -1) {
            return false;
        }
        
        for(int i=0; i<dir.size(); ++i) {
            x = p.x + dir[i][0];
            y = p.y + dir[i][1];
            count = 0;
            while(checkBoundaries(x,y)) {
                if(grid[x][y] != -1 && grid[x][y] != val) {
                    ++count;
                }
                
                if(grid[x][y] == -1) {
                    count = 0;
                    break;
                }
                
                if(grid[x][y] == val && count > 0) {
                    currDir.push_back(dir[i]);
                    count = 0;
                    break;
                }
                x += dir[i][0];
                y += dir[i][1];
            }
        }
        
        if(currDir.size() == 0)
            return false;
        
        flip(p, currDir, val);
        return true;
    }
    
    void flip(Position p, vector<vector<int>> currDir, int val) {
        int x, y;
        //set the value
        grid[p.x][p.y] = val;
        val == 1 ? ++ones : ++twos;
        
        for(int i=0; i<currDir.size(); ++i) {
            x = p.x + currDir[i][0];
            y = p.y + currDir[i][1];
            while(checkBoundaries(x,y)) {
                if(grid[x][y] == -1 || grid[x][y] == val) {
                    //stop
                    break;
                } else {
                    grid[x][y] = (val == 1) ? 1 : 2;
                    grid[x][y] == 1 ? ++ones : ++twos;
                }
                x += currDir[i][0];
                y += currDir[i][1];
            }
        }
    }
    
    void display() {
        cout<<endl;
        for(int i=0; i<n; ++i) {
            cout<<"  "<<i+1<<" ";
        }
        cout<<endl<<"---------------------------------"<<endl;
        for(int i=0; i<n; ++i) {
            cout<<"| ";
            for(int j=0; j<n; ++j) {
                if(grid[i][j] > -1)
                    cout<<grid[i][j]<< " | ";
                else 
                    cout<<"  | ";
            }
            cout<<i+1<<endl;
            cout<<"---------------------------------"<<endl;
        }
    }
    
};


int main() {
    bool win = false;
    int row, col, curr, chance = 0;
    vector<int> result;
    
    Board b(8);
    b.reset();
    b.display();
    
    vector<Player> p;
    p.push_back(Player(1, false));
    p.push_back(Player(2, false));
    
    while(!win) {
        curr = chance%2;
        cout<<endl<<"Player "<<curr+1<<", Input row, column: ";
        cin>>row>>col;
        if(b.validMove(Position(row-1, col-1), p[curr].getID())) {
            ++chance;
        } else {
            cout<<endl<<"Invalid Move, Try Again!!"<<endl;
            continue;
        }
        b.display();
        win = b.checkWin();
        if(win) {
            cout<<endl<<"Player "<<curr+1<<" wins!!"<<endl;
            result = b.count();
            cout<<endl<<"Player "<<curr+1<<": "<<result[0]<<endl;
            cout<<endl<<"Player "<<curr<<": "<<result[1]<<endl;
            break;
        }
    }
    
    return 0;
}