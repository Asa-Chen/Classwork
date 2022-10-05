//A linked list search function
node* search(node* head, int target) {
    //base case
    if (head == NULL) {
        return NULL;
    }
    else if (head -> data() == target) {
        return head;
    } else {
        return search(head -> next(), target);
    }
}

//random stuff. in book
void random_fractal(double lht, double rht, double width, double epsilon) {
    if (width < epsilon) {
        display(rht); //Appendix I

    }
}