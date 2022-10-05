//Project 3 review
//when reading from file, no prompt
//use getline!!!
//Datafile output
//NAME
//BIRTHDAY
//DATE APPOINTMENT WAS MADE
//TIME APPOINTMENT WAS MADE


void LL_contain::add_to_end(const string& s){
    if (head == NULL) {
        head = new Node(s);
    } else {
        Node* cursor = head;
        while (cursor -> next() != NULL) {
            cursor = cursor -> next();
        }
        cursor -> set_next(new Node(s));
    }

}

//TYPE_DEF
//takes an object type and call it something else
//For the rest if the file, anytime "value_type" appears, it replaces it with the typedef object type
//Makes it so you don't have to change the object data type across an entire file. just the one typedef "data type" "name";
typedef "data type" "name";