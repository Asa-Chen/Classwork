// The implementation file for the MyTime class
#include "MyTime.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;
//Constructor
MyTime::MyTime(int h, int m){
	hours = h;
	minutes = m;
}

// Member functions
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
	char junk;
	cout << "Hours: ";
	ins >> hours;
  	ins.get(junk);
	cout << "Minutes: ";
	ins >> minutes;
	simplify();
}

void MyTime::output(ostream& outs) {
	    outs << hours << ':' << setw(2) << setfill('0') << minutes;
}


ostream& operator <<(ostream& outs, MyTime& t) {
    t.output(outs);
	return outs;
}

istream& operator >> (istream& ins, MyTime& t) {
	t.input(ins);
	return ins;
}
