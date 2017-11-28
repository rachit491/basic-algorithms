#include <iostream>

using namespace std;

int roundUp(int numToRound, int multiple) {  
    if(multiple == 0) {  
        return numToRound;  
    }  
    
    int remainder = numToRound % multiple; 
    if(remainder == 0) {
        return numToRound; 
    }
    
    return numToRound + multiple - remainder; 
}  

int main() {
    cout<<roundUp(35, 6);
    return 0;
}