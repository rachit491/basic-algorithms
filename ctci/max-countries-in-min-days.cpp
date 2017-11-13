#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int funct(vector<int> v) {
    if(v.size() == 0)
        return 0;
    
    unordered_map<int, int> freq;
    
    int end, start = 0, i;
    int count = 0;
    for(i=0; i<v.size(); i++) {
        freq[v[i]] = 1;
    }
    
    for(i=0; i<v.size(); i++) {
        freq[v[i]]--;
        if(v[start] == v[i] && i!=0) {
            start++;
        }
        if(freq[v[i]] == 0) {
            count++;
            if(count == freq.size()) {
                end = i;
                break;
            }
        }
    }
    
    cout<<start<<"\n";
    cout<<end<<"\n";
    
    return end-start+1;
}

int main()
{
    vector<int> v = { 6, 5, 1, 2, 3, 2, 1, 4, 5 };
    //vector<int> v = { 7,3,7,3,1,3,4,1 };
    //vector<int> v = {1,2,1,2,3,2,1,2};
    cout << funct(v);
    return 0;
}