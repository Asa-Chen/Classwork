//#include "shapes.h"
using namespace std;


void Shape::input() {
cout << "Please input the thickness: ";
cin >> thickness;
cout << "\nPlease input the cost per unit: ";
cin >> cost_unit;
};

void Circle::input() {
    cout << "Please input the Circle's radius: ";
    cin >> radius;
}

double Circle::area() {
    return M_PI * radius * radius;
}



void Rectangle::input() {
    cout << "Please input the Rectangle's length: ";
    cin >> length;
    cout << "\nPlease input the Rectangle's width: ";
    cin >> width;
}


double Rectangle::area() {
    return length * width;
}


void Trapezoid::input() {
    cout << "Please input base 1: ";
    cin >> base1;
    cout << "\nPlease input base 2: ";
    cin >> base2;
    cout << "\nPlease input height: ";
    cin >> height;
}

double Trapezoid::area() {
    return height * (base1 + base2) / 2.0;
}




