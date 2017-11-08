#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>

using namespace std;
class Node {
    public:
    	int val;
    	Node* left;
    	Node* right;
    
    	Node(int val) {
    		this->val = val;
    		this->left = NULL;
    		this->right = NULL;
    	}
};

void levelOrder(Node *root) {
    if(root == NULL)
        return;

    queue<Node *> q;
    Node *tmp;
    q.push(root);
    
    while(!q.empty()) {
        tmp = q.front();
        q.pop();
        
        cout<<tmp->val<<" ";
        
        if(tmp->left != NULL) {
            q.push(tmp->left);
        }
        
        if(tmp->right != NULL) {
            q.push(tmp->right);
        }
    }
}

int main() {
    /*
     * Considering tree as following:
     *              1
     *          2       3
     *      4      5,6      7
     *  8
     */

	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->left->left->left = new Node(8);
	
	cout<<"Preorder: \n";
	levelOrder(root);
	cout<<"\n";
	
    return 0;
}