/******************
* Asa Chen, CS2401 Fall 2021
* main2.cc for Lab12. Demonstration of recursion.
******************/
#include <iostream>
#include <string>
using namespace std;


void reversing(string &s, int start, int end);

int main(){
 string s;
 int start, end;
 cout << "Enter a string: ";
 getline(cin,s);
 cout << "Enter two numbers that are within the bounds of the string.\n";
 cin >> start >> end;
 cout << "This is how your string looks now:\n";
 reversing(s, start, end);
 cout << s << endl;
 return 0;
}

void reversing(string &s, int start, int end) {
if (start >= end) {
    return;
} else {
    char sw = s[start];
    s[start] = s[end];
    s[end] = sw;
    reversing(s, start + 1, end - 1);
    }
}