#include "MyTime.h"
//#include "MyTime.cc"
#include <iostream>
using namespace std;


int main() {
    int scalar = 0;
    MyTime t1,t2,t3;
    cout << "Input your first set of time values (Time-Set 1) below" << endl;
    cin >> t1;
    cout << "Input your second set of time values (Time-Set 2) below" << endl;
    cin >> t2;
    cout << "Input your scalar value (Must be an integer):" << endl;
    cin >> scalar;
    t3 = t1 + t2;
    cout << "Time-Set 1 + Time-Set 2 = ";
    cout << t3 << endl;
    t3 = t1 - t2;
    cout << "Time-Set 1 - Time-Set 2 = ";
    cout << t3 << endl;
    t3 = t1 * scalar;
    cout << "Time-Set 1 * scalar = ";
    cout << t3 << endl;
    t3 = t2 * scalar;
    cout << "Time-Set 2 * scalar =";
    cout << t3 << endl;
    t3 = t1 / scalar;
    cout << "Time-Set 1 / scalar =";
    cout << t3 << endl;
    t3 = t2 / scalar;
    cout << "Time-Set 2 / scalar =";
    cout << t3 << endl;
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