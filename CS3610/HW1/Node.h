/*
 * #File: Node.h
 * #Assignment: Homework 1, CS3610 fa2022
 * #Author: Asa Chen
 * #Date: August 29, 2022
 * #Info: The header file for Node class used by the Doubly Linked List in homework assignment one.
 *       This file contains the data stored in each Node, pointers enabling a doubly linked list, and
 *       basic access and setting functions for the data.
 */
#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;
class Node
{
public:

    //Accessors
    /**
     * Function: get_value
     * @brief Access the value object
     * @return value string 
     */
    string get_value() { return value; };
    /**
     * Function: get_key
     * @brief Access the key object
     * @return key string 
     */
    string get_key() { return key; };

    //Mutators
    /**
     * Function: set_value
     * @brief Set the value object
     * @param value_in - the input value you'd like to set
     */
    void set_value(string value_in) { value = value_in; };
    /**
     * Function: set_key
     * @brief Set the key object
     * @param key_in - the input key you'd like to set
     */
    void set_key(string key_in) { key = key_in; };

    //Pointers
    Node *next;
    Node *prev;

private:
    //Data
    string key;
    string value;
};

#endif