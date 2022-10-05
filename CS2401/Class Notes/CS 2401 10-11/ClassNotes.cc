//Adding items to Node list

//tail function
//tail is used to keep track of the end of a list, saves time since you don't have to move to the end of a list

void LL_container::add_to_end (const string& s) {
    if (head == NULL) {
        head = tail = new Node(s);
    }
    else {
        tail -> set_next(new Node(s));
        tail = tail -> next();
    }
}


//Now we're going to alter the node class
//DOUBLE LINKED LISTS
//adding a pointer that says "what comes before me"
//"previous" pointer for nodes, if the node is the first in the list, it points at NULL
//this involves changing the node

class Node {
    public:
    node (int i = 0, node* p = NULL, node* n = NULL);
    int data(){return data_field;}
    node* next(){return next;}
    node* previous(){return previous;}

    void set_data(int d){data_field = d;}
    void set_next(node* n){next = n;}
    void set_previous(node* p){previous = p;}


    private:
    int data_field;
    node* next;
    node* previous;
}

node::node(){
    data_field = i;
    next = n;
    previous = p;
}





void Llist{
    public:
    Llist(head = tail = NULL);
    void remove(int target);
    private:
    node* head;
    node* tail;
}

void Llist::remove(int target) {
    node* cursor = head;
    if (head -> data = target) {
        head = head -> next();
        delete cursor;
        head -> set_previous(NULL);
    }
    else {
        while (cursor != NULL && cursor -> data != target) {
            cursor = cursor -> next;
        }
        if (cursor != NULL) {
            //found target
            if (cursor == tail){
                tail = cursor -> previous();
                tail -> set_next(NULL);
            }
            else {
                cursor -> previous() -> set_next(cusor -> next());
                cursor -> next() -> set_previous(cursor -> previous());
            }
            delete cursor;
        }
    }
}