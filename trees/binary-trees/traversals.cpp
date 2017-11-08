#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

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

void preorder(Node *root) {
    if(root == NULL)
        return;

    cout<<root->val<<" ";
    
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root) {
    if(root == NULL)
        return;

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void postorder(Node *root) {
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    
    cout<<root->val<<" ";
}

int main() {
    /*
     * Considering tree as following:
     *              1
     *          2       3
     *      4      5,6
     *  8
     */

	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->left->left->left = new Node(8);
	
	cout<<"Preorder: \n";
	preorder(root);
	cout<<"\n\n";
	
	cout<<"Inorder: \n";
	inorder(root);
	cout<<"\n\n";
	
	cout<<"Postorder: \n";
	postorder(root);
    cout<<"\n\n";
    
    return 0;
}