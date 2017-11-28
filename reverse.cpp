#include <iostream>
#include <string>
using namespace std;

void reverse(string &str) {
    char tmp;
    for(int i=0, j=str.length()-1; i<j; i++, j--) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}

int main() {
    
    string str = "Rachit Shrivastava";
    reverse(str);
    cout<<"\n"<<str<<"\n";
    
    return 0;
}