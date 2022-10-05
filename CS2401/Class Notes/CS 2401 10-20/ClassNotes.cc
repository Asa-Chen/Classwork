//External iterators required for Project 4


//Writing an external iterator class
//The iterator object has its own class, and can point at verious points within the list
//This iterator has to be written for project 4


//example of calling an external iterator
TLList<int> nums;
TLList<int>::iterator it;
it = nums.begin();
while (it != nums.end()) {
    cout << *it << endl;
    ++it;//VERY IMPORTANT! if the ++ is infront, you add then output. If behind, output then add.
} //There are multiple operators that need to be overwritten 



//llist class
template<class T>
class TLList{
    public:
        typedef node_iterator<T> iterator;
        TLList();
        //The Big 3
        ~TLList();
        TLList(const TLList& other);
        void operator = (const TLList& other);


        void add (const T& item);
        void display(std::ostream& outs) const;

        //iterator functions
        iterator begin() const {return iterator(head);}
        iterator end() const {return iterator(NULL);}


    private:
        node<T>* head; //T is meant to declare that its storing a node class stated above
        node<T>* tail; //my node pointer will be a node of type T
};





//external iterator class declaration
#include "node.h"
template<class T>
class node_iterator{
    public:
        node_iterator(node<T>* c = NULL) {current = c;}
        bool operator != (node_iterator other) const;//Don't need <T> when inside own class and referencing itself
        bool operator == (node_iterator other) const;
        T operator *() const;
        node_iterator operator ++(); //prefix operator. because ++ adds a node iterator first
        node_iterator operator ++(int); //postfix operator. because ++ adds a node iterator after. Int is a flag used by the compiler to indicate postfix

    private:
        node<T>* current;
};

template <class T>
bool node_iterator<T>::operator != (node_iterator<T> other) const {
    return current != other.current;
}

template <class T>
bool node_iterator<T>::operator == (node_iterator<T> other) const {
    return current == other.current;
}

template<class T>
T node_iterator<T>::operator *() const {
    return current -> data();
}

//prefix ++
template<class T>
node_iterator<T> node_iterator<T>::operator ++() {
    current = current -> next():
    return *this; //this is my address, *this is the data stored at my own address
}

//postfix ++
template<class T>
node_iterator<T> node_iterator<T>::operator ++(int) { //different because if you returned first, the function would die
    node_iterator original(*this); //node_iterator tmp = *this; //save the original iterator position
    current = current -> next(): //move the iterator
    return original; //return the original
}