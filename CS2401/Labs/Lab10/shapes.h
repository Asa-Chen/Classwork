
#include <iostream>
#include <cmath>
#ifndef SHAPES_H
#define SHAPES_H
using namespace std;

class Shape {

    public:
    Shape() {thickness = 1.25; cost_unit = 1.09;}
    virtual void input() {cout << "Please input the thickness: "; cin >> thickness; cout << "\nPlease input the cost per unit: "; cin >> cost_unit;}
    double cost() {return thickness * cost_unit * area();}
    virtual double area() = 0;
    private:
    double thickness;
    double cost_unit;
};



class Circle:public Shape {
    public:
    Circle() {radius = 0;}
    void input() {cout << "Please input the Circle's radius: "; cin >> radius;}
    double area() {return M_PI * radius * radius;}
    private:
    double radius;
};


class Rectangle:public Shape {
    public:
    Rectangle() {length = width = 0;}
    void input() {cout << "Please input the Rectangle's length: "; cin >> length; cout << "\nPlease input the Rectangle's width: "; cin >> width;}
    double area() {return length * width;}
    private:
    double length;
    double width;
};



class Trapezoid:public Shape {
    public: 
    Trapezoid() {base1 = base2 = height = 0;}
    void input(){cout << "Please input base 1: "; cin >> base1; cout << "\nPlease input base 2: "; cin >> base2; cout << "\nPlease input height: "; cin >> height;}
    double area() {return height * (base1 + base2) / 2.0;}
    private:
    double base1;
    double base2;
    double height;
};


#endif