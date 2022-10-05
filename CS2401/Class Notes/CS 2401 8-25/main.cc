#include "auto.h"
#include <iostream>

int main (){
    Automobile mine; // Create object of automobile class
    cout << mine.get_gas_left; //Use object name then "." operator to access any funciton in the class
    mine.accelerate(10);
    // Those are the most basic uses of a class

    // I want this to increase the speed by 1 if no argument is given
    mine.accelerate(); // To do this, we need to create a default argument
}