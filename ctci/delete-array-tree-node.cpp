#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int child;
	int parent;
};

void print(vector<TreeNode> v) {
    cout<<"List values\n";
    for(int i=0; i<v.size(); i++) {
	    cout<<v[i].child<<" : "<<v[i].parent<<endl;
	}
}

void deleteNode(vector<TreeNode> &v, int val) {
    //let's make parent of node to be deleted as -999
    //all its subsequent nodes follow the same rule
    bool found = false;
    vector<int> del_nodes;
    
    for(int i=0; i<v.size(); i++) {
        if(v[i].parent == val || v[i].child == val) {
            if(v[i].parent != v[i].child && v[i].child != val) {
                del_nodes.push_back(v[i].child);
            }
            v[i].parent = -999;
        }
    }
    
    if(del_nodes.size() > 0) {
        for(int i=0; i<del_nodes.size(); i++)
            deleteNode(v, del_nodes[i]);
    }
}

int main() {
	vector<TreeNode> v = {{0,0}, {1,0}, {2,0}, {5,1}, {3,3}, {4,3}, {6,4}};
	print(v);
	
	int del;
	
	cout<<"Enter Node to delete: ";
	cin>>del;
	
	deleteNode(v, del);
	print(v);
	
	return 0;
}