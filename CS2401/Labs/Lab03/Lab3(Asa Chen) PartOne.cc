/********************
 * Asa Chen
 * CS2401 Lab 3
 * September 16, 2021
 * Part 1 of Lab 3, program represents the difference between automatic varaible declaration and static declaration.
********************/


#include <iostream>
using namespace std;

void pretty();

int main() {
    for (int i = 0; i < 6; i++){
        pretty();
    }
    return 0;
}



void pretty() {
    //int x = 0;
    static int x = 0;
    x++;
    for (int i = 0; i < x; i++) {
        cout << '*';
    }
    cout << endl;
}