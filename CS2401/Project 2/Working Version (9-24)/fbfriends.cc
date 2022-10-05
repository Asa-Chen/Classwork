/*******************************************************************
 * Asa Chen
 * 09-22-2021
 * fbfriends.cc
 * Friend object container class implimentation file. Contains
 * all the necessary implimentations to properly assemble and
 * manipulate a list of friends.
 * *****************************************************************/


#include "fbfriends.h"
#include "MyFriend.h"
using namespace std;

FBFriends::FBFriends() { //Default Constructor
    used = 0;
    current_index = 0;
    capacity = 5;
    data = new MyFriend[capacity];
}


FBFriends::~FBFriends () { //Destructor 
    cout << "Data removed." << endl;
    delete []data;
}


FBFriends::FBFriends (const FBFriends& other) { //Copy function
    used = other.used;
    capacity = other.capacity;
    current_index = other.current_index;
    data = new MyFriend[capacity];
    for (int i = 0; i <= used; i++) {
        data[i] = other.data[i];
    }

}


void FBFriends::operator = (const FBFriends& other) { //Equality function
if (this == &other) {
    return;
}
delete []data;
    used = other.used;
    capacity = other.capacity;
    current_index = other.current_index;
    data = new MyFriend[capacity];
    for (int i = 0; i <= used; i++) {
        data[i] = other.data[i];
    }
}


void FBFriends::start () { //Index reset
    current_index = 0;
}


void FBFriends::advance () { //Index list advance by 1
    current_index++;
}


bool FBFriends::is_item () const { //Index checker
    if (current_index < used) {
        return true;
    } else {
        return false;
    }
}


MyFriend FBFriends::current() const { //Returns current index value, or empty object
    MyFriend tmp;
    if (is_item()) {
    return data[current_index];
    } else {
        return tmp;
    }
}


void FBFriends::remove_current() { //Removes object stored at index
for (int i = current_index; i < used; i++) {
    data[i] = data[i + 1];
}
used--;
}


void FBFriends::insert(const MyFriend& f) { //Adjusts and inserts an object before current index 
                                            //or at beginning of list
    if (used == capacity) {
    resize();
    }
    if (is_friend(f)) {
        cout << "Already in list.\n";
        return;
    }
    if (is_item() == true) {
    for (int i = used; i > current_index; i--) {
        data[i] = data[i - 1];
    }
    data[current_index] = f;
    used++;
    } else {
    for (int i = used; i > 0; i--) {
       data[i] = data[i - 1];
    }
    data[0] = f;
    used++;
    }
}


void FBFriends::attach(const MyFriend& f) { //Inserts an object after the current index or 
                                            //at the end of the list
    if (used == capacity) {
    resize();
    }
    if (is_item() == true) {
     for (int i = used; i > current_index; i--) {
         data[i] = data[i - 1];
     }
     data[current_index + 1] = f;  
     used++; 
    } else {
    data[used + 1] = f;
    used++;
    }
}


void FBFriends::show_all(std::ostream& outs) const { //Runs through the entire friends' list and displays all objects
    outs << "Current Index:" << current_index << endl << "Capacity:" << capacity << endl << "Used:" << used << endl;
    for (int i = 0; i < used; i++) {
        data[i].output(outs);
    }
}

void FBFriends::bday_sort() { //Sorts the entire list by birthday from earliest to latest
MyFriend tmp;
bool complete = false;
while (!complete) {
    complete = true;
    for (int i = used - 1; i > 0; i--) {
        if (data[i].get_bday() < data[i-1].get_bday()) {
            tmp = data[i-1];
            data[i-1] = data[i];
            data[i] = tmp;
            complete = false;
        }
    }
}
}


MyFriend FBFriends::find_friend(const std::string& name) const { //Runs through the entire list and returns an object with the 
                                                                //same name as a given target name, if the friend is in the list.
MyFriend tmp;
for (int i = 0; i < used; i++) {
    if (data[i].get_name() == name) {
        return data[i];
    }
}
return tmp;
}


bool FBFriends::is_friend(const MyFriend& f) const { //Runs through the entire list to see if a given friend is already in the list
for (int i = 0; i < used; i++) {
    if (data[i] == f) {
        return true;
    }
}
return false;
}


void FBFriends::load(std::istream& ins) { //Loads a friend list from an exterior file
MyFriend tmp;
while (!ins.eof()) {
used++;
if (used == capacity) {
    resize();
}
tmp.input(ins);
data[used - 1] = tmp;
}
}



void FBFriends::save(std::ostream& outs) const { //Saves current friend's list to an exterior file
for (int i = 0; i < used; i++) {
    data[i].output(outs);
}
}


void FBFriends::resize() { //Resizes the dynamic array by 5 when adding to a list at full capacity
MyFriend* tmpptr;
tmpptr = new MyFriend[capacity + 5];
for (int i = 0; i < used; i++) {
    tmpptr[i] = data[i];
}
delete []data;
data = tmpptr;
capacity += 5;
}

