/* Lab 11
* Asa Chen
* CS 2401
*/
#include <iostream>
#include <iomanip>
using namespace std;

void counting(int x);
void print_stars(int n);
void see_stars(int n, int s);

int main() {
    int x;
    for (int j = 0; j < 3; ++j) {
        cout << "Enter a number: ";
        cin >> x;
        cout << "The even numbers counting up to x: \n";
        counting(x);
    }

    int n;
    cout << "Enter a number between 1 and 30 to see the stars\n";
    cin >> n;
    see_stars(1,n);

    return 0;
}


void counting (int x) {
    if (x <= 1) { //base case
        return;
    } else {
        if (x % 2 != 0) {--x;}
        counting(x-2);
        cout << x << endl;
    }
}

void print_stars(int n) {
    if (n < 1) {
        return;
    } else {
    cout << '*';
    print_stars(n - 1);
    }
}

void see_stars(int n, int s) {
    if (n > s) {
        if (s < 1) {return;}
        print_stars(s);
        cout << endl;
        see_stars(n,s - 1);
        return;
    } else {
        print_stars(n);
        cout << endl;
        see_stars(n + 1, s);
    }

}