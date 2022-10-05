/*******************************************************************
 * Asa Chen
 * 09-22-2021
 * MyFriend.cc
 * Friend class implimentation file. Containts all of the necessary
 * functions in order to access, write, compare, and output friend
 * objects to files, terminal or container class.
 * *****************************************************************/


#include "MyFriend.h"
using namespace std;

MyFriend::MyFriend() { //Default constructor
name = "Empty";
bday = Date();
}


string MyFriend::get_name() const { //Accesses the class name data
return name;
}


Date MyFriend::get_bday() const { //Accesses the stored birth date
return bday;
}


bool MyFriend::operator == (const MyFriend& other) const { //Compares the class data with another given class
    if (name == other.name && bday == other.bday) {
        return true;
    } else {
        return false;
    }
}


bool MyFriend::operator != (const MyFriend& other) const { //Compares the class data with another given class
    if (name != other.name || bday != other.bday) {
        return true;
    } else {
        return false;
    }
}


void MyFriend::input(istream& ins) { //Writes class data either from keyboard input or an external file
    if (&ins == &cin) {
        cout << "Please input your friend's name:";
        while (ins.peek() == '\n' || ins.peek() == ' ') {
				ins.ignore();
			}
        getline(cin, name);
        cout << "Please input the friend's birthday as mm/dd/yyyy: ";
        cin >> bday;
    } else {
        getline (ins,name);
        while (ins.peek() == '\n' || ins.peek() == ' ') {
			ins.ignore();
		}
        ins >> bday;
        while (ins.peek() == '\n' || ins.peek() == ' ') {
			ins.ignore();
		}
    }
}


void MyFriend::output(ostream& outs) const { //Outputs class data either to the terminal or external file
    if (&outs == &cout) {
        cout << "Friend's name: " << name << endl;
        cout << " Friend's birthday: " << bday << endl;
    } else {
        outs << name << endl;
        outs << bday << endl;
    }
}


istream& operator >> (istream& ins, MyFriend&f) { //overloaded input operator calls the input function to write data
    f.input(ins);
    return ins;
}


ostream& operator << (ostream& outs, const MyFriend& f) { //overloaded output operator calls the output function to display/output data
    f.output(outs);
    return outs;
}