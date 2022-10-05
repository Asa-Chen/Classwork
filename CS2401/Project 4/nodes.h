/*
* Asa Chen - CS2401 Project 4
* node.h - header file for a template data node used in dlist.h
* 10-28-21
*/
#ifndef DNODES_H
#define DNODES_H
using namespace std;
template <class T>
class Node{
    public:
    Node(T d = T(), Node* n = NULL, Node* p = NULL); //default constructor

    //accessors
    T data() const;
    Node* next() const;
    Node* previous() const;
    
    //set functions
    void set_data(T item);
    void set_next(Node* n);
    void set_previous(Node* p);


    private:
    T data_field;
    Node* next_field;
    Node* previous_field;

};




#include "nodes.temp"

#endif
