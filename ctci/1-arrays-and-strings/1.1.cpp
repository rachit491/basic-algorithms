#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Implement an algorithm to determine if a string has all unique characters.
 */
int main() {
	string str = "abcdefghijkl";
	bool arr[256];
	
	for(int i=0; i<256; i++) {
	    arr[i] = false;
	}
	
	for(int i=0; i<str.length(); i++) {
	    int x = (int)str[i];
	    
	    if(arr[x]) {
	        cout<<"false";
	        return 0;
	    }
	    
	    arr[x] = true;
	}
	
	cout<<"true";
	
	return 0;
}