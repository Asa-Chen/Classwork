#include <iostream>
#include <iomanip>
#include "dictionary.h"
using namespace std;
int main()
{
    string key;
    string value;
    Dictionary d;

    for (int i = 0; i < 5; i++)
    {
        cout << endl
             << "Please input a value to be stored in the Dictionary: ";
        cin >> value;
        cout << endl
             << "Please input a key you'd like to use to access the value: ";
        cin >> key;
        d.put(key, value);
    }
    cout << endl
         << "Key - Value"
         << "  List size:" << d.size() << endl;
    d.display();

    cout << "Please input a Key you'd like to search for in the list: ";
    cin >> key;
    cout << "The value stored is: " << d.get(key) << endl;

    cout << "Please input a Key you'd like to remove from the list: ";
    cin >> key;
    d.removeKey(key);
    cout << endl
         << "Key - Value"
         << "  List size:" << d.size() << endl;
    d.display();

    cout << "Please input a value you'd like to remove from the list: ";
    cin >> value;
    d.removeValues(value);
    cout << endl
         << "Key - Value"
         << "  List size:" << d.size() << endl;
    d.display();

    cout << "Please input a Key you'd like to check for in the list. 1 = yes, 0 = no: ";
    cin >> key;
    cout << endl
         << d.hasKey(key)
         << endl
         << endl;

    cout << "Please input a Value you'd like to check for in the list. 1 = yes, 0 = no: ";
    cin >> value;
    cout << endl
         << d.hasValue(key)
         << endl
         << endl;

    cout << "Thank you, Goodbye.";
}