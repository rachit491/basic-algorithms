#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//Write a method to decide if two strings are anagrams or not
int main() {
	string str1 = "polo";
	string str2 = "loop";
	
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	
	if(str1 == str2) {
	    cout<<"true";
	} else {
	    cout<<"false";
	}
	
	return 0;
}