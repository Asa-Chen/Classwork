//Linked Lists with class Nodes instead of struct nodes



class Node {
public:
Node (const std::string s = "", Node* n = NULL);

//accessors
std::string data () const {return data_field;}
Node* next () const {return next_field;}


//mutators
void set_data(const std::string& s) {data_field = s;}
void set_next (Node* n) {next_field = n;}


private:
std::string data_field;
Node* next_field;

}



//.cc file
Node::Node(const std::string s, Node* n) {
    data_field = s;
    next_field = n;
}



//.h file
class LL_container {
    public:
//constructor
    LL_container();

//The Big 3
    ~LL_container();
    LL_container (const LL_container& other);
    //void operator = (const LL_container& other); //If you want to chain the "=" operator, i.e. obj1 = obj2 = obj3, return LL_container&
    //Return LL_container by reference! because if not, you'll call the copy constructor
    LL_container& operator = (const LL_container& other);

    //Other useful stuff
    void add_to_end (const std::string& s);
    void add_to_head (const std::string& s);
    void remove (std::string& target);
    void display () const;


    private:
    Node* head;
}


//.cc file
LL_container::LL_container() {
    //initialize to an empty list
    head = NULL;
}

void LL_container::display() const {
    Node* cursor = head;
    while (cursor != NULL) {
        //output data
        cout << cursor -> data() << endl; //calls function instead of data unit
        //move cursor
        cursor = cursor -> next();
    }
}

LL_container::~LL_container() {
    Node* rmptr;

    while (head != NULL) {
        rmptr = head; //set rmptr to head
        //move head to next node
        head = head -> next();
        //deallocate rmptr
        delete rmptr;

    }
}

LL_container::LL_container (const LL_container & other) {
    if (other.head == NULL) {
        head - NULL;
    }
    else {
        Node* src, dest;
        head = new Node(other.head -> data());
        //start srd at the second node in other's list
        src = other.head -> next();
        dest = head;

    while (src != NULL) {
        dest -> set_next (new Node(src -> data()));
        src = src -> next;
        dest = dest -> next;
    
        }
        dest -> set_next(NULL); //sets end of list to NULL
    }
}

LL_container& LL_container::operator = (const LL_container& other) {
    if (this == &other) {
        return *this;
    }

    //destructor code
    //copy constructor code

    return *this;
}

void LL_container::add_to_head (const string& s) {
    head = new Node (s, head);
}