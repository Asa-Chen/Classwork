/******************
 * Asa Chen - CS2401 Fall 2021-2022
 * Project 5 - closet.cc
 * implimentation file for closet items, parent and children.
 *****************/


#include "closet.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

//Jacket Functions
void jacket::input(istream& ins) {
    if (&ins == &cin) {
    cout << "Please input jacket color: ";
    while(cin.peek() == '\n' || cin.peek() == '\r') cin.ignore();
    getline(cin, color); 
    cout << "\nPlease input jacket material: ";
    while(cin.peek() == '\n' || cin.peek() == '\r') cin.ignore(); 
    getline(cin, material);
    } else {
    getline(ins, color);
    //while(cin.peek() == '\n' || cin.peek() == ' ') {cin.ignore();}
    getline(ins, material); 
    }
}

void jacket::output(ostream& outs) const {
    if (&outs == &cout) {
    cout << "\n" << setw(15) << setfill('-') << "jacket:";
    cout << "\nJacket color is: " << color;
    cout << "\nJacket material is: " << material;
    } else {
        outs << "jacket" << endl;
        outs << color << endl;
        outs << material << endl;
    }

}

//Frizbee Functions
void frizbee::input(istream& ins) {
    if (&ins == &cin) {
    cout << "Please input frizbee color: ";
    while(cin.peek() == '\n' || cin.peek() == '\r') cin.ignore();
    getline(cin, color); 
    } else {
    getline(ins, color);
    }
}

void frizbee::output(ostream& outs) const {
    if (&outs == &cout) {
    cout << "\n" << setw(15) << setfill('-') << "frizbee:";
    cout << "\nfrizbee color is: " << color;
    } else {
        outs << "frizbee" << endl;
        outs << color << endl;
    }
}

//Shirt Functions
void shirt::input(istream& ins) {
    if (&ins == &cin) {
    cout << "Please input shirt color: ";
    while(cin.peek() == '\n' || cin.peek() == '\r') cin.ignore();
    getline(cin, color); 
    cout << "\nPlease input shirt size (i.e. 'large'): ";
    while(cin.peek() == '\n' || cin.peek() == '\r') cin.ignore(); 
    getline(cin, size);
    } else {
    getline(ins, color);
    //while(cin.peek() == '\n' || cin.peek() == ' ') {cin.ignore();}
    getline(ins, size); 
    }
}

void shirt::output(ostream& outs) const {
    if (&outs == &cout) {
    cout << "\n" << setw(15) << setfill('-') << "shirt:";
    cout << "\nshirt color is: " << color;
    cout << "\nshirt size is: " << size;
    } else {
        outs << "shirt" << endl;
        outs << color << endl;
        outs << size << endl;
    }
}

//Shoes Functions
void shoes::input(istream& ins) {
    if (&ins == &cin) {
    cout << "Please input shoe color: ";
    while(cin.peek() == '\n' || cin.peek() == '\r') cin.ignore();
    getline(cin, color); 
    cout << "\nPlease input shoe style (i.e. 'sneaker'): ";
    while(cin.peek() == '\n' || cin.peek() == '\r') cin.ignore(); 
    getline(cin, style);
    cout << "\nPlease input shoe size as a whole number (i.e. 12): ";
    while(cin.peek() == '\n' || cin.peek() == '\r') cin.ignore();
    cin >> size;

    } else {
    getline(ins, color);
    getline(ins, style);
    ins >> size; 
    }
}

void shoes::output(ostream& outs) const {
    if (&outs == &cout) {
    cout << "\n" << setw(15) << setfill('-') << "shoes:";
    cout << "\nshoe color is: " << color;
    cout << "\nshoe style is: " << style;
    cout << "\nshoe size is: " << size;
    } else {
        outs << "shoes" << endl;
        outs << color << endl;
        outs << style << endl;
        outs << size << endl;
    }

}

//Pants Functions
void pants::input(istream& ins) {
    if (&ins == &cin) {
    cout << "Please input pants color: ";
    while(cin.peek() == '\n' || cin.peek() == '\r') cin.ignore();
    getline(cin, color); 
    cout << "\nPlease input pants material: ";
    while(cin.peek() == '\n' || cin.peek() == '\r') cin.ignore(); 
    getline(cin, material);
    cout << "\nPlease input pants waist size as an integer (i.e. 12): ";
    while(cin.peek() == '\n' || cin.peek() == '\r') cin.ignore();
    cin >> waist;

    } else {
    getline(ins, color);
    getline(ins, material);
    ins >> waist; 
    }
}

void pants::output(ostream& outs) const {
    if (&outs == &cout) {
    cout << "\n" << setw(15) << setfill('-') << "pants:";
    cout << "\npants color is: " << color;
    cout << "\npants material is: " << material;
    cout << "\npants waist size is: " << waist;
    } else {
        outs << "pants" << endl;
        outs << color << endl;
        outs << material << endl;
        outs << waist << endl;
    }

}

//Backpack Functions
void backpack::input(istream& ins) {
    if (&ins == &cin) {
    cout << "Please input backpack color: ";
    while(cin.peek() == '\n' || cin.peek() == '\r') cin.ignore();
    getline(cin, color); 
    cout << "\nPlease input backpack material: ";
    while(cin.peek() == '\n' || cin.peek() == '\r') cin.ignore(); 
    getline(cin, material);
    } else {
    getline(ins, color);
    //while(cin.peek() == '\n' || cin.peek() == ' ') {cin.ignore();}
    getline(ins, material); 
    }
}

void backpack::output(ostream& outs) const {
    if (&outs == &cout) {
    cout << "\n" << setw(15) << setfill('-') << "backpack:";
    cout << "\nbackpack color is: " << color;
    cout << "\nbackpack material is: " << material;
    } else {
        outs << "backpack" << endl;
        outs << color << endl;
        outs << material << endl;
    }

}