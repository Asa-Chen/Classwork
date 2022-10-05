/***
 * #File: dictionary.h
 * #Assignment: Homework 1, CS3610 fa2022
 * #Author: Asa Chen
 * #Date: August 29, 2022
 * #Info: The dictionary header and implimentation for homework assignment 1. This file relies linearly on the 
 *        preceeding double-link-list header file which relies on the node header file. This file contains a default constructor,
 *        list mutators, display/organization functions, and data retrieval functions.
 */
#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <string>
#include <vector>
#include "DLL.h"

using namespace std;

class Dictionary
{
public:

    //Default constructor
    /**
     * Function: Dictionary
     * @brief Constructs a new Dictionary object
     */
    Dictionary() { DLL d_list; };

    //Mutators
    /**
     * Functon: get
     * @brief Retreives a given value from the list if present.
     * @param key_target - The key you'd like to use to search the list.
     * @return string - The value if present. If not found, returns "NOT_FOUND"
     */
    string get(string key_target);
    /**
     * Function: put
     * @brief Places a given key-value pair in the list, if key is already present, its value is overwritten.
     * @param key - The key you'd like to place in the list.
     * @param value - The value you'd like to store with the key.
     */
    void put(string key, string value);
    /**
     * Function: removeKey
     * @brief Searches the list and removes the node represented by a given key.
     * @param key - The key you'd like to remove from the list.
     */
    void removeKey(string key);
    /**
     * Function: removeValues
     * @brief Removes all instances of a given value from the list.
     * @param value - The value you'd like to remove from the list.
     */
    void removeValues(string value);

    //Data retrieval 
    /**
     * Function: hasKey
     * @brief Searches the list and determines if a given key is in the list.
     * @param key_target - The key you'd like to find.
     * @return true - Yes, the given key is in the list.
     * @return false - No, the given key is not in the list.
     */
    bool hasKey(string key_target);
    /**
     * Function: hasValue
     * @brief Searches the list and determines of a given value is in the list.
     * @param value_target - The value you'd like to find
     * @return true - Yes, the value is in the list.
     * @return false - No, the value is not in the list.
     */
    bool hasValue(string value_target);
    /**
     * Function: display
     * @brief Displays the list from front to back.
     */
    void display();
    /**
     * Function: size
     * @brief Iterates through the list and determines the size.
     * @return int - The size of the list, if empty, returns 0.
     */
    int size();
    /**
     * Function: organize
     * @brief Sorts the list in alphabetical order from front to back.
     */
    void organize();
    /**
     * Function: values
     * @brief Collects all values in the list into a single vector and returns the vector.
     * @return vector<string> - The vector of all strings stored in the list, if empty, returns empty vector.
     */
    vector<string> values();
    /**
     * Function: keys
     * @brief Collects all keys stored in the list into one vector and returns it.
     * @return vector<string> - The collection of all keys in the list. If list is empty, returns empty vector.
     */
    vector<string> keys();

private:
    DLL d_list;
};

#endif

string Dictionary::get(string key_target)
{
    for (int i = 0; i < key_target.size(); i++)
    {
        key_target[i] = tolower(key_target[i]);
    }
    return d_list.key_value_search(key_target);
}

void Dictionary::put(string key, string value)
{
    d_list.add(key, value);
}

void Dictionary::removeKey(string key)
{
    for (int i = 0; i < key.size(); i++)
    {
        key[i] = tolower(key[i]);
    }
    d_list.key_remove(key);
}

void Dictionary::removeValues(string value)
{
    d_list.value_s_remove(value);
}

bool Dictionary::hasKey(string key_target)
{
    for (int i = 0; i < key_target.size(); i++)
    {
        key_target[i] = tolower(key_target[i]);
    }
    string result = d_list.key_search(key_target);
    if (result == "NOT_FOUND")
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Dictionary::hasValue(string value_target)
{
    string result = d_list.value_search(value_target);
    if (result == "NOT_FOUND")
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Dictionary::display()
{
    d_list.show_from_front();
}

int Dictionary::size()
{
    return d_list.list_size();
}

void Dictionary::organize()
{
    d_list.sort();
}

vector<string> Dictionary::values()
{
    return d_list.show_values();
}

vector<string> Dictionary::keys()
{
    return d_list.show_keys();
}