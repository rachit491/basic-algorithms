#include <iostream>
#include <vector>
#include <string>

using namespace std;

size_t split(const string &txt, vector<string> &strs, char ch) {
  size_t pos = txt.find(ch);
  size_t initialPos = 0;
  strs.clear();

  // Decompose statement
  while(pos != string::npos) {
    strs.push_back(txt.substr(initialPos, pos - initialPos));
    initialPos = pos + 1;

    pos = txt.find(ch, initialPos);
  }

  // Add the last one
  strs.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));

  return strs.size();
}

int main() {
  vector<string> v;
  
  string str = "Here is a Dummy string with integer 23 56 90";
  split(str, v, ' ');
  
  for(int i=0; i<v.size(); ++i) {
    cout<<v[i]<<endl;
  }
  
  return 0;
}
