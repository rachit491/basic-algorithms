//Implement an algorithm to find the nth to last element of a singly linked list.

node* nthToLast(int n) {
    //root be the start of the list
    node *tmp = root;
    node *nth = NULL;
    int counter = 1;
    
    while(tmp != NULL) {
        tmp = tmp->next;
        counter++;
        if(n == counter) {
            nth = root;
        } else if (counter > n) {
            nth = nth->next;
        }
    }
    
    return nth;
}