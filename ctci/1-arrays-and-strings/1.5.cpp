#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Write a method to replace all spaces in a string with ‘%20’.
int main() {
	string str = "abcd efgh ijkl. Hello World.";
	string msg = "%20";
	
	for(int i=0; i<str.length(); i++) {
	    if(str[i] == ' ') {
	        str = str.substr(0, i) + msg + str.substr(i+1, str.length());
	    }
	}
	
	cout<<str;
	
	return 0;
}