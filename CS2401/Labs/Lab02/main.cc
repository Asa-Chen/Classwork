#include "numlist.h"
#include <fstream>

using namespace std;

int main() {
string in_file;
int user_num1, user_num2, user_num3;
NumList numbers;
cout << "Please type the name of your file: ";
cin >> in_file;
//-----
fstream ifs; //Opens file stream from given file name, and loads values into array "numbers"
ifs.open(in_file);
if (ifs.is_open()){
    //do nothing
} else {
    cout << "File failed to open. Try Again.";
    return 0;
}
numbers.load_from_file(ifs);
ifs.close();
//-----
numbers.b_sort(); //Sorts the initial array, and establishes the name for the sorted output file
size_t index = in_file.find(".");
string out_file = in_file.insert(index, "sorted");
//-----
cout << "Please type your first number input: "; //Asks user for numbers, and sorts them respectively
cin >> user_num1;
numbers.insert(user_num1);
numbers.b_sort();
cout << "Please type your second number input: ";
cin >> user_num2;
numbers.insert(user_num2);
numbers.b_sort();
cout << "Please type your third number input: ";
cin >> user_num3;
numbers.insert(user_num3);
numbers.b_sort();
//-----
numbers.see_all(); //Displays final array to terminal, opens out file stream, and writes array to "sorted" file
ofstream ofs;
ofs.open(out_file);
numbers.save_to_file(ofs);
ofs.close();
//-----
return 0;
}