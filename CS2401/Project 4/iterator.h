/*
* Asa Chen - CS2401 Project 4
* iterator.h - header file for a template external iterator used by a data list class
* 10-28-21
*/
#include "nodes.h"
#ifndef ITERATOR_H
#define ITERATOR_H

template<class T>
class dlist;


template<class T>
class node_iterator {
    friend class dlist<T>;
    public:
    //default constructor
    node_iterator(Node<T>* n = NULL) {current = n;}

    //operators
    bool operator != (const node_iterator other) const;
    bool operator == (const node_iterator other) const;
    T operator *() const;
    node_iterator operator ++();
    node_iterator operator ++(int);
    node_iterator operator --();
    node_iterator operator --(int);
    



    private:
    Node<T>* current;
};

#include "iterator.temp"
#endif


