/*******************************************************************
 * Asa Chen
 * 09-13-2021
 * checkbook.cc
 * Implimentation file for checkbook container class. Contains all
 * function implimentations declared in the included "checkbook.h"
 * file.
 * *****************************************************************/

#include "checkbook.h"
#include <iomanip>
using namespace std;


Checkbook::Checkbook (double b, int c){ //Default constructor
    balance = b;
    checknum = c;
}

void Checkbook::load_from_file(std::istream& ins) { //Used in main program to load the given userfile into the array (IF the file already exists)
    ins >> balance; //Loads account balance
    while (ins.peek() == '\n' || ins.peek() == ' ') { //Skips empty lines
        ins.ignore();
    }
    ins >> checknum; //Loads the check number
    while (!ins.eof()) { //Writes the remainder of the file into the checkbook using write_check
        write_check(ins);
    }
}

void Checkbook::deposit (double amount) { //Takes the given amount and adds it to the account balance
    balance += amount;
}

void Checkbook::write_check (std::istream& ins) { //Determines if the input is from the keyboard or a file, increases the check num accordingly,
    Check tmp;                                    //then calls write_check from the check class to write the check or load from a file.
    used++;
    if (&ins == &cin) {
        tmp.set_check_num(checknum);
        checknum++;
    }
    tmp.write_check(ins);
    checks[used - 1] = tmp;
}

void Checkbook::remove (int rmnum) { //removes a check when given a valid check number to search for.
                                    //!DO NOT! input a char/string value. The menu loop will break and repeat infintely. 
//TO REMOVE A CHECK, simply switch the check you want to remove with the last used check at the end
    Check tmp;
    for (int i = 0; i <= used - 1; i++) { //loop used to search the array for the given check number
        if (checks[i].get_num() == rmnum) {
            checks[i] = checks[used - 1];
            used--;
        }
    }
}

void Checkbook::save (std::ostream& ofs) { //Called automatically when the user ends the program.
                                          //Overwrites the file given in the beginning, or creates a file if none was given.
                                          //Uses the output function declared in the check class.
    ofs << balance << endl << endl;
    ofs << checknum << endl << endl;
    for (int i = 0; i < used; i++){
        checks[i].output(ofs);
    }
}

double Checkbook::get_balance() const { //Accesses the checkbook balance and returns the value
    return balance;
}

void Checkbook::show_all(std::ostream& outs) const { //Runs through the checks array and displays all valid written checks
                                                    //Uses the output function declared in the check class.
    outs << fixed << setprecision(2);
    for (int i = 0; i < used; i++){
        checks[i].output(outs);
    }
}

void Checkbook::show(std::string target) const { //Searches the checks array for all checks written to a certain recipient.
                                                //Returns the total amount of any/all checks written to that recipient.
    double total = 0.0;
    for (int i = 0; i < used; i++) {
        if (checks[i].get_payto() == target) {
            cout << checks[i];
            total += checks[i].get_amount();
        }
    }
    cout << "Sum of Checks: " << total << endl;
}


double Checkbook::average() const { //Takes the value of every check in the checkbook and averages them out. Returning the value.
    double i_sum = 0.0;
    for (int i = 0; i < used; i++) {
        i_sum += checks[i].get_amount();
    }
    return i_sum/used;
}




void Checkbook::number_sort() { //Sorts the entire checkbook by the specific check number on each check, from lowest-highest.
    int counter;
    Check tmp;
    bool complete = false;
    while (!complete) {
        complete = true;

        for (int i = used - 1; i > 0; i--) {
            if (checks[i].get_num() < checks[i-1].get_num()) {
                tmp = checks[i-1];
                checks[i-1] = checks[i];
                checks[i] = tmp;
                complete = false;
            }
        }
    }
    }


void Checkbook::payto_sort() { //Sorts the entire checkbook alphabetically by recipient, running a-z.
    int counter;
    Check tmp;
    bool complete = false;
    while (!complete) {
        complete = true;

        for (int i = used-1 ; i > 0; i--) {
            string Target = checks[i].get_payto(); //Loads i and i-1 into separate strings
            string TargetDown1 = checks[i-1].get_payto();
            for (int z = 0; z < Target.length(); z++) { //Converts 'i' string to all lowercase
                Target[z] = tolower(Target[z]);
            }
            for (int z = 0; z < TargetDown1.length(); z++){ //Converts 'i-1' string to all lowercase
                TargetDown1[z] = tolower(TargetDown1[z]);
            }
            if (Target < TargetDown1){ //Compares the two strings
                tmp = checks[i-1];
                checks[i-1] = checks[i];
                checks[i] = tmp;
                complete = false;
            }
        }
    }
}

void Checkbook::date_sort() { //Sorts the entire checkbook by the date written, from oldest-newest.
    int counter; 
    Check tmp;
    bool complete = false;
    while (!complete) {
        complete = true;

        for (int i = used - 1; i > 0; i--) {
            if (checks[i].get_date() < checks[i-1].get_date()) {
                tmp = checks[i-1];
                checks[i-1] = checks[i];
                checks[i] = tmp;
                complete = false;
            }
        }
    }
}