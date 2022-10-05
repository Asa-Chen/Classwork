//Last couple things needed for Project 4
//In the node, you will need to add a previous pointer


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
        iterator end() const {return iterator(NULL);} //NULL both ways

        //r_begin()
        //r_end()

        //void remove(iterator it) //removes whatever the iterator is pointing at currently
        //void insert_before(iterator it, T item)
        //void inster_after(iterator it, T item)

    private:
        node<T>* head; //T is meant to declare that its storing a node class stated above
        node<T>* tail; //my node pointer will be a node of type T
};


node<T>* ptr = it.current(); //Need an extra pointer to rearrange next/previous and still delete the node
 //In order to allow the LList class to use the current function of the iterator, you need to set the LList class to be a friend of the node

//break

 #include "node.h"
template<class T>
class node_iterator{
    friend class TLList<T>; //<------------------This thing
    //This will cause a problem when compiling because TLList is not compiled yet
    //To remedy this, use the example below
    public:

    private:
        node<T>* current;
};


template<class T> //This thing <-------
class TLList; // This thing <---------
 //promises the compiler that there is a TLList class that will be built
 #include "node.h"
template<class T>
class node_iterator{
    friend class TLList<T>;
    public:
    private:
        node<T>* current;
};

//break

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

        //prefix --
        //postfix -- 
        //You will need to define these as well <----------------------

    private:
        node<T>* current;
};


//break


//Not relative to Project 4
//THE REASON you are doing project 4, is to understand how the templates and STL work. VERY IMPORTANT
//Standard Template Library - STL
//Already has a bunch of standard templates built

//set - each item can only appear once

//multiset - items can appear more than once
//Kind of an array of stuff
//When you put things into the set, it automatically organizes them based on the "<" operator

#include <set>
#include <string>

using namespace std;
int main() {
    multiset<string> names;//requires std
    names.insert("hello");
    names.insert("World");
    names.insert("chungus");
    names.insert("hello"); //since its a multiset, you can insert the same string more than once

    //In order to get to the data, declare an iterator
    multiset<string>::iterator it; //an iterator that works on a multiset of strings
    //Iterator is completly detached, not relative to anything
    //fix that below
    it = names.begin(); //now it is attached to the beginning of the names set
    while (it != names.end()) {
        cout << *it << endl; //Looks like a pointer, BUT IS NOT. Asking to output the data that the iterator is pointing at.
        ++it; //* is overloaded for iterators to output the data they point at
    }
}

OUTPUT:

Arnold
David
David
Steve
//because <

< needs to have the following properties:
antisymmetry - if x < y, NOT y < x // if x < y, y cannot be < x
transitivity - if x < y, and y < z, then x < z
irreflexivity - NOT x < x //X can't be less than itself



//YOU CAN REUSE THE ITERATOR
    multiset<string> colors;
    it = colors.begin(); //same iterator as above
    while (it != end()) {
        //output stuff
    }


//YOU CANNOT REUSE ITERATORS ON DIFFERENT DATA TYPES
    multiset<int> nums;
    it = nums.negin(); //NO NO!
//Declare a new iterator for the type of data the set is storing (int)
