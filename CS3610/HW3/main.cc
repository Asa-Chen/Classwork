#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "index-tree.h" 
using namespace std;

char menu();


int main (int argc, char *argv[]) {
char choice = ' ';
BTree index;

index.insert("one",1,index.root);
index.insert("two",3,index.root);
index.insert("three",5,index.root);
index.insert("one",1,index.root);
index.insert("one",5,index.root);

index.print(index.root);




while (choice != '4') {
    choice = menu();
    switch(choice) {
        case '1': 
            //do something
            break;
        case '2':
            //do something 
            break;
        case '3': 
            //do something
            break;
        case '4': 
            cout << "ending the program\n";
            break;
        default: 
            cout << "Invalid Input\n";
            break;
    }

}

    








    return 0;
}

char menu(){
    char choice;
    
    cout << "Pick from the following: \n";
    cout << "Option 1: Display Index(s) in order\n";
    cout << "Option 2: Search for a word\n";
    cout << "Option 3: Find the most common word\n";
    cout << "Option 4: Quit\n";
    cin >> choice;

    return choice;
    }