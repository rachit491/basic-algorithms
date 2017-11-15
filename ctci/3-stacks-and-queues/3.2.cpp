#include <iostream>

using namespace std;

/**
 * How would you design a stack which, in addition to push and pop, 
 * also has a function min which returns the minimum element? 
 * Push, pop and min should all operate in O(1) time.
 */

class Node {
public:
	int value;
	int min;
	Node *next;
	Node(int value) {
		this->value = value;
		next = NULL;
	}
};

class Stack {
	Node *top = NULL;
public:
	void push(int value) {
		Node *tmp = new Node(value);
		if(top == NULL) {
		    tmp->min = value;
		    top = tmp;
		    return;
		}
		tmp->min = min(value, top->min);
		tmp->next = top;
		top = tmp;
	}

	Node* pop() {
		Node *tmp = top;
		top = top->next;
		tmp->next = NULL;
		return tmp;
	}

	void display() {
		Node *tmp = top;
		while(tmp) {
			cout<<tmp->value<<endl;
			tmp = tmp->next;
		}
	}
	
	int getMin() {
		return top->min;
	}
};

int main() {
	int n, input;
	Stack st;
	cout<<"Input size of the Stack: ";
	cin>>n;
	cout<<"Enter values: \n";
	for(int i=0; i<n; i++) {
		cin>>input;
		st.push(input);
	}
	cout<<"\nStack is: \n\n";
	st.display();
	cout<<"\nMinimum value in stack: "<<st.getMin()<<endl;
	//Node *node = st.pop();
	//cout<<node->value<<" Popped!\n";
	//node = st.pop();
	//cout<<node->value<<" Popped!\n";
	//cout<<"\nMinimum value in stack: "<<st.getMin()<<endl;
	return 0;
}