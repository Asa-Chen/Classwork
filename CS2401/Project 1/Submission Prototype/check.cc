/*************************************************************************
    This is the implementation file for the Check class. For more 
		information about the class see check.h.
    Students are expected to implement some of the functions shown 
		below.
	John Dolan			Ohio University EECS	September 2019
	Patricia Lindner	Ohio University EECS	August 2021
*************************************************************************/
#include "check.h"
using namespace std;

Check::Check(Date d, string p, int num,double amt){
	checknum = num;
	date = d;
	payto = p;
	amount = amt;
}

// Input and output functions
void Check::write_check(std::istream& ins){
	if (&ins == &cin) { //Keyboard
		cout << "Please input the date as mm/dd/yyyy: ";
		cin >> date;
		cout << "Please input your check recipient: ";
		cin >> payto;
		cout << "Please input your check amount as 'dollars.cents': ";
		cin >> amount;

	} else { //File
			ins >> checknum;
			while (ins.peek() == '\n' || ins.peek() == ' ') {
				ins.ignore();
			}
			ins >> date;
			while (ins.peek() == '\n' || ins.peek() == ' ') {
				ins.ignore();
			}
			getline (ins, payto);
			while (ins.peek() == '\n' || ins.peek() == ' ') {
				ins.ignore();
			}
			ins >> amount;
			while (ins.peek() == '\n' || ins.peek() == ' ') {
				ins.ignore();
		}

	}
	/* You are to write the implementation of this function to read 
	from the keyboard or a file. Remember to use getline to read the 
	payto.  */
} // both write_check and output need to be able to write to terminal or file with proper notation

void Check::output(std::ostream& outs)const{
	if (&outs == &cout) {
		cout << "Check Number: " << checknum << endl;
		cout << "Date: " << date << endl;
		cout << "Recepient: " << payto << endl;
		cout << "Amount: " << amount << endl << endl;
	} else {
		outs << checknum << endl << endl;
		outs << date << endl << endl;
		outs << payto << endl << endl;
		outs << amount << endl << endl;
	}
	/* You are to write the implementation of this function to write 
	to the monitor or to a file. Remember not to put labels into the 
	file.*/
}

ostream& operator << (ostream& outs, const Check& c){
	c.output(outs);
	return outs;
}

istream& operator >> (istream& ins, Check& c){
	c.write_check(ins);
	return ins;
}