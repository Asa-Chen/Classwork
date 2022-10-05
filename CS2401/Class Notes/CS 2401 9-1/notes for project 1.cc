cin >> my_string;
//The >> operator does not read the new line character after an input.
//i.e. "Asa Chen", the "\n" is still in the input stream
//getline(cin, my_string); does consume the new line character.
//HOWEVER!
cin >> string_1;
getline(cin, my_string);
//When using these back to back, getline will read the "\n" left in the input stream and quits early

//TO REMOVE \n, 
cin >> string_1;

while(ins.peek() == "\n" || ins.peek() == "\r") { //looks at the next character in the input stream, "\r" is windows version of "\n"
    ins.ignore(); //Takes next character on input stream and removes it
}
getline(cin,my_string);
//This is only necessary if you encouter this situation

//Input and output functions need to be able to input and output to keyboard/terminal or file/file
void input(std::istream& ins) {
 if(&ins == &cin) {
     //read from the keyboard
     //Include promts for input
 } else {
     //read from file
     //no need for promts
 }
}

void output(std::ostream& outs){
    if(&outs == &cout) {
        //output to terminal
        //Lable data as it is displayed
    } else {
        //output to file
        //don't want to lable data since it would confuse a program reading the file
    }
}


//most files will not be changed
//main is commented out, just un comment the code
//don't change the date class
//main part is writing the checkbook container, use size variable like discussed on 8-30
//Next available check number is just a counter that keeps counting
//comparison operators for date are already written in date class
//function prototypes are already written, just write implimentations

