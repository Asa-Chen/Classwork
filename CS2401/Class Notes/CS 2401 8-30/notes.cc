
#include <string>
//Arrays


int my_array[100];
std::string s_array[100];

//to overwright array data
my_array[0] = 10; //0 is the point in the array I wish to override 

//Array of clases
Automobile carlot[100];
int used = 0;

while (used < 100){
    Automobile tmp;
    tmp.input(cin);
    carlot[used] = tmp;
    used++; //used is simultaneously the number of vehicles in the lot and the next index in the array
} //takes the input from cin and puts it into the next available car slot

double total_fuel = 0.0;
for int j=0; j<used;j++) {
    total_fuel += carlot[j].get_fuel();
}

//Container class (a class holding an array of data)
class Numbers {
    public:
        static const int SIZE = 200; //Static varaibles help maintain consistency across member objects and ensures the data is not altered 
        //When we normally used variables, they are automatic, i.e. they're only allocated if the function is called. (takes less memory)
        //Static variables are declared and the memory is allocated for the entire time the program is running. (takes more memory)
        Numbers () {used = 0}; //declares used as 0
        void add_item(double item);
        void see_all()const;
        double sum_all()const;

    private:
        double data [SIZE]; //the array of data and the amount of data points in the array
        int used;

}

//.cc file implimentations
void Numbers::add_item(double item){
    if (used < SIZE) { //if statement makes sure you don't "walk off the end of your array" and get a Seg Fault
    data[used] = item;
    used++;
    } else {
        cout << "Sorry, array is full" << endl;
    }
}

void Numbers::see_all() const{
    for (int i = 0; i < used; i++) { //Since used is a member variable of the class, you can reference used without passing it in
        cout << data[i] << endl;
    }
}

double Numers::sum_all()const{
    double sum = 0.0;
    for (int i = 0; i < used; i++){
        sum += data[i];
    }
    return sum;
}


//New class 
class Names {
    public:
    static const int SIZE = 200;
    Names() {used = 0};
    bool in_there(const std::string& target) const;
    void remove(const std::string& target); // not const because you are removing a string from the array 
    private:
    std::string data[SIZE];
    int used;

}

//.cc file implimentations

bool Names::in_there(const std::string& target) const {
    int i = 0;
    while (i < used) { //use used instead of size to ensure that you don't go through junk memory left in the array
    if (data[i] == target) {
        return true;
    }
    i++;
    }
    return false;
}

void Names::remove(const std::string& target){
    int i = 0;
    while (i < used) { //the same process of searching for a data value in the array
    if (data[i] == target) {
        data[i] = data[used - 1]; //used -1 is the last piece of data that was used
        used--;
        //break; //breaks the loop if i only want to find and remove the value once
        //i--; //use if you wish to remove all of the specific values from the loop my double checking the spot you replaced to ensure
            //it is not the desired value. It is just to make sure the last value in the array was not also the value you wished to remove
            //THIS IS ASSUMING THAT ARRAY DATA ORGANZATION DOES NOT MATTER
    }
    i++;
    }
}

Names classList;
while (classList.in_there("Bob")){
    classList.remove("Bob");
}

//Vectors are container classes with all of the implimentations already made
//we will not use vectors, mainly arrays and a couple of other data types so that we get used to creating and establishing our own data types