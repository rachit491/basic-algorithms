#include <iostream>
#include <vector>

using namespace std;

/**
 * Imagine a (literal) stack of plates. If the stack gets too high, it might topple. 
 * Therefore, in real life, we would likely start a new stack when the previous stack 
 * exceeds some threshold. Implement a data structure SetOfStacks that mimics this. 
 * SetOfStacks should be composed of several stacks, and should create a new stack 
 * once the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() 
 * should behave identically to a single stack (that is, pop() should return the 
 * same values as it would if there were just a single stack).
 *
 * FOLLOW UP
 * Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.
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
	Node *top;
	int capacity;
	int count;
public:
	Stack() {
		top = NULL;
		count = 0;
	}

	void push(int value) {
		Node *tmp = new Node(value);
		count++;
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
		count--;
		return tmp;
	}

	bool isEmpty() {
		return (top == NULL);
	}

	bool isFull() {
		return (capacity == count);
	}

	int peek() {
		return top->value;
	}

	void setCapacity(int capacity) {
		this->capacity = capacity;
	}

	void display() {
		Node *tmp = top;
		while(tmp) {
			cout<<tmp->value<<endl;
			tmp = tmp->next;
		}
	}
};

class SetOfStacks {
	vector<Stack> s;
	int capacity;
public:
	SetOfStacks(int capacity) {
		this->capacity = capacity;
	}

	void push(int value) {
		int top = s.size()-1;
		if(top < 0 || s[top].isFull()) {
			Stack st;
			s.push_back(st);
			top = s.size()-1;
			s[top].setCapacity(capacity);
		}
		s[top].push(value);
	}

	Node* pop() {
		int top = s.size()-1;
		Node *tmp = s[top].pop();
		if(s[top].isEmpty()) {
			s.erase(s.end()-1);
		}
		return tmp;
	}

	Node* popAt(int stackIndex) {
		//can have a rollover feature, which might not be a good thing for stack
		int top = s.size()-1;
		if(stackIndex-1 >=0 && stackIndex-1 <= top) {
			return s[stackIndex-1].pop();
		}
		return NULL;
	}

	void display() {
	    
	    cout<<"\n\n________________\nLIST \n\n";
		for(int i=0; i<s.size(); i++) {
			cout<<"Stack No. "<<i+1<<"\n";
			s[i].display();
			cout<<"\n\n";
		}
	}
};

int main() {
	int capacity;
	cout<<"Enter threshold value for each pile of plates: ";
	cin>>capacity;

	SetOfStacks ss(capacity);

	ss.push(10);
	ss.push(100);
	ss.push(1000);
	ss.push(405);
	ss.display();
	ss.push(135);
	ss.display();
	ss.pop();
	ss.display();
	ss.push(8342);
	ss.push(10000);
	ss.push(6000);

	ss.display();
	
	ss.pop();
	ss.pop();
	ss.popAt(1);
	ss.pop();
	
	ss.display();
	
	ss.push(832);
	ss.push(65000);
	ss.push(6005);
	ss.push(2);
	
	ss.display();
	
	return 0;
}