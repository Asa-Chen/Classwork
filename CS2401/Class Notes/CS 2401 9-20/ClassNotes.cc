class D_Nums {
    public:
        D_Nums();
        void add_item(double item);

    private:
        double* data; //pointer to data array
        int used; //can use size_t if you want
        int capacity; 
        int current_index; //iterator, need for Project 2
        void resize(); //Make the array bigger if used is full. Function in private section because it is not up to the programmer
};

D_Nums::D_Nums() { //default constructor sets data pointer to new double array of size capacity
    used = 0;
    capacity = 5;
    data = new double[capacity];
}

void D_Nums::add_item(double item){
    if (used == capacity) {
        resize(); //Can only access from member functions
    }
    data[used] = item;
    used++;
}

void D_Nums::resize() {
    double* tmpptr;
    tmpptr = new double[capacity +5];

    for (int i = 0; i < used; i++) { //Copy data into tmpptr
        tmpptr[i] = data[i];
    }
    delete []data; //deallocate old array. [] deletes entire array. Without deletes just the one memory cell
    data = tmpptr; //point data at the new array
    capacity += 5; //resize capacity to reflect new array
}


//If you want to see destructor deleting
cout << "Deleting this object";

//^^^^^^^^^^^^Reviewing class on friday, copy, destroy, and equals


//BRAND NEW TOPIC
//problems with dynamic arrays: copying and resizing takes a LONG TIME for big data sets
//Arrays also have to be contiguous in memory, meaning you need a large enough chunk of clear memory
//Linked Lists is the remedy
//^^^^^^^^^^^^
//We are going to start with structures but it can be done with classes
//From the beginning, point to the next spot in memory, and so on for each structure, the data no longers has to be contiguous.
//The first pointer/front of list is called the HEAD, and the end pointer will be set to NULL, which is 0 in the OS memory, which is never used or allocated.
struct Node {
    string data;
    // can store any data you want and multiple forms
    Node* n_link;
}


Node* head;

//empty list
head = NULL;

//put a node in list
head = new Node; //Once you set the head, don't cut it off!
(*head).data = "string";
(*head).n_link = NULL;

//make second node
Node* ptr;
ptr = new Node;
(*ptr).data = "wut";
(*head).n_link = ptr; //points head n_link to the next node in the list.
(*ptr).n_link = NULL;

//Easier way to dereference and access pointer data
head -> data = "wut";
// "->" takes the place of (*)
// "->" is typically called "at"
head -> data = "wut"; //Head at data
head -> n_list = NULL; //Head at n_list


//suppose you have a really long list

//BIG O, an approximation of how the algorithm will perform given the data set


//Searching linked lists
Node* cursor = head;
//or
Node* cursor;
cursor = head;

while (cursor != NULL) { //keep looping until the cursor hits NULL, but, DO NOT SEARCH NULL
if (cursor -> data == target) {
    cout << cursor -> data << end; //display data
}
cursor = cursor -> next; //set cursor to whatever the structure's next address is, trust it to know where the next element is
}

//Function to add a new node to the end of a linked list
void add_to__end(Node*& head, string& datatoadd) { //Pass head as ref because if the list is empty, you must overwright head with the address of the beginning of the list
if (head == NULL) { //Check the head! or else you can have seg faults
    head = new Node;
    head -> data = datatoadd;
    head -> n_link = NULL;
} else {
    Node* cursor = head;
    while (cursor -> n_link != NULL) { //if the next pointer is aimed at null
    cursor = cursor -> n_link;
    }
    cursor -> n_link = new Node; //attaches new node onto end of last node
    cursor -> n_link -> n_link = NULL; //You can chain the arrows. Value of n_link in the recently created Node is equal to NULL.
    cursor -> n_link -> data = datatoadd;
    //or
    cursor = cursor -> n_link;
    cursor -> n_link = NULL;
    cursor -> data = datatoadd;


}

}