/*************************************************************************
	Lab Assignment 9 - working with a stack
	It's sometimes tricky to set up the loop that reads the expression 
	from the keyboard, so I am giving that to you. You have to fill in 
	the rest of the main.

	John Dolan	Fall 2016	Ohio University		Home of the Bobcats
*************************************************************************/
#include <stack>
#include <iostream>
#include<cstdlib>
#include "calc_useful.h"
using namespace std;

int main(){
	char c;
	char tmp;
	int onenum, twonum;
	bool continu = true;
	// declare an STL stack called nums right here:
	stack<int> nums;

	//cout << "Please enter your expression:\n";

	//c = cin.get(); // priming read for the sentinel loop.
	while(continu == true){
		cout << "\nPlease enter your expression:\n";
		c = cin.get(); // priming read for the sentinel loop.
		while(c != '\n'){
			if(isdigit(c)){
				cin.putback(c);
				cin >> onenum;
				// stack operation here.
				nums.push(onenum);

			}
			else if(isop(c)){
				if(!nums.empty()){
					onenum = nums.top();
					nums.pop();
					if (!nums.empty()) {
						twonum = nums.top();
						nums.pop();
						nums.push(evaluate(twonum,onenum,c));
					} else {
						cout << "Error: ";
						cout << "Out of order, or too many, operands.";
						return -1;
					}
					// pop two numbers from the stack
					// evaluate them using the evaluate from stack_useful
					// push result onto the stack

				}
				else{ // couldn't find a use for this.
					cout << "Error:";
					cout << "...  "; // what did this error tell us about the user's expression?
					return -1;
				}
			}

			c = cin.get(); // reading at the bottom of the sentinel loop
		} // bottom of the loop that reads a single expression from the keyboard

		if (!nums.empty() && nums.size() == 1) {
			cout << "Answer: " << nums.top();
			nums.pop();
		} else if (!nums.empty()) {
			cout << "Error: ";
			cout << "Too few operands.";
			return -1;
		}
	// output the final result from the top of the stack
	// but only after you check to make sure there's something on the stack
	
		cout << "\nEnter another equation?(y or n)";
		cin >> tmp;
		if(tmp == 'y' || tmp == 'Y'){
			continu = true;
			c = cin.get();
		}else {
			continu = false;
		}
	}
	return 0;
}