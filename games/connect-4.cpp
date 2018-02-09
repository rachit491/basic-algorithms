#include <iostream>
#include <vector>

using namespace std;

class Player {
	int pid;
	char sym;

public:
	Player(int pid, char sym) {
		this->pid = pid;
		this->sym = sym;
	}
	
	char getSymbol() {
	    return sym;
	}
	
	int getID() {
	    return pid;
	}
};

class Computer : public Player {
public:
    Computer(int pid, char sym) : Player(pid, sym) { }
    
    int getPosition(int limit) {
        return (rand() % limit) + 1;
    }
};

class Board {
	int n = 7;	//board dimensions
	vector<vector<char>> board;

public:
	Board() {
		board.resize(n, vector<char> (n, '-'));
	}

	int setPieceAt(int idx, Player p) {
        int r = n-1;
        int ret = -1;
        for(int i=r; i>=0; i--) {
            if(board[i][idx] == '-') {
                board[i][idx] = p.getSymbol();
                ret = 0;
                break;
            }
        }
        
        if(ret == 0)
            ret = ret || checkWin(p.getSymbol());
        
        return ret;
	}

	bool checkWin(char player) {
	    // horizontalCheck 
        for(int j=0; j<n-3 ; j++) {
            for(int i=0; i<n; i++) {
                if(board[i][j] == player && board[i][j+1] == player && board[i][j+2] == player && board[i][j+3] == player){
                    return true;
                }           
            }
        }
        
        // verticalCheck
        for(int i=0; i<n-3 ; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == player && board[i+1][j] == player && board[i+2][j] == player && board[i+3][j] == player) {
                    return true;
                }           
            }
        }
        
        // ascendingDiagonalCheck 
        for(int i=3; i<n; i++) {
            for(int j=0; j<n-3; j++) {
                if(board[i][j] == player && board[i-1][j+1] == player && board[i-2][j+2] == player && board[i-3][j+3] == player)
                    return true;
            }
        }
        
        // descendingDiagonalCheck
        for(int i=3; i<n; i++) {
            for(int j=3; j<n; j++) {
                if(board[i][j] == player && board[i-1][j-1] == player && board[i-2][j-2] == player && board[i-3][j-3] == player)
                    return true;
            }
        }
        
        return false;
	}

	void display() {
	    cout<<"\nThe Board is :\n\n";
		cout<<"  ";
		for(int i=0; i<n; i++) {
			cout<<i+1<<" ";
		}
		cout<<"\n";

		cout<<" ~";
		for(int i=0; i<n; i++) {
			cout<<"~~";
		}

		cout<<"\n";
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(j == 0)	cout<<"| ";
				cout<<board[i][j]<<" ";
				if(j == n-1)	cout<<"| ";
			}
			cout<<"\n";
		}

		cout<<" ~";
		for(int i=0; i<n; i++) {
			cout<<"~~";
		}
		cout<<"\n";
	}
};

int main() {
	int op, alt = 0, pos;
	Board b = Board();
	vector<Player> p;
	p.push_back(Player(1, '$'));
	
    cout<<"CONNECT 4\n\n";
    cout<<"1. 1 Player Mode\n2. 2 Player Mode\n";
    cout<<"Enter you choice: ";
    cin>>op;
	
	if(op == 1) {
	    p.push_back(Computer(2, '*'));
	}
    else if(op == 2) {
        p.push_back(Player(2, '@'));
        cout<<"\n";
        cout<<"Player 1 symbol will be \'"<<p[0].getSymbol()<<"\'\n";
        cout<<"Player 2 symbol will be \'"<<p[1].getSymbol()<<"\'\n";
    } else {
        cout<<"\nError in option!\n";
        return -1;
    }
    
	b.display();
	
	bool loop = true;
	
	while(loop) {
        cout<<"Player "<<(alt%2)+1<<", pick a position (1-7): ";
        if(op == 2)
            cin>>pos;
        else {
            pos = (Computer) p[alt%2].getPosition();
        }
        if(pos>0 && pos<8) {
            switch(b.setPieceAt(pos-1, p[alt%2])) {
                case 0:
                    alt++;
                    break;
                case 1:
                    loop = false;
                    cout<<"\n\nPLAYER "<<p[alt%2].getID()<<" WINS!!\n";
                    break;
                    
                case -1:
                    cout<<"\nInvalid position selected.. Try again!\n";
                    break;
            }
            
            b.display();
        }
	}
	
	return 0;
}