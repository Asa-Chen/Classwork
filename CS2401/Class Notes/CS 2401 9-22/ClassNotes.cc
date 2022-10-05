//Removing items from a linked list


void remove(Node*& head, const string& target) {
    if (head == NULL) {
        return;
    }
    
    if (head -> data == target) {
        //delete head; //This is really bad! you just deallocated the address to your entire list
        
        //rm points at what I want to get rid of
        Node* rm = head;

        //set head equal to the second node, the next node in the list
        head = head -> n_link;

        delete rm;
    } else {
        Node* cursor, prev;
        
        cursor = head;
        while (cursor != NULL && cursor -> data != target) {//If you check the data and cursor is at NULL, you will get a seg fault
            prev = cursor;
            cursor = cursor -> n_link;
        }

        if (cursor != NULL) {
        prev -> n_link = cursor -> n_link; //connect the item previous to your target to the item after your target
        delete cursor;
        } else {
            cout << "Target unidentified\n";
        }
    }
} 

