#include "numlist.h"
//#include <iostream>
#include <fstream>

using namespace std;

int main() {
string in_file;
int user_num1, user_num2, user_num3;
NumList numbers;
cout << "Please type the name of your file: ";
cin >> in_file;

fstream ifs;
ifs.open(in_file);
numbers.load_from_file(ifs);
ifs.close();

numbers.b_sort();
//numbers.see_all();


size_t index = in_file.find(".");
string out_file = in_file.insert(index, "sorted");

cout << "Please type your first number input: ";
cin >> user_num1;
numbers.insert(user_num1);
cout << "Please type your second number input: ";
cin >> user_num2;
numbers.insert(user_num2);
cout << "Please type your third number input: ";
cin >> user_num3;
numbers.insert(user_num3);


numbers.see_all();
ofstream ofs;
ofs.open(out_file);
numbers.save_to_file(ofs);
ofs.close();



return 0;
}