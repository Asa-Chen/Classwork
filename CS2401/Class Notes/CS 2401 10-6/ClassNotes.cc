//Linked lists with class nodes cont.


LL_container::LL_container(const LL_container& other) { //copy constructor
    if (other.head == NULL) {
        head == NULL;
    } else {
        Node* src,dest;
        head = new Node(other.head -> data());
        //start src at the second node in the list
        src = other.head -> next();
        dest = head;

        while (src != NULL) {
            dest -> set_next(new Node(src -> data)));
            src = src -> next();
            dest = dest -> next();
        }
        }

    }
}


void LL_container::remove(const string& target) {
    if (head == NULL) return;
    Node* prev, cursor;
    cursor = head;
    if (head -> data() == target) { //special case if head is the target
    head = head -> next();
    delete cursor;
    } else {
        while (cursor != NULL && cursor -> data() != target) {
            prev = cursor;
             cursor = cursor -> next();
        }
        if (cursor != NULL) {
            prev -> set_next(cursor -> next());
            delete cursor;
        }
    }
}