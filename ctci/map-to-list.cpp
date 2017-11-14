#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * Convert a map to linked list,
 * considering that no nodes is repeated in the key or value part of the map,
 * and no map-pair is dangling
 */

struct node {
    int value;
    node *next;
    
    node(int value) {
        this->value = value;
        next = NULL;
    }
}*root;


void print() {
    node *tmp = root;
    while(tmp != NULL) {
        cout<<tmp->value<<"->";
        tmp = tmp->next;
    }
    cout<<endl;
}

void insert(node *p) {
    if(root == NULL) {
        root = p;
        //print();
        return;
    }
    
    node *tmp = root;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    
    tmp->next = p;
    
    //print();
}

void print(unordered_map<int, int> map) {
    for(auto it=map.begin(); it != map.end(); it++) {
        cout<<it->first<<":"<<it->second<<endl;
    }
}

int main() {
    unordered_map<int, int> map = {{1,2}, {3,4}, {2,3}, {4,6}, {6,5}};
    unordered_map<int, int> to;
    int start, end;
    node *tmp1, *tmp2;
    
    //O(n) - n is pair of nodes
    for(auto it=map.begin(); it != map.end(); it++) {
        to[it->second]++;
        to[it->first]--;
    }
    cout<<"Map: \n";
    print(map);
    //print(to);
    
    //O(m) - m is number of nodes
    for(auto it=to.begin(); it != to.end(); it++) {
        switch(it->second) {
            case 1: end = it->first; break;
            case -1: start = it->first; break;
        }
    }
    
    cout<<"\nStart: "<<start<<", End: "<<end<<"\n";
    
    auto i = map.find(start);
    //O(m2)
    while(i->second != end) {
        insert(new node(i->first));
        i = map.find(i->second);
    }
    
    insert(new node(i->first));
    insert(new node(i->second));
    
    cout<<"\nLinked List: \n";
    print();
    
    return 0;
}