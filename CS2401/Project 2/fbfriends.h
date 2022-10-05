/*************************************************************************
   This class is a container that holds objects of the class MyFriend.
   It uses an internal iterator to give the application the ability to
   order the container as well as access to the elements in the container.
   Because it uses dynamic memory it needs to have the Big3.

     John Dolan			Spring 2021		Ohio University EECS
	 Patricia Lindner	Fall 2021		Ohio University EECS
*************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "MyFriend.h"
#ifndef FBFRIENDS_H
#define FBFRIENDS_H

class FBFriends{
    public:
        FBFriends();

        //The functions known as the Big 3
        ~FBFriends();
        FBFriends(const FBFriends& other);
        void operator = (const FBFriends& other);

        // Functions for the internal iterator
        void start();
        void advance();
        bool is_item()const;
        MyFriend current()const;
        void remove_current();
        void insert(const MyFriend& f);
        void attach(const MyFriend& f);
        
        void show_all(std::ostream& outs)const;
        void bday_sort();
        MyFriend find_friend(const std::string& name)const;
        bool is_friend(const MyFriend& f) const;

        void load(std::istream& ins);
        void save(std::ostream& outs)const;

    private:
        void resize(); // increases the capacity of the container by 5
        MyFriend *data;
        int used;
        int capacity;
        int current_index;
};

#endif