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
} *l1, *l2;

void printList(Node* root) {
    Node *tmp = root;
    //cout<<"The list is: ";
    while(tmp) {
        cout<<tmp->value;
        tmp = tmp->next;
        if(tmp) {
            cout<<"->";
        }
    }
    cout<<endl;
}

Node* addLists(Node *a, Node *b) {
    Node *tmp;
    Node *result = NULL;
    int n, m;
    int sum = 0, ones = 0, tens = 0;
    
    tmp = a;
    while(tmp != NULL) {
        //length of list 1
        n++;
        tmp = tmp->next;
    }
    
    tmp = b;
    while(tmp != NULL) {
        //length of list 2
        m++;
        tmp = tmp->next;
    }
    
    tmp = NULL;
    while(m > 0 && n > 0) {
        sum = a->value + b->value + tens;
        ones = sum % 10;
        tens = sum / 10;
        Node *node = new Node(ones);
        if(result == NULL) {
            result = node;
        } else {
            tmp->next = node;
        }
        tmp = node;
        a = a->next;
        b = b->next;
        m--;
        n--;
    }
    
    while(n > 0) {
        sum = tens + a->value;
        ones = sum % 10;
        tens = sum / 10;
        Node *node = new Node(ones);
        if(result == NULL) {
            result = node;
        } else {
            tmp->next = node;
        }
        tmp = node;
        a = a->next;
        n--;
    }
    
    while(m > 0) {
        sum = tens + b->value;
        ones = sum % 10;
        tens = sum / 10;
        Node *node = new Node(ones);
        if(result == NULL) {
            result = node;
        } else {
            tmp->next = node;
        }
        tmp = node;
        b = b->next;
        m--;
    }
    
    if(tens > 0) {
        Node *node = new Node(tens);
        if(result == NULL) {
            result = node;
        } else {
            tmp->next = node;
        }
        tmp = node;
    }

        
    return result;
}

int main() {
    int i, n, input;
    Node *prev = NULL;
    
    cout<<"Input length of l1: ";
    cin>>n;
    
    for(i=0;i<n;i++) {
        cin>>input;
        Node *node = new Node(input);
        if(l1 == NULL) {
            l1 = node;
        }
        else {
            prev->next = node;
        }
        prev = node;
    }

    printList(l1);
    
    prev = NULL;
    cout<<"\nInput length of l2: ";
    cin>>n;
    
    for(i=0;i<n;i++) {
        cin>>input;
        Node *node = new Node(input);
        if(l2 == NULL) {
            l2 = node;
        }
        else {
            prev->next = node;
        }
        prev = node;
    }

    printList(l2);
    
    cout<<"\n\nSum:  ";
    printList(addLists(l1, l2));
    
    return 0;
}