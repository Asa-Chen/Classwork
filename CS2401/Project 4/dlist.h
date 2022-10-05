/*
* Asa Chen - CS2401 Project 4
* dlist.h - header file for a template data list class using an external iterator and node class
* 10-28-21
*/
#include "nodes.h"
#include "iterator.h"
#ifndef DLIST_H
#define DLIST_H
using namespace std;

template<class T>
class dlist{
    public:
    typedef node_iterator<T> iterator;
    dlist(); //default constructor
    
    //Big 3
    ~dlist();
    dlist(const dlist& other);
    void operator = (const dlist& other);

    //inserts
    void rear_insert(T item);
    void front_insert(T item);

    //remove
    void front_remove();
    void rear_remove();

    //show
    void show() const;
    void reverse_show() const;
    int size() const;

    //iterator
    iterator begin() const;
    iterator end() const;
    iterator r_begin() const;
    iterator r_end() const;
    void remove(iterator target);

    void insert_before(iterator& target, T& item);
    void insert_after(iterator& target, T& item);


    private:
    Node<T>* head;
    Node<T>* tail;
};


#include "dlist.temp"

#endif