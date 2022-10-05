#include "MyTime.h"
#include "MyTime.cc"
#include <iostream>
using namespace std;


int main() {
    int scalar = 0;
    MyTime t1,t2,t3;
    cout << "Input your first set of time values (Time-Set 1) below" << endl;
    t1 >> cin;
    cout << "Input your second set of time values (Time-Set 2) below" << endl;
    t2 >> cin;
    cout << "Input your scalar value (Must be an integer):" << endl;
    cin >> scalar;
    t3 = t1 + t2;
    cout << "Time-Set 1 + Time-Set 2 = ";
    t3 << cout << endl;
    t3 = t1 - t2;
    cout << "Time-Set 1 - Time-Set 2 = ";
    t3 << cout << endl;
    t3 = t1 * scalar;
    cout << "Time-Set 1 * scalar = ";
    t3 << cout << endl;
    t3 = t2 * scalar;
    cout << "Time-Set 2 * scalar =";
    t3 << cout << endl;
    t3 = t1 / scalar;
    cout << "Time-Set 1 / scalar =";
    t3 << cout << endl;
    t3 = t2 / scalar;
    cout << "Time-Set 2 / scalar =";
    t3 << cout << endl;
    if (t1 == t2) {
        cout << "Time-Set 1 = Time-Set 2: True" << endl;
    } else {
        cout << "Time-Set 1 = Time-Set 2: False" << endl;
    } if (t1 < t2) {
        cout << "Time-Set 1 < Time-Set 2: True" << endl;
    } else {
        cout << "Time-Set 1 < Time-Set 2: False" << endl;
    } if (t1 <= t2) {
        cout << "Time-Set 1 <= Time-Set 2: True" << endl;
    } else {
        cout << "Time-Set 1 <= Time-Set 2: False" << endl;
    }

return 0;
}