#include <iostream>
#include <fstream>
#include <string>
#include "waiting.h"
#include "appointment.h"
#include "node.h"
using namespace std;

Waiting::Waiting() { //Default Constructor, nothing fancy
    head = NULL;
    aptcount = 0;
}

Waiting::~Waiting() { //Destructor, runs through entire linked lists and deletes nodes.
    node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head -> link();
        delete tmp;
    }
    cout << endl << "List deleted" << endl << endl;
}

Waiting::Waiting(const Waiting& other) { //Copy function
    node* cursor_other = other.head;
    node* cursor;
    aptcount = 0;
    head = NULL;
    if (head == NULL) { //Start a new list
        head = cursor = new node(cursor_other -> data());
        cursor_other = cursor_other -> link();
        aptcount++;
    }
    while (cursor_other != NULL) { //Run through the other list and copy data to new list
        cursor -> set_link(new node(cursor_other -> data()));
        cursor = cursor -> link();
        cursor_other = cursor_other -> link();
        aptcount++;
    }
}


void Waiting::operator = (const Waiting& other) { //Equality operator
    if (head == other.head) {
        return; //Check to see if lists are equal
    }
    node* tmp; //If not equal, delete old list
    while (head != NULL) {
        tmp = head;
        head = head -> link();
        delete tmp;
    }
    node* cursor_other = other.head; //Copy Constructor
    node* cursor;
    head = NULL;
    if (head == NULL) {
        head = cursor = new node(cursor_other -> data());
        cursor_other = cursor_other -> link();
        aptcount++;
    }
    while (cursor_other -> link() != NULL) {
        cursor -> set_link(new node(cursor_other -> data()));
        cursor = cursor -> link();
        cursor_other = cursor_other -> link();
        aptcount++;
    }
}

void Waiting::display(ostream& outs) const { //Displays list to outstream
    node* cursor = head;
    while (cursor != NULL) {
        cursor -> data().output(outs);
        cursor = cursor -> link();
    }

}

Appointment Waiting::find(string& target) const { //Find, searches list and returns an appointment, if in list
    Appointment tmp;
    node* cursor = head;
    while (cursor != NULL && cursor -> data().get_name() != target) {
        cursor = cursor -> link(); //advance cursor to the target, if there.
    } if (cursor != NULL) {
        return cursor -> data(); //if the target is in the list, return the target
    } else {
        return tmp; //if not, return an empty appointment
    }
}

int Waiting::waiting() const {
    return aptcount;
}

int Waiting::longest_wait() const { //Returns the longest wait time, should always be the person at the head of the list
    return head -> data().minutes_waiting();
}

int Waiting::average_wait() const { //Averages and returns all the wait times in the list
    int nettotal = 0;
    node* cursor = head;
    while (cursor != NULL) { //Runs through the list and adds the minutes waiting of each individual to nettotal
        nettotal += cursor -> data().minutes_waiting();
        cursor = cursor -> link();
    }
    return (nettotal / aptcount); //divide by the total appointment count to find an average
}

int Waiting::oldest() const { //Returns the age of the oldest person in the list
    node* cursor = head;
    Date today;
    today.make_today(); 
    int oldest = cursor -> data().get_bday().age(today); //set oldest to the first person in the list
    while (cursor != NULL) {
        if (oldest < cursor -> data().get_bday().age(today)) { //if there is someone in the list older, switch them
            oldest = cursor -> data().get_bday().age(today);
        }
        cursor = cursor -> link();
    }

    return oldest;
}

int Waiting::youngest() const { //Returns the age of the youngest person in the list
    node* cursor = head;
    Date today;
    today.make_today();
    int youngest = cursor -> data().get_bday().age(today); //same as oldest, but reverse the '>'
    while (cursor != NULL) {
        if (youngest > cursor -> data().get_bday().age(today)) {
            youngest = cursor -> data().get_bday().age(today);
        }
        cursor = cursor -> link();
    }

    return youngest;
}

int Waiting::average_age() const { //Returns the average age of the people in the list
    node* cursor = head;
    Date today;
    today.make_today();
    int nettotal = 0;
    while (cursor != NULL) {
        nettotal += cursor -> data().get_bday().age(today); //add the age of every individual to nettotal
        cursor = cursor -> link();
    }
    return (nettotal / aptcount); //divide by the total number of appointments to find average
}

void Waiting::add(Appointment& ap) { //Adds an apointment to the list, at the proper time interval
    if (head == NULL) {
    head = new node(ap); //If list is empty, make a list
    aptcount++;
    } else {
        node* cursor = head;
        if (ap < cursor -> data()) { //If the appointment is earlier than the first node in the list
            node* tmp = head;
            head = new node(ap, tmp);
            aptcount++;
        } else {
            while (cursor -> link() != NULL) {
                if (ap < cursor -> data()) {break;}
                cursor = cursor -> link();
            }
            if (cursor -> link() == NULL && ap < cursor -> data()) { //SPECIAL CASE! - if you need to put the appointment before the last node
                node* tmp = cursor -> link(); //set a tmp node equal to the node ahead of the cursor
                Appointment tmpA = cursor -> data(); //create a tmp appointment with the data in the cursor
                cursor -> set_data(ap); //Set the current node data equal to the new data
                cursor -> set_link(new node(tmpA,tmp)); //create a new node with the old data from the cursor
                aptcount++;
            }
            /*Note:
            *There is definetly a better way to insert new appointments besides swapping the old data for new data in the cursor then putting the old data in a node after the cursor.
            *Unfortunatly, I ran out of time. No time to re-do the entire add function or impliment a 'previous' cursor.
            */
             else if (cursor -> link() == NULL) { //END OF LIST - If the cursor hits the end of the list, and there is no special case, slap it on the end
                cursor -> set_link(new node(ap)); //set a new node off the end of the last node with appointment data
                aptcount++;
            } else {
                node* tmp = cursor -> link(); //MIDDLE OF LIST - set a tmp node equal to the node ahead of the cursor
                Appointment tmpA = cursor -> data(); //create a tmp appointment with the data in the cursor
                cursor -> set_data(ap); //Set the current node data equal to the new data
                cursor -> set_link(new node(tmpA,tmp)); //create a new node with the old data from the cursor
                aptcount++;
            }
        }
    }
}

void Waiting::remove(string& target) { //Removes an appointment from the list 
    node* cursor = head;
    if (cursor -> data().get_name() == target){ //if the head is the target
        node* tmp = head;
        head = cursor -> link(); //advance the head
        delete tmp; //delete the target
        aptcount--;
    } else {
        while (cursor != NULL && cursor -> link() -> data().get_name() != target) { //If the next cursor is the target, stop
            cursor = cursor -> link();
        }
        if (cursor != NULL) {
            node* tmp = cursor -> link(); //set tmp equal to the target
            cursor -> set_link(cursor -> link() -> link()); //set the cursor's next pointer to the one ahead of the target
            delete tmp; //delete the target
            aptcount--;
        }
    }
}

void Waiting::load(istream& ins) { //loads a list of appointments from a file
    while (ins.peek() == '\n' || ins.peek() == ' ') {
	ins.ignore();
	}
    if (ins.eof() == true){ //If the file you load from is created but empty, don't load anything. This prevents loading empty nodes from empty files
        return;
    }

    Appointment TmpApt; //create a temporary appointment 
    node* cursor;
    if (head == NULL) { //if list is empty, make one
    TmpApt.input(ins); //set the tmp appointment equal to the next appointment in the list
    head = cursor = new node(TmpApt); //pass the appointment into the list
    aptcount++;
    }

    while (!ins.eof()){ //Ignore all spaces or new lines until a character is reached
        while (ins.peek() == '\n' || ins.peek() == ' ') {
		ins.ignore();
		}
        if (ins.eof() == true) {break;} //If the loop hits the end of the file, stop. This is to prevent empty lines at the end of the file causing the input function to load/insert an empty node
        TmpApt.input(ins); //set the tmp appointment equal to the next appointment in the list
        cursor -> set_link(new node(TmpApt)); //pass the appointment into the list
        cursor = cursor -> link();
        aptcount++;
    }

}

void Waiting::save(ostream& outs) const { //saves a list of appointments to a file
    if (head == NULL) {
        return;
    }
    node* cursor;
    cursor = head;
    while(cursor != NULL) {
        cursor -> data().output(outs);
        cursor = cursor -> link();
    }
}