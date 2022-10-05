//fully parenthesized calculator

(6 + ((5* 2) * 3))

//Create two stacks, one of numbers and one of operation
//In the calculator you can ignore the (
//When you hit a right hand ), take the top two numbers off and the first operation
//Use the operation on the numbers
//put the number back on the number stack
//repeat until complete
using namespace std;

int main() {
    STACK<int> nums;
    STACK<char> ops;

    char tmp;
    int n1,n2,n3;
    tmp = cin.get();


    while (tmp != '\n') {
        if (isdigit(tmp)) { //if tmp is a digit
            cin.putback(tmp); //push back onto the stream
            cin >> n1; //read into the number slot
            nums.push(n1);
        } else if (tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/') {
            ops.push(tmp);
        }
        else if (tmp == ')') {
            //do the top operation on the ops stack with the top two numbers from nums
            if (!nums.empty()) {
                n2 = nums.top();
                nums.pop();
            }
            if (!nums.empty()) {
                n1 = nums.top();
                nums.pop();
            }
            //have to write evaluate to get answer
            if (!ops.empty()) {
            n3 = evaluate(n1, n2, ops.top()); //solve the operator of n2 and n1
            ops.pop(); //remove the operation from the ops stack
            nums.push(n3); //return the solved number to the nums stack
            }
        }
        tmp = cin.get();
    }

    if (!nums.empty()) {
        cout << "Answer : " << nums.top() << endl;
        nums.pop();
    }





}