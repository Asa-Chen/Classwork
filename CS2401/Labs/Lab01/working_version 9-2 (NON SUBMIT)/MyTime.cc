// The implementation file for the MyTime class
#include "MyTime.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;
//Constructors
MyTime::MyTime(int h, int m){
	hours = h;
	minutes = m;
}

// Member and friend functions
void MyTime::Reset(int h, int m){
	hours = h;
	minutes = m;
}

void MyTime::simplify(){
    hours += minutes/60;
	minutes = minutes%60;
}

MyTime MyTime::operator + (const MyTime& t2) const{
	MyTime tmp;
    tmp.hours = hours + t2.hours;
	tmp.minutes = minutes + t2.minutes;
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator - (const MyTime& t2) const{
	MyTime tmp;
	tmp.minutes = abs((hours*60+minutes) - (t2.hours*60+t2.minutes));
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator / (int num) const{
	MyTime tmp;
	tmp.minutes = hours*60 + minutes;
	tmp.minutes /= num;
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator * (int num) const{
	MyTime tmp;
	tmp.minutes = hours*60 + minutes;
	tmp.minutes *= num;
	tmp.simplify();
	return tmp;
}

bool MyTime::operator == (const MyTime& t2) const{
	return hours == t2.hours && minutes == t2.minutes;
}

bool MyTime::operator < (const MyTime& t2) const{
	return (hours*60 + minutes) < (t2.hours*60 + t2.minutes);
}

bool MyTime::operator <= (const MyTime& t2) const{
	return (hours*60 + minutes) <= (t2.hours*60 + t2.minutes);
}

void MyTime::input(istream&ins) {
	/* Move the implementation code from the >> operator show below here.
	   Remember that since this function will be a member now, there will not be a t1.*/
	char junk;
	cout << "Hours: ";
	ins >> hours;
  	ins.get(junk);
	cout << "Minutes: ";
	ins >> minutes;
	simplify();
	   /*The >> operator should now call this function.
	   Remove the friend keyword from the operator in the .h file and move the
	   function prototype to after the class declaration.
	*/
}

void MyTime::output(ostream& outs) {
	/* Repeat what you did for input except using the code for the << operator */
	    outs << hours << ':' << setw(2) << setfill('0') << minutes;
}


ostream& MyTime::operator <<(ostream& outs) {
    output(outs);
	return outs;
}

istream& MyTime::operator >> (istream& ins) {
	input(ins);
	return ins;
}
