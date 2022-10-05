//parenthesis syntax checker
(((()))))

int main() {
    STACK<char> s; //stack of characters
    char tmp; //temporary character I can read in from input stream
    tmp = cin.get(); //used because it gets one line at a time, and we will need the new-line character to tell when to end the loop

    while (tmp != '\n') {
        if (tmp == '(' || tmp == '[' || tmp =='{') {
            s.push('tmp'); //push tmp or ()
        } else if (tmp == ')') { //If you find a ) 
            if (!s.empty() && s.top() == '('){ //And the list is not empty and there is a ( at the top of the list to match, pop
                s.pop();
            } else {
                cout << "ERROR: Mismatch";
            }
        } else if (tmp == ']') {
            if (!s.empty() && s.top() == '['){ 
                s.pop();
            } else {
                cout << "ERROR: Mismatch";
            }
        } else if (tmp == '}') {
            if (!s.empty() && s.top() == '{'){ 
                s.pop();
            } else {
                cout << "ERROR: Mismatch";
            }
        }

        tmp = cin.get();

    }

    if (!s.empty()) {
        cout << "ERROR: too many left hand parenthesis";
    }
}