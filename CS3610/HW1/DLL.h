/*
 * #File: DLL.h
 * #Assignment: Homework 1, CS3610 fa2022
 * #Author: Asa Chen
 * #Date: August 29, 2022
 * #Info: The linked list header file which requires the Node class and is the backbone of the dictionary
 *       header file and implimentation. This file contains pointers to the head and tail of the list, default
 *       constructors, addition functions, removal functions, search functions, retrieval functions, and organization functions.
 */
#ifndef DLL_H
#define DLL_H
#include <vector>
#include "Node.h"
using namespace std;

class DLL
{
public:
    //Default Constructor
    DLL();

    //Mutators
    /**
     * Function: add
     * @brief Adds a key-value pair onto the list. If the list is empty it makes one, if the list 
     *       is not empty, the pair is put on the end then sorted.
     * 
     * @param key - The key you wish to place in the list.
     * @param value - The value you wish to place in the list.
     */
    void add(string key, string value);
    /**
     * Function: sort
     * @brief Sorts the list alphabetically from front to back. Used by other functions in this file.
     */
    void sort();
    /**
     * Function: key_remove
     * @brief Searches the list for a given key. If the key is in the list it is removed.
     * @param key_target - The key you'd like to remove from the list.
     */
    void key_remove(string key_target);
    /**
     * Function: value_s_remove
     * @brief Searches the list for given values and removes all instances of that value.
     * @param value_target - The key you'd like to remove.
     */
    void value_s_remove(string value_target);

    //display function (for main.cc testing)
    /**
     * Function: show_from_front
     * @brief Displays the list from front to back.
     */
    void show_from_front();

    //List information and data retrieval
    /**
     * Function: list_sie
     * @brief Iterates through the list and creates a sum representing the total number of nodes in a list.
     * @return int - The number of nodes in the list.
     */
    int list_size();
    /**
     * Function: key_value_search
     * @brief Searches the list for a given key and, if found, returns the value stored with the key.
     * @param key_target - The key you'd like to search for.
     * @return string - The value string associated with the key. If not found, returns "NOT_FOUND".
     */
    string key_value_search(string key_target);
    /**
     * Function: key_search
     * @brief Searches the list for a given key and, if found, returns the key.
     * @param key_target - The key you'd like to search for.
     * @return string - The key stored in the Node. if not found, returns "NOT_FOUND".
     */
    string key_search(string key_target);
    /**
     * @brief Searches the key for a given value and, if found, returns the value.
     * @param value_target - The value you'd like to find.
     * @return string - The value stored in the node. If not found, returns "NOT_FOUND".
     */
    string value_search(string value_target);
    /**
     * Function: show_values
     * @brief Collects all values stored in the list into a single vector and returns the vector.
     * @return vector<string> - The vector of all values, if list is empty, returns empty vector.
     */
    vector<string> show_values();
    /**
     * @brief Collects all keys in the list and stores them in a single vector.
     * @return vector<string> - The vector of all keys, if list is empty, returns empty vector.
     */
    vector<string> show_keys();

private:
    Node *head;
    Node *tail;
};

//----
DLL::DLL()
{
    head = tail = nullptr;
}

void DLL::add(string key, string value)
{
    if (head == nullptr)
    {
        head = tail = new Node;
        head -> set_value(value);
        head -> set_key(key);
        head -> next = nullptr;
        tail -> next = nullptr;
        head -> prev = nullptr;
        tail -> prev = nullptr;
        return;
    }
    else
    {
        //-----------------------search to see if a key is in the list
        for (Node *iter = head; iter != nullptr; iter = iter -> next)
        {
            string search_key = key;
            for (int i = 0; i < search_key.size(); i++)
            {
                search_key[i] = tolower(search_key[i]);
            }
            string iter_key = iter -> get_key();
            for (int i = 0; i < iter_key.size(); i++)
            {
                iter_key[i] = tolower(iter_key[i]);
            }
            if (iter_key == search_key)
            {
                iter -> set_value(value);
                return;
            }
        } //---------------------- If the key is not found
        tail -> next = new Node;
        tail -> next -> prev = tail;
        tail = tail -> next;
        tail -> set_value(value);
        tail -> set_key(key);
        tail -> next = nullptr;
        sort();
    }
}

void DLL::sort()
{
    if (head == nullptr || head == tail)
    {
        return;
    }
    else
    {
        for (Node *iter_ptr = head -> next; iter_ptr != nullptr; iter_ptr = iter_ptr -> next)
        {
            Node *tmp_ptr = iter_ptr;
            while (tmp_ptr -> prev != nullptr)
            {
                string tmp_key = tmp_ptr -> get_key();
                for (int i = 0; i < tmp_key.size(); i++)
                {
                    tmp_key[i] = tolower(tmp_key[i]);
                }
                string prev_key = tmp_ptr -> prev -> get_key();
                for (int i = 0; i < prev_key.size(); i++)
                {
                    prev_key[i] = tolower(prev_key[i]);
                }
                if (tmp_key < prev_key)
                {
                    string tmp_val = tmp_ptr -> get_value();
                    string tmp_key = tmp_ptr -> get_key();
                    tmp_ptr -> set_value(tmp_ptr -> prev -> get_value());
                    tmp_ptr -> set_key(tmp_ptr -> prev -> get_key());
                    tmp_ptr -> prev -> set_value(tmp_val);
                    tmp_ptr -> prev -> set_key(tmp_key);
                }
                else
                {
                    tmp_ptr = tmp_ptr -> prev;
                }
            }
        }
    }
}

void DLL::key_remove(string key_target)
{
    string head_key = head -> get_key();
    for (int i = 0; i < head_key.size(); i++)
    {
        head_key[i] = tolower(head_key[i]);
    }
    string tail_key = tail -> get_key();
    for (int i = 0; i < tail_key.size(); i++)
    {
        tail_key[i] = tolower(tail_key[i]);
    }
    Node *tmp_ptr;
    if (head == nullptr)
    {
        // Do Nothing
    }
    else if (head == tail && head_key == key_target)
    {
        tmp_ptr = head;
        head = nullptr;
        tail = nullptr;
        delete tmp_ptr;
    }
    else if (head_key == key_target)
    {
        tmp_ptr = head;
        head = head -> next;
        head -> prev = nullptr;
        delete tmp_ptr;
        sort();
    }
    else if (tail_key == key_target)
    {
        tmp_ptr = tail;
        tail = tail->prev;
        tail -> next = nullptr;
        delete tmp_ptr;
        sort();
    }
    else
    {
        for (tmp_ptr = head; tmp_ptr != nullptr; tmp_ptr = tmp_ptr -> next)
        {
            string tmp_key = tmp_ptr -> get_key();
            for (int i = 0; i < tmp_key.size(); i++)
            {
                tmp_key[i] = tolower(tmp_key[i]);
            }
            if (tmp_key == key_target)
            {
                break;
            }
        }
        tmp_ptr -> prev -> next = tmp_ptr -> next;
        tmp_ptr -> next -> prev = tmp_ptr -> prev;
        delete tmp_ptr;
        sort();
    }
}

void DLL::value_s_remove(string value_target)
{
    Node *tmp_ptr;
    Node *it_ptr;
    if (head == nullptr)
    {
        // Do nothing
    }
    else if (head == tail && head->get_value() == value_target)
    {
        tmp_ptr = head;
        head = nullptr;
        tail = nullptr;
        delete tmp_ptr;
    }
    else
    {
        it_ptr = head;
        while (it_ptr != nullptr)
        {
            if (it_ptr == head && it_ptr -> get_value() == value_target)
            {
                tmp_ptr = it_ptr;
                it_ptr = it_ptr -> next;
                head = head -> next;
                head -> prev = nullptr;
                delete tmp_ptr;
            }
            else if (it_ptr -> get_value() == value_target && it_ptr != tail)
            {
                tmp_ptr = it_ptr;
                it_ptr -> prev -> next = it_ptr -> next;
                it_ptr -> next -> prev = it_ptr -> prev;
                it_ptr = it_ptr -> next;
                delete tmp_ptr;
            }
            else if (it_ptr == tail && it_ptr -> get_value() == value_target)
            {
                tmp_ptr = it_ptr;
                it_ptr = it_ptr -> next;
                tail = tail -> prev;
                tail -> next = nullptr;
                delete tmp_ptr;
            }
            else
            {
                it_ptr = it_ptr -> next;
            }
        }
        sort();
    }
}

void DLL::show_from_front()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
    }
    for (Node *tmp_ptr = head; tmp_ptr != nullptr; tmp_ptr = tmp_ptr -> next)
    {
        cout << tmp_ptr -> get_key() << "  " << tmp_ptr -> get_value() << endl;
    }
}

int DLL::list_size()
{
    int counter = 0;
    if (head == nullptr)
    {
        return counter;
    }
    else
    {
        for (Node *tmp_ptr = head; tmp_ptr != nullptr; tmp_ptr = tmp_ptr -> next)
        {
            counter++;
        }
        return counter;
    }
}

string DLL::key_value_search(string key_target)
{
    if (head == nullptr)
    {
        return "NOT_FOUND";
    }
    else
    {

        for (Node *tmp_ptr = head; tmp_ptr != nullptr; tmp_ptr = tmp_ptr -> next)
        {
            string tmp_key = tmp_ptr -> get_key();
            for (int i = 0; i < tmp_key.size(); i++)
            {
                tmp_key[i] = tolower(tmp_key[i]);
            }
            if (tmp_key == key_target)
            {
                return tmp_ptr -> get_value();
            }
        }
        return "NOT_FOUND";
    }
}

string DLL::key_search(string key_target)
{
    if (head == nullptr)
    {
        return "NOT_FOUND";
    }
    else
    {
        for (Node *tmp_ptr = head; tmp_ptr != nullptr; tmp_ptr = tmp_ptr -> next)
        {
            string tmp_key = tmp_ptr -> get_key();
            for (int i = 0; i < tmp_key.size(); i++)
            {
                tmp_key[i] = tolower(tmp_key[i]);
            }
            if (tmp_key == key_target)
            {
                return tmp_ptr -> get_key();
            }
        }
        return "NOT_FOUND";
    }
}

string DLL::value_search(string value_target)
{
    if (head == nullptr)
    {
        return "NOT_FOUND";
    }
    else
    {
        for (Node *tmp_ptr = head; tmp_ptr != nullptr; tmp_ptr = tmp_ptr -> next)
        {
            if (tmp_ptr -> get_value() == value_target)
            {
                return tmp_ptr -> get_value();
            }
        }
        return "NOT_FOUND";
    }
}

vector<string> DLL::show_values()
{
    vector<string> value_vec;
    if (head == nullptr)
    {
        return value_vec;
    }
    else
    {
        for (Node *tmp_ptr = head; tmp_ptr != nullptr; tmp_ptr = tmp_ptr -> next)
        {
            value_vec.push_back(tmp_ptr -> get_value());
        }
        return value_vec;
    }
}

vector<string> DLL::show_keys()
{
    vector<string> key_vec;
    if (head == nullptr)
    {
        return key_vec;
    }
    else
    {
        for (Node *tmp_ptr = head; tmp_ptr != nullptr; tmp_ptr = tmp_ptr -> next)
        {
            key_vec.push_back(tmp_ptr -> get_key());
        }
        return key_vec;
    }
}

#endif
