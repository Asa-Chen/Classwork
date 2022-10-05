/***********************
* Asa Chen - CS2401 Fall 2021-2022
* Project 5 - main.cc
* Application used to demostrate parent and child classes
***********************/
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "closet.h"
using namespace std;

void display(list<Closetitem*> li, list<Closetitem*>::iterator it);
char menu1();
int main() {

list<Closetitem*> closet; //STL list of Closetitem pointers
list<Closetitem*>::iterator iter; //Iterator for STL list
jacket* jptr; //Jacket pointer
frizbee* fptr; //Frizbee pointer
shirt* sptr; //Shirt pointer
shoes* shptr; //Shoes pointer
pants* pptr; //Pants pointer
backpack* bptr; //Backpack pointer
char choice1; //Choice for menu
string owner, ownerfile, item; //Strings for file load/save
ifstream fin;
ofstream fout;

//File input
cout << "\nPlease enter a closet owner: ";
getline(cin, owner);
ownerfile = owner + ".txt";

fin.open(ownerfile);
if (!fin.fail()) {
    while (!fin.eof()) {
        getline(fin,item);
        while (fin.peek() == '\n' || fin.peek() == ' ') fin.ignore();
        if (fin.eof() == true) {break;} //Statement meant to prevent spare lines at end of file from messing up input
        if (item == "jacket") {
            jptr = new jacket();
            jptr -> input(fin);
            closet.push_back(jptr);
        } else if (item == "frizbee") {
            fptr = new frizbee();
            fptr -> input(fin);
            closet.push_back(fptr);   
        } else if (item == "shirt") {
            sptr = new shirt();
            sptr -> input(fin);
            closet.push_back(sptr);
        } else if (item == "shoes") {
            shptr = new shoes();
            shptr -> input(fin);
            closet.push_back(shptr);
        } else if (item == "pants") {
            pptr = new pants();
            pptr -> input(fin);
            closet.push_back(pptr);
        } else if (item == "backpack") {
            bptr = new backpack();
            bptr -> input(fin);
            closet.push_back(bptr);
        } else {
            //do nothing
        }
    }
    fin.close();
}

//Main Menu
choice1 = menu1();
while (choice1 != '7') {
    switch(choice1) {
        case '0':
            jptr = new jacket(); //set the pointer equal to a new object
            jptr -> input(cin); //fill the object
            closet.push_back(jptr); //push it onto the list
            break;
        case '1':
            fptr = new frizbee();
            fptr -> input(cin);
            closet.push_back(fptr);
            break;
        case '2':
            sptr = new shirt();
            sptr -> input(cin);
            closet.push_back(sptr);
            break;
        case '3':
            shptr = new shoes();
            shptr -> input(cin);
            closet.push_back(shptr);
            break;
        case '4':
            pptr = new pants();
            pptr -> input(cin);
            closet.push_back(pptr);
            break;
        case '5':
            bptr = new backpack();
            bptr -> input(cin);
            closet.push_back(bptr);
            break;
        case '6':
            if (!closet.empty()) {
                display(closet, iter);
            }
            break;
        case '7':
            //cout << "\nEnding Application. Thank you.";
            break;
    }
    choice1 = menu1();
}



//File output
cout << "\nEnding Application. Thank you.";
fout.open(ownerfile);
if (!fout.fail()) {
    for (iter = closet.begin(); iter != closet.end(); ++iter) {
        (*iter) -> output(fout);
    }
} else {"\n Error saving data.";}
fout.close();

    return 0;
}

//Displayed menu
char menu1() {
    char choice;
    cout << "\nUse one of the following inputs to use the closet.\n";
    cout << "0 - Place a Jacket in the closet\n";
    cout << "1 - Place a Frizbee in the closet\n";
    cout << "2 - Place a Shirt in the closet\n";
    cout << "3 - Place a pair of Shoes in the closet\n";
    cout << "4 - Place a pair of Pants in the closet\n";
    cout << "5 - Place a Backpack in the closet\n";
    cout << "6 - Display all items in the closet\n";
    cout << "7 - Close the closet and end the program\n";
    cin >> choice;
    return choice;
}

void display(list<Closetitem*> li, list<Closetitem*>::iterator it) { //custom display function. Makes the display case cleaner.
    if (!li.empty()) {
        for (it = li.begin(); it != li.end(); ++it) {
            (*it) -> output(cout);
        }
    }
}