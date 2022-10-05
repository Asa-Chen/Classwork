//Begin talking abut dynamic memory

//everything beforehand has been static memory, i.e.
static const int SIZE = 200;


//Dynamic memory: explicitly allocating and deallocating memory based on what we need in the moment
//They way we will do this, is by using pointers. NEVER USED POINTERS BEFORE
int x = 16;
//this statement takes a memory region the OS knows will hold the integer (typically 4 bytes) and gives us a name to reference that memory "x"
cout << x;//output the value stored in x

cout << &x; //output the address of x (where the 16 is being stored in memory) 0x762352fea (hexadecimal address)

//a pointer is a variable that stores an address
int x = 16; //stores data
int* ptr; //stores the LOCATION (address) of data

cout << ptr; //output the address of the data the pointer is refering too, which is an address

cout << &ptr; //output the memory location of the pointer. NOT the address the pointer is referencing

cout << *ptr; //output the data stored at the location the pointer references. THIS IS CALLED dereferencing
//SO FAR, THIS IS ALL AUTOMATIC MEMORY, NOT DYNAMIC

//EXAMPLE
int x = 16; //create variable
int * ptr; //create a pointer, which is not dynamic memory
ptr = &x; //set the value of the pointer to the address of x

//MOVING ON TO POINTERS WITH DYNAMIC MEMORY
//Dynamic memory
// new returns the address that it allocated out of "the heap"
//Allocates enough memory for an int, but there is no way to access that memory
new int; //BAD PROGRAMMING!!!


*ptr //means the value stored at the pointer
ptr //Means the address stored by the pointer

//save the address that new returned into a pointer
ptr = new int; //this is useful because new memory is allocated and you have and address to access that memory
(*ptr)++; //increase the value thats being stored at the location the pointer is pointing at
//must use parenthesies and *
ptr++;//NOT CORRECT! This will jump the pointer by 4 bytes, messing it up. you wouldn't be able to access that data anymore
(*ptr)++; //dereferences the location first, then manipulates the data


ptr = new int;
(*ptr)++;
(*ptr)-=4;
ptr = new int; //IF YOU RUN THIS LINE AGAIN, YOU WILL REWRITE the pointer value, which means you lose the address to the first data set
                //THIS IS CALLED MEMORY LEAKING

//to deallocate memory
delete ptr; //deallocates memory ptr was referencing
//now you can run
ptr = new int;
//your program still has access to ptr, you can now put new data in that slot
//EVERYTIME YOU USE NEW, MATCH IT WITH A DELETE. ALLOCATE AND THEN DEALLOCATE
//VERY VERY IMPORTANT TO DEALLOCATE MEMORY IF YOU DON'T NEED IT

//"The heap" is a special lump of memory set aside for the program to run dynamic memory

//concerning arrays
int array[100];
int* ptr;
ptr = array; //set ptr equal to address of first index of array



//Another method for displaying an array
//OS knows how big an int is so array + used is really array + (used * sizeof(int))
while (ptr < array + used) { //Playing with memory locations,
    cout << *ptr << endl;
    //OS knows how big an int is so ++ptr will add sizeof(int) to ptr
    ++ptr; //adds whatever the size of an int is to the pointer, not 1
}//Shuffles through the array like a for loop would, and displays the values at *ptr using memory location instead of the values at that memory location



ptr = new int;

double* d;
d = new double; //all "new" does is look at the type, and give you enough memory to hold that type
*d = 3.14;

string* s;
s = new string;
s = "Hello World";


//assuming you've included the Automobile class
Automobile* a;
a = new Automobile;
(*a).input(cin);

delete d;
delete s;
delete a;
delete ptr;

//YOu can use just about anything for pointers
//simple data types, objects, container classes
//AGAIN, MEMORY LEAK = memory allocated, and never deallocated. VERY BAD
//AS SOON AS YOU CLOSE A PROGRAM, YOU RELEASE ALL THE MEMORY



