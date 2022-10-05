

//Relevant to project 4,

//template node, template class
//Making a linked list that can hold any kind of data
//Template list class that has a head & a tail
//Front insert, add to head
//Tail insert, add to tail
//Front remove
//PROGRAM INCRIMENTALLY!!!!!!!!!!!!!
//Main1.cc has been written for testing
//ITERATOR, NOT THE SAME AS PROJECT 2
//Can start working on list class since it doesn't need the iterator
//Can work up until line 50 of main1 without interator info
//Linked lists are dynamic memory, meaning that you NEED THE BIG 3
//MAINTAIN next and previous for adding and removing pointers from the list


//Bi-directional external iterator
//Iterator is its own class
//Useful info in book. 320,326,344

//Entire application is written for you.
//Application is meant as a test to see how well you built the previous items
//Swatches.txt is the swatch file, used for testing?
//A bunch of .exe that work with swatch class
//Main2 uses the swatch class and creates a linked list of nodes that holds swatch data
//use templates you've written to allow main to create and organize a list of colors
//The application then makes a copy, removes the first node, last node, and middle node
//Outputs the original a bunch of different ways
//destroys the original by cutting off the head and the tail until its dead
//GET THE COPY RIGHT!
//No user interaction
//make html program. Don't have to understand how that works
//main2 is .hold
//Move main1 to .hold, then main2 to .cc whe ready
//don't complie two mains
//Don't have to change any files given


//template nodes. Not exactly what is needed for project 4, but is easily modified to suit

template<class T> //T can be anything

class Node {
    public:
        Node(T d = T(), node* n - NULL); //Data types in C++ have default constructors. So use T() to set whatever data type it is

        //accessors
        T data()const {return data_field;}
        node* next()const {return next_field;}
        const node* next()const {return next_field;} //helpful

        //setting function
        void set_data(T item) {data_field = item;}
        void set_next(node* n) {next_field = n;}

    private:
        T data_field;
        node* next_field;


};

template<class T>
node<T>::node(T d, node* n) { //Default constructor
    data_field = d;
    next_field = n;
}


//Linked list template

template<class T>
class TLList{
    public:
        TLList();
        //The Big 3
        ~TLList();
        TLList(const TLList& other);
        void operator = (const TLList& other);


        void add (const T& item);
        void display(std::ostream& outs) const;


    private:
        node<T>* head; //T is meant to declare that its storing a node class stated above
        node<T>* tail; //my node pointer will be a node of type T
};


template<class T>
TLList<T>::TLList(){
    head = tail = NULL;
}


template<class T>
void TLList<T>::add(const T& item){
    //add this to back of list
    if(head == NULL) {
        head = tail = new node<T>(item);
    }
    else {
        tail -> set_next(new node<T>(item));
        tail = tail -> next();
    }
}



