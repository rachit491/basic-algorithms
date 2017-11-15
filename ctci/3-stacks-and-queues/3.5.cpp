#include <iostream>

using namespace std;

//Implement a MyQueue class which implements a queue using two stacks.
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

	void display() {
		Node *tmp = top;
		while(tmp) {
			cout<<tmp->value<<endl;
			tmp = tmp->next;
		}
	}
};

class MyQueue {
	Stack s1, s2;
public:
	void add(int value) {
		s1.push(value);
	}

	Node* remove() {
		if(!s2.isEmpty()) 
			return s2.pop();

		while(!s1.isEmpty()) {
			s2.push((s1.pop())->value);
		}
		
		return s2.pop();
	}

	void display() {
	    if(s2.isEmpty()) {
	        while(!s1.isEmpty()) {
    			s2.push((s1.pop())->value);
    		}
	    }
		s2.display();
		s1.display();
	}
};

int main() {
	int n, input;
	MyQueue q;

	cout<<"Input size of the Queue: ";
	cin>>n;

	cout<<"Enter values: \n";
	for(int i=0; i<n; i++) {
		cin>>input;
		q.add(input);
	}

	cout<<"\nQueue is: \n\n";
	q.display();

	cout<<"Removed Element: "<<(q.remove())->value<<endl;
	cout<<"\nQueue is: \n\n";
	q.display();
	
	return 0;
}