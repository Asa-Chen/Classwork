//Stacks & cues 
//Using STL for lab this week
Stack<int>


//What is a stack?
//last-in-first-out, LIFO type of data structure

//Queue
//First-in-First-Out, FIFO type of data structure



//How to impliment a stack
//Writing as a template class

template<class T>
class STACK {
    public:
    STACK() {topptr = NULL;}
    //big 3 for singly linked list

    //STACK function
    //add a new item to the top of the stack
    void push(const T& item);

    //remove the top item of the stack
    void pop(); //just like remove head function

    //Will need to know what is in the node at the top of the stack
    T top() const {return topptr -> data();}

    //check if the stack is empty
    bool empty() const {return topptr == NULL;}


    private:
    node<T>* topptr; //head of stack. Only need a top pointer because we will only ever manipulate the top
}


template<class T>
void::STACK<T>::push(const T& item) {
    topptr = new node<T>(item, topptr); //Just like add to head, so, start a new node with item, then point topptr at it
}


template<class T>
void STACK<T>::pop() {
    node<T>* rmptr = topptr;
    topptr = topptr -> next();
    delete rmptr;
}
