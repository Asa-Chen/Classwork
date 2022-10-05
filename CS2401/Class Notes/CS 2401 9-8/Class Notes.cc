//sorting algorithims continued
//Talked about selection sort in class last friday
//selection sort involves going through the string in nested loops, placing the smallest value in the proper place
//

//Formula to calculate the number of times the inner loop is called
// N = size of list, 
// N-1 + N-2 + N-3 + ..+ 1
//Formula is 

//N(N-1)
//------
//  2

// (N-1)((N-1) +1)   (N-1)N    N^2 - N
// --------------- = ------ = -------- = Big O N^2, (Big ) is a measure of performance for an algorithm)
//        2            2         2     
//So thats selection sorting


//Bubble sorting Algorithm
//
//    Example Array:  |3|1|4|2|5|
//Bubble sort looks at adjacent members of array and compares them
// Pass #1 Compare 3&1, move the lowest to the left, compare 1&4, compare 4&2, swap 4&2, compare 4&5 |1|3|2|4|5|
//Pass #2 Compare 1&3, compare 3&2, swap 3&2, compare rest of values
//Pass #3 Compare values for array
//In three passes, the array is sorted as |1|2|3|4|5|
//Bubbles sort is best for when the array is already mostly in order

//Selection sort runs through the array and only switches one data point in an entire pass
//Selection sort pass only moves one variable, therefore it is longer
//Bubble sort can quit as soon as it doesn't swap anything
//Selection sort must compare all the data points in the array against the rest of the array
//Bubble sort, helpful for lab 2?
//When building a class, you can write a bubble sort and selection sort function, and leave the decision up to the application programmer

//Assume there is a class already written that the bubble sort function will go with

void MyClass::b_sort() {
    int i; //counter
    base_data_type tmp; //whatever the container class is holding
    bool done = false;

    while (!done) {
        //start by assuming i am done now
        done = true;

        //inner loop 
        //compare the item at position i to the one next to it (i+1)
        for (i = 0; i < used -1, i++) {
            //if i and i+1 are out of order, i need to swap them
            if(data[i] > data[i+1]) {
                //swap items
                tmp = data[i+1];
                data[i+1] = data[i];
                data[i] = tmp;
                //because i swapped something, i am not done, therefore done = false;
                done = false;
            } //if you exit this loop without triggering the if statement, done is still true, and the loop stops
        }
    }

}
//These are the two sorting algorithms used in this class

//!!!!WHEN COMPILING, include the class implimentation in the compile command instead of in the main file


//Moving on to GDB, the GNU debugger
//A program where you can compile the program you wrote with a special program
//Normal compile command, g++ MyClass.cc main.cc
//Possible debug compile command, g++ -g MyClass.cc main.cc
//When debugging, -g is useful, however on the final build, -g should be ommited to save space
//n command, "next"
//p command, "peek" to view the current status of data. I.e. "p count", "s sum"
//to get out of a debug sesh, use command, q
//begin debug, gdb ./a.out(executable name)
//set initial breakpoint, i.e., break main
//begin debugging, use command, run


//Cutting notes short because laptop battery is shit
//Class is recorded in teams