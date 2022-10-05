/********************
 * Asa Chen
 * CS2401 Lab 3
 * September 16, 2021
 * Part 3 of Lab 3, Program demonstrates dynamic resizing of arrays based on capacity requirements. 
********************/
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    size_t capacity = 5;
    size_t used = 0;
    int* ptr;
    int* tmpptr;

    ptr = new int[capacity];

    for (size_t i = 0; i<25; i++) {
        ptr[used] = rand();
        //cout << ptr[used] << " ";
        used++;
        if (used == capacity){
            //cout << "Sorry, no room left. \n";
            //break;
            tmpptr = new int[capacity + 5];
            for (int i = 0; i < used; i++) {
                tmpptr[i] = ptr[i];
            }
            capacity += 5;
            delete ptr; //more like, deallocate
            ptr = tmpptr; //DO NOT DELETE TMP, since it is pointing at the required memory
            cout << "Resized\n";
        }
    }
    tmpptr[2] = 0;
    for (int i = 0; i < used; i++){
        cout << ptr[i] << " ";
    }

return 0;
}