#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

#ifndef CHORE_H
#define CHORE_H
class chore {
    public:
    int prior() {return priority;}
    chore(string choren = "empty", int p = 0) {chorename = choren; priority = p;}
    void input() {cout << "\nInput chore priority: "; cin >> priority; cin.ignore(); cout << "Input chore: "; getline(cin, chorename);}
    void out() const {cout << "\nChore Priority: " << priority; cout << " Chore: " << chorename;}
    private:
    string chorename;
    int priority;
};

    bool operator < (chore c1, chore c2) {return c1.prior() < c2.prior();}

#endif