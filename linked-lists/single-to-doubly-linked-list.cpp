#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int value) {
        this->value = value;
        next = NULL;
    }
} *root;

class NodeD {
public:
    int value;
    NodeD* next;
    NodeD* prev;
    NodeD(int value) {
        this->value = value;
        next = NULL;
        prev = NULL;
    }
} *rootD;

/*
In singly linked list, the core node usually contains a pointer that points to the next node, and an element.

struct node {
  int x;
  struct node *next;
};

In order to convert it to doubly linked list, you have to first add to the node the feature to point to previous node as well.

struct node {
  int x;
  struct node *next;
  struct node *prev;
};

After doing that, you can march from the head, and doing something like:

while(node->next) { // stop when you meet the null node
   node->next->prev = node; // link back the current and next nodes
   node = node->next;       // march to the next node and do the same
} 
*/

void printList(Node* head) {
    Node *tmp = head;
    cout<<"The list is: ";
    while(tmp) {
        cout<<tmp->value<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}

void printDList(NodeD* head) {
    NodeD *tmp = head;
    cout<<"The doubly list is: ";
    while(tmp) {
        cout<<tmp->value<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}

void doublyLinkedList() {
    Node* tmp = root;
    NodeD* tmpD;
    while(tmp) {
        NodeD* node = new NodeD(tmp->value);
        if(rootD == NULL) {
            rootD = node;
        } else {
            tmpD->next = node;
            node->prev = tmpD;
        }
        tmpD = node;
        tmp = tmp->next;
    }
}

int main() {
    int i, n, input;
    Node *prev;
    cout<<"Input n: ";
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>input;
        Node *node = new Node(input);
        if(root == NULL) {
            root = node;
        }
        else {
            prev->next = node;
        }
        prev = node;
    }

    printList(root);
    
    doublyLinkedList();     //makeDoublyLL
    
    printDList(rootD);

    return 0;
}