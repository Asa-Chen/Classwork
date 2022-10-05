/*******************************************************************
 * Asa Chen
 * 09-13-2021
 * checkbook.h
 * Header file for checkbook container class. Contains all the
 * function declarations required to run the program.
 * *****************************************************************/

#ifndef CHECKBOOK_H
#define CHECKBOOK_H

#include <iostream>
#include "check.h"
#include "date.h"

class Checkbook {

    public:
    static const size_t CAPACITY = 200;

    //Constructor
    Checkbook (double b = 00.00, int c = 1);
    
    //Mutate
    void load_from_file(std::istream& ifs);
    void deposit (double amount);
    void write_check(std::istream& ins);
    void remove (int rmnum);
    void save (std::ostream& ofs);



    //Access 
    double get_balance() const;
    void show_all(std::ostream& outs) const;
    void show (std::string target) const;
    double average() const;

    //Organize
    void number_sort();
    void payto_sort();
    void date_sort();


    private:
    double balance;
    int checknum;
    size_t used;
    Check checks[CAPACITY];





};


#endif