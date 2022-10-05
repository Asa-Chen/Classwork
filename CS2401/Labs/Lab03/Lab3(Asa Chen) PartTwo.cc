/********************
 * Asa Chen
 * CS2401 Lab 3
 * September 16, 2021
 * Part 2 of Lab 3, program demonstrates the different ways to call a pointer, and the different results of these actions.
********************/
#include <iostream>
#include <cstdlib>
using namespace std;

main() {
    int* ptr;
    ptr = new int;
    cout << ptr << endl;
    cout << &ptr << endl;
    *ptr = 2401;
    for (int i = 0; i < 10; i++) {
        //++(*ptr);
        ++(ptr);
        cout << *ptr << " Is stored at: " << ptr << endl;
    }


return 0;

}