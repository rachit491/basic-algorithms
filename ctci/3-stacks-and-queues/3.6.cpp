#include <iostream>

using namespace std;

/**
 * Write a program to sort a stack in ascending order. 
 * You should not make any assumptions about how the stack is implemented. 
 * The following are the only functions that should be used to write this 
 * program: push | pop | peek | isEmpty.
 */

class Node {
public:
	int value;
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
		    top = tmp;
		    return;
		}
		tmp->next = top;
		top = tmp;
	}

	Node* pop() {
		Node *tmp = top;
		top = top->next;
		tmp->next = NULL;
		return tmp;
	}

	bool isEmpty() {
		return (top == NULL);
	}

	int peek() {
		return top->value;
	}

	void display() {
		Node *tmp = top;
		while(tmp) {
			cout<<tmp->value<<endl;
			tmp = tmp->next;
		}
	}
};

Stack sortStack(Stack st) {
	Stack result;
	while(!st.isEmpty()) {
		Node *tmp = st.pop();
		while(!result.isEmpty() && tmp->value > result.peek()) {
			st.push((result.pop())->value);
		}
		result.push(tmp->value);
	}
	return result;
}

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

	Stack res = sortStack(st);

	cout<<"\nSorted Stack is: \n\n";
	res.display();

	return 0;
}