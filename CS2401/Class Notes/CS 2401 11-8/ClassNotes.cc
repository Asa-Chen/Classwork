
//Recursion


void reverse_print(node* head) {
    node* cursor = head;
    stack<int> s;

    while(cursor != NULL) {
        s.push(cursor -> data);
        cursor = cursor -> next();
    }

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
}


//recursion
//-when a function calls itself
//-calling the function that is running inside the function that is running


int main() {
    main(); //this is valid, but not useful
    return 0;
}



void reverse_print(node* head) {
    //Base case, always looks like some kind of if statement
    //need this to avoid infinite loops
    //Without a base case, you'll create errors
    if(head == NULL) {
        return;
    }
    else {
        //Variant expression
        reverse_print(head -> next()); //Must use (head -> next()) because head alone would cause an infinite loop
        cout << head -> data() << endl;
    }
}



void select_sort(int a[], int size) {
    //Base case
    if (size == 0) {
        return;
    } else {
        int smallspt = find_min(a,size); //pretend this function exists
        //swap 
        int tmp = a[0];
        a[0] = a[smallspt];
        a[smallspt] = tmp;


        //Variant expression
        select_sort(a + 1, size - 1);
    }
}




12345
//to
1
2
3
4
5
void print_vertical(int n) {
    //base case
    if (n < 10) {
        cout << n << endl;
    }
    else {
        print_vertical(n / 10);
        cout << n % 10 << endl;

    }
}
