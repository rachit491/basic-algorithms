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

void printList(Node* head) {
    Node *tmp = head;
    cout<<"The list is: ";
    while(tmp) {
        cout<<tmp->value<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}

int findMidList() {
    Node* tmp1 = root;
    Node* tmp2 = root;
    Node* prev;
    while(tmp2 && tmp2->next != NULL) {
        prev = tmp1;
        tmp1 = tmp1->next;
        tmp2 = tmp2->next->next;
    }
    
    /*
    In case of even length of linked list, we have two middle values,
    so we either choose left value or right value or average of both 
    (Median if values were sorted already). It's good to keep a prev 
    Node pointer for that.
    */
    //return prev->value;
    return tmp1->value;
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
    
    cout << "Middle Value in list: " << findMidList();

    return 0;
}
