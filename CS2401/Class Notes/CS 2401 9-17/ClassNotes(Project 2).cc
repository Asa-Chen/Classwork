//Sequence classes
//Dynamic Arrays

//Sequence is meant to keep track of the data in the order it was put in
//remove functions need to remove the data and shift everything
//Two friends are equal if their name and birthday match exactly
//Sequence classes talked about on the day you missed?
//Only resize the array if capacity is met


//Dynamic Arrays(AGAIN)

class D_Nums {
    public:
        D_Nums();
        void add_item(double item);

    private:
        double* data; //pointer to data array
        int used; //can use size_t if you want
        int capacity; 
        int current_index; //iterator, need for Project 2
        void resize(); //Make the array bigger if used is full. Function in private section because it is not up to the programmer
};

D_Nums::D_Nums() { //default constructor sets data pointer to new double array of size capacity
    used = 0;
    capacity = 5;
    data = new double[capacity];
}

void D_Nums::add_item(double item){
    if (used == capacity) {
        resize(); //Can only access from member functions
    }
    data[used] = item;
    used++;
}

void D_Nums::resize() {
    double* tmpptr;
    tmpptr = new double[capacity +5];

    for (int i = 0; i < used; i++) { //Copy data into tmpptr
        tmpptr[i] = data[i];
    }
    delete []data; //deallocate old array. [] deletes entire array. Without deletes just the one memory cell
    data = tmpptr; //point data at the new array
    capacity += 5; //resize capacity to reflect new array
}

//array copy loop shortcut
#include <algorithm>
copy(begin, end, destination); //faster than loop because OS can copy in chunks
copy(data, data + used, tmpptr); //Copy from data to data+used, into tmpptr


//The Big 3!
// If you declare a pointer inside a function, then the function goes out of scope, you won't delete the data the pointer is aiming at. MAKE SURE YOU DELETE
//The Big 3: Destructor
~D_Nums();
D_Nums::~D_Nums() {
    delete []data; //get rid of array pointer is aiming at
}

//The Big 3: Copy Constructor
D_Nums(const D_Nums& other); //Ensures that if you copy an object, it doesn't point to the same array as the original pointer, overwriting the previous data

D_Nums::D_Nums(const D_Nums& other) {// D_Nums(old);
    used = other.used;
    capacity = other.capacity;
    current_index = other.current_index;
    //data = other.data; // Points at same array, fucking things up. BAD DO NOT DO!

    //Make a new data array and copy from other
    data = new double[capacity];
    //copy loop or function
    for (int i = 0; i < used; i++) {
        data[i] = other.data[i];
    }



}

//The Big 3: Equality Operator
void operator = (const D_Nums& other); //Binary operator, belongs to object on the left. D_Nums new, old; new = old. With equal, its possible that new is pointing at an old array

void D_Nums::operator = (const D_Nums& other) {
    //Check if both objects are the same. Don't want to assing self to self
    if (this == &other) {//'this' is a keyword that returns the address. "This" is my address, &other is the other's address
    return;
    }
    //deallocate old data array
    delete []data;

    //Make a copy of other
    used = other.used;
    capacity = other.capacity;
    current_index = other.current_index;
    //data = other.data; // Points at same array, fucking things up. BAD DO NOT DO!

    //Make a new data array and copy from other
    data = new double[capacity];
    //copy loop or function
    for (int i = 0; i < used; i++) {
        data[i] = other.data[i];
    }
    //copy function
    copy (other.data, other.data+other.used, data);
}

