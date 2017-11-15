#include <iostream>

using namespace std;

/**
 * Given a circular linked list, implement an algorithm which returns node at the beginning of the loop.
 * DEFINITION
 * Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an earlier node, so as to make a loop in the linked list.
 * EXAMPLE
 * input: A -> B -> C -> D -> E -> C [the same C as earlier]
 * output: C
 */

class Node {
public:
    int value;
    Node* next;
    Node(int value) {
        this->value = value;
        next = NULL;
    }
} *root;

Node* findLoop() {
    if(root == NULL) {
        return root;
    }

    Node *slow = root;
    Node *fast = root;
    Node *faster = root;

    while(slow && (fast = faster->next) && (faster = fast->next)) {
        if(slow == fast || slow == faster) {
            return slow;
        }
        slow = slow->next;
    }
    
    return NULL;
}