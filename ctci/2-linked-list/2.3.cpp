/**
 * Implement an algorithm to delete a node in the middle of a single linked list, given only 
 * access to that node.
 */
 
void deleteNode(node *del) {
    //root is not given
    if(del == NULL) {
        return;
    } else if(del->next == NULL) {
        delete(del);
        return;
    }
    
    node *tmp = del->next;
    del->data = tmp->data;
    del->next = tmp->next;
    delete(tmp);
}