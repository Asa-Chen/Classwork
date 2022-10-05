#include "auto.h"
// Constructor
Automobile::Automobile(){
    gas_left = 0.0;
    current_speed = 0.0;
    odometer = 0.0;
    avg_mpg = 0.0;

}

Automobile::Automobile (const std::string &c);


// Accessor Functions
double Automobile::get_gas_left () const { // Automobile:: is a "scope resolution"
    return gas_left;                       // Used to tell the compiler that I'm using the class
}